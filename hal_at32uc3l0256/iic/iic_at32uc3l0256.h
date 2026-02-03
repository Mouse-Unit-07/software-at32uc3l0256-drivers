/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : iic_at32uc3l0256.h                                    */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for internal interrupt           */
/* controller HAL                                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef IIC_AT32UC3L0256_H_
#define IIC_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_iic_at32uc3l0256(void);
void deinit_iic_at32uc3l0256(void);
void enable_global_interrupts_at32uc3l0256(void);
void disable_global_interrupts_at32uc3l0256(void);

#endif /* IIC_AT32UC3L0256_H_ */
