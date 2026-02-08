/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : gpio_at32uc3l0256.c                                   */
/*                                                                            */
/* AT32UC3L0256 implementation for GPIO HAL                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "asf.h"
#include "gpio_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
enum
{
    INPUT_COUNT = 4,
    OUTPUT_COUNT = 10
};

static const struct gpio_handle *const input_handles[INPUT_COUNT] = {
    &battery_comparator,
    &wheel_driver_cld,
    &wheel_encoder_motor_1_b_channel,
    &wheel_encoder_motor_2_b_channel
};

static const uint32_t pull_up_configs[INPUT_COUNT] = {
    0,
    0,
    GPIO_PULL_UP,
    GPIO_PULL_UP
};

static const struct gpio_handle *const output_handles[OUTPUT_COUNT] = {
    &regulators_enable,
    &led_d1,
    &led_d2,
    &led_d3,
    &led_d4,
    &wheel_driver_standby,
    &wheel_driver_motor_1_in1,
    &wheel_driver_motor_1_in2,
    &wheel_driver_motor_2_in1,
    &wheel_driver_motor_2_in2
};

/*----------------------------------------------------------------------------*/
/*                               Public Handles                               */
/*----------------------------------------------------------------------------*/
const struct gpio_handle regulators_enable = {
    .gpio_pin_address = AVR32_PIN_PB11
};

const struct gpio_handle battery_comparator = {
    .gpio_pin_address = AVR32_PIN_PB06
};

const struct gpio_handle led_d1 = {
    .gpio_pin_address = AVR32_PIN_PA22
};

const struct gpio_handle led_d2 = {
    .gpio_pin_address = AVR32_PIN_PB03
};

const struct gpio_handle led_d3 = {
    .gpio_pin_address = AVR32_PIN_PB02
};

const struct gpio_handle led_d4 = {
    .gpio_pin_address = AVR32_PIN_PB00
};

const struct gpio_handle wheel_driver_standby = {
    .gpio_pin_address = AVR32_PIN_PB04
};

const struct gpio_handle wheel_driver_cld = {
    .gpio_pin_address = AVR32_PIN_PB10
};

const struct gpio_handle wheel_driver_motor_1_in1 = {
    .gpio_pin_address = AVR32_PIN_PB01
};

const struct gpio_handle wheel_driver_motor_1_in2 = {
    .gpio_pin_address = AVR32_PIN_PA07
};

const struct gpio_handle wheel_driver_motor_2_in1 = {
    .gpio_pin_address = AVR32_PIN_PA21
};

const struct gpio_handle wheel_driver_motor_2_in2 = {
    .gpio_pin_address = AVR32_PIN_PA20
};

const struct gpio_handle wheel_encoder_motor_1_b_channel = {
    .gpio_pin_address = AVR32_PIN_PA04
};

const struct gpio_handle wheel_encoder_motor_2_b_channel = {
    .gpio_pin_address = AVR32_PIN_PA11
};

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_gpio_at32uc3l0256(void)
{
    for (uint32_t i = 0u; i < INPUT_COUNT; i++) {
        uint32_t address = input_handles[i]->gpio_pin_address;
        uint32_t pull_up_config = pull_up_configs[i];
        gpio_configure_pin(address, GPIO_DIR_INPUT | pull_up_config);
    }

    for (uint32_t i = 0u; i < OUTPUT_COUNT; i++) {
        uint32_t address = output_handles[i]->gpio_pin_address;
        gpio_configure_pin(address, GPIO_DIR_OUTPUT | GPIO_INIT_LOW);
    }
}

void deinit_gpio_at32uc3l0256(void)
{
    /* nothing to clear/reset */
}

bool read_gpio_pin_at32uc3l0256(const struct gpio_handle *handle)
{
    return (bool)gpio_get_pin_value(handle->gpio_pin_address);
}

void write_gpio_pin_at32uc3l0256(const struct gpio_handle *handle, bool value)
{
    if(value) {
        gpio_set_gpio_pin(handle->gpio_pin_address);
    } else {
        gpio_clr_gpio_pin(handle->gpio_pin_address);
    }
}

void toggle_gpio_pin_at32uc3l0256(const struct gpio_handle *handle)
{
    gpio_tgl_gpio_pin(handle->gpio_pin_address);
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
