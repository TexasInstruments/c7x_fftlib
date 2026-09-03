// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_cn.h"

/* CODE_SECTION (FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_cn, ".text:ansi") */
/* CODE_SECTION (FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_checkParams_cn, */
/*               ".text:ansi") */

/*DFT twiddles */
#define COS_TWO_PI_DIV_3    0.5f      /* cos(2π/3) */                            
#define SIN_TWO_PI_DIV_3    0.86602540378443871f /* sin(2π/3) */                                                                  
#define COS_TWO_PI_DIV_5    0.30901699437494745f /* cos(2π/5) */                                                                  
#define SIN_TWO_PI_DIV_5    0.95105651629515353f /* sin(2π/5) */                                                                  
#define COS_FOUR_PI_DIV_5   0.80901699437494734f /* cos(4π/5) */                                                                 
#define SIN_FOUR_PI_DIV_5   0.58778525229247325f /* sin(4π/5) */ 

void butterfly5x5(FFTLIB_F32  x0_inRe,
                  FFTLIB_F32  x0_inIm,
                  FFTLIB_F32  x1_inRe,
                  FFTLIB_F32  x1_inIm,
                  FFTLIB_F32  x2_inRe,
                  FFTLIB_F32  x2_inIm,
                  FFTLIB_F32  x3_inRe,
                  FFTLIB_F32  x3_inIm,
                  FFTLIB_F32  x4_inRe,
                  FFTLIB_F32  x4_inIm,
                  FFTLIB_F32  w1Re,
                  FFTLIB_F32  w1Im,
                  FFTLIB_F32  w2Re,
                  FFTLIB_F32  w2Im,
                  FFTLIB_F32  w3Re,
                  FFTLIB_F32  w3Im,
                  FFTLIB_F32  w4Re,
                  FFTLIB_F32  w4Im,
                  FFTLIB_F32 *bflyOut)
{
   FFTLIB_F32 XbaseRe[5], XbaseIm[5];

   XbaseRe[0] = x0_inRe + x1_inRe + x2_inRe + x3_inRe + x4_inRe;
   XbaseIm[0] = x0_inIm + x1_inIm + x2_inIm + x3_inIm + x4_inIm;

   XbaseRe[1] = x0_inRe
              + x1_inRe *  COS_TWO_PI_DIV_5 + x1_inIm *  SIN_TWO_PI_DIV_5
              + x2_inRe * -COS_FOUR_PI_DIV_5 + x2_inIm *  SIN_FOUR_PI_DIV_5
              + x3_inRe * -COS_FOUR_PI_DIV_5 + x3_inIm * -SIN_FOUR_PI_DIV_5
              + x4_inRe *  COS_TWO_PI_DIV_5 + x4_inIm * -SIN_TWO_PI_DIV_5;
   XbaseIm[1] = x0_inIm
              + x1_inRe * -SIN_TWO_PI_DIV_5 + x1_inIm *  COS_TWO_PI_DIV_5
              + x2_inRe * -SIN_FOUR_PI_DIV_5 + x2_inIm * -COS_FOUR_PI_DIV_5
              + x3_inRe *  SIN_FOUR_PI_DIV_5 + x3_inIm * -COS_FOUR_PI_DIV_5
              + x4_inRe *  SIN_TWO_PI_DIV_5 + x4_inIm *  COS_TWO_PI_DIV_5;

   XbaseRe[2] = x0_inRe
              + x1_inRe * -COS_FOUR_PI_DIV_5 + x1_inIm *  SIN_FOUR_PI_DIV_5
              + x2_inRe *  COS_TWO_PI_DIV_5 + x2_inIm * -SIN_TWO_PI_DIV_5
              + x3_inRe *  COS_TWO_PI_DIV_5 + x3_inIm *  SIN_TWO_PI_DIV_5
              + x4_inRe * -COS_FOUR_PI_DIV_5 + x4_inIm * -SIN_FOUR_PI_DIV_5;
   XbaseIm[2] = x0_inIm
              + x1_inRe * -SIN_FOUR_PI_DIV_5 + x1_inIm * -COS_FOUR_PI_DIV_5
              + x2_inRe *  SIN_TWO_PI_DIV_5 + x2_inIm *  COS_TWO_PI_DIV_5
              + x3_inRe * -SIN_TWO_PI_DIV_5 + x3_inIm *  COS_TWO_PI_DIV_5
              + x4_inRe *  SIN_FOUR_PI_DIV_5 + x4_inIm * -COS_FOUR_PI_DIV_5;

   XbaseRe[3] = x0_inRe
              + x1_inRe * -COS_FOUR_PI_DIV_5 + x1_inIm * -SIN_FOUR_PI_DIV_5
              + x2_inRe *  COS_TWO_PI_DIV_5 + x2_inIm *  SIN_TWO_PI_DIV_5
              + x3_inRe *  COS_TWO_PI_DIV_5 + x3_inIm * -SIN_TWO_PI_DIV_5
              + x4_inRe * -COS_FOUR_PI_DIV_5 + x4_inIm *  SIN_FOUR_PI_DIV_5;
   XbaseIm[3] = x0_inIm
              + x1_inRe *  SIN_FOUR_PI_DIV_5 + x1_inIm * -COS_FOUR_PI_DIV_5
              + x2_inRe * -SIN_TWO_PI_DIV_5 + x2_inIm *  COS_TWO_PI_DIV_5
              + x3_inRe *  SIN_TWO_PI_DIV_5 + x3_inIm *  COS_TWO_PI_DIV_5
              + x4_inRe * -SIN_FOUR_PI_DIV_5 + x4_inIm * -COS_FOUR_PI_DIV_5;

   XbaseRe[4] = x0_inRe
              + x1_inRe *  COS_TWO_PI_DIV_5 + x1_inIm * -SIN_TWO_PI_DIV_5
              + x2_inRe * -COS_FOUR_PI_DIV_5 + x2_inIm * -SIN_FOUR_PI_DIV_5
              + x3_inRe * -COS_FOUR_PI_DIV_5 + x3_inIm *  SIN_FOUR_PI_DIV_5
              + x4_inRe *  COS_TWO_PI_DIV_5 + x4_inIm *  SIN_TWO_PI_DIV_5;
   XbaseIm[4] = x0_inIm
              + x1_inRe *  SIN_TWO_PI_DIV_5 + x1_inIm *  COS_TWO_PI_DIV_5
              + x2_inRe *  SIN_FOUR_PI_DIV_5 + x2_inIm * -COS_FOUR_PI_DIV_5
              + x3_inRe * -SIN_FOUR_PI_DIV_5 + x3_inIm * -COS_FOUR_PI_DIV_5
              + x4_inRe * -SIN_TWO_PI_DIV_5 + x4_inIm *  COS_TWO_PI_DIV_5;

   bflyOut[0] = XbaseRe[0];
   bflyOut[1] = XbaseIm[0];
   bflyOut[2] = XbaseRe[1] * w1Re - XbaseIm[1] * w1Im;
   bflyOut[3] = XbaseRe[1] * w1Im + XbaseIm[1] * w1Re;
   bflyOut[4] = XbaseRe[2] * w2Re - XbaseIm[2] * w2Im;
   bflyOut[5] = XbaseRe[2] * w2Im + XbaseIm[2] * w2Re;
   bflyOut[6] = XbaseRe[3] * w3Re - XbaseIm[3] * w3Im;
   bflyOut[7] = XbaseRe[3] * w3Im + XbaseIm[3] * w3Re;
   bflyOut[8] = XbaseRe[4] * w4Re - XbaseIm[4] * w4Im;
   bflyOut[9] = XbaseRe[4] * w4Im + XbaseIm[4] * w4Re;
}

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

void butterfly3x3(FFTLIB_F32  x0_inRe,
                  FFTLIB_F32  x0_inIm,
                  FFTLIB_F32  x1_inRe,
                  FFTLIB_F32  x1_inIm,
                  FFTLIB_F32  x2_inRe,
                  FFTLIB_F32  x2_inIm,
                  FFTLIB_F32  w1Re,
                  FFTLIB_F32  w1Im,
                  FFTLIB_F32  w2Re,
                  FFTLIB_F32  w2Im,
                  FFTLIB_F32 *bflyOut)
{
   FFTLIB_F32 XbaseRe[3], XbaseIm[3];

   XbaseRe[0] = x0_inRe + x1_inRe + x2_inRe;
   XbaseIm[0] = x0_inIm + x1_inIm + x2_inIm;

   XbaseRe[1] = x0_inRe - x1_inRe * COS_TWO_PI_DIV_3 + x1_inIm * SIN_TWO_PI_DIV_3 - x2_inRe * COS_TWO_PI_DIV_3 - x2_inIm * SIN_TWO_PI_DIV_3;
   XbaseIm[1] = x0_inIm - x1_inRe * SIN_TWO_PI_DIV_3 - x1_inIm * COS_TWO_PI_DIV_3 + x2_inRe * SIN_TWO_PI_DIV_3 - x2_inIm * COS_TWO_PI_DIV_3;

   XbaseRe[2] = x0_inRe - x1_inRe * COS_TWO_PI_DIV_3 - x1_inIm * SIN_TWO_PI_DIV_3 - x2_inRe * COS_TWO_PI_DIV_3 + x2_inIm * SIN_TWO_PI_DIV_3;
   XbaseIm[2] = x0_inIm + x1_inRe * SIN_TWO_PI_DIV_3 - x1_inIm * COS_TWO_PI_DIV_3 - x2_inRe * SIN_TWO_PI_DIV_3 - x2_inIm * COS_TWO_PI_DIV_3;

   bflyOut[0] = XbaseRe[0];
   bflyOut[1] = XbaseIm[0];
   bflyOut[2] = XbaseRe[1] * w1Re - XbaseIm[1] * w1Im;
   bflyOut[3] = XbaseRe[1] * w1Im + XbaseIm[1] * w1Re;
   bflyOut[4] = XbaseRe[2] * w2Re - XbaseIm[2] * w2Im;
   bflyOut[5] = XbaseRe[2] * w2Im + XbaseIm[2] * w2Re;
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
   FFTLIB_F32    bflyOut[5 * 2];
   uint32_t      numPointsPerDft;
   uint32_t      dftIndex;
   uint32_t      dftStartOffset;
   uint32_t      dftPointIndex;
   FFTLIB_F32   *pWLocal;
   uint32_t      k, l;
   uint32_t      r5, r3, r4, r2;
   uint32_t      numRadix5Stages = 0;
   uint32_t      numRadix3Stages = 0;
   uint32_t      numRadix4Stages = 0;
   uint32_t      numRadix2Stages = 0;
   uint32_t      stageTemp       = numPoints;

#ifdef FFTLIB_CHECK_PARAMS
   status = FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_checkParams_cn(pX, bufParamsX, pW, bufParamsW, pY, bufParamsY,
                                                                  numPoints, numChannels);

   if (status == FFTLIB_SUCCESS) {
#endif
      numPointsPerDft = numPoints;

      ifft_i32fc_o32fc_conjugate_cn(pX, (numPointsPerDft * numChannels));
      ifft_i32fc_o32fc_scale_cn(pX, (numPointsPerDft * numChannels), numPoints);

      /* Calculate IFFT stages decomposition */
      while (stageTemp > 1U) {
         if (stageTemp % 5U == 0U) { numRadix5Stages++; stageTemp /= 5U; }
         else if (stageTemp % 3U == 0U) { numRadix3Stages++; stageTemp /= 3U; }
         else if (stageTemp % 4U == 0U) { numRadix4Stages++; stageTemp /= 4U; }
         else if (stageTemp % 2U == 0U) { numRadix2Stages++; stageTemp /= 2U; }
         else { break; }
      }

      pWLocal = pW;

      /* Execute Radix-5 stages */
      for (r5 = 0; r5 < numRadix5Stages; r5++) {
         for (k = 0; k < (numPoints / 5U); k++) {
            dftIndex       = k / (numPointsPerDft / 5U);
            dftStartOffset = dftIndex * numPointsPerDft;
            dftPointIndex  = k % (numPointsPerDft / 5U);
            for (l = 0; l < numChannels; l++) {
               butterfly5x5(
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex)],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex) + 1U],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex)],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex) + 1U],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex)],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex) + 1U],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (3U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex)],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (3U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex) + 1U],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (4U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex)],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (4U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex) + 1U],
                     pWLocal[dftPointIndex * 2U],
                     pWLocal[(dftPointIndex * 2) + 1U],
                     pWLocal[((numPointsPerDft / 5U) * 2U) + (dftPointIndex * 2U)],
                     pWLocal[((numPointsPerDft / 5U) * 2U) + (dftPointIndex * 2) + 1U],
                     pWLocal[(2U * (numPointsPerDft / 5U) * 2U) + (dftPointIndex * 2U)],
                     pWLocal[(2U * (numPointsPerDft / 5U) * 2U) + (dftPointIndex * 2) + 1U],
                     pWLocal[(3U * (numPointsPerDft / 5U) * 2U) + (dftPointIndex * 2U)],
                     pWLocal[(3U * (numPointsPerDft / 5U) * 2U) + (dftPointIndex * 2) + 1U],
                     bflyOut);

               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex)]     = bflyOut[0];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex) + 1U] = bflyOut[1];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex)]     = bflyOut[2];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex) + 1U] = bflyOut[3];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex)]     = bflyOut[4];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex) + 1U] = bflyOut[5];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (3U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex)]     = bflyOut[6];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (3U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex) + 1U] = bflyOut[7];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (4U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex)]     = bflyOut[8];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (4U * (numPointsPerDft / 5U) * 2U) + (2U * dftPointIndex) + 1U] = bflyOut[9];
            }
         }
         numPointsPerDft /= 5U;
         pWLocal += 4U * numPointsPerDft * 2U;
      }

      /* Execute Radix-3 stages */
      for (r3 = 0; r3 < numRadix3Stages; r3++) {
         for (k = 0; k < (numPoints / 3U); k++) {
            dftIndex       = k / (numPointsPerDft / 3U);
            dftStartOffset = dftIndex * numPointsPerDft;
            dftPointIndex  = k % (numPointsPerDft / 3U);

            for (l = 0; l < numChannels; l++) {
               butterfly3x3(
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex)],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex) + 1U],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 3U) * 2U) + (2U * dftPointIndex)],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 3U) * 2U) + (2U * dftPointIndex) + 1U],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * (numPointsPerDft / 3U) * 2U) + (2U * dftPointIndex)],
                     pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * (numPointsPerDft / 3U) * 2U) + (2U * dftPointIndex) + 1U],
                     pWLocal[dftPointIndex * 2U],
                     pWLocal[(dftPointIndex * 2) + 1U],
                     pWLocal[((numPointsPerDft / 3U) * 2U) + (dftPointIndex * 2U)],
                     pWLocal[((numPointsPerDft / 3U) * 2U) + (dftPointIndex * 2) + 1U],
                     bflyOut);

               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex)]     = bflyOut[0];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * dftPointIndex) + 1U] = bflyOut[1];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 3U) * 2U) + (2U * dftPointIndex)]     = bflyOut[2];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + ((numPointsPerDft / 3U) * 2U) + (2U * dftPointIndex) + 1U] = bflyOut[3];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * (numPointsPerDft / 3U) * 2U) + (2U * dftPointIndex)]     = bflyOut[4];
               pX[(l * numPoints * 2U) + (dftStartOffset * 2U) + (2U * (numPointsPerDft / 3U) * 2U) + (2U * dftPointIndex) + 1U] = bflyOut[5];
            }
         }
         numPointsPerDft /= 3U;
         pWLocal += 2U * numPointsPerDft * 2U;
      }

      /* Execute Radix-4 stages */
      for (r4 = 0; r4 < numRadix4Stages; r4++) {
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
         pWLocal += 3U * numPointsPerDft * 2U;
      }

      /* Execute Radix-2 stages */
      for (r2 = 0; r2 < numRadix2Stages; r2++) {
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
         numPointsPerDft /= 2U;
      }
      /* Do swap of points between bit-reversed locations */
      /* check if the numPoints is only power of 2 */
      uint32_t isPowerOf2 = (numRadix3Stages == 0 && numRadix5Stages == 0) ? 1 : 0;

      if (isPowerOf2) 
      {
         /* use bit-reversal with IFFT scaling and conjugation */
         for (k = 0; k < numPoints; k++) 
         {
            uint32_t kBitr;

            kBitr = bitr(k, numPoints - 1U);

            for (l = 0; l < numChannels; l++) 
            {
               pY[(l * numPoints * 2U) + (2U * k)]     = pX[(l * numPoints * 2U) + (2U * kBitr)];
               pY[(l * numPoints * 2U) + (2U * k) + 1U] = -1.0 * pX[(l * numPoints * 2U) + (2U * kBitr) + 1U];
            }
         }
      }
      else
      {
         /* use digit-reversal with IFFT scaling and conjugation*/
         uint32_t radixSeq[32], numRadixStages = 0U;
         uint32_t tempCheck = numPoints;

         /* Radix-5 */
         while (tempCheck % 5U == 0U) 
         {
            radixSeq[numRadixStages++] = 5U; 
            tempCheck /= 5U; 
         }
         /* Radix-3 */
         while (tempCheck % 3U == 0U) 
         { 
            radixSeq[numRadixStages++] = 3U;
            tempCheck /= 3U; 
         }
         /* Radix-4 */
         while (tempCheck % 4U == 0U) 
         {
            radixSeq[numRadixStages++] = 2U;
            radixSeq[numRadixStages++] = 2U;
            tempCheck /= 4U;
         }
         /* Radix-2 */
         if (tempCheck == 2U) 
         {
            radixSeq[numRadixStages++] = 2U;
            tempCheck /= 2U;
         }

         /* Apply mixed-radix digit-reversal permutation */
         for (k = 0U; k < numPoints; k++) 
         {
            /* Extract digits of k in the radix sequence */
            uint32_t kTemp = k;
            uint32_t digits[32];
            uint32_t s;

            for (s = 0U; s < numRadixStages; s++) 
            {
               digits[s] = kTemp % radixSeq[s];
               kTemp /= radixSeq[s];
            }

            /* Recompose in reversed stage order */
            uint32_t kBitr = 0U;
            uint32_t mult = 1U;
            int32_t sRev;

            for (sRev = numRadixStages - 1; sRev >= 0; sRev--) 
            {
               kBitr += digits[sRev] * mult;
               mult *= radixSeq[sRev];
            }

            /* Copy from reversed input position to natural output position */
            for (l = 0; l < numChannels; l++) {
               pY[(l * numPoints * 2U) + (2U * k)] = pX[(l * numPoints * 2U) + (2U * kBitr)];
               pY[(l * numPoints * 2U) + (2U * k) + 1U] = -1.0f * (pX[(l * numPoints * 2U) + (2U * kBitr) + 1U]);
            }
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
   else if (bufParamsW->dim_x != (numPoints * 2U)) {
      status = FFTLIB_ERR_INVALID_DIMENSION;
   }
   else if ((bufParamsX->data_type != (uint32_t) FFTLIB_FLOAT32) ||
            (bufParamsW->data_type != (uint32_t) FFTLIB_FLOAT32) ||
            (bufParamsY->data_type != (uint32_t) FFTLIB_FLOAT32)) {
      status = FFTLIB_ERR_INVALID_TYPE;
   }
   else {
      uint32_t temp = numPoints;
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
         status = FFTLIB_ERR_NOT_IMPLEMENTED;
      }
   }
   return (status);
}
