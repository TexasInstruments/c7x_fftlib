// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_fft1dBatched_i32f_c32fc_o32fc_idat.h"

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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
#include "test_data/staticRefCase7.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
#include "test_data/staticRefCase8.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
#include "test_data/staticRefCase9.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
#include "test_data/staticRefCase10.h"
#endif

static fft1dBatched_i32f_c32fc_o32fc_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        STATIC,        // test pattern
        staticRefIn1,  // staticIn
        staticRefOut1, // staticOut
        64,            // numPoints
        1,             // numChannels
        1,             // outmode
        1,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        STATIC,        // test pattern
        staticRefIn2,  // staticIn
        staticRefOut2, // staticOut
        128,           // numPoints
        2,             // numChannels
        1,             // outmode
        2,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        STATIC,        // test pattern
        staticRefIn3,  // staticIn
        staticRefOut3, // staticOut
        256,           // numPoints
        4,             // numChannels
        1,             // outmode
        3,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        STATIC,        // test pattern
        staticRefIn4,  // staticIn
        staticRefOut4, // staticOut
        512,           // numPoints
        8,             // numChannels
        1,             // outmode
        4,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        STATIC,        // test pattern
        staticRefIn5,  // staticIn
        staticRefOut5, // staticOut
        1024,          // numPoints
        4,             // numChannels
        1,             // outmode
        5,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        STATIC,        // test pattern
        staticRefIn6,  // staticIn
        staticRefOut6, // staticOut
        64,            // numPoints
        1,             // numChannels
        0,             // outmode
        6,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        STATIC,        // test pattern
        staticRefIn7,  // staticIn
        staticRefOut7, // staticOut
        128,           // numPoints
        2,             // numChannels
        0,             // outmode
        7,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        STATIC,        // test pattern
        staticRefIn8,  // staticIn
        staticRefOut8, // staticOut
        256,           // numPoints
        4,             // numChannels
        0,             // outmode
        8,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        STATIC,        // test pattern
        staticRefIn9,  // staticIn
        staticRefOut9, // staticOut
        512,           // numPoints
        8,             // numChannels
        0,             // outmode
        9,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        STATIC,         // test pattern
        staticRefIn10,  // staticIn
        staticRefOut10, // staticOut
        1024,           // numPoints
        4,              // numChannels
        0,              // outmode
        10,             // test ID
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void fft1dBatched_i32f_c32fc_o32fc_getTestParams(fft1dBatched_i32f_c32fc_o32fc_testParams_t** params, int32_t* numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(fft1dBatched_i32f_c32fc_o32fc_testParams_t);
}
