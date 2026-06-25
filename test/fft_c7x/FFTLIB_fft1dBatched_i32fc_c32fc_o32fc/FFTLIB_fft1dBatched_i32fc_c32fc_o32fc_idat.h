// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1DBATCHED_I32F_C32FC_O32FC_IDAT_H

#define FFTLIB_FFT1DBATCHED_I32F_C32FC_O32FC_IDAT_H

#include <fftlib.h>

// include test infrastructure provided by FFTLIB
#include "FFTLIB_test.h"

typedef struct {
   uint8_t testPattern; /* 0: constant, 1: sequential, 2: random,
                           3: static array, 4: file, etc           */
   FFTLIB_F32 *staticIn0;
   FFTLIB_F32 *staticOut;
   uint32_t    numChannels;
   uint32_t    numPoints;
   uint32_t    testID;
} fft1dBatched_testParams_t;

void fft1dBatched_getTestParams(fft1dBatched_testParams_t **params, int32_t *numTests);

#endif /* define FFTLIB_FFT1DBATCHEDBATCHED_I32F_C32FC_O32FC_IDAT_H */
