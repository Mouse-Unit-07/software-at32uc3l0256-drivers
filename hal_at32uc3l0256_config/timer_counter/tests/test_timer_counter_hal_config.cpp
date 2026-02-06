/*================================ FILE INFO =================================*/
/* Filename           : test_timer_counter_hal_config.cpp                     */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256_config library                    */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
extern "C" {
#include <stdint.h>
#include "timer_counter_hal.h"
#include "timer_counter_hal_config.h"
}

#include <CppUTest/TestHarness.h>

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
/* none */

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(TimerCounterHalConfigTest)
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
TEST(TimerCounterHalConfigTest, TimerCounterHandlerIsNotNull)
{
    const struct tc_hal_handler *tc_handler = get_tc_hal_handler();
    CHECK(tc_handler != NULL);
}

TEST(TimerCounterHalConfigTest, TimerCounterHandlerElementsAreNotNull)
{
    const struct tc_hal_handler *tc_handler = get_tc_hal_handler();
    CHECK(tc_handler->init_timer_counter != NULL);
    CHECK(tc_handler->deinit_timer_counter != NULL);
    CHECK(tc_handler->get_timer_count != NULL);
    CHECK(tc_handler->restart_timer != NULL);
}
