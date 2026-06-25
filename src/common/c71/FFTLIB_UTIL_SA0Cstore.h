// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_SA0CSTORE_H_
#define COMMON_FFTLIB_UTIL_SA0CSTORE_H_ 1

/******************************************************************************/

/* ---------------------------------------------------------------- */
/*  MISRAC Rule 8.13(NEEDS.CONST) Deviation: CbackDestination cannot*/
/*  be declared with const qualifier because data is copied into    */
/*  buffer pointed by the pointer.                                  */
/* ---------------------------------------------------------------- */
/******************************************************************************/
/*!
 * \ingroup fftlib_util
 * \brief
 * \details
 * \param[in] numRows
 * \param[in] CbackDestination
 * \param[in] paramsC
 * \return  void
 */
/******************************************************************************/
#ifdef __cplusplus
#pragma FUNC_ALWAYS_INLINE
#else
#pragma FUNC_ALWAYS_INLINE(FFTLIB_UTIL_SA0Cstore)
#endif
static inline void FFTLIB_UTIL_SA0Cstore(int32_t numRows, uint8_t *CbackDestination)
{
   int32_t   r;
   __mma_vec VB0;

   for (r = 0; r < numRows; r++) {
      // move row of CBack to transfer buffer
      __HWAXFER(__MMA_XFER_SRC_C);
      // move row from transfer buffer to VB (data enters C7x core)
      VB0 = __HWARCV(0);
      __HWAADV();
      // move row from VB to memory
      __vpred    tmp = c7x::strm_agen<0, __mma_vec>::get_vpred();
      __mma_vec *VB1 = c7x::strm_agen<0, __mma_vec>::get_adv(CbackDestination);
      __vstore_pred(tmp, VB1, VB0);
   }
   return;
}

/* ---------------------------------------------------------------- */
/*  MISRAC Rule 8.13(NEEDS.CONST) Deviation: CbackDestination cannot*/
/*  be declared with const qualifier because data is copied into    */
/*  buffer pointed by the pointer.                                  */
/* ---------------------------------------------------------------- */
#ifdef __cplusplus
#pragma FUNC_ALWAYS_INLINE
#else
#pragma FUNC_ALWAYS_INLINE(FFTLIB_UTIL_SA0Cstore_unroll)
#endif
#ifdef __cplusplus
template <int32_t UNROLL_TIMES>
static inline void FFTLIB_UTIL_SA0Cstore_unroll(int32_t numRows, uint8_t *CbackDestination)
{
   int32_t   r;
   __mma_vec VB0;
   __vpred   tmp;
   FFTLIB_UNROLL(UNROLL_TIMES)
   for (r = 0; r < numRows; r++) {
      // move row of CBack to transfer buffer
      __HWAXFER(__MMA_XFER_SRC_C);
      // move row from transfer buffer to VB (data enters C7x core)
      VB0 = __HWARCV(0);
      __HWAADV();
      // move row from VB to memory
      tmp            = c7x::strm_agen<0, __mma_vec>::get_vpred();
      __mma_vec *VB1 = c7x::strm_agen<0, __mma_vec>::get_adv(CbackDestination);
      __vstore_pred(tmp, VB1, VB0);
   }
   return;
}
#endif
#endif /* COMMON_FFTLIB_UTIL_SA0CSTORE_H_ */
