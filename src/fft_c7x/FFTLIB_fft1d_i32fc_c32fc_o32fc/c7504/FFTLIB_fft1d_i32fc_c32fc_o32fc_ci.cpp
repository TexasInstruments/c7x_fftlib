// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "../FFTLIB_fft1d_i32fc_c32fc_o32fc.h"

#define TRACE_ON (0)
#define LAST_LOOP_UNROLL 0

#if TRACE_ON
#include "../../../common/printv.h"
#include <stdio.h>
#endif

// CODE_SECTION(FFTLIB_fft1d,              ".text:optimized")
// CODE_SECTION(FFTLIB_fft1d_core,         ".text:optimized")
// CODE_SECTION(FFTLIB_fft1d_checkParams,  ".text:optimized")

#define SE_PARAM_BASE (0x0000)
/* SE params for radix-5 */
#define SE_RADIX5_PARAM_OFFSET (SE_PARAM_BASE)
#define SE_RADIX5_TWID_PARAM_OFFSET (SE_RADIX5_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE_RADIX5_LOOP1_PARAM_OFFSET (SE_RADIX5_TWID_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE0_RADIX5_REORDER_PARAM_OFFSET (SE_RADIX5_LOOP1_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE1_RADIX5_REORDER_PARAM_OFFSET (SE0_RADIX5_REORDER_PARAM_OFFSET + SE_PARAM_SIZE)
/* SA params for radix-5 */
#define SA_RADIX5_PARAM_OFFSET (SE1_RADIX5_REORDER_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA_RADIX5_LOOP1_PARAM_OFFSET (SA_RADIX5_PARAM_OFFSET + SA_PARAM_SIZE)
#define SA0_RADIX5_REORDER_PARAM_OFFSET (SA_RADIX5_LOOP1_PARAM_OFFSET + SA_PARAM_SIZE)
#define SA1_RADIX5_REORDER_PARAM_OFFSET (SA0_RADIX5_REORDER_PARAM_OFFSET + SA_PARAM_SIZE)
/* SE params for radix-3 */
#define SE_RADIX3_PARAM_OFFSET (SA1_RADIX5_REORDER_PARAM_OFFSET + SA_PARAM_SIZE)
#define SE_RADIX3_TWID_PARAM_OFFSET (SE_RADIX3_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE_RADIX3_LOOP1_PARAM_OFFSET (SE_RADIX3_TWID_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE0_RADIX3_REORDER_PARAM_OFFSET (SE_RADIX3_LOOP1_PARAM_OFFSET + SE_PARAM_SIZE)
/* SA params for radix-3 */
#define SA_RADIX3_PARAM_OFFSET (SE0_RADIX3_REORDER_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA_RADIX3_LOOP1_PARAM_OFFSET (SA_RADIX3_PARAM_OFFSET + SA_PARAM_SIZE)
#define SA0_RADIX3_REORDER_PARAM_OFFSET (SA_RADIX3_LOOP1_PARAM_OFFSET + SA_PARAM_SIZE)
/* SE params for radix-4 / radix-2 */
#define SE_LOOP1_PARAM_OFFSET (SA0_RADIX3_REORDER_PARAM_OFFSET + SA_PARAM_SIZE)
#define SE_LOOP2_PARAM_OFFSET (SE_LOOP1_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE_LOOP3_PARAM_OFFSET (SE_LOOP2_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE_LOOP4_PARAM_OFFSET (SE_LOOP3_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE_LOOP5_PARAM_OFFSET (SE_LOOP4_PARAM_OFFSET + SE_PARAM_SIZE)
#define SE_TWID_PARAM_OFFSET (SE_LOOP5_PARAM_OFFSET + SE_PARAM_SIZE)
/* SA params for radix-4 / radix-2 */
#define SA_LOOP1_PARAM_OFFSET (SE_TWID_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA_LOOP2_PARAM_OFFSET (SA_LOOP1_PARAM_OFFSET + SA_PARAM_SIZE)
#define SA_LOOP3_PARAM_OFFSET (SA_LOOP2_PARAM_OFFSET + SA_PARAM_SIZE)
#define STAGE_INFO_OFFSET (SA_LOOP3_PARAM_OFFSET + SA_PARAM_SIZE)

#define STAGE_R5_ITER_CNT  (8U)
#define STAGE_R5_DIM_CNT   (9U)
#define STAGE_R5_DIM0      (10U)
#define STAGE_R3_ITER_CNT  (11U)
#define STAGE_R3_DIM_CNT   (12U)
#define STAGE_R3_DIM0      (13U)
#define STAGE_R3_TAIL_ICNT (14U)
#define STAGE_R3_TAIL_DIM  (15U)

FFTLIB_STATUS
FFTLIB_fft1d_i32fc_c32fc_o32fc_init(FFTLIB_F32           *pX,
                                    FFTLIB_bufParams1D_t *bufParamsX,
                                    FFTLIB_F32           *pW,
                                    FFTLIB_bufParams1D_t *bufParamsW,
                                    FFTLIB_F32           *pY,
                                    FFTLIB_bufParams1D_t *bufParamsY,
                                    void                 *pBlock)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

#if defined(FFTLIB_CHECK_PARAMS) || defined(FFTLIB_FFT1D_I32FC_C32FC_O32FC_CHECK_PARAMS)
   status = FFTLIB_fft1d_i32fc_c32fc_o32fc_checkParams(pX, bufParamsX, pW, bufParamsW, pY, bufParamsY, pBlock);
   if (status == FFTLIB_SUCCESS)
#endif
   {
      uint32_t         numPoints;
      uint32_t         numPointsPerDft;
      uint32_t         seCnt1, seCnt2, seCnt3, seCnt4;
      uint32_t numRadix5Stages = 0;
      uint32_t numRadix3Stages = 0;
      uint32_t numRadix4Stages = 0;
      uint32_t numRadix2Stages = 0;

      __SE_TEMPLATE_v1 se0_param = __gen_SE_TEMPLATE_v1();
      __SE_TEMPLATE_v1 se1_param = __gen_SE_TEMPLATE_v1();
      __SA_TEMPLATE_v1 sa0_param = __gen_SA_TEMPLATE_v1();

      numPoints       = bufParamsX->dim_x >> 1;

      uint32_t stageTemp = numPoints;
      while (stageTemp > 1U) {
         if (stageTemp % 5U == 0U) {
            numRadix5Stages++;
            stageTemp /= 5U;
         }
         else if (stageTemp % 3U == 0U) {
            numRadix3Stages++;
            stageTemp /= 3U;
         }
         else if (stageTemp % 4U == 0U) {
            numRadix4Stages++;
            stageTemp /= 4U;
         }
         else if (stageTemp % 2U == 0U) {
            numRadix2Stages++;
            stageTemp /= 2U;
         }
      }

      uint32_t numBitRevGrps = 1U;
      uint32_t numDigitRevGrps = 1U;
      for (uint32_t s5 = 0U; s5 < numRadix5Stages; s5++)
      {
         numDigitRevGrps *= 5U;
         numBitRevGrps *= 5U;
      }
      for (uint32_t s3 = 0U; s3 < numRadix3Stages; s3++)
      {
         numBitRevGrps *= 3U;
      }
      
      uint32_t bitRevPoints = numPoints / numBitRevGrps;
      uint32_t digitRevNumPoints = numPoints/numDigitRevGrps;

      uint32_t *pStageInfo = (uint32_t *) ((uint8_t *) pBlock + STAGE_INFO_OFFSET);

      pStageInfo[0] = numRadix5Stages;
      pStageInfo[1] = numRadix3Stages;
      pStageInfo[2] = numRadix4Stages;
      pStageInfo[3] = numRadix2Stages;
      pStageInfo[4] = numBitRevGrps;
      pStageInfo[5] = bitRevPoints;
      pStageInfo[6] = (numRadix4Stages == 0U && numRadix2Stages == 0U && numRadix3Stages == 0U && numRadix5Stages > 0U) ? 1U : 0U;
      pStageInfo[7] = (numRadix4Stages == 0U && numRadix2Stages == 0U && numRadix5Stages == 0U && numRadix3Stages > 0U) ? 1U : 0U;

      pStageInfo[STAGE_R5_ITER_CNT]  = 1U;
      pStageInfo[STAGE_R5_DIM_CNT]   = 0U;
      pStageInfo[STAGE_R5_DIM0]      = 0U;
      pStageInfo[STAGE_R3_ITER_CNT]  = 1U;
      pStageInfo[STAGE_R3_DIM_CNT]   = 0U;
      pStageInfo[STAGE_R3_DIM0]      = 0U;
      pStageInfo[STAGE_R3_TAIL_ICNT] = 0U;
      pStageInfo[STAGE_R3_TAIL_DIM]  = 0U;
      
      numPointsPerDft = numPoints;
      seCnt1          = numPoints >> 2;
      seCnt2          = numPoints >> 4;
      seCnt3          = 1;
      seCnt4          = pStageInfo[5] >> 2;

      uint32_t elementSize = c7x::element_count_of<c7x::cfloat_vec>::value;

      if (numRadix5Stages > 0) {
         se0_param.ICNT0 = elementSize;
         se0_param.ICNT1 = 5;
         se0_param.DIM1  = numPoints / 5;
         se0_param.ICNT2 = numPoints / 5;
         se0_param.DIM2  = elementSize;
         se0_param.ICNT3 = numPoints / 5;
         se0_param.DIM3  = elementSize * (numPoints / 5);

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_4D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX5_PARAM_OFFSET)) = se0_param;

         se0_param.ICNT0 = elementSize;
         se0_param.ICNT1 = 4;
         se0_param.DIM1  = numPoints / 5;
         se0_param.ICNT2 = numPoints / 5;
         se0_param.DIM2  = elementSize;
         se0_param.ICNT3 = numPoints / 5;
         se0_param.DIM3  = elementSize;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_4D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX5_TWID_PARAM_OFFSET)) = se0_param;

         sa0_param.ICNT0 = elementSize;
         sa0_param.ICNT1 = 5;
         sa0_param.DIM1  = numPoints / 5;
         sa0_param.ICNT2 = numPoints / 5;
         sa0_param.DIM2  = elementSize;
         sa0_param.ICNT3 = numPoints / 5;
         sa0_param.DIM3  = elementSize;

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         sa0_param.DIMFMT = __SA_DIMFMT_4D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_RADIX5_PARAM_OFFSET)) = sa0_param;

         se0_param.ICNT0 = 1;
         se0_param.ICNT1 = 5;
         se0_param.DIM1  = 1;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_2D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX5_LOOP1_PARAM_OFFSET)) = se0_param;

         sa0_param.ICNT0 = 1;
         sa0_param.ICNT1 = 5;
         sa0_param.DIM1  = 1;

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         sa0_param.DIMFMT = __SA_DIMFMT_2D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_RADIX5_LOOP1_PARAM_OFFSET)) = sa0_param;

         se0_param.ICNT0     = numPoints / 5;
         se0_param.ICNT1     = elementSize;
         se0_param.DIM1      = numPoints / 5;
         se0_param.TRANSPOSE = __SE_TRANSPOSE_64BIT;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_2D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_RADIX5_REORDER_PARAM_OFFSET)) = se0_param;

         se0_param.ICNT0     = 1;
         se0_param.ICNT1     = numPoints / 5;
         se0_param.DIM1      = 1;
         se0_param.TRANSPOSE = __SE_TRANSPOSE_OFF;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_2D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_RADIX5_REORDER_PARAM_OFFSET)) = se0_param;

         sa0_param.ICNT0  = 4;
         sa0_param.DIMFMT = __SA_DIMFMT_1D;
        
         uint32_t dimStride = numPoints;
         if (numRadix4Stages == 0 && numRadix2Stages == 0 && numRadix3Stages == 0) {
            if (numRadix5Stages > 1) {
               dimStride       /= 5U;
               sa0_param.ICNT1  = 5;
               sa0_param.DIM1   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_2D;
            }
            if (numRadix5Stages > 2) {
               dimStride /= 5U;
               sa0_param.ICNT2  = 5;
               sa0_param.DIM2   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_3D;
            }
            if (numRadix5Stages > 3) {
               dimStride /= 5U;
               sa0_param.ICNT3  = 5;
               sa0_param.DIM3   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_4D;
            }
            if (numRadix5Stages > 4) {
               dimStride /= 5U;
               sa0_param.ICNT4  = 5;
               sa0_param.DIM4   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_5D;
            }
            if (numRadix5Stages > 5) {
               dimStride /= 5U;
               sa0_param.ICNT5  = 5;
               sa0_param.DIM5   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_6D;
            }
         }
         else{
            uint32_t numPointsRadix4 = numPoints;
            uint32_t stride          = 1U;
            while (numPointsRadix4 % 5 == 0) {
               numPointsRadix4 = numPointsRadix4 / 5;
               stride          = stride * 5U;
            }
            sa0_param.ICNT0 = 4;
            dimStride       = stride;
            if (numRadix5Stages >= 1) {
               sa0_param.ICNT1  = numPointsRadix4;
               sa0_param.DIM1   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_2D;
            }
            if (numRadix5Stages > 1) {
               dimStride /= 5U;
               sa0_param.ICNT2  = 5;
               sa0_param.DIM2   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_3D;
            }
            if (numRadix5Stages > 2) {
               dimStride /= 5U;
               sa0_param.ICNT3  = 5;
               sa0_param.DIM3   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_4D;
            }
            if (numRadix5Stages > 3) {
               dimStride /= 5U;
               sa0_param.ICNT4  = 5;
               sa0_param.DIM4   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_5D;
            }
            if (numRadix5Stages > 4) {
               dimStride /= 5U;
               sa0_param.ICNT5  = 5;
               sa0_param.DIM5   = dimStride;
               sa0_param.DIMFMT = __SA_DIMFMT_6D;
            }
         }

         uint32_t r5Total   = (numRadix4Stages == 0U && numRadix2Stages == 0U && numRadix3Stages == 0U) ? (numRadix5Stages - 1U) : numRadix5Stages;
         uint32_t r5DimCnt  = (r5Total > 5U) ? (r5Total - 5U) : 0U;
         uint32_t r5IterCnt = 1U;
         uint32_t i;
         for (i = 0U; i < r5DimCnt; i++) {
            r5IterCnt *= 5U;
         }
         pStageInfo[STAGE_R5_ITER_CNT] = r5IterCnt;
         pStageInfo[STAGE_R5_DIM_CNT]  = r5DimCnt;
         pStageInfo[STAGE_R5_DIM0]     = dimStride / 5U;

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_RADIX5_REORDER_PARAM_OFFSET)) = sa0_param;

         sa0_param.ICNT0  = 1;
         sa0_param.VECLEN = c7x::sa_veclen<cfloat>::value;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA1_RADIX5_REORDER_PARAM_OFFSET)) = sa0_param;
      }
      if (numRadix3Stages > 0) {
         se0_param.ICNT0 = elementSize;
         se0_param.ICNT1 = 3;
         se0_param.DIM1  = numPoints / 3;
         se0_param.ICNT2 = numPoints / 3;
         se0_param.DIM2  = elementSize;
         se0_param.ICNT3 = numPoints / 3;
         se0_param.DIM3  = elementSize * (numPoints / 3);

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_4D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX3_PARAM_OFFSET)) = se0_param;

         se0_param.ICNT0 = elementSize;
         se0_param.ICNT1 = 2; 
         se0_param.DIM1  = numPoints / 3;
         se0_param.ICNT2 = numPoints / 3;
         se0_param.DIM2  = elementSize;
         se0_param.ICNT3 = numPoints / 3;
         se0_param.DIM3  = elementSize;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_4D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX3_TWID_PARAM_OFFSET)) = se0_param;

         sa0_param.ICNT0 = elementSize;
         sa0_param.ICNT1 = 3;
         sa0_param.DIM1  = numPoints / 3;
         sa0_param.ICNT2 = numPoints / 3;
         sa0_param.DIM2  = elementSize;
         sa0_param.ICNT3 = numPoints / 3;
         sa0_param.DIM3  = elementSize;

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         sa0_param.DIMFMT = __SA_DIMFMT_4D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_RADIX3_PARAM_OFFSET)) = sa0_param;

         se0_param.ICNT0 = 1;
         se0_param.ICNT1 = 3;
         se0_param.DIM1  = 1;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_2D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX3_LOOP1_PARAM_OFFSET)) = se0_param;

         sa0_param.ICNT0 = 1;
         sa0_param.ICNT1 = 3;
         sa0_param.DIM1  = 1;

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         sa0_param.DIMFMT = __SA_DIMFMT_2D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_RADIX3_LOOP1_PARAM_OFFSET)) = sa0_param;

         se0_param.ICNT0     = digitRevNumPoints / 3;
         se0_param.ICNT1     = 3;
         se0_param.DIM1      = digitRevNumPoints / 3;
         se0_param.TRANSPOSE = __SE_TRANSPOSE_64BIT;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_2D;

         if(digitRevNumPoints > 1)
         {
            se0_param.ICNT2    = numDigitRevGrps;
            se0_param.DIM2     = digitRevNumPoints;
            se0_param.DIMFMT  = __SE_DIMFMT_3D;
         }
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_RADIX3_REORDER_PARAM_OFFSET)) = se0_param;

         se0_param.TRANSPOSE = __SE_TRANSPOSE_OFF;
         sa0_param.ICNT0  = 3;
         sa0_param.DIMFMT = __SA_DIMFMT_1D;
         
         uint32_t dim3Stride = numPoints;
         if (numRadix4Stages == 0 && numRadix2Stages == 0 && numRadix5Stages == 0) {
            if (numRadix3Stages > 1) {
               dim3Stride      /= 3U;
               sa0_param.ICNT1  = 3;
               sa0_param.DIM1   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_2D;
            }
            if (numRadix3Stages > 2) {
               dim3Stride      /= 3U;
               sa0_param.ICNT2  = 3;
               sa0_param.DIM2   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_3D;
            }
            if (numRadix3Stages > 3) {
               dim3Stride      /= 3U;
               sa0_param.ICNT3  = 3;
               sa0_param.DIM3   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_4D;
            }
            if (numRadix3Stages > 4) {
               dim3Stride      /= 3U;
               sa0_param.ICNT4  = 3;
               sa0_param.DIM4   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_5D;
            }
            if (numRadix3Stages > 5) {
               dim3Stride      /= 3U;
               sa0_param.ICNT5  = 3;
               sa0_param.DIM5   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_6D;
            }
         }
         else if((numRadix4Stages > 0 || numRadix2Stages > 0 )&& numRadix5Stages == 0){
            uint32_t numPointsRadix4 = numPoints;
            uint32_t stride          = 1U;
            while (numPointsRadix4 % 3 == 0) {
               numPointsRadix4 = numPointsRadix4 / 3;
               stride          = stride * 3U;
            }

            sa0_param.ICNT0 = 3;
            dim3Stride      = stride;
            if (numRadix3Stages >= 1) {
               sa0_param.ICNT1  = numPointsRadix4;
               sa0_param.DIM1   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_2D;
            }
            if (numRadix3Stages > 1) {
               dim3Stride      /= 3U;
               sa0_param.ICNT2  = 3;
               sa0_param.DIM2   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_3D;
            }
            if (numRadix3Stages > 2) {
               dim3Stride      /= 3U;
               sa0_param.ICNT3  = 3;
               sa0_param.DIM3   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_4D;
            }
            if (numRadix3Stages > 3) {
               dim3Stride      /= 3U;
               sa0_param.ICNT4  = 3;
               sa0_param.DIM4   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_5D;
            }
            if (numRadix3Stages > 4) {
               dim3Stride      /= 3U;
               sa0_param.ICNT5  = 3;
               sa0_param.DIM5   = dim3Stride;
               sa0_param.DIMFMT = __SA_DIMFMT_6D;
            }
         }
         else{
            uint32_t numPointsRadix4 = digitRevNumPoints;
            uint32_t stride          = 1U;
         
            while (numPointsRadix4 % 3 == 0) {
               numPointsRadix4 = numPointsRadix4 / 3;
               stride          = stride * 3U;
            }

            sa0_param.ICNT0 = 3;
            dim3Stride      = stride;
            if (numRadix3Stages >= 1) {
               sa0_param.ICNT1  = numPointsRadix4;
               sa0_param.DIM1   = dim3Stride;
               sa0_param.ICNT2  = numDigitRevGrps;
               sa0_param.DIM2   = digitRevNumPoints;
               sa0_param.DIMFMT = __SA_DIMFMT_3D;
            }
            if (numRadix3Stages > 1) {
               dim3Stride      /= 3U;
               sa0_param.ICNT2  = 3;
               sa0_param.DIM2   = dim3Stride;
               sa0_param.ICNT3  = numDigitRevGrps;
               sa0_param.DIM3   = digitRevNumPoints;
               sa0_param.DIMFMT = __SA_DIMFMT_4D;
            }
            if (numRadix3Stages > 2) {
               dim3Stride      /= 3U;
               sa0_param.ICNT3  = 3;
               sa0_param.DIM3   = dim3Stride;
               sa0_param.ICNT4  = numDigitRevGrps;
               sa0_param.DIM4   = digitRevNumPoints;
               sa0_param.DIMFMT = __SA_DIMFMT_5D;
            }
            if (numRadix3Stages > 3) {
               dim3Stride      /= 3U;
               sa0_param.ICNT4  = 3;
               sa0_param.DIM4   = dim3Stride;
               sa0_param.ICNT5  = numDigitRevGrps;
               sa0_param.DIM5   = digitRevNumPoints;
               sa0_param.DIMFMT = __SA_DIMFMT_6D;
            }
            if (numRadix3Stages > 4) {
               dim3Stride     /= 3U;
               sa0_param.ICNT5 = 3;
               sa0_param.DIM5  = dim3Stride;
            }
         }

         uint32_t r3Total   = (numRadix4Stages == 0U && numRadix2Stages == 0U && numRadix5Stages == 0U) ? (numRadix3Stages - 1U) : ((numRadix5Stages > 0U) ? (numRadix3Stages + 1U) : numRadix3Stages);
         uint32_t r3DimCnt  = (r3Total > 5U) ? (r3Total - 5U) : 0U;
         uint32_t r3IterCnt = 1U;
         uint32_t i;
            
         if ((numRadix5Stages > 0U) && (r3DimCnt > 0U)) {
            pStageInfo[STAGE_R3_TAIL_ICNT] = numDigitRevGrps;
            pStageInfo[STAGE_R3_TAIL_DIM]  = digitRevNumPoints;
            r3IterCnt *= numDigitRevGrps;
            r3DimCnt--;
         }
         for (i = 0U; i < r3DimCnt; i++) {
            r3IterCnt *= 3U;
         }
         pStageInfo[STAGE_R3_ITER_CNT] = r3IterCnt;
         pStageInfo[STAGE_R3_DIM_CNT]  = r3DimCnt;
         pStageInfo[STAGE_R3_DIM0]     = dim3Stride / 3U;

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_RADIX3_REORDER_PARAM_OFFSET)) = sa0_param;
            
      }

      if (numRadix4Stages > 0 || numRadix2Stages > 0) {
         se0_param.ICNT0 = elementSize;
         se0_param.ICNT1 = 4; /* 4 quarters(Offsets: 0, N/4, N/2, 3N/4) */
         se0_param.DIM1  = seCnt1;
         se0_param.ICNT2 = seCnt2; /* Number of 8-point fetches within each  */
         se0_param.DIM2  = elementSize;
         se0_param.ICNT3 = seCnt3; /* Number of DFT's  */
         se0_param.DIM3  = numPointsPerDft;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_4D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP1_PARAM_OFFSET)) = se0_param;

         /* se1_param = (0); */
         se1_param.ICNT0 = elementSize;
         se1_param.ICNT1 = 3;
         se1_param.DIM1  = seCnt1; /* Twiddle factors for x1, x2 and x3      */
         se1_param.ICNT2 = seCnt2; /* Number of 8-point fetches within each  */
         se1_param.DIM2  = elementSize;
         se1_param.ICNT3 = seCnt3; /* Number of DFT's                        */
         se1_param.DIM3  = 0;

         se1_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se1_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se1_param.DIMFMT  = __SE_DIMFMT_4D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_TWID_PARAM_OFFSET)) = se1_param;

         /* sa0_param = (0); */
         sa0_param.ICNT0 = elementSize;
         sa0_param.ICNT1 = 4;
         sa0_param.DIM1  = seCnt1; /* Save to each of the 4 quarters         */
         sa0_param.ICNT2 = seCnt2; /* Number of 8-point stores within each   */
         sa0_param.DIM2  = elementSize;
         sa0_param.ICNT3 = seCnt3;
         sa0_param.DIM3  = numPointsPerDft; /* Number of DFT's                */

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         sa0_param.DIMFMT = __SA_DIMFMT_4D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_LOOP1_PARAM_OFFSET)) = sa0_param;

         /* se0_param = (0); */
         se0_param.ICNT0 = elementSize; /* Fetch first two quarters */
         se0_param.ICNT1 = 1;
         se0_param.DIM1  = 16; /* Process two 16-point DFTs in one shot  */
         se0_param.ICNT2 = seCnt2;
         se0_param.DIM2  = 16; /* Half the number of DFT's               */

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         /* se0_param.TRANSPOSE = */
         /*     __SE_TRANSPOSE_128BIT; /\* Using 256BIT transpose required  *\/ */
         /*                            /\* 16-byte alignment on pX          *\/ */
         se0_param.VECLEN = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT = __SE_DIMFMT_3D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP2_PARAM_OFFSET)) = se0_param;

         /* sa0_param = (0); */
         sa0_param.ICNT0 = numPoints;

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         sa0_param.DIMFMT = __SA_DIMFMT_1D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_LOOP2_PARAM_OFFSET)) = sa0_param;

         /* se0_param = (0); */
         se0_param       = __gen_SE_TEMPLATE_v1();
         se0_param.ICNT0 = numPoints;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_1D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP3_PARAM_OFFSET)) = se0_param;

         /* sa0_param = (0); */
         sa0_param.ICNT0 = numPoints;

         sa0_param.VECLEN = c7x::sa_veclen<c7x::cfloat_vec>::value;
         sa0_param.DIMFMT = __SA_DIMFMT_1D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_LOOP3_PARAM_OFFSET)) = sa0_param;

         /* se0_param = (0); */
         se0_param.ICNT0 = seCnt4; /* Fetch consecutive four points for DFT  */
         se0_param.ICNT1 = elementSize;
         se0_param.DIM1  = seCnt4;
         se0_param.ICNT2 = numBitRevGrps;
         se0_param.DIM2  = bitRevPoints;

         /* Fetch 8 points separated by            */ /* (numPoints >>
                                                                  3). This fetch
                                                                  pattern   */
         /* can be used for bit reversal           */

         se0_param.ELETYPE   = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.TRANSPOSE = __SE_TRANSPOSE_64BIT;
         se0_param.VECLEN    = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT    = __SE_DIMFMT_3D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP4_PARAM_OFFSET)) = se0_param;

         /* se0_param = (0); */
         se0_param.ICNT0 = seCnt4;
         se0_param.ICNT1 = elementSize;
         se0_param.DIM1  = seCnt4;
         se0_param.ICNT2 = numBitRevGrps;
         se0_param.DIM2  = bitRevPoints;
         /* Fetch 8 points separated by            */ /* (bitRevPoints >>
                                                                  3). This fetch
                                                                  pattern   */
         /* can be used for bit reversal           */

         se0_param.ELETYPE   = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.TRANSPOSE = __SE_TRANSPOSE_64BIT;
         se0_param.VECLEN    = c7x::se_veclen<c7x::cfloat_vec>::value;
         se0_param.DIMFMT    = __SE_DIMFMT_3D;
         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP5_PARAM_OFFSET)) = se0_param;
      }
   }
   return (status);
}

FFTLIB_STATUS
FFTLIB_fft1d_i32fc_c32fc_o32fc_kernel(FFTLIB_F32           *pX,
                                      FFTLIB_bufParams1D_t *bufParamsX,
                                      FFTLIB_F32           *pW,
                                      FFTLIB_bufParams1D_t *bufParamsW,
                                      FFTLIB_F32           *pY,
                                      FFTLIB_bufParams1D_t *bufParamsY,
                                      void                 *pBlock)
{
   uint32_t         k;
   FFTLIB_STATUS    status = FFTLIB_SUCCESS;
   uint32_t         numPoints;
   uint32_t         numPointsPerDft;
   uint32_t         numLeadingZeros;
   uint32_t         bitRevOffset;
   uint32_t         seCnt1, seCnt2, seCnt3;
   uint32_t         numRadix5Stages = 0;
   uint32_t         numRadix3Stages = 0;
   uint32_t         numRadix4Stages = 0;
   uint32_t         numRadix2Stages = 0;
   __SE_TEMPLATE_v1 se0_param;
   __SE_TEMPLATE_v1 se1_param;
   __SA_TEMPLATE_v1 sa0_param;
   __SA_TEMPLATE_v1 sa1_param;

   cfloat *pSrc;
   cfloat *pDst;

   // unused variable #if 0 section in code
   /* cfloat* restrict pYLocal; */

   cfloat *restrict pWLocal;
   cfloat *restrict pY0;
   cfloat *restrict pY1;
   cfloat *restrict pY2;
   cfloat *restrict pY3;
   cfloat *restrict pY4;
   cfloat *restrict pY5;
   cfloat *restrict pY6;
   cfloat *restrict pY7;

   typedef typename c7x::cfloat_vec CV;
   typedef CV                      *CVP;

   typedef typename c7x::float_vec V;
   typedef V                      *VP;

   CV     vX_0, vX_N_4, vX_N_2, vX_3N_4;
   CV     vSum1, vSum2, vDiff1, vDiff2;
   CV     vTwX1, vTwX2, vTwX3;
   CV     vX0Temp, vX1Temp, vX2Temp, vX3Temp;
   CV     vX0, vX1, vX2, vX3;
   CV     vX_0_1, vX_N_4_1, vX_N_2_1, vX_3N_4_1;
   CV     vSum1_1, vSum2_1, vDiff1_1, vDiff2_1;
   CV     vX0_1, vX1_1, vX2_1, vX3_1;
   CV     vX0_2PtDft_1, vX0_2PtDft_2;
   CV     vX1_2PtDft_1, vX1_2PtDft_2;
   CV     vX2_2PtDft_1, vX2_2PtDft_2;
   CV     vX3_2PtDft_1, vX3_2PtDft_2;
   cfloat twTemp;

#ifdef FFTLIB_CHECK_PARAMS
   status = FFTLIB_fft1d_i32fc_c32fc_o32fc_checkParams(pX, bufParamsX, pW, bufParamsW, pY, bufParamsY, pBlock);
   if (status == FFTLIB_SUCCESS)
#endif
   {
      numPoints       = bufParamsX->dim_x >> 1;
      numPointsPerDft = numPoints;

      /* Retrieve stage counts from pBlock */
      uint32_t *pStageInfo   = (uint32_t *) ((uint8_t *) pBlock + STAGE_INFO_OFFSET);
      numRadix5Stages        = pStageInfo[0];
      numRadix3Stages        = pStageInfo[1];
      numRadix4Stages        = pStageInfo[2];
      numRadix2Stages        = pStageInfo[3];
      uint32_t numBitRevGrps = pStageInfo[4];
      uint32_t bitRevPoints  = pStageInfo[5];
      uint32_t pureRadix5    = pStageInfo[6];
      uint32_t pureRadix3    = pStageInfo[7];

      uint32_t r5IterCnt  = pStageInfo[STAGE_R5_ITER_CNT];
      uint32_t r5DimCnt   = pStageInfo[STAGE_R5_DIM_CNT];
      uint32_t r5Dim0     = pStageInfo[STAGE_R5_DIM0];
      uint32_t r3IterCnt  = pStageInfo[STAGE_R3_ITER_CNT];
      uint32_t r3DimCnt   = pStageInfo[STAGE_R3_DIM_CNT];
      uint32_t r3Dim0     = pStageInfo[STAGE_R3_DIM0];
      uint32_t r3TailIcnt = pStageInfo[STAGE_R3_TAIL_ICNT];
      uint32_t r3TailDim  = pStageInfo[STAGE_R3_TAIL_DIM];
      uint32_t idx;

      pWLocal = (cfloat *) pW;
      /* Execute Radix-5 stages */
      if (numRadix5Stages > 0) {
         CV vecIn0, vecIn1, vecIn2, vecIn3, vecIn4;
         CV vecSum0, vecSum1, vecSum2, vecSum3, vecSum4;
         CV vectw1, vectw2, vectw3, vectw4;
         CV vecDfttw1, vecDfttw2, vecDfttw3, vecDfttw4;

         __cfloat dfttw1, dfttw2, dfttw3, dfttw4;

         se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX5_PARAM_OFFSET));
         se1_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX5_TWID_PARAM_OFFSET));
         sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_RADIX5_PARAM_OFFSET));

         pSrc = (cfloat *) pX;
         pDst = (cfloat *) pY;

         seCnt1 = numPointsPerDft / 5;
         seCnt2 = (seCnt1 + 3) / 4;
         seCnt3 = 1;

         dfttw1.r() = 0.30901699437494745;
         dfttw1.i() = -0.95105651629515353;

         dfttw2.r() = -0.80901699437494734;
         dfttw2.i() = -0.58778525229247325;

         dfttw3.r() = -0.80901699437494734;
         dfttw3.i() = 0.58778525229247325;

         dfttw4.r() = 0.30901699437494745;
         dfttw4.i() = 0.95105651629515353;

         vecDfttw1 = __duplicate(dfttw1);
         vecDfttw2 = __duplicate(dfttw2);
         vecDfttw3 = __duplicate(dfttw3);
         vecDfttw4 = __duplicate(dfttw4);

         /* Execute numRadix5Stages - 1 */
         for (uint32_t r5 = 0; r5 < numRadix5Stages - 1; r5++) {
            se0_param.DIM1          = seCnt1;
            se0_param.ICNT2         = seCnt2;
            se0_param.ICNT3         = seCnt3;
            se0_param.DIM3          = numPointsPerDft;
            se0_param.DECDIM1_WIDTH = seCnt1;
            se0_param.DECDIM1       = __SE_DECDIM_DIM2;

            __SE0_OPEN(pSrc, se0_param);

            se1_param.DIM1          = seCnt1;
            se1_param.ICNT2         = seCnt2;
            se1_param.ICNT3         = seCnt3;
            se1_param.DIM3          = 0;
            se1_param.DECDIM1_WIDTH = seCnt1;
            se1_param.DECDIM1       = __SE_DECDIM_DIM2;
            __SE1_OPEN(pWLocal, se1_param);

            sa0_param.DIM1          = seCnt1;
            sa0_param.ICNT2         = seCnt2;
            sa0_param.ICNT3         = seCnt3;
            sa0_param.DIM3          = numPointsPerDft;
            sa0_param.DECDIM1_WIDTH = seCnt1;
            sa0_param.DECDIM1       = __SA_DECDIM_DIM2;
            __SA0_OPEN(sa0_param);

            uint32_t loopCnt = seCnt2 * seCnt3;

            /* 24 + trip_cnt * 20 */
            for (k = 0; k < loopCnt; k++) {
               vecIn0 = c7x::strm_eng<0, CV>::get_adv();
               vecIn1 = c7x::strm_eng<0, CV>::get_adv();
               vecIn2 = c7x::strm_eng<0, CV>::get_adv();
               vecIn3 = c7x::strm_eng<0, CV>::get_adv();
               vecIn4 = c7x::strm_eng<0, CV>::get_adv();

               vectw1 = c7x::strm_eng<1, CV>::get_adv();
               vectw2 = c7x::strm_eng<1, CV>::get_adv();
               vectw3 = c7x::strm_eng<1, CV>::get_adv();
               vectw4 = c7x::strm_eng<1, CV>::get_adv();

               vecSum0 = vecIn0 + vecIn1 + vecIn2 + vecIn3 + vecIn4;
               vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2 + vecIn3 * vecDfttw3 + vecIn4 * vecDfttw4;
               vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw4 + vecIn3 * vecDfttw1 + vecIn4 * vecDfttw3;
               vecSum3 = vecIn0 + vecIn1 * vecDfttw3 + vecIn2 * vecDfttw1 + vecIn3 * vecDfttw4 + vecIn4 * vecDfttw2;
               vecSum4 = vecIn0 + vecIn1 * vecDfttw4 + vecIn2 * vecDfttw3 + vecIn3 * vecDfttw2 + vecIn4 * vecDfttw1;

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum0);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum1 * vectw1);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum2 * vectw2);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum3 * vectw3);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum4 * vectw4);
            }
            numPointsPerDft /= 5U;
            pWLocal += numPointsPerDft * 4;
            seCnt1 /= 5;
            seCnt2 = (seCnt1 + 3) / 4;
            seCnt3 *= 5;

            __SE0_CLOSE();
            __SE1_CLOSE();
            __SA0_CLOSE();
         }

         /* Last stage of the Radix-5 for mixed radix */
         if (pureRadix5 == 0) {
            se0_param.DIM1          = seCnt1;
            se0_param.ICNT2         = seCnt2;
            se0_param.ICNT3         = seCnt3;
            se0_param.DIM3          = numPointsPerDft;
            se0_param.DECDIM1_WIDTH = seCnt1;
            se0_param.DECDIM1       = __SE_DECDIM_DIM2;

            __SE0_OPEN(pSrc, se0_param);

            se1_param.DIM1          = seCnt1;
            se1_param.ICNT2         = seCnt2;
            se1_param.ICNT3         = seCnt3;
            se1_param.DIM3          = 0;
            se1_param.DECDIM1_WIDTH = seCnt1;
            se1_param.DECDIM1       = __SE_DECDIM_DIM2;
            __SE1_OPEN(pWLocal, se1_param);

            sa0_param.DIM1          = seCnt1;
            sa0_param.ICNT2         = seCnt2;
            sa0_param.ICNT3         = seCnt3;
            sa0_param.DIM3          = numPointsPerDft;
            sa0_param.DECDIM1_WIDTH = seCnt1;
            sa0_param.DECDIM1       = __SA_DECDIM_DIM2;
            __SA0_OPEN(sa0_param);

            uint32_t loopCnt = seCnt2 * seCnt3;

            /* 24 + trip_cnt * 20 */
            for (k = 0; k < loopCnt; k++) {
               vecIn0 = c7x::strm_eng<0, CV>::get_adv();
               vecIn1 = c7x::strm_eng<0, CV>::get_adv();
               vecIn2 = c7x::strm_eng<0, CV>::get_adv();
               vecIn3 = c7x::strm_eng<0, CV>::get_adv();
               vecIn4 = c7x::strm_eng<0, CV>::get_adv();

               vectw1 = c7x::strm_eng<1, CV>::get_adv();
               vectw2 = c7x::strm_eng<1, CV>::get_adv();
               vectw3 = c7x::strm_eng<1, CV>::get_adv();
               vectw4 = c7x::strm_eng<1, CV>::get_adv();

               vecSum0 = vecIn0 + vecIn1 + vecIn2 + vecIn3 + vecIn4;
               vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2 + vecIn3 * vecDfttw3 + vecIn4 * vecDfttw4;
               vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw4 + vecIn3 * vecDfttw1 + vecIn4 * vecDfttw3;
               vecSum3 = vecIn0 + vecIn1 * vecDfttw3 + vecIn2 * vecDfttw1 + vecIn3 * vecDfttw4 + vecIn4 * vecDfttw2;
               vecSum4 = vecIn0 + vecIn1 * vecDfttw4 + vecIn2 * vecDfttw3 + vecIn3 * vecDfttw2 + vecIn4 * vecDfttw1;

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum0);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum1 * vectw1);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum2 * vectw2);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum3 * vectw3);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum4 * vectw4);
            }
            numPointsPerDft /= 5U;
            pWLocal += numPointsPerDft * 4;
            seCnt1 /= 5;
            seCnt2 = (seCnt1 + 3) / 4;
            seCnt3 *= 5;

            __SE0_CLOSE();
            __SE1_CLOSE();
            __SA0_CLOSE();
         }
         else {
            /* Last stage of the Radix-5 + digit Reversal*/
            if (numPoints != 5) {
               se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_RADIX5_REORDER_PARAM_OFFSET));
               se1_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_RADIX5_REORDER_PARAM_OFFSET));
               sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_RADIX5_REORDER_PARAM_OFFSET));
               sa1_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA1_RADIX5_REORDER_PARAM_OFFSET));

               cfloat *pDst1 = pDst + 4;

               cfloat in0, in1, in2, in3, in4;
               cfloat sum0, sum1, sum2, sum3, sum4;

               uint32_t loopCnt = (numPoints / 25) / r5IterCnt;

               __SE0_OPEN(pSrc, se0_param);
               for (uint32_t iter = 0; iter < r5IterCnt; iter++) {
                  uint32_t offset = 0U, rem = iter, dim = r5Dim0;
                  for (idx = 0U; idx < r5DimCnt; idx++) {
                     offset += (rem % 5U) * dim;
                     rem /= 5U;
                     dim /= 5U;
                  }
                  cfloat *pDstLocal = pDst + offset;
                  __SA0_OPEN(sa0_param);

                  /* 15 + trip_cnt * 16 */
                  for (k = 0; k < loopCnt; k++) {
                     vecIn0 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn1 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn2 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn3 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn4 = c7x::strm_eng<0, CV>::get_adv();

                     vecSum0 = vecIn0 + vecIn1 + vecIn2 + vecIn3 + vecIn4;
                     vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2 + vecIn3 * vecDfttw3 + vecIn4 * vecDfttw4;
                     vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw4 + vecIn3 * vecDfttw1 + vecIn4 * vecDfttw3;
                     vecSum3 = vecIn0 + vecIn1 * vecDfttw3 + vecIn2 * vecDfttw1 + vecIn3 * vecDfttw4 + vecIn4 * vecDfttw2;
                     vecSum4 = vecIn0 + vecIn1 * vecDfttw4 + vecIn2 * vecDfttw3 + vecIn3 * vecDfttw2 + vecIn4 * vecDfttw1;

                     __vpred tmp;
                     CVP     addr;
                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum0);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum1);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum2);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum3);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum4);
                  }
                  __SA0_CLOSE();
               }
               __SE0_CLOSE();

               __SE1_OPEN(pSrc + (numPoints / 5) * 4, se1_param);
               for (uint32_t iter = 0; iter < r5IterCnt; iter++) {
                  uint32_t offset = 0U, rem = iter, dim = r5Dim0;
                  for (idx = 0U; idx < r5DimCnt; idx++) {
                     offset += (rem % 5U) * dim;
                     rem /= 5U;
                     dim /= 5U;
                  }
                  cfloat *pDstLocal1 = pDst1 + offset;
                  __SA1_OPEN(sa1_param);
                  /* 22 + trip_cnt * 12 */
                  for (k = 0; k < loopCnt; k++) {
                     in0 = c7x::strm_eng<1, cfloat>::get_adv();
                     in1 = c7x::strm_eng<1, cfloat>::get_adv();
                     in2 = c7x::strm_eng<1, cfloat>::get_adv();
                     in3 = c7x::strm_eng<1, cfloat>::get_adv();
                     in4 = c7x::strm_eng<1, cfloat>::get_adv();

                     sum0 = in0 + in1 + in2 + in3 + in4;
                     sum1 = in0 + in1 * dfttw1 + in2 * dfttw2 + in3 * dfttw3 + in4 * dfttw4;
                     sum2 = in0 + in1 * dfttw2 + in2 * dfttw4 + in3 * dfttw1 + in4 * dfttw3;
                     sum3 = in0 + in1 * dfttw3 + in2 * dfttw1 + in3 * dfttw4 + in4 * dfttw2;
                     sum4 = in0 + in1 * dfttw4 + in2 * dfttw3 + in3 * dfttw2 + in4 * dfttw1;

                     __vpred ftmp;
                     cfloat *faddr;
                     ftmp  = c7x::strm_agen<1, cfloat>::get_vpred();
                     faddr = c7x::strm_agen<1, cfloat>::get_adv(pDstLocal1);
                     __vstore_pred(ftmp, faddr, sum0);

                     ftmp  = c7x::strm_agen<1, cfloat>::get_vpred();
                     faddr = c7x::strm_agen<1, cfloat>::get_adv(pDstLocal1);
                     __vstore_pred(ftmp, faddr, sum1);

                     ftmp  = c7x::strm_agen<1, cfloat>::get_vpred();
                     faddr = c7x::strm_agen<1, cfloat>::get_adv(pDstLocal1);
                     __vstore_pred(ftmp, faddr, sum2);

                     ftmp  = c7x::strm_agen<1, cfloat>::get_vpred();
                     faddr = c7x::strm_agen<1, cfloat>::get_adv(pDstLocal1);
                     __vstore_pred(ftmp, faddr, sum3);

                     ftmp  = c7x::strm_agen<1, cfloat>::get_vpred();
                     faddr = c7x::strm_agen<1, cfloat>::get_adv(pDstLocal1);
                     __vstore_pred(ftmp, faddr, sum4);
                  }
                  __SA1_CLOSE();
               }
               __SE1_CLOSE();
            }
            else {
               /* pureRadix5 with numPoints as 5*/
               se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX5_LOOP1_PARAM_OFFSET));
               sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_RADIX5_LOOP1_PARAM_OFFSET));

               cfloat in0, in1, in2, in3, in4;
               cfloat sum0, sum1, sum2, sum3, sum4;

               __SE0_OPEN(pSrc, se0_param);
               __SA0_OPEN(sa0_param);

               in0 = c7x::strm_eng<0, cfloat>::get_adv();
               in1 = c7x::strm_eng<0, cfloat>::get_adv();
               in2 = c7x::strm_eng<0, cfloat>::get_adv();
               in3 = c7x::strm_eng<0, cfloat>::get_adv();
               in4 = c7x::strm_eng<0, cfloat>::get_adv();

               sum0 = in0 + in1 + in2 + in3 + in4;
               sum1 = in0 + in1 * dfttw1 + in2 * dfttw2 + in3 * dfttw3 + in4 * dfttw4;
               sum2 = in0 + in1 * dfttw2 + in2 * dfttw4 + in3 * dfttw1 + in4 * dfttw3;
               sum3 = in0 + in1 * dfttw3 + in2 * dfttw1 + in3 * dfttw4 + in4 * dfttw2;
               sum4 = in0 + in1 * dfttw4 + in2 * dfttw3 + in3 * dfttw2 + in4 * dfttw1;

               __vpred ftmp;
               cfloat *faddr;
               ftmp  = c7x::strm_agen<0, cfloat>::get_vpred();
               faddr = c7x::strm_agen<0, cfloat>::get_adv(pDst);
               __vstore_pred(ftmp, faddr, sum0);

               ftmp  = c7x::strm_agen<0, cfloat>::get_vpred();
               faddr = c7x::strm_agen<0, cfloat>::get_adv(pDst);
               __vstore_pred(ftmp, faddr, sum1);

               ftmp  = c7x::strm_agen<0, cfloat>::get_vpred();
               faddr = c7x::strm_agen<0, cfloat>::get_adv(pDst);
               __vstore_pred(ftmp, faddr, sum2);

               ftmp  = c7x::strm_agen<0, cfloat>::get_vpred();
               faddr = c7x::strm_agen<0, cfloat>::get_adv(pDst);
               __vstore_pred(ftmp, faddr, sum3);

               ftmp  = c7x::strm_agen<0, cfloat>::get_vpred();
               faddr = c7x::strm_agen<0, cfloat>::get_adv(pDst);
               __vstore_pred(ftmp, faddr, sum4);

               __SE0_CLOSE();
               __SA0_CLOSE();
            }
         }
      }
      if (numRadix3Stages > 0) {
         CV vecIn0, vecIn1, vecIn2;
         CV vecSum0, vecSum1, vecSum2;
         CV vectw1, vectw2;
         CV vecDfttw1, vecDfttw2;

         __cfloat dfttw1, dfttw2;

         se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX3_PARAM_OFFSET));
         se1_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX3_TWID_PARAM_OFFSET));
         sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_RADIX3_PARAM_OFFSET));

         pSrc = (numRadix5Stages > 0) ? ((numRadix4Stages == 0 && numRadix2Stages == 0) ? (cfloat *) pY : (cfloat *) pY) : (cfloat *) pX;
         pDst = (numRadix5Stages > 0) ? ((numRadix4Stages == 0 && numRadix2Stages == 0) ? (cfloat *) pY : (cfloat *) pX) : (cfloat *) pY; 

         seCnt1 = numPointsPerDft / 3;
         seCnt2 = (seCnt1 + 3) / 4;
         seCnt3 = numPoints / numPointsPerDft;

         dfttw1.r() = -0.5;
         dfttw1.i() = -0.86602540378443871;

         dfttw2.r() = -0.5;
         dfttw2.i() = 0.86602540378443871;

         vecDfttw1 = __duplicate(dfttw1);
         vecDfttw2 = __duplicate(dfttw2);

         /* Execute numRadix3Stages - 1 */
         for (uint32_t r3 = 0; r3 < numRadix3Stages - 1; r3++) {
            se0_param.DIM1          = seCnt1;
            se0_param.ICNT2         = seCnt2;
            se0_param.ICNT3         = seCnt3;
            se0_param.DIM3          = numPointsPerDft;
            se0_param.DECDIM1_WIDTH = seCnt1;
            se0_param.DECDIM1       = __SE_DECDIM_DIM2;

            __SE0_OPEN(pSrc, se0_param);

            se1_param.DIM1          = seCnt1;
            se1_param.ICNT2         = seCnt2;
            se1_param.ICNT3         = seCnt3;
            se1_param.DIM3          = 0;
            se1_param.DECDIM1_WIDTH = seCnt1;
            se1_param.DECDIM1       = __SE_DECDIM_DIM2;
            __SE1_OPEN(pWLocal, se1_param);

            sa0_param.DIM1          = seCnt1;
            sa0_param.ICNT2         = seCnt2;
            sa0_param.ICNT3         = seCnt3;
            sa0_param.DIM3          = numPointsPerDft;
            sa0_param.DECDIM1_WIDTH = seCnt1;
            sa0_param.DECDIM1       = __SA_DECDIM_DIM2;
            __SA0_OPEN(sa0_param);

            uint32_t loopCnt = ((seCnt2 * seCnt3) + 1) / 2;
               
            /* 21 + trip_cnt * 12 */
            for (k = 0; k < loopCnt; k++) {
               /* unroll 1 */
               vecIn0 = c7x::strm_eng<0, CV>::get_adv();
               vecIn1 = c7x::strm_eng<0, CV>::get_adv();
               vecIn2 = c7x::strm_eng<0, CV>::get_adv();

               vectw1 = c7x::strm_eng<1, CV>::get_adv();
               vectw2 = c7x::strm_eng<1, CV>::get_adv();

               vecSum0 = vecIn0 + vecIn1 + vecIn2;
               vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2;
               vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw1;
            
               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum0);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum1 * vectw1);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum2 * vectw2);

               /* unroll 2 */
               vecIn0 = c7x::strm_eng<0, CV>::get_adv();
               vecIn1 = c7x::strm_eng<0, CV>::get_adv();
               vecIn2 = c7x::strm_eng<0, CV>::get_adv();

               vectw1 = c7x::strm_eng<1, CV>::get_adv();
               vectw2 = c7x::strm_eng<1, CV>::get_adv();

               vecSum0 = vecIn0 + vecIn1 + vecIn2;
               vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2;
               vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw1;
            
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum0);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum1 * vectw1);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vecSum2 * vectw2);
                  
            }
               numPointsPerDft /= 3U;
               pWLocal += numPointsPerDft * 2;
               seCnt1 /= 3;
               seCnt2 = (seCnt1 + 3) / 4;
               seCnt3 *= 3;

               __SE0_CLOSE();
               __SE1_CLOSE();
               __SA0_CLOSE();
         }

         /* Last stage of the Radix-3 for mixed radix */
         if (pureRadix3 == 0) {
            se0_param.DIM1          = seCnt1;
            se0_param.ICNT2         = seCnt2;
            se0_param.ICNT3         = seCnt3;
            se0_param.DIM3          = numPointsPerDft;
            se0_param.DECDIM1_WIDTH = seCnt1;
            se0_param.DECDIM1       = __SE_DECDIM_DIM2;

            __SE0_OPEN(pSrc, se0_param);

            se1_param.DIM1          = seCnt1;
            se1_param.ICNT2         = seCnt2;
            se1_param.ICNT3         = seCnt3;
            se1_param.DIM3          = 0;
            se1_param.DECDIM1_WIDTH = seCnt1;
            se1_param.DECDIM1       = __SE_DECDIM_DIM2;
            __SE1_OPEN(pWLocal, se1_param);

            sa0_param.DIM1          = seCnt1;
            sa0_param.ICNT2         = seCnt2;
            sa0_param.ICNT3         = seCnt3;
            sa0_param.DIM3          = numPointsPerDft;
            sa0_param.DECDIM1_WIDTH = seCnt1;
            sa0_param.DECDIM1       = __SA_DECDIM_DIM2;
            __SA0_OPEN(sa0_param);

            uint32_t loopCnt = ((seCnt2 * seCnt3) + 1) / 2;

            /* 21 + trip_cnt * 12 */
            for (k = 0; k < loopCnt; k++) {
               /* unroll 1 */
               vecIn0 = c7x::strm_eng<0, CV>::get_adv();
               vecIn1 = c7x::strm_eng<0, CV>::get_adv();
               vecIn2 = c7x::strm_eng<0, CV>::get_adv();

               vectw1 = c7x::strm_eng<1, CV>::get_adv();
               vectw2 = c7x::strm_eng<1, CV>::get_adv();

               vecSum0 = vecIn0 + vecIn1 + vecIn2;
               vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2;
               vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw1;
            
               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum0);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum1 * vectw1);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum2 * vectw2);

               /* unroll 2 */
               vecIn0 = c7x::strm_eng<0, CV>::get_adv();
               vecIn1 = c7x::strm_eng<0, CV>::get_adv();
               vecIn2 = c7x::strm_eng<0, CV>::get_adv();

               vectw1 = c7x::strm_eng<1, CV>::get_adv();
               vectw2 = c7x::strm_eng<1, CV>::get_adv();

               vecSum0 = vecIn0 + vecIn1 + vecIn2;
               vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2;
               vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw1;
            
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum0);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum1 * vectw1);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum2 * vectw2);
            }
            
            numPointsPerDft /= 3U;
            pWLocal += numPointsPerDft * 2;
            seCnt1 /= 3;
            seCnt2 = (seCnt1 + 3) / 4;
            seCnt3 *= 3;

            __SE0_CLOSE();
            __SE1_CLOSE();
            __SA0_CLOSE();
         }
         else {
            /* Last stage of the Radix-3 + digit Reversal*/
            if(numPoints == 3)
            {
               /* pureRadix3 with numPoints as 3*/
               se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_RADIX3_LOOP1_PARAM_OFFSET));
               sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_RADIX3_LOOP1_PARAM_OFFSET));

               cfloat in0, in1, in2;
               cfloat sum0, sum1, sum2;

               __SE0_OPEN(pSrc, se0_param);
               __SA0_OPEN(sa0_param);

               in0 = c7x::strm_eng<0, cfloat>::get_adv();
               in1 = c7x::strm_eng<0, cfloat>::get_adv();
               in2 = c7x::strm_eng<0, cfloat>::get_adv();

               sum0 = in0 + in1 + in2;
               sum1 = in0 + in1 * dfttw1 + in2 * dfttw2;
               sum2 = in0 + in1 * dfttw2 + in2 * dfttw1;

               __vpred ftmp;
               cfloat *faddr;
               ftmp  = c7x::strm_agen<0, cfloat>::get_vpred();
               faddr = c7x::strm_agen<0, cfloat>::get_adv(pDst);
               __vstore_pred(ftmp, faddr, sum0);

               ftmp  = c7x::strm_agen<0, cfloat>::get_vpred();
               faddr = c7x::strm_agen<0, cfloat>::get_adv(pDst);
               __vstore_pred(ftmp, faddr, sum1);

               ftmp  = c7x::strm_agen<0, cfloat>::get_vpred();
               faddr = c7x::strm_agen<0, cfloat>::get_adv(pDst);
               __vstore_pred(ftmp, faddr, sum2);

               __SE0_CLOSE();
               __SA0_CLOSE();
            }
            else if (numPoints == 9) {
               se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_RADIX3_REORDER_PARAM_OFFSET));
               sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_RADIX3_REORDER_PARAM_OFFSET));

               __SE0_OPEN(pSrc, se0_param);
               __SA0_OPEN(sa0_param);

               for (k = 0; k < (numPoints / 9); k++) {
               vecIn0 = c7x::strm_eng<0, CV>::get_adv();
               vecIn1 = c7x::strm_eng<0, CV>::get_adv();
               vecIn2 = c7x::strm_eng<0, CV>::get_adv();

               vecSum0 = vecIn0 + vecIn1 + vecIn2;
               vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2;
               vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw1;

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum0);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum1);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp, addr, vecSum2);
               }
            __SE0_CLOSE();
            __SA0_CLOSE();
            }
            else{
               se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_RADIX3_REORDER_PARAM_OFFSET));
               sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_RADIX3_REORDER_PARAM_OFFSET));

               uint32_t loopCnt = (numPoints / 27) / r3IterCnt;

               __SE0_OPEN(pSrc, se0_param);
               for (uint32_t iter = 0; iter < r3IterCnt; iter++) {
                  uint32_t offset = 0U, rem = iter, dim = r3Dim0;
                  for (idx = 0U; idx < r3DimCnt; idx++) {
                     offset += (rem % 3U) * dim;
                     rem /= 3U;
                     dim /= 3U;
                  }
                  offset += (r3TailIcnt != 0U) ? ((rem % r3TailIcnt) * r3TailDim) : 0U;
                  cfloat *pDstLocal = pDst + offset;
                  __SA0_OPEN(sa0_param);

                  /* 18 + trip_cnt * 14 */
                  for (k = 0; k < loopCnt; k++) {
                     vecIn0 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn1 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn2 = c7x::strm_eng<0, CV>::get_adv();

                     vecSum0 = vecIn0 + vecIn1 + vecIn2;
                     vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2;
                     vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw1;

                     __vpred tmp;
                     CVP     addr;
                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum0);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum1);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum2);

                     vecIn0 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn1 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn2 = c7x::strm_eng<0, CV>::get_adv();

                     vecSum0 = vecIn0 + vecIn1 + vecIn2;
                     vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2;
                     vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw1;

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum0);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum1);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum2);

                     vecIn0 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn1 = c7x::strm_eng<0, CV>::get_adv();
                     vecIn2 = c7x::strm_eng<0, CV>::get_adv();

                     vecSum0 = vecIn0 + vecIn1 + vecIn2;
                     vecSum1 = vecIn0 + vecIn1 * vecDfttw1 + vecIn2 * vecDfttw2;
                     vecSum2 = vecIn0 + vecIn1 * vecDfttw2 + vecIn2 * vecDfttw1;

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum0);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum1);

                     tmp  = c7x::strm_agen<0, CV>::get_vpred();
                     addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
                     __vstore_pred(tmp, addr, vecSum2);
                  }
                  __SA0_CLOSE();
               }
               __SE0_CLOSE();
            }
         }
      }

      /* Execute Radix-4 / Radix-2 stages */
      if (numRadix4Stages > 0 || numRadix2Stages > 0) {
         if(numPointsPerDft >= 32){
            se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP1_PARAM_OFFSET));
            se1_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_TWID_PARAM_OFFSET));
            sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_LOOP1_PARAM_OFFSET));
            seCnt1    = numPointsPerDft >> 2;
            seCnt2    = numPointsPerDft >> 4;
            seCnt3    = numPoints / numPointsPerDft;

            pSrc = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pY : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pY : (cfloat *) pX;
            pDst = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pX : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pX : (cfloat *) pY;


            while (numPointsPerDft >= 16) {
               /* TODO OPT: Calculate params upfront in init function,
               *           rather than generating SE params on the fly here */
               se0_param.ICNT1 = 4;
               se0_param.DIM1  = seCnt1; /* 4 quarters(Offsets: 0, N/4, N/2, 3N/4) */
               se0_param.ICNT2 = seCnt2;
               se0_param.DIM2  = 4;
               /* Number of 8-point fetches within       */ /* each quarter */
               se0_param.ICNT3 = seCnt3;
               se0_param.DIM3  = numPointsPerDft; /* Number of DFT's               */
               __SE0_OPEN((void *) pSrc, se0_param);

               se1_param.ICNT1 = 3;
               se1_param.DIM1  = seCnt1; /* Twiddle factors for x1, x2 and x3      */
               se1_param.ICNT2 = seCnt2; /* Number of 8-point fetches within each  */
               se1_param.DIM2  = 4;      /* quarter                                */
               se1_param.ICNT3 = seCnt3; /* Number of DFT's                        */
               se1_param.DIM3  = 0;
               __SE1_OPEN((void *) pWLocal, se1_param);

               sa0_param.ICNT1 = 4;
               sa0_param.DIM1  = /* Save to each of the 4 quarters         */ seCnt1;
               sa0_param.ICNT2 = seCnt2;
               sa0_param.DIM2  = 4;
               /* Number of 8-point stores within        */ /* each quarter */
               sa0_param.ICNT3 = seCnt3;
               sa0_param.DIM3  = numPointsPerDft;
               /* Number of DFT's                        */
               __SA0_OPEN(sa0_param);

               /* Loop is unrolled twice for better optimization */
               for (k = 0; k < numPoints; k += 32) {

                  /* First iteration of loop unroll */
                  vX_0    = c7x::strm_eng<0, CV>::get_adv();
                  vX_N_4  = c7x::strm_eng<0, CV>::get_adv();
                  vX_N_2  = c7x::strm_eng<0, CV>::get_adv();
                  vX_3N_4 = c7x::strm_eng<0, CV>::get_adv();

                  vSum1  = vX_0 + vX_N_2;
                  vSum2  = vX_N_4 + vX_3N_4;
                  vDiff1 = vX_0 - vX_N_2;
                  vDiff2 = vX_N_4 - vX_3N_4;

                  vTwX1 = c7x::strm_eng<1, CV>::get_adv();
                  vTwX2 = c7x::strm_eng<1, CV>::get_adv();
                  vTwX3 = c7x::strm_eng<1, CV>::get_adv();

                  vX0Temp = vSum1 + vSum2;
                  vX1Temp = vDiff1 - __vcrot90sp_vv(vDiff2);
                  vX2Temp = vSum1 - vSum2;
                  vX3Temp = vDiff1 + __vcrot90sp_vv(vDiff2);

                  vX0 = vX0Temp;
                  vX1 = __complex_multiply(vX1Temp, vTwX1);
                  vX2 = __complex_multiply(vX2Temp, vTwX2);
                  vX3 = __complex_multiply(vX3Temp, vTwX3);

                  /* __SA0ADV(CV, pXLocal) = vX0; */
                  /* __SA0ADV(CV, pXLocal) = vX2; */
                  /* __SA0ADV(CV, pXLocal) = vX1; */
                  /* __SA0ADV(CV, pXLocal) = vX3; */

                  __vpred tmp;
                  CVP     addr;
                  tmp  = c7x::strm_agen<0, CV>::get_vpred();
                  addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
                  __vstore_pred(tmp, addr, vX0);

                  tmp  = c7x::strm_agen<0, CV>::get_vpred();
                  addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
                  __vstore_pred(tmp, addr, vX2);

                  tmp  = c7x::strm_agen<0, CV>::get_vpred();
                  addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
                  __vstore_pred(tmp, addr, vX1);

                  tmp  = c7x::strm_agen<0, CV>::get_vpred();
                  addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
                  __vstore_pred(tmp, addr, vX3);

                  /* Second iteration of loop unroll */

                  vX_0    = c7x::strm_eng<0, CV>::get_adv();
                  vX_N_4  = c7x::strm_eng<0, CV>::get_adv();
                  vX_N_2  = c7x::strm_eng<0, CV>::get_adv();
                  vX_3N_4 = c7x::strm_eng<0, CV>::get_adv();

                  vSum1  = vX_0 + vX_N_2;
                  vSum2  = vX_N_4 + vX_3N_4;
                  vDiff1 = vX_0 - vX_N_2;
                  vDiff2 = vX_N_4 - vX_3N_4;

                  vTwX1 = c7x::strm_eng<1, CV>::get_adv();
                  vTwX2 = c7x::strm_eng<1, CV>::get_adv();
                  vTwX3 = c7x::strm_eng<1, CV>::get_adv();

                  vX0Temp = vSum1 + vSum2;
                  vX1Temp = vDiff1 - __vcrot90sp_vv(vDiff2);
                  vX2Temp = vSum1 - vSum2;
                  vX3Temp = vDiff1 + __vcrot90sp_vv(vDiff2);

                  vX0 = vX0Temp;
                  vX1 = __complex_multiply(vX1Temp, vTwX1);
                  vX2 = __complex_multiply(vX2Temp, vTwX2);
                  vX3 = __complex_multiply(vX3Temp, vTwX3);

                  /* __SA0ADV(CV, pXLocal) = vX0; */
                  /* __SA0ADV(CV, pXLocal) = vX2; */
                  /* __SA0ADV(CV, pXLocal) = vX1; */
                  /* __SA0ADV(CV, pXLocal) = vX3; */

                  tmp  = c7x::strm_agen<0, CV>::get_vpred();
                  addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
                  __vstore_pred(tmp, addr, vX0);

                  tmp  = c7x::strm_agen<0, CV>::get_vpred();
                  addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
                  __vstore_pred(tmp, addr, vX2);

                  tmp  = c7x::strm_agen<0, CV>::get_vpred();
                  addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
                  __vstore_pred(tmp, addr, vX1);

                  tmp  = c7x::strm_agen<0, CV>::get_vpred();
                  addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
                  __vstore_pred(tmp, addr, vX3);
               }
               __SA0_CLOSE();
               __SE0_CLOSE();
               __SE1_CLOSE();

               numPointsPerDft >>= 2;
               pWLocal += numPointsPerDft * 3;
               seCnt1 >>= 2;
               seCnt2 >>= 2;
               seCnt3 <<= 2;
               /* printf ("\n\n"); */
               /* for (int32_t u = 0; u < 64 * 2; u++) { */
               /*    printf ("%f, ", ((float *) pX)[u]); */
               /* } */
            }
            if (numPointsPerDft == 4) {
               /* 4-point stage with bit-reversal */
               numLeadingZeros = __norm((int32_t) (bitRevPoints - 1)) + 1;

               se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP4_PARAM_OFFSET));
               __SE0_OPEN((void *) (pSrc), se0_param);

               for (uint32_t grp = 0U; grp < numBitRevGrps; grp++) {
                  uint32_t grpOffset = grp * bitRevPoints;

                  /* pY0 = &pYLocal[0x00000000u]; */
                  /* pY1 = &pYLocal[0x40000000u >> numLeadingZeros]; */
                  /* pY2 = &pYLocal[0x80000000u >> numLeadingZeros]; */
                  /* pY3 = &pYLocal[0xC0000000u >> numLeadingZeros]; */

                  pY0 = (cfloat *) (pDst + grpOffset);
                  pY1 = (cfloat *) (pDst + grpOffset + (0x40000000u >> numLeadingZeros));
                  pY2 = (cfloat *) (pDst + grpOffset + (0x80000000u >> numLeadingZeros));
                  pY3 = (cfloat *) (pDst + grpOffset + (0xC0000000u >> numLeadingZeros));

#ifdef LAST_LOOP_UNROLL
                  /* pY4 = &pYLocal[0x20000000u >> numLeadingZeros]; */
                  /* pY5 = &pYLocal[0x60000000u >> numLeadingZeros]; */
                  /* pY6 = &pYLocal[0xA0000000u >> numLeadingZeros]; */
                  /* pY7 = &pYLocal[0xE0000000u >> numLeadingZeros]; */

                  pY4 = (cfloat *) (pDst + grpOffset + (0x20000000u >> numLeadingZeros));
                  pY5 = (cfloat *) (pDst + grpOffset + (0x60000000u >> numLeadingZeros));
                  pY6 = (cfloat *) (pDst + grpOffset + (0xA0000000u >> numLeadingZeros));
                  pY7 = (cfloat *) (pDst + grpOffset + (0xE0000000u >> numLeadingZeros));
#endif

#ifdef LAST_LOOP_UNROLL
                  for (k = 0; k < (int32_t) (bitRevPoints >> 2); k += 8)
#else
                  for (k = 0; k < (int32_t) (bitRevPoints >> 2); k += 4)
#endif
                  {
                     bitRevOffset = __bit_reverse(k) >> numLeadingZeros;

                     vX_0    = c7x::strm_eng<0, CV>::get_adv();
                     vX_N_4  = c7x::strm_eng<0, CV>::get_adv();
                     vX_N_2  = c7x::strm_eng<0, CV>::get_adv();
                     vX_3N_4 = c7x::strm_eng<0, CV>::get_adv();

                     vSum1  = vX_0 + vX_N_2;
                     vSum2  = vX_N_4 + vX_3N_4;
                     vDiff1 = vX_0 - vX_N_2;
                     vDiff2 = vX_N_4 - vX_3N_4;

                     vX0 = vSum1 + vSum2;
                     vX1 = vDiff1 - __vcrot90sp_vv(vDiff2);
                     vX2 = vSum1 - vSum2;
                     vX3 = vDiff1 + __vcrot90sp_vv(vDiff2);

                     __vstore_reverse_bit((CVP) (pY0 + bitRevOffset), vX0);
                     __vstore_reverse_bit((CVP) (pY1 + bitRevOffset), vX1);
                     __vstore_reverse_bit((CVP) (pY2 + bitRevOffset), vX2);
                     __vstore_reverse_bit((CVP) (pY3 + bitRevOffset), vX3);

#ifdef LAST_LOOP_UNROLL
                     vX_0_1    = c7x::strm_eng<0, CV>::get_adv();
                     vX_N_4_1  = c7x::strm_eng<0, CV>::get_adv();
                     vX_N_2_1  = c7x::strm_eng<0, CV>::get_adv();
                     vX_3N_4_1 = c7x::strm_eng<0, CV>::get_adv();

                     vSum1_1  = vX_0_1 + vX_N_2_1;
                     vSum2_1  = vX_N_4_1 + vX_3N_4_1;
                     vDiff1_1 = vX_0_1 - vX_N_2_1;
                     vDiff2_1 = vX_N_4_1 - vX_3N_4_1;

                     vX0_1 = vSum1_1 + vSum2_1;
                     vX1_1 = vDiff1_1 - __vcrot90sp_vv(vDiff2_1);
                     vX2_1 = vSum1_1 - vSum2_1;
                     vX3_1 = vDiff1_1 + __vcrot90sp_vv(vDiff2_1);

                     __vstore_reverse_bit((CVP) (pY4 + bitRevOffset), vX0_1);
                     __vstore_reverse_bit((CVP) (pY5 + bitRevOffset), vX1_1);
                     __vstore_reverse_bit((CVP) (pY6 + bitRevOffset), vX2_1);
                     __vstore_reverse_bit((CVP) (pY7 + bitRevOffset), vX3_1);
   #endif
                  }
               }
               __SE0_CLOSE();
               /* printf ("\nStage == 4\n"); */
               /* for (int32_t u = 0; u < 64 * 2; u++) { */
               /*    printf ("%f, ", ((float *) pY)[u]); */
               /* } */
            }
            else {
#if 1
               numLeadingZeros = __norm((int32_t) (bitRevPoints - 1)) + 1;
#if __C7X_HOSTEM__
               pWLocal += 1;
               twTemp = *pWLocal;
               vTwX1  = CV(twTemp, twTemp, twTemp, twTemp);
#else
               pWLocal += 1;
               twTemp = *pWLocal;
               vTwX1  = (CV) (twTemp, twTemp, twTemp, twTemp);
#endif

#if __C7X_HOSTEM__
               pWLocal += 2;
               twTemp = *pWLocal;
               vTwX2  = CV(twTemp, twTemp, twTemp, twTemp);
#else
               pWLocal += 2;
               twTemp = *pWLocal;
               vTwX2  = (CV) (twTemp, twTemp, twTemp, twTemp);
#endif
#if __C7X_HOSTEM__
               pWLocal += 2;
               twTemp = *pWLocal;
               vTwX3  = CV(twTemp, twTemp, twTemp, twTemp);
#else
               pWLocal += 2;
               twTemp = *pWLocal;
               vTwX3  = (CV) (twTemp, twTemp, twTemp, twTemp);
#endif

               se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP5_PARAM_OFFSET));
               __SE0_OPEN((void *) (pSrc), se0_param);

               for (uint32_t grp = 0U; grp < numBitRevGrps; grp++) {
                  uint32_t grpOffset = grp * bitRevPoints;

                  /* pY0 = &pYLocal[0x00000000u]; */
                  /* pY1 = &pYLocal[0x80000000u >> numLeadingZeros]; */
                  /* pY2 = &pYLocal[0x20000000u >> numLeadingZeros]; */
                  /* pY3 = &pYLocal[0xA0000000u >> numLeadingZeros]; */
                  /* pY4 = &pYLocal[0x40000000u >> numLeadingZeros]; */
                  /* pY5 = &pYLocal[0xC0000000u >> numLeadingZeros]; */
                  /* pY6 = &pYLocal[0x60000000u >> numLeadingZeros]; */
                  /* pY7 = &pYLocal[0xE0000000u >> numLeadingZeros]; */

                  pY0 = (cfloat *) (pDst + grpOffset);
                  pY1 = (cfloat *) (pDst + grpOffset + (0x80000000u >> numLeadingZeros));
                  pY2 = (cfloat *) (pDst + grpOffset + (0x20000000u >> numLeadingZeros));
                  pY3 = (cfloat *) (pDst + grpOffset + (0xA0000000u >> numLeadingZeros));
                  pY4 = (cfloat *) (pDst + grpOffset + (0x40000000u >> numLeadingZeros));
                  pY5 = (cfloat *) (pDst + grpOffset + (0xC0000000u >> numLeadingZeros));
                  pY6 = (cfloat *) (pDst + grpOffset + (0x60000000u >> numLeadingZeros));
                  pY7 = (cfloat *) (pDst + grpOffset + (0xE0000000u >> numLeadingZeros));

                  for (k = 0; k < (int32_t) (bitRevPoints >> 2); k += 8) {
                     bitRevOffset = __bit_reverse(k) >> numLeadingZeros;

                     vX_0      = c7x::strm_eng<0, CV>::get_adv();
                     vX_0_1    = c7x::strm_eng<0, CV>::get_adv();
                     vX_N_4    = c7x::strm_eng<0, CV>::get_adv();
                     vX_N_4_1  = c7x::strm_eng<0, CV>::get_adv();
                     vX_N_2    = c7x::strm_eng<0, CV>::get_adv();
                     vX_N_2_1  = c7x::strm_eng<0, CV>::get_adv();
                     vX_3N_4   = c7x::strm_eng<0, CV>::get_adv();
                     vX_3N_4_1 = c7x::strm_eng<0, CV>::get_adv();

                     vSum1  = vX_0 + vX_N_2;
                     vSum2  = vX_N_4 + vX_3N_4;
                     vDiff1 = vX_0 - vX_N_2;
                     vDiff2 = vX_N_4 - vX_3N_4;

                     vX0 = vSum1 + vSum2;
                     vX1 = vDiff1 - __vcrot90sp_vv(vDiff2);
                     vX2 = vSum1 - vSum2;
                     vX3 = vDiff1 + __vcrot90sp_vv(vDiff2);

                     vSum1_1  = vX_0_1 + vX_N_2_1;
                     vSum2_1  = vX_N_4_1 + vX_3N_4_1;
                     vDiff1_1 = vX_0_1 - vX_N_2_1;
                     vDiff2_1 = vX_N_4_1 - vX_3N_4_1;

                     vX0Temp = vSum1_1 + vSum2_1;
                     vX1Temp = vDiff1_1 - __vcrot90sp_vv(vDiff2_1);
                     vX2Temp = vSum1_1 - vSum2_1;
                     vX3Temp = vDiff1_1 + __vcrot90sp_vv(vDiff2_1);

                     vX0_1 = vX0Temp;
                     vX1_1 = __complex_multiply(vX1Temp, vTwX1);
                     vX2_1 = __complex_multiply(vX2Temp, vTwX2);
                     vX3_1 = __complex_multiply(vX3Temp, vTwX3);

                     vX0_2PtDft_1 = vX0 + vX0_1;
                     vX0_2PtDft_2 = vX0 - vX0_1;
                     vX1_2PtDft_1 = vX1 + vX1_1;
                     vX1_2PtDft_2 = vX1 - vX1_1;
                     vX2_2PtDft_1 = vX2 + vX2_1;
                     vX2_2PtDft_2 = vX2 - vX2_1;
                     vX3_2PtDft_1 = vX3 + vX3_1;
                     vX3_2PtDft_2 = vX3 - vX3_1;

                     __vstore_reverse_bit((CVP) (pY0 + bitRevOffset), vX0_2PtDft_1);
                     __vstore_reverse_bit((CVP) (pY1 + bitRevOffset), vX0_2PtDft_2);
                     __vstore_reverse_bit((CVP) (pY2 + bitRevOffset), vX1_2PtDft_1);
                     __vstore_reverse_bit((CVP) (pY3 + bitRevOffset), vX1_2PtDft_2);
                     __vstore_reverse_bit((CVP) (pY4 + bitRevOffset), vX2_2PtDft_1);
                     __vstore_reverse_bit((CVP) (pY5 + bitRevOffset), vX2_2PtDft_2);
                     __vstore_reverse_bit((CVP) (pY6 + bitRevOffset), vX3_2PtDft_1);
                     __vstore_reverse_bit((CVP) (pY7 + bitRevOffset), vX3_2PtDft_2);
                  }
               }
               __SE0_CLOSE();
#endif
            }
         }
         else if(numPointsPerDft == 16){

            se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP3_PARAM_OFFSET));
            se1_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_TWID_PARAM_OFFSET));
            sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_LOOP3_PARAM_OFFSET));

            pSrc = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pY : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pY : (cfloat *) pX;
            pDst = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pX : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pX : (cfloat *) pY;

            seCnt1    = numPointsPerDft >> 2;
            seCnt2    = numPointsPerDft >> 4;
            seCnt3    = numPoints / numPointsPerDft;

            se1_param.DIM1  = seCnt1;
            se1_param.ICNT2 = seCnt2;
            se1_param.ICNT3 = seCnt3;
            
            __SE0_OPEN((void *) pSrc, se0_param);
            __SE1_OPEN((void *) pWLocal, se1_param);
            __SA0_OPEN(sa0_param);

            /* 16 + trip_cnt * 6 */
            for (k = 0; k < numPoints; k += 16) {
               vX_0    = c7x::strm_eng<0, CV>::get_adv();
               vX_N_4  = c7x::strm_eng<0, CV>::get_adv();
               vX_N_2  = c7x::strm_eng<0, CV>::get_adv();
               vX_3N_4 = c7x::strm_eng<0, CV>::get_adv();

               vSum1  = vX_0 + vX_N_2;
               vSum2  = vX_N_4 + vX_3N_4;
               vDiff1 = vX_0 - vX_N_2;
               vDiff2 = vX_N_4 - vX_3N_4;

               vTwX1 = c7x::strm_eng<1, CV>::get_adv();
               vTwX2 = c7x::strm_eng<1, CV>::get_adv();
               vTwX3 = c7x::strm_eng<1, CV>::get_adv();

               vX0Temp = vSum1 + vSum2;
               vX1Temp = vDiff1 - __vcrot90sp_vv(vDiff2);
               vX2Temp = vSum1 - vSum2;
               vX3Temp = vDiff1 + __vcrot90sp_vv(vDiff2);

               vX0 = vX0Temp;
               vX1 = __complex_multiply(vX1Temp, vTwX1);
               vX2 = __complex_multiply(vX2Temp, vTwX2);
               vX3 = __complex_multiply(vX3Temp, vTwX3);

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vX0);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vX2);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vX1);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pSrc);
               __vstore_pred(tmp, addr, vX3);
            }

            __SA0_CLOSE();
            __SE0_CLOSE();
            __SE1_CLOSE();

            numLeadingZeros = __norm((int32_t) (bitRevPoints - 1)) + 1;
            se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP4_PARAM_OFFSET));

            __SE0_OPEN((void *) (pSrc), se0_param);

            for (uint32_t grp = 0U; grp < numBitRevGrps; grp++) 
            {
               uint32_t grpOffset = grp * bitRevPoints;

               pY0 = (cfloat *) (pDst + grpOffset);
               pY1 = (cfloat *) (pDst + grpOffset + (0x40000000u >> numLeadingZeros));
               pY2 = (cfloat *) (pDst + grpOffset + (0x80000000u >> numLeadingZeros));
               pY3 = (cfloat *) (pDst + grpOffset + (0xC0000000u >> numLeadingZeros));

               /* 10 + trip_cnt * 5 */
               for (k = 0; k < (int32_t) (bitRevPoints >> 2); k += 4)
               {
                  bitRevOffset = __bit_reverse(k) >> numLeadingZeros;

                  vX_0    = c7x::strm_eng<0, CV>::get_adv();
                  vX_N_4  = c7x::strm_eng<0, CV>::get_adv();
                  vX_N_2  = c7x::strm_eng<0, CV>::get_adv();
                  vX_3N_4 = c7x::strm_eng<0, CV>::get_adv();

                  vSum1  = vX_0 + vX_N_2;
                  vSum2  = vX_N_4 + vX_3N_4;
                  vDiff1 = vX_0 - vX_N_2;
                  vDiff2 = vX_N_4 - vX_3N_4;

                  vX0 = vSum1 + vSum2;
                  vX1 = vDiff1 - __vcrot90sp_vv(vDiff2);
                  vX2 = vSum1 - vSum2;
                  vX3 = vDiff1 + __vcrot90sp_vv(vDiff2);

                  __vstore_reverse_bit((CVP) (pY0 + bitRevOffset), vX0);
                  __vstore_reverse_bit((CVP) (pY1 + bitRevOffset), vX1);
                  __vstore_reverse_bit((CVP) (pY2 + bitRevOffset), vX2);
                  __vstore_reverse_bit((CVP) (pY3 + bitRevOffset), vX3);
               }
            }
            __SE0_CLOSE();
         }
         else if(numPointsPerDft == 8){

            se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP3_PARAM_OFFSET));
            sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_LOOP3_PARAM_OFFSET));

            pSrc = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pY : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pY : (cfloat *) pX;
            pDst = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pX : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pX : (cfloat *) pY;

            CV vec0, vec1, sum0, diff0, dj, lo, hi, p, m, vEven, vOdd;

            c7x::uchar_vec ctrlId = c7x::uchar_vec(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31);

            CV twid = CV(1,0, 0.7071,-0.7071, 0,-1, -0.7071,-0.7071);

            __SE0_OPEN((void *) pSrc, se0_param);
            __SA0_OPEN(sa0_param);

            /* 33 + trip_cnt * 9 */
            for(k=0; k < numPoints; k+=16)
            {
               /* unroll 1 */
               vec0    = c7x::strm_eng<0, CV>::get_adv();
               vec1    = c7x::strm_eng<0, CV>::get_adv();

               sum0  = vec0 + vec1;
               diff0 = vec0 - vec1;
               dj    = __crot270(diff0);

               lo = c7x::reinterpret<CV>(__permute_low_low(ctrlId, c7x::reinterpret<c7x::uchar_vec>(diff0),c7x::reinterpret<c7x::uchar_vec>(sum0)));
               hi = c7x::reinterpret<CV>(__permute_high_high(ctrlId, c7x::reinterpret<c7x::uchar_vec>(dj),c7x::reinterpret<c7x::uchar_vec>(sum0)));

               p = lo + hi;
               m = lo - hi;

               vEven = c7x::reinterpret<CV>(__permute_even_even_long(ctrlId, c7x::reinterpret<c7x::uchar_vec>(m),c7x::reinterpret<c7x::uchar_vec>(p)));
               vOdd  = c7x::reinterpret<CV>(__permute_odd_odd_long(ctrlId, c7x::reinterpret<c7x::uchar_vec>(m),c7x::reinterpret<c7x::uchar_vec>(p)));

               vOdd = vOdd * twid;

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp,addr, vEven + vOdd);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp,addr, vEven - vOdd);

               /* unroll 2 */
               vec0    = c7x::strm_eng<0, CV>::get_adv();
               vec1    = c7x::strm_eng<0, CV>::get_adv();

               sum0  = vec0 + vec1;
               diff0 = vec0 - vec1;
               dj    = __crot270(diff0);

               lo = c7x::reinterpret<CV>(__permute_low_low(ctrlId, c7x::reinterpret<c7x::uchar_vec>(diff0),c7x::reinterpret<c7x::uchar_vec>(sum0)));
               hi = c7x::reinterpret<CV>(__permute_high_high(ctrlId, c7x::reinterpret<c7x::uchar_vec>(dj),c7x::reinterpret<c7x::uchar_vec>(sum0)));

               p = lo + hi;
               m = lo - hi;

               vEven = c7x::reinterpret<CV>(__permute_even_even_long(ctrlId, c7x::reinterpret<c7x::uchar_vec>(m),c7x::reinterpret<c7x::uchar_vec>(p)));
               vOdd  = c7x::reinterpret<CV>(__permute_odd_odd_long(ctrlId, c7x::reinterpret<c7x::uchar_vec>(m),c7x::reinterpret<c7x::uchar_vec>(p)));

               vOdd = vOdd * twid;

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp,addr, vEven + vOdd);

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp,addr, vEven - vOdd);
            }
            __SE0_CLOSE();
            __SA0_CLOSE();
         }
         else if(numPointsPerDft == 4){

            se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP3_PARAM_OFFSET));
            sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_LOOP3_PARAM_OFFSET));

            pSrc = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pY : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pY : (cfloat *) pX;
            pDst = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pX : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pX : (cfloat *) pY;

            CV vec0, rVec0, sVec0, sum0, rsum0, sSum0, out;

            c7x::uchar_vec cntrl = c7x::uchar_vec(16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);

            c7x::float_vec signVal = c7x::float_vec(1,1,1,1,-1,-1,-1,-1);
            c7x::float_vec signVal2 = c7x::float_vec(1,1,-1,-1,1,1,-1,-1);
            CV cw = CV(1,0, 1,0, 1,0, 0,-1);

            __SE0_OPEN((void *) pSrc, se0_param);
            __SA0_OPEN(sa0_param);

            /* 24 + trip_cnt * 9 */
            for(k=0; k < numPoints; k+=16)
            {
               /* unroll 1 */
               vec0    = c7x::strm_eng<0, CV>::get_adv();

               rVec0 = c7x::reinterpret<CV>(__permute_cntrl(cntrl,c7x::reinterpret<c7x::uchar_vec>(vec0)));

               sVec0 = c7x::reinterpret<CV>((c7x::reinterpret<c7x::float_vec>(vec0)) * signVal);

               sum0 = rVec0 + sVec0;

               sSum0 = sum0 * cw;
               rsum0 = __swap(sSum0);

               out = c7x::reinterpret<CV>((c7x::reinterpret<c7x::float_vec>(sSum0)) * signVal2) + rsum0;

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred_reverse_bit(tmp,addr, out);

               /* unroll 2 */
               vec0    = c7x::strm_eng<0, CV>::get_adv();

               rVec0 = c7x::reinterpret<CV>(__permute_cntrl(cntrl,c7x::reinterpret<c7x::uchar_vec>(vec0)));
               sVec0 = c7x::reinterpret<CV>((c7x::reinterpret<c7x::float_vec>(vec0)) * signVal);

               sum0 = rVec0 + sVec0;

               sSum0 = sum0 * cw;
               rsum0 = __swap(sSum0);

               out = c7x::reinterpret<CV>((c7x::reinterpret<c7x::float_vec>(sSum0)) * signVal2) + rsum0;

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred_reverse_bit(tmp,addr, out);

               /* unroll 3 */
               vec0    = c7x::strm_eng<0, CV>::get_adv();

               rVec0 = c7x::reinterpret<CV>(__permute_cntrl(cntrl,c7x::reinterpret<c7x::uchar_vec>(vec0)));
               sVec0 = c7x::reinterpret<CV>((c7x::reinterpret<c7x::float_vec>(vec0)) * signVal);

               sum0 = rVec0 + sVec0;

               sSum0 = sum0 * cw;
               rsum0 = __swap(sSum0);

               out = c7x::reinterpret<CV>((c7x::reinterpret<c7x::float_vec>(sSum0)) * signVal2) + rsum0;

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred_reverse_bit(tmp,addr, out);

               /* unroll 4 */
               vec0    = c7x::strm_eng<0, CV>::get_adv();

               rVec0 = c7x::reinterpret<CV>(__permute_cntrl(cntrl,c7x::reinterpret<c7x::uchar_vec>(vec0)));
               sVec0 = c7x::reinterpret<CV>((c7x::reinterpret<c7x::float_vec>(vec0)) * signVal);

               sum0 = rVec0 + sVec0;

               sSum0 = sum0 * cw;
               rsum0 = __swap(sSum0);

               out = c7x::reinterpret<CV>((c7x::reinterpret<c7x::float_vec>(sSum0)) * signVal2) + rsum0;

               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred_reverse_bit(tmp,addr, out);
            }
            __SE0_CLOSE();
            __SA0_CLOSE();
         }
         else if(numPointsPerDft == 2){
            se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE_LOOP3_PARAM_OFFSET));
            sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA_LOOP3_PARAM_OFFSET));

            pSrc = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pY : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pY : (cfloat *) pX;
            pDst = (numRadix5Stages > 0 && numRadix3Stages == 0) ? (cfloat *) pX : (numRadix3Stages > 0 && numRadix5Stages == 0) ? (cfloat *) pX : (cfloat *) pY;

            c7x::float_vec signVal = c7x::float_vec(1,1,-1,-1,1,1,-1,-1);

            CV vec0, rVec0, sVec0, out;

            __SE0_OPEN((void *) pSrc, se0_param);
            __SA0_OPEN(sa0_param);
         
            /* 7 + trip_cnt * 1 */
            for(k=0; k < numPoints; k+=4)
            {
               vec0    = c7x::strm_eng<0, CV>::get_adv();

               rVec0 = __swap(vec0);
               sVec0 = c7x::reinterpret<CV>(c7x::reinterpret<c7x::float_vec>(vec0) * signVal);
            
               out = rVec0 + sVec0;

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDst);
               __vstore_pred(tmp,addr, out);
            }
            __SE0_CLOSE();
            __SA0_CLOSE();
         }
      }

      /* Digit Reversal for Radix-3 */
      if (numRadix3Stages > 0 && pureRadix3 == 0) {

         pSrc = (numRadix5Stages > 0) ? (cfloat *) pY : (cfloat *) pX;
         pDst = (numRadix5Stages > 0) ? (cfloat *) pX : (cfloat *) pY; 

         se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_RADIX3_REORDER_PARAM_OFFSET));
         sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_RADIX3_REORDER_PARAM_OFFSET));

         uint32_t loopCnt = (numPoints / 3) / r3IterCnt;

         CV      vecIn;

         __SE0_OPEN(pSrc, se0_param);
         for (uint32_t iter = 0; iter < r3IterCnt; iter++) {
            uint32_t offset = 0U, rem = iter, dim = r3Dim0;
            for (idx = 0U; idx < r3DimCnt; idx++) {
               offset += (rem % 3U) * dim;
               rem /= 3U;
               dim /= 3U;
            }
            offset += (r3TailIcnt != 0U) ? ((rem % r3TailIcnt) * r3TailDim) : 0U;
            cfloat *pDstLocal = pDst + offset;
            __SA0_OPEN(sa0_param);

            /* 1 + trip_cnt * 1 */
            for (uint32_t i = 0; i < loopCnt; i++) {
               vecIn = c7x::strm_eng<0, CV>::get_adv();

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
               __vstore_pred(tmp, addr, vecIn);
            }
            __SA0_CLOSE();
         }
         __SE0_CLOSE();
      }

      /* Digit Reversal for Radix-5 */
      if (numRadix5Stages > 0 && pureRadix5 == 0) {
         pSrc = (cfloat *) pX;
         pDst = (cfloat *) pY;

         se0_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_RADIX5_REORDER_PARAM_OFFSET));
         se1_param = *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_RADIX5_REORDER_PARAM_OFFSET));
         sa0_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_RADIX5_REORDER_PARAM_OFFSET));
         sa1_param = *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA1_RADIX5_REORDER_PARAM_OFFSET));

         uint32_t loopCnt = (numPoints / 5) / r5IterCnt;

         CV      vecIn;
         cfloat  In;
         cfloat *pDst1 = pDst + 4;

         __SE0_OPEN(pSrc, se0_param);
         __SE1_OPEN(pSrc + (numPoints / 5) * 4, se1_param);
         for (uint32_t iter = 0; iter < r5IterCnt; iter++) {
            uint32_t offset = 0U, rem = iter, dim = r5Dim0;
            for (idx = 0U; idx < r5DimCnt; idx++) {
               offset += (rem % 5U) * dim;
               rem /= 5U;
               dim /= 5U;
            }
            cfloat  *pDstLocal    = pDst + offset;
            cfloat  *pDstLocal1   = pDst1 + offset;
            __SA0_OPEN(sa0_param);
            __SA1_OPEN(sa1_param);

            /* 2 + trip_cnt * 2 */
            for (uint32_t i = 0; i < loopCnt; i++) {
               vecIn = c7x::strm_eng<0, CV>::get_adv();
               In    = c7x::strm_eng<1, cfloat>::get_adv();

               __vpred tmp;
               CVP     addr;
               tmp  = c7x::strm_agen<0, CV>::get_vpred();
               addr = c7x::strm_agen<0, CV>::get_adv(pDstLocal);
               __vstore_pred(tmp, addr, vecIn);

               __vpred ftmp;
               cfloat *faddr;
               ftmp  = c7x::strm_agen<1, cfloat>::get_vpred();
               faddr = c7x::strm_agen<1, cfloat>::get_adv(pDstLocal1);
               __vstore_pred(ftmp, faddr, In);
            }
            __SA0_CLOSE();
            __SA1_CLOSE();
         }
         __SE0_CLOSE();
         __SE1_CLOSE();
      }
   }

   return (status);
}

#if (!defined(FFTLIB_REMOVE_CHECK_PARAMS) && !defined(FFTLIB_FFT1D_I32FC_C32FC_O32FC_REMOVE_CHECK_PARAMS)) ||          \
    (defined(FFTLIB_CHECK_PARAMS)) || (defined(FFTLIB_FFT1D_I32FC_C32FC_O32FC_CHECK_PARAMS))

FFTLIB_STATUS
FFTLIB_fft1d_i32fc_c32fc_o32fc_checkParams(FFTLIB_F32           *pX,
                                           FFTLIB_bufParams1D_t *bufParamsX,
                                           FFTLIB_F32           *pW,
                                           FFTLIB_bufParams1D_t *bufParamsW,
                                           FFTLIB_F32           *pY,
                                           FFTLIB_bufParams1D_t *bufParamsY,
                                           void                 *pBlock)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   if ((pX == NULL) || (pW == NULL) || (pY == NULL)) {
      status = FFTLIB_ERR_NULL_POINTER;
   }
   else if (bufParamsX->dim_x != bufParamsW->dim_x || bufParamsX->dim_x != bufParamsY->dim_x) {
      status = FFTLIB_ERR_INVALID_DIMENSION;
   }
   else if ((bufParamsX->data_type != FFTLIB_FLOAT32) || (bufParamsW->data_type != FFTLIB_FLOAT32) ||
            (bufParamsY->data_type != FFTLIB_FLOAT32)) {
      status = FFTLIB_ERR_INVALID_TYPE;
   }
   else if (((uint64_t) pX) & 0xFu) {                /* pX must be 16-byte aligned for a */
      status = FFTLIB_ERR_NOT_ALIGNED_PTRS_STRIDES; /* streaming engine
                                                      configuration         */
   }
   else {
      /* Check if number of pts is a power of 2 || power of 3 || power of 5 */
      uint32_t temp = bufParamsX->dim_x / 2U; // Get actual numPoints
      uint32_t i;

      for (i = 0; i < 32U && (temp % 5U == 0U); ++i) {
         temp /= 5U;
      }
      for (i = 0; i < 32U && (temp % 3U == 0U); ++i) {
         temp /= 3U;
      }
      for (i = 0; i < 32U && (temp % 2U == 0U); ++i) {
         temp /= 2U;
      }

      if (temp != 1) {
         status = FFTLIB_ERR_INVALID_DIMENSION; // Has prime factors other than 2, 3 and 5
      }
   }
   return (status);
}

#endif
