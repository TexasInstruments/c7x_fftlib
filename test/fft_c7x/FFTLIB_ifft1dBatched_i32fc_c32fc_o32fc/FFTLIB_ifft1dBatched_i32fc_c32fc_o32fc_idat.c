// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc_idat.h"

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 201) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
#include "test_data/staticRefCase40.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 201) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
#include "test_data/staticRefCase41.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 201) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
#include "test_data/staticRefCase42.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 201) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
#include "test_data/staticRefCase43.h"
#endif

static ifft1d_testParams_t testParams[] = {

#if !defined(__C7504__) && !defined(__C7524__)
#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        32,            // numChannels
        16,            // numPoints
        1,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        64,            // numChannels
        16,            // numPoints
        2,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        128,           // numChannels
        16,            // numPoints
        3,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        256,           // numChannels
        16,            // numPoints
        4,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        512,           // numChannels
        16,            // numPoints
        5,             // test ID
    },
#endif
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        32,            // numChannels
        32,            // numPoints
        6,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        64,            // numChannels
        32,            // numPoints
        7,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        128,           // numChannels
        32,            // numPoints
        8,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        256,           // numChannels
        32,            // numPoints
        9,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        512,           // numChannels
        32,            // numPoints
        10,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        32,            // numChannels
        64,            // numPoints
        11,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        64,            // numChannels
        64,            // numPoints
        12,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        128,           // numChannels
        64,            // numPoints
        13,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        256,           // numChannels
        64,            // numPoints
        14,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        16,            // numChannels
        128,           // numPoints
        15,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        32,            // numChannels
        128,           // numPoints
        16,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        64,            // numChannels
        128,           // numPoints
        17,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        128,           // numChannels
        128,           // numPoints
        18,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        8,             // numChannels
        256,           // numPoints
        19,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        16,            // numChannels
        256,           // numPoints
        20,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        32,            // numChannels
        256,           // numPoints
        21,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        64,            // numChannels
        256,           // numPoints
        22,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        4,             // numChannels
        512,           // numPoints
        23,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        8,             // numChannels
        512,           // numPoints
        24,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        16,            // numChannels
        512,           // numPoints
        25,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        32,            // numChannels
        512,           // numPoints
        26,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        2,             // numChannels
        1024,          // numPoints
        27,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        4,             // numChannels
        1024,          // numPoints
        28,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        8,             // numChannels
        1024,          // numPoints
        29,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        16,            // numChannels
        1024,          // numPoints
        30,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        1,             // numChannels
        2048,          // numPoints
        31,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        2,             // numChannels
        2048,          // numPoints
        32,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        4,             // numChannels
        2048,          // numPoints
        33,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        8,             // numChannels
        2048,          // numPoints
        34,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        1,             // numChannels
        4096,          // numPoints
        35,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        2,             // numChannels
        4096,          // numPoints
        36,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        4,             // numChannels
        4096,          // numPoints
        37,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        1,             // numChannels
        8192,          // numPoints
        38,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        NULL,          // randomOut
        2,             // numChannels
        8192,          // numPoints
        39,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        STATIC,         // test pattern
        staticRefIn40,  // staticIn
        staticRefOut40, // staticOut
        1,              // numChannels
        128,            // numPoints
        40,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
    {
        STATIC,         // test pattern
        staticRefIn41,  // staticIn
        staticRefOut41, // staticOut
        2,              // numChannels
        256,            // numPoints
        41,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
    {
        STATIC,         // test pattern
        staticRefIn42,  // staticIn
        staticRefOut42, // staticOut
        4,              // numChannels
        512,            // numPoints
        42,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
    {
        STATIC,         // test pattern
        staticRefIn43,  // staticIn
        staticRefOut43, // staticOut
        8,              // numChannels
        1024,           // numPoints
        43,             // test ID
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void ifft1d_getTestParams(ifft1d_testParams_t** params, int32_t* numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(ifft1d_testParams_t);
}
