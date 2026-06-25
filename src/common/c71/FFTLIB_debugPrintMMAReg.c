// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "FFTLIB_debug.h"

void FFTLIB_debugPrintMMAReg(const int32_t regNumber)
{
   /*****************************************************************************
    * commented out until compiler fix is in place for HWXFER to accept 0 to 15 *
    *****************************************************************************/
   /* FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * __HWAXFER(__MMA_XFER_SRC_HWA_STATUS); // 8->HWACONFIG, 9->HWAOFFSET, 10->HWASTATUS, 11->HWABUSY
    * __HWAADV();
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    *
    * uchar64 vb_hwaconfig = __HWARCV(0);
    * __HWAADV();
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    * FFTLIB_asm(" NOP");
    *
    * /\* printf("\n%d:", regNumber); *\/
    * /\* Since hard-coded here: __HWAXFER(__MMA_XFER_SRC_HWA_STATUS); *\/
    * printf("\n10:");
    * FFTLIB_debugPrintVReg_i64x(vb_hwaconfig); */
}
