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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 100))
#include "test_data/staticRefCase100.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 101))
#include "test_data/staticRefCase101.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 102))
#include "test_data/staticRefCase102.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 103))
#include "test_data/staticRefCase103.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 104))
#include "test_data/staticRefCase104.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 105))
#include "test_data/staticRefCase105.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 106))
#include "test_data/staticRefCase106.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 107))
#include "test_data/staticRefCase107.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 108))
#include "test_data/staticRefCase108.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 109))
#include "test_data/staticRefCase109.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 110))
#include "test_data/staticRefCase110.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 111))
#include "test_data/staticRefCase111.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 112))
#include "test_data/staticRefCase112.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 113))
#include "test_data/staticRefCase113.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 118))
#include "test_data/staticRefCase118.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 119))
#include "test_data/staticRefCase119.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 154))
#include "test_data/staticRefCase154.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 155))
#include "test_data/staticRefCase155.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 156))
#include "test_data/staticRefCase156.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 157))
#include "test_data/staticRefCase157.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 158))
#include "test_data/staticRefCase158.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 159))
#include "test_data/staticRefCase159.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 160))
#include "test_data/staticRefCase160.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 161))
#include "test_data/staticRefCase161.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 162))
#include "test_data/staticRefCase162.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 163))
#include "test_data/staticRefCase163.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 164))
#include "test_data/staticRefCase164.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 165))
#include "test_data/staticRefCase165.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 166))
#include "test_data/staticRefCase166.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 167))
#include "test_data/staticRefCase167.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 168))
#include "test_data/staticRefCase168.h"
#endif

static fft1dBatched_i32f_c32fc_o32fc_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        STATIC,              // test pattern
        staticRefIn1,        // staticIn
        staticRefOut1,       // staticOut
        64,                  // numPoints
        1,                   // numChannels
        1,                   // outmode
        1,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        STATIC,              // test pattern
        staticRefIn2,        // staticIn
        staticRefOut2,       // staticOut
        128,                 // numPoints
        2,                   // numChannels
        1,                   // outmode
        2,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        STATIC,              // test pattern
        staticRefIn3,        // staticIn
        staticRefOut3,       // staticOut
        256,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        3,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        STATIC,              // test pattern
        staticRefIn4,        // staticIn
        staticRefOut4,       // staticOut
        512,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        4,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        STATIC,              // test pattern
        staticRefIn5,        // staticIn
        staticRefOut5,       // staticOut
        1024,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        5,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        STATIC,              // test pattern
        staticRefIn6,        // staticIn
        staticRefOut6,       // staticOut
        64,                  // numPoints
        1,                   // numChannels
        0,                   // outmode
        6,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        STATIC,              // test pattern
        staticRefIn7,        // staticIn
        staticRefOut7,       // staticOut
        128,                 // numPoints
        2,                   // numChannels
        0,                   // outmode
        7,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        STATIC,              // test pattern
        staticRefIn8,        // staticIn
        staticRefOut8,       // staticOut
        256,                 // numPoints
        4,                   // numChannels
        0,                   // outmode
        8,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        STATIC,              // test pattern
        staticRefIn9,        // staticIn
        staticRefOut9,       // staticOut
        512,                 // numPoints
        8,                   // numChannels
        0,                   // outmode
        9,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        STATIC,              // test pattern
        staticRefIn10,       // staticIn
        staticRefOut10,      // staticOut
        1024,                // numPoints
        4,                   // numChannels
        0,                   // outmode
        10,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        STATIC,              // test pattern
        staticRefIn11,       // staticIn
        staticRefOut11,      // staticOut
        10,                  // numPoints
        1,                   // numChannels
        1,                   // outmode
        11,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        STATIC,              // test pattern
        staticRefIn12,       // staticIn
        staticRefOut12,      // staticOut
        50,                  // numPoints
        1,                   // numChannels
        1,                   // outmode
        12,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        STATIC,              // test pattern
        staticRefIn13,       // staticIn
        staticRefOut13,      // staticOut
        250,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        13,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        STATIC,              // test pattern
        staticRefIn14,       // staticIn
        staticRefOut14,      // staticOut
        1250,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        14,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        STATIC,              // test pattern
        staticRefIn15,       // staticIn
        staticRefOut15,      // staticOut
        6250,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        15,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        STATIC,              // test pattern
        staticRefIn16,       // staticIn
        staticRefOut16,      // staticOut
        50,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        16,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        STATIC,              // test pattern
        staticRefIn17,       // staticIn
        staticRefOut17,      // staticOut
        250,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        17,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        STATIC,              // test pattern
        staticRefIn18,       // staticIn
        staticRefOut18,      // staticOut
        1250,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        18,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        STATIC,              // test pattern
        staticRefIn19,       // staticIn
        staticRefOut19,      // staticOut
        6250,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        19,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        STATIC,              // test pattern
        staticRefIn20,       // staticIn
        staticRefOut20,      // staticOut
        10,                  // numPoints
        16,                  // numChannels
        1,                   // outmode
        20,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        STATIC,              // test pattern
        staticRefIn21,       // staticIn
        staticRefOut21,      // staticOut
        250,                 // numPoints
        16,                  // numChannels
        1,                   // outmode
        21,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        STATIC,              // test pattern
        staticRefIn22,       // staticIn
        staticRefOut22,      // staticOut
        1250,                // numPoints
        16,                  // numChannels
        1,                   // outmode
        22,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        23,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        24,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8000,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        25,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        26,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        27,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16000,               // numPoints
        1,                   // numChannels
        1,                   // outmode
        28,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        29,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        30,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2560,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        31,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12800,               // numPoints
        1,                   // numChannels
        1,                   // outmode
        32,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5120,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        33,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        2,                   // numChannels
        1,                   // outmode
        34,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        2,                   // numChannels
        1,                   // outmode
        35,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8000,                // numPoints
        2,                   // numChannels
        1,                   // outmode
        36,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        2,                   // numChannels
        1,                   // outmode
        37,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        2,                   // numChannels
        1,                   // outmode
        38,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        2,                   // numChannels
        1,                   // outmode
        39,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        2,                   // numChannels
        1,                   // outmode
        40,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2560,                // numPoints
        2,                   // numChannels
        1,                   // outmode
        41,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12800,               // numPoints
        2,                   // numChannels
        1,                   // outmode
        42,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5120,                // numPoints
        2,                   // numChannels
        1,                   // outmode
        43,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 44))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        44,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 45))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        45,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 46))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        46,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 47))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        47,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 48))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5120,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        48,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 49))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        49,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 50))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        50,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 51))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        51,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 52))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        52,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 53))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        53,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 54))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        16,                  // numChannels
        1,                   // outmode
        54,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 55))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        16,                  // numChannels
        1,                   // outmode
        55,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 56))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        10,                  // numPoints
        1,                   // numChannels
        0,                   // outmode
        56,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 57))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        250,                 // numPoints
        1,                   // numChannels
        0,                   // outmode
        57,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1250,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        58,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6250,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        59,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 60))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        50,                  // numPoints
        4,                   // numChannels
        0,                   // outmode
        60,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 61))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        250,                 // numPoints
        4,                   // numChannels
        0,                   // outmode
        61,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 62))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1250,                // numPoints
        4,                   // numChannels
        0,                   // outmode
        62,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 63))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6250,                // numPoints
        4,                   // numChannels
        0,                   // outmode
        63,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 64))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        10,                  // numPoints
        16,                  // numChannels
        0,                   // outmode
        64,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 65))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        250,                 // numPoints
        16,                  // numChannels
        0,                   // outmode
        65,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 66))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1250,                // numPoints
        16,                  // numChannels
        0,                   // outmode
        66,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 67))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        1,                   // numChannels
        0,                   // outmode
        67,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 68))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        68,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 69))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8000,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        69,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 70))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        1,                   // numChannels
        0,                   // outmode
        70,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 71))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        71,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 72))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16000,               // numPoints
        1,                   // numChannels
        0,                   // outmode
        72,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 73))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        73,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 74))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        74,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 75))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2560,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        75,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 76))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12800,               // numPoints
        1,                   // numChannels
        0,                   // outmode
        76,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 77))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5120,                // numPoints
        1,                   // numChannels
        0,                   // outmode
        77,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 78))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        2,                   // numChannels
        0,                   // outmode
        78,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 79))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        2,                   // numChannels
        0,                   // outmode
        79,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 80))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8000,                // numPoints
        2,                   // numChannels
        0,                   // outmode
        80,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 81))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        2,                   // numChannels
        0,                   // outmode
        81,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 82))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        2,                   // numChannels
        0,                   // outmode
        82,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 83))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        2,                   // numChannels
        0,                   // outmode
        83,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 84))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        2,                   // numChannels
        0,                   // outmode
        84,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 85))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2560,                // numPoints
        2,                   // numChannels
        0,                   // outmode
        85,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 86))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12800,               // numPoints
        2,                   // numChannels
        0,                   // outmode
        86,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 87))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5120,                // numPoints
        2,                   // numChannels
        0,                   // outmode
        87,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 88))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        4,                   // numChannels
        0,                   // outmode
        88,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 89))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        4,                   // numChannels
        0,                   // outmode
        89,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 90))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        4,                   // numChannels
        0,                   // outmode
        90,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 91))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        4,                   // numChannels
        0,                   // outmode
        91,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 92))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5120,                // numPoints
        4,                   // numChannels
        0,                   // outmode
        92,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 93))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        8,                   // numChannels
        0,                   // outmode
        93,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 94))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        8,                   // numChannels
        0,                   // outmode
        94,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 95))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        8,                   // numChannels
        0,                   // outmode
        95,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 96))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        8,                   // numChannels
        0,                   // outmode
        96,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 97))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        8,                   // numChannels
        0,                   // outmode
        97,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 98))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        16,                  // numChannels
        0,                   // outmode
        98,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 99))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        16,                  // numChannels
        0,                   // outmode
        99,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 100))
    {
        STATIC,              // test pattern
        staticRefIn100,      // staticIn
        staticRefOut100,     // staticOut
        6,                   // numPoints
        1,                   // numChannels
        1,                   // outmode
        100,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 101))
    {
        STATIC,              // test pattern
        staticRefIn101,      // staticIn
        staticRefOut101,     // staticOut
        162,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        101,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 102))
    {
        STATIC,              // test pattern
        staticRefIn102,      // staticIn
        staticRefOut102,     // staticOut
        486,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        102,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 103))
    {
        STATIC,              // test pattern
        staticRefIn103,      // staticIn
        staticRefOut103,     // staticOut
        192,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        103,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 104))
    {
        STATIC,              // test pattern
        staticRefIn104,      // staticIn
        staticRefOut104,     // staticOut
        384,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        104,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 105))
    {
        STATIC,              // test pattern
        staticRefIn105,      // staticIn
        staticRefOut105,     // staticOut
        768,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        105,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 106))
    {
        STATIC,              // test pattern
        staticRefIn106,      // staticIn
        staticRefOut106,     // staticOut
        1152,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        106,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 107))
    {
        STATIC,              // test pattern
        staticRefIn107,      // staticIn
        staticRefOut107,     // staticOut
        2304,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        107,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 108))
    {
        STATIC,              // test pattern
        staticRefIn108,      // staticIn
        staticRefOut108,     // staticOut
        1728,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        108,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 109))
    {
        STATIC,              // test pattern
        staticRefIn109,      // staticIn
        staticRefOut109,     // staticOut
        3456,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        109,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 110))
    {
        STATIC,              // test pattern
        staticRefIn110,      // staticIn
        staticRefOut110,     // staticOut
        5184,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        110,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 111))
    {
        STATIC,              // test pattern
        staticRefIn111,      // staticIn
        staticRefOut111,     // staticOut
        30,                  // numPoints
        1,                   // numChannels
        1,                   // outmode
        111,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 112))
    {
        STATIC,              // test pattern
        staticRefIn112,      // staticIn
        staticRefOut112,     // staticOut
        90,                  // numPoints
        1,                   // numChannels
        1,                   // outmode
        112,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 113))
    {
        STATIC,              // test pattern
        staticRefIn113,      // staticIn
        staticRefOut113,     // staticOut
        270,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        113,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 114))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1920,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        114,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 115))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        115,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 116))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        116,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 117))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        117,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 118))
    {
        STATIC,              // test pattern
        staticRefIn118,      // staticIn
        staticRefOut118,     // staticOut
        18,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        118,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 119))
    {
        STATIC,              // test pattern
        staticRefIn119,      // staticIn
        staticRefOut119,     // staticOut
        54,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        119,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 120))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        192,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        120,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 121))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        384,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        121,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 122))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        768,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        122,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 123))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        123,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 124))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2304,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        124,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 125))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1728,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        125,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 126))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3456,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        126,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 127))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        127,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 128))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        30,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        128,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 129))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        90,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        129,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 130))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        270,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        130,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 131))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1920,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        131,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 132))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        132,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 133))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        133,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 134))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        134,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 135))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        18,                  // numPoints
        8,                   // numChannels
        1,                   // outmode
        135,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 136))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        54,                  // numPoints
        8,                   // numChannels
        1,                   // outmode
        136,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 137))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        162,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        137,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 138))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        486,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        138,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 139))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        192,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        139,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 140))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        384,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        140,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 141))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        768,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        141,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 142))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        142,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 143))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2304,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        143,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 144))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1728,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        144,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 145))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3456,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        145,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 146))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        146,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 147))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        30,                  // numPoints
        8,                   // numChannels
        1,                   // outmode
        147,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 148))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        90,                  // numPoints
        8,                   // numChannels
        1,                   // outmode
        148,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 149))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        270,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        149,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 150))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1920,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        150,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 151))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        151,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 152))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        152,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 153))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        153,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 154))
    {
        STATIC,              // test pattern
        staticRefIn154,      // staticIn
        staticRefOut154,     // staticOut
        6,                   // numPoints
        1,                   // numChannels
        1,                   // outmode
        154,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 155))
    {
        STATIC,              // test pattern
        staticRefIn155,      // staticIn
        staticRefOut155,     // staticOut
        54,                  // numPoints
        1,                   // numChannels
        1,                   // outmode
        155,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 156))
    {
        STATIC,              // test pattern
        staticRefIn156,      // staticIn
        staticRefOut156,     // staticOut
        162,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        156,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 157))
    {
        STATIC,              // test pattern
        staticRefIn157,      // staticIn
        staticRefOut157,     // staticOut
        486,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        157,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 158))
    {
        STATIC,              // test pattern
        staticRefIn158,      // staticIn
        staticRefOut158,     // staticOut
        192,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        158,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 159))
    {
        STATIC,              // test pattern
        staticRefIn159,      // staticIn
        staticRefOut159,     // staticOut
        384,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        159,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 160))
    {
        STATIC,              // test pattern
        staticRefIn160,      // staticIn
        staticRefOut160,     // staticOut
        768,                 // numPoints
        1,                   // numChannels
        1,                   // outmode
        160,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 161))
    {
        STATIC,              // test pattern
        staticRefIn161,      // staticIn
        staticRefOut161,     // staticOut
        1152,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        161,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 162))
    {
        STATIC,              // test pattern
        staticRefIn162,      // staticIn
        staticRefOut162,     // staticOut
        2304,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        162,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 163))
    {
        STATIC,              // test pattern
        staticRefIn163,      // staticIn
        staticRefOut163,     // staticOut
        1728,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        163,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 164))
    {
        STATIC,              // test pattern
        staticRefIn164,      // staticIn
        staticRefOut164,     // staticOut
        3456,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        164,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 165))
    {
        STATIC,              // test pattern
        staticRefIn165,      // staticIn
        staticRefOut165,     // staticOut
        5184,                // numPoints
        1,                   // numChannels
        1,                   // outmode
        165,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 166))
    {
        STATIC,              // test pattern
        staticRefIn166,      // staticIn
        staticRefOut166,     // staticOut
        18,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        166,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 167))
    {
        STATIC,              // test pattern
        staticRefIn167,      // staticIn
        staticRefOut167,     // staticOut
        54,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        167,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 168))
    {
        STATIC,              // test pattern
        staticRefIn168,      // staticIn
        staticRefOut168,     // staticOut
        162,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        168,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 169))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        486,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        169,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 170))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        192,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        170,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 171))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        384,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        171,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 172))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        768,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        172,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 173))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        173,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 174))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        270,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        174,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 175))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1920,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        175,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 176))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        176,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 177))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        177,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 178))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        178,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 179))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        18,                  // numPoints
        8,                   // numChannels
        1,                   // outmode
        179,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 180))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        54,                  // numPoints
        8,                   // numChannels
        1,                   // outmode
        180,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 181))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        162,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        181,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 182))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        486,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        182,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 183))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        192,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        183,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 184))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        384,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        184,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 185))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        768,                 // numPoints
        8,                   // numChannels
        1,                   // outmode
        185,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 186))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        186,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 187))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2304,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        187,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 188))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1728,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        188,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 189))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3456,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        189,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 190))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        8,                   // numChannels
        1,                   // outmode
        190,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 191))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numPoints
        8,                   // numChannels
        1,                   // outmode
        191,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 192))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        100,                 // numPoints
        2,                   // numChannels
        1,                   // outmode
        192,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 193))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        36,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        193,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 194))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numPoints
        8,                   // numChannels
        1,                   // outmode
        194,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 195))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        200,                 // numPoints
        2,                   // numChannels
        1,                   // outmode
        195,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 196))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        72,                  // numPoints
        4,                   // numChannels
        1,                   // outmode
        196,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 197))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numPoints
        8,                   // numChannels
        1,                   // outmode
        197,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 198))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        400,                 // numPoints
        2,                   // numChannels
        1,                   // outmode
        198,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 199))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        144,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        199,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 200))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numPoints
        8,                   // numChannels
        1,                   // outmode
        200,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 201))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        800,                 // numPoints
        2,                   // numChannels
        1,                   // outmode
        201,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 202))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        288,                 // numPoints
        4,                   // numChannels
        1,                   // outmode
        202,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 203))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numPoints
        8,                   // numChannels
        0,                   // outmode
        203,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 204))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        100,                 // numPoints
        2,                   // numChannels
        0,                   // outmode
        204,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 205))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        36,                  // numPoints
        4,                   // numChannels
        0,                   // outmode
        205,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 206))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numPoints
        8,                   // numChannels
        0,                   // outmode
        206,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 207))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        200,                 // numPoints
        2,                   // numChannels
        0,                   // outmode
        207,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 208))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        72,                  // numPoints
        4,                   // numChannels
        0,                   // outmode
        208,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 209))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numPoints
        8,                   // numChannels
        0,                   // outmode
        209,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 210))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        400,                 // numPoints
        2,                   // numChannels
        0,                   // outmode
        210,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 211))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        144,                 // numPoints
        4,                   // numChannels
        0,                   // outmode
        211,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 212))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numPoints
        8,                   // numChannels
        0,                   // outmode
        212,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 213))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        800,                 // numPoints
        2,                   // numChannels
        0,                   // outmode
        213,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 214))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        288,                 // numPoints
        4,                   // numChannels
        0,                   // outmode
        214,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 215))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        31250,               // numPoints
        4,                   // numChannels
        1,                   // outmode
        215,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 216))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        13122,               // numPoints
        4,                   // numChannels
        1,                   // outmode
        216,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 217))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        39366,               // numPoints
        2,                   // numChannels
        1,                   // outmode
        217,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 218))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12500,               // numPoints
        4,                   // numChannels
        1,                   // outmode
        218,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 219))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        62500,               // numPoints
        2,                   // numChannels
        1,                   // outmode
        219,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 220))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8748,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        220,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 221))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        26244,               // numPoints
        2,                   // numChannels
        1,                   // outmode
        221,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 222))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12150,               // numPoints
        4,                   // numChannels
        1,                   // outmode
        222,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 223))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        21870,               // numPoints
        2,                   // numChannels
        1,                   // outmode
        223,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 224))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4860,                // numPoints
        4,                   // numChannels
        1,                   // outmode
        224,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 225))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        43740,               // numPoints
        2,                   // numChannels
        1,                   // outmode
        225,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 226))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        31250,               // numPoints
        4,                   // numChannels
        0,                   // outmode
        226,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 227))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        13122,               // numPoints
        4,                   // numChannels
        0,                   // outmode
        227,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 228))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        39366,               // numPoints
        2,                   // numChannels
        0,                   // outmode
        228,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 229))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12500,               // numPoints
        4,                   // numChannels
        0,                   // outmode
        229,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 230))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        62500,               // numPoints
        2,                   // numChannels
        0,                   // outmode
        230,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 231))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8748,                // numPoints
        4,                   // numChannels
        0,                   // outmode
        231,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 232))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        26244,               // numPoints
        2,                   // numChannels
        0,                   // outmode
        232,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 233))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12150,               // numPoints
        4,                   // numChannels
        0,                   // outmode
        233,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 234))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        21870,               // numPoints
        2,                   // numChannels
        0,                   // outmode
        234,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 235))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4860,                // numPoints
        4,                   // numChannels
        0,                   // outmode
        235,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 236))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        43740,               // numPoints
        2,                   // numChannels
        0,                   // outmode
        236,                 // test ID
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

/* ======================================================================== */
/*                       End of file                                        */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2017 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
