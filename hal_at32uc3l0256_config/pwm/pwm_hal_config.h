/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : pwm_hal_config.h                                      */
/*                                                                            */
/* Interface for AT32UC3L0256 Implementation for pulse width modulation HAL   */
/* handler                                                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef PWM_HAL_CONFIG_H_
#define PWM_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
struct pwm_hal_handler *get_pwm_hal_handler(void);
const struct pwm_handle *get_wheel_motor_1_handle(void);
const struct pwm_handle *get_wheel_motor_2_handle(void);
const struct pwm_handle *get_vacuum_motor_handle(void);

#endif /* PWM_HAL_CONFIG */
