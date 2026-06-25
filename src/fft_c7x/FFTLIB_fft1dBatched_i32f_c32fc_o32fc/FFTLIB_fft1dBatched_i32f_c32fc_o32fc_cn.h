// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1DBATCHED_I32F_C32FC_O32FC_CN_H_
#define FFTLIB_FFT1DBATCHED_I32F_C32FC_O32FC_CN_H_ 1

#include "../../common/FFTLIB_types.h"
#include "../FFTLIB_fft1dBatched_i32f_c32fc_o32fc/FFTLIB_fft1dBatched_i32f_c32fc_o32fc_cn.h"

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_cn(FFTLIB_F32           *pX,
                                        FFTLIB_bufParams1D_t *bufParamsX,
                                        FFTLIB_F32           *pW,
                                        FFTLIB_bufParams1D_t *bufParamsW,
                                        FFTLIB_F32           *pXFFT,
                                        FFTLIB_bufParams1D_t *bufParamsXFFT,
                                        FFTLIB_F32           *pSplitFactor,
                                        FFTLIB_bufParams1D_t *bufParamsSplitFactor,
                                        FFTLIB_F32           *pY,
                                        FFTLIB_bufParams1D_t *bufParamsY,
                                        uint32_t              numPoints,
                                        uint32_t              numChannels,
                                        uint8_t               outmode);

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_checkParams_cn(FFTLIB_F32           *pX,
                                                    FFTLIB_bufParams1D_t *bufParamsX,
                                                    FFTLIB_F32           *pW,
                                                    FFTLIB_bufParams1D_t *bufParamsW,
                                                    FFTLIB_F32           *pY,
                                                    FFTLIB_bufParams1D_t *bufParamsY,
                                                    uint32_t              numPoints,
                                                    uint32_t              numChannels,
                                                    uint8_t               outmode);

#endif
