// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_SE1BLOAD_H_
#define COMMON_FFTLIB_UTIL_SE1BLOAD_H_ 1

/******************************************************************************/

/******************************************************************************/
/*!
 * \ingroup fftlib_util
 * \brief   load numRows of B into the Bload buffer
 * \details use streaming engine 1 to load numRows of B into the Bload buffer
 * \param  numRows
 * \return  void
 */
/******************************************************************************/
__INLINE_FUNC(FFTLIB_UTIL_SE1Bload)
static inline void FFTLIB_UTIL_SE1Bload(int32_t numRows)
{
   int32_t r;

   for (r = 0; r < numRows; r++) {
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDB(valB);
      __HWAADV();
   }

   return;
}
#endif /* COMMON_FFTLIB_UTIL_SE1BLOAD_H_ */
