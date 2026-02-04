/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : pwm_hal_config.c                                      */
/*                                                                            */
/* AT32UC3L0256 implementation for pulse width modulation HAL handler         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "pwm_hal.h"
#include "asf.h"
#include "pwm_at32uc3l0256.h"
#include "pwm_hal_config.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
const struct pwm_hal_handler pwm_handler = 
{
    .init_pwm = init_pwm_at32uc3l0256,
    .deinit_pwm = deinit_pwm_at32uc3l0256,
    .set_pwm_duty_cycle_percent = set_pwm_duty_cycle_percent_at32uc3l0256,
};

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
const struct pwm_hal_handler *get_pwm_hal_handler(void)
{
    return &pwm_handler;
}

const struct pwm_handle *get_wheel_motor_1_handle(void)
{
    return &wheel_motor_1;
}

const struct pwm_handle *get_wheel_motor_2_handle(void)
{
    return &wheel_motor_2;
}

const struct pwm_handle *get_vacuum_motor_handle(void)
{
    return &vacuum_motor;
}


/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
