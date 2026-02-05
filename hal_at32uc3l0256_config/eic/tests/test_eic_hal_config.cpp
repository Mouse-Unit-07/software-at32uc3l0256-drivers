/*================================ FILE INFO =================================*/
/* Filename           : test_eic_hal_config.cpp                               */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256_config library                    */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/

extern "C" {
#include <stdint.h>
#include "eic_hal.h"
#include "eic_hal_config.h"
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
TEST_GROUP(EicHalConfigTest)
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
TEST(EicHalConfigTest, EicHandlerIsNotNull)
{
    const struct eic_hal_handler *eic_handler = get_eic_hal_handler();
    CHECK(eic_handler != NULL);
}

TEST(EicHalConfigTest, EicHandlerElementsAreNotNull)
{
    const struct eic_hal_handler *eic_handler = get_eic_hal_handler();
    CHECK(eic_handler->init_eic != NULL);
    CHECK(eic_handler->deinit_eic != NULL);
    CHECK(eic_handler->set_external_callback != NULL);
}
