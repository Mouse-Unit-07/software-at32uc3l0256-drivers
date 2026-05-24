/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : usart_at32uc3l0256.c                                  */
/*                                                                            */
/* AT32UC3L0256 implementation for universal synchronous/asynchronous         */
/* receiver/transmitter HAL                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "asf.h"
#include "runtime_diagnostics.h"
#include "usart_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
static void reset_usart_state(void);

static uint32_t increment_rx_cb_index(uint32_t index);
static bool is_rx_cb_empty(void);
static bool is_rx_cb_full(void);
static void push_rx_cb(char c);
static char pop_rx_cb(void);

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
/* can't be enum/variable- resolves to a macro w/ a custom type */
#define USART_SERIAL_BASE_ADDRESS (&AVR32_USART1)

/* pin selection related globals */
/* need unsigned constants for struct/array initializers (no enums or variables) */
#define USART_RX_PIN (AVR32_USART1_RXD_0_0_PIN)
#define USART_TX_PIN (AVR32_USART1_TXD_0_0_PIN)
#define USART_RX_FUNCTION (AVR32_USART1_RXD_0_0_FUNCTION)
#define USART_TX_FUNCTION (AVR32_USART1_TXD_0_0_FUNCTION)

/* avoiding enum for implicit casting */
static const unsigned long BAUDRATE = 115200u;
static const unsigned char CHAR_LENGTH = 8u;
static const unsigned char PARITY = AVR32_USART_MR_PAR_NONE;
static const unsigned short STOP_BIT = AVR32_USART_MR_NBSTOP_1;

enum {RX_CIRCULAR_BUFFER_SIZE = 128};

struct circular_buffer {
    volatile uint32_t head;
    volatile uint32_t tail;

    uint8_t buffer[RX_CIRCULAR_BUFFER_SIZE];
};

static struct circular_buffer rx_circular_buffer = {0};

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
#ifndef WINDOWS_BUILD /* need ISR to build for testing */
__attribute__((__interrupt__))
#endif
void rx_isr(void)
{
    int c;
    int return_value = usart_read_char(USART_SERIAL_BASE_ADDRESS, &c);
    if (return_value != USART_SUCCESS) {
        RUNTIME_WARNING(0, "usart isr: usart_read_char() failed", return_value);
    } else {
        push_rx_cb((char)c);
    }
}

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_usart_at32uc3l0256(void)
{
    reset_usart_state();

    uint32_t uint_return_value = GPIO_INVALID_ARGUMENT;
    gpio_map_t USART_GPIO_MAP =
    {
        {USART_RX_PIN, USART_RX_FUNCTION},
        {USART_TX_PIN, USART_TX_FUNCTION}
    };
    uint_return_value = gpio_enable_module(USART_GPIO_MAP, sizeof(USART_GPIO_MAP) / sizeof (USART_GPIO_MAP[0]));
    
    if (uint_return_value != GPIO_SUCCESS) {
        RUNTIME_ERROR(0, "usart init: init_usart_at32uc3l0256() failed", GPIO_INVALID_ARGUMENT);
        return;
    }

    const usart_serial_options_t usart_serial_options = {
        .baudrate     = BAUDRATE,
        .charlength   = CHAR_LENGTH,
        .paritytype   = PARITY,
        .stopbits     = STOP_BIT
    };

    stdio_serial_init(USART_SERIAL_BASE_ADDRESS, &usart_serial_options);

#ifndef WINDOWS_BUILD /* can't test- AVR32 defined type parameter */
    INTC_register_interrupt(&rx_isr, AVR32_USART1_IRQ, AVR32_INTC_INT0);
#endif
#ifndef WINDOWS_BUILD /* can't test- address is only valid on AVR32 */
    USART_SERIAL_BASE_ADDRESS->ier = AVR32_USART_IER_RXRDY_MASK;
#endif
}

void deinit_usart_at32uc3l0256(void)
{
    reset_usart_state();
}

bool is_rx_buffer_empty_at32uc3l0256(void)
{
    return is_rx_cb_empty();
}

bool is_rx_buffer_full_at32uc3l0256(void)
{
    return is_rx_cb_full();
}

char pop_rx_buffer_at32uc3l0256(void)
{
    return pop_rx_cb();
}

void clear_rx_buffer_at32uc3l0256(void)
{
    rx_circular_buffer.head = 0u;
    rx_circular_buffer.tail = 0u;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
static void reset_usart_state(void)
{
    memset(&rx_circular_buffer, 0, sizeof(rx_circular_buffer));
}

static uint32_t increment_rx_cb_index(uint32_t index)
{
    return (index + 1u) % RX_CIRCULAR_BUFFER_SIZE;
}

static bool is_rx_cb_empty(void)
{
    return (rx_circular_buffer.head == rx_circular_buffer.tail);
}

static bool is_rx_cb_full(void)
{
    return (increment_rx_cb_index(rx_circular_buffer.head) == rx_circular_buffer.tail);
}

static void push_rx_cb(char c)
{
    if (is_rx_cb_full()) {
        return;
    }

    rx_circular_buffer.buffer[rx_circular_buffer.head] = c;
    rx_circular_buffer.head = increment_rx_cb_index(rx_circular_buffer.head);
}

static char pop_rx_cb(void)
{
    char c = '\0';
    if (is_rx_cb_empty()) {
        return c;
    }

    c = rx_circular_buffer.buffer[rx_circular_buffer.tail];
    rx_circular_buffer.tail = increment_rx_cb_index(rx_circular_buffer.tail);
    return c;
}
