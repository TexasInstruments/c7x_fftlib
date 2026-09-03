// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0


#include "FFTLIB_fft1d_i32f_c32fc_o32fc_idat.h"

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

static fft1d_i32f_c32fc_o32fc_testParams_t testParams[] = {

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
        128,                 // numPoints
        2,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        STATIC,              // test pattern
        staticRefIn3,        // staticIn
        staticRefOut3,       // staticOut
        256,                 // numPoints
        3,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        STATIC,              // test pattern
        staticRefIn4,        // staticIn
        staticRefOut4,       // staticOut
        512,                 // numPoints
        4,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        STATIC,              // test pattern
        staticRefIn5,        // staticIn
        staticRefOut5,       // staticOut
        1024,                // numPoints
        5,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        STATIC,              // test pattern
        staticRefIn6,        // staticIn
        staticRefOut6,       // staticOut
        2048,                // numPoints
        6,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        STATIC,              // test pattern
        staticRefIn7,        // staticIn
        staticRefOut7,       // staticOut
        4096,                // numPoints
        7,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        STATIC,              // test pattern
        staticRefIn8,        // staticIn
        staticRefOut8,       // staticOut
        8192,                // numPoints
        8,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        STATIC,              // test pattern
        staticRefIn9,        // staticIn
        staticRefOut9,       // staticOut
        10,                  // numPoints
        9,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        STATIC,              // test pattern
        staticRefIn10,       // staticIn
        staticRefOut10,      // staticOut
        50,                  // numPoints
        10,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        STATIC,              // test pattern
        staticRefIn11,       // staticIn
        staticRefOut11,      // staticOut
        250,                 // numPoints
        11,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        STATIC,              // test pattern
        staticRefIn12,       // staticIn
        staticRefOut12,      // staticOut
        1250,                // numPoints
        12,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        STATIC,              // test pattern
        staticRefIn13,       // staticIn
        staticRefOut13,      // staticOut
        6250,                // numPoints
        13,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        STATIC,              // test pattern
        staticRefIn14,       // staticIn
        staticRefOut14,      // staticOut
        320,                 // numPoints
        14,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        STATIC,              // test pattern
        staticRefIn15,       // staticIn
        staticRefOut15,      // staticOut
        1600,                // numPoints
        15,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        STATIC,              // test pattern
        staticRefIn16,       // staticIn
        staticRefOut16,      // staticOut
        8000,                // numPoints
        16,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        STATIC,              // test pattern
        staticRefIn17,       // staticIn
        staticRefOut17,      // staticOut
        640,                 // numPoints
        17,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        STATIC,              // test pattern
        staticRefIn18,       // staticIn
        staticRefOut18,      // staticOut
        3200,                // numPoints
        18,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        STATIC,              // test pattern
        staticRefIn19,       // staticIn
        staticRefOut19,      // staticOut
        16000,               // numPoints
        19,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        STATIC,              // test pattern
        staticRefIn20,       // staticIn
        staticRefOut20,      // staticOut
        1280,                // numPoints
        20,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        STATIC,              // test pattern
        staticRefIn21,       // staticIn
        staticRefOut21,      // staticOut
        6400,                // numPoints
        21,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        STATIC,              // test pattern
        staticRefIn22,       // staticIn
        staticRefOut22,      // staticOut
        32000,               // numPoints
        22,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        STATIC,              // test pattern
        staticRefIn23,       // staticIn
        staticRefOut23,      // staticOut
        2560,                // numPoints
        23,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        STATIC,              // test pattern
        staticRefIn24,       // staticIn
        staticRefOut24,      // staticOut
        12800,               // numPoints
        24,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        STATIC,              // test pattern
        staticRefIn25,       // staticIn
        staticRefOut25,      // staticOut
        5120,                // numPoints
        25,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        STATIC,              // test pattern
        staticRefIn26,       // staticIn
        staticRefOut26,      // staticOut
        6,                   // numPoints
        26,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        STATIC,              // test pattern
        staticRefIn27,       // staticIn
        staticRefOut27,      // staticOut
        18,                  // numPoints
        27,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        STATIC,              // test pattern
        staticRefIn28,       // staticIn
        staticRefOut28,      // staticOut
        54,                  // numPoints
        28,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        STATIC,              // test pattern
        staticRefIn29,       // staticIn
        staticRefOut29,      // staticOut
        162,                 // numPoints
        29,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        STATIC,              // test pattern
        staticRefIn30,       // staticIn
        staticRefOut30,      // staticOut
        486,                 // numPoints
        30,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        STATIC,              // test pattern
        staticRefIn31,       // staticIn
        staticRefOut31,      // staticOut
        192,                 // numPoints
        31,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        STATIC,              // test pattern
        staticRefIn32,       // staticIn
        staticRefOut32,      // staticOut
        384,                 // numPoints
        32,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        STATIC,              // test pattern
        staticRefIn33,       // staticIn
        staticRefOut33,      // staticOut
        768,                 // numPoints
        33,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        STATIC,              // test pattern
        staticRefIn34,       // staticIn
        staticRefOut34,      // staticOut
        1536,                // numPoints
        34,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        STATIC,              // test pattern
        staticRefIn35,       // staticIn
        staticRefOut35,      // staticOut
        3072,                // numPoints
        35,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        STATIC,              // test pattern
        staticRefIn36,       // staticIn
        staticRefOut36,      // staticOut
        576,                 // numPoints
        36,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        STATIC,              // test pattern
        staticRefIn37,       // staticIn
        staticRefOut37,      // staticOut
        1152,                // numPoints
        37,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2304,                // numPoints
        38,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4608,                // numPoints
        39,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        9216,                // numPoints
        40,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1728,                // numPoints
        41,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3456,                // numPoints
        42,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6912,                // numPoints
        43,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 44))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        13824,               // numPoints
        44,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 45))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        27648,               // numPoints
        45,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 46))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5184,                // numPoints
        46,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 47))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        10368,               // numPoints
        47,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 48))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        20736,               // numPoints
        48,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 49))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        41472,               // numPoints
        49,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 50))
    {
        STATIC,              // test pattern
        staticRefIn50,       // staticIn
        staticRefOut50,      // staticOut
        30,                  // numPoints
        50,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 51))
    {
        STATIC,              // test pattern
        staticRefIn51,       // staticIn
        staticRefOut51,      // staticOut
        90,                  // numPoints
        51,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 52))
    {
        STATIC,              // test pattern
        staticRefIn52,       // staticIn
        staticRefOut52,      // staticOut
        270,                 // numPoints
        52,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 53))
    {
        STATIC,              // test pattern
        staticRefIn53,       // staticIn
        staticRefOut53,      // staticOut
        810,                 // numPoints
        53,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 54))
    {
        STATIC,              // test pattern
        staticRefIn54,       // staticIn
        staticRefOut54,      // staticOut
        960,                 // numPoints
        54,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 55))
    {
        STATIC,              // test pattern
        staticRefIn55,       // staticIn
        staticRefOut55,      // staticOut
        1920,                // numPoints
        55,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 56))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        3840,                // numPoints
        56,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 57))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        7680,                // numPoints
        57,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        15360,               // numPoints
        58,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2880,                // numPoints
        59,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 60))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        5760,                // numPoints
        60,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 61))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        11520,               // numPoints
        61,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 62))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        23040,               // numPoints
        62,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 63))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8640,                // numPoints
        63,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 64))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        17280,               // numPoints
        64,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 65))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        34560,               // numPoints
        65,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 66))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        25920,               // numPoints
        66,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 67))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        150,                 // numPoints
        67,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 68))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        450,                 // numPoints
        68,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 69))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1350,                // numPoints
        69,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 70))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4050,                // numPoints
        70,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 71))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4800,                // numPoints
        71,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 72))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        9600,                // numPoints
        72,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 73))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        19200,               // numPoints
        73,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 74))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        14400,               // numPoints
        74,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 75))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        28800,               // numPoints
        75,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 76))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        750,                 // numPoints
        76,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 77))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2250,                // numPoints
        77,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 78))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        6750,                // numPoints
        78,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 79))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        20250,               // numPoints
        79,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 80))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        24000,               // numPoints
        80,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 81))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numPoints
        81,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 82))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        100,                 // numPoints
        82,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 83))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        36,                  // numPoints
        83,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 84))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numPoints
        84,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 85))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        200,                 // numPoints
        85,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 86))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        72,                  // numPoints
        86,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 87))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numPoints
        87,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 88))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        400,                 // numPoints
        88,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 89))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        144,                 // numPoints
        89,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 90))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numPoints
        90,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 91))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        800,                 // numPoints
        91,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 92))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        288,                 // numPoints
        92,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 93))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        156250,              // numPoints
        93,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 94))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4374,                // numPoints
        94,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 95))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        39366,               // numPoints
        95,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 96))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        62500,               // numPoints
        96,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 97))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8748,                // numPoints
        97,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 98))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        26244,               // numPoints
        98,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 99))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        65610,               // numPoints
        99,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 100))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        24300,               // numPoints
        100,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 101))
    {
        RANDOM,              // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        43740,               // numPoints
        101,                 // test ID
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void fft1d_i32f_c32fc_o32fc_getTestParams(fft1d_i32f_c32fc_o32fc_testParams_t** params, int32_t* numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(fft1d_i32f_c32fc_o32fc_testParams_t);
}

/* ======================================================================== */
/*                       End of file                                        */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2017 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
