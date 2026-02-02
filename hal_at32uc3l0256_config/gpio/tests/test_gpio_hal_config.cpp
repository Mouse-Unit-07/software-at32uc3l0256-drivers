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
    struct gpio_hal_handler *gpio_handler = get_gpio_hal_handler();
    CHECK(gpio_handler != NULL);
}

TEST(GpioHalConfigTest, GpioHandlerElementsAreNotNull)
{
    struct gpio_hal_handler *gpio_handler = get_gpio_hal_handler();
    CHECK(gpio_handler->init_gpio != NULL);
    CHECK(gpio_handler->deinit_gpio != NULL);
    CHECK(gpio_handler->read_gpio_pin != NULL);
    CHECK(gpio_handler->write_gpio_pin != NULL);
    CHECK(gpio_handler->toggle_gpio_pin != NULL);
}
