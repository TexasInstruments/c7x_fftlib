# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

import numpy as np


class FFTLIB_fft1dBatched_i16sc_c16sc_o16sc:
    """Batched FFT algorithm: int16 complex input -> complex output - radix-4 implementation"""

    def __init__(self, numChannels, numPoints, shift_vec):
        """Initialize batched FFT algorithm

        Args:
            numChannels (int): Number of parallel FFTs
            numPoints (int): FFT size
            shift_vec (list): Shift vector for scaling per stage
        """
        self.numChannels = numChannels
        self.numPoints = numPoints
        self.shift_vec = shift_vec
        self.pW = self._generate_twiddle_factors()

    def _float2short(self, x):
        """Convert float to int16 with proper rounding and saturation"""
        x = np.floor(0.5 + x)
        if x >= 32767.0:
            return 32767
        if x <= -32768.0:
            return -32768
        return int(x)

    def _generate_twiddle_factors(self):
        """Generate twiddle factors"""
        pW = [0] * (self.numPoints * 2)
        PI = 3.141592654
        twF2sScale = 32767.5

        t = self.numPoints >> 2
        k = 0
        j = 1
        while j <= self.numPoints >> 2:
            for i in range(0, self.numPoints >> 2, j):
                pW[k] = self._float2short(
                    twF2sScale * np.cos(2 * PI * i / self.numPoints)
                )
                pW[k + 1] = self._float2short(
                    twF2sScale * (-np.sin(2 * PI * i / self.numPoints))
                )
                pW[k + 2 * t] = self._float2short(
                    twF2sScale * np.cos(4 * PI * i / self.numPoints)
                )
                pW[k + 2 * t + 1] = self._float2short(
                    twF2sScale * (-np.sin(4 * PI * i / self.numPoints))
                )
                pW[k + 4 * t] = self._float2short(
                    twF2sScale * np.cos(6 * PI * i / self.numPoints)
                )
                pW[k + 4 * t + 1] = self._float2short(
                    twF2sScale * (-np.sin(6 * PI * i / self.numPoints))
                )
                k += 2
            k += (t) * 4
            t = t >> 2
            j = j << 2
        return pW

    def _sat_and_scale(self, x):
        """Saturate and scale"""
        x = int(x)
        x_temp = (x + 0x4000) << 1
        if x_temp > 0x7FFF0000:
            x_temp = 0x7FFF0000
        if x_temp < -0x80000000:
            x_temp = -0x80000000
        result = x_temp >> 16
        if result > 32767:
            result = 32767
        elif result < -32768:
            result = -32768
        return int(result)

    def _crot90h_re(self, re, im):
        """90-degree rotation real component"""
        return -im if im != -32768 else 32767

    def _crot90h_im(self, re, im):
        """90-degree rotation imaginary component"""
        return re

    def _shift_right_and_round(self, buff, shift):
        """Right shift with banker's rounding"""
        if shift == 0:
            return list(buff)
        shift_out_bit_mask = 1 << (shift - 1)
        result = []
        for val in buff:
            val = int(val)
            if (val & shift_out_bit_mask) != 0:
                result.append((val >> shift) + 1)
            else:
                result.append(val >> shift)
        return result

    def _butterfly_no_tw(self, p0re, p0im, p1re, p1im, p2re, p2im, p3re, p3im):
        """Butterfly without twiddle factors"""
        sum1re = p0re + p2re
        sum1im = p0im + p2im
        sum2re = p1re + p3re
        sum2im = p1im + p3im
        diff1re = p0re - p2re
        diff1im = p0im - p2im
        diff2re = p1re - p3re
        diff2im = p1im - p3im

        x0re = sum1re + sum2re
        x0im = sum1im + sum2im
        x1re = diff1re - self._crot90h_re(diff2re, diff2im)
        x1im = diff1im - self._crot90h_im(diff2re, diff2im)
        x2re = sum1re - sum2re
        x2im = sum1im - sum2im
        x3re = diff1re + self._crot90h_re(diff2re, diff2im)
        x3im = diff1im + self._crot90h_im(diff2re, diff2im)

        return [x0re, x0im, x1re, x1im, x2re, x2im, x3re, x3im]

    def _butterfly(
        self,
        p0re,
        p0im,
        p1re,
        p1im,
        p2re,
        p2im,
        p3re,
        p3im,
        x1_tw_re,
        x1_tw_im,
        x2_tw_re,
        x2_tw_im,
        x3_tw_re,
        x3_tw_im,
    ):
        """Butterfly with twiddle factors"""
        sum1re = p0re + p2re
        sum1im = p0im + p2im
        sum2re = p1re + p3re
        sum2im = p1im + p3im
        diff1re = p0re - p2re
        diff1im = p0im - p2im
        diff2re = p1re - p3re
        diff2im = p1im - p3im

        x0_temp_re = sum1re + sum2re
        x0_temp_im = sum1im + sum2im
        x1_temp_re = diff1re - self._crot90h_re(diff2re, diff2im)
        x1_temp_im = diff1im - self._crot90h_im(diff2re, diff2im)
        x2_temp_re = sum1re - sum2re
        x2_temp_im = sum1im - sum2im
        x3_temp_re = diff1re + self._crot90h_re(diff2re, diff2im)
        x3_temp_im = diff1im + self._crot90h_im(diff2re, diff2im)

        x0_long_re = int(x0_temp_re) << 15
        x0_long_im = int(x0_temp_im) << 15
        x1_long_re = int(x1_temp_re) * int(x1_tw_re) - int(x1_temp_im) * int(x1_tw_im)
        x1_long_im = int(x1_temp_re) * int(x1_tw_im) + int(x1_temp_im) * int(x1_tw_re)
        x2_long_re = int(x2_temp_re) * int(x2_tw_re) - int(x2_temp_im) * int(x2_tw_im)
        x2_long_im = int(x2_temp_re) * int(x2_tw_im) + int(x2_temp_im) * int(x2_tw_re)
        x3_long_re = int(x3_temp_re) * int(x3_tw_re) - int(x3_temp_im) * int(x3_tw_im)
        x3_long_im = int(x3_temp_re) * int(x3_tw_im) + int(x3_temp_im) * int(x3_tw_re)

        x0re = self._sat_and_scale(x0_long_re)
        x0im = self._sat_and_scale(x0_long_im)
        x1re = self._sat_and_scale(x1_long_re)
        x1im = self._sat_and_scale(x1_long_im)
        x2re = self._sat_and_scale(x2_long_re)
        x2im = self._sat_and_scale(x2_long_im)
        x3re = self._sat_and_scale(x3_long_re)
        x3im = self._sat_and_scale(x3_long_im)

        return [x0re, x0im, x1re, x1im, x2re, x2im, x3re, x3im]

    def _bitr(self, in_val, max_value):
        """Bit reversal function"""
        i = 31
        while i > 0:
            if ((max_value >> i) & 1) != 0:
                break
            i -= 1
        num_bits = i + 1

        out = 0
        for i in range(num_bits):
            out |= ((in_val >> i) & 1) << (num_bits - 1 - i)
        return out

    def _to_int16(self, val):
        """Convert to signed int16"""
        val = int(val)
        if val > 32767:
            return 32767
        elif val < -32768:
            return -32768
        return val

    def _exec_single_channel(self, gInput):
        """Execute radix-4 FFT for a single channel"""
        num_points = self.numPoints
        pX = []

        for i in range(num_points):
            pX.append(self._to_int16(gInput[i].real))
            pX.append(self._to_int16(gInput[i].imag))

        num_points_per_dft = num_points
        pW_local = 0
        stage_index = 0
        shift = 0

        # Radix-4 decimation stages
        while num_points_per_dft > 2:
            shift = self.shift_vec[stage_index]

            for k in range(num_points // 4):
                dft_index = k // (num_points_per_dft // 4)
                dft_start_offset = dft_index * num_points_per_dft
                dft_point_index = k % (num_points_per_dft // 4)

                idx0 = (dft_start_offset * 2) + (2 * dft_point_index)
                idx1 = (
                    (dft_start_offset * 2)
                    + ((num_points_per_dft // 4) * 2)
                    + (2 * dft_point_index)
                )
                idx2 = (
                    (dft_start_offset * 2)
                    + ((num_points_per_dft // 2) * 2)
                    + (2 * dft_point_index)
                )
                idx3 = (
                    (dft_start_offset * 2)
                    + (3 * (num_points_per_dft // 4) * 2)
                    + (2 * dft_point_index)
                )

                if (num_points_per_dft == 4) or (
                    (num_points_per_dft == 8) and (dft_point_index == 0)
                ):
                    bfly_out = self._butterfly_no_tw(
                        pX[idx0],
                        pX[idx0 + 1],
                        pX[idx1],
                        pX[idx1 + 1],
                        pX[idx2],
                        pX[idx2 + 1],
                        pX[idx3],
                        pX[idx3 + 1],
                    )
                else:
                    tw_idx = pW_local + dft_point_index * 2
                    x1_tw_re = self.pW[tw_idx]
                    x1_tw_im = self.pW[tw_idx + 1]
                    x2_tw_re = self.pW[tw_idx + (num_points_per_dft // 4) * 2]
                    x2_tw_im = self.pW[tw_idx + (num_points_per_dft // 4) * 2 + 1]
                    x3_tw_re = self.pW[tw_idx + (num_points_per_dft // 2) * 2]
                    x3_tw_im = self.pW[tw_idx + (num_points_per_dft // 2) * 2 + 1]

                    bfly_out = self._butterfly(
                        pX[idx0],
                        pX[idx0 + 1],
                        pX[idx1],
                        pX[idx1 + 1],
                        pX[idx2],
                        pX[idx2 + 1],
                        pX[idx3],
                        pX[idx3 + 1],
                        x1_tw_re,
                        x1_tw_im,
                        x2_tw_re,
                        x2_tw_im,
                        x3_tw_re,
                        x3_tw_im,
                    )

                if num_points_per_dft != 8:
                    bfly_out = self._shift_right_and_round(bfly_out, shift)

                pX[idx0] = bfly_out[0]
                pX[idx0 + 1] = bfly_out[1]
                pX[idx1] = bfly_out[4]
                pX[idx1 + 1] = bfly_out[5]
                pX[idx2] = bfly_out[2]
                pX[idx2 + 1] = bfly_out[3]
                pX[idx3] = bfly_out[6]
                pX[idx3 + 1] = bfly_out[7]

            num_points_per_dft //= 4
            pW_local += 3 * num_points_per_dft * 2
            stage_index += 1

        # Final 2-point stage
        if num_points_per_dft == 2:
            for k in range(num_points // 2):
                idx_k = 2 * k * 2
                idx_k1 = ((2 * k) + 1) * 2

                bfly_out = [
                    pX[idx_k] + pX[idx_k1],
                    pX[idx_k + 1] + pX[idx_k1 + 1],
                    pX[idx_k] - pX[idx_k1],
                    pX[idx_k + 1] - pX[idx_k1 + 1],
                ]

                bfly_out = self._shift_right_and_round(bfly_out, shift)

                pX[idx_k] = bfly_out[0]
                pX[idx_k + 1] = bfly_out[1]
                pX[idx_k1] = bfly_out[2]
                pX[idx_k1 + 1] = bfly_out[3]

        # Bit-reversal reordering
        pY = [0] * (num_points * 2)
        for k in range(num_points):
            k_bitr = self._bitr(k, num_points - 1)
            pY[2 * k] = pX[2 * k_bitr]
            pY[2 * k + 1] = pX[2 * k_bitr + 1]

        # Convert back to complex array
        G = np.zeros(num_points, dtype=np.complex128)
        for i in range(num_points):
            G[i] = complex(pY[2 * i], pY[2 * i + 1])

        return G

    def exec(self, gInput):
        """Execute batched radix-4 FFT algorithm

        Args:
            gInput (numpy array): Batched complex input array (numChannels x numPoints)

        Returns:
            tuple: (output array, shift vector)
        """
        G = np.zeros((self.numChannels, self.numPoints), dtype=np.complex128)

        for ch in range(self.numChannels):
            G[ch, :] = self._exec_single_channel(gInput[ch, :])

        shiftVector = np.zeros(self.numChannels, dtype=np.uint32)
        return G, shiftVector
