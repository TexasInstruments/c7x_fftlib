// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1DBATCHED_I32F_C32FC_O32FC_H_
#define FFTLIB_FFT1DBATCHED_I32F_C32FC_O32FC_H_ 1

#include "../../common/FFTLIB_types.h"

/*!
 * @defgroup FFTLIB_fft1dBatched_i32f_c32fc_o32fc FFTLIB_fft1dBatched_i32f_c32fc_o32fc
 * @brief Kernel for computing 32-bit floating-point real to complex FFT
 *
 * @details
 *          - The kernel performs FFT of an N-point real sequence using
 *            N/2-point complex FFT, which saves compute time
 *          - The size of data is required to be a power of 2 or power of 3 or power of 5.
 *          - The kernel requires application to provide a pre-generated
 *            twiddle factors along with the input data.
 *          - The kernel requires application to provide a pre-generated
 *            split factors along with the input data.
 *          - The kernel takes in a outmode flag, which determines the
 *            number of output samples - full or half (N or N/2 + 1).
 *
 * @ingroup  FFT_C7X
 * @{
 */

/**
 * @brief Macro to define the array size for storing SE/SA parameters
 */

/* PBLOCK has to accommodate certain number of SE/SA configurations */
#define FFTLIB_FFT1DBATCHED_I32F_C32FC_O32FC_PBLOCK_SIZE (41 * SE_PARAM_SIZE + 18 * sizeof(uint32_t))

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief       This function should be called before the
 *               @ref FFTLIB_fft1dBatched_i32f_c32fc_o32fc_kernel function is
 * called. This function takes care of any one-time operations such as
 *               setting up the configuration for the streaming engine.
 *
 *  @param [in]  pX            :  Pointer to buffer with input data
 *  @param [in]  bufParamsX    :  Pointer to the structure containing
 * dimensional information of input buffer
 *  @param [in]  pW            :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW    :  Pointer to the structure containing
 * dimensional information of twiddle factor buffer
 *  @param [in]  pXFFT         :  Pointer to buffer with input data
 *  @param [in]  bufParamsXFFT :  Pointer to the structure containing
 * dimensional information of of pXFFT buffer
 *  @param [in]  pSf           :  Pointer to buffer with split factors
 *  @param [in]  bufParamsSf   :  Pointer to the structure containing
 *                               dimensional information of split factor buffer
 *  @param [out] pY            :  Pointer to buffer with output data
 *  @param [in]  bufParamsY    :  Pointer to the structure containing
 * dimensional information of output buffer
 *  @param [in]  numPoints        :  FFT size
 *  @param [in]  numChannels      :  Batch size of FFT
 *  @param [in]  outmode      :  Flag to determine full or half spectrum
 * @param [out] pBlock        :  Pointer to the buffer that will hold the
 *                               streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_init(FFTLIB_F32*           pX,
                                          FFTLIB_bufParams1D_t* bufParamsX,
                                          FFTLIB_F32*           pW,
                                          FFTLIB_bufParams1D_t* bufParamsW,
                                          FFTLIB_F32*           pXFFT,
                                          FFTLIB_bufParams1D_t* bufParamsXFFT,
                                          FFTLIB_F32*           pSf,
                                          FFTLIB_bufParams1D_t* bufParamsSf,
                                          FFTLIB_F32*           pY,
                                          FFTLIB_bufParams1D_t* bufParamsY,
                                          uint32_t              numPoints,
                                          uint32_t              numChannels,
                                          uint8_t               outmode,
                                          void*                 pBlock);

/**
 *  @brief       This function is the main kernel compute function.
 *
 *  @param [in]  pX            :  Pointer to buffer with input data
 *  @param [in]  bufParamsX    :  Pointer to the structure containing
 * dimensional information of input buffer
 *  @param [in]  pW            :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW    :  Pointer to the structure containing
 * dimensional information of twiddle factor buffer
 *  @param [in]  pXFFT         :  Pointer to temp. buffer with FFT of input data
 *  @param [in]  bufParamsXFFT :  Pointer to the structure containing
 * dimensional information of of pXFFT buffer
 *  @param [in]  pSf           :  Pointer to buffer with split factors
 *  @param [in]  bufParamsSf   :  Pointer to the structure containing
 *                               dimensional information of split factor buffer
 *  @param [out] pY            :  Pointer to buffer with output data
 *  @param [in]  bufParamsY    :  Pointer to the structure containing
 * dimensional information of output buffer
 *  @param [in]  numPoints        :  FFT size
 *  @param [in]  numChannels      :  Batch size of FFT
 *  @param [in]  outmode      :  Flag to determine full or half spectrum
 * @param [in]  pBlock        :  Pointer to the buffer that will hold the
 *                               streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_kernel(FFTLIB_F32* restrict pX,
                                            FFTLIB_bufParams1D_t* bufParamsX,
                                            FFTLIB_F32* restrict pW,
                                            FFTLIB_bufParams1D_t* bufParamsW,
                                            FFTLIB_F32* restrict pXFFT,
                                            FFTLIB_bufParams1D_t* bufParamsXFFT,
                                            FFTLIB_F32* restrict pSf,
                                            FFTLIB_bufParams1D_t* bufParamsSf,
                                            FFTLIB_F32* restrict pY,
                                            FFTLIB_bufParams1D_t* bufParamsY,
                                            uint32_t              numPoints,
                                            uint32_t              numChannels,
                                            uint8_t               outmode,
                                            void*                 pBlock);

/**
 *  @brief       This function checks the validity of the parameters passed
 * to
 *               @ref FFTLIB_fft1dBatched_i32f_c32fc_o32fc_init and
 *               @ref FFTLIB_fft1dBatched_i32f_c32fc_o32fc_kernel functions.
 *
 *  @param [in]  pX           :  Pointer to buffer with input data
 *  @param [in]  bufParamsX   :  Pointer to the structure containing
 * dimensional information of input buffer
 *  @param [in]  pW           :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW   :  Pointer to the structure containing
 * dimensional information of twiddle factor buffer
 *  @param [out] pY           :  Pointer to buffer with output data
 *  @param [in]  bufParamsY   :  Pointer to the structure containing
 * dimensional
 *  @param [in]  numPoints        :  FFT size
 *  @param [in]  numChannels      :  Batch size of FFT
 *  @param [in]  outmode      :  Flag to determine full or half spectrum
 *  @param [in]  pBlock       :  Pointer to the buffer that will hold the
 *                               streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref FFTLIB_STATUS.
 */

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32f_c32fc_o32fc_checkParams(FFTLIB_F32*           pX,
                                                 FFTLIB_bufParams1D_t* bufParamsX,
                                                 FFTLIB_F32*           pW,
                                                 FFTLIB_bufParams1D_t* bufParamsW,
                                                 FFTLIB_F32*           pY,
                                                 FFTLIB_bufParams1D_t* bufParamsY,
                                                 uint32_t              numPoints,
                                                 uint32_t              numChannels,
                                                 uint8_t               outmode,
                                                 void*                 pBlock);
/**
 *  @brief       This function generates the split factors required to post
 *                 process the N/2-point FFT output
 *  @param [out]  pSFactor           :  Pointer to buffer with split factors
 *  @param [in]   numPoints          :  FFT size
 */
void split_factor_gen_r2c(FFTLIB_F32* pSFactor, int32_t numPoints);

/**
 *  @brief       This function generates twiddle factors required for
 *               the N/2-point FFT
 *  @param [out]  pW           :  Pointer to buffer with twiddle factors
 *  @param [in]   numPoints    :  FFT size
 */
void tw_gen_r2c(FFTLIB_F32* pW, int32_t numPoints);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
