/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : clock_at32uc3l0256.h                                  */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for clock HAL                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef CLOCK_AT32UC3L0256_H_
#define CLOCK_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_clock_at32uc3l0256(void);
void deinit_clock_at32uc3l0256(void);
void delay_ms_at32uc3l0256(uint32_t delay_time);
void delay_us_at32uc3l0256(uint32_t delay_time);

#endif /* CLOCK_AT32UC3L0256_H_ */
