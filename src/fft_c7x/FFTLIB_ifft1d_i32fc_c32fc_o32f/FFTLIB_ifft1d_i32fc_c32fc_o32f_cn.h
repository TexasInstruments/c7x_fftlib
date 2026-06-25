// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1D_I32F_C32FC_O32FC_CN_H_
#define FFTLIB_FFT1D_I32F_C32FC_O32FC_CN_H_ 1

#include "../../common/FFTLIB_types.h"
#include "../FFTLIB_ifft1d_i32fc_c32fc_o32fc/FFTLIB_ifft1d_i32fc_c32fc_o32fc_cn.h"

FFTLIB_STATUS
FFTLIB_ifft1d_i32fc_c32fc_o32f_cn(FFTLIB_F32           *pX,
                                  FFTLIB_bufParams1D_t *bufParamsX,
                                  FFTLIB_F32           *pW,
                                  FFTLIB_bufParams1D_t *bufParamsW,
                                  FFTLIB_F32           *pXFFT,
                                  FFTLIB_bufParams1D_t *bufParamsXFFT,
                                  FFTLIB_F32           *pSplitFactor,
                                  FFTLIB_bufParams1D_t *bufParamsSplitFactor,
                                  FFTLIB_F32           *pY,
                                  FFTLIB_bufParams1D_t *bufParamsY);

FFTLIB_STATUS
FFTLIB_ifft1d_i32fc_c32fc_o32f_checkParams_cn(FFTLIB_F32           *pX,
                                              FFTLIB_bufParams1D_t *bufParamsX,
                                              FFTLIB_F32           *pW,
                                              FFTLIB_bufParams1D_t *bufParamsW,
                                              FFTLIB_F32           *pY,
                                              FFTLIB_bufParams1D_t *bufParamsY);

#endif
