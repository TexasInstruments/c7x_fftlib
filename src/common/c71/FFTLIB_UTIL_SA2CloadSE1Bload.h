// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_SA2CLOADSE1BLOAD_H_
#define COMMON_FFTLIB_UTIL_SA2CLOADSE1BLOAD_H_ 1

/******************************************************************************/

/******************************************************************************/
/*!
 * \ingroup fftlib_util
 * \brief
 * \details
 * \param[in] numRows    Number of rows to load
 * \param[in] CbackSource Pointer to the C-back source data buffer
 */
/******************************************************************************/

__INLINE_FUNC(FFTLIB_UTIL_SA2CloadSE1Bload)
static inline void FFTLIB_UTIL_SA2CloadSE1Bload(int32_t numRows, const void *restrict CbackSource)
{
   int32_t r;

   for (r = 0; r < numRows; r++) {
      __mma_vec valC = *c7x::strm_agen<2, __mma_vec>::get_adv(CbackSource);
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDBC(valB, valC);
      __HWAADV();
   }
   return;
}
#endif /* COMMON_FFTLIB_UTIL_SA2CLOADSE1BLOAD_H_ */
