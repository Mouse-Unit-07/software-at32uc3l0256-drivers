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

bool pwma_set_multiple_values(volatile avr32_pwma_t *pwma, uint32_t channel_mask,
                        uint16_t *channel_duty_cycles)
{
    return mock().actualCall("pwma_set_multiple_values")
        .returnBoolValue();
}

bool pwma_write_top_value(volatile avr32_pwma_t *pwma, uint16_t top_value)
{
    return mock().actualCall("pwma_write_top_value")
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
        .andReturnValue(static_cast<bool>(PASS));
    mock().expectOneCall("pwma_set_multiple_values")
        .andReturnValue(static_cast<bool>(PASS));
    mock().expectOneCall("pwma_write_top_value")
        .andReturnValue(static_cast<bool>(PASS));
    init_pwm_at32uc3l0256();
}

TEST(HalPwmTests, InitPwmFreqAndSpreadConfigFailureCallsRuntimeError)
{
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(1);
    mock().expectOneCall("pwma_config_enable")
        .andReturnValue(static_cast<bool>(FAIL));
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "pwm init: configure_frequency_and_spread() failed")
        .withUnsignedIntParameter("fail_value", FAIL);
    init_pwm_at32uc3l0256();
}

TEST(HalPwmTests, InitPwmSetDutyCyclesFailureCallsRuntimeError)
{
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(1);
    mock().expectOneCall("pwma_config_enable")
        .andReturnValue(static_cast<bool>(PASS));
    mock().expectOneCall("pwma_set_multiple_values")
        .andReturnValue(static_cast<bool>(FAIL));
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "pwm init: set_duty_cycles() failed")
        .withUnsignedIntParameter("fail_value", FAIL);
    init_pwm_at32uc3l0256();
}

TEST(HalPwmTests, InitPwmSetTopFailureCallsRuntimeError)
{
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(1);
    mock().expectOneCall("pwma_config_enable")
        .andReturnValue(static_cast<bool>(PASS));
    mock().expectOneCall("pwma_set_multiple_values")
        .andReturnValue(static_cast<bool>(PASS));
    mock().expectOneCall("pwma_write_top_value")
        .andReturnValue(static_cast<bool>(FAIL));
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "pwm init: set_pwm_top() failed")
        .withUnsignedIntParameter("fail_value", FAIL);
    init_pwm_at32uc3l0256();
}

TEST(HalPwmTests, DeinitPwm)
{
    deinit_pwm_at32uc3l0256();
}

TEST(HalPwmTests, SetPwmDutyCycleCallsFunctions)
{
    mock().expectOneCall("pwma_set_multiple_values")
        .andReturnValue(static_cast<bool>(PASS));
    
    set_pwm_duty_cycle_percent_at32uc3l0256(
        &wheel_motor_1, 10);
}

TEST(HalPwmTests, SetPwmDutyCycleBadPercentDoesNotCauseErrors)
{
    mock().expectOneCall("pwma_set_multiple_values")
        .andReturnValue(static_cast<bool>(PASS));
    
    set_pwm_duty_cycle_percent_at32uc3l0256(
        &wheel_motor_1, 9000);
}

TEST(HalPwmTests, SetPwmDutyCycleSetDutyCyclesFailureCallsRuntimeError)
{
    mock().expectOneCall("pwma_set_multiple_values")
        .andReturnValue(static_cast<bool>(FAIL));
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "pwm set duty cycle: set_duty_cycles() failed")
        .withUnsignedIntParameter("fail_value", FAIL);
    
    set_pwm_duty_cycle_percent_at32uc3l0256(
        &wheel_motor_1, 0);
}
