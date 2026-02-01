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
#include "asf.h"
#include "clock_at32uc3l0256.h"
#include "gpio_at32uc3l0256.h"
#include "timer_counter_at32uc3l0256.h"
}

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
/* ---------------------------------------------------------------------------*/
/* Clock */

/* ---------------------------------------------------------------------------*/
/* GPIO */
enum
{
    INPUT_COUNT = 4,
    OUTPUT_COUNT = 10
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

/* ---------------------------------------------------------------------------*/
/* Timer Counter */

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

/* Unable to mock- below are static inline functions in ASF headers: */
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

void gpio_tgl_gpio_pin(uint32_t pin)
{
    mock().actualCall("gpio_tgl_gpio_pin");
}

/* ---------------------------------------------------------------------------*/
/* Timer Counter */
int tc_init_waveform(volatile avr32_tc_t *tc, const tc_waveform_opt_t *opt)
{
    CHECK(tc != NULL);
    CHECK(opt != NULL);
    return mock().actualCall("tc_init_waveform")
        .returnIntValue();
}

int tc_write_rc(volatile avr32_tc_t *tc, unsigned int channel, unsigned short value)
{
    CHECK(tc != NULL);
    return mock().actualCall("tc_write_rc")
        .returnIntValue();
    return 1;
}

int tc_configure_interrupts(volatile avr32_tc_t *tc, unsigned int channel, const tc_interrupt_t *bitfield)
{
    CHECK(tc != NULL);
    CHECK(bitfield != NULL);
    return mock().actualCall("tc_configure_interrupts")
        .returnIntValue();
}

int tc_start(volatile avr32_tc_t *tc, unsigned int channel)
{
    CHECK(tc != NULL);
    return mock().actualCall("tc_start")
        .returnIntValue();
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

TEST_GROUP(HalTimerCounterTests)
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
/* ---------------------------------------------------------------------------*/
/* Clock */
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
    delay_ms_at32uc3l0256(1000); /* arbitrary delay value */
}

TEST(HalClockTests, DeinitUs)
{
    delay_us_at32uc3l0256(1000000); /* arbitrary delay value */
}

/* ---------------------------------------------------------------------------*/
/* GPIO */
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

/* ---------------------------------------------------------------------------*/
/* Timer Counter */
TEST(HalTimerCounterTests, InitTimerCounterCallsFunctions)
{
    mock().expectOneCall("tc_init_waveform")
        .andReturnValue(1);
    mock().expectOneCall("tc_write_rc")
        .andReturnValue(1);
    mock().expectOneCall("tc_configure_interrupts")
        .andReturnValue(1);
    mock().expectOneCall("tc_start")
        .andReturnValue(1);
    init_timer_counter_at32uc3l0256();
}

TEST(HalTimerCounterTests, InitTimerCounterInitWaveformFailureCallsRuntimeError)
{
    mock().expectOneCall("tc_init_waveform")
        .andReturnValue(TC_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "tc_init_waveform call failed")
        .withUnsignedIntParameter("fail_value", TC_INVALID_ARGUMENT);
    init_timer_counter_at32uc3l0256();
}

TEST(HalTimerCounterTests, InitTimerCounterWriteRcFailureCallsRuntimeError)
{
    mock().expectOneCall("tc_init_waveform")
        .andReturnValue(1);
    mock().expectOneCall("tc_write_rc")
        .andReturnValue(TC_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "tc_write_rc call failed")
        .withUnsignedIntParameter("fail_value", TC_INVALID_ARGUMENT);
    init_timer_counter_at32uc3l0256();
}

TEST(HalTimerCounterTests, InitTimerCounterConfigureInterruptsFailureCallsRuntimeError)
{
    mock().expectOneCall("tc_init_waveform")
        .andReturnValue(1);
    mock().expectOneCall("tc_write_rc")
        .andReturnValue(1);
    mock().expectOneCall("tc_configure_interrupts")
        .andReturnValue(TC_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "tc_configure_interrupts call failed")
        .withUnsignedIntParameter("fail_value", TC_INVALID_ARGUMENT);
    init_timer_counter_at32uc3l0256();
}

TEST(HalTimerCounterTests, InitTimerCounterTcStartFailureCallsRuntimeError)
{
    mock().expectOneCall("tc_init_waveform")
        .andReturnValue(1);
    mock().expectOneCall("tc_write_rc")
        .andReturnValue(1);
    mock().expectOneCall("tc_configure_interrupts")
        .andReturnValue(1);
    mock().expectOneCall("tc_start")
        .andReturnValue(TC_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
        .withUnsignedIntParameter("timestamp", 0)
        .withStringParameter("fail_message", "tc_start call failed")
        .withUnsignedIntParameter("fail_value", TC_INVALID_ARGUMENT);
    init_timer_counter_at32uc3l0256();
}
