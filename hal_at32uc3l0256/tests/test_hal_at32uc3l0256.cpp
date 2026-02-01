/*================================ FILE INFO =================================*/
/* Filename           : test_hal_at32uc3l0256.cpp                             */
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
#include "clock_at32uc3l0256.h"
#include "gpio_at32uc3l0256.h"
}

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
/* Clock */
enum
{
    DFLL_FCPU_PRESCALER = 2, /* F_CPU = (DFLL base) / 2^2 = 35MHz */
    DFLL_PBA_PRESCALER = 1, /* PBA = (DFLL base) / 2^1 = 70MHz */
    DFLL_PBB_PRESCALER = 1 /* PBB = (DFLL base) / 2^1 = 70MHz */
};

/* GPIO */
enum
{
    INPUT_COUNT = 4,
    OUTPUT_COUNT = 10
};

enum
{
    AVR32_PIN_PB11 = 43,
    AVR32_PIN_PB06 = 38,
    AVR32_PIN_PA22 = 22,
    AVR32_PIN_PB03 = 35,
    AVR32_PIN_PB02 = 34,
    AVR32_PIN_PB00 = 32,
    AVR32_PIN_PB04 = 36,
    AVR32_PIN_PB10 = 42,
    AVR32_PIN_PB01 = 33,
    AVR32_PIN_PA07 = 7,
    AVR32_PIN_PA21 = 21,
    AVR32_PIN_PA20 = 20,
    AVR32_PIN_PA04 = 4,
    AVR32_PIN_PA11 = 11,
};

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

extern const struct gpio_handle regulators_enable; /* arbitrary input pin */
extern const struct gpio_handle led_d1; /* arbitrary output pin */

/*============================================================================*/
/*                            Mock Implementations                            */
/*============================================================================*/
extern "C"
{
/* Clock */
void dfll_enable_open_loop(const struct dfll_config *cfg, unsigned int dfll_id)
{
    CHECK(cfg != NULL);
    mock().actualCall("dfll_enable_open_loop")
        .withUnsignedIntParameter("dfll_id", dfll_id);
}

void sysclk_set_prescalers(unsigned int cpu_shift,
                            unsigned int pba_shift, unsigned int pbb_shift)
{
    mock().actualCall("sysclk_set_prescalers")
        .withUnsignedIntParameter("cpu_shift", cpu_shift)
        .withUnsignedIntParameter("pba_shift", pba_shift)
        .withUnsignedIntParameter("pbb_shift", pbb_shift);
}

void sysclk_set_source(uint_fast8_t src)
{
    mock().actualCall("sysclk_set_source");
}

/* Untested- static inline functions in ASF headers: */
/* dfll_config_init_open_loop_mode() */
/* dfll_config_tune_for_target_hz() */
/* osc_disable() */
/* delay_ms() */
/* delay_us() */

/* ---------------------------------------------------------------------------*/
/* GPIO */
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
TEST(HalClockTests, InitClockCallsFunctionsWithCorrectArguments)
{
    mock().expectOneCall("dfll_enable_open_loop")
        .withUnsignedIntParameter("dfll_id", 0);
    mock().expectOneCall("sysclk_set_prescalers")
        .withUnsignedIntParameter("cpu_shift", DFLL_FCPU_PRESCALER)
        .withUnsignedIntParameter("pba_shift", DFLL_PBA_PRESCALER)
        .withUnsignedIntParameter("pbb_shift", DFLL_PBB_PRESCALER);
    mock().expectOneCall("sysclk_set_source");
    
    init_clock_at32uc3l0256();
}

TEST(HalClockTests, DeinitClock)
{
    deinit_clock_at32uc3l0256();
}

TEST(HalClockTests, DelayMs)
{
    delay_ms_at32uc3l0256(1000);
}

TEST(HalClockTests, DeinitUs)
{
    delay_us_at32uc3l0256(1000000);
}

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
