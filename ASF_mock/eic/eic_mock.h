/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : eic_mock.h                                            */
/*                                                                            */
/* Bare minimum interface/definitions from ASF library to get universal       */
/* synchronous/asynchronous receiver/transmitter hal implementation to build  */
/* on Windows.                                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef EIC_MOCK_H_
#define EIC_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* ASF constants and struct definitions */
enum
{
    AVR32_EIC_EXTINT_1_1_PIN = 39,
    AVR32_EIC_EXTINT_1_1_FUNCTION = 6,
    AVR32_EIC_EXTINT_3_1_PIN = 41,
    AVR32_EIC_EXTINT_3_1_FUNCTION = 6
};

/* untestable static inline functions in ASF headers */


/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
/* none */

#endif /* EIC_MOCK_H_ */
