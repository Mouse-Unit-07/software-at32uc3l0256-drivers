/*================================ FILE INFO =================================*/
/* Filename           : test_gpio_at32uc3l0256.cpp                            */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256 library                           */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
#include <unordered_set>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {
#include <stdint.h>
#include "asf.h"
#include "gpio_at32uc3l0256.h"
}

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
extern "C"
{

enum
{
    INPUT_COUNT = 4,
    OUTPUT_COUNT = 10
};
}

std::unordered_set<int> gpio_pins {
    AVR32_PIN_PB11,
    AVR32_PIN_PB11,
    AVR32_PIN_PB06,
    AVR32_PIN_PA22,
    AVR32_PIN_PB03,
    AVR32_PIN_PB02,
    AVR32_PIN_PB00,
    AVR32_PIN_PB04,
    AVR32_PIN_PB10,
    AVR32_PIN_PB01,
    AVR32_PIN_PA07,
    AVR32_PIN_PA21,
    AVR32_PIN_PA20,
    AVR32_PIN_PA04,
    AVR32_PIN_PA11
};

extern "C"
{
extern const struct gpio_handle regulators_enable; /* arbitrary input pin */
extern const struct gpio_handle led_d1; /* arbitrary output pin */
}

/*============================================================================*/
/*                            Mock Implementations                            */
/*============================================================================*/
extern "C"
{

void gpio_configure_pin(uint32_t pin, uint32_t flags)
{
    CHECK(gpio_pins.find(static_cast<int>(pin)) != gpio_pins.end());
    mock().actualCall("gpio_configure_pin");
}

bool gpio_get_pin_value(uint32_t pin)
{
    return mock().actualCall("gpio_get_pin_value")
        .returnBoolValue();
}

void gpio_set_gpio_pin(uint32_t pin)
{
    mock().actualCall("gpio_set_gpio_pin");
}

void gpio_clr_gpio_pin(uint32_t pin)
{
    mock().actualCall("gpio_clr_gpio_pin");
}

void gpio_tgl_gpio_pin(uint32_t pin)
{
    mock().actualCall("gpio_tgl_gpio_pin");
}

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(HalGpioTests)
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
TEST(HalGpioTests, InitGpioCallsFunctions)
{
    mock().expectNCalls(INPUT_COUNT + OUTPUT_COUNT, "gpio_configure_pin");
    init_gpio_at32uc3l0256();
}

TEST(HalGpioTests, DeinitGpio)
{
    deinit_gpio_at32uc3l0256();
}

TEST(HalGpioTests, ReadPinCallsFunctions)
{
    mock().expectOneCall("gpio_get_pin_value")
        .andReturnValue(true);
    read_gpio_pin_at32uc3l0256(&regulators_enable);
}

TEST(HalGpioTests, WritePinHighCallsSetFunction)
{
    mock().expectOneCall("gpio_set_gpio_pin");
    write_gpio_pin_at32uc3l0256(&led_d1, 1);
}

TEST(HalGpioTests, WritePinLowCallsClearFunction)
{
    mock().expectOneCall("gpio_clr_gpio_pin");
    write_gpio_pin_at32uc3l0256(&led_d1, 0);
}

TEST(HalGpioTests, TogglePinCallsFunction)
{
    mock().expectOneCall("gpio_tgl_gpio_pin");
    toggle_gpio_pin_at32uc3l0256(&led_d1);
}
