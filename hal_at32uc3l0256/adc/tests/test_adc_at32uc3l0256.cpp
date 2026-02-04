/*================================ FILE INFO =================================*/
/* Filename           : test_adc_at32uc3l0256.cpp                           */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256 library                           */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {
#include <stdint.h>
#include "asf.h"
#include "adc_at32uc3l0256.h"
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

uint32_t gpio_enable_module(const gpio_map_t gpiomap, uint32_t size)
{
    return mock().actualCall("gpio_enable_module")
        .returnUnsignedIntValue();
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
TEST(HalClockTests, InitAdcCallsFunctions)
{
    mock().expectOneCall("sysclk_init");
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(1);
    init_adc_at32uc3l0256();
}
