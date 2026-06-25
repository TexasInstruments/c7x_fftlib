# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

"""
Main test data generation orchestrator for FFTLIB_fft1dBatched_i16sc_c16sc_o16sc.
Coordinates CSV reading, test case generation, and idat.c file creation.
"""

from __future__ import print_function
from subprocess import call
from sys import platform

import csv
import json
import numpy as np
import fft1dBatched_i16sc_c16sc_o16sc as fft1dBatched_16sc
import file_io


def parse_shift_vector(shiftVectorStr):
    """Parse shift vector from CSV (JSON array format)

    Args:
        shiftVectorStr (str): Shift vector as JSON array string (e.g., "[0,1,1]")

    Returns:
        list: Shift vector as list of integers
    """
    if not shiftVectorStr or shiftVectorStr.strip() == "":
        return []
    try:
        return json.loads(shiftVectorStr)
    except (json.JSONDecodeError, ValueError):
        return []


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

    idatFile.write("#include <stdint.h>\n")
    idatFile.write('#include "%s_idat.h"\n' % kernelName)
    idatFile.write("\n")


def gen_shift_vectors(idatFile, testCases, shiftVectors):
    """Generate inline shift vectors for ALL tests (RANDOM and STATIC)

    Args:
        idatFile (file object): File object to write to
        testCases (list): List of test case dictionaries
        shiftVectors (dict): Dictionary of shiftVectors keyed by testId
    """
    # Generate shift vectors section header
    idatFile.write("/* ===== Shift Vectors ===== */\n")

    for testCase in testCases:
        testId = testCase["ID"]

        # Generate shift vectors for ALL test IDs that are in shiftVectors dict
        if testId in shiftVectors:
            shiftVec = shiftVectors[testId]
            idatFile.write('__attribute__((section(".staticData")))\n')
            idatFile.write("static uint32_t shiftVector%d[] = { " % testId)
            for i, val in enumerate(shiftVec):
                idatFile.write("%d" % int(val))
                if i < len(shiftVec) - 1:
                    idatFile.write(", ")
            idatFile.write(" };\n\n")


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
            headerFileName = "staticRefCase" + str(testId) + ".h"
            idatFile.write(
                "#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == %d)"
                " || (TEST_CATEGORY == 100) || (TEST_CASE == %d))\n"
                % ((testCategory), int(testId))
            )
            idatFile.write('#include "test_data/%s"\n' % (headerFileName))
            idatFile.write("#endif\n\n")


def gen_idat_file(idatFile, testCases):
    """Generate and write test case parameters to idat file

    Args:
        idatFile (file object): File object to write to
        testCases (list): List of test case dictionaries
    """
    idatFile.write(
        "static fft1dBatched_i16sc_c16sc_o16sc_testParams_t testParams[] = {\n\n"
    )

    for testCase in testCases:

        testId = testCase["ID"]
        testType = testCase["testType"]
        numPoints = testCase["numPoints"]
        numChannels = testCase["numChannels"]
        numShifts = testCase["numShifts"]

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
            shiftVec = "shiftVector%d" % testId
            idatFile.write(
                "        %s,%s// shiftVector\n" % (shiftVec, " " * (20 - len(shiftVec)))
            )
            idatFile.write("        NULL,%s// randomOut\n" % (" " * (20 - len("NULL"))))
        else:
            fftIn = "staticRefIn" + str(testId)
            fftOut = "staticRefOut" + str(testId)
            shiftVec = "shiftVector%d" % testId
            idatFile.write(
                "        %s,%s// staticIn\n" % (fftIn, " " * (20 - len(fftIn)))
            )
            idatFile.write(
                "        %s,%s// shiftVector\n" % (shiftVec, " " * (20 - len(shiftVec)))
            )
            idatFile.write(
                "        %s,%s// staticOut\n" % (fftOut, " " * (20 - len(fftOut)))
            )
        numShifts_spaces = " " * (20 - len(str(numShifts)))
        idatFile.write("        %s,%s// numShifts\n" % (numShifts, numShifts_spaces))
        numChannels_spaces = " " * (20 - len(str(numChannels)))
        numPoints_spaces = " " * (20 - len(str(numPoints)))
        testId_spaces = " " * (20 - len(str(testId)))
        idatFile.write(
            "        %d,%s// numChannels\n" % (numChannels, numChannels_spaces)
        )
        idatFile.write("        %d,%s// numPoints\n" % (numPoints, numPoints_spaces))
        idatFile.write("        %d,%s// test ID\n" % (testId, testId_spaces))
        idatFile.write("    },\n")
        idatFile.write("#endif\n\n")

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
    if "numShifts" in testCase:
        testCase["numShifts"] = int(testCase["numShifts"])

    return testCase


def gen_test_case_header_file(testCase):
    """Generate test case and write out input/output to header file

    Args:
        testCase (dict): Test case parameters

    Returns:
        array: Shift vector for this test case
    """
    testId = testCase["ID"]
    numPoints = testCase["numPoints"]
    numChannels = testCase["numChannels"]
    numShifts = int(testCase["numShifts"])

    # Parse shift vector from CSV
    shiftVecStr = testCase.get("shiftVector", "")
    shiftVec = parse_shift_vector(shiftVecStr)

    # Validate shift vector
    if len(shiftVec) != numShifts:
        print("Warning: shiftVector length mismatch for test ID %d" % testId)
        if len(shiftVec) == 0:
            shiftVec = [0] * numShifts  # Default fallback

    # Generate int16 complex input in range -1000 to 1000 for batched (numChannels x numPoints)
    x = np.zeros((numChannels, numPoints), dtype=np.complex128)
    for ch in range(numChannels):
        x_real = np.random.randint(-1000, 1001, numPoints).astype(
            np.int16
        )  # Range: -1000 to 1000
        x_imag = np.random.randint(-1000, 1001, numPoints).astype(
            np.int16
        )  # Range: -1000 to 1000
        x[ch, :] = x_real + 1j * x_imag

    # Execute algorithm with shift vector
    algo = fft1dBatched_16sc.FFTLIB_fft1dBatched_i16sc_c16sc_o16sc(
        numChannels, numPoints, shiftVec
    )
    y, _ = algo.exec(x)

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

shiftVectors = {}

# Read CSV and process test cases
with open(testCasesCsvFile) as csv_file:
    testCaseReader = csv.DictReader(csv_file)
    testCases = list(testCaseReader)

    for testCase in testCases:
        testCase = process_test_case(testCase)

    for testCase in testCases:
        if int(testCase["ID"]) in testIdList:
            testId = testCase["ID"]
            testType = testCase["testType"]
            numPoints = testCase["numPoints"]
            numChannels = testCase["numChannels"]
            numShifts = int(testCase["numShifts"])

            # Parse shift vector from CSV (for both STATIC and RANDOM)
            shiftVecStr = testCase.get("shiftVector", "")
            shiftVec = parse_shift_vector(shiftVecStr)

            if len(shiftVec) != numShifts:
                print("Warning: shiftVector length mismatch for test ID %d" % testId)
                shiftVec = [0] * numShifts  # Default fallback

            # Store shift vector for idat.c generation
            shiftVectors[testId] = shiftVec

            if testType == "STATIC":
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
                    testType,
                )


idatFileName = "../../FFTLIB_fft1dBatched_i16sc_c16sc_o16sc/FFTLIB_fft1dBatched_i16sc_c16sc_o16sc_idat.c"
kernelName = "FFTLIB_fft1dBatched_i16sc_c16sc_o16sc"

with open(idatFileName, "w") as idatFile:
    gen_preamble(idatFile, kernelName)
    gen_header_includes(idatFile, testCases)
    gen_shift_vectors(idatFile, testCases, shiftVectors)
    gen_idat_file(idatFile, testCases)

print("Idat file generation completed")
