/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : usart_hal_config.h                                    */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for universal synchronous/       */
/* asynchronous receiver/transmitter HAL handler                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef USART_HAL_CONFIG_H_
#define USART_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
const struct usart_hal_handler *get_usart_hal_handler(void);

#endif /* USART_HAL_CONFIG_H_ */
