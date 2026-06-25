// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "../../../common/c71/FFTLIB_inlines.h"
#include "../FFTLIB_FFT_dftLarge_ixX_cxX_oxX_priv.h"

void FFTLIB_FFT_dftLarge_ixX_cxX_oxX_perfEst(FFTLIB_kernelHandle         handle,
                                             const FFTLIB_bufParams1D_t *bufParamsX,
                                             const FFTLIB_bufParams1D_t *bufParamsY,
                                             const FFTLIB_bufParams1D_t *bufParamsW,
                                             uint32_t                    fftSize,
                                             uint32_t                    batchSize,
                                             uint64_t                   *archCycles,
                                             uint64_t                   *estCycles)
{
   FFTLIB_bufParams2D_t bufParamsMatrixData, bufParamsMatrixW;
   int32_t              caseNumber;
   int32_t              startupCycles, teardownCycles;

   bufParamsMatrixData.dim_x     = fftSize * 2;
   bufParamsMatrixData.dim_y     = batchSize;
   bufParamsMatrixData.stride_y  = fftSize * 2 * FFTLIB_sizeof(bufParamsX->data_type);
   bufParamsMatrixData.data_type = bufParamsX->data_type;
   bufParamsMatrixW.dim_x        = fftSize * 2;
   bufParamsMatrixW.dim_y        = fftSize * 2;
   bufParamsMatrixW.stride_y     = fftSize * 2 * FFTLIB_sizeof(bufParamsW->data_type);
   bufParamsMatrixW.data_type    = bufParamsW->data_type;

   startupCycles = 3; // dftLarge exec()

   FFTLIB_LINALG_matrixMatrixMultiply_ixX_ixX_oxX_perfEst(handle, &bufParamsMatrixData, &bufParamsMatrixW,
                                                          &bufParamsMatrixData, archCycles, estCycles, &caseNumber);

   teardownCycles = 3; // dftLarge exec()

   *archCycles = startupCycles + *archCycles + teardownCycles;
   *estCycles  = startupCycles + *estCycles + teardownCycles;

   return;
}

template <uint32_t dataType>
FFTLIB_STATUS FFTLIB_FFT_dftLarge_ixX_cxX_oxX_getSizes(const FFTLIB_FFT_dftLarge_ixX_cxX_oxX_InitArgs *pKerInitArgs,
                                                       FFTLIB_bufParams1D_t                           *bufParamsX,
                                                       FFTLIB_bufParams1D_t                           *bufParamsW,
                                                       FFTLIB_bufParams1D_t                           *bufParamsY)
{
   uint32_t      fftSize   = pKerInitArgs->fftSize;
   uint32_t      batchSize = pKerInitArgs->batchSize;
   uint32_t      MMA_SIZE;
   FFTLIB_STATUS status = FFTLIB_SUCCESS;

   if (dataType == FFTLIB_INT32) {
      MMA_SIZE = FFTLIB_MMA_SIZE_32_BIT;
   }
   else if (dataType == FFTLIB_INT16) {
      MMA_SIZE = FFTLIB_MMA_SIZE_16_BIT;
   }
   else {
      status = FFTLIB_ERR_NOT_IMPLEMENTED;
   }

   if (fftSize <= MMA_SIZE / 2) {
      status = FFTLIB_ERR_INVALID_DIMENSION;
   }

   if (status == FFTLIB_SUCCESS) {
      bufParamsX->dim_x = batchSize * fftSize * 2;
      bufParamsY->dim_x = batchSize * fftSize * 2;
      bufParamsW->dim_x = fftSize * 2 * fftSize * 2;
   }

   return status;
}

template FFTLIB_STATUS
FFTLIB_FFT_dftLarge_ixX_cxX_oxX_getSizes<FFTLIB_INT16>(const FFTLIB_FFT_dftLarge_ixX_cxX_oxX_InitArgs *pKerInitArgs,
                                                       FFTLIB_bufParams1D_t                           *bufParamsX,
                                                       FFTLIB_bufParams1D_t                           *bufParamsW,
                                                       FFTLIB_bufParams1D_t                           *bufParamsY);
template FFTLIB_STATUS
FFTLIB_FFT_dftLarge_ixX_cxX_oxX_getSizes<FFTLIB_INT32>(const FFTLIB_FFT_dftLarge_ixX_cxX_oxX_InitArgs *pKerInitArgs,
                                                       FFTLIB_bufParams1D_t                           *bufParamsX,
                                                       FFTLIB_bufParams1D_t                           *bufParamsW,
                                                       FFTLIB_bufParams1D_t                           *bufParamsY);

template <typename dataType>
FFTLIB_STATUS FFTLIB_FFT_dftLarge_ixX_cxX_oxX_twGen(const FFTLIB_FFT_dftLarge_ixX_cxX_oxX_InitArgs *pKerInitArgs,
                                                    void *restrict pW,
                                                    const FFTLIB_bufParams1D_t *bufParamsW)
{
   FFTLIB_STATUS        status = FFTLIB_SUCCESS;
   uint32_t             j, k;
   const FFTLIB_D64     PI = 3.141592654;
   FFTLIB_D64           twF2sScale;
   FFTLIB_bufParams1D_t bufParamsXLocal, bufParamsYLocal, bufParamsWLocal;
   dataType            *pWLocal    = (dataType *) pW;
   uint32_t             fftSize    = pKerInitArgs->fftSize;
   uint32_t             interleave = pKerInitArgs->interleave;

   if (sizeof(dataType) == 4) {
      status = FFTLIB_FFT_dftLarge_ixX_cxX_oxX_getSizes<FFTLIB_INT32>(pKerInitArgs, &bufParamsXLocal, &bufParamsWLocal,
                                                                      &bufParamsYLocal);
   }
   else if (sizeof(dataType) == 2) {
      status = FFTLIB_FFT_dftLarge_ixX_cxX_oxX_getSizes<FFTLIB_INT16>(pKerInitArgs, &bufParamsXLocal, &bufParamsWLocal,
                                                                      &bufParamsYLocal);
   }
   else {
      status = FFTLIB_ERR_NOT_IMPLEMENTED;
   }

   if (bufParamsW->dim_x != bufParamsWLocal.dim_x) {
      status = FFTLIB_ERR_INVALID_DIMENSION;
   }

   if (status == FFTLIB_SUCCESS) {
      twF2sScale = ((uint32_t) 1 << ((uint32_t) (sizeof(dataType) * 8 - 2))) - 1;
      twF2sScale += ((uint32_t) 1 << ((uint32_t) (sizeof(dataType) * 8 - 2)));
      twF2sScale += 0.5;
      if (interleave) {
         for (j = 0; j < fftSize; j++) {
            for (k = 0; k < fftSize; k++) {
               pWLocal[j * 2 * fftSize * 2 + k * 2] =
                   FFTLIB_UTIL_cos_i64f_oxX<dataType>(2 * PI * j * k / fftSize, twF2sScale);
               pWLocal[j * 2 * fftSize * 2 + k * 2 + 1] =
                   -FFTLIB_UTIL_sin_i64f_oxX<dataType>(2 * PI * j * k / fftSize, twF2sScale);
            }
            for (k = 0; k < fftSize; k++) {
               pWLocal[(j * 2 + 1) * fftSize * 2 + k * 2] =
                   FFTLIB_UTIL_sin_i64f_oxX<dataType>(2 * PI * j * k / fftSize, twF2sScale);
               pWLocal[(j * 2 + 1) * fftSize * 2 + k * 2 + 1] =
                   FFTLIB_UTIL_cos_i64f_oxX<dataType>(2 * PI * j * k / fftSize, twF2sScale);
            }
         }
      }
      else {
         for (j = 0; j < fftSize; j++) {
            for (k = 0; k < fftSize; k++) {
               pWLocal[j * fftSize * 2 + k] = FFTLIB_UTIL_cos_i64f_oxX<dataType>(2 * PI * j * k / fftSize, twF2sScale);
               pWLocal[j * fftSize * 2 + fftSize + k] =
                   -FFTLIB_UTIL_sin_i64f_oxX<dataType>(2 * PI * j * k / fftSize, twF2sScale);
            }
            for (k = 0; k < fftSize; k++) {
               pWLocal[fftSize * fftSize * 2 + j * fftSize * 2 + k] =
                   FFTLIB_UTIL_sin_i64f_oxX<dataType>(2 * PI * j * k / fftSize, twF2sScale);
               pWLocal[fftSize * fftSize * 2 + j * fftSize * 2 + fftSize + k] =
                   FFTLIB_UTIL_cos_i64f_oxX<dataType>(2 * PI * j * k / fftSize, twF2sScale);
            }
         }
      }
   }

   return status;
}

template FFTLIB_STATUS
FFTLIB_FFT_dftLarge_ixX_cxX_oxX_twGen<int16_t>(const FFTLIB_FFT_dftLarge_ixX_cxX_oxX_InitArgs *pKerInitArgs,
                                               void *restrict pW,
                                               const FFTLIB_bufParams1D_t *bufParamsW);

template FFTLIB_STATUS
FFTLIB_FFT_dftLarge_ixX_cxX_oxX_twGen<int32_t>(const FFTLIB_FFT_dftLarge_ixX_cxX_oxX_InitArgs *pKerInitArgs,
                                               void *restrict pW,
                                               const FFTLIB_bufParams1D_t *bufParamsW);
