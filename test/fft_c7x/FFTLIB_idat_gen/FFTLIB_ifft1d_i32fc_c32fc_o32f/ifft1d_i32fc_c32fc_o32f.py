# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

import numpy as np


class FFTLIB_ifft1d_i32fc_c32fc_o32f:
    """IFFT algorithm: complex input -> real output (non-batched)"""

    def __init__(self, numPoints):
        """Initialize IFFT algorithm with size

        Args:
            numPoints (int): IFFT size
        """
        self.numPoints = numPoints

    def exec(self, G_FFT):
        """Execute IFFT algorithm and return real part

        Args:
            G_FFT (numpy array): Full spectrum complex input

        Returns:
            numpy array: Real output array
        """
        g = np.real(np.fft.ifft(G_FFT))
        return np.round(g, 6)
