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
#include "pwm_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
static volatile avr32_pwma_t *pwma = &AVR32_PWMA;

enum
{
    WHEEL_MOTOR_1_PIN = AVR32_PWMA_28_PIN,
    WHEEL_MOTOR_2_PIN = AVR32_PWMA_13_PIN,
    VACUUM_MOTOR_PIN = AVR32_PWMA_31_PIN,
    WHEEL_MOTOR_1_PIN_FUNCTION = AVR32_PWMA_28_FUNCTION,
    WHEEL_MOTOR_2_PIN_FUNCTION = AVR32_PWMA_13_FUNCTION,
    VACUUM_MOTOR_PIN_FUNCTION = AVR32_PWMA_31_FUNCTION
};

/* avoiding enums to prevent casting errors */
const unsigned int GCLK_ID = AVR32_SCIF_GCLK_PWMA;
const uint32_t GCLK_FREQUENCY = 48000000;

enum
{
    GCLK_SOURCE = AVR32_SCIF_GC_USES_CLK_PBA
};

enum
{
    OUTPUT_FREQUENCY = 190000,
    SPREAD = 0
};

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
void call_asf_gpio_enable_module(void);
void call_asf_genclk_enable_config(void);
bool call_asf_pwma_config_enable(void);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_pwm_at32uc3l0256(void)
{
    call_asf_gpio_enable_module();
    call_asf_genclk_enable_config();

    call_asf_pwma_config_enable();
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
void call_asf_gpio_enable_module(void)
{
    static const gpio_map_t PWMA_GPIO_MAP = {
        {WHEEL_MOTOR_1_PIN, WHEEL_MOTOR_1_PIN_FUNCTION},
        {WHEEL_MOTOR_2_PIN, WHEEL_MOTOR_2_PIN_FUNCTION},
        {VACUUM_MOTOR_PIN, VACUUM_MOTOR_PIN_FUNCTION},
    };
    gpio_enable_module(PWMA_GPIO_MAP, 
        sizeof(PWMA_GPIO_MAP) / sizeof(PWMA_GPIO_MAP[0]));
}

void call_asf_genclk_enable_config(void)
{
    uint32_t div = div_ceil((sysclk_get_pba_hz()), GCLK_FREQUENCY);
    genclk_enable_config(GCLK_ID, GCLK_SOURCE, div);
}

bool call_asf_pwma_config_enable(void)
{
    return pwma_config_enable(pwma, OUTPUT_FREQUENCY, GCLK_FREQUENCY, SPREAD);
}