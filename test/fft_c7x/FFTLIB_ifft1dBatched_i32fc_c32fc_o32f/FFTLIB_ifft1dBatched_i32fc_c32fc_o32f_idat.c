// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_idat.h"

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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
#include "test_data/staticRefCase11.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
#include "test_data/staticRefCase12.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
#include "test_data/staticRefCase13.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
#include "test_data/staticRefCase14.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
#include "test_data/staticRefCase15.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
#include "test_data/staticRefCase16.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
#include "test_data/staticRefCase17.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
#include "test_data/staticRefCase18.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
#include "test_data/staticRefCase19.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
#include "test_data/staticRefCase20.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
#include "test_data/staticRefCase21.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
#include "test_data/staticRefCase22.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
#include "test_data/staticRefCase23.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
#include "test_data/staticRefCase24.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
#include "test_data/staticRefCase25.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
#include "test_data/staticRefCase26.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
#include "test_data/staticRefCase27.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
#include "test_data/staticRefCase28.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
#include "test_data/staticRefCase29.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
#include "test_data/staticRefCase30.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
#include "test_data/staticRefCase31.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
#include "test_data/staticRefCase32.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
#include "test_data/staticRefCase33.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
#include "test_data/staticRefCase34.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
#include "test_data/staticRefCase35.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
#include "test_data/staticRefCase36.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
#include "test_data/staticRefCase37.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
#include "test_data/staticRefCase38.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
#include "test_data/staticRefCase39.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
#include "test_data/staticRefCase40.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
#include "test_data/staticRefCase41.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
#include "test_data/staticRefCase42.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
#include "test_data/staticRefCase43.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 44))
#include "test_data/staticRefCase44.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 45))
#include "test_data/staticRefCase45.h"
#endif

static ifft1dBatched_i32fc_c32fc_o32f_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        STATIC,        // test pattern
        staticRefIn1,  // staticIn
        staticRefOut1, // staticOut
        128,           // numPoints
        1,             // numChannels
        1,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        STATIC,        // test pattern
        staticRefIn2,  // staticIn
        staticRefOut2, // staticOut
        256,           // numPoints
        1,             // numChannels
        2,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        STATIC,        // test pattern
        staticRefIn3,  // staticIn
        staticRefOut3, // staticOut
        512,           // numPoints
        1,             // numChannels
        3,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        STATIC,        // test pattern
        staticRefIn4,  // staticIn
        staticRefOut4, // staticOut
        1024,          // numPoints
        1,             // numChannels
        4,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        STATIC,        // test pattern
        staticRefIn5,  // staticIn
        staticRefOut5, // staticOut
        2048,          // numPoints
        1,             // numChannels
        5,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        STATIC,        // test pattern
        staticRefIn6,  // staticIn
        staticRefOut6, // staticOut
        4096,          // numPoints
        1,             // numChannels
        6,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        STATIC,        // test pattern
        staticRefIn7,  // staticIn
        staticRefOut7, // staticOut
        8192,          // numPoints
        1,             // numChannels
        7,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        STATIC,        // test pattern
        staticRefIn8,  // staticIn
        staticRefOut8, // staticOut
        128,           // numPoints
        2,             // numChannels
        8,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        STATIC,        // test pattern
        staticRefIn9,  // staticIn
        staticRefOut9, // staticOut
        256,           // numPoints
        2,             // numChannels
        9,             // test ID
        0,             // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        STATIC,         // test pattern
        staticRefIn10,  // staticIn
        staticRefOut10, // staticOut
        512,            // numPoints
        2,              // numChannels
        10,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        STATIC,         // test pattern
        staticRefIn11,  // staticIn
        staticRefOut11, // staticOut
        1024,           // numPoints
        2,              // numChannels
        11,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        STATIC,         // test pattern
        staticRefIn12,  // staticIn
        staticRefOut12, // staticOut
        2048,           // numPoints
        2,              // numChannels
        12,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        STATIC,         // test pattern
        staticRefIn13,  // staticIn
        staticRefOut13, // staticOut
        4096,           // numPoints
        2,              // numChannels
        13,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        STATIC,         // test pattern
        staticRefIn14,  // staticIn
        staticRefOut14, // staticOut
        8192,           // numPoints
        2,              // numChannels
        14,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        STATIC,         // test pattern
        staticRefIn15,  // staticIn
        staticRefOut15, // staticOut
        128,            // numPoints
        4,              // numChannels
        15,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        STATIC,         // test pattern
        staticRefIn16,  // staticIn
        staticRefOut16, // staticOut
        256,            // numPoints
        4,              // numChannels
        16,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        STATIC,         // test pattern
        staticRefIn17,  // staticIn
        staticRefOut17, // staticOut
        512,            // numPoints
        4,              // numChannels
        17,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        STATIC,         // test pattern
        staticRefIn18,  // staticIn
        staticRefOut18, // staticOut
        1024,           // numPoints
        4,              // numChannels
        18,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        STATIC,         // test pattern
        staticRefIn19,  // staticIn
        staticRefOut19, // staticOut
        2048,           // numPoints
        4,              // numChannels
        19,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        STATIC,         // test pattern
        staticRefIn20,  // staticIn
        staticRefOut20, // staticOut
        4096,           // numPoints
        4,              // numChannels
        20,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        STATIC,         // test pattern
        staticRefIn21,  // staticIn
        staticRefOut21, // staticOut
        128,            // numPoints
        16,             // numChannels
        21,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        STATIC,         // test pattern
        staticRefIn22,  // staticIn
        staticRefOut22, // staticOut
        256,            // numPoints
        16,             // numChannels
        22,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        STATIC,         // test pattern
        staticRefIn23,  // staticIn
        staticRefOut23, // staticOut
        512,            // numPoints
        16,             // numChannels
        23,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        STATIC,         // test pattern
        staticRefIn24,  // staticIn
        staticRefOut24, // staticOut
        1024,           // numPoints
        16,             // numChannels
        24,             // test ID
        0,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        STATIC,         // test pattern
        staticRefIn25,  // staticIn
        staticRefOut25, // staticOut
        128,            // numPoints
        1,              // numChannels
        25,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        STATIC,         // test pattern
        staticRefIn26,  // staticIn
        staticRefOut26, // staticOut
        256,            // numPoints
        1,              // numChannels
        26,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        STATIC,         // test pattern
        staticRefIn27,  // staticIn
        staticRefOut27, // staticOut
        512,            // numPoints
        1,              // numChannels
        27,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        STATIC,         // test pattern
        staticRefIn28,  // staticIn
        staticRefOut28, // staticOut
        1024,           // numPoints
        1,              // numChannels
        28,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        STATIC,         // test pattern
        staticRefIn29,  // staticIn
        staticRefOut29, // staticOut
        2048,           // numPoints
        1,              // numChannels
        29,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        STATIC,         // test pattern
        staticRefIn30,  // staticIn
        staticRefOut30, // staticOut
        4096,           // numPoints
        1,              // numChannels
        30,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        STATIC,         // test pattern
        staticRefIn31,  // staticIn
        staticRefOut31, // staticOut
        128,            // numPoints
        2,              // numChannels
        31,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        STATIC,         // test pattern
        staticRefIn32,  // staticIn
        staticRefOut32, // staticOut
        256,            // numPoints
        2,              // numChannels
        32,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        STATIC,         // test pattern
        staticRefIn33,  // staticIn
        staticRefOut33, // staticOut
        512,            // numPoints
        2,              // numChannels
        33,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        STATIC,         // test pattern
        staticRefIn34,  // staticIn
        staticRefOut34, // staticOut
        1024,           // numPoints
        2,              // numChannels
        34,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        STATIC,         // test pattern
        staticRefIn35,  // staticIn
        staticRefOut35, // staticOut
        2048,           // numPoints
        2,              // numChannels
        35,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        STATIC,         // test pattern
        staticRefIn36,  // staticIn
        staticRefOut36, // staticOut
        4096,           // numPoints
        2,              // numChannels
        36,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        STATIC,         // test pattern
        staticRefIn37,  // staticIn
        staticRefOut37, // staticOut
        8192,           // numPoints
        2,              // numChannels
        37,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        STATIC,         // test pattern
        staticRefIn38,  // staticIn
        staticRefOut38, // staticOut
        128,            // numPoints
        4,              // numChannels
        38,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        STATIC,         // test pattern
        staticRefIn39,  // staticIn
        staticRefOut39, // staticOut
        256,            // numPoints
        4,              // numChannels
        39,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        STATIC,         // test pattern
        staticRefIn40,  // staticIn
        staticRefOut40, // staticOut
        512,            // numPoints
        4,              // numChannels
        40,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
    {
        STATIC,         // test pattern
        staticRefIn41,  // staticIn
        staticRefOut41, // staticOut
        1024,           // numPoints
        4,              // numChannels
        41,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
    {
        STATIC,         // test pattern
        staticRefIn42,  // staticIn
        staticRefOut42, // staticOut
        2048,           // numPoints
        4,              // numChannels
        42,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
    {
        STATIC,         // test pattern
        staticRefIn43,  // staticIn
        staticRefOut43, // staticOut
        128,            // numPoints
        16,             // numChannels
        43,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 44))
    {
        STATIC,         // test pattern
        staticRefIn44,  // staticIn
        staticRefOut44, // staticOut
        256,            // numPoints
        16,             // numChannels
        44,             // test ID
        1,              // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 45))
    {
        STATIC,         // test pattern
        staticRefIn45,  // staticIn
        staticRefOut45, // staticOut
        512,            // numPoints
        16,             // numChannels
        45,             // test ID
        1,              // inMode
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void ifft1dBatched_i32fc_c32fc_o32f_getTestParams(ifft1dBatched_i32fc_c32fc_o32f_testParams_t** params,
                                                  int32_t*                                      numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(ifft1dBatched_i32fc_c32fc_o32f_testParams_t);
}
