// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_fft1d_i16sc_c16sc_o16sc_idat.h"
#include <stdint.h>

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
#include "test_data/staticRefCase1.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
#include "test_data/staticRefCase2.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
#include "test_data/staticRefCase3.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
#include "test_data/staticRefCase4.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
#include "test_data/staticRefCase5.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
#include "test_data/staticRefCase6.h"
#endif

/* ===== Shift Vectors ===== */
__attribute__((section(".staticData"))) static uint32_t shiftVector1[] = {0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector2[] = {0, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector3[] = {0, 1, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector4[] = {0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector5[] = {0, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector6[] = {0, 1, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector7[] = {0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector8[] = {1, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector9[] = {1, 0, 0, 0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector10[] = {0, 1, 0, 1, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector11[] = {1, 0, 1, 0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector12[] = {1, 1, 1, 0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector13[] = {1, 0, 1, 1, 1, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector14[] = {0, 0, 0, 1, 0, 1, 1};

static fft1d_i16sc_c16sc_o16sc_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        STATIC,        // test pattern
        staticRefIn1,  // staticIn
        shiftVector1,  // shiftVector
        staticRefOut1, // staticOut
        3,             // numShifts
        64,            // numPoints
        1,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        STATIC,        // test pattern
        staticRefIn2,  // staticIn
        shiftVector2,  // shiftVector
        staticRefOut2, // staticOut
        4,             // numShifts
        256,           // numPoints
        2,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        STATIC,        // test pattern
        staticRefIn3,  // staticIn
        shiftVector3,  // shiftVector
        staticRefOut3, // staticOut
        5,             // numShifts
        1024,          // numPoints
        3,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        STATIC,        // test pattern
        staticRefIn4,  // staticIn
        shiftVector4,  // shiftVector
        staticRefOut4, // staticOut
        3,             // numShifts
        128,           // numPoints
        4,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        STATIC,        // test pattern
        staticRefIn5,  // staticIn
        shiftVector5,  // shiftVector
        staticRefOut5, // staticOut
        4,             // numShifts
        512,           // numPoints
        5,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        STATIC,        // test pattern
        staticRefIn6,  // staticIn
        shiftVector6,  // shiftVector
        staticRefOut6, // staticOut
        5,             // numShifts
        2048,          // numPoints
        6,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        RANDOM,       // test pattern
        NULL,         // randomIn
        shiftVector7, // shiftVector
        NULL,         // randomOut
        3,            // numShifts
        64,           // numPoints
        7,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        RANDOM,       // test pattern
        NULL,         // randomIn
        shiftVector8, // shiftVector
        NULL,         // randomOut
        4,            // numShifts
        256,          // numPoints
        8,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        RANDOM,       // test pattern
        NULL,         // randomIn
        shiftVector9, // shiftVector
        NULL,         // randomOut
        6,            // numShifts
        4096,         // numPoints
        9,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        RANDOM,        // test pattern
        NULL,          // randomIn
        shiftVector10, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        4096,          // numPoints
        10,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        RANDOM,        // test pattern
        NULL,          // randomIn
        shiftVector11, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        8192,          // numPoints
        11,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        RANDOM,        // test pattern
        NULL,          // randomIn
        shiftVector12, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        8192,          // numPoints
        12,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        RANDOM,        // test pattern
        NULL,          // randomIn
        shiftVector13, // shiftVector
        NULL,          // randomOut
        7,             // numShifts
        16384,         // numPoints
        13,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        RANDOM,        // test pattern
        NULL,          // randomIn
        shiftVector14, // shiftVector
        NULL,          // randomOut
        7,             // numShifts
        16384,         // numPoints
        14,            // test ID
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void fft1d_i16sc_c16sc_o16sc_getTestParams(fft1d_i16sc_c16sc_o16sc_testParams_t** params, int32_t* numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(fft1d_i16sc_c16sc_o16sc_testParams_t);
}
