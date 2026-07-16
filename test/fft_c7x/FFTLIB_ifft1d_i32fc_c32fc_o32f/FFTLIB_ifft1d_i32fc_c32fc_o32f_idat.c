// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0


#include "FFTLIB_ifft1d_i32fc_c32fc_o32f_idat.h"

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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 53))
#include "test_data/staticRefCase53.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 54))
#include "test_data/staticRefCase54.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 55))
#include "test_data/staticRefCase55.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 56))
#include "test_data/staticRefCase56.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 57))
#include "test_data/staticRefCase57.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
#include "test_data/staticRefCase58.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 84))
#include "test_data/staticRefCase84.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 85))
#include "test_data/staticRefCase85.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 86))
#include "test_data/staticRefCase86.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 87))
#include "test_data/staticRefCase87.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 88))
#include "test_data/staticRefCase88.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 89))
#include "test_data/staticRefCase89.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 90))
#include "test_data/staticRefCase90.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 91))
#include "test_data/staticRefCase91.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 92))
#include "test_data/staticRefCase92.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 93))
#include "test_data/staticRefCase93.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 94))
#include "test_data/staticRefCase94.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 95))
#include "test_data/staticRefCase95.h"
#endif

static ifft1d_i32fc_c32fc_o32f_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        STATIC,        // test pattern
        staticRefIn1,  // staticIn
        staticRefOut1, // staticOut
        64,            // numPoints
        1,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        STATIC,        // test pattern
        staticRefIn2,  // staticIn
        staticRefOut2, // staticOut
        128,           // numPoints
        2,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        STATIC,        // test pattern
        staticRefIn3,  // staticIn
        staticRefOut3, // staticOut
        256,           // numPoints
        3,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        STATIC,        // test pattern
        staticRefIn4,  // staticIn
        staticRefOut4, // staticOut
        512,           // numPoints
        4,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        STATIC,        // test pattern
        staticRefIn5,  // staticIn
        staticRefOut5, // staticOut
        1024,          // numPoints
        5,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        STATIC,        // test pattern
        staticRefIn6,  // staticIn
        staticRefOut6, // staticOut
        2048,          // numPoints
        6,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        STATIC,        // test pattern
        staticRefIn7,  // staticIn
        staticRefOut7, // staticOut
        4096,          // numPoints
        7,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        STATIC,        // test pattern
        staticRefIn8,  // staticIn
        staticRefOut8, // staticOut
        8192,          // numPoints
        8,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        STATIC,        // test pattern
        staticRefIn9,  // staticIn
        staticRefOut9, // staticOut
        128,           // numPoints
        9,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        STATIC,        // test pattern
        staticRefIn10, // staticIn
        staticRefOut10,// staticOut
        256,           // numPoints
        10,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        STATIC,        // test pattern
        staticRefIn11, // staticIn
        staticRefOut11,// staticOut
        10,            // numPoints
        11,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        STATIC,        // test pattern
        staticRefIn12, // staticIn
        staticRefOut12,// staticOut
        50,            // numPoints
        12,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        STATIC,        // test pattern
        staticRefIn13, // staticIn
        staticRefOut13,// staticOut
        250,           // numPoints
        13,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        STATIC,        // test pattern
        staticRefIn14, // staticIn
        staticRefOut14,// staticOut
        1250,          // numPoints
        14,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        STATIC,        // test pattern
        staticRefIn15, // staticIn
        staticRefOut15,// staticOut
        6250,          // numPoints
        15,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        STATIC,        // test pattern
        staticRefIn16, // staticIn
        staticRefOut16,// staticOut
        31250,         // numPoints
        16,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        STATIC,        // test pattern
        staticRefIn17, // staticIn
        staticRefOut17,// staticOut
        320,           // numPoints
        17,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        STATIC,        // test pattern
        staticRefIn18, // staticIn
        staticRefOut18,// staticOut
        1600,          // numPoints
        18,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        STATIC,        // test pattern
        staticRefIn19, // staticIn
        staticRefOut19,// staticOut
        8000,          // numPoints
        19,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        STATIC,        // test pattern
        staticRefIn20, // staticIn
        staticRefOut20,// staticOut
        640,           // numPoints
        20,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        STATIC,        // test pattern
        staticRefIn21, // staticIn
        staticRefOut21,// staticOut
        3200,          // numPoints
        21,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        STATIC,        // test pattern
        staticRefIn22, // staticIn
        staticRefOut22,// staticOut
        16000,         // numPoints
        22,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        STATIC,        // test pattern
        staticRefIn23, // staticIn
        staticRefOut23,// staticOut
        1280,          // numPoints
        23,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        STATIC,        // test pattern
        staticRefIn24, // staticIn
        staticRefOut24,// staticOut
        6400,          // numPoints
        24,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        STATIC,        // test pattern
        staticRefIn25, // staticIn
        staticRefOut25,// staticOut
        32000,         // numPoints
        25,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        STATIC,        // test pattern
        staticRefIn26, // staticIn
        staticRefOut26,// staticOut
        2560,          // numPoints
        26,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        STATIC,        // test pattern
        staticRefIn27, // staticIn
        staticRefOut27,// staticOut
        12800,         // numPoints
        27,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        STATIC,        // test pattern
        staticRefIn28, // staticIn
        staticRefOut28,// staticOut
        5120,          // numPoints
        28,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        STATIC,        // test pattern
        staticRefIn29, // staticIn
        staticRefOut29,// staticOut
        6,             // numPoints
        29,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        STATIC,        // test pattern
        staticRefIn30, // staticIn
        staticRefOut30,// staticOut
        18,            // numPoints
        30,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        STATIC,        // test pattern
        staticRefIn31, // staticIn
        staticRefOut31,// staticOut
        54,            // numPoints
        31,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        STATIC,        // test pattern
        staticRefIn32, // staticIn
        staticRefOut32,// staticOut
        162,           // numPoints
        32,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        STATIC,        // test pattern
        staticRefIn33, // staticIn
        staticRefOut33,// staticOut
        486,           // numPoints
        33,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        STATIC,        // test pattern
        staticRefIn34, // staticIn
        staticRefOut34,// staticOut
        192,           // numPoints
        34,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        STATIC,        // test pattern
        staticRefIn35, // staticIn
        staticRefOut35,// staticOut
        384,           // numPoints
        35,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        STATIC,        // test pattern
        staticRefIn36, // staticIn
        staticRefOut36,// staticOut
        768,           // numPoints
        36,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        STATIC,        // test pattern
        staticRefIn37, // staticIn
        staticRefOut37,// staticOut
        1536,          // numPoints
        37,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        STATIC,        // test pattern
        staticRefIn38, // staticIn
        staticRefOut38,// staticOut
        3072,          // numPoints
        38,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        STATIC,        // test pattern
        staticRefIn39, // staticIn
        staticRefOut39,// staticOut
        576,           // numPoints
        39,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        STATIC,        // test pattern
        staticRefIn40, // staticIn
        staticRefOut40,// staticOut
        1152,          // numPoints
        40,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        2304,          // numPoints
        41,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        4608,          // numPoints
        42,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        9216,          // numPoints
        43,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 44))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        1728,          // numPoints
        44,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 45))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        3456,          // numPoints
        45,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 46))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        6912,          // numPoints
        46,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 47))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        13824,         // numPoints
        47,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 48))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        27648,         // numPoints
        48,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 49))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        5184,          // numPoints
        49,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 50))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        10368,         // numPoints
        50,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 51))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        20736,         // numPoints
        51,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 52))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        41472,         // numPoints
        52,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 53))
    {
        STATIC,        // test pattern
        staticRefIn53, // staticIn
        staticRefOut53,// staticOut
        30,            // numPoints
        53,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 54))
    {
        STATIC,        // test pattern
        staticRefIn54, // staticIn
        staticRefOut54,// staticOut
        90,            // numPoints
        54,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 55))
    {
        STATIC,        // test pattern
        staticRefIn55, // staticIn
        staticRefOut55,// staticOut
        270,           // numPoints
        55,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 56))
    {
        STATIC,        // test pattern
        staticRefIn56, // staticIn
        staticRefOut56,// staticOut
        810,           // numPoints
        56,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 57))
    {
        STATIC,        // test pattern
        staticRefIn57, // staticIn
        staticRefOut57,// staticOut
        960,           // numPoints
        57,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
    {
        STATIC,        // test pattern
        staticRefIn58, // staticIn
        staticRefOut58,// staticOut
        1920,          // numPoints
        58,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        3840,          // numPoints
        59,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 60))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        7680,          // numPoints
        60,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 61))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        15360,         // numPoints
        61,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 62))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        2880,          // numPoints
        62,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 63))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        5760,          // numPoints
        63,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 64))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        11520,         // numPoints
        64,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 65))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        23040,         // numPoints
        65,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 66))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        8640,          // numPoints
        66,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 67))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        17280,         // numPoints
        67,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 68))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        34560,         // numPoints
        68,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 69))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        25920,         // numPoints
        69,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 70))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        150,           // numPoints
        70,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 71))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        450,           // numPoints
        71,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 72))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        1350,          // numPoints
        72,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 73))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        4050,          // numPoints
        73,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 74))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        4800,          // numPoints
        74,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 75))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        9600,          // numPoints
        75,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 76))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        19200,         // numPoints
        76,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 77))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        14400,         // numPoints
        77,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 78))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        28800,         // numPoints
        78,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 79))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        750,           // numPoints
        79,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 80))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        2250,          // numPoints
        80,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 81))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        6750,          // numPoints
        81,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 82))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        20250,         // numPoints
        82,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 83))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        24000,         // numPoints
        83,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 84))
    {
        STATIC,        // test pattern
        staticRefIn84, // staticIn
        staticRefOut84,// staticOut
        4,             // numPoints
        84,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 85))
    {
        STATIC,        // test pattern
        staticRefIn85, // staticIn
        staticRefOut85,// staticOut
        100,           // numPoints
        85,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 86))
    {
        STATIC,        // test pattern
        staticRefIn86, // staticIn
        staticRefOut86,// staticOut
        36,            // numPoints
        86,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 87))
    {
        STATIC,        // test pattern
        staticRefIn87, // staticIn
        staticRefOut87,// staticOut
        8,             // numPoints
        87,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 88))
    {
        STATIC,        // test pattern
        staticRefIn88, // staticIn
        staticRefOut88,// staticOut
        200,           // numPoints
        88,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 89))
    {
        STATIC,        // test pattern
        staticRefIn89, // staticIn
        staticRefOut89,// staticOut
        72,            // numPoints
        89,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 90))
    {
        STATIC,        // test pattern
        staticRefIn90, // staticIn
        staticRefOut90,// staticOut
        16,            // numPoints
        90,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 91))
    {
        STATIC,        // test pattern
        staticRefIn91, // staticIn
        staticRefOut91,// staticOut
        400,           // numPoints
        91,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 92))
    {
        STATIC,        // test pattern
        staticRefIn92, // staticIn
        staticRefOut92,// staticOut
        144,           // numPoints
        92,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 93))
    {
        STATIC,        // test pattern
        staticRefIn93, // staticIn
        staticRefOut93,// staticOut
        32,            // numPoints
        93,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 94))
    {
        STATIC,        // test pattern
        staticRefIn94, // staticIn
        staticRefOut94,// staticOut
        800,           // numPoints
        94,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 95))
    {
        STATIC,        // test pattern
        staticRefIn95, // staticIn
        staticRefOut95,// staticOut
        288,           // numPoints
        95,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 96))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        156250,        // numPoints
        96,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 97))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        4374,          // numPoints
        97,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 98))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        39366,         // numPoints
        98,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 99))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        62500,         // numPoints
        99,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 100))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        8748,          // numPoints
        100,           // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 101))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        26244,         // numPoints
        101,           // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 102))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        65610,         // numPoints
        102,           // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 103))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        24300,         // numPoints
        103,           // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 104))
    {
        RANDOM,        // test pattern
        NULL,          // staticIn
        NULL,          // staticOut
        43740,         // numPoints
        104,           // test ID
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void ifft1d_i32fc_c32fc_o32f_getTestParams(ifft1d_i32fc_c32fc_o32f_testParams_t** params, int32_t* numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(ifft1d_i32fc_c32fc_o32f_testParams_t);
}

/* ======================================================================== */
/*                       End of file                                        */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2017 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
