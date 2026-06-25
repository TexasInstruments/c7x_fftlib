// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_c7504_utility.h"

/**************************************************************************************
 *
 * Storage for emulating the dynamic range min/max feature of the MMA
 *
 **************************************************************************************/

int64_t FFTLIB_CN_dynamicRangeMin;
int64_t FFTLIB_CN_dynamicRangeMax;

/**************************************************************************************
 *
 * Functions for emulating the dynamic range min/max feature of the MMA
 *
 **************************************************************************************/

template <typename accumulateType>
void FFTLIB_CN_initDynamicRange(FFTLIB_initDynamicRange_type initDynamicRange, accumulateType temp)
{
   if (initDynamicRange == FFTLIB_DYNAMIC_RANGE_NOINIT) {
      // do nothing
   }
   else {
      FFTLIB_CN_dynamicRangeMin = 0x7FFFFFFFFFFFFFFF;
      FFTLIB_CN_dynamicRangeMax = 0x8000000000000000U;
   }

   return;
}

template void FFTLIB_CN_initDynamicRange(FFTLIB_initDynamicRange_type initDynamicRange, int32_t temp);
template void FFTLIB_CN_initDynamicRange(FFTLIB_initDynamicRange_type initDynamicRange, int64_t temp);

template <> void FFTLIB_CN_initDynamicRange(FFTLIB_initDynamicRange_type initDynamicRange, uint32_t temp)
{
   if (initDynamicRange == FFTLIB_DYNAMIC_RANGE_NOINIT) {
      // do nothing
   }
   else {
      FFTLIB_CN_dynamicRangeMin = 0x00000000FFFFFFFFU;
      FFTLIB_CN_dynamicRangeMax = 0x0000000000000000;
   }

   return;
}

template <> void FFTLIB_CN_initDynamicRange(FFTLIB_initDynamicRange_type initDynamicRange, uint64_t temp)
{
   if (initDynamicRange == FFTLIB_DYNAMIC_RANGE_NOINIT) {
      // do nothing
   }
   else {
      FFTLIB_CN_dynamicRangeMin = 0xFFFFFFFFFFFFFFFFU;
      FFTLIB_CN_dynamicRangeMax = 0x0000000000000000;
   }

   return;
}
