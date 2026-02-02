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
/* can't use enums- shifting performed */
/* can't use const variables- need multiple instances (timer counter) */
#define DFLL_CLK_FREQ_HZ (130000000u)
#define DFLL_FCPU_PRESCALER (2u) /* F_CPU = (DFLL base) / 2^2 = 35MHz */
#define DFLL_PBA_PRESCALER (1u)  /* PBA = (DFLL base) / 2^1 = 70MHz */
#define DFLL_PBB_PRESCALER (1u)   /* PBB = (DFLL base) / 2^1 = 70MHz */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_clock_at32uc3l0256(void);
void deinit_clock_at32uc3l0256(void);
void delay_ms_at32uc3l0256(uint32_t delay_time);
void delay_us_at32uc3l0256(uint32_t delay_time);

#endif /* CLOCK_AT32UC3L0256_H_ */
