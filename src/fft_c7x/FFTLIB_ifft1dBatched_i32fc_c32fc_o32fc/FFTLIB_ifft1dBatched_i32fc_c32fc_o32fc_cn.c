// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_cn.h"

/* CODE_SECTION (FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_cn, ".text:ansi") */
/* CODE_SECTION (FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_checkParams_cn, */
/*               ".text:ansi") */

void butterfly4x4(FFTLIB_F32  point0Re,
                  FFTLIB_F32  point0Im,
                  FFTLIB_F32  point1Re,
                  FFTLIB_F32  point1Im,
                  FFTLIB_F32  point2Re,
                  FFTLIB_F32  point2Im,
                  FFTLIB_F32  point3Re,
                  FFTLIB_F32  point3Im,
                  FFTLIB_F32  x1TwRe,
                  FFTLIB_F32  x1TwIm,
                  FFTLIB_F32  x2TwRe,
                  FFTLIB_F32  x2TwIm,
                  FFTLIB_F32  x3TwRe,
                  FFTLIB_F32  x3TwIm,
                  FFTLIB_F32 *bflyOut)
{
   FFTLIB_F32 x0Re;
   FFTLIB_F32 x0Im;
   FFTLIB_F32 x1Re;
   FFTLIB_F32 x1Im;
   FFTLIB_F32 x2Re;
   FFTLIB_F32 x2Im;
   FFTLIB_F32 x3Re;
   FFTLIB_F32 x3Im;

   x0Re = point0Re + point1Re + point2Re + point3Re;

   x0Im = point0Im + point1Im + point2Im + point3Im;

   x1Re =
       ((point0Re + point1Im - point2Re - point3Im) * x1TwRe) - ((point0Im - point1Re - point2Im + point3Re) * x1TwIm);

   x1Im =
       ((point0Re + point1Im - point2Re - point3Im) * x1TwIm) + ((point0Im - point1Re - point2Im + point3Re) * x1TwRe);

   x2Re =
       ((point0Re - point1Re + point2Re - point3Re) * x2TwRe) - ((point0Im - point1Im + point2Im - point3Im) * x2TwIm);

   x2Im =
       ((point0Re - point1Re + point2Re - point3Re) * x2TwIm) + ((point0Im - point1Im + point2Im - point3Im) * x2TwRe);

   x3Re =
       ((point0Re - point1Im - point2Re + point3Im) * x3TwRe) - ((point0Im + point1Re - point2Im - point3Re) * x3TwIm);

   x3Im =
       ((point0Re - point1Im - point2Re + point3Im) * x3TwIm) + ((point0Im + point1Re - point2Im - point3Re) * x3TwRe);

   bflyOut[0] = x0Re;
   bflyOut[1] = x0Im;
   bflyOut[2] = x1Re;
   bflyOut[3] = x1Im;
   bflyOut[4] = x2Re;
   bflyOut[5] = x2Im;
   bflyOut[6] = x3Re;
   bflyOut[7] = x3Im;
}

uint32_t bitr(uint32_t in, uint32_t maxValue)
{
   uint32_t i;
   uint32_t out;
   uint32_t numBits;

   for (i = 31; i > 0U; i--) {
      if (((maxValue >> i) & 1U) != 0U) {
         break;
      }
   }
   numBits = i + 1U;

   out = 0;
   for (i = 0; i < numBits; i++) {
      out |= (((in >> i) & 1U) << (numBits - 1U - i));
   }

   return (out);
}

void ifft_i32fc_o32fc_conjugate_cn(void *pX, uint32_t size)
{

   float   *pXLocal = (float *) pX;
   float   *pX_ptr  = pXLocal;
   uint32_t i       = 0;
   for (i = 1; i < (size << 1); i += 2U) {
      pXLocal[i] = (-1.0f) * pX_ptr[i];
   }
}

void ifft_i32fc_o32fc_scale_cn(void *pX, uint32_t size, uint32_t numPoints)
{

   float   *pXLocal = (float *) pX;
   float   *pX_ptr  = pXLocal;
   uint32_t i       = 0;
   for (i = 0; i < (size << 1); i += 1U) {
      pXLocal[i] = (1.0f / (float) numPoints) * pX_ptr[i];
   }
}

FFTLIB_STATUS
FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_cn(FFTLIB_F32           *pX,
                                          FFTLIB_bufParams1D_t *bufParamsX,
                                          FFTLIB_F32           *pW,
                                          FFTLIB_bufParams1D_t *bufParamsW,
                                          FFTLIB_F32           *pY,
                                          FFTLIB_bufParams1D_t *bufParamsY,
                                          uint32_t              numPoints,
                                          uint32_t              numChannels)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;
   FFTLIB_F32    bflyOut[4 * 2];
   uint32_t      numPointsPerDft;
   uint32_t      dftIndex;
   uint32_t      dftStartOffset;
   uint32_t      dftPointIndex;
   FFTLIB_F32   *pWLocal;
   uint32_t      k, l;

#ifdef FFTLIB_CHECK_PARAMS
   status = FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_checkParams_cn(pX, bufParamsX, pW, bufParamsW, pY, bufParamsY,
                                                                  numPoints, numChannels);

   if (status == FFTLIB_SUCCESS) {
#endif
      numPointsPerDft = numPoints;

      ifft_i32fc_o32fc_conjugate_cn(pX, (numPointsPerDft * numChannels));
      ifft_i32fc_o32fc_scale_cn(pX, (numPointsPerDft * numChannels), numPoints);

      pWLocal = pW;
      while (numPointsPerDft > 2U) {
         for (k = 0; k < (numPoints / 4U); k++) {
            dftIndex       = k / (numPointsPerDft / 4U);
            dftStartOffset = dftIndex * numPointsPerDft;
            dftPointIndex  = k % (numPointsPerDft / 4U);
            for (l = 0; l < numChannels; l++) {
               butterfly4x4(
                   pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex)],
                   pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((2U * dftPointIndex) + 1U)],
                   pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 4U) * 2U) +
                      (2U * dftPointIndex)],
                   pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 4U) * 2U) +
                      ((2U * dftPointIndex) + 1U)],
                   pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 2U) * 2U) +
                      (2U * dftPointIndex)],
                   pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 2U) * 2U) +
                      ((2U * dftPointIndex) + 1U)],
                   pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (3U * (numPointsPerDft / 4U) * 2U) +
                      (2U * dftPointIndex)],
                   pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (3U * (numPointsPerDft / 4U) * 2U) +
                      ((2U * dftPointIndex) + 1U)],
                   pWLocal[dftPointIndex * 2U],                                          /* re of twiddle for x_1 */
                   pWLocal[(dftPointIndex * 2U) + 1U],                                   /* im of twiddle for x_1 */
                   pWLocal[((numPointsPerDft / 4U) * 2U) + (dftPointIndex * 2U)],        /* re of twiddle for x_2 */
                   pWLocal[((numPointsPerDft / 4U) * 2U) + ((dftPointIndex * 2U) + 1U)], /* re of twiddle for x_2 */
                   pWLocal[((numPointsPerDft / 2U) * 2U) + (dftPointIndex * 2U)],        /* re of twiddle for x_2 */
                   pWLocal[((numPointsPerDft / 2U) * 2U) + ((dftPointIndex * 2U) + 1U)], /* re of twiddle for x_2 */
                   bflyOut);

               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex)]        = bflyOut[0];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((2U * dftPointIndex) + 1U)] = bflyOut[1];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 4U) * 2U) +
                  ((2U * dftPointIndex))]                                                     = bflyOut[4];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 4U) * 2U) +
                  ((2U * dftPointIndex) + 1U)]                                                = bflyOut[5];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 2U) * 2U) + (2U * dftPointIndex)] =
                   bflyOut[2];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 2U) * 2U) +
                  ((2U * dftPointIndex) + 1U)] = bflyOut[3];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (3U * (numPointsPerDft / 4U) * 2U) +
                  (2U * dftPointIndex)]        = bflyOut[6];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (3U * (numPointsPerDft / 4U) * 2U) +
                  ((2U * dftPointIndex) + 1U)] = bflyOut[7];
            }
         }
         numPointsPerDft /= 4U;
         pWLocal += (3U * numPointsPerDft * 2U);
      }

      if (numPointsPerDft == 2U) {
         for (k = 0; k < (numPoints / 2U); k++) {
            for (l = 0; l < numChannels; l++) {
               bflyOut[0] =
                   pX[((l * numPoints * 2U) + ((2U * k) * 2U))] + pX[((l * numPoints * 2U) + (((2U * k) + 1U) * 2U))];
               bflyOut[1] = pX[((l * numPoints * 2U) + ((2U * k) * 2U) + 1U)] +
                            pX[((l * numPoints * 2U) + (((2U * k) + 1U) * 2U) + 1U)];
               bflyOut[2] =
                   pX[((l * numPoints * 2U) + ((2U * k) * 2U))] - pX[((l * numPoints * 2U) + (((2U * k) + 1U) * 2U))];
               bflyOut[3] = pX[((l * numPoints * 2U) + ((2U * k) * 2U) + 1U)] -
                            pX[((l * numPoints * 2U) + (((2U * k) + 1U) * 2U) + 1U)];

               pX[((l * numPoints * 2U) + ((2U * k) * 2U))]             = bflyOut[0];
               pX[((l * numPoints * 2U) + ((2U * k) * 2U) + 1U)]        = bflyOut[1];
               pX[((l * numPoints * 2U) + (((2U * k) + 1U) * 2U))]      = bflyOut[2];
               pX[((l * numPoints * 2U) + (((2U * k) + 1U) * 2U) + 1U)] = bflyOut[3];
            }
         }
      }

      /* Do swap of points between bit-reversed locations */
      for (k = 0; k < numPoints; k++) {
         uint32_t kBitr;

         kBitr = bitr(k, numPoints - 1U);
         for (l = 0; l < numChannels; l++) {
            pY[(l * numPoints * 2U) + (2U * k)]      = pX[(l * numPoints * 2U) + (2U * kBitr)];
            pY[(l * numPoints * 2U) + (2U * k) + 1U] = -1.0 * pX[(l * numPoints * 2U) + (2U * kBitr) + 1U];
         }
      }

#ifdef FFTLIB_CHECK_PARAMS
   }
#endif
   return (status);
}

FFTLIB_STATUS FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_checkParams_cn(FFTLIB_F32           *pX,
                                                                    FFTLIB_bufParams1D_t *bufParamsX,
                                                                    FFTLIB_F32           *pW,
                                                                    FFTLIB_bufParams1D_t *bufParamsW,
                                                                    FFTLIB_F32           *pY,
                                                                    FFTLIB_bufParams1D_t *bufParamsY,
                                                                    uint32_t              numPoints,
                                                                    uint32_t              numChannels)
{
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   if ((pX == NULL) || (pW == NULL) || (pY == NULL)) {
      status = FFTLIB_ERR_NULL_POINTER;
   }
   else if (bufParamsX->dim_x != bufParamsY->dim_x) {
      status = FFTLIB_ERR_INVALID_DIMENSION;
   }
   else if (bufParamsX->dim_x < (numPoints * numChannels * 2U)) {
      /* In general, dim_x == numPoints*numChannels*2. However, optimized
       * kernel requires dim_x to be atleast 64*2. Hence, for small values
       * of numPoints*numChannels, dim_x could be greater than
       * numPoints*numChannels*2                                           */
      status = FFTLIB_ERR_INVALID_DIMENSION;
   }
   else if (bufParamsW->dim_x != (numPoints * 2U)) {
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
         if ((numPoints & (1u << k)) != 0u) {
            break;
         }
         k++;
      }
      if ((1u << k) != numPoints) {
         status = FFTLIB_ERR_INVALID_DIMENSION;
      }
   }
   return (status);
}
