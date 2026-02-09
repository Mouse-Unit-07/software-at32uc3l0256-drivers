/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : gpio_at32uc3l0256.h                                   */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for GPIO HAL                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef GPIO_AT32UC3L0256_H_
#define GPIO_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
struct gpio_handle {
    uint32_t gpio_pin_address;
};

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
extern const struct gpio_handle encoder_1_channel_b;
extern const struct gpio_handle encoder_2_channel_b;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_gpio_at32uc3l0256(void);
void deinit_gpio_at32uc3l0256(void);
bool read_gpio_pin_at32uc3l0256(const struct gpio_handle *handle);
void write_gpio_pin_at32uc3l0256(const struct gpio_handle *handle, bool value);
void toggle_gpio_pin_at32uc3l0256(const struct gpio_handle *handle);

#endif /* GPIO_AT32UC3L0256_H_ */
