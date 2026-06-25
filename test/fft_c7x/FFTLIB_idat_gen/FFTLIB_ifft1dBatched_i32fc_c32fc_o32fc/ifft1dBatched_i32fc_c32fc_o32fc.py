# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

import numpy as np

# IFFT algorithm: takes complex input, generates complex output
# Batched version (multiple channels)


class FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc:
    """IFFT algorithm: batched complex input -> complex output"""

    def __init__(self, numChannels, numPoints):
        """Initialize IFFT algorithm with size

        Args:
            numChannels (int): Number of parallel IFFTs
            numPoints (int): IFFT size
        """
        self.numChannels = numChannels
        self.numPoints = numPoints

    def exec(self, gInput):
        """Execute IFFT algorithm

        Args:
            gInput (numpy array): Batched complex input array (numChannels x numPoints)

        Returns:
            numpy array: Complex output array
        """
        G = np.fft.ifft(gInput, axis=1)
        G = np.round(G, 6)
        return G
