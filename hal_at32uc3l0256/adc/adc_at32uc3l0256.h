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
struct adc_handle {
    uint32_t channel_mask;
};

extern const struct adc_handle ir_sensor_1;
extern const struct adc_handle ir_sensor_2;
extern const struct adc_handle ir_sensor_3;
extern const struct adc_handle ir_sensor_4;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_adc_at32uc3l0256(void);
void deinit_adc_at32uc3l0256(void);
uint32_t read_adc_channel_at32uc3l0256(const struct adc_handle *handle);

#endif /* ADC_AT32UC3L0256_H_ */
