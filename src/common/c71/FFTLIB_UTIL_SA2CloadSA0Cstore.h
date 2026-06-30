// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_SA2CLOADSA0CSTORE_H_
#define COMMON_FFTLIB_UTIL_SA2CLOADSA0CSTORE_H_ 1

/******************************************************************************/

/* ---------------------------------------------------------------- */
/*  MISRAC Rule 8.13(NEEDS.CONST) Deviation: CbackDestination cannot*/
/*  be declared with const qualifier because data is copied into    */
/*  buffer pointed by the pointer.                                  */
/* ---------------------------------------------------------------- */
/******************************************************************************/
/*!
 * \ingroup  fftlib_util
 * \brief
 * \details
 * \param[in] numRows         Number of rows to load and store
 * \param[in] CbackSource     Pointer to the source buffer for C-back data
 * \param[in] CbackDestination Pointer to the destination buffer for C-back data
 */
/******************************************************************************/

__INLINE_FUNC(FFTLIB_UTIL_SA2CloadSA0Cstore)
static inline void
FFTLIB_UTIL_SA2CloadSA0Cstore(int32_t numRows, const uint8_t *restrict CbackSource, uint8_t *restrict CbackDestination)
{
   int32_t   r;
   __mma_vec VB0;

#pragma LOOP_NO_ALIAS
   for (r = 0; r < numRows; r++) {
      __mma_vec valC = *c7x::strm_agen<2, __mma_vec>::get_adv(CbackSource);
      __HWALDC(valC);
      __HWAXFER(__MMA_XFER_SRC_C);
      VB0 = __HWARCV(0);
      __HWAADV();

      __vpred    tmp = c7x::strm_agen<0, __mma_vec>::get_vpred();
      __mma_vec *VB1 = c7x::strm_agen<0, __mma_vec>::get_adv(CbackDestination);
      __vstore_pred(tmp, VB1, VB0);
   }
   return;
}
#endif /* COMMON_FFTLIB_UTIL_SA2CLOADSA0CSTORE_H_ */
