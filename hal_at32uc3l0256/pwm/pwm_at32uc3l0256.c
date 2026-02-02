/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : pwm_at32uc3l0256.c                                    */
/*                                                                            */
/* AT32UC3L0256 implementation for timer counter HAL                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "asf.h"
#include "runtime_diagnostics.h"
#include "pwm_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
static bool pwm_failed = false;

static volatile avr32_pwma_t *pwma = &AVR32_PWMA;
static uint16_t duty_cycles[] = {0u, 0u, 0u}; /* 0% on init for PWM off */

enum
{
    WHEEL_MOTOR_1_INDEX = 0,
    WHEEL_MOTOR_2_INDEX,
    VACUUM_MOTOR_1_INDEX
};

/* avoiding enum to prevent casting errors */
static const uint32_t GCLK_FREQUENCY = 48000000;

/* needs to be a macro to concatenate w/ other macros */
#define PWMA_INTERRUPT_PRIORITY 0

/*----------------------------------------------------------------------------*/
/*                               Public Handles                               */
/*----------------------------------------------------------------------------*/
const struct pwm_handle wheel_motor_1 = {
    .index = WHEEL_MOTOR_1_INDEX
};

const struct pwm_handle wheel_motor_2 = {
    .index = WHEEL_MOTOR_2_INDEX
};

const struct pwm_handle vacuum_motor = {
    .index = VACUUM_MOTOR_1_INDEX
};

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
#ifndef WINDOWS_BUILD /* untestable ISR*/
ISR(tofl_irq, AVR32_PWMA_IRQ_GROUP, PWMA_INTERRUPT_PRIORITY)
{
    pwma->scr=AVR32_PWMA_SCR_TOFL_MASK;
}
#endif

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
static void reset_pwm_flags(void);
static void pwm_runtime_error(const char *fail_message, uint32_t fail_value);
static void initialize_pwm_pins(void);
static void initialize_pwm_clock_source(void);
static bool configure_frequency_and_spread(void);
static bool set_duty_cycles(void);
static bool set_pwm_top(void);
static void enable_pwm_interrupts(void);
static uint32_t percent_to_duty_cycle(uint32_t percent);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_pwm_at32uc3l0256(void)
{
    bool asf_return_value = FAIL;

    reset_pwm_flags();

    initialize_pwm_pins();
    initialize_pwm_clock_source();

    asf_return_value = configure_frequency_and_spread();
    if (asf_return_value == FAIL) {
        pwm_runtime_error("pwm init: configure_frequency_and_spread() failed", FAIL);
        return;
    }

    asf_return_value = set_duty_cycles();
    if (asf_return_value == FAIL) {
        pwm_runtime_error("pwm init: set_duty_cycles() failed", FAIL);
        return;
    }

    asf_return_value = set_pwm_top();
    if (asf_return_value == FAIL) {
        pwm_runtime_error("pwm init: set_pwm_top() failed", FAIL);
        return;
    }

    enable_pwm_interrupts();
}

void deinit_pwm_at32uc3l0256(void)
{
    reset_pwm_flags();
}

void set_pwm_duty_cycle_percent_at32uc3l0256(const struct pwm_handle *handle, uint32_t percent)
{
    /* assuming the caller checks preconditions, but silently truncate anyway */
    if (percent > 100u) {
        percent = 100; 
    }

    uint32_t new_dc = percent_to_duty_cycle(percent);
    duty_cycles[handle->index] = new_dc;

    bool asf_return_value = set_duty_cycles();
    if (asf_return_value == FAIL) {
        pwm_runtime_error("pwm set duty cycle: set_duty_cycles() failed", FAIL);
        return;
    }
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
static void reset_pwm_flags(void)
{
    pwm_failed = false;
}

static void pwm_runtime_error(const char *fail_message, uint32_t fail_value)
{
    RUNTIME_ERROR(0, fail_message, fail_value);
    pwm_failed = true;
}

static void initialize_pwm_pins(void)
{
    static const gpio_map_t PWMA_GPIO_MAP = {
        {AVR32_PWMA_28_PIN, AVR32_PWMA_28_FUNCTION}, /* wheel motor 1 */
        {AVR32_PWMA_13_PIN, AVR32_PWMA_13_FUNCTION}, /* wheel motor 2 */
        {AVR32_PWMA_31_PIN, AVR32_PWMA_31_FUNCTION}, /* vacuum motor */
    };
    gpio_enable_module(PWMA_GPIO_MAP, 
        sizeof(PWMA_GPIO_MAP) / sizeof(PWMA_GPIO_MAP[0]));
}

static void initialize_pwm_clock_source(void)
{
    const unsigned int GCLK_ID = AVR32_SCIF_GCLK_PWMA;

    enum
    {
        GCLK_SOURCE = AVR32_SCIF_GC_USES_CLK_PBA
    };

    uint32_t div = div_ceil((sysclk_get_pba_hz()), GCLK_FREQUENCY);
    genclk_enable_config(GCLK_ID, GCLK_SOURCE, div);
}

static bool configure_frequency_and_spread(void)
{
    /* PWM output freq limited such that: */
    /* MM_PWMA_GCLK_FREQUENCY/OUTPUT_FREQUENCY < 255 */
    /* to minimize PWM frequency, 48MHz/190kHz = 252 */
    /* for some reason we can't change GCLK, but we can change OUTPUT_FREQUENCY */
    const uint32_t OUTPUT_FREQUENCY = 190000u;
    const uint16_t SPREAD = 0u;

    return pwma_config_enable(pwma, OUTPUT_FREQUENCY, GCLK_FREQUENCY, SPREAD);
}

static bool set_duty_cycles(void)
{
    /* channel IDs come from pin numbers- can't find masks in ASF library */
    const uint32_t WHEEL_MOTOR_1_CHANNEL_ID = 28u;
    const uint32_t WHEEL_MOTOR_2_CHANNEL_ID = 13u;
    const uint32_t VACUUM_MOTOR_CHANNEL_ID = 31u;

    return pwma_set_multiple_values(
        pwma,
        ((WHEEL_MOTOR_1_CHANNEL_ID << 0) |
        (WHEEL_MOTOR_2_CHANNEL_ID << 8) |
        (VACUUM_MOTOR_CHANNEL_ID << 16)),
        (uint16_t*)&duty_cycles);
}

static bool set_pwm_top(void)
{
    /* 0xFF top lets us have the conventional 0~255 PWM range */
    return pwma_write_top_value(pwma, PWMA_MAXIMUM_TOP);
}

static void enable_pwm_interrupts(void)
{
#ifndef WINDOWS_BUILD /* untestable macro & code */
    irq_register_handler(&tofl_irq, AVR32_PWMA_IRQ, PWMA_INTERRUPT_PRIORITY);
    pwma->ier = AVR32_PWMA_IER_TOFL_MASK;
#endif
}

static uint32_t percent_to_duty_cycle(uint32_t percent)
{
    return (uint32_t)((percent * PWMA_MAXIMUM_TOP + 50u) / 100u);
}
