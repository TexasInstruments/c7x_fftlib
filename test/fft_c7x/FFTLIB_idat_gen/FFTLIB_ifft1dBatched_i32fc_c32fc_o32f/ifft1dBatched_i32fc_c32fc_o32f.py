# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

import numpy as np

# IFFT algorithm for complex-to-real: generates real output from complex input
# Batched version (multiple channels)
# inMode = 0 -> half spectrum input
# inMode = 1 -> full spectrum input


class FFTLIB_ifft1dBatched_i32fc_c32fc_o32f:
    """IFFT algorithm: batched complex input -> real output"""

    def __init__(self, numChannels, numPoints, inMode=1):
        """Initialize IFFT algorithm with size

        Args:
            numChannels (int): Number of parallel IFFTs
            numPoints (int): IFFT size
            inMode (int): 0=half spectrum, 1=full spectrum
        """
        self.numChannels = numChannels
        self.numPoints = numPoints
        self.inMode = inMode

    def exec(self, G_FFT):
        """Execute IFFT algorithm

        Args:
            G_FFT (numpy array): Batched complex input array (numChannels x numPoints)

        Returns:
            numpy array: Real output array
        """
        if self.inMode == 0:
            g = np.round(np.fft.irfft(G_FFT, n=self.numPoints, axis=1), 6)
        else:
            g = np.round(np.fft.ifft(G_FFT, axis=1).real, 6)

        return g
