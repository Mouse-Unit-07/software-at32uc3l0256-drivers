/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : eic_hal_config.h                                      */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for external interrupt           */
/* controller HAL handler                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef EIC_HAL_CONFIG_H_
#define EIC_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
const struct eic_hal_handler *get_eic_hal_handler(void);
const struct eic_handle* get_encoder_1_channel_a_handle(void);
const struct eic_handle* get_encoder_2_channel_a_handle(void);
const struct eic_handle* get_config_pushbutton_handle(void);

#endif /* EIC_HAL_CONFIG_H_ */
