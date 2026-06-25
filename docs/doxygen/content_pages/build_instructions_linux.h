// Copyright (C) 2026 Texas Instruments Incorporated
//
// SPDX-License-Identifier: Apache-2.0

#if defined(__C7100__)
/**

 \page build_instructions_linux Ubuntu 22.04 Build Instructions for FFTLIB

 \par Python3 Setup

 - We auto generate test cases via python scripts packaged in the library

 - Please ensure that you have the  following python3 packages installed

   - numpy, scipy, and scikit-learn

 \par Environment Setup

  - Run the executables on EVM using CCS (Code composer studio)

  - Setup needed for the compiler for CGT7x
    - Download [CGT7x Compiler Installer](https://www.ti.com/tool/C7000-CGT) and install
    - export CGT7X_ROOT=${CGT7X_COMPILER_DIR}

  - Path setup
    - export PATH=${CGT7X_ROOT}/bin:${PATH}

 \par Build

  - FFTLIB utilizes CMake to build, ensure that system has CMake v3.16.0 or higher
  - Build options:
    - SOC=AM62A/j721e/j721s2/j784s4/j722s/AM275
    - DEVICE=C7504/C7100/C7120/C7524/C7524
    - TARGET_PLATFORM=PC
    - KERNEL_NAME
    - BUILD_TEST=1 OR AUTO_TEST=1
    - FFTLIB_DEBUGPRINT=1/0
    - FFTLIB_TESTPRINT
    - ALL_TEST_CASES=1 OR TEST_CASE=TestCaseID
    - CMAKE_EXPORT_COMPILE_COMMANDS=TRUE
    - CMAKE_BUILD_TYPE=Release/Debug
    - AUTO_TEST=1/0 (builds all test cases and libraries)
  - Example CMake commands
    - To build fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc for target on J721E and run performance test cases:
      - \code cmake -B build -DTARGET_PLATFORM="" -DBUILD_TEST="1"
-DKERNEL_NAME="fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc" -DSOC="j721e" \
-DDEVICE="C7100" -DFFTLIB_DEBUGPRINT="0" -DALL_TEST_CASES="1" -DCMAKE_EXPORT_COMPILE_COMMANDS="TRUE" \
-DCMAKE_BUILD_TYPE="Release" \endcode
    - To build fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc for host emulation on J721E and run test case 2 with debug
print statements
        - \code cmake -B build -DTARGET_PLATFORM="PC" -DBUILD_TEST="1"
-DKERNEL_NAME="fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc" -DSOC="j721e" \
-DDEVICE="C7100" -DFFTLIB_DEBUGPRINT="1" -DTEST_CASE="2" -DCMAKE_EXPORT_COMPILE_COMMANDS="TRUE" \
-DCMAKE_BUILD_TYPE="Release" \endcode
    -  To build all tests cases and libraries for release for J721E for target
        - \code cmake -B build -DTARGET_PLATFORM="" -DAUTO_TEST="1" -DSOC="j721e" -DDEVICE="C7100" \
-DALL_TEST_CASES="1" -DCMAKE_BUILD_TYPE="Release" -DFFTLIB_DEBUGPRINT="0" \endcode
    - Then run:
        - \code cmake --build build -j<num_cores> \endcode
    - Note: AUTO_TEST binaries don't run on AM275 due lack of external memory; please build binaries with TEST_CASE flag

 \par Run

  - To run FFTLIB kernels on a PC:
    - \code bin/Release/test_FFTLIB_<kernel_name>_<device>_x86_64 \endcode OR \code
bin/Debug/test_FFTLIB_<kernel_name>_<device>_x86_64 \endcode
      - Ex: \code bin/Release/test_FFTLIB_and_C7100_x86_64 \endcode
  - To run FFTLIB kernels for target
    - To reproduce numbers given in the datasheet, run the .out program on the EVM in No Boot Mode

*/

#elif defined(__C7120__)
/**

 \page build_instructions_linux Ubuntu 22.04 Build Instructions for FFTLIB

 \par Python3 Setup

 - We auto generate test cases via python scripts packaged in the library

 - Please ensure that you have the  following python3 packages installed

   - numpy, scipy, and scikit-learn

 \par Environment Setup

  - Run the executables on EVM using CCS (Code composer studio)

  - Setup needed for the compiler for CGT7x
    - Download [CGT7x Compiler Installer](https://www.ti.com/tool/C7000-CGT) and install
    - export CGT7X_ROOT=${CGT7X_COMPILER_DIR}

  - Path setup
    - export PATH=${CGT7X_ROOT}/bin:${PATH}

 \par Build

  - FFTLIB utilizes CMake to build, ensure that system has CMake v3.16.0 or higher
  - Build options:
    - SOC=AM62A/j721e/j721s2/j784s4/j722s
    - DEVICE=C7504/C7100/C7120/C7524
    - TARGET_PLATFORM=PC/""
    - KERNEL_NAME
    - BUILD_TEST=1 OR AUTO_TEST=1
    - FFTLIB_DEBUGPRINT=1/0
    - FFTLIB_TESTPRINT
    - ALL_TEST_CASES=1 OR TEST_CASE=TestCaseID
    - CMAKE_EXPORT_COMPILE_COMMANDS=TRUE
    - CMAKE_BUILD_TYPE=Release/Debug
    - AUTO_TEST=1/0 (builds all test cases and libraries)
  - Example CMake commands
    - To build fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc for target on J721S2 and run performance test cases:
      - \code cmake -B build -DTARGET_PLATFORM="" -DBUILD_TEST="1"
-DKERNEL_NAME="fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc" -DSOC="j721s2" \
-DDEVICE="C7120" -DFFTLIB_DEBUGPRINT="0" -DALL_TEST_CASES="1" -DCMAKE_EXPORT_COMPILE_COMMANDS="TRUE" \
-DCMAKE_BUILD_TYPE="Release" \endcode
    - To build fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc for host emulation on J721S2 and run test case 2 with debug
print statements
        - \code cmake -B build -DTARGET_PLATFORM="PC" -DBUILD_TEST="1"
-DKERNEL_NAME="fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc" -DSOC="j721s2" \
-DDEVICE="C7120" -DFFTLIB_DEBUGPRINT="1" -DTEST_CASE="2" -DCMAKE_EXPORT_COMPILE_COMMANDS="TRUE" \
-DCMAKE_BUILD_TYPE="Release" \endcode
    -  To build all tests cases and libraries for release for J721S2 for target
        - \code cmake -B build -DTARGET_PLATFORM="" -DAUTO_TEST="1" -DSOC="j721s2" -DDEVICE="C7120" \
-DALL_TEST_CASES="1" -DCMAKE_BUILD_TYPE="Release" -DFFTLIB_DEBUGPRINT="0" \endcode
    - Then run:
        - \code cmake --build build -j<num_cores> \endcode


 \par Run

  - To run FFTLIB kernels on a PC:
    - \code bin/Release/test_FFTLIB_<kernel_name>_<device>_x86_64 \endcode OR \code
bin/Debug/test_FFTLIB_<kernel_name>_<device>_x86_64 \endcode
      - Ex: \code bin/Release/test_FFTLIB_and_C7120_x86_64 \endcode
  - To run FFTLIB kernels for target
    - To reproduce numbers given in the datasheet, run the .out program on the EVM in No Boot Mode

*/

#elif defined(__C7504__)
/**

 \page build_instructions_linux Ubuntu 22.04 Build Instructions for FFTLIB

 \par Python3 Setup

 - We auto generate test cases via python scripts packaged in the library

 - Please ensure that you have the  following python3 packages installed

   - numpy, scipy, and scikit-learn

 \par Environment Setup

  - Run the executables on EVM using CCS (Code composer studio)

  - Setup needed for the compiler for CGT7x
    - Download [CGT7x Compiler Installer](https://www.ti.com/tool/C7000-CGT) and install
    - export CGT7X_ROOT=${CGT7X_COMPILER_DIR}

  - Path setup
    - export PATH=${CGT7X_ROOT}/bin:${PATH}

 \par Build

  - FFTLIB utilizes CMake to build, ensure that system has CMake v3.16.0 or higher
  - Build options:
    - SOC=AM62A/j721e/j721s2/j784s4/j722s/AM62D
    - DEVICE=C7504/C7100/C7120/C7120/C7524/C7504
    - TARGET_PLATFORM=PC/""
    - KERNEL_NAME
    - BUILD_TEST=1 OR AUTO_TEST=1
    - FFTLIB_DEBUGPRINT=1/0
    - FFTLIB_TESTPRINT
    - ALL_TEST_CASES=1 OR TEST_CASE=TestCaseID
    - CMAKE_EXPORT_COMPILE_COMMANDS=TRUE
    - CMAKE_BUILD_TYPE=Release/Debug
    - AUTO_TEST=1/0 (builds all test cases and libraries)
  - Example CMake commands
    - To build fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc for target on AM62A and run performance test cases:
      - \code cmake -B build -DTARGET_PLATFORM="" -DBUILD_TEST="1"
-DKERNEL_NAME="fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc" -DSOC="AM62A" \
-DDEVICE="C7504" -DFFTLIB_DEBUGPRINT="0" -DALL_TEST_CASES="1" -DCMAKE_EXPORT_COMPILE_COMMANDS="TRUE" \
-DCMAKE_BUILD_TYPE="Release" \endcode
    - To build fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc for host emulation on AM62A and run test case 2 with debug
print statements
        - \code cmake -B build -DTARGET_PLATFORM="PC" -DBUILD_TEST="1"
-DKERNEL_NAME="fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc" -DSOC="AM62A" \
-DDEVICE="C7504" -DFFTLIB_DEBUGPRINT="1" -DTEST_CASE="2" -DCMAKE_EXPORT_COMPILE_COMMANDS="TRUE" \
-DCMAKE_BUILD_TYPE="Release" \endcode
    -  To build all tests cases and libraries for release for AM62A for target
        - \code cmake -B build -DTARGET_PLATFORM="" -DAUTO_TEST="1" -DSOC="AM62A" -DDEVICE="C7504" \
-DALL_TEST_CASES="1" -DCMAKE_BUILD_TYPE="Release" -DFFTLIB_DEBUGPRINT="0" \endcode
    - Then run:
        - \code cmake --build build -j<num_cores> \endcode

 \par Run

  - To run FFTLIB kernels on a PC:
    - \code bin/Release/test_FFTLIB_<kernel_name>_<device>_x86_64 \endcode OR \code
bin/Debug/test_FFTLIB_<kernel_name>_<device>_x86_64 \endcode
      - Ex: \code bin/Release/test_FFTLIB_and_C7504_x86_64 \endcode
  - To run FFTLIB kernels for target
    - To reproduce numbers given in the datasheet, run the .out program on the EVM in No Boot Mode

*/

#elif defined(__C7524__)
/**

 \page build_instructions_linux Ubuntu 22.04 Build Instructions for FFTLIB

 \par Python3 Setup

 - We auto generate test cases via python scripts packaged in the library

 - Please ensure that you have the  following python3 packages installed

   - numpy, scipy, and scikit-learn

 \par Environment Setup

  - Run the executables on EVM using CCS (Code composer studio)

  - Setup needed for the compiler for CGT7x
    - Download [CGT7x Compiler Installer](https://www.ti.com/tool/C7000-CGT) and install
    - export CGT7X_ROOT=${CGT7X_COMPILER_DIR}

  - Path setup
    - export PATH=${CGT7X_ROOT}/bin:${PATH}

 \par Build

  - FFTLIB utilizes CMake to build, ensure that system has CMake v3.16.0 or higher
  - Build options:
    - SOC=AM62A/j721e/j721s2/j784s4/j722s
    - DEVICE=C7504/C7100/C7120/C7524
    - TARGET_PLATFORM=PC/""
    - KERNEL_NAME
    - BUILD_TEST=1 OR AUTO_TEST=1
    - FFTLIB_DEBUGPRINT=1/0
    - FFTLIB_TESTPRINT
    - ALL_TEST_CASES=1 OR TEST_CASE=TestCaseID
    - CMAKE_EXPORT_COMPILE_COMMANDS=TRUE
    - CMAKE_BUILD_TYPE=Release/Debug
    - AUTO_TEST=1/0 (builds all test cases and libraries)
  - Example CMake commands
    - To build fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc for target on j722s and run performance test cases:
      - \code cmake -B build -DTARGET_PLATFORM="" -DBUILD_TEST="1"
-DKERNEL_NAME="fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc" -DSOC="j722s" \
-DDEVICE="C7524" -DFFTLIB_DEBUGPRINT="0" -DALL_TEST_CASES="1" -DCMAKE_EXPORT_COMPILE_COMMANDS="TRUE" \
-DCMAKE_BUILD_TYPE="Release" \endcode
    - To build fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc for host emulation on j722s and run test case 2 with debug
print statements
        - \code cmake -B build -DTARGET_PLATFORM="PC" -DBUILD_TEST="1"
-DKERNEL_NAME="fft_c7x/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc" -DSOC="j722s" \
-DDEVICE="C7524" -DFFTLIB_DEBUGPRINT="1" -DTEST_CASE="2" -DCMAKE_EXPORT_COMPILE_COMMANDS="TRUE" \
-DCMAKE_BUILD_TYPE="Release" \endcode
    -  To build all tests cases and libraries for release for j722s for target
        - \code cmake -B build -DTARGET_PLATFORM="" -DAUTO_TEST="1" -DSOC="j722s" -DDEVICE="C7524" \
-DALL_TEST_CASES="1" -DCMAKE_BUILD_TYPE="Release" -DFFTLIB_DEBUGPRINT="0" \endcode
    - Then run:
        - \code cmake --build build -j<num_cores> \endcode

 \par Run

  - To run FFTLIB kernels on a PC:
    - \code bin/Release/test_FFTLIB_<kernel_name>_<device>_x86_64 \endcode OR \code
bin/Debug/test_FFTLIB_<kernel_name>_<device>_x86_64 \endcode
      - Ex: \code bin/Release/test_FFTLIB_and_C7524_x86_64 \endcode
  - To run FFTLIB kernels for target
    - To reproduce numbers given in the datasheet, run the .out program on the EVM in No Boot Mode

*/

#endif
