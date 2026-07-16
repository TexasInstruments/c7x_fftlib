// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include <math.h>

#include "FFTLIB_fft1dBatched_i32f_c32fc_o32fc.h"

void tw_gen_r2c(FFTLIB_F32 *pW, int32_t numPoints)
{
   int32_t      i, j, k = 0, t;
   const double PI = 3.141592654;

   // since we perform N-point FFT to compute FFT of 2N-point real sequence
   numPoints >>= (int32_t) 1;

   // RADIX-5 stage twiddles
   if (numPoints % 5 == 0) {
      int32_t numPointsStage = numPoints;
      t                      = numPoints / 5;
      for (j = 1; j <= numPoints / 5 && numPointsStage % 5 == 0; j = j * 5) {
         for (i = 0; i < numPoints / 5; i += j) {
               pW[k]             = (FFTLIB_F32) cos(2 * PI * i / numPoints);
               pW[k + 1]         = (FFTLIB_F32) -sin(2 * PI * i / numPoints);
               pW[k + 2 * t]     = (FFTLIB_F32) cos(4 * PI * i / numPoints);
               pW[k + 2 * t + 1] = (FFTLIB_F32) -sin(4 * PI * i / numPoints);
               pW[k + 4 * t]     = (FFTLIB_F32) cos(6 * PI * i / numPoints);
               pW[k + 4 * t + 1] = (FFTLIB_F32) -sin(6 * PI * i / numPoints);
               pW[k + 6 * t]     = (FFTLIB_F32) cos(8 * PI * i / numPoints);
               pW[k + 6 * t + 1] = (FFTLIB_F32) -sin(8 * PI * i / numPoints);
               k += 2;
         }
         k += t * 6;
         t = t / 5;
         numPointsStage /= 5;
      }
      numPoints = numPointsStage;
   }
   // RADIX-3 stage twiddles
   if (numPoints % 3 == 0) {
      int32_t numPointsStage = numPoints;
      t                      = numPoints / 3;
      for (j = 1; j <= numPoints / 3 && numPointsStage % 3 == 0; j = j * 3) {
         for (i = 0; i < numPoints / 3; i += j) {
               pW[k]             = (FFTLIB_F32) cos(2 * PI * i / numPoints);
               pW[k + 1]         = (FFTLIB_F32) -sin(2 * PI * i / numPoints);
               pW[k + 2 * t]     = (FFTLIB_F32) cos(4 * PI * i / numPoints);
               pW[k + 2 * t + 1] = (FFTLIB_F32) -sin(4 * PI * i / numPoints);
               k += 2;
         }
         k += t * 2;
         t = t / 3;
         numPointsStage /= 3;
      }
      numPoints = numPointsStage;
   }

   // RADIX-4 stage twiddles (no internal DFT matrix needed)
   if (numPoints % 4 == 0) {
      int32_t numPointsStage = numPoints;
      t                      = numPoints >> 2;
      for (j = 1; j <= numPoints >> (int32_t) 2 && numPointsStage % 4 == 0; j = j << 2) {
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
         k += t * 4;
         t = t >> 2;
         numPointsStage /= 4;
      }
   }
}

void split_factor_gen_r2c(FFTLIB_F32 *pSf, int32_t numPoints)
{

   int32_t      i;
   const double PI = 3.141592654;

   for (i = 0; i < numPoints >> (int32_t) 1; i++) {
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
