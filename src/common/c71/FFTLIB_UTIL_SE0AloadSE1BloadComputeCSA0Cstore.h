// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_SE0ALOADSE1BLOADCOMPUTECSA0CSTORE_H_
#define COMMON_FFTLIB_UTIL_SE0ALOADSE1BLOADCOMPUTECSA0CSTORE_H_ 1

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
 * \return  void
 */
/******************************************************************************/

__INLINE_FUNC(FFTLIB_UTIL_SE0AloadSE1BloadComputeCSA0Cstore)
static inline void FFTLIB_UTIL_SE0AloadSE1BloadComputeCSA0Cstore(int32_t numRows, uint8_t *CbackDestination)
{
   int32_t   r;
   __mma_vec VB0;

   _nassert(numRows > 0);
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);

      __HWAOPXFER(__MMA_A_LDA);
      // move row from transfer buffer to VB
      VB0 = __HWARCV((uint32_t) 0);
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

__INLINE_FUNC(FFTLIB_UTIL_SE0AloadSE1BloadComputeCSA0Cstore_unroll)
template <int32_t UNROLL_TIMES>
static inline void FFTLIB_UTIL_SE0AloadSE1BloadComputeCSA0Cstore_unroll(int32_t numRows, uint8_t *CbackDestination)
{
   int32_t   r;
   __mma_vec VB0;

   FFTLIB_UNROLL(UNROLL_TIMES)
   for (r = 0; r < numRows; r++) {
      __mma_vec valA = c7x::strm_eng<0, __mma_vec>::get_adv();
      __mma_vec valB = c7x::strm_eng<1, __mma_vec>::get_adv();
      __HWALDAB(valA, valB);

      __HWAOPXFER(__MMA_A_LDA);
      // move row from transfer buffer to VB
      VB0 = __HWARCV((uint32_t) 0);
      __HWAADV();

      // move row from VB to memory
      __vpred    tmp = c7x::strm_agen<0, __mma_vec>::get_vpred();
      __mma_vec *VB1 = c7x::strm_agen<0, __mma_vec>::get_adv(CbackDestination);
      __vstore_pred(tmp, VB1, VB0);
   }
   return;
}
#endif /* COMMON_FFTLIB_UTIL_SE0ALOADSE1BLOADCOMPUTECSA0CSTORE_H_ */
