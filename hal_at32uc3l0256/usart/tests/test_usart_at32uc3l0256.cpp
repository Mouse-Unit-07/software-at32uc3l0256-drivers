/*================================ FILE INFO =================================*/
/* Filename           : test_usart_at32uc3l0256.cpp                           */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256 library                           */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C"
{

#include <stdint.h>
#include "asf.h"
#include "usart_at32uc3l0256.h"

}

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
void init_usart_without_cpputest_checks(void)
{
    mock().ignoreOtherCalls();
    init_usart_at32uc3l0256();
    mock().clear();
}

void overflow_rx_buffer_with_cpputest_checks(void)
{
    int c{'A'};

    for (int i{0}; i < 128; ++i) {
        mock().expectOneCall("usart_read_char")
                .withOutputParameterReturning("c", &c, sizeof(c))
                .andReturnValue(USART_SUCCESS);

        rx_isr();
    }
}

void fail_rx_with_cpputest_checks(void)
{
    int c{'\0'};
    mock().expectOneCall("usart_read_char")
            .withOutputParameterReturning("c", &c, sizeof(c))
            .andReturnValue(USART_FAILURE);
    mock().expectOneCall("RUNTIME_WARNING")
            .withUnsignedIntParameter("timestamp", 0)
            .withStringParameter("fail_message", "usart isr: usart_read_char() failed")
            .withUnsignedIntParameter("fail_value", USART_FAILURE);

    rx_isr();
}

/*============================================================================*/
/*                            Mock Implementations                            */
/*============================================================================*/
extern "C"
{

/* ---------------------------------------------------------------------------*/
/* Runtime Diagnostics */
void RUNTIME_ERROR(uint32_t timestamp, const char *fail_message, uint32_t fail_value)
{
    CHECK(fail_message != NULL);
    mock().actualCall("RUNTIME_ERROR")
            .withUnsignedIntParameter("timestamp", timestamp)
            .withStringParameter("fail_message", fail_message)
            .withUnsignedIntParameter("fail_value", fail_value);
}

void RUNTIME_WARNING(uint32_t timestamp, const char *fail_message, uint32_t fail_value)
{
    CHECK(fail_message != NULL);
    mock().actualCall("RUNTIME_WARNING")
            .withUnsignedIntParameter("timestamp", timestamp)
            .withStringParameter("fail_message", fail_message)
            .withUnsignedIntParameter("fail_value", fail_value);
}

/* ---------------------------------------------------------------------------*/
/* USART */
uint32_t gpio_enable_module(const gpio_map_t gpiomap, uint32_t size)
{
    return mock().actualCall("gpio_enable_module").returnIntValue();
}

int usart_read_char(volatile avr32_usart_t *usart, int *c)
{
    mock().actualCall("usart_read_char").withOutputParameter("c", c);

    return mock().intReturnValue();
}

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(HalUsartTests)
{
    void setup() override
    {
        mock().clear();
    }

    void teardown() override
    {
        mock().checkExpectations();
        mock().clear();
        deinit_usart_at32uc3l0256();
    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(HalUsartTests, InitUsartCallsFunctions)
{
    mock().expectOneCall("gpio_enable_module").andReturnValue(GPIO_SUCCESS);
    init_usart_at32uc3l0256();
}

TEST(HalUsartTests, InitUsartGpioFailureCallsRuntimeError)
{
    mock().expectOneCall("gpio_enable_module").andReturnValue(GPIO_INVALID_ARGUMENT);
    mock().expectOneCall("RUNTIME_ERROR")
            .withUnsignedIntParameter("timestamp", 0)
            .withStringParameter("fail_message", "usart init: init_usart_at32uc3l0256() failed")
            .withUnsignedIntParameter("fail_value", GPIO_INVALID_ARGUMENT);
    init_usart_at32uc3l0256();
}

TEST(HalUsartTests, DeinitUsart)
{
    deinit_usart_at32uc3l0256();
}

TEST(HalUsartTests, RxBufferStartsEmpty)
{
    CHECK(is_rx_buffer_empty_at32uc3l0256());
}

TEST(HalUsartTests, RxIsrStoresCharacter)
{
    int c{'A'};

    mock().expectOneCall("usart_read_char")
            .withOutputParameterReturning("c", &c, sizeof(c))
            .andReturnValue(USART_SUCCESS);

    rx_isr();

    CHECK_FALSE(is_rx_buffer_empty_at32uc3l0256());
}

TEST(HalUsartTests, PopRxBufferReturnsStoredCharacter)
{
    int c{'B'};

    mock().expectOneCall("usart_read_char")
            .withOutputParameterReturning("c", &c, sizeof(c))
            .andReturnValue(USART_SUCCESS);

    rx_isr();

    CHECK_EQUAL('B', pop_rx_buffer_at32uc3l0256());
}

TEST(HalUsartTests, PopRxBufferMakesBufferEmpty)
{
    int c{'C'};

    mock().expectOneCall("usart_read_char")
            .withOutputParameterReturning("c", &c, sizeof(c))
            .andReturnValue(USART_SUCCESS);

    rx_isr();

    pop_rx_buffer_at32uc3l0256();

    CHECK(is_rx_buffer_empty_at32uc3l0256());
}

TEST(HalUsartTests, EmptyPopReturnsNullCharacter)
{
    CHECK_EQUAL('\0', pop_rx_buffer_at32uc3l0256());
}

TEST(HalUsartTests, RxFailureCallsRuntimeWarning)
{
    fail_rx_with_cpputest_checks();
}

TEST(HalUsartTests, RxFailureDoesNotPushCharacter)
{
    fail_rx_with_cpputest_checks();

    CHECK(is_rx_buffer_empty_at32uc3l0256());
}

TEST(HalUsartTests, IsRxBufferFullInitiallyFalse)
{
    CHECK_FALSE(is_rx_buffer_full_at32uc3l0256());
}

TEST(HalUsartTests, IsRxBufferFullReturnsTrueWhenFullAndOverflow)
{
    int c{'A'};

    for (int i{0}; i < 127; ++i) {
        mock().expectOneCall("usart_read_char")
                .withOutputParameterReturning("c", &c, sizeof(c))
                .andReturnValue(USART_SUCCESS);

        rx_isr();
    }

    CHECK(is_rx_buffer_full_at32uc3l0256());

    mock().expectOneCall("usart_read_char")
            .withOutputParameterReturning("c", &c, sizeof(c))
            .andReturnValue(USART_SUCCESS);

    rx_isr();

    CHECK(is_rx_buffer_full_at32uc3l0256());
}

TEST(HalUsartTests, ClearRxBufferEmptiesBuffer)
{
    int c{'B'};

    mock().expectOneCall("usart_read_char")
            .withOutputParameterReturning("c", &c, sizeof(c))
            .andReturnValue(USART_SUCCESS);

    rx_isr();

    CHECK_FALSE(is_rx_buffer_empty_at32uc3l0256());

    clear_rx_buffer_at32uc3l0256();

    CHECK_TRUE(is_rx_buffer_empty_at32uc3l0256());
}

TEST(HalUsartTests, InitResetsDriverState)
{
    overflow_rx_buffer_with_cpputest_checks();
    fail_rx_with_cpputest_checks();

    init_usart_without_cpputest_checks();

    CHECK(is_rx_buffer_empty_at32uc3l0256());
    CHECK_FALSE(is_rx_buffer_full_at32uc3l0256());
}

TEST(HalUsartTests, DeinitResetsDriverState)
{
    overflow_rx_buffer_with_cpputest_checks();
    fail_rx_with_cpputest_checks();

    deinit_usart_at32uc3l0256();

    CHECK(is_rx_buffer_empty_at32uc3l0256());
    CHECK_FALSE(is_rx_buffer_full_at32uc3l0256());
}
