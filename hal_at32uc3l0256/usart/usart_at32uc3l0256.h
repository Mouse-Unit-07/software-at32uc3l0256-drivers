/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : usart_at32uc3l0256.h                                  */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for universal synchronous/       */
/* asynchronous reciver/transmitter HAL                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef USART_AT32UC3L0256_H_
#define USART_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_usart_at32uc3l0256(void);
void deinit_usart_at32uc3l0256(void);
bool is_rx_buffer_empty_at32uc3l0256(void);
bool is_rx_buffer_full_at32uc3l0256(void);
char pop_rx_buffer_at32uc3l0256(void);
void clear_rx_buffer_at32uc3l0256(void);

/* ISR exposed for testing */
void rx_isr(void);

#endif /* USART_AT32UC3L0256_H_ */
