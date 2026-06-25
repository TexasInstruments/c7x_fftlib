// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1DBATCHED_I16SC_C16SC_O16SC_IDAT_H

#define FFTLIB_FFT1DBATCHED_I16SC_C16SC_O16SC_IDAT_H

/* #include "../../common/FFTLIB_types.h" */
#include "FFTLIB_test.h"

typedef struct {
   uint8_t testPattern; /* 0: constant, 1: sequential, 2: random, 3: static
                           array, 4: file, etc */
   int16_t  *staticIn0;
   uint32_t *shiftVector;
   int16_t  *staticOut;
   uint32_t  numShifts;
   uint32_t  numChannels;
   uint32_t  numPoints;
   uint32_t  testID;
} fft1dBatched_i16sc_c16sc_o16sc_testParams_t;

void fft1dBatched_i16sc_c16sc_o16sc_getTestParams(fft1dBatched_i16sc_c16sc_o16sc_testParams_t **params,
                                                  int32_t                                      *numTests);

#endif /* define FFTLIB_FFT1DBATCHED_I16SC_C16SC_O16SC_IDAT_H */
