// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef C71_FFTLIB_UTILITY_H_
#define C71_FFTLIB_UTILITY_H_ 1

#include "../FFTLIB_types.h"

/*******************************************************************************
 *
 * EXTERNAL VARIABLES
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Inline functions
 *
 ******************************************************************************/

/**************************************************************************************
 *
 * Circular Buffer Table
 *
 **************************************************************************************/
#define FFTLIB_CIRBUFCOUNT 11
extern int32_t circularBlockSizeTbl[FFTLIB_CIRBUFCOUNT];

#endif /* C71_FFTLIB_UTILITY_H_ */
