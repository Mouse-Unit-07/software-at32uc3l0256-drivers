/*================================ FILE INFO =================================*/
/* Filename           : test_iic_hal_config.cpp                               */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256_config library                    */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
extern "C" {
#include <stdint.h>
#include "iic_hal.h"
#include "iic_hal_config.h"
}

#include <CppUTest/TestHarness.h>

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
/* none */

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(IicHalConfigTest)
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
TEST(IicHalConfigTest, IicHandlerIsNotNull)
{
    const struct iic_hal_handler *iic_handler = get_iic_hal_handler();
    CHECK(iic_handler != NULL);
}

TEST(IicHalConfigTest, IicHandlerElementsAreNotNull)
{
    const struct iic_hal_handler *iic_handler = get_iic_hal_handler();
    CHECK(iic_handler->init_iic != NULL);
    CHECK(iic_handler->deinit_iic != NULL);
    CHECK(iic_handler->enable_global_interrupts != NULL);
    CHECK(iic_handler->disable_global_interrupts != NULL);
}
