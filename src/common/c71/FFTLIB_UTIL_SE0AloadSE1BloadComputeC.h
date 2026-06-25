// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_SE0ALOADSE1BLOADCOMPUTEC_H_
#define COMMON_FFTLIB_UTIL_SE0ALOADSE1BLOADCOMPUTEC_H_ 1

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
__INLINE_FUNC(FFTLIB_UTIL_SE0AloadSE1BloadComputeC)
static inline void FFTLIB_UTIL_SE0AloadSE1BloadComputeC(int32_t numRows)
{
   int32_t r;
   _nassert(numRows > 0);
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }
   return;
}

__INLINE_FUNC(FFTLIB_UTIL_SE0AloadSE1BloadComputeC_unroll16)
static inline void FFTLIB_UTIL_SE0AloadSE1BloadComputeC_unroll16(int32_t numRows)
{
   int32_t r;

   FFTLIB_UNROLL(16)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }
   return;
}

__INLINE_FUNC(FFTLIB_UTIL_SE0AloadSE1BloadComputeC_unroll32)
static inline void FFTLIB_UTIL_SE0AloadSE1BloadComputeC_unroll32(int32_t numRows)
{
   int32_t r;

   FFTLIB_UNROLL(32)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }
   return;
}

__INLINE_FUNC(FFTLIB_UTIL_SE0AloadSE1BloadComputeC_unroll64)
static inline void FFTLIB_UTIL_SE0AloadSE1BloadComputeC_unroll64(int32_t numRows)
{
   int32_t r;

   FFTLIB_UNROLL(64)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }
   return;
}

#ifdef __cplusplus
__INLINE_FUNC(FFTLIB_UTIL_SE0AloadSE1BloadComputeC_unroll)
template <int32_t UNROLL_TIMES> static inline void FFTLIB_UTIL_SE0AloadSE1BloadComputeC_unroll(int32_t numRows)
{
   int32_t r;

   FFTLIB_UNROLL(UNROLL_TIMES)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }
   return;
}
#endif

#ifdef __cplusplus
__INLINE_FUNC(FFTLIB_UTIL_SE0AloadSE1BloadComputeC_peel)
template <int32_t UNROLL_TIMES>
static inline void FFTLIB_UTIL_SE0AloadSE1BloadComputeC_peel(int32_t numRows, int32_t peelSize)
{
   int32_t r;

   FFTLIB_UNROLL(UNROLL_TIMES)
   for (r = 0; r < peelSize; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }

   _nassert(numRows > 0);
   for (r = peelSize; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }
   return;
}
#endif
#endif /* COMMON_FFTLIB_UTIL_SE0ALOADSE1BLOADCOMPUTEC_H_ */
