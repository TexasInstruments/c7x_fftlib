// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef TEST_FFTLIB_TEST_H_
#define TEST_FFTLIB_TEST_H_ 1

#include "TI_memory.h"
#include "TI_profile.h"
#include "TI_test.h"

#if defined(__C7100__) || defined(__C7120__) || defined(__C7502__) || defined(__C7504__) || defined(__C7508__) ||      \
    defined(__C7524__)
#include "c71/FFTLIB_test.h"
#else
#error invalid target
#endif

// TBD: How to handle when __C7100__ is defined?
#if defined(__C7120__)
#include "c7120/FFTLIB_test.h"
/* #else
 * #error invalid target */
#endif

#if defined(__C7504__)
#include "c7504/FFTLIB_test.h"
/* #else
 * #error invalid target */
#endif

#endif /* TEST_FFTLIB_TEST_H_ */
