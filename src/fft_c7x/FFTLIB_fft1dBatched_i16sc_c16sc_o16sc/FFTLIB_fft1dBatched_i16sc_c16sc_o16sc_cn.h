// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1DBATCHED_I16SC_C16SC_O16SC_CN_H_
#define FFTLIB_FFT1DBATCHED_I16SC_C16SC_O16SC_CN_H_ 1

#include "../../common/FFTLIB_types.h"

FFTLIB_STATUS
FFTLIB_fft1dBatched_i16sc_c16sc_o16sc_cn(int16_t              *pX,
                                         FFTLIB_bufParams1D_t *bufParamsX,
                                         int16_t              *pW,
                                         FFTLIB_bufParams1D_t *bufParamsW,
                                         int16_t              *pY,
                                         FFTLIB_bufParams1D_t *bufParamsY,
                                         uint32_t             *pShift,
                                         FFTLIB_bufParams1D_t *bufParamsShift,
                                         uint32_t              numPoints,
                                         uint32_t              numChannels);

FFTLIB_STATUS FFTLIB_fft1dBatched_i16sc_c16sc_o16sc_checkParams_cn(int16_t              *pX,
                                                                   FFTLIB_bufParams1D_t *bufParamsX,
                                                                   int16_t              *pW,
                                                                   FFTLIB_bufParams1D_t *bufParamsW,
                                                                   int16_t              *pY,
                                                                   FFTLIB_bufParams1D_t *bufParamsY,
                                                                   uint32_t             *pShift,
                                                                   FFTLIB_bufParams1D_t *bufParamsShift,
                                                                   uint32_t              numPoints,
                                                                   uint32_t              numChannels);

uint32_t bitr(uint32_t in, uint32_t maxValue);

void butterfly(int16_t  point0Re,
               int16_t  point0Im,
               int16_t  point1Re,
               int16_t  point1Im,
               int16_t  point2Re,
               int16_t  point2Im,
               int16_t  point3Re,
               int16_t  point3Im,
               int16_t  x1TwRe,
               int16_t  x1TwIm,
               int16_t  x2TwRe,
               int16_t  x2TwIm,
               int16_t  x3TwRe,
               int16_t  x3TwIm,
               int16_t *bflyOut);

void butterflyNoTw(int16_t  point0Re,
                   int16_t  point0Im,
                   int16_t  point1Re,
                   int16_t  point1Im,
                   int16_t  point2Re,
                   int16_t  point2Im,
                   int16_t  point3Re,
                   int16_t  point3Im,
                   int16_t *bflyOut);

int16_t crot90HIm(int16_t re, int16_t im);

int16_t crot90HRe(int16_t re, int16_t im);

static int16_t satAndScale(int64_t x);

void shiftRightAndRound(int16_t *pBuff, uint32_t numElements, uint32_t shift);
#endif /* FFTLIB_FFT1DBATCHED_I16SC_C16SC_O16SC_CN_H_ */
