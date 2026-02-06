/*================================ FILE INFO =================================*/
/* Filename           : test_usart_hal_config.cpp                             */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256_config library                    */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/

extern "C" {
#include <stdint.h>
#include "usart_hal.h"
#include "usart_hal_config.h"
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
TEST_GROUP(UsartHalConfigTest)
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
TEST(UsartHalConfigTest, TimerCounterHandlerIsNotNull)
{
    const struct usart_hal_handler *usart_handler = get_usart_hal_handler();
    CHECK(usart_handler != NULL);
}

TEST(UsartHalConfigTest, TimerCounterHandlerElementsAreNotNull)
{
    const struct usart_hal_handler *usart_handler = get_usart_hal_handler();
    CHECK(usart_handler->init_usart != NULL);
    CHECK(usart_handler->deinit_usart != NULL);
}
