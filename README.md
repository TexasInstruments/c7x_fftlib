<div align="center">

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://www.ti.com/content/dam/ticom/images/identities/ti-brand/ti-logo-hz-1c-white.svg" width="300">
  <img alt="Texas Instruments Logo" src="https://www.ti.com/content/dam/ticom/images/identities/ti-brand/ti-hz-2c-pos-rgb.svg" width="300">
</picture>

# FFTLIB — C7<sup>™</sup> Fast Fourier Transform Library

[Summary](#summary) | [Features](#features) | [Kernels](#kernels) | [Supported Devices](#supported-devices) | [Setup Instructions](#setup-instructions) | [Build Instructions](#build-instructions) | [Related Repos](#related-repos) | [Licensing](#licensing) | [Contributions](#contributions) | [Developer Resources](#developer-resources)

</div>

## Summary

FFTLIB is TI's optimized Fast Fourier Transform library for the **C7<sup>™</sup>** DSP architecture.
It provides a suite of kernels targeting the C7<sup>™</sup> vector and streaming engines (SE/SA),
enabling high-throughput FFT and linear algebra on TI SoCs such as AM62D, AM275 and AM283.

Each kernel ships in two variants selected at init time via the `FFTLIB_FUNCTION_OPT` /
`FFTLIB_FUNCTION_NATC` enum in the kernel's `InitArgs`:

| Suffix | Description |
|--------|-------------|
| `_cn` | C-native reference (`NATC`) — portable, functionally correct, used for validation |
| `_ci` | C7<sup>™</sup> intrinsic (`OPT`) — hardware-optimized, targets SE/SA streaming engines |

Each kernel has a corresponding test driver (`_d.c`). Some kernels additionally include a Python
reference implementation under `test/fft_c7x/FFTLIB_idat_gen/FFTLIB_<kernel>/` for test vector generation.


## Features

- **FFT and IFFT kernels** spanning 16-bit integer and 32-bit floating-point data types
- **C7<sup>™</sup> streaming engine optimized** — all kernels leverage SE/SA hardware for peak throughput
- **Batched and single-transform variants** — process one or many FFTs in a single kernel call
- **Real-to-complex and complex-to-complex** input/output support
- **Portable reference implementations** — `_cn` variants enable host-side validation and porting
- **CMake-based build** with presets for PC simulation and on-target deployment


## Kernels

### FFT — C7<sup>™</sup> SE/SA Kernels (`fft_c7x`)

| Kernel | Description |
|--------|-------------|
| `FFTLIB_fft1d_i16sc_c16sc_o16sc` | 1-D FFT, 16-bit integer complex input/twiddle/output |
| `FFTLIB_fft1d_i32f_c32fc_o32fc` | 1-D FFT, 32-bit float real input, complex output |
| `FFTLIB_fft1d_i32fc_c32fc_o32fc` | 1-D FFT, 32-bit float complex input/twiddle/output |
| `FFTLIB_fft1dBatched_i16sc_c16sc_o16sc` | Batched 1-D FFT, 16-bit integer complex |
| `FFTLIB_fft1dBatched_i32f_c32fc_o32fc` | Batched 1-D FFT, 32-bit float real-to-complex |
| `FFTLIB_fft1dBatched_i32fc_c32fc_o32fc` | Batched 1-D FFT, 32-bit float complex-to-complex |
| `FFTLIB_ifft1d_i32fc_c32fc_o32f` | 1-D IFFT, 32-bit float complex-to-real output |
| `FFTLIB_ifft1d_i32fc_c32fc_o32fc` | 1-D IFFT, 32-bit float complex-to-complex output |
| `FFTLIB_ifft1dBatched_i32fc_c32fc_o32f` | Batched 1-D IFFT, 32-bit float complex-to-real |
| `FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc` | Batched 1-D IFFT, 32-bit float complex-to-complex |

### FFT — C7<sup>™</sup>+MMA DFT Kernels (`fft_c7xmma`, C7100 and C7120 only; not supported on AM62D C7504, AM275 C7524 or AM283 C7524)

| Kernel | Description |
|--------|-------------|
| `FFTLIB_FFT_fft_ixX_cxX_oxX` | Top-level DFT coordinator; dispatches to small, large, or high-radix sub-kernels |
| `FFTLIB_FFT_dftSmall_ixX_cxX_oxX` | DFT for small point counts via brute-force matrix multiply |
| `FFTLIB_FFT_dftLarge_ixX_cxX_oxX` | DFT for large point counts via brute-force matrix multiply |
| `FFTLIB_FFT_highRadixDecompositions_ixX_cxX_oxX` | DFT via high-radix FFT algorithm decompositions |


## Supported Devices

| Device | C7<sup>™</sup> Core |
|--------|----------|
| AM62D | C7504 |
| AM275 | C7524 |
| AM283 | C7524 |


## Setup Instructions

### Prerequisites

- **Linux** host (Ubuntu 20.04 or later recommended)
- **CMake** ≥ 3.16
- **TI C7000 Code Generation Tools** (`ti-cgt-c7000`) — install to `~/ti/`

  Download from [TI CGT C7000](https://www.ti.com/tool/C7000-CGT).
  Default expected path: `~/ti/ti-cgt-c7000_5.0.0.LTS/`

  Or set the environment variable before building:
  ```bash
  export CGT7X_ROOT=/path/to/ti-cgt-c7000_<version>
  ```


## Build Instructions

FFTLIB uses **CMake presets** to manage build configurations.

### Available Presets

| Preset | SoC | Platform |
|--------|-----|----------|
| `release-autotest-am62d-pc` | AM62D | PC simulation + tests |
| `release-autotest-am62d-target` | AM62D | On-device + tests |
| `release-autotest-am275-pc` | AM275 | PC simulation + tests |
| `release-autotest-am275-target` | AM275 | On-device + tests |
| `release-autotest-am283-pc` | AM283 | PC simulation + tests |
| `release-autotest-am283-target` | AM283 | On-device + tests |
| `release-buildlib-am62d-pc` | AM62D | PC (library only) |
| `release-buildlib-am62d-target` | AM62D | On-device (library only) |
| `release-buildlib-am275-pc` | AM275 | PC (library only) |
| `release-buildlib-am275-target` | AM275 | On-device (library only) |
| `release-buildlib-am283-pc` | AM283 | PC (library only) |
| `release-buildlib-am283-target` | AM283 | On-device (library only) |

### Quick Start — PC simulation (AM62D)

```bash
# Configure
cmake -S . -B build --preset=release-autotest-am62d-pc

# Build
cmake --build build -- -j$(nproc)
```

### On-Target Build (AM62D)

```bash
cmake -S . -B build --preset=release-autotest-am62d-target
cmake --build build -- -j$(nproc)
```

### Library-Only Build

```bash
cmake -S . -B build --preset=release-buildlib-am62d-pc
cmake --build build -- -j$(nproc)
```


## Related Repos

- [MCU+ SDK](https://github.com/TexasInstruments/mcupsdk-core) — SoC drivers and middleware for AM2x/AM6x devices


## Licensing

This repository is licensed under the **Apache License, Version 2.0**.
See [LICENSE](LICENSE) for the full text.

All source files carry an SPDX `Apache-2.0` identifier.


## Contributions

This repository is not currently accepting community contributions.

Bug reports and feature requests are welcome via [TI E2E Community Forums](https://e2e.ti.com).


---

## Developer Resources

[TI E2E™ design support forums](https://e2e.ti.com)
