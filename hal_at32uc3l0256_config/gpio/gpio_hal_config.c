/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : gpio_hal_config.c                                     */
/*                                                                            */
/* AT32UC3L0256 implementation for GPIO HAL handler                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "gpio_hal.h"
#include "asf.h"
#include "gpio_at32uc3l0256.h"
#include "gpio_hal_config.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
const struct gpio_hal_handler gpio_handler = 
{
    .init_gpio = init_gpio_at32uc3l0256,
    .deinit_gpio = deinit_gpio_at32uc3l0256,
    .read_gpio_pin = read_gpio_pin_at32uc3l0256,
    .write_gpio_pin = write_gpio_pin_at32uc3l0256,
    .toggle_gpio_pin = toggle_gpio_pin_at32uc3l0256
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
const struct gpio_hal_handler *get_gpio_hal_handler(void)
{
    return &gpio_handler;
}

const struct gpio_handle *get_regulators_enable_handle(void)
{
    return &regulators_enable;
}

const struct gpio_handle *get_battery_comparator_handle(void)
{
    return &battery_comparator;
}

const struct gpio_handle *get_led_d1_handle(void)
{
    return &led_d1;
}

const struct gpio_handle *get_led_d2_handle(void)
{
    return &led_d2;
}

const struct gpio_handle *get_led_d3_handle(void)
{
    return &led_d3;
}

const struct gpio_handle *get_led_d4_handle(void)
{
    return &led_d4;
}

const struct gpio_handle *get_wheel_driver_standby_handle(void)
{
    return &wheel_driver_standby;
}

const struct gpio_handle *get_wheel_driver_cld_handle(void)
{
    return &wheel_driver_cld;
}

const struct gpio_handle *get_wheel_driver_motor_1_in1_handle(void)
{
    return &wheel_driver_motor_1_in1;
}

const struct gpio_handle *get_wheel_driver_motor_1_in2_handle(void)
{
    return &wheel_driver_motor_1_in2;
}

const struct gpio_handle *get_wheel_driver_motor_2_in1_handle(void)
{
    return &wheel_driver_motor_2_in1;
}

const struct gpio_handle *get_wheel_driver_motor_2_in2_handle(void)
{
    return &wheel_driver_motor_2_in2;
}

const struct gpio_handle *get_wheel_encoder_motor_1_b_channel_handle(void)
{
    return &wheel_encoder_motor_1_b_channel;
}

const struct gpio_handle *get_wheel_encoder_motor_2_b_channel_handle(void)
{
    return &wheel_encoder_motor_2_b_channel;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
