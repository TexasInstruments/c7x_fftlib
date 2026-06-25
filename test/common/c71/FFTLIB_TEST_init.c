// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_test.h"

#if !defined(_HOST_BUILD)
extern const uint64_t pte_lvl0[512];
#endif

void FFTLIB_TEST_init()
{

#if __C7X_VEC_SIZE_BITS__ == 512
   // Known silicon bug, errata: TBD
   __sa_set_cr(0, __sa_get_cr(1));
#endif

#if !defined(_HOST_BUILD)
   // enable MMU
   enable_cache_mmu((uint64_t) pte_lvl0);

   // invalidate TLB
   invalidate_tlb();
#endif

#ifndef FFTLIB_FIXED_SEED
   time_t t;
   time(&t);
   FFTLIB_DEBUGPRINTFN(1, "rand seed = %u\n", (unsigned) t);
   srand((unsigned) t);
#else
   FFTLIB_DEBUGPRINTFN(1, "fixed seed = %u\n", (unsigned) FFTLIB_FIXED_SEED);
   srand((unsigned) FFTLIB_FIXED_SEED);
#endif

#if !defined(DEMO)
#if defined(_HOST_BUILD)
#if defined(FFTLIB_DEBUGPRINT)
   streaming_engine::set_debug_level(FFTLIB_DEBUGPRINT);
   sa_generator::set_debug_level(FFTLIB_DEBUGPRINT);
#endif
#endif
#endif
}
