# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

"""
Main test data generation for FFTLIB_ifft1dBatched_i32fc_c32fc_o32f.
"""

from __future__ import print_function
from subprocess import call
from sys import platform

import csv
import numpy as np
import ifft1dBatched_i32fc_c32fc_o32f as ifft1dBatched_32fc_o32f
import file_io


def gen_preamble(idatFile, kernelName):
    """Generate preamble with license header and includes

    Args:
        idatFile (file object): File object to write to
        kernelName (str): Name of the kernel for the include statement
    """
    with open("../common/ti_lice_header_idat.txt", "r") as fIn:
        lines = fIn.readlines()
        idatFile.writelines(lines)
    idatFile.write("\n")

    idatFile.write('#include "%s_idat.h"\n' % kernelName)
    idatFile.write("\n")


def gen_header_includes(idatFile, testCases):
    """Generate #include statements for STATIC test reference data

    Args:
        idatFile (file object): File object to write to
        testCases (list): List of test case dictionaries
    """
    for testCase in testCases:
        testId = testCase["ID"]
        testType = testCase["testType"]
        testCategory = testCase["testCategory"]

        if testType == "STATIC":
            idatFile.write(
                "#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == %d)"
                " || (TEST_CATEGORY == 100) || (TEST_CASE == %d))\n"
                % ((testCategory), int(testId))
            )

            headerFileName = "staticRefCase" + str(testId) + ".h"
            idatFile.write('#include "test_data/%s"\n' % (headerFileName))
            idatFile.write("#endif\n\n")


def gen_idat_file(idatFile, testCases):
    """Generate and write test case parameters to idat file"""
    idatFile.write(
        "static ifft1dBatched_i32fc_c32fc_o32f_testParams_t testParams[] = {\n\n"
    )

    for testCase in testCases:

        testId = testCase["ID"]
        testType = testCase["testType"]
        testCategory = testCase["testCategory"]
        numPoints = testCase["numPoints"]
        numChannels = testCase["numChannels"]
        inMode = testCase["inMode"]

        idatFile.write(
            "#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == 200)"
            " || (TEST_CATEGORY == 100) || (TEST_CASE == %d))\n" % (int(testId))
        )

        idatFile.write("    {\n")
        idatFile.write(
            "        %s,%s// test pattern\n" % (testType, " " * (20 - len(testType)))
        )
        if testType == "RANDOM" or testType == "RANDOM_SIGNED":
            idatFile.write("        NULL,%s// randomIn\n" % (" " * (20 - len("NULL"))))
            idatFile.write("        NULL,%s// randomOut\n" % (" " * (20 - len("NULL"))))
        else:
            ifftIn = "staticRefIn" + str(testId)
            ifftOut = "staticRefOut" + str(testId)
            idatFile.write(
                "        %s,%s// staticIn\n" % (ifftIn, " " * (20 - len(ifftIn)))
            )
            idatFile.write(
                "        %s,%s// staticOut\n" % (ifftOut, " " * (20 - len(ifftOut)))
            )
        numPoints_spaces = " " * (20 - len(str(numPoints)))
        numChannels_spaces = " " * (20 - len(str(numChannels)))
        testId_spaces = " " * (20 - len(str(testId)))
        inMode_spaces = " " * (20 - len(str(inMode)))
        idatFile.write("        %d,%s// numPoints\n" % (numPoints, numPoints_spaces))
        idatFile.write(
            "        %d,%s// numChannels\n" % (numChannels, numChannels_spaces)
        )
        idatFile.write("        %d,%s// test ID\n" % (testId, testId_spaces))
        idatFile.write("        %d,%s// inMode\n" % (inMode, inMode_spaces))
        idatFile.write("    },\n")
        idatFile.write("#endif")
        idatFile.write("\n\n")

    idatFile.write("};\n\n")
    with open("test_param_function.txt", "r") as fIn:
        lines = fIn.readlines()
        idatFile.writelines(lines)


def process_test_case(testCase):
    """Convert str to int for necessary parameters"""
    testCase["ID"] = int(testCase["ID"])
    testCase["testCategory"] = int(testCase["testCategory"])
    testCase["numPoints"] = int(testCase["numPoints"])
    testCase["numChannels"] = int(testCase["numChannels"])
    testCase["inMode"] = int(testCase["inMode"])
    return testCase


def gen_test_case_header_file(testCase):
    """Generate test case and write out input/output to header file"""
    testId = testCase["ID"]
    numPoints = testCase["numPoints"]
    numChannels = testCase["numChannels"]
    inMode = testCase["inMode"]

    gInput_real = np.round(
        np.random.uniform(low=-1.0, high=1.0, size=(numChannels, numPoints)), 6
    )

    if inMode == 0:
        G_half = np.round(np.fft.rfft(gInput_real), 6)
        algo = ifft1dBatched_32fc_o32f.FFTLIB_ifft1dBatched_i32fc_c32fc_o32f(
            numChannels, numPoints, inMode
        )
        y = algo.exec(G_half)
        gInput = G_half
    else:
        G_full = np.round(np.fft.fft(gInput_real), 6)
        algo = ifft1dBatched_32fc_o32f.FFTLIB_ifft1dBatched_i32fc_c32fc_o32f(
            numChannels, numPoints, inMode
        )
        y = algo.exec(G_full)
        gInput = G_full

    headerFileName = "staticRefCase" + str(testId) + ".h"
    file_io.write_header_file(gInput, y, testCase, headerFileName)

    # Calculate min and max of output data
    minY = np.min(y)
    maxY = np.max(y)
    return [minY, maxY]


testCasesCsvFile = "test_cases_list.csv"
testIdList = []
testIdList += range(0, 250)


with open(testCasesCsvFile) as csv_file:
    testCaseReader = csv.DictReader(csv_file)
    testCases = list(testCaseReader)

    for testCase in testCases:
        testCase = process_test_case(testCase)

    for testCase in testCases:
        if int(testCase["ID"]) in testIdList:
            if testCase["testType"] == "STATIC":
                [minY, maxY] = gen_test_case_header_file(testCase)
                print(
                    "Test case generation completed for test ID",
                    testCase["ID"],
                    "w/ min:",
                    minY,
                    "and max",
                    maxY,
                )
            else:
                print(
                    "Skipping test case generation for test ID",
                    testCase["ID"],
                    "as testType is",
                    testCase["testType"],
                )


idatFileName = "../../FFTLIB_ifft1dBatched_i32fc_c32fc_o32f/FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_idat.c"
kernelName = "FFTLIB_ifft1dBatched_i32fc_c32fc_o32f"

with open(idatFileName, "w") as idatFile:
    gen_preamble(idatFile, kernelName)
    gen_header_includes(idatFile, testCases)
    gen_idat_file(idatFile, testCases)

print("Idat file generation completed")
