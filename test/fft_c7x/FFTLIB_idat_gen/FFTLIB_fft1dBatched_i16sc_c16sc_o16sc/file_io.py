# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

"""
File I/O operations for FFTLIB_fft1dBatched_i16sc_c16sc_o16sc test data generation.
Handles writing test reference data to header files.
"""

from __future__ import print_function
import os


def write_header_file(x, y, testCase, headerFileName):
    """Write input and output to header file

    Args:
        x (numpy array): Input FFT data (complex batched)
        y (numpy array): Output FFT data (complex batched)
        testCase (dict): Test case parameters
        headerFileName (str): Name of header file to write
    """
    testId = testCase["ID"]

    attributesX = '__attribute__((section(".staticData"))) static ' + "int16_t" + " "
    attributesY = '__attribute__((section(".staticData"))) static ' + "int16_t" + " "

    outputDir = "../../FFTLIB_fft1dBatched_i16sc_c16sc_o16sc/test_data/"

    os.makedirs(outputDir, exist_ok=True)

    with open(outputDir + headerFileName, "w") as f:
        f.write("#include <stdint.h>\n\n")
        [numChannels, numPoints] = x.shape
        f.write(attributesX + "staticRefIn" + str(testId) + "[]=\n")
        f.write("{\n")
        for c in range(0, x.shape[0]):
            for i in range(0, x.shape[1]):
                print("{:>2}".format(int(x[c, i].real)), file=f, end=",")
                print("{:>2}".format(int(x[c, i].imag)), file=f, end=",")
            f.write("\n")
        f.write("\n};")
        f.write("\n\n")

    with open(outputDir + headerFileName, "a") as f:
        [numChannels, numPoints] = y.shape
        f.write(attributesY + "staticRefOut" + str(testId) + "[]=\n")
        f.write("{\n")
        for c in range(0, numChannels):
            for i in range(0, numPoints):
                print("{:>2}".format(int(y[c, i].real)), file=f, end=",")
                print("{:>2}".format(int(y[c, i].imag)), file=f, end=",")
            f.write("\n")
        f.write("\n};")
        f.write("\n\n")
