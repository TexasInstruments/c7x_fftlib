// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "../../../common/c71/FFTLIB_debug.h"
#include "../../FFTLIB_fft1dBatched_i32fc_c32fc_o32fc/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc.h"
#include "../FFTLIB_fft1dBatched_i32f_c32fc_o32fc.h"
#include "FFTLIB_types.h"
/* #include "ti_he_impl/targ_defs.h" */

#define SE_PARAM_BASE (0x0000)
#define SE0_PARAM_OFFSET (SE_PARAM_BASE)
#define SE1_PARAM_OFFSET (SE0_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA0_PARAM_OFFSET (SE1_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA1_PARAM_OFFSET (SA0_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA2_PARAM_OFFSET (SA1_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA3_PARAM_OFFSET (SA2_PARAM_OFFSET + SE_PARAM_SIZE)

typedef typename c7x::cfloat_vec CV;
typedef typename c7x::float_vec  V;

// #define TWIDDLE_USING_SE 1

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_init(FFTLIB_F32           *pX,
                                          FFTLIB_bufParams1D_t *bufParamsX,
                                          FFTLIB_F32           *pW,
                                          FFTLIB_bufParams1D_t *bufParamsW,
                                          FFTLIB_F32           *pXFFT,
                                          FFTLIB_bufParams1D_t *bufParamsXFFT,
                                          FFTLIB_F32           *pSf,
                                          FFTLIB_bufParams1D_t *bufParamsSf,
                                          FFTLIB_F32           *pY,
                                          FFTLIB_bufParams1D_t *bufParamsY,
                                          uint32_t              numPoints,
                                          uint32_t              numChannels,
                                          uint8_t               outmode,
                                          void                 *pBlock)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   __SE_TEMPLATE_v1 se0_param = __gen_SE_TEMPLATE_v1();
   __SE_TEMPLATE_v1 se1_param = __gen_SE_TEMPLATE_v1();
   __SA_TEMPLATE_v1 sa0_param = __gen_SA_TEMPLATE_v1();
   __SA_TEMPLATE_v1 sa1_param = __gen_SA_TEMPLATE_v1();
   __SA_TEMPLATE_v1 sa2_param = __gen_SA_TEMPLATE_v1();
   __SA_TEMPLATE_v1 sa3_param = __gen_SA_TEMPLATE_v1();

   FFTLIB_bufParams1D_t bufParamsX_FFT;

   bufParamsX_FFT.dim_x         = numChannels * numPoints;
   bufParamsX_FFT.data_type     = FFTLIB_FLOAT32;
   FFTLIB_bufParams1D_t *bufPtr = &bufParamsX_FFT;

   FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_init((FFTLIB_F32 *) pX, bufPtr, (FFTLIB_F32 *) pW, bufPtr,
                                              (FFTLIB_F32 *) pXFFT, bufPtr, (numPoints >> 1), numChannels,
                                              &((uint8_t *) pBlock)[7 * SE_PARAM_SIZE]);

   uint32_t numPointsOut = (outmode == 1) ? numPoints : (numPoints >> 1) + 1;
   uint32_t elementCount = c7x::element_count_of<CV>::value;
   uint32_t SEBlocks     = ((numPoints >> 1) + elementCount - 1) / elementCount;

#ifdef TWIDDLE_USING_SE
   uint32_t offset       = (((uint64_t) pSf - (uint64_t) pXFFT)) / sizeof(cfloat);

   /* element type is 64 bits, element count reflects type */
   se0_param.ICNT0 = elementCount;
   se0_param.DIM1  = offset;
   se0_param.ICNT1 = 2;
   se0_param.DIM2  = elementCount;
   se0_param.ICNT2 = SEBlocks;

   se0_param.ELETYPE                                               = __SE_ELETYPE_32BIT_CMPLX_SWAP;
   se0_param.VECLEN                                                = c7x::se_veclen<CV>::value;
   se0_param.DIMFMT                                                = __SE_DIMFMT_3D;
   se0_param.DECDIM1                                               = __SE_DECDIM_DIM2;
   se0_param.DECDIM1_WIDTH                                         = (numPoints >> 1) - 1;
   *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_PARAM_OFFSET)) = se0_param;

   se1_param.ICNT0 = elementCount;
   se1_param.DIM1  = offset + (numPoints >> 1) - 1;
   se1_param.ICNT1 = 2;
   se1_param.DIM2  = -(int32_t) elementCount;
   se1_param.ICNT2 = SEBlocks;

   se1_param.DIR                                                   = __SE_DIR_DEC;
   se1_param.ELETYPE                                               = __SE_ELETYPE_32BIT_CMPLX_SWAP;
   se1_param.VECLEN                                                = c7x::se_veclen<CV>::value;
   se1_param.DIMFMT                                                = __SE_DIMFMT_3D;
   *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_PARAM_OFFSET)) = se1_param;
#else

   /* element type is 64 bits, element count reflects type */
   se0_param.ICNT0 = elementCount;
   se0_param.DIM1  = elementCount;
   se0_param.ICNT1 = SEBlocks;
   se0_param.DIM2  = (numPoints >> 1);
   se0_param.ICNT2 = numChannels;

   se0_param.ELETYPE                                               = __SE_ELETYPE_32BIT_CMPLX_SWAP;
   se0_param.VECLEN                                                = c7x::se_veclen<CV>::value;
   se0_param.DIMFMT                                                = __SE_DIMFMT_3D;
   se0_param.DECDIM1                                               = __SE_DECDIM_DIM1;
   se0_param.DECDIM1_WIDTH                                         = (numPoints >> 1) - 1;
   *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_PARAM_OFFSET)) = se0_param;

   se1_param.ICNT0 = (numPoints >> 1);
   se1_param.DIM1  = (numPoints >> 1);
   se1_param.ICNT1 = numChannels;

   se1_param.DIR                                                   = __SE_DIR_DEC;
   se1_param.ELETYPE                                               = __SE_ELETYPE_32BIT_CMPLX_SWAP;
   se1_param.VECLEN                                                = c7x::se_veclen<CV>::value;
   se1_param.DIMFMT                                                = __SE_DIMFMT_2D;
   *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_PARAM_OFFSET)) = se1_param;

   /* Split Factor fetch forward */
   sa2_param.ICNT0 = elementCount;
   sa2_param.DIM1  = elementCount;
   sa2_param.ICNT1 = SEBlocks;
   sa2_param.DIM2  = 0;
   sa2_param.ICNT2 = numChannels;

   sa2_param.VECLEN                                                = c7x::sa_veclen<CV>::value;
   sa2_param.DIMFMT                                                = __SA_DIMFMT_3D;
   *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA2_PARAM_OFFSET)) = sa2_param;

   /* Split Factor fetch inverse */
   sa3_param.ICNT0 = elementCount;
   sa3_param.DIM1  = -(int32_t) elementCount;
   sa3_param.ICNT1 = SEBlocks;
   sa3_param.DIM2  = 0;
   sa3_param.ICNT2 = numChannels;

   sa3_param.VECLEN                                                = c7x::sa_veclen<CV>::value;
   sa3_param.DIMFMT                                                = __SA_DIMFMT_3D;
   *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA3_PARAM_OFFSET)) = sa3_param;
#endif

   sa0_param.ICNT0                                                 = elementCount;
   sa0_param.DIM1                                                  = elementCount;
   sa0_param.ICNT1                                                 = SEBlocks;
   sa0_param.DECDIM1                                               = __SA_DECDIM_DIM1;
   sa0_param.DECDIM1_WIDTH                                         = outmode == 1 ? (numPoints >> 1) :numPointsOut - 1;
   sa0_param.DIM2                                                  = (numPointsOut);
   sa0_param.ICNT2                                                 = numChannels;
   sa0_param.VECLEN                                                = c7x::sa_veclen<CV>::value;
   sa0_param.DIMFMT                                                = __SA_DIMFMT_3D;
   *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_PARAM_OFFSET)) = sa0_param;

   /* only need to store complex conjugate if full spectrum */
   if (outmode == 1) {
      sa1_param.ICNT0                                                 = elementCount;
      sa1_param.DIM1                                                  = -(int32_t) elementCount;
      sa1_param.ICNT1                                                 = SEBlocks;
      sa1_param.DIM2                                                  = (numPoints);
      sa1_param.ICNT2                                                 = numChannels;
      sa1_param.VECLEN                                                = c7x::sa_veclen<CV>::value;
      sa1_param.DIMFMT                                                = __SA_DIMFMT_3D;
      *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA1_PARAM_OFFSET)) = sa1_param;
   }

   else {
      /* Nothing for half spectrum */
   }

   return (status);
}

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_kernel(FFTLIB_F32 *restrict pX,
                                            FFTLIB_bufParams1D_t *bufParamsX,
                                            FFTLIB_F32 *restrict pW,
                                            FFTLIB_bufParams1D_t *bufParamsW,
                                            FFTLIB_F32 *restrict pXFFT,
                                            FFTLIB_bufParams1D_t *bufParamsXFFT,
                                            FFTLIB_F32 *restrict pSf,
                                            FFTLIB_bufParams1D_t *bufParamsSf,
                                            FFTLIB_F32 *restrict pY,
                                            FFTLIB_bufParams1D_t *bufParamsY,
                                            uint32_t              numPoints,
                                            uint32_t              numChannels,
                                            uint8_t               outmode,
                                            void                 *pBlock)
{

   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   FFTLIB_bufParams1D_t  bufParamsX_FFT;
   FFTLIB_bufParams1D_t *bufPtr = &bufParamsX_FFT;

   bufParamsX_FFT.dim_x     = numPoints * numChannels;
   bufParamsX_FFT.data_type = FFTLIB_FLOAT32;

   FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_kernel((FFTLIB_F32 *) pX, bufPtr, (FFTLIB_F32 *) pW, bufPtr,
                                                (FFTLIB_F32 *) pXFFT, bufPtr, (numPoints >> 1), numChannels,
                                                &((uint8_t *) pBlock)[7 * SE_PARAM_SIZE]);

   FFTLIB_asm(" MARK 6");

   __SE_TEMPLATE_v1 se0Params; // SE parameter vector
   __SE_TEMPLATE_v1 se1Params; // SE parameter vector

   /* __SE_TEMPLATE_v1 se1ParamsLast = __gen_SE_TEMPLATE_v1 (); */
   __SA_TEMPLATE_v1 sa0Params;

#ifndef TWIDDLE_USING_SE
   __SA_TEMPLATE_v1 sa2Params;
   __SA_TEMPLATE_v1 sa3Params;
#endif

   se0Params = *(__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_PARAM_OFFSET);
   se1Params = *(__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_PARAM_OFFSET);
   sa0Params = *(__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_PARAM_OFFSET);

#ifndef TWIDDLE_USING_SE
   sa2Params = *(__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA2_PARAM_OFFSET);
   sa3Params = *(__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA3_PARAM_OFFSET);
#endif

   uint32_t elementCount = c7x::element_count_of<CV>::value;
   uint32_t SEBlocks     = ((numPoints >> 1) + elementCount - 1) / elementCount;
   uint32_t numPointsOut = (outmode == 1) ? numPoints : (numPoints >> 1) + 1;

   uint32_t halfPoints = numPoints >> 1;
   uint32_t numOverWr  = (SEBlocks * elementCount) - halfPoints;

   numOverWr = (numOverWr > (halfPoints - 1)) ? (halfPoints - 1) : numOverWr;

   __vpred predOverWrLd = __mask_long(elementCount);
   __vpred predOverWrSt = __mask_long(numOverWr);

   __vpred tmp;
   CV     *addr;

   FFTLIB_F32 *restrict pYLocal  = pY;

#ifndef TWIDDLE_USING_SE 

   FFTLIB_F32 *restrict pSfLocal = pSf;
   CV *addrSf;
   __vpred tmpSf;

   __SE0_OPEN(pXFFT + 2, se0Params);
   __SE1_OPEN(pXFFT + numPoints, se1Params);
   __SA2_OPEN(sa2Params);
   __SA3_OPEN(sa3Params);
#endif
   __SA0_OPEN(sa0Params);

   CV var0, var1;
   CV temp0, temp1;
   CV sFA, sFB;
   CV regStore0, regStore1;

#if defined(_HOST_BUILD)
   c7x::ulong_vec xorVec = (c7x::ulong_vec)(0x0000000080000000);

#else
   c7x::ulong_vec xorVec = (0x0000000080000000U);
#endif

   uint32_t i  = 0;
   uint32_t ch = 0;

   /* Full Spectrum Outmode */
   if (outmode == 1) {

      /* full spectrum complex conjugate store */
      __SA_TEMPLATE_v1 sa1Params;
      sa1Params = *(__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA1_PARAM_OFFSET);
      __SA1_OPEN(sa1Params);

      FFTLIB_F32 *restrict pYLocalReverse = pYLocal + (2 * numPoints - (elementCount << 1));

      /* FFTLIB_asm(" MARK 8"); */
#pragma MUST_ITERATE(8, , 8)
#pragma UNROLL(8)
      for (ch = 0; ch < numChannels; ch++) {
#ifdef TWIDDLE_USING_SE       
         __SE0_OPEN(pXFFT + ch * numPoints + 2, se0Params);
         __SE1_OPEN(pXFFT + ch * numPoints + numPoints, se1Params);
#endif
         for (i = 0; i < SEBlocks; i++) {
            var0 = c7x::strm_eng<0, CV>::get_adv();
            var1 = c7x::strm_eng<1, CV>::get_adv();

#ifdef TWIDDLE_USING_SE
            sFA = c7x::strm_eng<0, CV>::get_adv();
            sFB = c7x::strm_eng<1, CV>::get_adv();
#else
            tmpSf  = c7x::strm_agen<2, CV>::get_vpred();
            addrSf = c7x::strm_agen<2, CV>::get_adv(pSfLocal + 2);
            sFA    = __vload_pred(tmpSf, addrSf);

            tmpSf  = c7x::strm_agen<3, CV>::get_vpred();
            addrSf = c7x::strm_agen<3, CV>::get_adv(pSf + (numPoints * 2) - (elementCount * 2) - 2);
            sFB    = __reverse(__vload_pred(tmpSf, addrSf));
#endif
            temp0 = (__complex_multiply(var0, c7x::as_cfloat_vec(sFA)));
            temp1 = (__complex_conjugate_multiply(var1, c7x::as_cfloat_vec(sFB)));

            regStore0 = temp0 + temp1;
            regStore1 = c7x::as_cfloat_vec((c7x::as_ulong_vec(regStore0)) ^ (xorVec));

            tmp  = c7x::strm_agen<1, CV>::get_vpred();
            addr = c7x::strm_agen<1, CV>::get_adv(pYLocalReverse);

            __vstore_pred(tmp, addr, (__reverse(regStore1)));

            tmp       = c7x::strm_agen<0, CV>::get_vpred();
            addr      = c7x::strm_agen<0, CV>::get_adv(pYLocal + 2);

            __vstore_pred(tmp, addr, regStore0);
         }

         /*********************************/
         /* Write pY[0] and pY[numPoints] */
         /*********************************/

         cfloat var2, temp2, temp3;
         /* current channel row */
         uint32_t c = numPoints * ch;

         if (numOverWr > 0) {
            uint32_t overWrLoadBin = halfPoints + numOverWr + 1 - elementCount;

            CV overWrVal     = __vload_pred(predOverWrLd, ((CV *) (pY + (c << 1) + (overWrLoadBin << 1))));
            CV overWrValConj = c7x::as_cfloat_vec((c7x::as_ulong_vec(overWrVal)) ^ (xorVec));
            __vstore_pred(predOverWrSt, ((CV *) (pY + ((c << 1) + numPoints - (numOverWr << 1)))), (__reverse(overWrValConj)));
         }

         // pY[0]
         var2 = ((cfloat *) pXFFT)[(c >> 1) + 0];

         temp2 = __complex_multiply(var2, (((cfloat *) pSf)[0]));
         temp3 = __complex_conjugate_multiply(var2, (((cfloat *) pSf)[numPoints - 1]));

         ((cfloat *) pY)[c + 0] = temp2 + temp3;

         // pY[numPoints]
         pY[(c << 1) + numPoints]     = pXFFT[c + 0] - pXFFT[c + 1];
         pY[(c << 1) + numPoints + 1] = 0;
         
#ifdef TWIDDLE_USING_SE 
         se0Params.DIM1 = se0Params.DIM1 - (numPoints>>1);
         se1Params.DIM1 = se1Params.DIM1 - (numPoints>>1);

         __SE0_CLOSE();
         __SE1_CLOSE();
#endif
      }
      /* FFTLIB_asm(" MARK 9"); */

      __SA1_CLOSE();
   }

   /* Half Spectrum Outmode */
   else {

      /* FFTLIB_asm(" MARK 8"); */
#pragma MUST_ITERATE(8, , 8)
#pragma UNROLL(8)
      for (ch = 0; ch < numChannels; ch++) {
#ifdef TWIDDLE_USING_SE       
         __SE0_OPEN(pXFFT + ch * numPoints + 2, se0Params);
         __SE1_OPEN(pXFFT + ch * numPoints + numPoints, se1Params);
#endif
         for (i = 0; i < SEBlocks; i++) {
            var0 = c7x::strm_eng<0, CV>::get_adv();
            var1 = c7x::strm_eng<1, CV>::get_adv();

#ifdef TWIDDLE_USING_SE
            sFA = c7x::strm_eng<0, CV>::get_adv();
            sFB = c7x::strm_eng<1, CV>::get_adv();
#else
            tmpSf  = c7x::strm_agen<2, CV>::get_vpred();
            addrSf = c7x::strm_agen<2, CV>::get_adv(pSfLocal + 2);
            sFA    = __vload_pred(tmpSf, addrSf);

            tmpSf  = c7x::strm_agen<3, CV>::get_vpred();
            addrSf = c7x::strm_agen<3, CV>::get_adv(pSf + (numPoints * 2) - (elementCount * 2) - 2);
            sFB    = __reverse(__vload_pred(tmpSf, addrSf));
#endif

            temp0 = (__complex_multiply(var0, c7x::as_cfloat_vec(sFA)));
            temp1 = (__complex_conjugate_multiply(var1, c7x::as_cfloat_vec(sFB)));

            regStore0 = temp0 + temp1;
            tmp       = c7x::strm_agen<0, CV>::get_vpred();
            addr      = c7x::strm_agen<0, CV>::get_adv(pYLocal + 2);

            __vstore_pred(tmp, addr, regStore0);
         }

         /***************/
         /* Write pY[0] */
         /***************/

         cfloat var2, temp2, temp3;
         /* current channel row */
         uint32_t c    = numPoints * ch;
         uint32_t cout = numPointsOut * ch;

         // pY[0]
         var2 = ((cfloat *) pXFFT)[(c >> 1) + 0];

         temp2 = __complex_multiply(var2, (((cfloat *) pSf)[0]));
         temp3 = __complex_conjugate_multiply(var2, (((cfloat *) pSf)[numPoints - 1]));

         ((cfloat *) pY)[cout + 0] = temp2 + temp3;

         /***************/
         /* Write pY[N] */
         /***************/

         pY[(cout << 1) + numPoints]     = pXFFT[c + 0] - pXFFT[c + 1];
         pY[(cout << 1) + numPoints + 1] = 0;

#ifdef TWIDDLE_USING_SE 
         se0Params.DIM1 = se0Params.DIM1 -(numPoints>>1);
         se1Params.DIM1 = se1Params.DIM1 -(numPoints>>1);

         __SE0_CLOSE();
         __SE1_CLOSE();
#endif
      }
      /* FFTLIB_asm(" MARK 9"); */
   }

   __SA0_CLOSE();
#ifndef TWIDDLE_USING_SE
   __SA2_CLOSE();
   __SA3_CLOSE();
   __SE0_CLOSE();
   __SE1_CLOSE();
#endif

   return status;
}

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_checkParams(FFTLIB_F32           *pX,
                                                 FFTLIB_bufParams1D_t *bufParamsX,
                                                 FFTLIB_F32           *pW,
                                                 FFTLIB_bufParams1D_t *bufParamsW,
                                                 FFTLIB_F32           *pY,
                                                 FFTLIB_bufParams1D_t *bufParamsY,
                                                 uint32_t              numPoints,
                                                 uint32_t              numChannels,
                                                 uint8_t               outmode,
                                                 void                 *pBlock)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   if ((pX == NULL) || (pW == NULL) || (pY == NULL)) {
      status = FFTLIB_ERR_NULL_POINTER;
   }
   else if (bufParamsX->dim_x != bufParamsW->dim_x || bufParamsX->dim_x != bufParamsY->dim_x) {
      status = FFTLIB_ERR_INVALID_DIMENSION;
   }
   /* else if (bufParamsX->dim_x < 64 * 2) { /\* Minimum number of points is 64 */
   /*                                         *\/ */
   /*    printf("dim < 64\n"); */
   /*    status = FFTLIB_ERR_INVALID_DIMENSION; */
   /* } */
   else if ((bufParamsX->data_type != FFTLIB_FLOAT32) || (bufParamsW->data_type != FFTLIB_FLOAT32) ||
            (bufParamsY->data_type != FFTLIB_FLOAT32)) {
      status = FFTLIB_ERR_INVALID_TYPE;
   }
   else if (((uint64_t) pX) & 0xFu) {               /* pX must be 16-byte aligned for a
                                                     */
      status = FFTLIB_ERR_NOT_ALIGNED_PTRS_STRIDES; /* streaming engine
                                                        configuration */
   }

   else if ((outmode != 0) && (outmode != 1)) {

      status = FFTLIB_ERR_INVALID_OUTMODE;
   }

   /* 512b not supported currently */
   else if (__C7X_VEC_SIZE_BITS__ == 512) {

      status = FFTLIB_ERR_NOT_IMPLEMENTED;
   }

   else {
      /* Check if number of pts is a power of 2 || power of 3 || power of 5 */
      uint32_t temp = numPoints / 2; // Get actual numPoints
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
