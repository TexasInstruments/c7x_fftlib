// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#ifndef C71_FFTLIB_DEBUG_H_
#define C71_FFTLIB_DEBUG_H_ 1

#include <float.h>  // for max float, double values
#include <limits.h> // for min, max integer values

#include "../FFTLIB_bufParams.h"
#include "../FFTLIB_types.h"

#include "FFTLIB_debugPrintVector.h"

/*******************************************************************************
 *
 * Function prototypes
 *
 ******************************************************************************/

#ifdef __cplusplus

extern "C" {
#endif /* __cplusplus */

void FFTLIB_debugPrintMatrix1D(void *matrix, const FFTLIB_bufParams1D_t *params);
void FFTLIB_debugPrintMatrix(void *matrix, const FFTLIB_bufParams2D_t *params);
void FFTLIB_debugPrintMatrix3D(void *matrix, const FFTLIB_bufParams3D_t *params);

void FFTLIB_debugPrint3DVReg(void *matrix, const FFTLIB_bufParams3D_t *params);
void FFTLIB_debugPrintBufParams1D(const FFTLIB_bufParams1D_t *params);
void FFTLIB_debugPrintBufParams(const FFTLIB_bufParams2D_t *params);
void FFTLIB_debugPrintBufParams3D(const FFTLIB_bufParams3D_t *params);

void FFTLIB_debugPrintMMAReg(const int32_t regNumber);

/******************************************************************************/

//#if defined(_HOST_BUILD)
//   // x86 GCC assembly code for printing the stack pointer
//   // this version defines the function in asm, which avoid all compiler warnings
//   // if this stops working, a simpler version is commented below
//   unsigned long *get_stack_ptr(void);
//   __asm__(
//          "get_stack_ptr:\n"
//          "mov %rsp, %rax\n"
//          "ret\n"
//          );
//
//   static inline unsigned long *get_stack_ptr(void) {
//      __asm__(
//              "mov %rsp, %rax"
//              );
//#define FFTLIB_DEBUGPRINT_STACK_PTR FFTLIB_DEBUGPRINTFN(1, "Stack Pointer: %p\n", get_stack_ptr())
//#else
//#define FFTLIB_DEBUGPRINT_STACK_PTR
//#endif  // #if defined(_HOST_BUILD)

//   static inline void FFTLIB_debugPrintStackPtr(void){
//#if defined(_HOST_BUILD)
//      unsigned long *stack_ptr = get_stack_ptr();
//#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

// C++ linkage only
#ifdef __cplusplus

static inline uint8_t FFTLIB_firstElement(c7x::uchar_vec vector) { return *((uint8_t *) (&vector)); }

static inline int8_t FFTLIB_firstElement(c7x::char_vec vector) { return *((int8_t *) (&vector)); }

static inline uint16_t FFTLIB_firstElement(c7x::ushort_vec vector) { return *((uint16_t *) (&vector)); }

static inline int16_t FFTLIB_firstElement(c7x::short_vec vector) { return *((int16_t *) (&vector)); }

#endif // #ifdef __cplusplus

#endif /* C71_FFTLIB_DEBUG_H_ */
