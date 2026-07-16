// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include <math.h>

#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32f.h"

void ifft_c2r_tw_gen(FFTLIB_F32 *pW, int32_t numPoints)
{
   uint32_t     i, j, k = 0, t;
   const double PI = 3.141592654;

   // since we perform N-point FFT to compute FFT of 2N-point real sequence
   uint32_t uNumPoints = (uint32_t) numPoints >> 1U;

   /* RADIX-5 stage twiddles */
   if ((int32_t) uNumPoints % 5 == 0) {
      int32_t numPointsStage = (int32_t) uNumPoints;
      t                      = (int32_t) uNumPoints / 5;
      for (j = 1; j <= (int32_t) uNumPoints / 5 && numPointsStage % 5 == 0; j = j * 5) {
         for (i = 0; i < (int32_t) uNumPoints / 5; i += j) {
            pW[k]             = (FFTLIB_F32) cos(2 * PI * i / uNumPoints);
            pW[k + 1]         = (FFTLIB_F32) -sin(2 * PI * i / uNumPoints);
            pW[k + 2 * t]     = (FFTLIB_F32) cos(4 * PI * i / uNumPoints);
            pW[k + 2 * t + 1] = (FFTLIB_F32) -sin(4 * PI * i / uNumPoints);
            pW[k + 4 * t]     = (FFTLIB_F32) cos(6 * PI * i / uNumPoints);
            pW[k + 4 * t + 1] = (FFTLIB_F32) -sin(6 * PI * i / uNumPoints);
            pW[k + 6 * t]     = (FFTLIB_F32) cos(8 * PI * i / uNumPoints);
            pW[k + 6 * t + 1] = (FFTLIB_F32) -sin(8 * PI * i / uNumPoints);
            k += 2;
         }
         k += t * 6;
         t = t / 5;
         numPointsStage /= 5;
      }
      uNumPoints = (uint32_t) numPointsStage;
   }

   /* RADIX-3 stage twiddles */
   if ((int32_t) uNumPoints % 3 == 0) {
      int32_t numPointsStage = (int32_t) uNumPoints;
      t                      = (int32_t) uNumPoints / 3;
      for (j = 1; j <= (int32_t) uNumPoints / 3 && numPointsStage % 3 == 0; j = j * 3) {
         for (i = 0; i < (int32_t) uNumPoints / 3; i += j) {
            pW[k]             = (FFTLIB_F32) cos(2 * PI * i / uNumPoints);
            pW[k + 1]         = (FFTLIB_F32) -sin(2 * PI * i / uNumPoints);
            pW[k + 2 * t]     = (FFTLIB_F32) cos(4 * PI * i / uNumPoints);
            pW[k + 2 * t + 1] = (FFTLIB_F32) -sin(4 * PI * i / uNumPoints);
            k += 2;
         }
         k += t * 2;
         t = t / 3;
         numPointsStage /= 3;
      }
      uNumPoints = (uint32_t) numPointsStage;
   }

   /* RADIX-4 stage twiddles */
   if ((int32_t) uNumPoints % 4 == 0) {
      int32_t numPointsStage = (int32_t) uNumPoints;
      t                      = (int32_t) uNumPoints >> 2;
      for (j = 1; j <= (int32_t) uNumPoints >> 2 && numPointsStage % 4 == 0; j = j << 2) {
         for (i = 0; i < (int32_t) uNumPoints >> 2; i += j) {
            /* TODO: Big endian requires different format of Twiddle factors? */
            pW[k]             = (FFTLIB_F32) cos(2 * PI * i / uNumPoints);
            pW[k + 1]         = (FFTLIB_F32) -sin(2 * PI * i / uNumPoints);
            pW[k + 2 * t]     = (FFTLIB_F32) cos(4 * PI * i / uNumPoints);
            pW[k + 2 * t + 1] = (FFTLIB_F32) -sin(4 * PI * i / uNumPoints);
            pW[k + 4 * t]     = (FFTLIB_F32) cos(6 * PI * i / uNumPoints);
            pW[k + 4 * t + 1] = (FFTLIB_F32) -sin(6 * PI * i / uNumPoints);
            k += 2;
         }
         k += (t) *4;
         t = t >> (int32_t) 2;
         numPointsStage /= 4;
      }
   }
}

void ifft_c2r_split_factor_gen(FFTLIB_F32 *pSf, int32_t numPoints)
{

   int32_t i = 0;

   const double PI = 3.141592654;

   for (i = 0; i < (numPoints >> (int32_t) 1); i++) {
      pSf[2 * i]     = (FFTLIB_F32) (0.5 * (1 - sin(2 * PI * i / numPoints)));
      pSf[2 * i + 1] = (FFTLIB_F32) (0.5 * (cos(2 * PI * i / numPoints)));

      pSf[2 * i + numPoints]     = (FFTLIB_F32) (0.5 * (1 + sin(2 * PI * i / numPoints)));
      pSf[2 * i + numPoints + 1] = (FFTLIB_F32) (0.5 * (-cos(2 * PI * i / numPoints)));
   }
}
