/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : iic_hal_config.h                                      */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for internal interrupt           */
/* controller HAL handler                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef IIC_HAL_CONFIG_H_
#define IIC_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
const struct iic_hal_handler *get_iic_hal_handler(void);

#endif /* IIC_HAL_CONFIG_H_ */
