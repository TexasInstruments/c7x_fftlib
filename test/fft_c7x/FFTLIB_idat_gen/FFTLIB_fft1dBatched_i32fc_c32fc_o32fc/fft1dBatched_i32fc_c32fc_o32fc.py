# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

import numpy as np

# FFT algorithm: takes complex input, generates complex output
# Batched version (multiple channels)


class FFTLIB_fft1dBatched_i32fc_c32fc_o32fc:
    """FFT algorithm: batched complex input -> complex output"""

    def __init__(self, numChannels, numPoints):
        """Initialize FFT algorithm with size

        Args:
            numChannels (int): Number of parallel FFTs
            numPoints (int): FFT size
        """
        self.numChannels = numChannels
        self.numPoints = numPoints

    def exec(self, gInput):
        """Execute FFT algorithm

        Args:
            gInput (numpy array): Batched complex input array (numChannels x numPoints)

        Returns:
            numpy array: Complex output array
        """
        G = np.fft.fft(gInput, axis=1)
        G = np.round(G, 6)
        return G
