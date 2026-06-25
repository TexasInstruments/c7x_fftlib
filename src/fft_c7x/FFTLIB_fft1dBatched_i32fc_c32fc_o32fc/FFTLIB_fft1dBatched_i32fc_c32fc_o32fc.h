// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1DBATCHED_I32FC_C32FC_O32FC_H_
#define FFTLIB_FFT1DBATCHED_I32FC_C32FC_O32FC_H_ 1

#include "../../common/FFTLIB_types.h"

// clang-format off
/*!
 * @defgroup FFTLIB_fft1dBatched_i32fc_c32fc_o32fc FFTLIB_fft1dBatched_i32fc_c32fc_o32cf
 * @brief Kernel for computing 32-bit floating-point batched FFT
 * @details
 *        - The size of data is required to be a power of 2.
 *        - The kernel requires application to provide a pre-generated
 *          twiddle factors along with the input data.
 * @ingroup  FFT_C7X
 * @{
 */
// clang-format on
/**
 * @brief Macro to define the array size for storing SE/SA parameters
 */
// clang-format on
/* PBLOCK has to accommodate certain number of SE/SA configurations */
#define FFTLIB_FFT1DBATCHED_I32FC_C32FC_O32FC_PBLOCK_SIZE (13 * SE_PARAM_SIZE)

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief       This function should be called before the
 *               @ref FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_kernel function
 * is called. This function takes care of any one-time operations such as
 * setting up the configuration for the streaming engine.
 *
 *  @param [in]  pX               :  Pointer to buffer with input data
 *  @param [in]  bufParamsX       :  Pointer to the structure containing
 *                                   dimensional information of input buffer
 *  @param [in]  pW               :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW       :  Pointer to the structure containing
 *                                   dimensional information of twiddle
 * factor buffer
 *  @param [in]  pY               :  Pointer to buffer with output data
 *  @param [in]  bufParamsY       :  Pointer to the structure containing
 *                                   dimensional information of output buffer
 *  @param [in]  numPoints        :  FFT size
 *  @param [in]  numChannels      :  Batch size of FFT
 *  @param [out] pBlock           :  Pointer to the buffer that will hold the
 *                                   streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref
 *               FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_init(FFTLIB_F32*           pX,
                                           FFTLIB_bufParams1D_t* bufParamsX,
                                           FFTLIB_F32*           pW,
                                           FFTLIB_bufParams1D_t* bufParamsW,
                                           FFTLIB_F32*           pY,
                                           FFTLIB_bufParams1D_t* bufParamsY,
                                           uint32_t              numPoints,
                                           uint32_t              numChannels,
                                           void*                 pBlock);

/**
 *  @brief       This function is the main kernel compute function.
 *
 *  @param [in]  pX               :  Pointer to buffer with input data
 *  @param [in]  bufParamsX       :  Pointer to the structure containing
 *                                   dimensional information of input buffer
 *  @param [in]  pW               :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW       :  Pointer to the structure containing
 *                                   dimensional information of twiddle
 * factor buffer
 *  @param [out] pY               :  Pointer to buffer with output data
 *  @param [in]  bufParamsY       :  Pointer to the structure containing
 *                                   dimensional information of output buffer
 *  @param [in]  numPoints        :  FFT size
 *  @param [in]  numChannels      :  Batch size of FFT
 *  @param [in]  pBlock           :  Pointer to the buffer that will hold the
 *                                   streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref
 *               FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS
FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_kernel(FFTLIB_F32*           pX,
                                             FFTLIB_bufParams1D_t* bufParamsX,
                                             FFTLIB_F32*           pW,
                                             FFTLIB_bufParams1D_t* bufParamsW,
                                             FFTLIB_F32*           pY,
                                             FFTLIB_bufParams1D_t* bufParamsY,
                                             uint32_t              numPoints,
                                             uint32_t              numChannels,
                                             void*                 pBlock);

/**
 *  @brief       This function checks the validity of the parameters passed
 * to
 *               @ref FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_init and
 *               @ref FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_kernel functions.
 *
 *  @param [in]  pX               :  Pointer to buffer with input data
 *  @param [in]  bufParamsX       :  Pointer to the structure containing
 *                                   dimensional information of input buffer
 *  @param [in]  pW               :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW       :  Pointer to the structure containing
 *                                   dimensional information of twiddle
 * factor buffer
 *  @param [in]  pY               :  Pointer to buffer with output data
 *  @param [in]  bufParamsY       :  Pointer to the structure containing
 *                                   dimensional information of output buffer
 *  @param [in]  numPoints        :  FFT size
 *  @param [in]  numChannels      :  Batch size of FFT
 *  @param [in]  pBlock           :  Pointer to the buffer that will hold the
 *                                   streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref
 *               FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_checkParams(FFTLIB_F32*           pX,
                                                                FFTLIB_bufParams1D_t* bufParamsX,
                                                                FFTLIB_F32*           pW,
                                                                FFTLIB_bufParams1D_t* bufParamsW,
                                                                FFTLIB_F32*           pY,
                                                                FFTLIB_bufParams1D_t* bufParamsY,
                                                                uint32_t              numPoints,
                                                                uint32_t              numChannels,
                                                                void*                 pBlock);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
