// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_SE0BLOAD_H_
#define COMMON_FFTLIB_UTIL_SE0BLOAD_H_ 1

/******************************************************************************/

/******************************************************************************/
/*!
 * \ingroup fftlib_util
 * \brief
 * \details
 * \param[in] numRows
 * \return  void
 */
/******************************************************************************/

__INLINE_FUNC(FFTLIB_UTIL_SE0Bload)
static inline void FFTLIB_UTIL_SE0Bload(int32_t numRows)
{
   int32_t r;

   _nassert(numRows > 0);
   for (r = 0; r < numRows; r++) {
      __mma_vec valB = c7x::strm_eng<0, __mma_vec>::get_adv();
      __HWALDB(valB);
      __HWAADV();
   }

   return;
}
#endif /* COMMON_FFTLIB_UTIL_SE0BLOAD_H_ */
