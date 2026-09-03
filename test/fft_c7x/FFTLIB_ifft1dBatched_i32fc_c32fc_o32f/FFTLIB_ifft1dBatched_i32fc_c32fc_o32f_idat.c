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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
#include "test_data/staticRefCase22.h"
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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 48))
#include "test_data/staticRefCase48.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 49))
#include "test_data/staticRefCase49.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 50))
#include "test_data/staticRefCase50.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 51))
#include "test_data/staticRefCase51.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 52))
#include "test_data/staticRefCase52.h"
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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
#include "test_data/staticRefCase59.h"
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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 74))
#include "test_data/staticRefCase74.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 75))
#include "test_data/staticRefCase75.h"
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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 87))
#include "test_data/staticRefCase87.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 88))
#include "test_data/staticRefCase88.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 89))
#include "test_data/staticRefCase89.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 95))
#include "test_data/staticRefCase95.h"
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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 166))
#include "test_data/staticRefCase166.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 167))
#include "test_data/staticRefCase167.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 168))
#include "test_data/staticRefCase168.h"
#endif

static ifft1dBatched_i32fc_c32fc_o32f_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        STATIC,              // test pattern
        staticRefIn1,        // staticIn
        staticRefOut1,       // staticOut
        128,                 // numPoints
        1,                   // numChannels
        1,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        STATIC,              // test pattern
        staticRefIn2,        // staticIn
        staticRefOut2,       // staticOut
        256,                 // numPoints
        1,                   // numChannels
        2,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        STATIC,              // test pattern
        staticRefIn3,        // staticIn
        staticRefOut3,       // staticOut
        512,                 // numPoints
        1,                   // numChannels
        3,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        STATIC,              // test pattern
        staticRefIn4,        // staticIn
        staticRefOut4,       // staticOut
        1024,                // numPoints
        1,                   // numChannels
        4,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        STATIC,              // test pattern
        staticRefIn5,        // staticIn
        staticRefOut5,       // staticOut
        2048,                // numPoints
        1,                   // numChannels
        5,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        STATIC,              // test pattern
        staticRefIn6,        // staticIn
        staticRefOut6,       // staticOut
        4096,                // numPoints
        1,                   // numChannels
        6,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        STATIC,              // test pattern
        staticRefIn7,        // staticIn
        staticRefOut7,       // staticOut
        8192,                // numPoints
        1,                   // numChannels
        7,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        STATIC,              // test pattern
        staticRefIn8,        // staticIn
        staticRefOut8,       // staticOut
        128,                 // numPoints
        2,                   // numChannels
        8,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        STATIC,              // test pattern
        staticRefIn9,        // staticIn
        staticRefOut9,       // staticOut
        256,                 // numPoints
        2,                   // numChannels
        9,                   // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        STATIC,              // test pattern
        staticRefIn10,       // staticIn
        staticRefOut10,      // staticOut
        512,                 // numPoints
        2,                   // numChannels
        10,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        STATIC,              // test pattern
        staticRefIn11,       // staticIn
        staticRefOut11,      // staticOut
        1024,                // numPoints
        2,                   // numChannels
        11,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        STATIC,              // test pattern
        staticRefIn12,       // staticIn
        staticRefOut12,      // staticOut
        2048,                // numPoints
        2,                   // numChannels
        12,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        STATIC,              // test pattern
        staticRefIn13,       // staticIn
        staticRefOut13,      // staticOut
        4096,                // numPoints
        2,                   // numChannels
        13,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        STATIC,              // test pattern
        staticRefIn14,       // staticIn
        staticRefOut14,      // staticOut
        8192,                // numPoints
        2,                   // numChannels
        14,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        STATIC,              // test pattern
        staticRefIn15,       // staticIn
        staticRefOut15,      // staticOut
        128,                 // numPoints
        4,                   // numChannels
        15,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        STATIC,              // test pattern
        staticRefIn16,       // staticIn
        staticRefOut16,      // staticOut
        256,                 // numPoints
        4,                   // numChannels
        16,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        STATIC,              // test pattern
        staticRefIn17,       // staticIn
        staticRefOut17,      // staticOut
        512,                 // numPoints
        4,                   // numChannels
        17,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        STATIC,              // test pattern
        staticRefIn18,       // staticIn
        staticRefOut18,      // staticOut
        1024,                // numPoints
        4,                   // numChannels
        18,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2048,                // numPoints
        4,                   // numChannels
        19,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4096,                // numPoints
        4,                   // numChannels
        20,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8192,                // numPoints
        4,                   // numChannels
        21,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        STATIC,              // test pattern
        staticRefIn22,       // staticIn
        staticRefOut22,      // staticOut
        128,                 // numPoints
        16,                  // numChannels
        22,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        256,                 // numPoints
        16,                  // numChannels
        23,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        512,                 // numPoints
        16,                  // numChannels
        24,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1024,                // numPoints
        16,                  // numChannels
        25,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2048,                // numPoints
        16,                  // numChannels
        26,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        STATIC,              // test pattern
        staticRefIn27,       // staticIn
        staticRefOut27,      // staticOut
        128,                 // numPoints
        1,                   // numChannels
        27,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        STATIC,              // test pattern
        staticRefIn28,       // staticIn
        staticRefOut28,      // staticOut
        256,                 // numPoints
        1,                   // numChannels
        28,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        STATIC,              // test pattern
        staticRefIn29,       // staticIn
        staticRefOut29,      // staticOut
        512,                 // numPoints
        1,                   // numChannels
        29,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        STATIC,              // test pattern
        staticRefIn30,       // staticIn
        staticRefOut30,      // staticOut
        1024,                // numPoints
        1,                   // numChannels
        30,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        STATIC,              // test pattern
        staticRefIn31,       // staticIn
        staticRefOut31,      // staticOut
        2048,                // numPoints
        1,                   // numChannels
        31,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        STATIC,              // test pattern
        staticRefIn32,       // staticIn
        staticRefOut32,      // staticOut
        4096,                // numPoints
        1,                   // numChannels
        32,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        STATIC,              // test pattern
        staticRefIn33,       // staticIn
        staticRefOut33,      // staticOut
        8192,                // numPoints
        1,                   // numChannels
        33,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        STATIC,              // test pattern
        staticRefIn34,       // staticIn
        staticRefOut34,      // staticOut
        128,                 // numPoints
        2,                   // numChannels
        34,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        STATIC,              // test pattern
        staticRefIn35,       // staticIn
        staticRefOut35,      // staticOut
        256,                 // numPoints
        2,                   // numChannels
        35,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        STATIC,              // test pattern
        staticRefIn36,       // staticIn
        staticRefOut36,      // staticOut
        512,                 // numPoints
        2,                   // numChannels
        36,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        STATIC,              // test pattern
        staticRefIn37,       // staticIn
        staticRefOut37,      // staticOut
        1024,                // numPoints
        2,                   // numChannels
        37,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        STATIC,              // test pattern
        staticRefIn38,       // staticIn
        staticRefOut38,      // staticOut
        2048,                // numPoints
        2,                   // numChannels
        38,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        STATIC,              // test pattern
        staticRefIn39,       // staticIn
        staticRefOut39,      // staticOut
        4096,                // numPoints
        2,                   // numChannels
        39,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        STATIC,              // test pattern
        staticRefIn40,       // staticIn
        staticRefOut40,      // staticOut
        8192,                // numPoints
        2,                   // numChannels
        40,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
    {
        STATIC,              // test pattern
        staticRefIn41,       // staticIn
        staticRefOut41,      // staticOut
        128,                 // numPoints
        4,                   // numChannels
        41,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
    {
        STATIC,              // test pattern
        staticRefIn42,       // staticIn
        staticRefOut42,      // staticOut
        256,                 // numPoints
        4,                   // numChannels
        42,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
    {
        STATIC,              // test pattern
        staticRefIn43,       // staticIn
        staticRefOut43,      // staticOut
        512,                 // numPoints
        4,                   // numChannels
        43,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 44))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1024,                // numPoints
        4,                   // numChannels
        44,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 45))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2048,                // numPoints
        4,                   // numChannels
        45,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 46))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4096,                // numPoints
        4,                   // numChannels
        46,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 47))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8192,                // numPoints
        4,                   // numChannels
        47,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 48))
    {
        STATIC,              // test pattern
        staticRefIn48,       // staticIn
        staticRefOut48,      // staticOut
        128,                 // numPoints
        16,                  // numChannels
        48,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 49))
    {
        STATIC,              // test pattern
        staticRefIn49,       // staticIn
        staticRefOut49,      // staticOut
        256,                 // numPoints
        16,                  // numChannels
        49,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 50))
    {
        STATIC,              // test pattern
        staticRefIn50,       // staticIn
        staticRefOut50,      // staticOut
        10,                  // numPoints
        1,                   // numChannels
        50,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 51))
    {
        STATIC,              // test pattern
        staticRefIn51,       // staticIn
        staticRefOut51,      // staticOut
        50,                  // numPoints
        1,                   // numChannels
        51,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 52))
    {
        STATIC,              // test pattern
        staticRefIn52,       // staticIn
        staticRefOut52,      // staticOut
        250,                 // numPoints
        1,                   // numChannels
        52,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 53))
    {
        STATIC,              // test pattern
        staticRefIn53,       // staticIn
        staticRefOut53,      // staticOut
        1250,                // numPoints
        1,                   // numChannels
        53,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 54))
    {
        STATIC,              // test pattern
        staticRefIn54,       // staticIn
        staticRefOut54,      // staticOut
        6250,                // numPoints
        1,                   // numChannels
        54,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 55))
    {
        STATIC,              // test pattern
        staticRefIn55,       // staticIn
        staticRefOut55,      // staticOut
        50,                  // numPoints
        4,                   // numChannels
        55,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 56))
    {
        STATIC,              // test pattern
        staticRefIn56,       // staticIn
        staticRefOut56,      // staticOut
        250,                 // numPoints
        4,                   // numChannels
        56,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 57))
    {
        STATIC,              // test pattern
        staticRefIn57,       // staticIn
        staticRefOut57,      // staticOut
        1250,                // numPoints
        4,                   // numChannels
        57,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6250,                // numPoints
        4,                   // numChannels
        58,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
    {
        STATIC,              // test pattern
        staticRefIn59,       // staticIn
        staticRefOut59,      // staticOut
        10,                  // numPoints
        16,                  // numChannels
        59,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 60))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        250,                 // numPoints
        16,                  // numChannels
        60,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 61))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1250,                // numPoints
        16,                  // numChannels
        61,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 62))
    {
        STATIC,              // test pattern
        staticRefIn62,       // staticIn
        staticRefOut62,      // staticOut
        320,                 // numPoints
        1,                   // numChannels
        62,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 63))
    {
        STATIC,              // test pattern
        staticRefIn63,       // staticIn
        staticRefOut63,      // staticOut
        640,                 // numPoints
        1,                   // numChannels
        63,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 64))
    {
        STATIC,              // test pattern
        staticRefIn64,       // staticIn
        staticRefOut64,      // staticOut
        320,                 // numPoints
        2,                   // numChannels
        64,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 65))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        2,                   // numChannels
        65,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 66))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8000,                // numPoints
        2,                   // numChannels
        66,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 67))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        2,                   // numChannels
        67,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 68))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        2,                   // numChannels
        68,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 69))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        2,                   // numChannels
        69,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 70))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        2,                   // numChannels
        70,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 71))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2560,                // numPoints
        2,                   // numChannels
        71,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 72))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12800,               // numPoints
        2,                   // numChannels
        72,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 73))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5120,                // numPoints
        2,                   // numChannels
        73,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 74))
    {
        STATIC,              // test pattern
        staticRefIn74,       // staticIn
        staticRefOut74,      // staticOut
        320,                 // numPoints
        4,                   // numChannels
        74,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 75))
    {
        STATIC,              // test pattern
        staticRefIn75,       // staticIn
        staticRefOut75,      // staticOut
        640,                 // numPoints
        4,                   // numChannels
        75,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 76))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        4,                   // numChannels
        76,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 77))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6400,                // numPoints
        4,                   // numChannels
        77,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 78))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5120,                // numPoints
        4,                   // numChannels
        78,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 79))
    {
        STATIC,              // test pattern
        staticRefIn79,       // staticIn
        staticRefOut79,      // staticOut
        320,                 // numPoints
        8,                   // numChannels
        79,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 80))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        8,                   // numChannels
        80,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 81))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        8,                   // numChannels
        81,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 82))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3200,                // numPoints
        8,                   // numChannels
        82,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 83))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        8,                   // numChannels
        83,                  // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 84))
    {
        STATIC,              // test pattern
        staticRefIn84,       // staticIn
        staticRefOut84,      // staticOut
        10,                  // numPoints
        1,                   // numChannels
        84,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 85))
    {
        STATIC,              // test pattern
        staticRefIn85,       // staticIn
        staticRefOut85,      // staticOut
        50,                  // numPoints
        1,                   // numChannels
        85,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 86))
    {
        STATIC,              // test pattern
        staticRefIn86,       // staticIn
        staticRefOut86,      // staticOut
        250,                 // numPoints
        1,                   // numChannels
        86,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 87))
    {
        STATIC,              // test pattern
        staticRefIn87,       // staticIn
        staticRefOut87,      // staticOut
        1250,                // numPoints
        1,                   // numChannels
        87,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 88))
    {
        STATIC,              // test pattern
        staticRefIn88,       // staticIn
        staticRefOut88,      // staticOut
        6250,                // numPoints
        1,                   // numChannels
        88,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 89))
    {
        STATIC,              // test pattern
        staticRefIn89,       // staticIn
        staticRefOut89,      // staticOut
        50,                  // numPoints
        4,                   // numChannels
        89,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 90))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        250,                 // numPoints
        4,                   // numChannels
        90,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 91))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1250,                // numPoints
        4,                   // numChannels
        91,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 92))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6250,                // numPoints
        4,                   // numChannels
        92,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 93))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        10,                  // numPoints
        16,                  // numChannels
        93,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 94))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1250,                // numPoints
        16,                  // numChannels
        94,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 95))
    {
        STATIC,              // test pattern
        staticRefIn95,       // staticIn
        staticRefOut95,      // staticOut
        320,                 // numPoints
        1,                   // numChannels
        95,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 96))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        320,                 // numPoints
        2,                   // numChannels
        96,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 97))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1600,                // numPoints
        2,                   // numChannels
        97,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 98))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        640,                 // numPoints
        2,                   // numChannels
        98,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 99))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1280,                // numPoints
        2,                   // numChannels
        99,                  // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 100))
    {
        STATIC,              // test pattern
        staticRefIn100,      // staticIn
        staticRefOut100,     // staticOut
        6,                   // numPoints
        1,                   // numChannels
        100,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 101))
    {
        STATIC,              // test pattern
        staticRefIn101,      // staticIn
        staticRefOut101,     // staticOut
        162,                 // numPoints
        1,                   // numChannels
        101,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 102))
    {
        STATIC,              // test pattern
        staticRefIn102,      // staticIn
        staticRefOut102,     // staticOut
        486,                 // numPoints
        1,                   // numChannels
        102,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 103))
    {
        STATIC,              // test pattern
        staticRefIn103,      // staticIn
        staticRefOut103,     // staticOut
        192,                 // numPoints
        1,                   // numChannels
        103,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 104))
    {
        STATIC,              // test pattern
        staticRefIn104,      // staticIn
        staticRefOut104,     // staticOut
        384,                 // numPoints
        1,                   // numChannels
        104,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 105))
    {
        STATIC,              // test pattern
        staticRefIn105,      // staticIn
        staticRefOut105,     // staticOut
        768,                 // numPoints
        1,                   // numChannels
        105,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 106))
    {
        STATIC,              // test pattern
        staticRefIn106,      // staticIn
        staticRefOut106,     // staticOut
        1152,                // numPoints
        1,                   // numChannels
        106,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 107))
    {
        STATIC,              // test pattern
        staticRefIn107,      // staticIn
        staticRefOut107,     // staticOut
        2304,                // numPoints
        1,                   // numChannels
        107,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 108))
    {
        STATIC,              // test pattern
        staticRefIn108,      // staticIn
        staticRefOut108,     // staticOut
        1728,                // numPoints
        1,                   // numChannels
        108,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 109))
    {
        STATIC,              // test pattern
        staticRefIn109,      // staticIn
        staticRefOut109,     // staticOut
        3456,                // numPoints
        1,                   // numChannels
        109,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 110))
    {
        STATIC,              // test pattern
        staticRefIn110,      // staticIn
        staticRefOut110,     // staticOut
        5184,                // numPoints
        1,                   // numChannels
        110,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 111))
    {
        STATIC,              // test pattern
        staticRefIn111,      // staticIn
        staticRefOut111,     // staticOut
        30,                  // numPoints
        1,                   // numChannels
        111,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 112))
    {
        STATIC,              // test pattern
        staticRefIn112,      // staticIn
        staticRefOut112,     // staticOut
        90,                  // numPoints
        1,                   // numChannels
        112,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 113))
    {
        STATIC,              // test pattern
        staticRefIn113,      // staticIn
        staticRefOut113,     // staticOut
        270,                 // numPoints
        1,                   // numChannels
        113,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 114))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1920,                // numPoints
        1,                   // numChannels
        114,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 115))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        1,                   // numChannels
        115,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 116))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        1,                   // numChannels
        116,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 117))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        1,                   // numChannels
        117,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 118))
    {
        STATIC,              // test pattern
        staticRefIn118,      // staticIn
        staticRefOut118,     // staticOut
        18,                  // numPoints
        4,                   // numChannels
        118,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 119))
    {
        STATIC,              // test pattern
        staticRefIn119,      // staticIn
        staticRefOut119,     // staticOut
        54,                  // numPoints
        4,                   // numChannels
        119,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 120))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        192,                 // numPoints
        4,                   // numChannels
        120,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 121))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        384,                 // numPoints
        4,                   // numChannels
        121,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 122))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        768,                 // numPoints
        4,                   // numChannels
        122,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 123))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        4,                   // numChannels
        123,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 124))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2304,                // numPoints
        4,                   // numChannels
        124,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 125))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1728,                // numPoints
        4,                   // numChannels
        125,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 126))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3456,                // numPoints
        4,                   // numChannels
        126,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 127))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        4,                   // numChannels
        127,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 128))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        30,                  // numPoints
        4,                   // numChannels
        128,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 129))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        90,                  // numPoints
        4,                   // numChannels
        129,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 130))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        270,                 // numPoints
        4,                   // numChannels
        130,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 131))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1920,                // numPoints
        4,                   // numChannels
        131,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 132))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        4,                   // numChannels
        132,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 133))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        4,                   // numChannels
        133,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 134))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        4,                   // numChannels
        134,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 135))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        18,                  // numPoints
        8,                   // numChannels
        135,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 136))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        54,                  // numPoints
        8,                   // numChannels
        136,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 137))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        162,                 // numPoints
        8,                   // numChannels
        137,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 138))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        486,                 // numPoints
        8,                   // numChannels
        138,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 139))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        192,                 // numPoints
        8,                   // numChannels
        139,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 140))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        384,                 // numPoints
        8,                   // numChannels
        140,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 141))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        768,                 // numPoints
        8,                   // numChannels
        141,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 142))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        8,                   // numChannels
        142,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 143))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2304,                // numPoints
        8,                   // numChannels
        143,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 144))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1728,                // numPoints
        8,                   // numChannels
        144,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 145))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3456,                // numPoints
        8,                   // numChannels
        145,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 146))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        8,                   // numChannels
        146,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 147))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        30,                  // numPoints
        8,                   // numChannels
        147,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 148))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        90,                  // numPoints
        8,                   // numChannels
        148,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 149))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        270,                 // numPoints
        8,                   // numChannels
        149,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 150))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1920,                // numPoints
        8,                   // numChannels
        150,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 151))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        8,                   // numChannels
        151,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 152))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        8,                   // numChannels
        152,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 153))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        8,                   // numChannels
        153,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 154))
    {
        STATIC,              // test pattern
        staticRefIn154,      // staticIn
        staticRefOut154,     // staticOut
        6,                   // numPoints
        1,                   // numChannels
        154,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 155))
    {
        STATIC,              // test pattern
        staticRefIn155,      // staticIn
        staticRefOut155,     // staticOut
        54,                  // numPoints
        1,                   // numChannels
        155,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 156))
    {
        STATIC,              // test pattern
        staticRefIn156,      // staticIn
        staticRefOut156,     // staticOut
        162,                 // numPoints
        1,                   // numChannels
        156,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 157))
    {
        STATIC,              // test pattern
        staticRefIn157,      // staticIn
        staticRefOut157,     // staticOut
        486,                 // numPoints
        1,                   // numChannels
        157,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 158))
    {
        STATIC,              // test pattern
        staticRefIn158,      // staticIn
        staticRefOut158,     // staticOut
        192,                 // numPoints
        1,                   // numChannels
        158,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 159))
    {
        STATIC,              // test pattern
        staticRefIn159,      // staticIn
        staticRefOut159,     // staticOut
        384,                 // numPoints
        1,                   // numChannels
        159,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 160))
    {
        STATIC,              // test pattern
        staticRefIn160,      // staticIn
        staticRefOut160,     // staticOut
        768,                 // numPoints
        1,                   // numChannels
        160,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 161))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        1,                   // numChannels
        161,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 162))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2304,                // numPoints
        1,                   // numChannels
        162,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 163))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1728,                // numPoints
        1,                   // numChannels
        163,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 164))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3456,                // numPoints
        1,                   // numChannels
        164,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 165))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        1,                   // numChannels
        165,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 166))
    {
        STATIC,              // test pattern
        staticRefIn166,      // staticIn
        staticRefOut166,     // staticOut
        18,                  // numPoints
        4,                   // numChannels
        166,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 167))
    {
        STATIC,              // test pattern
        staticRefIn167,      // staticIn
        staticRefOut167,     // staticOut
        54,                  // numPoints
        4,                   // numChannels
        167,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 168))
    {
        STATIC,              // test pattern
        staticRefIn168,      // staticIn
        staticRefOut168,     // staticOut
        162,                 // numPoints
        4,                   // numChannels
        168,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 169))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        486,                 // numPoints
        4,                   // numChannels
        169,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 170))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        192,                 // numPoints
        4,                   // numChannels
        170,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 171))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        384,                 // numPoints
        4,                   // numChannels
        171,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 172))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        768,                 // numPoints
        4,                   // numChannels
        172,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 173))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        4,                   // numChannels
        173,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 174))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        270,                 // numPoints
        4,                   // numChannels
        174,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 175))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1920,                // numPoints
        4,                   // numChannels
        175,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 176))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        4,                   // numChannels
        176,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 177))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        4,                   // numChannels
        177,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 178))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        4,                   // numChannels
        178,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 179))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        18,                  // numPoints
        8,                   // numChannels
        179,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 180))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        54,                  // numPoints
        8,                   // numChannels
        180,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 181))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        162,                 // numPoints
        8,                   // numChannels
        181,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 182))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        486,                 // numPoints
        8,                   // numChannels
        182,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 183))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        192,                 // numPoints
        8,                   // numChannels
        183,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 184))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        384,                 // numPoints
        8,                   // numChannels
        184,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 185))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        768,                 // numPoints
        8,                   // numChannels
        185,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 186))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1152,                // numPoints
        8,                   // numChannels
        186,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 187))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2304,                // numPoints
        8,                   // numChannels
        187,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 188))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1728,                // numPoints
        8,                   // numChannels
        188,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 189))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3456,                // numPoints
        8,                   // numChannels
        189,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 190))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        8,                   // numChannels
        190,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 191))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numPoints
        8,                   // numChannels
        191,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 192))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        100,                 // numPoints
        2,                   // numChannels
        192,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 193))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        36,                  // numPoints
        4,                   // numChannels
        193,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 194))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numPoints
        8,                   // numChannels
        194,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 195))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        200,                 // numPoints
        2,                   // numChannels
        195,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 196))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        72,                  // numPoints
        4,                   // numChannels
        196,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 197))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numPoints
        8,                   // numChannels
        197,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 198))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        400,                 // numPoints
        2,                   // numChannels
        198,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 199))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        144,                 // numPoints
        4,                   // numChannels
        199,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 200))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numPoints
        8,                   // numChannels
        200,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 201))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        800,                 // numPoints
        2,                   // numChannels
        201,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 202))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        288,                 // numPoints
        4,                   // numChannels
        202,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 203))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numPoints
        8,                   // numChannels
        203,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 204))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        100,                 // numPoints
        2,                   // numChannels
        204,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 205))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        36,                  // numPoints
        4,                   // numChannels
        205,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 206))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numPoints
        8,                   // numChannels
        206,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 207))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        200,                 // numPoints
        2,                   // numChannels
        207,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 208))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        72,                  // numPoints
        4,                   // numChannels
        208,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 209))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numPoints
        8,                   // numChannels
        209,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 210))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        400,                 // numPoints
        2,                   // numChannels
        210,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 211))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        144,                 // numPoints
        4,                   // numChannels
        211,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 212))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numPoints
        8,                   // numChannels
        212,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 213))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        800,                 // numPoints
        2,                   // numChannels
        213,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 214))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        288,                 // numPoints
        4,                   // numChannels
        214,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 215))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        31250,               // numPoints
        4,                   // numChannels
        215,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 216))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        13122,               // numPoints
        4,                   // numChannels
        216,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 217))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        39366,               // numPoints
        2,                   // numChannels
        217,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 218))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12500,               // numPoints
        4,                   // numChannels
        218,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 219))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        62500,               // numPoints
        2,                   // numChannels
        219,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 220))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8748,                // numPoints
        4,                   // numChannels
        220,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 221))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        26244,               // numPoints
        2,                   // numChannels
        221,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 222))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12150,               // numPoints
        4,                   // numChannels
        222,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 223))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        21870,               // numPoints
        2,                   // numChannels
        223,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 224))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4860,                // numPoints
        4,                   // numChannels
        224,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 225))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        43740,               // numPoints
        2,                   // numChannels
        225,                 // test ID
        1,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 226))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        31250,               // numPoints
        4,                   // numChannels
        226,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 227))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        13122,               // numPoints
        4,                   // numChannels
        227,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 228))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        39366,               // numPoints
        2,                   // numChannels
        228,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 229))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12500,               // numPoints
        4,                   // numChannels
        229,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 230))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        62500,               // numPoints
        2,                   // numChannels
        230,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 231))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8748,                // numPoints
        4,                   // numChannels
        231,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 232))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        26244,               // numPoints
        2,                   // numChannels
        232,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 233))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        12150,               // numPoints
        4,                   // numChannels
        233,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 234))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        21870,               // numPoints
        2,                   // numChannels
        234,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 235))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4860,                // numPoints
        4,                   // numChannels
        235,                 // test ID
        0,                   // inMode
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 236))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        43740,               // numPoints
        2,                   // numChannels
        236,                 // test ID
        0,                   // inMode
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void ifft1dBatched_i32fc_c32fc_o32f_getTestParams(ifft1dBatched_i32fc_c32fc_o32f_testParams_t** params, int32_t* numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(ifft1dBatched_i32fc_c32fc_o32f_testParams_t);
}
