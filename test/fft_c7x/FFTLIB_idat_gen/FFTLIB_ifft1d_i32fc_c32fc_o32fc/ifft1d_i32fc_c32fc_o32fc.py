# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

import numpy as np


class FFTLIB_ifft1d_i32fc_c32fc_o32fc:
    """IFFT algorithm: complex input -> complex output (non-batched)"""

    def __init__(self, numPoints):
        """Initialize IFFT algorithm with size

        Args:
            numPoints (int): FFT size
        """
        self.numPoints = numPoints

    def exec(self, gInput):
        """Execute IFFT algorithm

        Args:
            gInput (numpy array): Complex input array

        Returns:
            numpy array: Complex output array
        """
        G = np.fft.ifft(gInput)
        G = np.round(G, 6)
        return G
