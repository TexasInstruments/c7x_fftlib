// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_IFFT1DBATCHED_I32FC_C32FC_O32FC_CN_H_
#define FFTLIB_IFFT1DBATCHED_I32FC_C32FC_O32FC_CN_H_ 1

#include "../../common/FFTLIB_types.h"

FFTLIB_STATUS
FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_cn(FFTLIB_F32           *pX,
                                          FFTLIB_bufParams1D_t *bufParamsX,
                                          FFTLIB_F32           *pW,
                                          FFTLIB_bufParams1D_t *bufParamsW,
                                          FFTLIB_F32           *pY,
                                          FFTLIB_bufParams1D_t *bufParamsY,
                                          uint32_t              numPoints,
                                          uint32_t              numChannels);

FFTLIB_STATUS FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_checkParams_cn(FFTLIB_F32           *pX,
                                                                    FFTLIB_bufParams1D_t *bufParamsX,
                                                                    FFTLIB_F32           *pW,
                                                                    FFTLIB_bufParams1D_t *bufParamsW,
                                                                    FFTLIB_F32           *pY,
                                                                    FFTLIB_bufParams1D_t *bufParamsY,
                                                                    uint32_t              numPoints,
                                                                    uint32_t              numChannels);

uint32_t bitr(uint32_t in, uint32_t maxValue);

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
                  FFTLIB_F32 *bflyOut);

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
                  FFTLIB_F32 *bflyOut);

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
                  FFTLIB_F32 *bflyOut);

void ifft_i32fc_o32fc_conjugate_cn(void *pX, uint32_t size);

void ifft_i32fc_o32fc_scale_cn(void *pX, uint32_t size, uint32_t numPoints);

#endif
