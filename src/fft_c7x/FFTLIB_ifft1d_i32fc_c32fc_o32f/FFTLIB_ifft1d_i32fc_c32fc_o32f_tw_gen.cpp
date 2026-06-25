// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include <math.h>

#include "FFTLIB_ifft1d_i32fc_c32fc_o32f.h"

void ifft_c2r_tw_gen(FFTLIB_F32 *pW, int32_t numPoints)
{
   uint32_t     i, j, k, t;
   const double PI = 3.141592654;

   // since we perform N-point FFT to compute FFT of 2N-point real sequence
   // numPoints >>= (int32_t)1;
   uint32_t uNumPoints = (uint32_t) numPoints >> 1U;
   t                   = uNumPoints >> (int32_t) 2;
   for (j = 1U, k = 0U; j <= ((uint32_t) uNumPoints >> 2U); j = j << 2U) {
      for (i = 0U; i < uNumPoints >> 2U; i += j) {
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
