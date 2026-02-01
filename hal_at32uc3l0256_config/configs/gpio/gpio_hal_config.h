/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : gpio_hal_config.h                                     */
/*                                                                            */
/* Interface for AT32UC3L0256 Implementation for GPIO HAL handler             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef GPIO_HAL_CONFIG_H_
#define GPIO_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
extern const struct gpio_handle regulators_enable;
extern const struct gpio_handle battery_comparator;
extern const struct gpio_handle led_d1;
extern const struct gpio_handle led_d2;
extern const struct gpio_handle led_d3;
extern const struct gpio_handle led_d4;
extern const struct gpio_handle wheel_driver_standby;
extern const struct gpio_handle wheel_driver_cld;
extern const struct gpio_handle wheel_driver_motor_1_in1;
extern const struct gpio_handle wheel_driver_motor_1_in2;
extern const struct gpio_handle wheel_driver_motor_2_in1;
extern const struct gpio_handle wheel_driver_motor_2_in2;
extern const struct gpio_handle wheel_encoder_motor_1_b_channel;
extern const struct gpio_handle wheel_encoder_motor_2_b_channel;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
struct gpio_hal_handler *get_gpio_hal_handler(void);

#endif /* GPIO_HAL_CONFIG */
