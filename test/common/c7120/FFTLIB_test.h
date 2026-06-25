// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef C7120_FFTLIB_TEST_H_
#define C7120_FFTLIB_TEST_H_ 1

// FFTLIB_TEST_compareDynamicRange uses some natural-c utilities from FFTLIB
#include "../src/common/FFTLIB_utility.h"

/*******************************************************************************
 *
 * External variables
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Inline functions
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * C++ function prototypes
 *
 ******************************************************************************/
#ifdef __cplusplus
// functions only implemented in C++.  Could potentially develop a wrapper for C
// linkage if necessary

#endif //__cplusplus

/*******************************************************************************
 *
 * C function prototypes
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

uint8_t FFTLIB_TEST_compareDynamicRange(void    *dynamicRangeRef,
                                        int64_t  dynamicRangeComputed,
                                        uint32_t outputType,
                                        uint8_t  shift,
                                        uint8_t  activationType);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* C7120_FFTLIB_TEST_H_ */
