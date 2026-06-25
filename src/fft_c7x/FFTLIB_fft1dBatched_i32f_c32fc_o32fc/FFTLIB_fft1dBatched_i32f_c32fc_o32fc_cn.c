// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_fft1dBatched_i32f_c32fc_o32fc_cn.h"
#include "../FFTLIB_fft1dBatched_i32fc_c32fc_o32fc/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_cn.h"

// TODO: add numpoints and numchannels to params here and header file
FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_cn(FFTLIB_F32           *pX,
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
                                        uint8_t               outmode)
{
   FFTLIB_STATUS        status = FFTLIB_SUCCESS;
   FFTLIB_bufParams1D_t bufParamsX_FFT;
   // FFTLIB_bufParams1D_t  *bufPtr = &bufParamsX_FFT;

   /* Outmode: number of complex out points */
   /* numPointsOut = N/2 + 1 for outmode = 0 but for calculation purposes keep it at N/2 */
   uint32_t numPointsOut = (outmode == 1U) ? numPoints : ((numPoints >> 1U) + 1U);

   bufParamsX_FFT.dim_x = numPoints;

   /* Do N/2 batched complex fft with N real numbers*/
   FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_cn(pX, &bufParamsX_FFT, pW, &bufParamsX_FFT, pXFFT, &bufParamsX_FFT,
                                            numPoints >> 1, numChannels);

   uint32_t ch;
   // TODO: loop through each channel and change indexing
   for (ch = 0; ch < numChannels; ch++) {
      uint32_t i    = 0;
      uint32_t c    = 0;
      uint32_t cout = 0;

      FFTLIB_F32 temp0Real;
      FFTLIB_F32 temp0Imag;
      FFTLIB_F32 temp1Real;
      FFTLIB_F32 temp1Imag;

      FFTLIB_F32 var0Real;
      FFTLIB_F32 var0Imag;
      FFTLIB_F32 var1Real;
      FFTLIB_F32 var1Imag;

      c    = (ch * (numPoints));
      cout = (ch * (numPointsOut));

      for (i = 0; i < (numPoints >> 1U); i += 1U) {
         var0Real = pXFFT[c + (2U * i)]; // [1]
         var0Imag = pXFFT[c + (2U * i) + 1U];
         if (!i) {
            var1Real = 0;
            var1Imag = 0;
         }
         else {
            var1Real = pXFFT[c + (numPoints) - (2U * i)];
            var1Imag = pXFFT[c + (numPoints) - (2U * i) + 1U];
         }

         temp0Real = ((var0Real * pSf[2U * i]) - (var0Imag * pSf[(2U * i) + 1U]));
         temp0Imag = ((var0Real * pSf[(2U * i) + 1U]) + (var0Imag * pSf[2U * i]));

         if (!i) {
            temp1Real = ((pXFFT[c + 0U] * pSf[(2U * numPoints) - (2U * i) - 2U]) +
                         (pXFFT[c + 1U] * pSf[(2U * numPoints) - (2U * i) - 2U + 1U]));
            temp1Imag = ((pXFFT[c + 0U] * pSf[(2U * numPoints) - (2U * i) - 2U]) -
                         (pXFFT[c + 1U] * pSf[(2U * numPoints) - (2U * i) - 2U + 1U]));
         }
         else {
            temp1Real = ((var1Real * pSf[(2U * numPoints) - (2U * i) - 2U]) +
                         (var1Imag * pSf[(2U * numPoints) - (2U * i) - 2U + 1U]));
            temp1Imag = ((var1Real * pSf[(2U * numPoints) - (2U * i) - 2U + 1U]) -
                         (var1Imag * pSf[(2U * numPoints) - (2U * i) - 2U]));
         }

         // TODO: change numPoints to legal memory access
         if ((2U * i) < (numPointsOut * 2U)) {
            pY[(cout << 1U) + (2U * i)]      = temp0Real + temp1Real;
            pY[(cout << 1U) + (2U * i) + 1U] = temp0Imag + temp1Imag;
         }

         if (outmode == 0) {
            continue;
         }
         /* if half spectrum, no need to check complex conjugate boundaries */

         /* printf("pY[%d] = %f\n", 2 * i, pY[2 * i]); */
         /* printf("pY[%d] = %f\n", 2 * i + 1, pY[2 * i + 1]); */

         // TODO: complex conjugate of first element doesn't exist for the output
         /* Don't write if index is greater than buffer size */
         if ((((numPointsOut) *2) - (2 * i)) < (numPointsOut * 2)) {
            pY[(cout << 1U) + ((numPointsOut) *2U) - (2U * (i))]      = pY[(cout << 1U) + (2U * i)];
            pY[(cout << 1U) + ((numPointsOut) *2U) - (2U * (i)) + 1U] = pY[(cout << 1U) + (2U * i) + 1U] * (-1.0f);
         }

         /* If index greater than buffer size, goto next loop */
         else {
            continue;
         }
      } // end numPoints loop

      /* calculate nyquist frequency bin */
      // similarly for i = numPoints >> 1
      i = (numPoints >> 1U);

      pY[(cout << 1U) + (2U * i)]      = pXFFT[c + 0U] - pXFFT[c + 1U];
      pY[(cout << 1U) + (2U * i) + 1U] = 0;
      /* printf("pY[%d] = %f\n", 2 * i, pY[2 * i]); */
      /* printf("pY[%d] = %f\n", 2 * i + 1, pY[2 * i + 1]); */

   } // end numChannels loop

   return (status);
}

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_checkParams_cn(FFTLIB_F32           *pX,
                                                    FFTLIB_bufParams1D_t *bufParamsX,
                                                    FFTLIB_F32           *pW,
                                                    FFTLIB_bufParams1D_t *bufParamsW,
                                                    FFTLIB_F32           *pY,
                                                    FFTLIB_bufParams1D_t *bufParamsY,
                                                    uint32_t              numPoints,
                                                    uint32_t              numChannels,
                                                    uint8_t               outmode)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   if ((pX == NULL) || (pW == NULL) || (pY == NULL)) {
      status = FFTLIB_ERR_NULL_POINTER;
   }
   else if ((bufParamsX->dim_x != bufParamsW->dim_x) || (bufParamsX->dim_x != bufParamsY->dim_x)) {
      status = FFTLIB_ERR_INVALID_DIMENSION;
   }
   else if ((bufParamsX->data_type != (uint32_t) FFTLIB_FLOAT32) ||
            (bufParamsW->data_type != (uint32_t) FFTLIB_FLOAT32) ||
            (bufParamsY->data_type != (uint32_t) FFTLIB_FLOAT32)) {
      status = FFTLIB_ERR_INVALID_TYPE;
   }
   else {
      /* Check if number of pts is a power of 2 */
      uint32_t k = 0;
      while (k < 32U) {
         if (bufParamsX->dim_x & (1u << k)) {
            break;
         }
         k++;
      }
      if ((1u << k) != bufParamsX->dim_x) {
         status = FFTLIB_ERR_INVALID_DIMENSION;
      }
   }
   return (status);
}
