/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : adc_at32uc3l0256.h                                    */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for analog to digital conversion */
/* HAL                                                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef ADC_AT32UC3L0256_H_
#define ADC_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
struct adc_handle;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_adc_at32uc3l0256(void);
void deinit_adc_at32uc3l0256(void);
void enable_adc_channel_at32uc3l0256(const struct adc_handle *handle);
void disable_adc_channel_at32uc3l0256(const struct adc_handle *handle);
uint32_t read_adc_channel_at32uc3l0256(const struct adc_handle *handle);

#endif /* ADC_AT32UC3L0256_H_ */
