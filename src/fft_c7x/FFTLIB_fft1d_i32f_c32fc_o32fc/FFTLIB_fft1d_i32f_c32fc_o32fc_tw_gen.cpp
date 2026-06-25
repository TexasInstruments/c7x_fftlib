// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include <math.h>

#include "FFTLIB_fft1d_i32f_c32fc_o32fc.h"

void tw_gen_r2c(FFTLIB_F32 *pW, int32_t numPoints)
{
   int32_t      i, j, k, t;
   const double PI = 3.141592654;

   // since we perform N-point FFT to compute FFT of 2N-point real sequence
   numPoints >>= (int32_t) 1;

   t = numPoints >> 2;
   for (j = 1, k = 0; j <= (numPoints >> (int32_t) 2); j = j << (int32_t) 2) {
      for (i = 0; i < numPoints >> 2; i += j) {
         /* TODO: Big endian requires different format of Twiddle factors? */
         pW[k]             = (FFTLIB_F32) cos(2 * PI * i / numPoints);
         pW[k + 1]         = (FFTLIB_F32) -sin(2 * PI * i / numPoints);
         pW[k + 2 * t]     = (FFTLIB_F32) cos(4 * PI * i / numPoints);
         pW[k + 2 * t + 1] = (FFTLIB_F32) -sin(4 * PI * i / numPoints);
         pW[k + 4 * t]     = (FFTLIB_F32) cos(6 * PI * i / numPoints);
         pW[k + 4 * t + 1] = (FFTLIB_F32) -sin(6 * PI * i / numPoints);
         k += 2;
      }
      k += (t) *4;
      t = t >> (int32_t) 2;
   }
}

void split_factor_gen_r2c(FFTLIB_F32 *pSf, int32_t numPoints)
{

   int32_t      i;
   const double PI = 3.141592654;

   for (i = 0; i < (numPoints >> (int32_t) 1); i++) {
      pSf[2 * i]     = (FFTLIB_F32) (0.5 * (1 - sin(2 * PI * i / numPoints)));
      pSf[2 * i + 1] = (FFTLIB_F32) (0.5 * (-cos(2 * PI * i / numPoints)));

      /* pSf[2 * i + numPoints] = */
      /*     (FFTLIB_F32) (0.5 * (1 + sin (2 * PI * i / numPoints))); */
      /* pSf[2 * i + numPoints + 1] = */
      /*     (FFTLIB_F32) (0.5 * (cos (2 * PI * i / numPoints))); */

      pSf[2 * numPoints - 2 * i - 2]     = (FFTLIB_F32) (0.5 * (1 + sin(2 * PI * i / numPoints)));
      pSf[2 * numPoints - 2 * i - 2 + 1] = (FFTLIB_F32) (0.5 * (cos(2 * PI * i / numPoints)));
   }

   /* for (i = 0; i < numPoints; i++) { */
   /*    printf ("%.2f, ", pSf[i]); */
   /* } */

   /* printf ("\n\n"); */
   /* for (i = 0; i < numPoints; i++) { */
   /*    printf ("%.2f, ", pSf[i + numPoints]); */
   /* } */
}
