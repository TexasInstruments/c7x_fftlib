// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_FILLBPANEL_H_
#define COMMON_FFTLIB_UTIL_FILLBPANEL_H_ 1

#include "../FFTLIB_types.h"

/******************************************************************************/
/*!
 * \ingroup fftlib_util
 * @par Description:
 *  Load numRows of both B panels with the specified values
 *
 *  Functionality
 *            - Extract lower significant bits (8, 16 or 32 depending on dataType)
 *              and form a 512 bit vector by duplicating the value
 *            - Write this at row number indicated by startRow in both B panels
 *            - Repeat steps 1 and 2 for numRows times by advancing both the
 *              row number and pValue
 *
 * @par
 * @param [in] pValue    Pointer to a 1 dimensional array holding 32bit values.
                         There are numRows valid elements in the array. (SQ32.0)
 * @param [in] dataType  Data type of value 8-bit, 16-bit, 32-bit (signficant bits in the supplied value) (Q32.0)
 * @param [in] startRow  Starting row number in the B matrix (Q32.0)
 * @param [in] numRows   Total number of rows to fill in the B matrix (Q32.0)
 * \return  void
 */
/******************************************************************************/

#if !defined(__C7524__)
__INLINE_FUNC(FFTLIB_STATUS FFTLIB_UTIL_fillBPanel)
FFTLIB_STATUS FFTLIB_UTIL_fillBPanel(const int32_t *pValue, uint32_t dataType, uint32_t startRow, int32_t numRows)
{
   int32_t r;
   int32_t panel;

   // initialize the config to one of the common configurations
   FFTLIB_MMA_CONFIG_REG mmaConfig;
   switch (dataType) {
   case FFTLIB_INT8:
      mmaConfig = configRegisterStruct_i8s_i8s_o8s;
      break;
   case FFTLIB_INT16:
      mmaConfig = configRegisterStruct_i16s_i16s_o16s;
      break;
   default:
      mmaConfig = configRegisterStruct_i32s_i32s_o32s;
      break;
   }

   // initialize the offset register
   __HWA_OFFSET_REG mmaOffset = offsetRegStruct_zeros;

   // update MMA configuration based on function arguments
   // set starting row
   mmaConfig.B_BOFFSET = startRow;
   // swap panels after numRows
   mmaConfig.B_BSWPER = numRows;
   // reset after numRows
   mmaConfig.B_BRSTPER = numRows;

   // open MMA
   __HWAOPEN(mmaConfig, mmaOffset, __MMA_OPEN_FSM_RESET);
   __HWAADV();

   switch (dataType) {
   case FFTLIB_INT8: {
      int8_t fillValue; // using int8_t produces compiler warning?

      // loop over the B panels
      for (panel = 0; panel < 2; panel++) {
         // fill a B panel
         _nassert(numRows > 1);
         for (r = 0; r < numRows; r++) {
            // extract the fill value from pValue
            fillValue = (int8_t) pValue[r];
            // duplicate across vector
            c7x::char_vec VB0 = __duplicate(fillValue);
            __HWALDB(__as_mma_vec(VB0));
            __HWAADV();
         }
      }
      break;
   }
   case FFTLIB_INT16: {
      int16_t fillValue;

      // loop over the B panels
      for (panel = 0; panel < 2; panel++) {
         // fill the B panel
         _nassert(numRows > 1);
         for (r = 0; r < numRows; r++) {
            // extract the fill value from pValue
            fillValue = (int16_t) pValue[r];
            // duplicate across vector
            c7x::short_vec VB0 = __duplicate(fillValue);
            __HWALDB(__as_mma_vec(VB0));
            __HWAADV();
         }
      }
      break;
   }
   default: {
      int32_t fillValue;

      // loop over the B panels
      for (panel = 0; panel < 2; panel++) {
         // fill the B panel
         _nassert(numRows > 1);
         for (r = 0; r < numRows; r++) {
            // extract the fill value from pValue
            fillValue = (int32_t) pValue[r];
            // duplicate across vector
            c7x::int_vec VB0 = __duplicate(fillValue);
            __HWALDB(__as_mma_vec(VB0));
            __HWAADV();
         }
      }
      break;
   }
   }

   return FFTLIB_SUCCESS;
}
#endif // #if !defined(__C7524__)
#endif /* COMMON_FFTLIB_UTIL_FILLBPANEL_H_ */
