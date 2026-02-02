/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : pwm_mock.c                                            */
/*                                                                            */
/* Empty implementations of functions to be mocked w/ CppUTest.               */
/* Needed for the config translation unit- compilation errors are thrown      */
/* when function pointers point to functions that are defined w/ calls to     */
/* functions that aren't defined.                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "pwm_mock.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
uint32_t gpio_enable_module(const gpio_map_t gpiomap, uint32_t size)
{
    return 1;
}

bool pwma_config_enable(volatile avr32_pwma_t *pwma, uint32_t pwma_freq_hz,
                        uint32_t gclk_freq_hz, uint16_t spread)
{
    return true;
}

bool pwma_set_multiple_values(volatile avr32_pwma_t *pwma, uint32_t channel_mask,
                        uint16_t *channel_duty_cycles)
{
    return true;
}

bool pwma_write_top_value(volatile avr32_pwma_t *pwma, uint16_t top_value)
{
    return true;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
