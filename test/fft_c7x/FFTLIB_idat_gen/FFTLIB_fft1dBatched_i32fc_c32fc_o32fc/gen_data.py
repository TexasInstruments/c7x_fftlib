# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

"""
Main test data generation orchestrator for FFTLIB_fft1dBatched_i32fc_c32fc_o32fc.
Coordinates CSV reading, test case generation, and idat.c file creation.
"""

from __future__ import print_function
from subprocess import call
from sys import platform

import csv
import numpy as np
import fft1dBatched_i32fc_c32fc_o32fc as fft1dBatched_32fc
import file_io


def gen_preamble(idatFile, kernelName):
    """Generate preamble (copyright + includes) for idat file

    Args:
        idatFile (file object): File object to write to
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
    """Generate and write test case parameters to idat file

    Args:
        idatFile (file object): File object to write to
        testCases (list): List of test case dictionaries
    """
    idatFile.write("static fft1dBatched_testParams_t testParams[] = {\n\n")

    first_16point = True
    for testCase in testCases:

        testId = testCase["ID"]
        testType = testCase["testType"]
        numPoints = testCase["numPoints"]
        numChannels = testCase["numChannels"]

        if numPoints == 16 and first_16point:
            idatFile.write("#if !defined(__C7504__) && !defined(__C7524__)\n")
            first_16point = False

        if numPoints != 16 and not first_16point:
            idatFile.write("#endif\n\n")
            first_16point = True

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
            fftIn = "staticRefIn" + str(testId)
            fftOut = "staticRefOut" + str(testId)
            idatFile.write(
                "        %s,%s// staticIn\n" % (fftIn, " " * (20 - len(fftIn)))
            )
            idatFile.write(
                "        %s,%s// staticOut\n" % (fftOut, " " * (20 - len(fftOut)))
            )
        numChannels_spaces = " " * (20 - len(str(numChannels)))
        numPoints_spaces = " " * (20 - len(str(numPoints)))
        testId_spaces = " " * (20 - len(str(testId)))
        idatFile.write(
            "        %d,%s// numChannels\n" % (numChannels, numChannels_spaces)
        )
        idatFile.write("        %d,%s// numPoints\n" % (numPoints, numPoints_spaces))
        idatFile.write("        %d,%s// test ID\n" % (testId, testId_spaces))
        idatFile.write("    },\n")
        idatFile.write("#endif")
        if numPoints == 16 and not first_16point:
            idx = testCases.index(testCase)
            if idx < len(testCases) - 1:
                next_numPoints = testCases[idx + 1]["numPoints"]
                if next_numPoints != 16:
                    idatFile.write("\n")
                else:
                    idatFile.write("\n\n")
            else:
                idatFile.write("\n")
        else:
            idatFile.write("\n\n")

    if not first_16point:
        idatFile.write("\n#endif\n")

    idatFile.write("};\n\n")
    with open("test_param_function.txt", "r") as fIn:
        lines = fIn.readlines()
        idatFile.writelines(lines)


def process_test_case(testCase):
    """Convert str to int for necessary parameters

    Args:
        testCase (dict): Dictionary object with test case parameters

    Returns:
        dict: Dictionary with necessary parameters converted to int
    """
    testCase["ID"] = int(testCase["ID"])
    testCase["testCategory"] = int(testCase["testCategory"])
    testCase["numPoints"] = int(testCase["numPoints"])
    testCase["numChannels"] = int(testCase["numChannels"])

    return testCase


def gen_test_case_header_file(testCase):
    """Generate test case and write out input/output to header file

    Args:
        testCase (dict): Test case parameters
    """
    testId = testCase["ID"]
    numPoints = testCase["numPoints"]
    numChannels = testCase["numChannels"]

    x = np.random.uniform(
        low=-1.0, high=1.0, size=(numChannels, numPoints)
    ) + 1j * np.random.uniform(low=-1.0, high=1.0, size=(numChannels, numPoints))

    algo = fft1dBatched_32fc.FFTLIB_fft1dBatched_i32fc_c32fc_o32fc(
        numChannels, numPoints
    )
    y = algo.exec(x)

    headerFileName = "staticRefCase" + str(testId) + ".h"
    file_io.write_header_file(x, y, testCase, headerFileName)

    # Get complex values with min and max magnitude
    y_abs = np.abs(y)
    y_flat = y.flatten()
    minY = y_flat[np.argmin(y_abs.flatten())]
    maxY = y_flat[np.argmax(y_abs.flatten())]
    return [minY, maxY]


testCasesCsvFile = "test_cases_list.csv"
testIdList = []
testIdList += range(0, 100)


# Read CSV and process test cases
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


idatFileName = "../../FFTLIB_fft1dBatched_i32fc_c32fc_o32fc/FFTLIB_fft1dBatched_i32fc_c32fc_o32fc_idat.c"
kernelName = "FFTLIB_fft1dBatched_i32fc_c32fc_o32fc"

with open(idatFileName, "w") as idatFile:
    gen_preamble(idatFile, kernelName)
    gen_header_includes(idatFile, testCases)
    gen_idat_file(idatFile, testCases)

print("Idat file generation completed")
