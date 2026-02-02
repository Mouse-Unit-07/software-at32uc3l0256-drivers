/*================================ FILE INFO =================================*/
/* Filename           : test_timer_counter_at32uc3l0256.cpp                   */
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
#include "timer_counter_at32uc3l0256.h"
}

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
void expect_successful_init_timer_counter_at32uc3l0256(void)
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

/* this call takes 9 seconds to run */
void call_tc_isr_to_uint32_max(void)
{
    for (uint32_t i = 0u; i < UINT32_MAX; i++) {
        tc_irq();
    }
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

TEST(HalTimerCounterTests, TimerCounterCountIsZeroOnInit)
{
    expect_successful_init_timer_counter_at32uc3l0256();
    CHECK(get_timer_count_at32uc3l0256() == 0);
}

/* time consuming- turn on when needed */
IGNORE_TEST(HalTimerCounterTests, TimerCounterIsrIncrementsCount)
{
    expect_successful_init_timer_counter_at32uc3l0256();
    call_tc_isr_to_uint32_max();
    CHECK(get_timer_count_at32uc3l0256() == UINT32_MAX);
}

/* time consuming- turn on when needed */
IGNORE_TEST(HalTimerCounterTests, TimerCounterRollsOverOnOverflow)
{
    expect_successful_init_timer_counter_at32uc3l0256();
    call_tc_isr_to_uint32_max();
    tc_irq();
    CHECK(get_timer_count_at32uc3l0256() == 0);
}

TEST(HalTimerCounterTests, DeinitResetsCount)
{
    expect_successful_init_timer_counter_at32uc3l0256();
    tc_irq();
    deinit_timer_counter_at32uc3l0256();
    CHECK(get_timer_count_at32uc3l0256() == 0);
}

TEST(HalTimerCounterTests, RestartTimerResetsCount)
{
    expect_successful_init_timer_counter_at32uc3l0256();
    tc_irq();
    restart_timer_at32uc3l0256();
    CHECK(get_timer_count_at32uc3l0256() == 0);
}
