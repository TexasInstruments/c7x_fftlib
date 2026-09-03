// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0


#include "FFTLIB_fft1d_i32fc_c32fc_o32fc_idat.h"

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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 46))
#include "test_data/staticRefCase46.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 47))
#include "test_data/staticRefCase47.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 48))
#include "test_data/staticRefCase48.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 49))
#include "test_data/staticRefCase49.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
#include "test_data/staticRefCase58.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
#include "test_data/staticRefCase59.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 60))
#include "test_data/staticRefCase60.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 61))
#include "test_data/staticRefCase61.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 62))
#include "test_data/staticRefCase62.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 63))
#include "test_data/staticRefCase63.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 64))
#include "test_data/staticRefCase64.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 65))
#include "test_data/staticRefCase65.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 66))
#include "test_data/staticRefCase66.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 67))
#include "test_data/staticRefCase67.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 75))
#include "test_data/staticRefCase75.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 76))
#include "test_data/staticRefCase76.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 77))
#include "test_data/staticRefCase77.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 78))
#include "test_data/staticRefCase78.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 79))
#include "test_data/staticRefCase79.h"
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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 96))
#include "test_data/staticRefCase96.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 97))
#include "test_data/staticRefCase97.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 98))
#include "test_data/staticRefCase98.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 99))
#include "test_data/staticRefCase99.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 100))
#include "test_data/staticRefCase100.h"
#endif

static fft1d_i32fc_c32fc_o32fc_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        STATIC,              // test pattern
        staticRefIn1,        // staticIn
        staticRefOut1,       // staticOut
        64,                  // numPoints
        1,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        STATIC,              // test pattern
        staticRefIn2,        // staticIn
        staticRefOut2,       // staticOut
        256,                 // numPoints
        2,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        STATIC,              // test pattern
        staticRefIn3,        // staticIn
        staticRefOut3,       // staticOut
        1024,                // numPoints
        3,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        STATIC,              // test pattern
        staticRefIn4,        // staticIn
        staticRefOut4,       // staticOut
        4096,                // numPoints
        4,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        STATIC,              // test pattern
        staticRefIn5,        // staticIn
        staticRefOut5,       // staticOut
        16384,               // numPoints
        5,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        STATIC,              // test pattern
        staticRefIn6,        // staticIn
        staticRefOut6,       // staticOut
        128,                 // numPoints
        6,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        STATIC,              // test pattern
        staticRefIn7,        // staticIn
        staticRefOut7,       // staticOut
        512,                 // numPoints
        7,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        STATIC,              // test pattern
        staticRefIn8,        // staticIn
        staticRefOut8,       // staticOut
        2048,                // numPoints
        8,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        STATIC,              // test pattern
        staticRefIn9,        // staticIn
        staticRefOut9,       // staticOut
        8192,                // numPoints
        9,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4096,                // numPoints
        10,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1024,                // numPoints
        11,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8192,                // numPoints
        12,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        STATIC,              // test pattern
        staticRefIn13,       // staticIn
        staticRefOut13,      // staticOut
        5,                   // numPoints
        13,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        STATIC,              // test pattern
        staticRefIn14,       // staticIn
        staticRefOut14,      // staticOut
        25,                  // numPoints
        14,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        STATIC,              // test pattern
        staticRefIn15,       // staticIn
        staticRefOut15,      // staticOut
        125,                 // numPoints
        15,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        STATIC,              // test pattern
        staticRefIn16,       // staticIn
        staticRefOut16,      // staticOut
        625,                 // numPoints
        16,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        STATIC,              // test pattern
        staticRefIn17,       // staticIn
        staticRefOut17,      // staticOut
        3125,                // numPoints
        17,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        STATIC,              // test pattern
        staticRefIn18,       // staticIn
        staticRefOut18,      // staticOut
        15625,               // numPoints
        18,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        STATIC,              // test pattern
        staticRefIn19,       // staticIn
        staticRefOut19,      // staticOut
        160,                 // numPoints
        19,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        STATIC,              // test pattern
        staticRefIn20,       // staticIn
        staticRefOut20,      // staticOut
        800,                 // numPoints
        20,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        STATIC,              // test pattern
        staticRefIn21,       // staticIn
        staticRefOut21,      // staticOut
        4000,                // numPoints
        21,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        STATIC,              // test pattern
        staticRefIn22,       // staticIn
        staticRefOut22,      // staticOut
        320,                 // numPoints
        22,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        23,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8000,                // numPoints
        24,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        25,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        26,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16000,               // numPoints
        27,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        28,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        29,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2560,                // numPoints
        30,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        STATIC,              // test pattern
        staticRefIn31,       // staticIn
        staticRefOut31,      // staticOut
        3,                   // numPoints
        31,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        STATIC,              // test pattern
        staticRefIn32,       // staticIn
        staticRefOut32,      // staticOut
        9,                   // numPoints
        32,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        STATIC,              // test pattern
        staticRefIn33,       // staticIn
        staticRefOut33,      // staticOut
        27,                  // numPoints
        33,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        STATIC,              // test pattern
        staticRefIn34,       // staticIn
        staticRefOut34,      // staticOut
        81,                  // numPoints
        34,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        STATIC,              // test pattern
        staticRefIn35,       // staticIn
        staticRefOut35,      // staticOut
        243,                 // numPoints
        35,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        STATIC,              // test pattern
        staticRefIn36,       // staticIn
        staticRefOut36,      // staticOut
        729,                 // numPoints
        36,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        STATIC,              // test pattern
        staticRefIn37,       // staticIn
        staticRefOut37,      // staticOut
        96,                  // numPoints
        37,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        STATIC,              // test pattern
        staticRefIn38,       // staticIn
        staticRefOut38,      // staticOut
        192,                 // numPoints
        38,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        STATIC,              // test pattern
        staticRefIn39,       // staticIn
        staticRefOut39,      // staticOut
        384,                 // numPoints
        39,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        STATIC,              // test pattern
        staticRefIn40,       // staticIn
        staticRefOut40,      // staticOut
        768,                 // numPoints
        40,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
    {
        STATIC,              // test pattern
        staticRefIn41,       // staticIn
        staticRefOut41,      // staticOut
        1536,                // numPoints
        41,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
    {
        STATIC,              // test pattern
        staticRefIn42,       // staticIn
        staticRefOut42,      // staticOut
        288,                 // numPoints
        42,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
    {
        STATIC,              // test pattern
        staticRefIn43,       // staticIn
        staticRefOut43,      // staticOut
        576,                 // numPoints
        43,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 44))
    {
        STATIC,              // test pattern
        staticRefIn44,       // staticIn
        staticRefOut44,      // staticOut
        1152,                // numPoints
        44,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 45))
    {
        STATIC,              // test pattern
        staticRefIn45,       // staticIn
        staticRefOut45,      // staticOut
        2304,                // numPoints
        45,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 46))
    {
        STATIC,              // test pattern
        staticRefIn46,       // staticIn
        staticRefOut46,      // staticOut
        4608,                // numPoints
        46,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 47))
    {
        STATIC,              // test pattern
        staticRefIn47,       // staticIn
        staticRefOut47,      // staticOut
        864,                 // numPoints
        47,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 48))
    {
        STATIC,              // test pattern
        staticRefIn48,       // staticIn
        staticRefOut48,      // staticOut
        1728,                // numPoints
        48,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 49))
    {
        STATIC,              // test pattern
        staticRefIn49,       // staticIn
        staticRefOut49,      // staticOut
        3456,                // numPoints
        49,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 50))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6912,                // numPoints
        50,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 51))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        13824,               // numPoints
        51,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 52))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2592,                // numPoints
        52,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 53))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        53,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 54))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        10368,               // numPoints
        54,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 55))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        20736,               // numPoints
        55,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 56))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        7776,                // numPoints
        56,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 57))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        15552,               // numPoints
        57,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
    {
        STATIC,              // test pattern
        staticRefIn58,       // staticIn
        staticRefOut58,      // staticOut
        15,                  // numPoints
        58,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
    {
        STATIC,              // test pattern
        staticRefIn59,       // staticIn
        staticRefOut59,      // staticOut
        45,                  // numPoints
        59,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 60))
    {
        STATIC,              // test pattern
        staticRefIn60,       // staticIn
        staticRefOut60,      // staticOut
        135,                 // numPoints
        60,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 61))
    {
        STATIC,              // test pattern
        staticRefIn61,       // staticIn
        staticRefOut61,      // staticOut
        405,                 // numPoints
        61,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 62))
    {
        STATIC,              // test pattern
        staticRefIn62,       // staticIn
        staticRefOut62,      // staticOut
        480,                 // numPoints
        62,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 63))
    {
        STATIC,              // test pattern
        staticRefIn63,       // staticIn
        staticRefOut63,      // staticOut
        960,                 // numPoints
        63,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 64))
    {
        STATIC,              // test pattern
        staticRefIn64,       // staticIn
        staticRefOut64,      // staticOut
        1920,                // numPoints
        64,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 65))
    {
        STATIC,              // test pattern
        staticRefIn65,       // staticIn
        staticRefOut65,      // staticOut
        3840,                // numPoints
        65,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 66))
    {
        STATIC,              // test pattern
        staticRefIn66,       // staticIn
        staticRefOut66,      // staticOut
        7680,                // numPoints
        66,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 67))
    {
        STATIC,              // test pattern
        staticRefIn67,       // staticIn
        staticRefOut67,      // staticOut
        1440,                // numPoints
        67,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 68))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        68,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 69))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        69,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 70))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        11520,               // numPoints
        70,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 71))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4320,                // numPoints
        71,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 72))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8640,                // numPoints
        72,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 73))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        17280,               // numPoints
        73,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 74))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12960,               // numPoints
        74,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 75))
    {
        STATIC,              // test pattern
        staticRefIn75,       // staticIn
        staticRefOut75,      // staticOut
        75,                  // numPoints
        75,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 76))
    {
        STATIC,              // test pattern
        staticRefIn76,       // staticIn
        staticRefOut76,      // staticOut
        225,                 // numPoints
        76,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 77))
    {
        STATIC,              // test pattern
        staticRefIn77,       // staticIn
        staticRefOut77,      // staticOut
        675,                 // numPoints
        77,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 78))
    {
        STATIC,              // test pattern
        staticRefIn78,       // staticIn
        staticRefOut78,      // staticOut
        2025,                // numPoints
        78,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 79))
    {
        STATIC,              // test pattern
        staticRefIn79,       // staticIn
        staticRefOut79,      // staticOut
        2400,                // numPoints
        79,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 80))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4800,                // numPoints
        80,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 81))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        9600,                // numPoints
        81,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 82))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        7200,                // numPoints
        82,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 83))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        14400,               // numPoints
        83,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 84))
    {
        STATIC,              // test pattern
        staticRefIn84,       // staticIn
        staticRefOut84,      // staticOut
        375,                 // numPoints
        84,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 85))
    {
        STATIC,              // test pattern
        staticRefIn85,       // staticIn
        staticRefOut85,      // staticOut
        1125,                // numPoints
        85,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 86))
    {
        STATIC,              // test pattern
        staticRefIn86,       // staticIn
        staticRefOut86,      // staticOut
        3375,                // numPoints
        86,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 87))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        10125,               // numPoints
        87,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 88))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12000,               // numPoints
        88,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 89))
    {
        STATIC,              // test pattern
        staticRefIn89,       // staticIn
        staticRefOut89,      // staticOut
        2,                   // numPoints
        89,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 90))
    {
        STATIC,              // test pattern
        staticRefIn90,       // staticIn
        staticRefOut90,      // staticOut
        50,                  // numPoints
        90,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 91))
    {
        STATIC,              // test pattern
        staticRefIn91,       // staticIn
        staticRefOut91,      // staticOut
        18,                  // numPoints
        91,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 92))
    {
        STATIC,              // test pattern
        staticRefIn92,       // staticIn
        staticRefOut92,      // staticOut
        4,                   // numPoints
        92,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 93))
    {
        STATIC,              // test pattern
        staticRefIn93,       // staticIn
        staticRefOut93,      // staticOut
        100,                 // numPoints
        93,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 94))
    {
        STATIC,              // test pattern
        staticRefIn94,       // staticIn
        staticRefOut94,      // staticOut
        36,                  // numPoints
        94,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 95))
    {
        STATIC,              // test pattern
        staticRefIn95,       // staticIn
        staticRefOut95,      // staticOut
        8,                   // numPoints
        95,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 96))
    {
        STATIC,              // test pattern
        staticRefIn96,       // staticIn
        staticRefOut96,      // staticOut
        200,                 // numPoints
        96,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 97))
    {
        STATIC,              // test pattern
        staticRefIn97,       // staticIn
        staticRefOut97,      // staticOut
        72,                  // numPoints
        97,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 98))
    {
        STATIC,              // test pattern
        staticRefIn98,       // staticIn
        staticRefOut98,      // staticOut
        16,                  // numPoints
        98,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 99))
    {
        STATIC,              // test pattern
        staticRefIn99,       // staticIn
        staticRefOut99,      // staticOut
        400,                 // numPoints
        99,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 100))
    {
        STATIC,              // test pattern
        staticRefIn100,      // staticIn
        staticRefOut100,     // staticOut
        144,                 // numPoints
        100,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 101))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        78125,               // numPoints
        101,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 102))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2187,                // numPoints
        102,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 103))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        19683,               // numPoints
        103,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 104))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        31250,               // numPoints
        104,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 105))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4374,                // numPoints
        105,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 106))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        13122,               // numPoints
        106,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 107))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32805,               // numPoints
        107,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 108))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12150,               // numPoints
        108,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 109))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        21870,               // numPoints
        109,                 // test ID
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void fft1d_i32fc_c32fc_o32fc_getTestParams(fft1d_i32fc_c32fc_o32fc_testParams_t** params, int32_t* numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(fft1d_i32fc_c32fc_o32fc_testParams_t);
}
