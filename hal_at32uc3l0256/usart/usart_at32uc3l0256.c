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
#include <stdint.h>
#include "asf.h"
#include "runtime_diagnostics.h"
#include "usart_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

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
const unsigned long BAUDRATE = 115200u;
const unsigned char CHAR_LENGTH = 8u;
const unsigned char PARITY = AVR32_USART_MR_PAR_NONE;
const unsigned short STOP_BIT = AVR32_USART_MR_NBSTOP_1;

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_usart_at32uc3l0256(void)
{
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
}

void deinit_usart_at32uc3l0256(void)
{
    /* nothing to reset/clear */
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
