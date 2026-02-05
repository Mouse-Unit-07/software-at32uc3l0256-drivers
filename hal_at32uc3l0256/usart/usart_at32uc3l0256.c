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
#include "usart_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
#define USART_SERIAL_BASE_ADDRESS (&AVR32_USART2)
const unsigned long BAUDRATE = 115200u;
const unsigned char CHAR_LENGTH = 8u;
const unsigned char PARITY = AVR32_USART_MR_PAR_NONE;
const unsigned short STOP_BIT = AVR32_USART_MR_NBSTOP_1;

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_usart_at32uc3l0256(void)
{
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
