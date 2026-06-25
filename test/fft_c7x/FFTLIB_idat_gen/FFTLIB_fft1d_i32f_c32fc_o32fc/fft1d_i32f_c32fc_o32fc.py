# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

import numpy as np


class FFTLIB_fft1d_i32f_c32fc_o32fc:
    """FFT algorithm: real input -> complex output (non-batched)"""

    def __init__(self, numPoints):
        """Initialize FFT algorithm with size

        Args:
            numPoints (int): FFT size
        """
        self.numPoints = numPoints

    def exec(self, gInput):
        """Execute FFT algorithm

        Args:
            gInput (numpy array): Real input array

        Returns:
            numpy array: Complex output array
        """
        gInput_complex = gInput.astype(np.complex128)
        G = np.fft.fft(gInput_complex)
        G = np.round(G, 6)
        return G
