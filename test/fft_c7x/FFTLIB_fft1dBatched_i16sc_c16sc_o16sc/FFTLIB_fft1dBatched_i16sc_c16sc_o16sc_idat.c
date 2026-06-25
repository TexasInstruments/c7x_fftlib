// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_fft1dBatched_i16sc_c16sc_o16sc_idat.h"
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

/* ===== Shift Vectors ===== */
__attribute__((section(".staticData"))) static uint32_t shiftVector1[] = {0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector2[] = {0, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector3[] = {0, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector4[] = {0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector5[] = {1, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector6[] = {0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector7[] = {1, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector8[] = {1, 0, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector9[] = {0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector10[] = {1, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector11[] = {0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector12[] = {1, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector13[] = {1, 0, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector14[] = {0, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector15[] = {1, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector16[] = {0, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector17[] = {1, 1, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector18[] = {1, 0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector19[] = {0, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector20[] = {1, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector21[] = {0, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector22[] = {1, 1, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector23[] = {1, 0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector24[] = {0, 1, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector25[] = {1, 0, 1, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector26[] = {0, 0, 1, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector27[] = {1, 1, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector28[] = {1, 0, 0, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector29[] = {0, 1, 1, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector30[] = {1, 0, 1, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector31[] = {0, 0, 1, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector32[] = {1, 1, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector33[] = {1, 0, 0, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector34[] = {0, 1, 1, 0, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector35[] = {1, 0, 1, 1, 0, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector36[] = {0, 0, 1, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector37[] = {1, 1, 0, 1, 1, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector38[] = {1, 0, 0, 0, 1, 1};

__attribute__((section(".staticData"))) static uint32_t shiftVector39[] = {0, 1, 1, 1, 0, 0};

__attribute__((section(".staticData"))) static uint32_t shiftVector40[] = {1, 0, 1, 0, 1, 0};

static fft1dBatched_i16sc_c16sc_o16sc_testParams_t testParams[] = {

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 1))
    {
        STATIC,        // test pattern
        staticRefIn1,  // staticIn
        shiftVector1,  // shiftVector
        staticRefOut1, // staticOut
        3,             // numShifts
        2,             // numChannels
        128,           // numPoints
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
        4,             // numChannels
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
        4,             // numShifts
        2,             // numChannels
        512,           // numPoints
        3,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 4))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector4,  // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        32,            // numChannels
        64,            // numPoints
        4,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 5))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector5,  // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        64,            // numChannels
        64,            // numPoints
        5,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 6))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector6,  // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        128,           // numChannels
        64,            // numPoints
        6,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 7))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector7,  // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        256,           // numChannels
        64,            // numPoints
        7,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 8))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector8,  // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        512,           // numChannels
        64,            // numPoints
        8,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 9))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector9,  // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        16,            // numChannels
        128,           // numPoints
        9,             // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 10))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector10, // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        32,            // numChannels
        128,           // numPoints
        10,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 11))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector11, // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        64,            // numChannels
        128,           // numPoints
        11,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 12))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector12, // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        128,           // numChannels
        128,           // numPoints
        12,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 13))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector13, // shiftVector
        NULL,          // randomOut
        3,             // numShifts
        256,           // numChannels
        128,           // numPoints
        13,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 14))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector14, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        8,             // numChannels
        256,           // numPoints
        14,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 15))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector15, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        16,            // numChannels
        256,           // numPoints
        15,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 16))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector16, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        32,            // numChannels
        256,           // numPoints
        16,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 17))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector17, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        64,            // numChannels
        256,           // numPoints
        17,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 18))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector18, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        128,           // numChannels
        256,           // numPoints
        18,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 19))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector19, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        4,             // numChannels
        512,           // numPoints
        19,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 20))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector20, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        8,             // numChannels
        512,           // numPoints
        20,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 21))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector21, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        16,            // numChannels
        512,           // numPoints
        21,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 22))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector22, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        32,            // numChannels
        512,           // numPoints
        22,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 23))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector23, // shiftVector
        NULL,          // randomOut
        4,             // numShifts
        64,            // numChannels
        512,           // numPoints
        23,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 24))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector24, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        2,             // numChannels
        1024,          // numPoints
        24,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 25))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector25, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        4,             // numChannels
        1024,          // numPoints
        25,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 26))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector26, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        8,             // numChannels
        1024,          // numPoints
        26,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 27))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector27, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        16,            // numChannels
        1024,          // numPoints
        27,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 28))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector28, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        32,            // numChannels
        1024,          // numPoints
        28,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 29))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector29, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        1,             // numChannels
        2048,          // numPoints
        29,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 30))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector30, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        2,             // numChannels
        2048,          // numPoints
        30,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 31))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector31, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        4,             // numChannels
        2048,          // numPoints
        31,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 32))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector32, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        8,             // numChannels
        2048,          // numPoints
        32,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 33))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector33, // shiftVector
        NULL,          // randomOut
        5,             // numShifts
        16,            // numChannels
        2048,          // numPoints
        33,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 34))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector34, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        1,             // numChannels
        4096,          // numPoints
        34,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 35))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector35, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        2,             // numChannels
        4096,          // numPoints
        35,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 36))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector36, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        4,             // numChannels
        4096,          // numPoints
        36,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 37))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector37, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        8,             // numChannels
        4096,          // numPoints
        37,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 38))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector38, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        1,             // numChannels
        8192,          // numPoints
        38,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 39))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector39, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        2,             // numChannels
        8192,          // numPoints
        39,            // test ID
    },
#endif

#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200) || (TEST_CATEGORY == 100) || (TEST_CASE == 40))
    {
        RANDOM_SIGNED, // test pattern
        NULL,          // randomIn
        shiftVector40, // shiftVector
        NULL,          // randomOut
        6,             // numShifts
        4,             // numChannels
        8192,          // numPoints
        40,            // test ID
    },
#endif

};

/*
 *  Sends the test parameter structure and number of tests
 */
void fft1dBatched_i16sc_c16sc_o16sc_getTestParams(fft1dBatched_i16sc_c16sc_o16sc_testParams_t** params,
                                                  int32_t*                                      numTests)
{
   *params   = testParams;
   *numTests = sizeof(testParams) / sizeof(fft1dBatched_i16sc_c16sc_o16sc_testParams_t);
}
