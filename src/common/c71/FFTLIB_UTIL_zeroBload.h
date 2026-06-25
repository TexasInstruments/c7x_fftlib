// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_ZEROBLOAD_H_
#define COMMON_FFTLIB_UTIL_ZEROBLOAD_H_ 1

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
__INLINE_FUNC(FFTLIB_UTIL_zeroBload)
static inline void FFTLIB_UTIL_zeroBload(int32_t numRows)
{
   int32_t   r;
   __mma_vec zeroVect = (__mma_vec) (0x00);

   for (r = 0; r < numRows; r++) {
      __HWALDB(zeroVect);
      __HWAADV();
   }

   return;
}

__INLINE_FUNC(FFTLIB_UTIL_zeroBload_unroll32)
static inline void FFTLIB_UTIL_zeroBload_unroll32(int32_t numRows)
{
   int32_t   r;
   __mma_vec zeroVect = (__mma_vec) (0);

   FFTLIB_UNROLL(32)
   for (r = 0; r < numRows; r++) {
      __HWALDB(zeroVect);
      __HWAADV();
   }

   return;
}

__INLINE_FUNC(FFTLIB_UTIL_zeroBload_unroll)
template <int32_t UNROLL_TIMES> static inline void FFTLIB_UTIL_zeroBload_unroll(int32_t numRows)
{
   int32_t   r;
   __mma_vec zeroVect = (__mma_vec) (0);

   FFTLIB_UNROLL(UNROLL_TIMES)
   for (r = 0; r < numRows; r++) {
      __HWALDB(zeroVect);
      __HWAADV();
   }

   return;
}

#endif /* COMMON_FFTLIB_UTIL_ZEROBLOAD_H_ */
