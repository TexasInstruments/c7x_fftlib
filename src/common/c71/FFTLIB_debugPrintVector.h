// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef COMMON_FFTLIB_UTIL_DEBUGPRINTVECTOR_H_
#define COMMON_FFTLIB_UTIL_DEBUGPRINTFECTOR_H_ 1

#include "../FFTLIB_types.h"

//----------------------------------------------------------------------------------
#ifdef __cplusplus
#include <c7x_scalable.h> // for device scalability

#pragma FUNC_ALWAYS_INLINE
static inline void FFTLIB_debugPrintVector(c7x::uchar_vec vector)
{
#if FFTLIB_DEBUGPRINT
   for (uint i = 0; i < c7x::element_count_of<c7x::uchar_vec>::value; i++) {
      FFTLIB_PRINTF("%04u", *((uchar*) (&vector) + i));
   }

   FFTLIB_PRINTF("%s", "\n");
#endif
}

#pragma FUNC_ALWAYS_INLINE
static inline void FFTLIB_debugPrintVector(c7x::char_vec vector)
{
#if FFTLIB_DEBUGPRINT
   for (uint i = 0; i < c7x::element_count_of<c7x::char_vec>::value; i++) {
      FFTLIB_PRINTF("%04d", *((int8_t*) (&vector) + i));
   }

   FFTLIB_PRINTF("%s", "\n");
#endif
}

#pragma FUNC_ALWAYS_INLINE
static inline void FFTLIB_debugPrintVector(c7x::ushort_vec vector)
{
#if FFTLIB_DEBUGPRINT
   for (uint i = 0; i < c7x::element_count_of<c7x::ushort_vec>::value; i++) {
      FFTLIB_PRINTF("%05u", *((ushort*) (&vector) + i));
   }

   FFTLIB_PRINTF("%s", "\n");
#endif
}

#pragma FUNC_ALWAYS_INLINE
static inline void FFTLIB_debugPrintVector(c7x::short_vec vector)
{
#if FFTLIB_DEBUGPRINT
   for (uint i = 0; i < c7x::element_count_of<c7x::short_vec>::value; i++) {
      FFTLIB_PRINTF("%05d", *((short*) (&vector) + i));
   }

   FFTLIB_PRINTF("%s", "\n");
#endif
}

#pragma FUNC_ALWAYS_INLINE
static inline void FFTLIB_debugPrintVector(c7x::uint_vec vector)
{
#if FFTLIB_DEBUGPRINT
   for (uint i = 0; i < c7x::element_count_of<c7x::uint_vec>::value; i++) {
      FFTLIB_PRINTF("%010u", *((uint*) (&vector) + i));
   }

   FFTLIB_PRINTF("%s", "\n");
#endif
}

#pragma FUNC_ALWAYS_INLINE
static inline void FFTLIB_debugPrintVector(c7x::int_vec vector)
{
#if FFTLIB_DEBUGPRINT
   for (uint i = 0; i < c7x::element_count_of<c7x::int_vec>::value; i++) {
      FFTLIB_PRINTF("%010d", *((int*) (&vector) + i));
   }

   FFTLIB_PRINTF("%s", "\n");
#endif
}

#pragma FUNC_ALWAYS_INLINE
static inline void FFTLIB_debugPrintVectorInHex(c7x::long_vec vector)
{
#if FFTLIB_DEBUGPRINT
   for (uint i = 0; i < c7x::element_count_of<c7x::long_vec>::value; i++) {
      FFTLIB_PRINTF("%016lx", *((long*) (&vector) + i));
   }

   FFTLIB_PRINTF("%s", "\n");
#endif
}

#pragma FUNC_ALWAYS_INLINE
static inline void FFTLIB_debugPrintFloatVector(c7x::float_vec reg)
{
   uint32_t elementCount = c7x::element_count_of<c7x::float_vec>::value;
   uint32_t i            = 0;
   for (i = 0; i < elementCount; i++) {
      printf("%.2f, ", reg.s[i]);
   }
   printf("%s", "\n");

   /*    int32_t c; */
   /*    float  *elementPtr = (float *) (&var0); */

   /*    for (c = 0; c < 8; c++) { */
   /*       printf ("%.2f ", (*elementPtr)); */
   /*       elementPtr++; */
   /*    } */
   /*    printf ("%s", "\n"); */
}

#endif //#ifdef __cplusplus
#endif /* COMMON_FFTLIB_UTIL_DEBUGPRINTVECTOR_H_ */
