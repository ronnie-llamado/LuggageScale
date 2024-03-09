#include "CppUTest/CommandLineTestRunner.h"

IMPORT_TEST_GROUP(CircularBuffer);
IMPORT_TEST_GROUP(HX711);

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
