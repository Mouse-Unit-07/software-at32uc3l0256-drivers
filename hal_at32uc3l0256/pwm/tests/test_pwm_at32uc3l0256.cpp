/*================================ FILE INFO =================================*/
/* Filename           : test_pwm_at32uc3l0256.cpp                             */
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
#include "pwm_at32uc3l0256.h"
}

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/


/*============================================================================*/
/*                            Mock Implementations                            */
/*============================================================================*/
extern "C"
{

/* ---------------------------------------------------------------------------*/
/* Pulse Width Modulation */
uint32_t gpio_enable_module(const gpio_map_t gpiomap, uint32_t size)
{
    return mock().actualCall("gpio_enable_module")
        .returnIntValue();
}

bool pwma_config_enable(volatile avr32_pwma_t *pwma, uint32_t pwma_freq_hz,
                        uint32_t gclk_freq_hz, uint16_t spread)
{
    return mock().actualCall("pwma_config_enable")
        .returnBoolValue();
}

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(HalPwmTests)
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
TEST(HalPwmTests, InitPwmCallsFunctions)
{
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(1);
    mock().expectOneCall("pwma_config_enable")
        .andReturnValue(true);
    init_pwm_at32uc3l0256();
}
