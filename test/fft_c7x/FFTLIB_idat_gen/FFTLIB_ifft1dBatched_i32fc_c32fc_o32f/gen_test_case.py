# Copyright (C) 2026 Texas Instruments Incorporated
#
# SPDX-License-Identifier: Apache-2.0

from __future__ import print_function
from subprocess import call
from sys import platform

import csv
import algo_flow as af


def gen_ifdefs(idatFile, testCases):

    fIn = open("preamble.txt", "r")
    lines = fIn.readlines()
    idatFile.writelines(lines)
    idatFile.write("\n\n")

    for testCase in testCases:
        testId = testCase["ID"]
        testType = testCase["testType"]
        testCategory = testCase["testCategory"]
        numPoints = testCase["numPoints"]
        numChannels = testCase["numChannels"]
        inMode = testCase["inMode"]

        idatFile.write(
            "#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == %d)"
            " || (TEST_CATEGORY == 100) || (TEST_CASE == %d))\n"
            % ((testCategory), int(testId))
        )

        headerFileName = "staticRefCase" + str(testId) + ".h"
        idatFile.write(
            '#include "test_data/extended_test_cases/%s"\n' % (headerFileName)
        )
        idatFile.write("#endif\n\n")


def gen_idat_file(idatFile, testCases):
    """Generate and write test case parameters to idat file

    Args:
        param1 (file object): Input file object to idat.c file
        param2 (dict object): Dict object with test case parameter

    """

    idatFile.write("static ifft1dBatched_i32fc_c32fc_o32f_testParams_t testParams[] = ")
    idatFile.write("{\n")

    for testCase in testCases:

        testId = testCase["ID"]
        testType = testCase["testType"]
        testCategory = testCase["testCategory"]
        numPoints = testCase["numPoints"]
        numChannels = testCase["numChannels"]
        inMode = testCase["inMode"]

        idatFile.write(
            "#if (defined(ALL_TEST_CASES) || (TEST_CATEGORY == %d)"
            " || (TEST_CATEGORY == 100) || (TEST_CASE == %d))\n"
            % ((testCategory), int(testId))
        )

        idatFile.write("{\n")
        idatFile.write("%s, // test pattern\n" % (testType))
        if testType == "RANDOME":
            idatFile.write("NULL, // staticIn0\n")
            idatFile.write("NULL, // staticOut\n")
        else:
            ifftIn = "staticRefIn" + str(testId)
            ifftOut = "staticRefOut" + str(testId)
            idatFile.write("%s, // staticIn0\n" % (ifftIn))
            idatFile.write("%s, // staticOut\n" % (ifftOut))
        idatFile.write("%d, // numPoints\n" % (numPoints))
        idatFile.write("%d, // numChannels\n" % (numChannels))
        idatFile.write("%d, // test ID\n" % int(testId))
        idatFile.write("%d, // inMode\n" % int(inMode))
        idatFile.write("},\n")
        idatFile.write("#endif")
        idatFile.write("\n\n")

    idatFile.write("};\n\n")
    fIn = open("test_param_function.txt", "r")
    lines = fIn.readlines()
    idatFile.writelines(lines)


def process_test_case(testCase):
    """Convert str to int for necessary parameters

    Args:
        Param1(:obj: dict) : Dictionary object with test case parameters

    Returns:
        Obj: Dictionary object with necessary parameters converted to int

    """
    testCase["ID"] = int(testCase["ID"])
    testCase["testCategory"] = int(testCase["testCategory"])
    testCase["numPoints"] = int(testCase["numPoints"])
    testCase["numChannels"] = int(testCase["numChannels"])
    testCase["inMode"] = int(testCase["inMode"])

    return testCase


testCasesCsvFile = "test_list.csv"
# testIdList = [2]  # list of test IDs that we want to generate test data
testIdList = []  # list of test IDs that we want to generate test data
testIdList += range(2, 54)


def file_IO_test_vectors(x, y, testCase):
    testId = testCase["ID"]

    headerFileName = "staticRefCase" + str(testId) + ".h"
    attributesX = '__attribute__((section(".staticData"))) static ' + "float" + " "
    attributesY = '__attribute__((section(".staticData"))) static ' + "float" + " "

    print("Writting testCase:", testCase)
    outputDir = (
        "../../FFTLIB_ifft1dBatched_i32fc_c32fc_o32f/"
        + "test_data/extended_test_cases/"
    )

    with open(outputDir + headerFileName, "w") as f:
        [numChannels, numPoints] = x.shape
        f.write(attributesX + "staticRefIn" + str(testId) + "[]=\n")
        f.write("{\n")
        for c in range(0, x.shape[0]):
            for i in range(0, x.shape[1]):
                print("{:>2}".format(x[c, i].real), file=f, end=",")
                print("{:>2}".format(x[c, i].imag), file=f, end=",")
                # print("{:>2}".format(x[i].imag), file=f, end="")
            f.write("\n")
        f.write("\n};")
        f.write("\n\n")

    with open(outputDir + headerFileName, "a") as f:
        [numChannels, numPoints] = y.shape
        f.write(attributesX + "staticRefOut" + str(testId) + "[]=\n")
        f.write("{\n")
        for c in range(0, numChannels):
            for i in range(0, numPoints):
                print("{:>2}".format(y[c, i]), file=f, end=",")
            f.write("\n")
        f.write("\n};")
        f.write("\n\n")


def gen_test_case_header_file(testCase):

    testId = testCase["ID"]
    testType = testCase["testType"]
    testCategory = testCase["testCategory"]
    numPoints = testCase["numPoints"]
    numChannels = testCase["numChannels"]
    inMode = testCase["inMode"]

    [x, y] = af.algo_flow(numChannels, numPoints, inMode)
    file_IO_test_vectors(x, y, testCase)


with open(testCasesCsvFile) as csv_file:

    testCaseReader = csv.DictReader(csv_file)
    testCases = list(testCaseReader)

    for testCase in testCases:
        testCase = process_test_case(testCase)

    for testCase in testCases:
        if int(testCase["ID"]) in testIdList:
            if testCase["testType"] == "STATIC":
                gen_test_case_header_file(testCase)
                print("Test case generation completed")
            else:
                print("Skipping test case generation as tesType is RANDOM")


idatFileName = "../../FFTLIB_ifft1dBatched_i32fc_c32fc_o32f/FFTLIB_ifft1dBatched_i32fc_c32fc_o32f_idat.c"

with open(idatFileName, "w") as idatFile:
    gen_ifdefs(idatFile, testCases)
    gen_idat_file(idatFile, testCases)


if platform == "linux" or platform == "linux2":
    call(["indent", "-nut", "-i3", "-c55", "-l200", idatFileName])
elif platform == "darwin":
    call(["gindent", "-nut", "-i3", "-c55", "-l200", idatFileName])
    call(["rm", idatFileName + "~"])  # remove backup file

print("Idat file generation completed")
