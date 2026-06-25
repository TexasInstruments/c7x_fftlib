// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_FFT1D_I16SC_C16SC_O16SC_H_
#define FFTLIB_FFT1D_I16SC_C16SC_O16SC_H_ 1

#include "../../common/FFTLIB_types.h"
/*!
 * @defgroup FFTLIB_fft1d_i16sc_c16sc_o16sc FFTLIB_fft1d_i16sc_c16sc_o16sc
 * @brief Kernel for computing 16-bit integer FFT
 *
 * @details
 *      - The size of data is required to be a power of 2.
 *      - The kernel requires application to provide a pre-generated
 *        twiddle factors along with the input data.
 * @ingroup  FFT_C7X
 * @{
 */

/**
 * @brief Macro to define the array size for storing SE/SA parameters
 */

/* PBLOCK has to accommodate certain number of SE/SA configurations */
#define FFTLIB_FFT1D_I16SC_C16SC_O16SC_PBLOCK_SIZE (9 * SE_PARAM_SIZE)

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief       This function should be called before the
 *               @ref FFTLIB_fft1d_i16sc_c16sc_o16sc_kernel function is called.
 *               This function takes care of any one-time operations such as
 *               setting up the configuration for the streaming engine.
 *
 *  @param [in]  pX               :  Pointer to buffer with input data
 *  @param [in]  bufParamsX       :  Pointer to the structure containing
 *                                   dimensional information of input buffer
 *  @param [in]  pW               :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW       :  Pointer to the structure containing
 *                                   dimensional information of twiddle factor
 *                                   buffer
 *  @param [in]  pY               :  Pointer to buffer with output data
 *  @param [in]  bufParamsY       :  Pointer to the structure containing
 *                                   dimensional information of output buffer
 *  @param [in]  pShift           :  Pointer to buffer with shift value at every
 *                                   stage of FFT
 *  @param [in]  bufParamsShift   :  Pointer to the structure containing
 *                                   dimensional information of shift buffer
 *  @param [out] pBlock           :  Pointer to the buffer that will hold the
 *                                   streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref
 *               FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS
FFTLIB_fft1d_i16sc_c16sc_o16sc_init(int16_t              *pX,
                                    FFTLIB_bufParams1D_t *bufParamsX,
                                    int16_t              *pW,
                                    FFTLIB_bufParams1D_t *bufParamsW,
                                    int16_t              *pY,
                                    FFTLIB_bufParams1D_t *bufParamsY,
                                    uint32_t             *pShift,
                                    FFTLIB_bufParams1D_t *bufParamsShift,
                                    void                 *pBlock);

/**
 *  @brief       This function is the main kernel compute function.
 *
 *  @param [in]  pX               :  Pointer to buffer with input data
 *  @param [in]  bufParamsX       :  Pointer to the structure containing
 *                                   dimensional information of input buffer
 *  @param [in]  pW               :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW       :  Pointer to the structure containing
 *                                   dimensional information of twiddle factor
 *                                   buffer
 *  @param [out] pY               :  Pointer to buffer with output data
 *  @param [in]  bufParamsY       :  Pointer to the structure containing
 *                                   dimensional information of output buffer
 *  @param [in]  pShift           :  Pointer to buffer with shift value at every
 *                                   stage of FFT
 *  @param [in]  bufParamsShift   :  Pointer to the structure containing
 *                                   dimensional information of shift buffer
 *  @param [in]  pBlock           :  Pointer to the buffer that will hold the
 *                                   streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref
 *               FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS
FFTLIB_fft1d_i16sc_c16sc_o16sc_kernel(int16_t              *pX,
                                      FFTLIB_bufParams1D_t *bufParamsX,
                                      int16_t              *pW,
                                      FFTLIB_bufParams1D_t *bufParamsW,
                                      int16_t              *pY,
                                      FFTLIB_bufParams1D_t *bufParamsY,
                                      uint32_t             *pShift,
                                      FFTLIB_bufParams1D_t *bufParamsShift,
                                      void                 *pBlock);
/**
 *  @brief       This function checks the validity of the parameters passed to
 *               @ref FFTLIB_fft1d_i16sc_c16sc_o16sc_init and
 *               @ref FFTLIB_fft1d_i16sc_c16sc_o16sc_kernel functions.
 *
 *  @param [in]  pX               :  Pointer to buffer with input data
 *  @param [in]  bufParamsX       :  Pointer to the structure containing
 *                                   dimensional information of input buffer
 *  @param [in]  pW               :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW       :  Pointer to the structure containing
 *                                   dimensional information of twiddle factor
 *                                   buffer
 *  @param [in]  pY               :  Pointer to buffer with output data
 *  @param [in]  bufParamsY       :  Pointer to the structure containing
 *                                   dimensional information of output buffer
 *  @param [in]  pShift           :  Pointer to buffer with shift value at every
 *                                   stage of FFT
 *  @param [in]  bufParamsShift   :  Pointer to the structure containing
 *                                   dimensional information of shift buffer
 *  @param [in]  pBlock           :  Pointer to the buffer that will hold the
 *                                   streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref
 *               FFTLIB_STATUS.
 */

FFTLIB_STATUS FFTLIB_fft1d_i16sc_c16sc_o16sc_checkParams(int16_t              *pX,
                                                         FFTLIB_bufParams1D_t *bufParamsX,
                                                         int16_t              *pW,
                                                         FFTLIB_bufParams1D_t *bufParamsW,
                                                         int16_t              *pY,
                                                         FFTLIB_bufParams1D_t *bufParamsY,
                                                         uint32_t             *pShift,
                                                         FFTLIB_bufParams1D_t *bufParamsShift,
                                                         void                 *pBlock);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
