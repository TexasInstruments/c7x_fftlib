// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_TEST_C7XECR_H_
#define FFTLIB_TEST_C7XECR_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void FFTLIB_TEST_c7xSetTCR0(uint64_t param);

void FFTLIB_TEST_c7xSetTBR0(uint64_t param);

void FFTLIB_TEST_c7xSetMAR(uint64_t param);

void FFTLIB_TEST_c7xSetSCR(uint64_t param);

// added during j721e bring-up to perform TLB invalidate ALL after the MMU setup
// code
void FFTLIB_TEST_c7xMmuTlbInvAll(void);

void FFTLIB_TEST_c7xSetL2CFG(uint64_t param);

uint64_t FFTLIB_TEST_c7xGetL2CFG(void);

void FFTLIB_TEST_c7xSetL1DCFG(uint64_t param);

uint64_t FFTLIB_TEST_c7xGetL1DCFG(void);

uint64_t MMALIB_c7xGetL1DWBINV(void);
uint64_t MMALIB_c7xGetL1DINV(void);
void     MMALIB_c7xSetL1DWBINV(uint64_t param);
void     MMALIB_c7xSetL1DINV(uint64_t param);
uint64_t MMALIB_c7xL1PCacheInvalidateAll();

#ifdef __cplusplus
}
#endif

#endif /* end of FFTLIB_TEST_C7XECR_H_ definition */
