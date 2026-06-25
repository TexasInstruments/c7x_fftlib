# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

"""
File I/O for FFTLIB_ifft1dBatched_i32fc_c32fc_o32f test data generation.
"""

from __future__ import print_function
import os


def write_header_file(x, y, testCase, headerFileName):
    """Write input and output test vectors to header file"""
    testId = testCase["ID"]
    attributesX = '__attribute__((section(".staticData"))) static ' + "float" + " "
    attributesY = '__attribute__((section(".staticData"))) static ' + "float" + " "

    outputDir = "../../FFTLIB_ifft1dBatched_i32fc_c32fc_o32f/test_data/"

    os.makedirs(outputDir, exist_ok=True)

    with open(outputDir + headerFileName, "w") as f:
        [numChannels, numPoints] = x.shape
        f.write(attributesX + "staticRefIn" + str(testId) + "[]=\n")
        f.write("{\n")
        for c in range(0, x.shape[0]):
            for i in range(0, x.shape[1]):
                print("{:>2}".format(x[c, i].real), file=f, end=",")
                print("{:>2}".format(x[c, i].imag), file=f, end=",")
            f.write("\n")
        f.write("\n};")
        f.write("\n\n")

    with open(outputDir + headerFileName, "a") as f:
        [numChannels, numPoints] = y.shape
        f.write(attributesY + "staticRefOut" + str(testId) + "[]=\n")
        f.write("{\n")
        for c in range(0, numChannels):
            for i in range(0, numPoints):
                print("{:>2}".format(y[c, i]), file=f, end=",")
            f.write("\n")
        f.write("\n};")
        f.write("\n\n")
