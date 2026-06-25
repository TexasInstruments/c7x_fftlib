// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "../../../common/c71/FFTLIB_debug.h"
#include "../../FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc/FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc.h"
#include "../FFTLIB_ifft1dBatched_i32fc_c32fc_o32f.h"
#include <cstdint>

#define SE_PARAM_BASE (0x0000)
#define SE0_PARAM_OFFSET (SE_PARAM_BASE)
#define SE1_PARAM_OFFSET (SE0_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA0_PARAM_OFFSET (SE1_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA1_PARAM_OFFSET (SA0_PARAM_OFFSET + SE_PARAM_SIZE)
#define SA2_PARAM_OFFSET (SA1_PARAM_OFFSET + SE_PARAM_SIZE)

typedef typename c7x::cfloat_vec CV;
typedef typename c7x::float_vec  V;
#define UNUSED(x) ((void) (x))
FFTLIB_STATUS
FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_init(FFTLIB_F32           *pX,
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
                                           uint8_t               inMode,
                                           void                 *pBlock)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   /* #if defined(FFTLIB_CHECK_PARAMS) || \ */
   /*     defined(FFTLIB_FFT1D_I32FC_C32FC_O32FC_CHECK_PARAMS) */
   /*    status = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams ( */
   /*        pX, bufParamsX, pW, bufParamsW, pY, bufParamsY, pBlock); */
   /*    if (status == FFTLIB_SUCCESS) */
   /* #endif */
   {

      __SE_TEMPLATE_v1 se0_param = __gen_SE_TEMPLATE_v1();
      __SE_TEMPLATE_v1 se1_param = __gen_SE_TEMPLATE_v1();
      __SA_TEMPLATE_v1 sa0_param = __gen_SA_TEMPLATE_v1();
      __SA_TEMPLATE_v1 sa1_param = __gen_SA_TEMPLATE_v1();
      __SA_TEMPLATE_v1 sa2_param = __gen_SA_TEMPLATE_v1();

      FFTLIB_bufParams1D_t bufParamsX_FFT;

      bufParamsX_FFT.dim_x = numPoints * numChannels;

      FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_init((FFTLIB_F32 *) pXFFT, &bufParamsX_FFT, (FFTLIB_F32 *) pW,
                                                  &bufParamsX_FFT, (FFTLIB_F32 *) pY, &bufParamsX_FFT, numPoints / 2,
                                                  numChannels, &((uint8_t *) pBlock)[6 * SE_PARAM_SIZE]);

      uint32_t elementCount = c7x::element_count_of<CV>::value;
      uint32_t offset       = numPoints >> 1;
      uint32_t SEBlocks     = offset / elementCount;

      if (inMode == 0) {
         uint32_t numPointsIn = (numPoints >> 1) + 1;

         se0_param.ICNT0 = elementCount;
         se0_param.DIM1  = elementCount;
         se0_param.ICNT1 = SEBlocks;
         se0_param.DIM2  = numPointsIn;
         se0_param.ICNT2 = numChannels;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<CV>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_3D;

         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_PARAM_OFFSET)) = se0_param;

         se1_param.ICNT0 = elementCount;
         se1_param.DIM1  = -(int32_t) elementCount;
         se1_param.ICNT1 = SEBlocks;
         se1_param.DIM2  = numPointsIn;
         se1_param.ICNT2 = numChannels;
         se1_param.DIR   = __SE_DIR_DEC;

         se1_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se1_param.VECLEN  = c7x::se_veclen<CV>::value;
         se1_param.DIMFMT  = __SE_DIMFMT_3D;

         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_PARAM_OFFSET)) = se1_param;

         /* Split Factor fetch forward */
         sa0_param.ICNT0 = elementCount;
         sa0_param.DIM1  = elementCount;
         sa0_param.ICNT1 = SEBlocks;
         sa0_param.DIM2  = 0;
         sa0_param.ICNT2 = numChannels;

         sa0_param.VECLEN                                                = c7x::sa_veclen<CV>::value;
         sa0_param.DIMFMT                                                = __SA_DIMFMT_3D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_PARAM_OFFSET)) = sa0_param;

         sa1_param.ICNT0 = elementCount;
         sa1_param.DIM1  = elementCount;
         sa1_param.ICNT1 = SEBlocks;
         sa1_param.DIM2  = 0;
         sa1_param.ICNT2 = numChannels;

         sa1_param.VECLEN                                                = c7x::sa_veclen<CV>::value;
         sa1_param.DIMFMT                                                = __SA_DIMFMT_3D;
         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA1_PARAM_OFFSET)) = sa1_param;

         sa2_param.ICNT0 = (numPoints >> 1);
         sa2_param.ICNT1 = numChannels;
         sa2_param.DIM1  = (numPoints >> 1);

         sa2_param.VECLEN = c7x::sa_veclen<CV>::value;
         sa2_param.DIMFMT = __SA_DIMFMT_2D;

         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA2_PARAM_OFFSET)) = sa2_param;
      }

      else {
         se0_param.ICNT0 = elementCount;
         se0_param.ICNT1 = 2;
         se0_param.DIM1  = offset;
         se0_param.ICNT2 = SEBlocks;
         se0_param.ICNT3 = numChannels;
         se0_param.DIM2  = elementCount;
         se0_param.DIM3  = numPoints;

         se0_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se0_param.VECLEN  = c7x::se_veclen<CV>::value;
         se0_param.DIMFMT  = __SE_DIMFMT_4D;

         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_PARAM_OFFSET)) = se0_param;

         se1_param.ICNT0 = elementCount;
         se1_param.ICNT1 = 2;
         se1_param.DIM1  = offset;
         se1_param.ICNT2 = SEBlocks;
         se1_param.ICNT3 = numChannels;
         se1_param.DIM2  = elementCount;
         se1_param.DIM3  = 0;

         se1_param.ELETYPE = __SE_ELETYPE_32BIT_CMPLX_SWAP;
         se1_param.VECLEN  = c7x::se_veclen<CV>::value;
         se1_param.DIMFMT  = __SE_DIMFMT_4D;

         *((__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_PARAM_OFFSET)) = se1_param;

         sa0_param.ICNT0 = numPoints >> 1;
         sa0_param.ICNT1 = numChannels;
         sa0_param.DIM1  = numPoints >> 1;

         sa0_param.VECLEN = c7x::sa_veclen<CV>::value;
         sa0_param.DIMFMT = __SA_DIMFMT_2D;

         *((__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_PARAM_OFFSET)) = sa0_param;
      }
   }
   return (status);
}

FFTLIB_STATUS
FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_kernel(FFTLIB_F32 *restrict pX,
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
                                             uint8_t               inMode,
                                             void                 *pBlock)
{

   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   uint32_t elementCount = c7x::element_count_of<CV>::value;
   uint32_t SEBlocks     = (numPoints >> 1) / elementCount;

   FFTLIB_F32 *restrict pXLocal  = pX;
   FFTLIB_F32 *restrict pSfLocal = pSf;

   CV var0, var1;
   CV temp0, temp1;
   CV sFA, sFB;
   CV regStore0;

   __vpred tmp, tmpSf;
   CV     *addr, *addrSf;

   uint32_t i;

   __SE_TEMPLATE_v1 se0Params = __gen_SE_TEMPLATE_v1(); // SE parameter vector
   __SE_TEMPLATE_v1 se1Params = __gen_SE_TEMPLATE_v1(); // SE parameter vector
   __SA_TEMPLATE_v1 sa0Params = __gen_SA_TEMPLATE_v1(); // SA parameter vector

   /* Half Spectrum inMode */
   if (inMode == 0) {
      __SA_TEMPLATE_v1 sa1Params = __gen_SA_TEMPLATE_v1(); // SA parameter vector
      __SA_TEMPLATE_v1 sa2Params = __gen_SA_TEMPLATE_v1(); // SA parameter vector
      UNUSED(sa1Params);
      UNUSED(sa2Params);
      se0Params = *(__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_PARAM_OFFSET);
      se1Params = *(__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_PARAM_OFFSET);
      sa0Params = *(__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_PARAM_OFFSET);
      sa1Params = *(__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA1_PARAM_OFFSET);
      sa2Params = *(__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA2_PARAM_OFFSET);

      __SE0_OPEN(pXLocal, se0Params);
      __SE1_OPEN(pXLocal + numPoints + 2, se1Params);
      __SA0_OPEN(sa0Params);
      __SA1_OPEN(sa1Params);
      __SA2_OPEN(sa2Params);

#pragma MUST_ITERATE(8, , 8)
#pragma UNROLL(8)
      for (i = 0; i < numChannels * SEBlocks; i++) {
         var0 = c7x::strm_eng<0, CV>::get_adv();
         var1 = c7x::strm_eng<1, CV>::get_adv();

         tmpSf  = c7x::strm_agen<0, CV>::get_vpred();
         addrSf = c7x::strm_agen<0, CV>::get_adv(pSfLocal);
         sFA    = __vload_pred(tmpSf, addrSf);

         tmpSf  = c7x::strm_agen<1, CV>::get_vpred();
         addrSf = c7x::strm_agen<1, CV>::get_adv(pSfLocal + numPoints);
         sFB    = __vload_pred(tmpSf, addrSf);

         temp0 = (__complex_multiply(var0, c7x::as_cfloat_vec(sFA)));
         temp1 = (__complex_conjugate_multiply(var1, c7x::as_cfloat_vec(sFB)));

         regStore0 = temp0 + temp1;
         tmp       = c7x::strm_agen<2, CV>::get_vpred();
         addr      = c7x::strm_agen<2, CV>::get_adv(&pXFFT[0]);
         __vstore_pred(tmp, addr, regStore0);
      }

      __SE0_CLOSE();
      __SE1_CLOSE();
      __SA0_CLOSE();
      __SA1_CLOSE();
      __SA2_CLOSE();
   }

   /* Full Spectrum inMode */
   else {
      se0Params = *(__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE0_PARAM_OFFSET);
      se1Params = *(__SE_TEMPLATE_v1 *) ((uint8_t *) pBlock + SE1_PARAM_OFFSET);
      sa0Params = *(__SA_TEMPLATE_v1 *) ((uint8_t *) pBlock + SA0_PARAM_OFFSET);

      __SE0_OPEN(pXLocal, se0Params);
      __SE1_OPEN(pSfLocal, se1Params);
      __SA0_OPEN(sa0Params);

#pragma MUST_ITERATE(8, , 8)
#pragma UNROLL(8)
      for (i = 0; i < numChannels * SEBlocks; i++) {
         var0 = c7x::strm_eng<0, CV>::get_adv();
         var1 = c7x::strm_eng<0, CV>::get_adv();

         sFA = c7x::strm_eng<1, CV>::get_adv();
         sFB = c7x::strm_eng<1, CV>::get_adv();

         temp0 = (__complex_multiply(var0, c7x::as_cfloat_vec(sFA)));
         temp1 = (__complex_multiply(var1, c7x::as_cfloat_vec(sFB)));

         regStore0 = temp0 + temp1;
         tmp       = c7x::strm_agen<0, CV>::get_vpred();
         addr      = c7x::strm_agen<0, CV>::get_adv(&pXFFT[0]);
         __vstore_pred(tmp, addr, regStore0);
      }

      __SE0_CLOSE();
      __SE1_CLOSE();
      __SA0_CLOSE();
   }

   FFTLIB_bufParams1D_t bufParamsX_FFT;

   bufParamsX_FFT.dim_x = numPoints * numChannels;

   FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_kernel((FFTLIB_F32 *) pXFFT, &bufParamsX_FFT, (FFTLIB_F32 *) pW,
                                                 &bufParamsX_FFT, (FFTLIB_F32 *) pY, &bufParamsX_FFT, numPoints / 2,
                                                 numChannels, &((uint8_t *) pBlock)[6 * SE_PARAM_SIZE]);

   return status;
}

#if (!defined(FFTLIB_REMOVE_CHECK_PARAMS) && !defined(FFTLIB_FFT1D_I32FC_C32FC_O32FC_REMOVE_CHECK_PARAMS)) ||          \
    (defined(FFTLIB_CHECK_PARAMS)) || (defined(FFTLIB_FFT1D_I32FC_C32FC_O32FC_CHECK_PARAMS))

FFTLIB_STATUS
FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams(FFTLIB_F32           *pX,
                                                  FFTLIB_bufParams1D_t *bufParamsX,
                                                  FFTLIB_F32           *pW,
                                                  FFTLIB_bufParams1D_t *bufParamsW,
                                                  FFTLIB_F32           *pY,
                                                  FFTLIB_bufParams1D_t *bufParamsY,
                                                  uint32_t              numPoints,
                                                  uint32_t              numChannels,
                                                  uint8_t               inMode,
                                                  void                 *pBlock)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   /* if ((pX == NULL) || (pW == NULL) || (pY == NULL)) { */
   /*    status = FFTLIB_ERR_NULL_POINTER; */
   /* } */
   /* else if (bufParamsX->dim_x != bufParamsW->dim_x || */
   /*          bufParamsX->dim_x != bufParamsY->dim_x) { */
   /*    status = FFTLIB_ERR_INVALID_DIMENSION; */
   /* } */
   /* else if (bufParamsX->dim_x < 64 * 2) { /\* Minimum number of points is 64
    * *\/ */
   /*    status = FFTLIB_ERR_INVALID_DIMENSION; */
   /* } */
   /* else if ((bufParamsX->data_type != FFTLIB_FLOAT32) || */
   /*          (bufParamsW->data_type != FFTLIB_FLOAT32) || */
   /*          (bufParamsY->data_type != FFTLIB_FLOAT32)) { */
   /*    status = FFTLIB_ERR_INVALID_TYPE; */
   /* } */
   /* else if (((uint64_t) pX) & 0xFu) { /\* pX must be 16-byte aligned for a
    * *\/ */
   /*    status = FFTLIB_ERR_NOT_ALIGNED_PTRS_STRIDES; /\* streaming engine */
   /*                                                     configuration *\/ */
   /* } */
   /* else { */
   /*    /\* Check if number of pts is a power of 2 *\/ */
   /*    uint32_t k = 0; */
   /*    while (k < 32) { */
   /*       if (bufParamsX->dim_x & (1u << k)) { */
   /*          break; */
   /*       } */
   /*       k++; */
   /*    } */
   /*    if ((1u << k) != bufParamsX->dim_x) { */
   /*       status = FFTLIB_ERR_INVALID_DIMENSION; */
   /*    } */
   /* } */
   return (status);
}

#endif
