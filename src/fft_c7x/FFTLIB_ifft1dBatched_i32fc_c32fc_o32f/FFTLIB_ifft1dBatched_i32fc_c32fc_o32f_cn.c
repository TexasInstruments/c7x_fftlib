// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_cn.h"

FFTLIB_STATUS
FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_cn(FFTLIB_F32           *pX,
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
                                         uint8_t               inMode)
{
   FFTLIB_STATUS        status = FFTLIB_SUCCESS;
   FFTLIB_bufParams1D_t bufParamsX_FFT;

   /* #ifdef FFTLIB_CHECK_PARAMS */
   /*    status = FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn ( */
   /*        pX, bufParamsX, pW, bufParamsW, pY, bufParamsY); */
   /*    if (status == FFTLIB_SUCCESS) */
   /* #endif */

   uint32_t N_2 = numPoints >> 1;

   uint32_t ch;

   for (ch = 0; ch < numChannels; ch++) {
      uint32_t i         = 0;
      uint32_t c         = 0;
      uint32_t ch_stride = 0;
      uint32_t stride    = 0;

      FFTLIB_F32 temp0Real;
      FFTLIB_F32 temp0Imag;
      FFTLIB_F32 temp1Real;
      FFTLIB_F32 temp1Imag;

      FFTLIB_F32 var0Real;
      FFTLIB_F32 var0Imag;
      FFTLIB_F32 var1Real;
      FFTLIB_F32 var1Imag;

      stride    = (inMode == 0U) ? 2U * (N_2 + 1U) : 2U * numPoints;
      ch_stride = (ch * stride);
      c         = (ch * 2U * numPoints);

      for (i = 0U; i < N_2; i++) {

         /* inMode: Number of complex input points */
         /* Generate the other half(using hermitian symmetry) of the input if inMode==0 */
         if (inMode == 0U) {
            var0Real = pX[ch_stride + (2U * i)];
            var0Imag = pX[ch_stride + (2U * i) + 1U];

            uint32_t j = N_2 - i;
            var1Real   = pX[ch_stride + (2U * j)];
            var1Imag   = -pX[ch_stride + (2U * j) + 1U];
         }
         else {
            var0Real = pX[ch_stride + (2U * i)];
            var0Imag = pX[ch_stride + (2U * i) + 1U];

            var1Real = pX[ch_stride + (2U * i) + numPoints];
            var1Imag = pX[ch_stride + (2U * i) + 1 + numPoints];
         }

         temp0Real = var0Real * pSf[(2U * i)] - (var0Imag * pSf[(2 * i) + 1U]);
         temp0Imag = var0Real * pSf[(2U * i) + 1U] + (var0Imag * pSf[(2U * i)]);

         temp1Real = var1Real * pSf[(2U * i) + numPoints] - (var1Imag * pSf[(2U * i) + 1U + (numPoints)]);
         temp1Imag = var1Real * pSf[(2U * i) + 1U + numPoints] + (var1Imag * pSf[(2U * i) + numPoints]);

         pXFFT[(c >> 1U) + (2U * i)]      = temp0Real + temp1Real;
         pXFFT[(c >> 1U) + (2U * i) + 1U] = temp0Imag + temp1Imag;
      }
   }

   FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_cn(pXFFT, &bufParamsX_FFT, pW, &bufParamsX_FFT, pY, &bufParamsX_FFT,
                                             numPoints / 2, numChannels);

   return (status);
}

FFTLIB_STATUS
FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_checkParams_cn(FFTLIB_F32           *pX,
                                                     FFTLIB_bufParams1D_t *bufParamsX,
                                                     FFTLIB_F32           *pW,
                                                     FFTLIB_bufParams1D_t *bufParamsW,
                                                     FFTLIB_F32           *pY,
                                                     FFTLIB_bufParams1D_t *bufParamsY)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   /* if ((pX == NULL) || (pW == NULL) || (pY == NULL)) { */
   /*    status = FFTLIB_ERR_NULL_POINTER; */
   /* } */
   /* else if (bufParamsX->dim_x != bufParamsW->dim_x || */
   /*          bufParamsX->dim_x != bufParamsY->dim_x) { */
   /*    status = FFTLIB_ERR_INVALID_DIMENSION; */
   /* } */
   /* else if ((bufParamsX->data_type != FFTLIB_FLOAT32) || */
   /*          (bufParamsW->data_type != FFTLIB_FLOAT32) || */
   /*          (bufParamsY->data_type != FFTLIB_FLOAT32)) { */
   /*    status = FFTLIB_ERR_INVALID_TYPE; */
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
