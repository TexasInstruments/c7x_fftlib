// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_utility.h"

/**************************************************************************************
 * Circular Buffer Table
 **************************************************************************************/
// int32_t circularBlockSizeTbl[FFTLIB_CIRBUFCOUNT] =

int32_t circularBlockSizeTbl[11] = {512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
