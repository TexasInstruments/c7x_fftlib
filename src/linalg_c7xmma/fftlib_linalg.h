// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef _FFTLIB_LINALG_H_
#define _FFTLIB_LINALG_H_

#include "FFTLIB_LINALG_matrixMatrixMultiplyAccumulate_ixX_ixX_ixX_oxX/FFTLIB_LINALG_matrixMatrixMultiplyAccumulate_ixX_ixX_ixX_oxX.h"
#include "FFTLIB_LINALG_matrixMatrixMultiply_ixX_ixX_oxX/FFTLIB_LINALG_matrixMatrixMultiply_ixX_ixX_oxX.h"
#include "FFTLIB_LINALG_matrixTranspose_ixX_oxX/FFTLIB_LINALG_matrixTranspose_ixX_oxX.h"
#include "FFTLIB_LINALG_pointwiseMatrixMatrixMultiply_ixX_ixX_oxX/FFTLIB_LINALG_pointwiseMatrixMatrixMultiply_ixX_ixX_oxX.h"

#endif /*_FFTLIB_LINALG_H_*/

/*!
 * \defgroup FFTLIB_LINALG Linear Algebra (LINALG) kernels
 * \brief This module consists of kernels within the linear algebra scope.
 * \details
 *   - Data is 8, 16 or 32 bit signed integer type with all inputs and output of the same type)
 *   - Overflow is handled via saturation
 */
