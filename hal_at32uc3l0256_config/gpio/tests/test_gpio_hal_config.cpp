/*================================ FILE INFO =================================*/
/* Filename           : test_gpio_hal_config.cpp                              */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256_config library                    */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/

extern "C" {
#include <stdint.h>
#include "gpio_hal.h"
#include "gpio_hal_config.h"
}

#include <CppUTest/TestHarness.h>

/*============================================================================*/
/*                             Private Definitions                            */
/*============================================================================*/
namespace
{

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(GpioHalConfigTest)
{
    void setup() override
    {

    }

    void teardown() override
    {

    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(GpioHalConfigTest, GpioHandlerIsNotNull)
{
    const struct gpio_hal_handler *gpio_handler = get_gpio_hal_handler();
    CHECK(gpio_handler != NULL);
}

TEST(GpioHalConfigTest, GpioHandlerElementsAreNotNull)
{
    const struct gpio_hal_handler *gpio_handler = get_gpio_hal_handler();
    CHECK(gpio_handler->init_gpio != NULL);
    CHECK(gpio_handler->deinit_gpio != NULL);
    CHECK(gpio_handler->read_gpio_pin != NULL);
    CHECK(gpio_handler->write_gpio_pin != NULL);
    CHECK(gpio_handler->toggle_gpio_pin != NULL);
}

TEST(GpioHalConfigTest, dinosaur)
{
    CHECK(get_regulators_enable_handle() != NULL);
    CHECK(get_battery_comparator_handle() != NULL);
    CHECK(get_led_d1_handle() != NULL);
    CHECK(get_led_d2_handle() != NULL);
    CHECK(get_led_d3_handle() != NULL);
    CHECK(get_led_d4_handle() != NULL);
    CHECK(get_wheel_driver_standby_handle() != NULL);
    CHECK(get_wheel_driver_cld_handle() != NULL);
    CHECK(get_wheel_driver_motor_1_in1_handle() != NULL);
    CHECK(get_wheel_driver_motor_1_in2_handle() != NULL);
    CHECK(get_wheel_driver_motor_2_in1_handle() != NULL);
    CHECK(get_wheel_driver_motor_2_in2_handle() != NULL);
    CHECK(get_wheel_encoder_motor_1_b_channel_handle() != NULL);
    CHECK(get_wheel_encoder_motor_2_b_channel_handle() != NULL);
}
