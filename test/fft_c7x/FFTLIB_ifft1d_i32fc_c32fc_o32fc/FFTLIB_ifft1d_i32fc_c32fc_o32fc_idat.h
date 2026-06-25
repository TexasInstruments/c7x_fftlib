// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1D_I32FC_C32FC_O32FC_IDAT_H

#define FFTLIB_FFT1D_I32FC_C32FC_O32FC_IDAT_H

#include "FFTLIB_test.h"

typedef struct {
   uint8_t testPattern; /* 0: constant, 1: sequential, 2: random,
                           3: static array, 4: file, etc           */
   FFTLIB_F32 *staticIn0;
   FFTLIB_F32 *staticOut;
   uint32_t    numPoints;
   uint32_t    testID;
} ifft1d_i32fc_c32fc_o32fc_testParams_t;

void ifft1d_i32fc_c32fc_o32fc_getTestParams(ifft1d_i32fc_c32fc_o32fc_testParams_t **params, int32_t *numTests);

#endif /* define FFTLIB_FFT1D_I32FC_C32FC_O32FC_IDAT_H */
