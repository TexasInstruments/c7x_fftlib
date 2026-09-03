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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
#include "test_data/staticRefCase58.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
#include "test_data/staticRefCase59.h"
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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 140))
#include "test_data/staticRefCase140.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 141))
#include "test_data/staticRefCase141.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 142))
#include "test_data/staticRefCase142.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 143))
#include "test_data/staticRefCase143.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 144))
#include "test_data/staticRefCase144.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 145))
#include "test_data/staticRefCase145.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 146))
#include "test_data/staticRefCase146.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 147))
#include "test_data/staticRefCase147.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 148))
#include "test_data/staticRefCase148.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 149))
#include "test_data/staticRefCase149.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 150))
#include "test_data/staticRefCase150.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 151))
#include "test_data/staticRefCase151.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 152))
#include "test_data/staticRefCase152.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 153))
#include "test_data/staticRefCase153.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 154))
#include "test_data/staticRefCase154.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 155))
#include "test_data/staticRefCase155.h"
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

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 169))
#include "test_data/staticRefCase169.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 170))
#include "test_data/staticRefCase170.h"
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 171))
#include "test_data/staticRefCase171.h"
#endif

static ifft1d_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numChannels
        16,                  // numPoints
        1,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 2))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        64,                  // numChannels
        16,                  // numPoints
        2,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 3))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        128,                 // numChannels
        16,                  // numPoints
        3,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        256,                 // numChannels
        16,                  // numPoints
        4,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        512,                 // numChannels
        16,                  // numPoints
        5,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numChannels
        32,                  // numPoints
        6,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        64,                  // numChannels
        32,                  // numPoints
        7,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        128,                 // numChannels
        32,                  // numPoints
        8,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        256,                 // numChannels
        32,                  // numPoints
        9,                   // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        512,                 // numChannels
        32,                  // numPoints
        10,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numChannels
        64,                  // numPoints
        11,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        64,                  // numChannels
        64,                  // numPoints
        12,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        128,                 // numChannels
        64,                  // numPoints
        13,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        256,                 // numChannels
        64,                  // numPoints
        14,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        128,                 // numPoints
        15,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numChannels
        128,                 // numPoints
        16,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        64,                  // numChannels
        128,                 // numPoints
        17,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        128,                 // numChannels
        128,                 // numPoints
        18,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        256,                 // numPoints
        19,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        256,                 // numPoints
        20,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numChannels
        256,                 // numPoints
        21,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        64,                  // numChannels
        256,                 // numPoints
        22,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        512,                 // numPoints
        23,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        512,                 // numPoints
        24,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        512,                 // numPoints
        25,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        32,                  // numChannels
        512,                 // numPoints
        26,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        1024,                // numPoints
        27,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        1024,                // numPoints
        28,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        1024,                // numPoints
        29,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        1024,                // numPoints
        30,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        2048,                // numPoints
        31,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        2048,                // numPoints
        32,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        2048,                // numPoints
        33,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        2048,                // numPoints
        34,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        4096,                // numPoints
        35,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        4096,                // numPoints
        36,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        4096,                // numPoints
        37,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        8192,                // numPoints
        38,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        8192,                // numPoints
        39,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        STATIC,              // test pattern
        staticRefIn40,       // staticIn
        staticRefOut40,      // staticOut
        1,                   // numChannels
        128,                 // numPoints
        40,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 41))
    {
        STATIC,              // test pattern
        staticRefIn41,       // staticIn
        staticRefOut41,      // staticOut
        2,                   // numChannels
        256,                 // numPoints
        41,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 42))
    {
        STATIC,              // test pattern
        staticRefIn42,       // staticIn
        staticRefOut42,      // staticOut
        4,                   // numChannels
        512,                 // numPoints
        42,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 43))
    {
        STATIC,              // test pattern
        staticRefIn43,       // staticIn
        staticRefOut43,      // staticOut
        8,                   // numChannels
        1024,                // numPoints
        43,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 44))
    {
        STATIC,              // test pattern
        staticRefIn44,       // staticIn
        staticRefOut44,      // staticOut
        1,                   // numChannels
        25,                  // numPoints
        44,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 45))
    {
        STATIC,              // test pattern
        staticRefIn45,       // staticIn
        staticRefOut45,      // staticOut
        1,                   // numChannels
        125,                 // numPoints
        45,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 46))
    {
        STATIC,              // test pattern
        staticRefIn46,       // staticIn
        staticRefOut46,      // staticOut
        1,                   // numChannels
        625,                 // numPoints
        46,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 47))
    {
        STATIC,              // test pattern
        staticRefIn47,       // staticIn
        staticRefOut47,      // staticOut
        1,                   // numChannels
        3125,                // numPoints
        47,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 48))
    {
        STATIC,              // test pattern
        staticRefIn48,       // staticIn
        staticRefOut48,      // staticOut
        2,                   // numChannels
        5,                   // numPoints
        48,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 49))
    {
        STATIC,              // test pattern
        staticRefIn49,       // staticIn
        staticRefOut49,      // staticOut
        2,                   // numChannels
        25,                  // numPoints
        49,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 50))
    {
        STATIC,              // test pattern
        staticRefIn50,       // staticIn
        staticRefOut50,      // staticOut
        2,                   // numChannels
        125,                 // numPoints
        50,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 51))
    {
        STATIC,              // test pattern
        staticRefIn51,       // staticIn
        staticRefOut51,      // staticOut
        2,                   // numChannels
        625,                 // numPoints
        51,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 52))
    {
        STATIC,              // test pattern
        staticRefIn52,       // staticIn
        staticRefOut52,      // staticOut
        2,                   // numChannels
        3125,                // numPoints
        52,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 53))
    {
        STATIC,              // test pattern
        staticRefIn53,       // staticIn
        staticRefOut53,      // staticOut
        4,                   // numChannels
        25,                  // numPoints
        53,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 54))
    {
        STATIC,              // test pattern
        staticRefIn54,       // staticIn
        staticRefOut54,      // staticOut
        4,                   // numChannels
        125,                 // numPoints
        54,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 55))
    {
        STATIC,              // test pattern
        staticRefIn55,       // staticIn
        staticRefOut55,      // staticOut
        4,                   // numChannels
        625,                 // numPoints
        55,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 56))
    {
        STATIC,              // test pattern
        staticRefIn56,       // staticIn
        staticRefOut56,      // staticOut
        4,                   // numChannels
        3125,                // numPoints
        56,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 57))
    {
        STATIC,              // test pattern
        staticRefIn57,       // staticIn
        staticRefOut57,      // staticOut
        8,                   // numChannels
        25,                  // numPoints
        57,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 58))
    {
        STATIC,              // test pattern
        staticRefIn58,       // staticIn
        staticRefOut58,      // staticOut
        8,                   // numChannels
        125,                 // numPoints
        58,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 59))
    {
        STATIC,              // test pattern
        staticRefIn59,       // staticIn
        staticRefOut59,      // staticOut
        8,                   // numChannels
        625,                 // numPoints
        59,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 60))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        3125,                // numPoints
        60,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 61))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        5,                   // numPoints
        61,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 62))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        125,                 // numPoints
        62,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 63))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        625,                 // numPoints
        63,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 64))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        160,                 // numPoints
        64,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 65))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        800,                 // numPoints
        65,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 66))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        4000,                // numPoints
        66,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 67))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        320,                 // numPoints
        67,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 68))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        1600,                // numPoints
        68,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 69))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        8000,                // numPoints
        69,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 70))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        640,                 // numPoints
        70,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 71))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        3200,                // numPoints
        71,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 72))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        1280,                // numPoints
        72,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 73))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        6400,                // numPoints
        73,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 74))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        2560,                // numPoints
        74,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 75))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        160,                 // numPoints
        75,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 76))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        800,                 // numPoints
        76,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 77))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        4000,                // numPoints
        77,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 78))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        320,                 // numPoints
        78,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 79))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        1600,                // numPoints
        79,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 80))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        640,                 // numPoints
        80,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 81))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        3200,                // numPoints
        81,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 82))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        1280,                // numPoints
        82,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 83))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        6400,                // numPoints
        83,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 84))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        2560,                // numPoints
        84,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 85))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        160,                 // numPoints
        85,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 86))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        800,                 // numPoints
        86,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 87))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        320,                 // numPoints
        87,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 88))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        1600,                // numPoints
        88,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 89))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        640,                 // numPoints
        89,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 90))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        3200,                // numPoints
        90,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 91))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        1280,                // numPoints
        91,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 92))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        2560,                // numPoints
        92,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 93))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        160,                 // numPoints
        93,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 94))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        800,                 // numPoints
        94,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 95))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        320,                 // numPoints
        95,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 96))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        1600,                // numPoints
        96,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 97))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        640,                 // numPoints
        97,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 98))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        160,                 // numPoints
        98,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 99))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        16,                  // numChannels
        320,                 // numPoints
        99,                  // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 100))
    {
        STATIC,              // test pattern
        staticRefIn100,      // staticIn
        staticRefOut100,     // staticOut
        1,                   // numChannels
        3,                   // numPoints
        100,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 101))
    {
        STATIC,              // test pattern
        staticRefIn101,      // staticIn
        staticRefOut101,     // staticOut
        1,                   // numChannels
        9,                   // numPoints
        101,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 102))
    {
        STATIC,              // test pattern
        staticRefIn102,      // staticIn
        staticRefOut102,     // staticOut
        1,                   // numChannels
        27,                  // numPoints
        102,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 103))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        81,                  // numPoints
        103,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 104))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        243,                 // numPoints
        104,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 105))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        96,                  // numPoints
        105,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 106))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        192,                 // numPoints
        106,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 107))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        384,                 // numPoints
        107,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 108))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        576,                 // numPoints
        108,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 109))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        1152,                // numPoints
        109,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 110))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        864,                 // numPoints
        110,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 111))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        1728,                // numPoints
        111,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 112))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        2592,                // numPoints
        112,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 113))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        15,                  // numPoints
        113,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 114))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        45,                  // numPoints
        114,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 115))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        135,                 // numPoints
        115,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 116))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        960,                 // numPoints
        116,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 117))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        1920,                // numPoints
        117,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 118))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        1440,                // numPoints
        118,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 119))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        1,                   // numChannels
        2880,                // numPoints
        119,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 120))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        3,                   // numPoints
        120,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 121))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        9,                   // numPoints
        121,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 122))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        27,                  // numPoints
        122,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 123))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        81,                  // numPoints
        123,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 124))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        243,                 // numPoints
        124,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 125))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        96,                  // numPoints
        125,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 126))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        192,                 // numPoints
        126,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 127))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        384,                 // numPoints
        127,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 128))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        576,                 // numPoints
        128,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 129))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        1152,                // numPoints
        129,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 130))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        864,                 // numPoints
        130,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 131))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        1728,                // numPoints
        131,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 132))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        2592,                // numPoints
        132,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 133))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        15,                  // numPoints
        133,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 134))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        45,                  // numPoints
        134,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 135))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        135,                 // numPoints
        135,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 136))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        960,                 // numPoints
        136,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 137))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        1920,                // numPoints
        137,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 138))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        1440,                // numPoints
        138,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 139))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        2880,                // numPoints
        139,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 140))
    {
        STATIC,              // test pattern
        staticRefIn140,      // staticIn
        staticRefOut140,     // staticOut
        8,                   // numChannels
        3,                   // numPoints
        140,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 141))
    {
        STATIC,              // test pattern
        staticRefIn141,      // staticIn
        staticRefOut141,     // staticOut
        8,                   // numChannels
        9,                   // numPoints
        141,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 142))
    {
        STATIC,              // test pattern
        staticRefIn142,      // staticIn
        staticRefOut142,     // staticOut
        8,                   // numChannels
        27,                  // numPoints
        142,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 143))
    {
        STATIC,              // test pattern
        staticRefIn143,      // staticIn
        staticRefOut143,     // staticOut
        8,                   // numChannels
        81,                  // numPoints
        143,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 144))
    {
        STATIC,              // test pattern
        staticRefIn144,      // staticIn
        staticRefOut144,     // staticOut
        8,                   // numChannels
        243,                 // numPoints
        144,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 145))
    {
        STATIC,              // test pattern
        staticRefIn145,      // staticIn
        staticRefOut145,     // staticOut
        8,                   // numChannels
        96,                  // numPoints
        145,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 146))
    {
        STATIC,              // test pattern
        staticRefIn146,      // staticIn
        staticRefOut146,     // staticOut
        8,                   // numChannels
        192,                 // numPoints
        146,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 147))
    {
        STATIC,              // test pattern
        staticRefIn147,      // staticIn
        staticRefOut147,     // staticOut
        8,                   // numChannels
        384,                 // numPoints
        147,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 148))
    {
        STATIC,              // test pattern
        staticRefIn148,      // staticIn
        staticRefOut148,     // staticOut
        8,                   // numChannels
        576,                 // numPoints
        148,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 149))
    {
        STATIC,              // test pattern
        staticRefIn149,      // staticIn
        staticRefOut149,     // staticOut
        8,                   // numChannels
        1152,                // numPoints
        149,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 150))
    {
        STATIC,              // test pattern
        staticRefIn150,      // staticIn
        staticRefOut150,     // staticOut
        8,                   // numChannels
        864,                 // numPoints
        150,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 151))
    {
        STATIC,              // test pattern
        staticRefIn151,      // staticIn
        staticRefOut151,     // staticOut
        8,                   // numChannels
        1728,                // numPoints
        151,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 152))
    {
        STATIC,              // test pattern
        staticRefIn152,      // staticIn
        staticRefOut152,     // staticOut
        8,                   // numChannels
        2592,                // numPoints
        152,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 153))
    {
        STATIC,              // test pattern
        staticRefIn153,      // staticIn
        staticRefOut153,     // staticOut
        8,                   // numChannels
        15,                  // numPoints
        153,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 154))
    {
        STATIC,              // test pattern
        staticRefIn154,      // staticIn
        staticRefOut154,     // staticOut
        8,                   // numChannels
        45,                  // numPoints
        154,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 155))
    {
        STATIC,              // test pattern
        staticRefIn155,      // staticIn
        staticRefOut155,     // staticOut
        8,                   // numChannels
        135,                 // numPoints
        155,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 156))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        960,                 // numPoints
        156,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 157))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        1920,                // numPoints
        157,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 158))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        1440,                // numPoints
        158,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 159))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        8,                   // numChannels
        2880,                // numPoints
        159,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 160))
    {
        STATIC,              // test pattern
        staticRefIn160,      // staticIn
        staticRefOut160,     // staticOut
        8,                   // numChannels
        2,                   // numPoints
        160,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 161))
    {
        STATIC,              // test pattern
        staticRefIn161,      // staticIn
        staticRefOut161,     // staticOut
        2,                   // numChannels
        50,                  // numPoints
        161,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 162))
    {
        STATIC,              // test pattern
        staticRefIn162,      // staticIn
        staticRefOut162,     // staticOut
        4,                   // numChannels
        18,                  // numPoints
        162,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 163))
    {
        STATIC,              // test pattern
        staticRefIn163,      // staticIn
        staticRefOut163,     // staticOut
        8,                   // numChannels
        4,                   // numPoints
        163,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 164))
    {
        STATIC,              // test pattern
        staticRefIn164,      // staticIn
        staticRefOut164,     // staticOut
        2,                   // numChannels
        100,                 // numPoints
        164,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 165))
    {
        STATIC,              // test pattern
        staticRefIn165,      // staticIn
        staticRefOut165,     // staticOut
        4,                   // numChannels
        36,                  // numPoints
        165,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 166))
    {
        STATIC,              // test pattern
        staticRefIn166,      // staticIn
        staticRefOut166,     // staticOut
        8,                   // numChannels
        8,                   // numPoints
        166,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 167))
    {
        STATIC,              // test pattern
        staticRefIn167,      // staticIn
        staticRefOut167,     // staticOut
        2,                   // numChannels
        200,                 // numPoints
        167,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 168))
    {
        STATIC,              // test pattern
        staticRefIn168,      // staticIn
        staticRefOut168,     // staticOut
        4,                   // numChannels
        72,                  // numPoints
        168,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 169))
    {
        STATIC,              // test pattern
        staticRefIn169,      // staticIn
        staticRefOut169,     // staticOut
        8,                   // numChannels
        16,                  // numPoints
        169,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 170))
    {
        STATIC,              // test pattern
        staticRefIn170,      // staticIn
        staticRefOut170,     // staticOut
        2,                   // numChannels
        400,                 // numPoints
        170,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 171))
    {
        STATIC,              // test pattern
        staticRefIn171,      // staticIn
        staticRefOut171,     // staticOut
        4,                   // numChannels
        144,                 // numPoints
        171,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 172))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        15625,               // numPoints
        172,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 173))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        6561,                // numPoints
        173,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 174))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        19683,               // numPoints
        174,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 175))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        6250,                // numPoints
        175,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 176))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        31250,               // numPoints
        176,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 177))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        4374,                // numPoints
        177,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 178))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        13122,               // numPoints
        178,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 179))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        6075,                // numPoints
        179,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 180))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        10935,               // numPoints
        180,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 181))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        4,                   // numChannels
        2430,                // numPoints
        181,                 // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 182))
    {
        RANDOM_SIGNED,       // test pattern
        NULL,                // randomIn
        NULL,                // randomOut
        2,                   // numChannels
        21870,               // numPoints
        182,                 // test ID
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
