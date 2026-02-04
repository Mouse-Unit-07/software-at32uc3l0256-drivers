/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : adc_mock.h                                            */
/*                                                                            */
/* Bare minimum interface/definitions from ASF library to get analog to       */
/* digital conversion hal implementation to build on Windows.                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef ADC_MOCK_H_
#define ADC_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* ASF constants and struct definitions */
enum
{
    AVR32_ADCIFB_AD_1_PIN = 15,
    AVR32_ADCIFB_AD_2_PIN = 16,
    AVR32_ADCIFB_AD_5_PIN = 19,
    AVR32_ADCIFB_AD_4_PIN = 18,
    AVR32_ADCIFB_AD_1_FUNCTION = 0,
    AVR32_ADCIFB_AD_2_FUNCTION = 0,
    AVR32_ADCIFB_AD_5_FUNCTION = 0,
    AVR32_ADCIFB_AD_4_FUNCTION = 0
};

/* untestable static inline functions in ASF headers */


/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void sysclk_init(void);

#endif /* ADC_MOCK_H_ */
