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

/* ---------------------------------------------------------------------------*/
/* Runtime Diagnostics */
void RUNTIME_ERROR(uint32_t timestamp, const char *fail_message, uint32_t fail_value)
{
    CHECK(fail_message != NULL);
    mock().actualCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", timestamp)
        .withStringParameter("fail_message", fail_message)
        .withUnsignedIntParameter("fail_value", fail_value);
}

/* ---------------------------------------------------------------------------*/
/* Analog to Digital Conversion */
void sysclk_init(void)
{
    mock().actualCall("sysclk_init");
}

uint32_t gpio_enable_module(const gpio_map_t gpiomap, uint32_t size)
{
    return mock().actualCall("gpio_enable_module")
        .returnUnsignedIntValue();
}

int32_t adcifb_configure(volatile avr32_adcifb_t *adcifb,
    const adcifb_opt_t *p_adcifb_opt)
{
    return mock().actualCall("adcifb_configure")
        .returnIntValue();
}

int32_t adcifb_configure_trigger(volatile avr32_adcifb_t *adcifb,
    uint8_t trgmod, uint32_t trgper)
{
    return mock().actualCall("adcifb_configure_trigger")
        .returnIntValue();
}

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(HalAdcTests)
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
TEST(HalAdcTests, InitAdcCallsFunctions)
{
    mock().expectOneCall("sysclk_init");
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(GPIO_SUCCESS);
    mock().expectOneCall("adcifb_configure")
        .andReturnValue(PASS);
    mock().expectOneCall("adcifb_configure_trigger")
        .andReturnValue(PASS);
    init_adc_at32uc3l0256();
}

TEST(HalAdcTests, InitAdcGpioFailureCallsRuntimeError)
{
    mock().expectOneCall("sysclk_init");
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(GPIO_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "adc init: gpio_enable_module() failed")
        .withUnsignedIntParameter("fail_value", GPIO_INVALID_ARGUMENT);
    init_adc_at32uc3l0256();
}

TEST(HalAdcTests, InitAdcConfigFailureCallsRuntimeError)
{
    mock().expectOneCall("sysclk_init");
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(GPIO_SUCCESS);
    mock().expectOneCall("adcifb_configure")
        .andReturnValue(FAIL);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "adc init: configure_adc() failed")
        .withUnsignedIntParameter("fail_value", FAIL);
    init_adc_at32uc3l0256();
}
