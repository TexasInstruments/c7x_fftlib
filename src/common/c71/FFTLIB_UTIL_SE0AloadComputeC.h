// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_SE0ALOADCOMPUTEC_H_
#define COMMON_FFTLIB_UTIL_SE0ALOADCOMPUTEC_H_ 1

/******************************************************************************/
/******************************************************************************/
/*!
 * \ingroup fftlib_util
 * \brief   use streaming engine 0 to load numRows of A
 *          compute C(row) = A(row) x Bfore(:,:)
 * \details
 * \param[in] numRows  Number of rows of A to load and compute
 */
/******************************************************************************/
#ifdef __cplusplus
#pragma FUNC_ALWAYS_INLINE
#else
#pragma FUNC_ALWAYS_INLINE(FFTLIB_UTIL_SE0AloadComputeC)
#endif
static inline void FFTLIB_UTIL_SE0AloadComputeC(int32_t numRows)
{
   int32_t r;

   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __HWALDA(valA);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }

   return;
}

#ifdef __cplusplus
#pragma FUNC_ALWAYS_INLINE
#else
#pragma FUNC_ALWAYS_INLINE(FFTLIB_UTIL_SE0AloadComputeC_unroll16)
#endif
static inline void FFTLIB_UTIL_SE0AloadComputeC_unroll16(int32_t numRows)
{
   int32_t r;
   FFTLIB_UNROLL(16)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __HWALDA(valA);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }

   return;
}

#ifdef __cplusplus
#pragma FUNC_ALWAYS_INLINE
#else
#pragma FUNC_ALWAYS_INLINE(FFTLIB_UTIL_SE0AloadComputeC_unroll32)
#endif
static inline void FFTLIB_UTIL_SE0AloadComputeC_unroll32(int32_t numRows)
{
   int32_t r;

   FFTLIB_UNROLL(32)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __HWALDA(valA);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }

   return;
}

#ifdef __cplusplus
#pragma FUNC_ALWAYS_INLINE
#else
#pragma FUNC_ALWAYS_INLINE(FFTLIB_UTIL_SE0AloadComputeC_unroll64)
#endif
static inline void FFTLIB_UTIL_SE0AloadComputeC_unroll64(int32_t numRows)
{
   int32_t r;

   FFTLIB_UNROLL(64)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __HWALDA(valA);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }

   return;
}

#ifdef __cplusplus
#pragma FUNC_ALWAYS_INLINE
#else
#pragma FUNC_ALWAYS_INLINE(FFTLIB_UTIL_SE0AloadComputeC_unroll)
#endif
#ifdef __cplusplus
template <int32_t UNROLL_TIMES> static inline void FFTLIB_UTIL_SE0AloadComputeC_unroll(int32_t numRows)
{
   int32_t r;

   FFTLIB_UNROLL(UNROLL_TIMES)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __HWALDA(valA);
      __HWAOP(__MMA_A_LDA);
      __HWAADV();
   }

   return;
}
#endif
#endif /* COMMON_FFTLIB_UTIL_SE0ALOADCOMPUTEC_H_ */
