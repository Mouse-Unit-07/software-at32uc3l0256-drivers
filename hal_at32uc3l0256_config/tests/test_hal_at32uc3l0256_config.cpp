/*================================ FILE INFO =================================*/
/* Filename           : test_hal_at32uc3l0256_config.cpp                      */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256_config library                    */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/

extern "C" {
#include <stdint.h>
#include "clock_hal.h"
#include "clock_hal_config.h"
#include "gpio_hal.h"
#include "gpio_hal_config.h"
#include "timer_counter_hal.h"
#include "timer_counter_hal_config.h"
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
TEST_GROUP(HalConfigTest)
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
TEST(HalConfigTest, ClockHandlerIsNotNull)
{
    struct clock_hal_handler *clock_handler = get_clock_hal_handler();
    CHECK(clock_handler != NULL);
}

TEST(HalConfigTest, ClockHandlerElementsAreNotNull)
{
    struct clock_hal_handler *clock_handler = get_clock_hal_handler();
    CHECK(clock_handler->init_clock != NULL);
    CHECK(clock_handler->deinit_clock != NULL);
    CHECK(clock_handler->delay_ms != NULL);
    CHECK(clock_handler->delay_us != NULL);
}

TEST(HalConfigTest, GpioHandlerIsNotNull)
{
    struct gpio_hal_handler *gpio_handler = get_gpio_hal_handler();
    CHECK(gpio_handler != NULL);
}

TEST(HalConfigTest, GpioHandlerElementsAreNotNull)
{
    struct gpio_hal_handler *gpio_handler = get_gpio_hal_handler();
    CHECK(gpio_handler->init_gpio != NULL);
    CHECK(gpio_handler->deinit_gpio != NULL);
    CHECK(gpio_handler->read_gpio_pin != NULL);
    CHECK(gpio_handler->write_gpio_pin != NULL);
    CHECK(gpio_handler->toggle_gpio_pin != NULL);
}

TEST(HalConfigTest, TimerCounterHandlerIsNotNull)
{
    struct tc_hal_handler *tc_handler = get_tc_hal_handler();
    CHECK(tc_handler != NULL);
}

TEST(HalConfigTest, TimerCounterHandlerElementsAreNotNull)
{
    struct tc_hal_handler *tc_handler = get_tc_hal_handler();
    CHECK(tc_handler->init_timer_counter != NULL);
    CHECK(tc_handler->deinit_timer_counter != NULL);
    CHECK(tc_handler->get_timer_count != NULL);
    CHECK(tc_handler->restart_timer != NULL);
}
