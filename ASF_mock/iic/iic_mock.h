/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : iic_mock.h                                            */
/*                                                                            */
/* Bare minimum interface/definitions from ASF library to get internal        */
/* interrupt controller hal implementation to build on Windows.               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef IIC_MOCK_H_
#define IIC_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* ASF constants and struct definitions */

/* untestable static inline functions in ASF headers */


/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void INTC_init_interrupts(void);

#endif /* IIC_MOCK_H_ */
