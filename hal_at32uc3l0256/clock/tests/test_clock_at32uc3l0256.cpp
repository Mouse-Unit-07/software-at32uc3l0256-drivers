/*================================ FILE INFO =================================*/
/* Filename           : test_clock_at32uc3l0256.cpp                           */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256 library                           */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C"
{

#include <stdint.h>
#include "asf.h"
#include "clock_at32uc3l0256.h"

}

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
/* none */

/*============================================================================*/
/*                            Mock Implementations                            */
/*============================================================================*/
extern "C"
{

void sysclk_init(void)
{
    mock().actualCall("sysclk_init");
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
TEST(HalClockTests, InitClockCallsFunctions)
{
    mock().expectOneCall("sysclk_init");

    init_clock_at32uc3l0256();
}

TEST(HalClockTests, DeinitClock)
{
    deinit_clock_at32uc3l0256();
}

TEST(HalClockTests, DelayMs)
{
    delay_ms_at32uc3l0256(1000); /* arbitrary delay value */
}

TEST(HalClockTests, DeinitUs)
{
    delay_us_at32uc3l0256(1000000); /* arbitrary delay value */
}
