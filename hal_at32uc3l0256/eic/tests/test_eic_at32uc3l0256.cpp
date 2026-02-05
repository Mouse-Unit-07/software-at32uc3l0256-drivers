/*================================ FILE INFO =================================*/
/* Filename           : test_eic_at32uc3l0256.cpp                             */
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
#include "eic_at32uc3l0256.h"
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
/* External Interrupt Controller */
uint32_t gpio_enable_module(const gpio_map_t gpiomap, uint32_t size)
{
    return mock().actualCall("gpio_enable_module")
        .returnIntValue();
}

void eic_clear_interrupt_line(volatile avr32_eic_t *eic, uint32_t line_number)
{
    CHECK(eic != NULL);
    mock().actualCall("eic_clear_interrupt_line");
}

void eic_init(volatile avr32_eic_t *eic, const eic_options_t *opt,
    uint32_t nb_lines)
{
    CHECK(eic != NULL);
    mock().actualCall("eic_init");
}

void eic_enable_lines(volatile avr32_eic_t *eic, uint32_t mask_lines)
{
    CHECK(eic != NULL);
    mock().actualCall("eic_enable_lines");
}

void eic_enable_interrupt_lines(volatile avr32_eic_t *eic, uint32_t mask_lines)
{
    CHECK(eic != NULL);
    mock().actualCall("eic_enable_interrupt_lines");
}

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(HalEicTests)
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
TEST(HalEicTests, InitEicCallsFunctions)
{
    mock().expectNCalls(2, "gpio_enable_module")
        .andReturnValue(GPIO_SUCCESS);
    mock().expectNCalls(2, "eic_init");
    mock().expectNCalls(2, "eic_enable_lines");
    mock().expectNCalls(2, "eic_enable_interrupt_lines");
    init_eic_at32uc3l0256();
}

TEST(HalEicTests, InitEicEncoderInitPinsFailureCallsRuntimeError)
{
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(GPIO_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "eic init pins: gpio_enable_module() on encoder pins failed")
        .withUnsignedIntParameter("fail_value", GPIO_INVALID_ARGUMENT);
    init_eic_at32uc3l0256();
}

TEST(HalEicTests, InitEicInitPushbuttonPinsFailureCallsRuntimeError)
{
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(GPIO_SUCCESS);
    mock().expectOneCall("gpio_enable_module")
        .andReturnValue(GPIO_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "eic init pins: gpio_enable_module() on pushbutton pin failed")
        .withUnsignedIntParameter("fail_value", GPIO_INVALID_ARGUMENT);
    init_eic_at32uc3l0256();
}

TEST(HalEicTests, Motor1EncoderIsrCallsFunctions)
{
    mock().expectOneCall("eic_clear_interrupt_line");
    motor_1_encoder_isr();
}

TEST(HalEicTests, Motor2EncoderIsrCallsFunctions)
{
    mock().expectOneCall("eic_clear_interrupt_line");
    motor_2_encoder_isr();
}

TEST(HalEicTests, ConfigPushbuttonIsrCallsFunctions)
{
    mock().expectOneCall("eic_clear_interrupt_line");
    config_pushbutton_isr();
}
