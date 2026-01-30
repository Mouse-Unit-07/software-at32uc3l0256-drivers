/*================================ FILE INFO =================================*/
/* Filename           : test_hal_at32uc3l0256.cpp                             */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256 library                           */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/

extern "C" {
#include <stdint.h>
#include "clock_at32uc3l0256.h"
}

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
extern "C"
{

void dfll_enable_open_loop(const struct dfll_config *cfg, unsigned int dfll_id)
{
    CHECK(cfg != NULL);
    mock().actualCall("dfll_enable_open_loop")
        .withUnsignedIntParameter("dfll_id", dfll_id);
}

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(HalClockTests)
{
    void setup() override
    {
        mock().clear();
    }

    void teardown() override
    {
        mock().checkExpectations();
        mock().clear();
    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(HalClockTests, InitCallsDfllEnableOpenLoopWithCorrectArguments)
{
    mock().expectOneCall("dfll_enable_open_loop")
        .withUnsignedIntParameter("dfll_id", 0);
    init_clock_at32uc3l0256();
}
