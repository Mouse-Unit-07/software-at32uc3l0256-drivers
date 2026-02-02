/*================================ FILE INFO =================================*/
/* Filename           : test_pwm_hal_config.cpp                               */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256_config library                    */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/

extern "C" {
#include <stdint.h>
#include "pwm_hal.h"
#include "pwm_hal_config.h"
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
TEST_GROUP(PwmHalConfigTest)
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
TEST(PwmHalConfigTest, PwmHandlerIsNotNull)
{
    struct pwm_hal_handler *pwm_handler = get_pwm_hal_handler();
    CHECK(pwm_handler != NULL);
}

TEST(PwmHalConfigTest, PwmHandlerElementsAreNotNull)
{
    struct pwm_hal_handler *pwm_handler = get_pwm_hal_handler();
    CHECK(pwm_handler->init_pwm != NULL);
    CHECK(pwm_handler->deinit_pwm != NULL);
    CHECK(pwm_handler->set_pwm_duty_cycle_percent != NULL);
}

TEST(PwmHalConfigTest, PwmHandleAccessorsAreNotNull)
{
    CHECK(get_wheel_motor_1_handle() != NULL);
    CHECK(get_wheel_motor_2_handle() != NULL);
    CHECK(get_vacuum_motor_handle() != NULL);
}
