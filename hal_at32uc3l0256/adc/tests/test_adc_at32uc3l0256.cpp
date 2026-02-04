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
constexpr int WATCHDOG_MAX{2000u};

void init_adc_without_cpputest_checks(void)
{
    mock().ignoreOtherCalls();
    init_adc_at32uc3l0256();
    mock().clear();
}

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

void RUNTIME_TELEMETRY(uint32_t timestamp, const char *fail_message, uint32_t fail_value)
{
    CHECK(fail_message != NULL);
    mock().actualCall("RUNTIME_TELEMETRY")
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
    CHECK(adcifb != NULL);
    CHECK(p_adcifb_opt != NULL);
    return mock().actualCall("adcifb_configure")
        .returnIntValue();
}

int32_t adcifb_configure_trigger(volatile avr32_adcifb_t *adcifb,
    uint8_t trgmod, uint32_t trgper)
{
    CHECK(adcifb != NULL);
    return mock().actualCall("adcifb_configure_trigger")
        .returnIntValue();
}

bool adcifb_is_ready(volatile avr32_adcifb_t *adcifb)
{
    CHECK(adcifb != NULL);
    return mock().actualCall("adcifb_is_ready")
        .returnBoolValue();
}

bool adcifb_is_drdy(volatile avr32_adcifb_t *adcifb)
{
    CHECK(adcifb != NULL);
    return mock().actualCall("adcifb_is_drdy")
        .returnBoolValue();
}

uint32_t adcifb_get_last_data(volatile avr32_adcifb_t *adcifb)
{
    CHECK(adcifb != NULL);
    return mock().actualCall("adcifb_get_last_data")
        .returnUnsignedIntValue();
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
        .withStringParameter("fail_message", "adc init: init_adc_pins() failed")
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
        .withStringParameter("fail_message", "adc init: configure_adc_except_trigger() failed")
        .withUnsignedIntParameter("fail_value", FAIL);
    init_adc_at32uc3l0256();
}

TEST(HalAdcTests, InitAdcConfigTriggerFailureCallsRuntimeError)
{
    mock().expectOneCall("sysclk_init");
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(GPIO_SUCCESS);
    mock().expectOneCall("adcifb_configure")
        .andReturnValue(PASS);
    mock().expectOneCall("adcifb_configure_trigger")
        .andReturnValue(FAIL);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "adc init: configure_adc_trigger() failed")
        .withUnsignedIntParameter("fail_value", FAIL);
    init_adc_at32uc3l0256();
}

TEST(HalAdcTests, NothingCalledAfterInitAdcFailure)
{
    mock().expectOneCall("sysclk_init");
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(GPIO_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "adc init: init_adc_pins() failed")
        .withUnsignedIntParameter("fail_value", GPIO_INVALID_ARGUMENT);
    init_adc_at32uc3l0256();

    read_adc_channel_at32uc3l0256(&ir_sensor_1);
}

TEST(HalAdcTests, DeinitAdc)
{
    deinit_adc_at32uc3l0256();
}

TEST(HalAdcTests, ReadAdcCallsFunctions)
{
    init_adc_without_cpputest_checks();

    mock().expectOneCall("adcifb_is_ready")
        .andReturnValue(true);
    mock().expectOneCall("RUNTIME_TELEMETRY")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "enable adc channel: adcifb_is_ready() passed watchdog")
        .withUnsignedIntParameter("fail_value", 0);
    mock().expectOneCall("adcifb_is_drdy")
        .andReturnValue(true);
    mock().expectOneCall("RUNTIME_TELEMETRY")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "start adc conversion: adcifb_is_drdy() passed watchdog")
        .withUnsignedIntParameter("fail_value", 0);
    mock().expectOneCall("adcifb_get_last_data")
        .andReturnValue(1023);
    read_adc_channel_at32uc3l0256(&ir_sensor_1);
}

TEST(HalAdcTests, ReadAdcAdcifbIsReadyWatchdogFailureCallsRuntimeError)
{
    init_adc_without_cpputest_checks();

    mock().expectNCalls(WATCHDOG_MAX + 1, "adcifb_is_ready")
        .andReturnValue(false);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "enable adc channel: adcifb_is_ready() failed watchdog")
        .withUnsignedIntParameter("fail_value", WATCHDOG_MAX);
    read_adc_channel_at32uc3l0256(&ir_sensor_1);
}

TEST(HalAdcTests, ReadAdcAdcifbIsDrdyWatchdogFailureCallsRuntimeError)
{
    init_adc_without_cpputest_checks();
    
    mock().expectOneCall("adcifb_is_ready")
        .andReturnValue(true);
    mock().expectOneCall("RUNTIME_TELEMETRY")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "enable adc channel: adcifb_is_ready() passed watchdog")
        .withUnsignedIntParameter("fail_value", 0);
    mock().expectNCalls(WATCHDOG_MAX + 1, "adcifb_is_drdy")
        .andReturnValue(false);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "start adc conversion: adcifb_is_drdy() failed watchdog")
        .withUnsignedIntParameter("fail_value", WATCHDOG_MAX);
    read_adc_channel_at32uc3l0256(&ir_sensor_1);
}
