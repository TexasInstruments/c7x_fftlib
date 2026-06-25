// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#include "../FFTLIB_types.h"
#include "FFTLIB_debug.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/******************************************************************************/

/******************************************************************************/
/*!
 * \ingroup
 * \brief
 * \details
 * \return  void
 */
/******************************************************************************/

void FFTLIB_debugPrintBufParams1D(const FFTLIB_bufParams1D_t *params)
{
   FFTLIB_PRINTF("   dim_x        = %d\n", params->dim_x);
   FFTLIB_PRINTF("   data_type    = %d\n", params->data_type);

   return;
}

void FFTLIB_debugPrintBufParams(const FFTLIB_bufParams2D_t *params)
{
   FFTLIB_PRINTF("   dim_x        = %d\n", params->dim_x);
   FFTLIB_PRINTF("   dim_y        = %d\n", params->dim_y);
   FFTLIB_PRINTF("   data_type    = %d\n", params->data_type);
   FFTLIB_PRINTF("   stride_y     = %d\n", params->stride_y);

   return;
}

void FFTLIB_debugPrintBufParams3D(const FFTLIB_bufParams3D_t *params)
{
   FFTLIB_PRINTF("   dim_x        = %d\n", params->dim_x);
   FFTLIB_PRINTF("   dim_y        = %d\n", params->dim_y);
   FFTLIB_PRINTF("   dim_z        = %d\n", params->dim_z);
   FFTLIB_PRINTF("   data_type    = %d\n", params->data_type);
   FFTLIB_PRINTF("   stride_y     = %d\n", params->stride_y);
   FFTLIB_PRINTF("   stride_z     = %d\n", params->stride_z);

   return;
}
#ifdef __cplusplus
}
#endif /* __cplusplus */
