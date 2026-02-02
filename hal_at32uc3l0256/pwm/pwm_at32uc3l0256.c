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
bool pwm_failed = false;

static volatile avr32_pwma_t *pwma = &AVR32_PWMA;
static uint16_t duty_cycle[] = {0u, 0u, 0u};

/* avoiding enum to prevent casting errors */
const uint32_t GCLK_FREQUENCY = 48000000;

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
void reset_pwm_flags(void);
void pwm_runtime_error(const char *fail_message, uint32_t fail_value);
void initialize_pwm_pins(void);
void initialize_pwm_clock_source(void);
bool configure_frequency_and_spread(void);
bool set_duty_cycles(void);

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
}

void deinit_pwm_at32uc3l0256(void)
{

}

void set_pwm_duty_cycle_percent_at32uc3l0256(struct pwm_handle *handle, uint32_t percent)
{

}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
void reset_pwm_flags(void)
{
    pwm_failed = false;
}

void pwm_runtime_error(const char *fail_message, uint32_t fail_value)
{
    RUNTIME_ERROR(0, fail_message, fail_value);
    pwm_failed = true;
}

void initialize_pwm_pins(void)
{
    enum
    {
        WHEEL_MOTOR_1_PIN = AVR32_PWMA_28_PIN,
        WHEEL_MOTOR_2_PIN = AVR32_PWMA_13_PIN,
        VACUUM_MOTOR_PIN = AVR32_PWMA_31_PIN,
        WHEEL_MOTOR_1_PIN_FUNCTION = AVR32_PWMA_28_FUNCTION,
        WHEEL_MOTOR_2_PIN_FUNCTION = AVR32_PWMA_13_FUNCTION,
        VACUUM_MOTOR_PIN_FUNCTION = AVR32_PWMA_31_FUNCTION
    };

    static const gpio_map_t PWMA_GPIO_MAP = {
        {WHEEL_MOTOR_1_PIN, WHEEL_MOTOR_1_PIN_FUNCTION},
        {WHEEL_MOTOR_2_PIN, WHEEL_MOTOR_2_PIN_FUNCTION},
        {VACUUM_MOTOR_PIN, VACUUM_MOTOR_PIN_FUNCTION},
    };
    gpio_enable_module(PWMA_GPIO_MAP, 
        sizeof(PWMA_GPIO_MAP) / sizeof(PWMA_GPIO_MAP[0]));
}

void initialize_pwm_clock_source(void)
{
    /* avoiding enums to prevent casting errors */
    const unsigned int GCLK_ID = AVR32_SCIF_GCLK_PWMA;

    enum
    {
        GCLK_SOURCE = AVR32_SCIF_GC_USES_CLK_PBA
    };

    uint32_t div = div_ceil((sysclk_get_pba_hz()), GCLK_FREQUENCY);
    genclk_enable_config(GCLK_ID, GCLK_SOURCE, div);
}

bool configure_frequency_and_spread(void)
{
    enum
    {
        OUTPUT_FREQUENCY = 190000,
        SPREAD = 0
    };

    return pwma_config_enable(pwma, OUTPUT_FREQUENCY, GCLK_FREQUENCY, SPREAD);
}

bool set_duty_cycles(void)
{
    enum
    {
        WHEEL_MOTOR_1_CHANNEL_ID = 28,
        WHEEL_MOTOR_2_CHANNEL_ID = 13,
        VACUUM_MOTOR_CHANNEL_ID = 31
    };

    return pwma_set_multiple_values(
        pwma,
        ((WHEEL_MOTOR_1_CHANNEL_ID << 0) |
        (WHEEL_MOTOR_2_CHANNEL_ID << 8) |
        (VACUUM_MOTOR_CHANNEL_ID << 16)),
        (uint16_t*)&duty_cycle);
}
