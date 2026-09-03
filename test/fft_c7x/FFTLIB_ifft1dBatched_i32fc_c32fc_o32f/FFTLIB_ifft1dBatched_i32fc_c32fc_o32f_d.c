// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#define NUM_RUNS (100)
#include <fftlib.h>

// include test infrastructure provided by FFTLIB
#include "FFTLIB_test.h"

#include <math.h>

#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32f.h"
#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_cn.h"
#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_idat.h"

#if defined(__C7504__) || defined(__C7524__)
__attribute__((section(".l2sramaux"), aligned(64))) int8_t l2auxBuffer[FFTLIB_L2_BUFFER_SIZE];
__attribute__((section(".ddrData"), aligned(64))) int8_t   ddrBuffer[2048 * 1024];

#else
__attribute__((section(".msmcData"), aligned(64))) int8_t msmcBuffer[FFTLIB_L3_RESULTS_BUFFER_SIZE];
__attribute__((section(".ddrData"), aligned(64))) int8_t  ddrBuffer[2048 * 1024];
#endif

int16_t volatile volatileSum = 0;

#pragma DATA_SECTION(FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock, ".pinit")
uint8_t FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock[FFTLIB_IFFT1DBATCHED_I32FC_C32FC_O32F_PBLOCK_SIZE];

int FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_d(uint32_t *pProfile, uint8_t LevelOfFeedback)
{
   int32_t                                      tpi;
   ifft1dBatched_i32fc_c32fc_o32f_testParams_t *prm;
   uint32_t                                     testNum = 0;     // test case id
   int32_t                                      currentTestFail; // status of current test case
   int32_t                                      fail = 0;        // fail flag

   ifft1dBatched_i32fc_c32fc_o32f_getTestParams(&prm, &test_cases);

   TI_profile_init("FFTLIB_ifft1dBatched_i32fc_c32fc_o32f");

   FILE *fpOutputCSV = fopen("FFTLIB_ifft1dBatched_i32fc_c32fc_o32f.csv", "w+");
   fprintf(fpOutputCSV, "Test ID,"
                        "Num Channels,"
                        "Num Points,"
                        "EVM Cycles\n");

   for (tpi = 0; tpi < test_cases; tpi++) {

      int32_t       status_nat_vs_opt = TI_TEST_KERNEL_PASS;
      int32_t       status_opt_vs_ref = TI_TEST_KERNEL_PASS;
      FFTLIB_STATUS status_opt        = FFTLIB_SUCCESS;
      FFTLIB_STATUS status_nat        = FFTLIB_SUCCESS;
      uint32_t      numPoints;
      uint32_t      numChannels;
      uint32_t      numPointsIn;
      uint8_t       inMode;
      FFTLIB_F32   *pX;
      FFTLIB_F32   *pXFFT;
      FFTLIB_F32   *pXFFTCn;
      FFTLIB_F32   *pY;
      FFTLIB_F32   *pXCn;
      FFTLIB_F32   *pYCn;
      FFTLIB_F32   *pW;
      FFTLIB_F32   *pSf;

      testNum     = prm[tpi].testID;
      numPoints   = prm[tpi].numPoints;
      numChannels = prm[tpi].numChannels;
      inMode      = prm[tpi].inMode;

      numPointsIn = (inMode == 0) ? (numPoints >> 1) + 1 : numPoints;

      pX = (FFTLIB_F32 *) TI_memalign(128, numChannels * numPointsIn * 2 * sizeof(FFTLIB_F32)); /* pX is required to be
                                                                                               16-byte aligned for
                                                                                               streaming engine use
                                                                                               in kernel */
      pXFFT = (FFTLIB_F32 *) TI_memalign(128, numChannels * (numPoints + 1) * 2 * sizeof(FFTLIB_F32));
      pY    = (FFTLIB_F32 *) TI_memalign(128, numChannels * (numPoints + 1) * sizeof(FFTLIB_F32));
      pW    = (FFTLIB_F32 *) TI_memalign(128, numPoints * 2 * sizeof(FFTLIB_F32));
#if defined(__C7504__) || defined(__C7524__)
      pXCn    = (FFTLIB_F32 *) ddrBuffer;
      pXFFTCn = (FFTLIB_F32 *) pXCn + numChannels * numPointsIn * 2;
#else
      pXCn    = (FFTLIB_F32 *) msmcBuffer;
      pXFFTCn = (FFTLIB_F32 *) pXCn + numChannels * numPoints * 2;
#endif
      pYCn = pXFFTCn + numChannels * numPoints * 2;
      /* pYCn = (FFTLIB_F32 *) malloc (numPoints * 2 * sizeof (FFTLIB_F32)); */

      /* #if defined(__C7504__) */
      /*       pSf = (FFTLIB_F32 *) l2auxBuffer; */
      /* #else */
      /*       pSf     = (FFTLIB_F32 *) TI_memalign (128, (numPoints + 1) * 2 *
       */
      /*                                                      sizeof
       * (FFTLIB_F32)); */
      /* #endif */
      pSf = (FFTLIB_F32 *) TI_memalign(128, (numPoints + 1) * 2 * sizeof(FFTLIB_F32));

      if (pX && pY && pW && pYCn && pSf && pXFFTCn) {
         FFTLIB_bufParams1D_t bufParamsData;
         if ((prm[tpi].testPattern == RANDOM) || (prm[tpi].testPattern == RANDOM_SIGNED)) {
            uint32_t i = 0;
            for (i = 0; i < numChannels * numPointsIn * 2; i++) {
               pX[i] = (float) rand() / (float) (RAND_MAX / (1 << 8)) - (1 << 7);
            }
         }
         else {
            TI_fillBuffer(prm[tpi].testPattern, 0, pX, prm[tpi].staticIn0, numPointsIn * 2 * numChannels, 1, 1,
                          sizeof(FFTLIB_F32), testPatternString);
         }

         TI_fillBuffer(STATIC, 0, pXCn, pX, numChannels * numPointsIn * 2, 1, 1, sizeof(FFTLIB_F32), testPatternString);

         bufParamsData.dim_x     = numPoints * numChannels;
         bufParamsData.data_type = FFTLIB_FLOAT32;

         ifft_c2r_tw_gen(pW, numPoints);
         ifft_c2r_split_factor_gen(pSf, numPoints);

         TI_profile_start(TI_PROFILE_KERNEL_INIT);
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_init(
             (FFTLIB_F32 *) pX, &bufParamsData, (FFTLIB_F32 *) pW, &bufParamsData, (FFTLIB_F32 *) pXFFT, &bufParamsData,
             (FFTLIB_F32 *) pSf, &bufParamsData, (FFTLIB_F32 *) pY, &bufParamsData, numPoints, numChannels, inMode,
             FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         TI_profile_stop();

         TI_profile_start(TI_PROFILE_KERNEL_OPT);
         FFTLIB_asm(" MARK 0");
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_kernel(
             (FFTLIB_F32 *) pX, &bufParamsData, (FFTLIB_F32 *) pW, &bufParamsData, (FFTLIB_F32 *) pXFFT, &bufParamsData,
             (FFTLIB_F32 *) pSf, &bufParamsData, (FFTLIB_F32 *) pY, &bufParamsData, numPoints, numChannels, inMode,
             FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);

         FFTLIB_asm(" MARK 1");
         TI_profile_stop();

#if (defined(RTL_TEST) || defined(QT_TEST) || defined(EVM_TEST))

         TI_fillBuffer(STATIC, 0, pX, pXCn, numChannels * numPointsIn * 2, 1, 1, sizeof(FFTLIB_F32), testPatternString);

         /* run warm instruction cache test */
         uint32_t k;
         for (k = 0; k < 4; k++) 
         {
            TI_profile_clear_cycle_count_single(TI_PROFILE_KERNEL_OPT_WARM);
            TI_profile_start(TI_PROFILE_KERNEL_OPT_WARM);
            FFTLIB_asm(" MARK 2");
            status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_kernel(
                (FFTLIB_F32 *) pX, &bufParamsData, (FFTLIB_F32 *) pW, &bufParamsData, (FFTLIB_F32 *) pXFFT,
                &bufParamsData, (FFTLIB_F32 *) pSf, &bufParamsData, (FFTLIB_F32 *) pY, &bufParamsData, numPoints,
                numChannels, inMode, FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
            FFTLIB_asm(" MARK 3");
            TI_profile_stop();
         }
         TI_fillBuffer(STATIC, 0, pX, pXCn, numChannels * numPointsIn * 2, 1, 1, sizeof(FFTLIB_F32), testPatternString);

         // get output to L1D
         /* uint32_t row    = 0; */
         int32_t col    = 0;
         int16_t outSum = 0;
         // treat output as bytes to be data type agnostic
         FFTLIB_F32 *pDst = (FFTLIB_F32 *) pY;
         /* for (row = 0; row < numChannels; row++) { */
         for (col = 0; col < numPoints; col++) {
            outSum += *pDst;
            pDst++;
         }
         /* } */

         /* dummy store of outSum to insure that the compiler does
   not remove
          * it. */
         volatileSum = outSum;
         TI_profile_start(TI_PROFILE_KERNEL_OPT_WARMWRB);
         FFTLIB_asm(" MARK 4");
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_kernel(
             (FFTLIB_F32 *) pX, &bufParamsData, (FFTLIB_F32 *) pW, &bufParamsData, (FFTLIB_F32 *) pXFFT, &bufParamsData,
             (FFTLIB_F32 *) pSf, &bufParamsData, (FFTLIB_F32 *) pY, &bufParamsData, numPoints, numChannels, inMode,
             FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);

         FFTLIB_asm(" MARK 5");
         TI_profile_stop();

#endif

         TI_profile_start(TI_PROFILE_KERNEL_CN);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_cn((FFTLIB_F32 *) pXCn, &bufParamsData, (FFTLIB_F32 *) pW,
                                                               &bufParamsData, (FFTLIB_F32 *) pXFFTCn, &bufParamsData,
                                                               (FFTLIB_F32 *) pSf, &bufParamsData, (FFTLIB_F32 *) pYCn,
                                                               &bufParamsData, numPoints, numChannels, inMode);
         TI_profile_stop();

         status_nat_vs_opt = TI_compare_mem_2D_float((void *) pYCn, (void *) pY, 0, (double) powf(10, -3), numPoints,
                                                     numChannels, numPoints, sizeof(FFTLIB_F32));

         if (prm[tpi].staticOut != NULL) {
            status_opt_vs_ref =
                TI_compare_mem_2D_float((void *) prm[tpi].staticOut, (void *) pY, 0, (double) powf(10, -3), numPoints,
                                        numChannels, numPoints, sizeof(FFTLIB_F32));

            /* printf ("StaticRef below:\n"); */
            /* int32_t i; */
            /* for (i = 0; i < 2 * numPoints; i += 2) { */
            /*    printf ("%d: %.2f, %.2f\n", i >> 1, */
            /*            (FFTLIB_F32) prm[tpi].staticOut[i], */
            /*            (FFTLIB_F32) (prm[tpi].staticOut[i + 1])); */
            /* } */
         }

         currentTestFail = ((status_nat_vs_opt == TI_TEST_KERNEL_FAIL) || (status_opt_vs_ref == TI_TEST_KERNEL_FAIL) ||
                            (status_opt != FFTLIB_SUCCESS) || (status_nat != FFTLIB_SUCCESS))
                               ? 1
                               : 0;

         fail = ((fail == 1) || (currentTestFail == 1)) ? 1 : 0;

         pProfile[3 * tpi]     = (int32_t) TI_profile_get_cycles(TI_PROFILE_KERNEL_OPT);
         pProfile[3 * tpi + 1] = (int32_t) TI_profile_get_cycles(TI_PROFILE_KERNEL_OPT_WARM);
         pProfile[3 * tpi + 2] = (int32_t) TI_profile_get_cycles(TI_PROFILE_KERNEL_OPT_WARMWRB);
         /* est_test = 1; */
         sprintf(desc, "%s generated input | numPoints=%d | numChannels=%d | inMode=%d", testPatternString, numPoints,
                 numChannels, inMode);

         fprintf(fpOutputCSV, "%d, %d, %d, %d\n", testNum, numChannels, numPoints, pProfile[3 * tpi + 1] / NUM_RUNS);

         uint64_t archCycles = 0, estCycles = 0;
         /* TI_profile_formula_add_test ( */
         /*     numPoints * numChannels, 1, NULL, fail, desc, 1); */

         TI_profile_add_test(testNum++, numPoints, archCycles, estCycles, currentTestFail, desc);
      }
      else {
         sprintf(desc, "numPoints=%d", numPoints);
         TI_profile_skip_test(desc);
      }

      TI_align_free(pX);
      TI_align_free(pXFFT);
      TI_align_free(pSf);
      TI_align_free(pY);
      TI_align_free(pW);
      /* free (pYCn); */
   }

   /* Close results CSV */
   fclose(fpOutputCSV);

   return fail;
}

int test_main(uint32_t *pProfile)
{
#if !defined(_HOST_BUILD)
   if (TI_cache_init()) {
      TI_memError("FFTLIB_fft1dBatched_i32fc_c32fc_o32fc");
      return 1;
   }
   else
#else
   printf("_HOST_BUILD is defined.\n");
#endif //_HOST_BUILD
   {
      return FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_d(&pProfile[0], 0);
   }
}

int coverage_test_main()
{
   const uint32_t numPoints   = 60U;
   const uint32_t numChannels = 4U;
   const uint32_t dimX        = numPoints * numChannels; 
   
   uint32_t       testNum     = 1000;
   int32_t        fail        = 0;

   FFTLIB_bufParams1D_t bufParamsData;
   bufParamsData.dim_x     = dimX;
   bufParamsData.data_type = FFTLIB_FLOAT32;

   FFTLIB_F32 *pX = (FFTLIB_F32 *) TI_memalign(128, dimX * sizeof(FFTLIB_F32));
   FFTLIB_F32 *pW = (FFTLIB_F32 *) TI_memalign(128, dimX * sizeof(FFTLIB_F32));
   FFTLIB_F32 *pY = (FFTLIB_F32 *) TI_memalign(128, dimX * sizeof(FFTLIB_F32));

   if (!pX || !pW || !pY) {
      sprintf(desc, "%s", "COVERAGE TEST - allocation failure");
      TI_profile_skip_test(desc);
      TI_align_free(pX);
      TI_align_free(pW);
      TI_align_free(pY);
      return 1;
   }

   while (testNum <= 1010) {
      FFTLIB_bufParams1D_t bufParamsX = bufParamsData;
      FFTLIB_bufParams1D_t bufParamsW = bufParamsData;
      FFTLIB_bufParams1D_t bufParamsY = bufParamsData;
      FFTLIB_STATUS        status_opt = FFTLIB_SUCCESS, status_nat = FFTLIB_SUCCESS;
      int32_t              currentTestFail = 0;

      switch (testNum) {
      case 1000: /* NULL pX */
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(NULL, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(NULL, &bufParamsX, pW, &bufParamsW, pY,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_NULL_POINTER) || (status_nat != FFTLIB_ERR_NULL_POINTER)) ? 1 : 0;
         break;
      case 1001: /* NULL pW */
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, NULL, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, NULL, &bufParamsW, pY,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_NULL_POINTER) || (status_nat != FFTLIB_ERR_NULL_POINTER)) ? 1 : 0;
         break;
      case 1002: /* NULL pY */
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, pW, &bufParamsW, NULL, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, pW, &bufParamsW, NULL,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_NULL_POINTER) || (status_nat != FFTLIB_ERR_NULL_POINTER)) ? 1 : 0;
         break;
      case 1003: /* bufParamsX->dim_x != bufParamsW->dim_x */
         bufParamsW.dim_x = dimX / 2U;
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, pW, &bufParamsW, pY,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_INVALID_DIMENSION) || (status_nat != FFTLIB_ERR_INVALID_DIMENSION)) ? 1 : 0;
         break;
      case 1004: /* bufParamsX->dim_x != bufParamsY->dim_x */
         bufParamsY.dim_x = dimX / 2U;
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, pW, &bufParamsW, pY,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail =
             ((status_opt != FFTLIB_ERR_INVALID_DIMENSION) || (status_nat != FFTLIB_ERR_INVALID_DIMENSION)) ? 1 : 0;
         break;
      case 1005: /* bufParamsX->data_type != FFTLIB_FLOAT32 */
         bufParamsX.data_type = (uint32_t) FFTLIB_UINT32;
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, pW, &bufParamsW, pY,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_INVALID_TYPE) || (status_nat != FFTLIB_ERR_INVALID_TYPE)) ? 1 : 0;
         break;
      case 1006: /* bufParamsW->data_type != FFTLIB_FLOAT32 */
         bufParamsW.data_type = (uint32_t) FFTLIB_UINT32;
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, pW, &bufParamsW, pY,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_INVALID_TYPE) || (status_nat != FFTLIB_ERR_INVALID_TYPE)) ? 1 : 0;
         break;
      case 1007: /* bufParamsY->data_type != FFTLIB_FLOAT32 */
         bufParamsY.data_type = (uint32_t) FFTLIB_UINT32;
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, pW, &bufParamsW, pY,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_INVALID_TYPE) || (status_nat != FFTLIB_ERR_INVALID_TYPE)) ? 1 : 0;
         break;
      case 1008: { /* pX not 16-byte aligned; checkParams_cn has no alignment
                    * check, so it is expected to still succeed */
         FFTLIB_F32 *pXMisaligned = (FFTLIB_F32 *) (((int8_t *) pX) + sizeof(FFTLIB_F32));
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pXMisaligned, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pXMisaligned, &bufParamsX, pW, &bufParamsW,
                                                                           pY, &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_NOT_ALIGNED_PTRS_STRIDES) || (status_nat != FFTLIB_SUCCESS)) ? 1 : 0;
      } break;
      case 1009: /* numPoints / 2 is not a product of {2, 3, 5} */
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, 14U, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, pW, &bufParamsW, pY,
                                                                           &bufParamsY, 14U, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_ERR_INVALID_DIMENSION) || (status_nat != FFTLIB_ERR_INVALID_DIMENSION)) ? 1 : 0;
         break;
      case 1010: /* success path with the baseline numPoints=60, numChannels=4
                  * (complex iFFT size 60/2 = 30 = 2*3*5) */
         status_opt = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(pX, &bufParamsX, pW, &bufParamsW, pY, &bufParamsY, numPoints, numChannels, 0U,
                                                                        FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_pBlock);
         status_nat = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(pX, &bufParamsX, pW, &bufParamsW, pY,
                                                                           &bufParamsY, numPoints, numChannels, 0U);
         currentTestFail = ((status_opt != FFTLIB_SUCCESS) || (status_nat != FFTLIB_SUCCESS)) ? 1 : 0;
         break;
      default:
         break;
      }

      fail = ((fail == 1) || (currentTestFail == 1)) ? 1 : 0;

      sprintf(desc, "%s", "COVERAGE TEST");
      TI_profile_add_test(testNum++, 0, 0, 0, currentTestFail, desc);
   }

   TI_align_free(pX);
   TI_align_free(pW);
   TI_align_free(pY);

   return fail;
}

/* Main call for individual test projects */
#if !defined(__ONESHOTTEST) && !defined(RTL_TEST)
int main()
{
   int test_fail = 1, cov_fail = 1;

   uint32_t profile[256 * 3];

   FFTLIB_TEST_init();

   test_fail = test_main(&profile[0]);
   cov_fail  = coverage_test_main();

#if !defined(NO_PRINTF)
   if ((test_fail == 0) && (cov_fail == 0))
      printf("Test Pass!\n");
   else
      printf("Test Fail!\n");

   int i;
   for (i = 0; i < test_cases; i++) {
      printf("Test %4d: Cold Cycles = %8d, Warm Cycles = %8d, Warm Cycles WRB "
             "= %8d\n",
             i, profile[3 * i], profile[3 * i + 1], profile[3 * i + 2]);
   }
#endif

   return test_fail || cov_fail;
}
#endif

/* ======================================================================== */
/*  End of file:  FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_d.c                        */
/* ======================================================================== */
