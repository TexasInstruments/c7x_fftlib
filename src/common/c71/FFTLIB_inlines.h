// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef C71_MMA_INLINES_H
#define C71_MMA_INLINES_H

#include "../FFTLIB_types.h"
#if defined(FFTLIB_DEBUGPRINT)
#include "FFTLIB_debug.h"
#endif
#include <float.h>  // for max float, double values
#include <limits.h> // for min, max integer values

#include "FFTLIB_UTIL_SE0Bload.h"

/*******************************************************************************
 *
 * Inlined functions
 *
 ******************************************************************************/

/******************************************************************************/

#include "FFTLIB_UTIL_SA0Cstore.h"
#include "FFTLIB_UTIL_SA2CloadSA0Cstore.h"
#include "FFTLIB_UTIL_SA2CloadSE1Bload.h"
#include "FFTLIB_UTIL_SE0AloadComputeC.h"
#include "FFTLIB_UTIL_SE0AloadComputeCSA0Cstore.h"
#include "FFTLIB_UTIL_SE0AloadSE1BloadComputeC.h"
#include "FFTLIB_UTIL_SE0AloadSE1BloadComputeCSA0Cstore.h"
#include "FFTLIB_UTIL_SE0Bload.h"
#include "FFTLIB_UTIL_SE1Bload.h"
#include "FFTLIB_UTIL_zeroBload.h"
#endif
