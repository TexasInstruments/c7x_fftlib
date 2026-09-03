// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_fft1d_i32f_c32fc_o32fc_cn.h"

FFTLIB_STATUS
FFTLIB_fft1d_i32f_c32fc_o32fc_cn(FFTLIB_F32           *pX,
                                 FFTLIB_bufParams1D_t *bufParamsX,
                                 FFTLIB_F32           *pW,
                                 FFTLIB_bufParams1D_t *bufParamsW,
                                 FFTLIB_F32           *pXFFT,
                                 FFTLIB_bufParams1D_t *bufParamsXFFT,
                                 FFTLIB_F32           *pSf,
                                 FFTLIB_bufParams1D_t *bufParamsSf,
                                 FFTLIB_F32           *pY,
                                 FFTLIB_bufParams1D_t *bufParamsY)
{
   FFTLIB_STATUS        status = FFTLIB_SUCCESS;
   uint32_t             numPoints;
   FFTLIB_bufParams1D_t bufParamsX_FFT;

   /* #ifdef FFTLIB_CHECK_PARAMS */
   /*    status = FFTLIB_fft1d_i32f_c32fc_o32fc_checkParams_cn ( */
   /*        pX, bufParamsX, pW, bufParamsW, pY, bufParamsY); */
   /*    if (status == FFTLIB_SUCCESS) */
   /* #endif */
   {

      numPoints                    = bufParamsX->dim_x;
      bufParamsX_FFT.dim_x         = numPoints;
      FFTLIB_bufParams1D_t *bufPtr = &bufParamsX_FFT;

      FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_cn(pX, bufPtr, pW, bufPtr, pXFFT, bufPtr, numPoints >> 1, 1);

      uint32_t i = 0;

      FFTLIB_F32 temp0Real;
      FFTLIB_F32 temp0Imag;
      FFTLIB_F32 temp1Real;
      FFTLIB_F32 temp1Imag;

      FFTLIB_F32 var0Real;
      FFTLIB_F32 var0Imag;
      FFTLIB_F32 var1Real;
      FFTLIB_F32 var1Imag;

      /* printf ("\npY natC FFT below:\n\n"); */
      /* for (i = 0; i < numPoints; i++) { */
      /*    printf ("%.2f, ", pY[i]); */
      /* } */
      /* printf ("\n\n"); */

      // we dont reach numPoints + 2 * (numPoints >> 2) in loop
      i        = (numPoints >> 2);
      var0Real = pXFFT[2U * i];
      var0Imag = pXFFT[(2U * i) + 1U];
      var1Real = pXFFT[(numPoints) - (2U * i)];
      var1Imag = pXFFT[(numPoints) - (2U * i) + 1U];

      temp0Real = (var0Real * pSf[2U * i]) - (var0Imag * pSf[(2U * i) + 1U]);
      temp0Imag = (var0Real * pSf[(2U * i) + 1U]) + (var0Imag * pSf[2U * i]);

      temp1Real = (var1Real * pSf[(2U * i) + numPoints]) + (var1Imag * pSf[(2U * i) + numPoints + 1U]);
      temp1Imag = (var1Real * pSf[(2U * i) + numPoints + 1]) - (var1Imag * pSf[(2U * i) + numPoints]);

      pY[2U * i]                            = temp0Real + temp1Real;
      pY[(2U * i) + 1U]                     = temp0Imag + temp1Imag;
      pY[(numPoints * 2U) - (2U * (i))]     = pY[2U * i];
      pY[(numPoints * 2U) - (2U * (i)) + 1] = pY[(2U * i) + 1U] * (-1.0f);

      // similarly for i = numPoints >> 1
      i = (numPoints >> 1U);

      pY[2U * i]        = pXFFT[0] - pXFFT[1];
      pY[(2U * i) + 1U] = 0;

      for (i = 0U; i < (numPoints >> 1U); i += 1) {
         /* for (i = 0; i < 16; i += 1) { */
         /* printf ("\nIteration %d\n", i); */
         var0Real = pXFFT[2U * i]; // [1]
         var0Imag = pXFFT[(2U * i) + 1U];
         var1Real = pXFFT[(numPoints) - (2U * i)];
         var1Imag = pXFFT[(numPoints) - (2U * i) + 1U];

         /* printf ("var0Real = %0.2f, var0Imag = %0.2f\n", var0Real, var0Imag);
          */
         /* printf ("var1Real = %0.2f, var1Imag = %0.2f\n", var1Real, var1Imag);
          */
         // A*X
         /* temp0Real = pY[2 * i] * pSf[2 * i] - (pY[2 * i + 1] * pSf[2 * i +
          * 1]); */
         /* temp0Imag = pY[2 * i] * pSf[2 * i + 1] + (pY[2 * i + 1] * pSf[2 *
          * i]); */

         temp0Real = (var0Real * pSf[2U * i]) - ((var0Imag * pSf[(2U * i) + 1U]));
         temp0Imag = (var0Real * pSf[(2U * i) + 1U]) + ((var0Imag * pSf[2U * i]));

         /* printf ("temp0Real = %0.2f, temp0Imag = %0.2f\n", temp0Real, */
         /*         temp0Imag); */
         /* printf ("temp2Real = %0.2f, temp2Imag = %0.2f\n", temp2Real, */
         /*         temp2Imag); */
         // B*X'[N-k]
         if (!i) {
            temp1Real = ((pXFFT[0] * pSf[(2U * numPoints) - (2U * i) - 2U]) +
                         (pXFFT[1] * pSf[(2U * numPoints) - (2U * i) - 2U + 1U]));
            temp1Imag = ((pXFFT[0] * pSf[(2U * numPoints) - (2U * i) - 2U]) -
                         (pXFFT[1] * pSf[(2U * numPoints) - (2U * i) - 2U + 1U]));
         }
         else {
            /* temp1Real = */
            /*     pY[numPoints - (2 * (i))] * pSf[2 * i + numPoints] + */
            /*     pY[numPoints - (2 * (i)) + 1] * pSf[2 * i + numPoints + 1];
             */
            /* temp1Imag = pY[numPoints - (2 * (i))] * pSf[2 * i + numPoints +
             * 1] - */
            /*             pY[numPoints - (2 * (i)) + 1] * pSf[2 * i +
             * numPoints]; */
            temp1Real = ((var1Real * pSf[(2U * numPoints) - (2U * i) - 2U]) +
                         (var1Imag * pSf[(2U * numPoints) - (2U * i) - 2U + 1U]));
            temp1Imag = ((var1Real * pSf[(2U * numPoints) - (2U * i) - 2U + 1U]) -
                         (var1Imag * pSf[(2U * numPoints) - (2U * i) - 2U]));
         }

         /* printf ("psFReal = %0.2f, psFImag = %0.2f\n", */
         /*         pSf[2 * numPoints - 2 * i - 2], */
         /*         pSf[2 * numPoints - 2 * i - 2 + 1]); */

         /* printf ("temp1Real = %0.2f, temp1Imag = %0.2f\n", temp1Real, */
         /*         temp1Imag); */

         /* printf ("temp3Real = %0.2f, temp3Imag = %0.2f\n", temp3Real, */
         /*         temp3Imag); */

         pY[2U * i]                             = temp0Real + temp1Real;
         pY[(2U * i) + 1U]                      = temp0Imag + temp1Imag;
         pY[(numPoints * 2U) - (2U * (i))]      = pY[2U * i];
         pY[(numPoints * 2U) - (2U * (i)) + 1U] = pY[(2U * i) + 1U] * (-1.0f);
      }

      /* printf ("pY natC below:\n"); */
      /* for (i = 0; i < 2 * numPoints; i += 2) { */
      /*    printf ("%d: %.2f, %.2f\n", i >> 1, pY[i], pY[i + 1]); */
      /* } */

      return (status);
   }
}

FFTLIB_STATUS
FFTLIB_fft1d_i32f_c32fc_o32fc_checkParams_cn(FFTLIB_F32           *pX,
                                             FFTLIB_bufParams1D_t *bufParamsX,
                                             FFTLIB_F32           *pW,
                                             FFTLIB_bufParams1D_t *bufParamsW,
                                             FFTLIB_F32           *pY,
                                             FFTLIB_bufParams1D_t *bufParamsY)
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
      /* Check if number of pts is even (for split-factor real FFT) */
      if ((bufParamsX->dim_x & 1U) != 0U) {
         status = FFTLIB_ERR_INVALID_DIMENSION;
      }
      else {
         /* Check if numPoints/2 is a power of {2, 3, 5} */
         uint32_t temp = bufParamsX->dim_x >> 1; // half numPoints
         uint32_t i;

         for (i = 0U; i < 32U && (temp % 5U == 0U); ++i) {
            temp /= 5U;
         }
         for (i = 0U; i < 32U && (temp % 3U == 0U); ++i) {
            temp /= 3U;
         }
         for (i = 0U; i < 32U && (temp % 2U == 0U); ++i) {
            temp /= 2U;
         }

         if (temp != 1U) {
            status = FFTLIB_ERR_INVALID_DIMENSION;
         }
      }
   }
   return (status);
}
