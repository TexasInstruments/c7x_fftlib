// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef TI_CACHE_H_
#define TI_CACHE_H_ 1

/* Cache operation prototypes */

int32_t TI_cache_init(void);

int32_t TI_cache_inval(void);

void FFTLIB_c7xCleaninvalidateL1DCache();

void FFTLIB_c7xInvalidateL1DCache();

#endif /* TI_CACHE_H_ */
