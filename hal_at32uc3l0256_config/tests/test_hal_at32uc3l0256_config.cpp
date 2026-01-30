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
TEST(HalConfigTest, HandlerIsNotNull)
{
    struct clock_hal_handler *clock_handler = get_clock_hal_handler();
    CHECK(clock_handler != NULL);
}

TEST(HalConfigTest, HandlerElementsAreNotNull)
{
    struct clock_hal_handler *clock_handler = get_clock_hal_handler();
    CHECK(clock_handler->init_clock != NULL);
    CHECK(clock_handler->deinit_clock != NULL);
    CHECK(clock_handler->delay_ms != NULL);
    CHECK(clock_handler->delay_us != NULL);
}