// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "../FFTLIB_bufParams.h"
#include "../FFTLIB_types.h"
#include "../FFTLIB_utility.h"

//----------------------------------------------------------------------------------

template <typename dataType> void FFTLIB_debugPrintMatrix_helper(dataType *matrix, const FFTLIB_bufParams2D_t *params)
{
   uint32_t  x, y;
   dataType *xPtr;
   dataType *yPtr = matrix;

   // stride_y is stored in bytes, but easier to use in elements
   uint32_t stride_y_elements = params->stride_y / FFTLIB_sizeof(params->data_type);

   for (y = 0; y < params->dim_y; y++) {
      xPtr = yPtr;
      FFTLIB_PRINTF("%p |", xPtr);
      for (x = 0; x < params->dim_x; x++) {
         FFTLIB_PRINTF("%3d ", *(xPtr));
         xPtr++;
      }
      FFTLIB_PRINTF("%s", "|\n");
      yPtr += stride_y_elements;
   }

   return;
}

template void FFTLIB_debugPrintMatrix_helper<int8_t>(int8_t *matrix, const FFTLIB_bufParams2D_t *params);
template void FFTLIB_debugPrintMatrix_helper<uint8_t>(uint8_t *matrix, const FFTLIB_bufParams2D_t *params);
template void FFTLIB_debugPrintMatrix_helper<int16_t>(int16_t *matrix, const FFTLIB_bufParams2D_t *params);
template void FFTLIB_debugPrintMatrix_helper<uint16_t>(uint16_t *matrix, const FFTLIB_bufParams2D_t *params);
template void FFTLIB_debugPrintMatrix_helper<int32_t>(int32_t *matrix, const FFTLIB_bufParams2D_t *params);

/******************************************************************************/

/******************************************************************************/
/*!
 * \ingroup
 * \brief
 * \details
 * \return  void
 */
/******************************************************************************/

// want this function to have C-linkage in library...
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void FFTLIB_debugPrintMatrix(void *matrix, const FFTLIB_bufParams2D_t *params)
{
   switch (params->data_type) {
   case FFTLIB_INT32:
      FFTLIB_debugPrintMatrix_helper<int32_t>((int32_t *) matrix, params);
      break;
   case FFTLIB_INT16:
      FFTLIB_debugPrintMatrix_helper<int16_t>((int16_t *) matrix, params);
      break;
   case FFTLIB_UINT16:
      FFTLIB_debugPrintMatrix_helper<uint16_t>((uint16_t *) matrix, params);
      break;
   case FFTLIB_INT8:
      FFTLIB_debugPrintMatrix_helper<int8_t>((int8_t *) matrix, params);
      break;
   case FFTLIB_UINT8:
      FFTLIB_debugPrintMatrix_helper<uint8_t>((uint8_t *) matrix, params);
      break;
   default:
      FFTLIB_PRINTF("\nERROR: Unrecognized data type in %s.\n", __FUNCTION__);
   }

   return;
}
#ifdef __cplusplus
}
#endif /* __cplusplus */
