# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

import numpy as np

# FFT algorithm: takes real input, generates complex output
# Batched version (multiple channels)
# outmode = 0: half spectrum (N//2 + 1 values using rfft)
# outmode = 1: full spectrum (N values using fft)


class FFTLIB_fft1dBatched_i32f_c32fc_o32fc:
    """FFT algorithm: batched real input -> complex output"""

    def __init__(self, numChannels, numPoints, outmode=1):
        """Initialize FFT algorithm with size

        Args:
            numChannels (int): Number of parallel FFTs
            numPoints (int): FFT size
            outmode (int): 0=half spectrum, 1=full spectrum
        """
        self.numChannels = numChannels
        self.numPoints = numPoints
        self.outmode = outmode

    def exec(self, gInput):
        """Execute FFT algorithm

        Args:
            gInput (numpy array): Batched real input array (numChannels x numPoints)

        Returns:
            numpy array: Complex output array
        """
        if self.outmode == 0:
            G = np.fft.rfft(gInput.astype(np.float64), axis=1)
        else:
            G = np.fft.fft(gInput.astype(np.complex128), axis=1)

        G = np.round(G, 6)
        return G
