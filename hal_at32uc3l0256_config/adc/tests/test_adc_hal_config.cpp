/*================================ FILE INFO =================================*/
/* Filename           : test_adc_hal_config.cpp                             */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256_config library                    */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
extern "C" {
#include <stdint.h>
#include "adc_hal.h"
#include "adc_hal_config.h"
}

#include <CppUTest/TestHarness.h>

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
/* none */

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(AdcHalConfigTest)
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
TEST(AdcHalConfigTest, AdcHandlerIsNotNull)
{
    const struct adc_hal_handler *adc_handler = get_adc_hal_handler();
    CHECK(adc_handler != NULL);
}

TEST(AdcHalConfigTest, AdcHandlerElementsAreNotNull)
{
    const struct adc_hal_handler *adc_handler = get_adc_hal_handler();
    CHECK(adc_handler->init_adc != NULL);
    CHECK(adc_handler->deinit_adc != NULL);
    CHECK(adc_handler->read_adc_channel != NULL);
}

TEST(AdcHalConfigTest, AdcHandlesAreNotNull)
{
    CHECK(get_ir_sensor_1_handle() != NULL);
    CHECK(get_ir_sensor_2_handle() != NULL);
    CHECK(get_ir_sensor_3_handle() != NULL);
    CHECK(get_ir_sensor_4_handle() != NULL);
}
