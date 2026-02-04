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

typedef struct {
    /*! Resolution mode */
    uint16_t resolution;

    /*! Channels Sample & Hold Time in [0,15], where
     *  Ts&h = shtim * Tclk_adc. */
    uint16_t shtim;

    /*! Ratio Fclk_adcifb/Fclk_adc = 2*i with i an integer in [1,64] */
    uint16_t ratio_clkadcifb_clkadc;

    /**
     * ADC Startup time in [0,127],
     * where Tstartup = startup * 8 * Tclk_adc
     */
    uint16_t startup;

    /*! ADCIFB Sleep Mode enable/disable */
    bool sleep_mode_enable;
} adcifb_opt_t;

typedef struct avr32_adcifb_cr_t {
    unsigned int                 :22;
    unsigned int dis             : 1;
    unsigned int en              : 1;
    unsigned int                 : 6;
    unsigned int start           : 1;
    unsigned int swrst           : 1;
} avr32_adcifb_cr_t;

typedef struct avr32_adcifb_mr_t {
    unsigned int pendbc          : 4;
    unsigned int                 : 4;
    unsigned int tspo            : 8;
    unsigned int                 : 9;
    unsigned int apoe            : 1;
    unsigned int ace             : 1;
    unsigned int pendet          : 1;
    unsigned int                 : 3;
    unsigned int tsamod          : 1;
} avr32_adcifb_mr_t;

typedef struct avr32_adcifb_acr_t {
    unsigned int                 : 4;
    unsigned int shtim           : 4;
    unsigned int                 : 1;
    unsigned int startup         : 7;
    unsigned int                 : 2;
    unsigned int prescal         : 6;
    unsigned int                 : 2;
    unsigned int res             : 2;
    unsigned int                 : 2;
    unsigned int                 : 1;
    unsigned int sleep           : 1;
} avr32_adcifb_acr_t;



typedef struct avr32_adcifb_trgr_t {
    unsigned int trgper          :16;
    unsigned int                 :13;
    unsigned int trgmod          : 3;
} avr32_adcifb_trgr_t;



typedef struct avr32_adcifb_cvr_t {
    unsigned int                 : 4;
    unsigned int hv              :12;
    unsigned int                 : 4;
    unsigned int lv              :12;
} avr32_adcifb_cvr_t;



typedef struct avr32_adcifb_sr_t {
    unsigned int                 : 7;
    unsigned int en              : 1;
    unsigned int                 : 9;
    unsigned int celse           : 1;
    unsigned int cgt             : 1;
    unsigned int clt             : 1;
    unsigned int                 : 2;
    unsigned int busy            : 1;
    unsigned int ready           : 1;
    unsigned int                 : 2;
    unsigned int nocnt           : 1;
    unsigned int pencnt          : 1;
    unsigned int                 : 2;
    unsigned int ovre            : 1;
    unsigned int drdy            : 1;
} avr32_adcifb_sr_t;



typedef struct avr32_adcifb_isr_t {
    unsigned int                 :17;
    unsigned int celse           : 1;
    unsigned int cgt             : 1;
    unsigned int clt             : 1;
    unsigned int                 : 2;
    unsigned int busy            : 1;
    unsigned int ready           : 1;
    unsigned int                 : 2;
    unsigned int nocnt           : 1;
    unsigned int pencnt          : 1;
    unsigned int                 : 2;
    unsigned int ovre            : 1;
    unsigned int drdy            : 1;
} avr32_adcifb_isr_t;

typedef struct avr32_adcifb_icr_t {
    unsigned int                 :17;
    unsigned int celse           : 1;
    unsigned int cgt             : 1;
    unsigned int clt             : 1;
    unsigned int                 : 2;
    unsigned int busy            : 1;
    unsigned int ready           : 1;
    unsigned int                 : 2;
    unsigned int nocnt           : 1;
    unsigned int pencnt          : 1;
    unsigned int                 : 2;
    unsigned int ovre            : 1;
    unsigned int drdy            : 1;
} avr32_adcifb_icr_t;

typedef struct avr32_adcifb_ier_t {
    unsigned int                 :17;
    unsigned int celse           : 1;
    unsigned int cgt             : 1;
    unsigned int clt             : 1;
    unsigned int                 : 2;
    unsigned int busy            : 1;
    unsigned int ready           : 1;
    unsigned int                 : 2;
    unsigned int nocnt           : 1;
    unsigned int pencnt          : 1;
    unsigned int                 : 2;
    unsigned int ovre            : 1;
    unsigned int drdy            : 1;
} avr32_adcifb_ier_t;

typedef struct avr32_adcifb_idr_t {
    unsigned int                 :17;
    unsigned int celse           : 1;
    unsigned int cgt             : 1;
    unsigned int clt             : 1;
    unsigned int                 : 2;
    unsigned int busy            : 1;
    unsigned int ready           : 1;
    unsigned int                 : 2;
    unsigned int nocnt           : 1;
    unsigned int pencnt          : 1;
    unsigned int                 : 2;
    unsigned int ovre            : 1;
    unsigned int drdy            : 1;
} avr32_adcifb_idr_t;

typedef struct avr32_adcifb_imr_t {
    unsigned int                 :17;
    unsigned int celse           : 1;
    unsigned int cgt             : 1;
    unsigned int clt             : 1;
    unsigned int                 : 2;
    unsigned int busy            : 1;
    unsigned int ready           : 1;
    unsigned int                 : 2;
    unsigned int nocnt           : 1;
    unsigned int pencnt          : 1;
    unsigned int                 : 2;
    unsigned int ovre            : 1;
    unsigned int drdy            : 1;
} avr32_adcifb_imr_t;

typedef struct avr32_adcifb_lcdr_t {
    unsigned int                 : 8;
    unsigned int lcch            : 8;
    unsigned int                 : 4;
    unsigned int ldata           :12;
} avr32_adcifb_lcdr_t;

typedef struct avr32_adcifb_parameter_t {
    unsigned int ch31            : 1;
    unsigned int ch30            : 1;
    unsigned int ch29            : 1;
    unsigned int ch28            : 1;
    unsigned int ch27            : 1;
    unsigned int ch26            : 1;
    unsigned int ch25            : 1;
    unsigned int ch24            : 1;
    unsigned int ch23            : 1;
    unsigned int ch22            : 1;
    unsigned int ch21            : 1;
    unsigned int ch20            : 1;
    unsigned int ch19            : 1;
    unsigned int ch18            : 1;
    unsigned int ch17            : 1;
    unsigned int ch16            : 1;
    unsigned int ch15            : 1;
    unsigned int ch14            : 1;
    unsigned int ch13            : 1;
    unsigned int ch12            : 1;
    unsigned int ch11            : 1;
    unsigned int ch10            : 1;
    unsigned int ch9             : 1;
    unsigned int ch8             : 1;
    unsigned int ch7             : 1;
    unsigned int ch6             : 1;
    unsigned int ch5             : 1;
    unsigned int ch4             : 1;
    unsigned int ch3             : 1;
    unsigned int ch2             : 1;
    unsigned int ch1             : 1;
    unsigned int ch0             : 1;
} avr32_adcifb_parameter_t;

typedef struct avr32_adcifb_version_t {
    unsigned int                 :12;
    unsigned int variant         : 4;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_adcifb_version_t;

typedef struct avr32_adcifb_cir_t {
    unsigned int                 : 5;
    unsigned int civr            : 3;
    unsigned int civs            : 1;
    unsigned int civ             : 7;
    unsigned int                 :14;
    unsigned int cim             : 2;
} avr32_adcifb_cir_t;

typedef struct avr32_adcifb_cher_t {
    unsigned int ch31            : 1;
    unsigned int ch30            : 1;
    unsigned int ch29            : 1;
    unsigned int ch28            : 1;
    unsigned int ch27            : 1;
    unsigned int ch26            : 1;
    unsigned int ch25            : 1;
    unsigned int ch24            : 1;
    unsigned int ch23            : 1;
    unsigned int ch22            : 1;
    unsigned int ch21            : 1;
    unsigned int ch20            : 1;
    unsigned int ch19            : 1;
    unsigned int ch18            : 1;
    unsigned int ch17            : 1;
    unsigned int ch16            : 1;
    unsigned int ch15            : 1;
    unsigned int ch14            : 1;
    unsigned int ch13            : 1;
    unsigned int ch12            : 1;
    unsigned int ch11            : 1;
    unsigned int ch10            : 1;
    unsigned int ch9             : 1;
    unsigned int ch8             : 1;
    unsigned int ch7             : 1;
    unsigned int ch6             : 1;
    unsigned int ch5             : 1;
    unsigned int ch4             : 1;
    unsigned int ch3             : 1;
    unsigned int ch2             : 1;
    unsigned int ch1             : 1;
    unsigned int ch0             : 1;
} avr32_adcifb_cher_t;

typedef struct avr32_adcifb_chdr_t {
    unsigned int ch31            : 1;
    unsigned int ch30            : 1;
    unsigned int ch29            : 1;
    unsigned int ch28            : 1;
    unsigned int ch27            : 1;
    unsigned int ch26            : 1;
    unsigned int ch25            : 1;
    unsigned int ch24            : 1;
    unsigned int ch23            : 1;
    unsigned int ch22            : 1;
    unsigned int ch21            : 1;
    unsigned int ch20            : 1;
    unsigned int ch19            : 1;
    unsigned int ch18            : 1;
    unsigned int ch17            : 1;
    unsigned int ch16            : 1;
    unsigned int ch15            : 1;
    unsigned int ch14            : 1;
    unsigned int ch13            : 1;
    unsigned int ch12            : 1;
    unsigned int ch11            : 1;
    unsigned int ch10            : 1;
    unsigned int ch9             : 1;
    unsigned int ch8             : 1;
    unsigned int ch7             : 1;
    unsigned int ch6             : 1;
    unsigned int ch5             : 1;
    unsigned int ch4             : 1;
    unsigned int ch3             : 1;
    unsigned int ch2             : 1;
    unsigned int ch1             : 1;
    unsigned int ch0             : 1;
} avr32_adcifb_chdr_t;

typedef struct avr32_adcifb_chsr_t {
    unsigned int ch31            : 1;
    unsigned int ch30            : 1;
    unsigned int ch29            : 1;
    unsigned int ch28            : 1;
    unsigned int ch27            : 1;
    unsigned int ch26            : 1;
    unsigned int ch25            : 1;
    unsigned int ch24            : 1;
    unsigned int ch23            : 1;
    unsigned int ch22            : 1;
    unsigned int ch21            : 1;
    unsigned int ch20            : 1;
    unsigned int ch19            : 1;
    unsigned int ch18            : 1;
    unsigned int ch17            : 1;
    unsigned int ch16            : 1;
    unsigned int ch15            : 1;
    unsigned int ch14            : 1;
    unsigned int ch13            : 1;
    unsigned int ch12            : 1;
    unsigned int ch11            : 1;
    unsigned int ch10            : 1;
    unsigned int ch9             : 1;
    unsigned int ch8             : 1;
    unsigned int ch7             : 1;
    unsigned int ch6             : 1;
    unsigned int ch5             : 1;
    unsigned int ch4             : 1;
    unsigned int ch3             : 1;
    unsigned int ch2             : 1;
    unsigned int ch1             : 1;
    unsigned int ch0             : 1;
} avr32_adcifb_chsr_t;

typedef struct avr32_adcifb_t {
  union {
          unsigned long                  cr        ;//0x0000
          avr32_adcifb_cr_t              CR        ;
  };
  union {
          unsigned long                  mr        ;//0x0004
          avr32_adcifb_mr_t              MR        ;
  };
  union {
          unsigned long                  acr       ;//0x0008
          avr32_adcifb_acr_t             ACR       ;
  };
  union {
          unsigned long                  trgr      ;//0x000c
          avr32_adcifb_trgr_t            TRGR      ;
  };
  union {
          unsigned long                  cvr       ;//0x0010
          avr32_adcifb_cvr_t             CVR       ;
  };
  union {
    const unsigned long                  sr        ;//0x0014
    const avr32_adcifb_sr_t              SR        ;
  };
  union {
    const unsigned long                  isr       ;//0x0018
    const avr32_adcifb_isr_t             ISR       ;
  };
  union {
          unsigned long                  icr       ;//0x001c
          avr32_adcifb_icr_t             ICR       ;
  };
  union {
          unsigned long                  ier       ;//0x0020
          avr32_adcifb_ier_t             IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0024
          avr32_adcifb_idr_t             IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x0028
    const avr32_adcifb_imr_t             IMR       ;
  };
  union {
    const unsigned long                  lcdr      ;//0x002c
    const avr32_adcifb_lcdr_t            LCDR      ;
  };
  union {
    const unsigned long                  parameter ;//0x0030
    const avr32_adcifb_parameter_t       PARAMETER ;
  };
  union {
    const unsigned long                  version   ;//0x0034
    const avr32_adcifb_version_t         VERSION   ;
  };
  union {
          unsigned long                  cir       ;//0x0038
          avr32_adcifb_cir_t             CIR       ;
  };
          unsigned int                   :32       ;//0x003c
  union {
          unsigned long                  cher      ;//0x0040
          avr32_adcifb_cher_t            CHER      ;
  };
  union {
          unsigned long                  chdr      ;//0x0044
          avr32_adcifb_chdr_t            CHDR      ;
  };
  union {
    const unsigned long                  chsr      ;//0x0048
    const avr32_adcifb_chsr_t            CHSR      ;
  };
} avr32_adcifb_t;

enum
{
    AVR32_ADCIFB_ADDRESS = 0xFFFF6000
};

/* only possible w/ a macro */
#define AVR32_ADCIFB (*((volatile avr32_adcifb_t*)AVR32_ADCIFB_ADDRESS))

enum
{
    AVR32_ADCIFB_ACR_RES_10BIT = 0x00000001
};

/* untestable static inline functions in ASF headers */


/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void sysclk_init(void);
int32_t adcifb_configure(volatile avr32_adcifb_t *adcifb,
    const adcifb_opt_t *p_adcifb_opt);

#endif /* ADC_MOCK_H_ */
