// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef C7120_FFTLIB_DEFINES_H_
#define C7120_FFTLIB_DEFINES_H_ 1

/*******************************************************************************
 *
 * SOC HARDWARE DEFINES
 *
 ******************************************************************************/

#define FFTLIB_SOC_MSMC 1 //!< SOC supports MSMC memory

/*******************************************************************************
 *
 * MMA HARDWARE DEFINES
 *
 ******************************************************************************/

#define FFTLIB_MMA_CONFIG_REG __HWA_CONFIG_REG_v1
#define FFTLIB_MMA_ARF 1 //<! Does the MMA implement an A register file (ARF)
#define FFTLIB_MMA_NUM_ARF_ROWS 64

#define FFTLIB_NONZER0_PADFILL 1

#define MMA_INDEPENDENT_B_ROW_COUNTERS 1
#define MMA_PSAT_ACTIVATION_SUPPORTED 1

/*******************************************************************************
 *
 * FFTLIB SOFTWARE DEFINES
 *
 ******************************************************************************/

// this should be deprecated
#define ENABLE_DYN_RANGE_CHECKING 1
// in favor of this
#define FFTLIB_ENABLE_DYNAMIC_RANGE_TRACKING 1

#define FFTLIB_CONVOLVE_COL_IN_KERNEL_PADDING 1

/*******************************************************************************
 *
 * Function prototypes
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* C7120_FFTLIB_DEFINES_H_ */
