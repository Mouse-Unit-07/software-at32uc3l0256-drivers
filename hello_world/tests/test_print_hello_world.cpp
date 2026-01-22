/*================================ FILE INFO =================================*/
/* Filename           : test_print_hello_world.cpp                            */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>
extern "C" {
#include "print_hello_world.h"
}

#include <CppUTest/TestHarness.h>

/*============================================================================*/
/*                             Private Definitions                            */
/*============================================================================*/
static void failWithMessageIfNull(FILE *file, const char *fail_message)
{
    if (file == nullptr) {
        FAIL(fail_message);
    }
}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(PrintHelloTest)
{
    FILE *original_stdout = nullptr;

    void setup()
    {
        original_stdout = stdout;
        FILE *file = freopen("test_output.txt", "w+", stdout);
        failWithMessageIfNull(file, 
            "Failed to redirect stdout to test_output.txt");
    }

    void teardown()
    {
        failWithMessageIfNull(stdout, "stdout is nullptr");
        fclose(stdout);
        FILE *file = freopen("CON", "w", original_stdout);
        failWithMessageIfNull(file, "Failed to restore stdout to console");
    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(PrintHelloTest, PrintsHelloWorld)
{
    enum {
        MAX_BUFFER_SIZE = 128u
    };
    char buffer[MAX_BUFFER_SIZE] = {0};

    printHelloWorld();

    fflush(stdout);

    FILE *file = fopen("test_output.txt", "r");
    failWithMessageIfNull(file, "Failed to open test output file");

    fread(buffer, sizeof(char), sizeof(buffer), file);
    fclose(file);

    STRCMP_EQUAL("Hello World\r\n", buffer);
}
