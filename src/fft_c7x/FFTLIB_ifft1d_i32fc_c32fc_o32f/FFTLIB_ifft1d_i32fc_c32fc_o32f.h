// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef FFTLIB_IFFT1D_I32FC_C32FC_O32F_H_
#define FFTLIB_IFFT1D_I32FC_C32FC_O32F_H_ 1

#include "../../common/FFTLIB_types.h"

/*!
 * @defgroup FFTLIB_ifft1d_i32fc_c32fc_o32f FFTLIB_ifft1d_i32fc_c32fc_o32f
 * @brief Kernel for computing 32-bit floating-point complex to real IFFT
 *
 * @details
 *          - The kernel performs IFFT of an N-point complex sequence using
 *            N/2-point complex IFFT to output a real sequence,
 *            which saves compute time
 *          - The size of data is required to be a power of 2.
 *          - The kernel requires application to provide a pre-generated
 *            twiddle factors along with the input data.
 *          - The kernel requires application to provide a pre-generated
 *            split factors along with the input data.
 *          - Supported sizes: 128 to 8192
 * @ingroup  FFT_C7X
 */
/** @{ */

/*!
 * @brief Macro to define the array size for storing SE/SA parameters
 */

/* PBLOCK has to accommodate certain number of SE/SA configurations */
#define FFTLIB_IFFT1D_I32FC_C32FC_O32F_PBLOCK_SIZE (18 * SE_PARAM_SIZE)

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  @brief       This function should be called before the
 *               @ref FFTLIB_ifft1d_i32fc_c32fc_o32f_kernel function is
 * called. This function takes care of any one-time operations such as
 *               setting up the configuration for the streaming engine.
 *
 *  @param [in]  pX            :  Pointer to buffer with input data
 *  @param [in]  bufParamsX    :  Pointer to the structure containing
 *                                dimensional information of input buffer
 *  @param [in]  pW            :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW    :  Pointer to the structure containing
 *                                dimensional information of twiddle factor
 * buffer
 *  @param [in]  pXFFT         :  Pointer to buffer with input data
 *  @param [in]  bufParamsXFFT :  Pointer to the structure containing
 *                                dimensional information of of pXFFT buffer
 *  @param [in]  pSf           :  Pointer to buffer with split factors
 *  @param [in]  bufParamsSf   :  Pointer to the structure containing
 *                                dimensional information of split factor buffer
 *  @param [out] pY            :  Pointer to buffer with output data
 *  @param [in]  bufParamsY    :  Pointer to the structure containing
 *                                dimensional information of output buffer
 *  @param [out] pBlock        :  Pointer to the buffer that will hold the
 *                               streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS
FFTLIB_ifft1d_i32fc_c32fc_o32f_init(FFTLIB_F32*           pX,
                                    FFTLIB_bufParams1D_t* bufParamsX,
                                    FFTLIB_F32*           pW,
                                    FFTLIB_bufParams1D_t* bufParamsW,
                                    FFTLIB_F32*           pXFFT,
                                    FFTLIB_bufParams1D_t* bufParamsXFFT,
                                    FFTLIB_F32*           pSf,
                                    FFTLIB_bufParams1D_t* bufParamsSf,
                                    FFTLIB_F32*           pY,
                                    FFTLIB_bufParams1D_t* bufParamsY,
                                    void*                 pBlock);

/*!
 *  @brief       This function is the main kernel compute function.
 *
 *  @param [in]  pX            :  Pointer to buffer with input data
 *  @param [in]  bufParamsX    :  Pointer to the structure containing
 *                                dimensional information of input buffer
 *  @param [in]  pW            :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW    :  Pointer to the structure containing
 *                                dimensional information of twiddle factor
 * buffer
 *  @param [in]  pXFFT         :  Pointer to temp. buffer with FFT of input data
 *  @param [in]  bufParamsXFFT :  Pointer to the structure containing
 *                                dimensional information of of pXFFT buffer
 *  @param [in]  pSf           :  Pointer to buffer with split factors
 *  @param [in]  bufParamsSf   :  Pointer to the structure containing
 *                                dimensional information of split factor buffer
 *  @param [out] pY            :  Pointer to buffer with output data
 *  @param [in]  bufParamsY    :  Pointer to the structure containing
 *                                dimensional information of output buffer
 *  @param [in]  pBlock        :  Pointer to the buffer that will hold the
 *                               streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref FFTLIB_STATUS.
 *
 */

FFTLIB_STATUS
FFTLIB_ifft1d_i32fc_c32fc_o32f_kernel(FFTLIB_F32* restrict pX,
                                      FFTLIB_bufParams1D_t* bufParamsX,
                                      FFTLIB_F32* restrict pW,
                                      FFTLIB_bufParams1D_t* bufParamsW,
                                      FFTLIB_F32* restrict pXFFT,
                                      FFTLIB_bufParams1D_t* bufParamsXFFT,
                                      FFTLIB_F32* restrict pSf,
                                      FFTLIB_bufParams1D_t* bufParamsSf,
                                      FFTLIB_F32* restrict pY,
                                      FFTLIB_bufParams1D_t* bufParamsY,
                                      void*                 pBlock);

/*!
 *  @brief       This function checks the validity of the parameters passed
 *               to
 *               @ref FFTLIB_ifft1d_i32fc_c32fc_o32f_init and
 *               @ref FFTLIB_ifft1d_i32fc_c32fc_o32f_kernel functions.
 *
 *  @param [in]  pX           :  Pointer to buffer with input data
 *  @param [in]  bufParamsX   :  Pointer to the structure containing
 *                               dimensional information of input buffer
 *  @param [in]  pW           :  Pointer to buffer with twiddle factors
 *  @param [in]  bufParamsW   :  Pointer to the structure containing
 *                               dimensional information of twiddle factor
 *                               buffer
 *  @param [out] pY           :  Pointer to buffer with output data
 *  @param [in]  bufParamsY   :  Pointer to the structure containing
 *                               dimensional
 *  @param [in]  pBlock       :  Pointer to the buffer that will hold the
 *                               streaming engine parameters
 *
 *  @return      Status value indicating success or failure. Refer to @ref FFTLIB_STATUS.
 */

FFTLIB_STATUS
FFTLIB_ifft1d_i32fc_c32fc_o32f_checkParams(FFTLIB_F32*           pX,
                                           FFTLIB_bufParams1D_t* bufParamsX,
                                           FFTLIB_F32*           pW,
                                           FFTLIB_bufParams1D_t* bufParamsW,
                                           FFTLIB_F32*           pY,
                                           FFTLIB_bufParams1D_t* bufParamsY,
                                           void*                 pBlock);

/*! @brief Generate split factors for complex-to-real IFFT.
 *  @param [out] pSFactor  Pointer to buffer where split factors are stored
 *  @param [in]  numPoints FFT size
 */
void ifft_c2r_split_factor_gen(FFTLIB_F32* pSFactor, int32_t numPoints);
/*! @brief Generate twiddle factors for complex-to-real IFFT.
 *  @param [out] pW        Pointer to buffer where twiddle factors are stored
 *  @param [in]  numPoints FFT size
 */
void ifft_c2r_tw_gen(FFTLIB_F32* pW, int32_t numPoints);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
