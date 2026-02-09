/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : gpio_hal_config.h                                     */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for GPIO HAL handler             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef GPIO_HAL_CONFIG_H_
#define GPIO_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
const struct gpio_hal_handler *get_gpio_hal_handler(void);
const struct gpio_handle *get_regulators_enable_handle(void);
const struct gpio_handle *get_battery_comparator_handle(void);
const struct gpio_handle *get_led_d1_handle(void);
const struct gpio_handle *get_led_d2_handle(void);
const struct gpio_handle *get_led_d3_handle(void);
const struct gpio_handle *get_led_d4_handle(void);
const struct gpio_handle *get_wheel_driver_standby_handle(void);
const struct gpio_handle *get_wheel_driver_cld_handle(void);
const struct gpio_handle *get_wheel_driver_motor_1_in1_handle(void);
const struct gpio_handle *get_wheel_driver_motor_1_in2_handle(void);
const struct gpio_handle *get_wheel_driver_motor_2_in1_handle(void);
const struct gpio_handle *get_wheel_driver_motor_2_in2_handle(void);
const struct gpio_handle *get_encoder_1_channel_b_handle(void);
const struct gpio_handle *get_encoder_2_channel_b_handle(void);

#endif /* GPIO_HAL_CONFIG_H_ */
