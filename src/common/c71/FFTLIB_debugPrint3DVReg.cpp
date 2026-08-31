// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "../FFTLIB_bufParams.h"
#include "../FFTLIB_types.h"

/******************************************************************************/

/******************************************************************************/
/*!
 * \ingroup
 * \brief
 * \details
 * \return  void
 */
/******************************************************************************/

template <typename dataType> void FFTLIB_debugPrint3DVReg_helper(dataType *matrix, const FFTLIB_bufParams3D_t *params)
{
   uint32_t  r, c, t;
   dataType *xPtr;
   dataType *yPtr;
   dataType *zPtr = matrix;

   // stride_y is stored in bytes, but easier to use in elements
   uint32_t stride_y_elements = params->stride_y / FFTLIB_sizeof(params->data_type);
   uint32_t stride_z_elements = params->stride_z / FFTLIB_sizeof(params->data_type);

   FFTLIB_PRINTF("%s", "{\n");
   for (t = 0; t < params->dim_z; t++) {
      yPtr = zPtr;
      for (r = 0; r < params->dim_y; r++) {
         xPtr = yPtr;
         for (c = 0; c < params->dim_x; c++) {
            FFTLIB_PRINTF("%3d, ", static_cast<int>(*xPtr));
            xPtr++;
         }
         FFTLIB_PRINTF("%s", "\n");
         yPtr += stride_y_elements;
      }
      zPtr += stride_z_elements;
   }
   FFTLIB_PRINTF("%s", "};\n");
   return;
}

template void FFTLIB_debugPrint3DVReg_helper<int8_t>(int8_t *matrix, const FFTLIB_bufParams3D_t *params);
template void FFTLIB_debugPrint3DVReg_helper<int16_t>(int16_t *matrix, const FFTLIB_bufParams3D_t *params);
template void FFTLIB_debugPrint3DVReg_helper<int32_t>(int32_t *matrix, const FFTLIB_bufParams3D_t *params);


template <typename dataType> void FFTLIB_debugPrint3DVReg_helperU(dataType *matrix, const FFTLIB_bufParams3D_t *params)
{
   uint32_t  r, c, t;
   dataType *xPtr;
   dataType *yPtr;
   dataType *zPtr = matrix;

   // stride_y is stored in bytes, but easier to use in elements
   uint32_t stride_y_elements = params->stride_y / FFTLIB_sizeof(params->data_type);
   uint32_t stride_z_elements = params->stride_z / FFTLIB_sizeof(params->data_type);

   FFTLIB_PRINTF("%s", "{\n");
   for (t = 0; t < params->dim_z; t++) {
      yPtr = zPtr;
      for (r = 0; r < params->dim_y; r++) {
         xPtr = yPtr;
         for (c = 0; c < params->dim_x; c++) {
            FFTLIB_PRINTF("%3u, ", static_cast<unsigned int>(*xPtr));
            xPtr++;
         }
         FFTLIB_PRINTF("%s", "\n");
         yPtr += stride_y_elements;
      }
      zPtr += stride_z_elements;
   }
   FFTLIB_PRINTF("%s", "};\n");
   return;
}

template void FFTLIB_debugPrint3DVReg_helperU<uint16_t>(uint16_t *matrix, const FFTLIB_bufParams3D_t *params);

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

void FFTLIB_debugPrint3DVReg(void *matrix, const FFTLIB_bufParams3D_t *params)
{
   switch (params->data_type) {
   case FFTLIB_INT32:
      FFTLIB_debugPrint3DVReg_helper<int32_t>((int32_t *) matrix, params);
      break;
   case FFTLIB_INT16:
      FFTLIB_debugPrint3DVReg_helper<int16_t>((int16_t *) matrix, params);
      break;
   case FFTLIB_UINT16:
      FFTLIB_debugPrint3DVReg_helperU<uint16_t>((uint16_t *) matrix, params);
      break;
   case FFTLIB_INT8:
      FFTLIB_debugPrint3DVReg_helper<int8_t>((int8_t *) matrix, params);
      break;
   default:
      FFTLIB_PRINTF("\nERROR: Unrecognized data type in %s.\n", __FUNCTION__);
   }

   return;
}
#ifdef __cplusplus
}
#endif /* __cplusplus */
