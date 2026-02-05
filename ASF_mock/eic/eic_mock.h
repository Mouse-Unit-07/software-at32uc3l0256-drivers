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

typedef struct avr32_eic_ier_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_ier_t;

typedef struct avr32_eic_idr_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_idr_t;

typedef struct avr32_eic_imr_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_imr_t;

typedef struct avr32_eic_isr_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_isr_t;

typedef struct avr32_eic_icr_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_icr_t;

typedef struct avr32_eic_mode_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_mode_t;

typedef struct avr32_eic_edge_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_edge_t;

typedef struct avr32_eic_level_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_level_t;

typedef struct avr32_eic_filter_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_filter_t;

typedef struct avr32_eic_test_t {
    unsigned int testen          : 1;
    unsigned int                 :15;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_test_t;

typedef struct avr32_eic_async_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_async_t;

typedef struct avr32_eic_en_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_en_t;

typedef struct avr32_eic_dis_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_dis_t;

typedef struct avr32_eic_ctrl_t {
    unsigned int                 :16;
    unsigned int int15           : 1;
    unsigned int int14           : 1;
    unsigned int int13           : 1;
    unsigned int int12           : 1;
    unsigned int int11           : 1;
    unsigned int int10           : 1;
    unsigned int int9            : 1;
    unsigned int int8            : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int nmi             : 1;
} avr32_eic_ctrl_t;

typedef struct avr32_eic_version_t {
    unsigned int                 :20;
    unsigned int version         :12;
} avr32_eic_version_t;

typedef struct avr32_eic_t {
  union {
          unsigned long                  ier       ;//0x0000
          avr32_eic_ier_t                IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0004
          avr32_eic_idr_t                IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x0008
    const avr32_eic_imr_t                IMR       ;
  };
  union {
    const unsigned long                  isr       ;//0x000c
    const avr32_eic_isr_t                ISR       ;
  };
  union {
          unsigned long                  icr       ;//0x0010
          avr32_eic_icr_t                ICR       ;
  };
  union {
          unsigned long                  mode      ;//0x0014
          avr32_eic_mode_t               MODE      ;
  };
  union {
          unsigned long                  edge      ;//0x0018
          avr32_eic_edge_t               EDGE      ;
  };
  union {
          unsigned long                  level     ;//0x001c
          avr32_eic_level_t              LEVEL     ;
  };
  union {
          unsigned long                  filter    ;//0x0020
          avr32_eic_filter_t             FILTER    ;
  };
  union {
          unsigned long                  test      ;//0x0024
          avr32_eic_test_t               TEST      ;
  };
  union {
          unsigned long                  async     ;//0x0028
          avr32_eic_async_t              ASYNC     ;
  };
          unsigned int                   :32       ;//0x002c
  union {
          unsigned long                  en        ;//0x0030
          avr32_eic_en_t                 EN        ;
  };
  union {
          unsigned long                  dis       ;//0x0034
          avr32_eic_dis_t                DIS       ;
  };
  union {
    const unsigned long                  ctrl      ;//0x0038
    const avr32_eic_ctrl_t               CTRL      ;
  };
          unsigned int                   :32       ;//0x003c
          unsigned int                   :32       ;//0x0040
          unsigned int                   :32       ;//0x0044
          unsigned int                   :32       ;//0x0048
          unsigned int                   :32       ;//0x004c
          unsigned int                   :32       ;//0x0050
          unsigned int                   :32       ;//0x0054
          unsigned int                   :32       ;//0x0058
          unsigned int                   :32       ;//0x005c
          unsigned int                   :32       ;//0x0060
          unsigned int                   :32       ;//0x0064
          unsigned int                   :32       ;//0x0068
          unsigned int                   :32       ;//0x006c
          unsigned int                   :32       ;//0x0070
          unsigned int                   :32       ;//0x0074
          unsigned int                   :32       ;//0x0078
          unsigned int                   :32       ;//0x007c
          unsigned int                   :32       ;//0x0080
          unsigned int                   :32       ;//0x0084
          unsigned int                   :32       ;//0x0088
          unsigned int                   :32       ;//0x008c
          unsigned int                   :32       ;//0x0090
          unsigned int                   :32       ;//0x0094
          unsigned int                   :32       ;//0x0098
          unsigned int                   :32       ;//0x009c
          unsigned int                   :32       ;//0x00a0
          unsigned int                   :32       ;//0x00a4
          unsigned int                   :32       ;//0x00a8
          unsigned int                   :32       ;//0x00ac
          unsigned int                   :32       ;//0x00b0
          unsigned int                   :32       ;//0x00b4
          unsigned int                   :32       ;//0x00b8
          unsigned int                   :32       ;//0x00bc
          unsigned int                   :32       ;//0x00c0
          unsigned int                   :32       ;//0x00c4
          unsigned int                   :32       ;//0x00c8
          unsigned int                   :32       ;//0x00cc
          unsigned int                   :32       ;//0x00d0
          unsigned int                   :32       ;//0x00d4
          unsigned int                   :32       ;//0x00d8
          unsigned int                   :32       ;//0x00dc
          unsigned int                   :32       ;//0x00e0
          unsigned int                   :32       ;//0x00e4
          unsigned int                   :32       ;//0x00e8
          unsigned int                   :32       ;//0x00ec
          unsigned int                   :32       ;//0x00f0
          unsigned int                   :32       ;//0x00f4
          unsigned int                   :32       ;//0x00f8
          unsigned int                   :32       ;//0x00fc
  union {
    const unsigned long                  version   ;//0x00ff
    const avr32_eic_version_t            VERSION   ;
  };
} avr32_eic_t;

enum
{
    AVR32_EIC_ADDRESS = 0xFFFF2400
};

#define AVR32_EIC (*((volatile avr32_eic_t*)AVR32_EIC_ADDRESS))

enum
{
    AVR32_EIC_INT1 = 1,
    AVR32_EIC_INT3 = 3,
    AVR32_EIC_INT2 = 2
};

typedef struct
{
  //!Line
  unsigned char eic_line;

  //! Mode : EDGE_LEVEL or TRIGGER_LEVEL
  unsigned char eic_mode;

  //! Edge : FALLING_EDGE or RISING_EDGE
  unsigned char eic_edge;

  //! Level :  LOW_LEVEL or HIGH_LEVEL
  unsigned char eic_level;

  //! Filter:  NOT_FILTERED or FILTERED
  unsigned char eic_filter;

  //! Async:  SYNC mode or ASYNC
  unsigned char eic_async;

} eic_options_t;

enum
{
    AVR32_EIC_EDGE_IRQ = 0x00000000,
    EIC_MODE_EDGE_TRIGGERED = AVR32_EIC_EDGE_IRQ,
    AVR32_EIC_RISING_EDGE = 0x00000001,
    AVR32_EIC_FALLING_EDGE = 0x00000000,
    AVR32_EIC_SYNC = 0x00000000,
    EIC_SYNCH_MODE = AVR32_EIC_SYNC,
};

/* untestable static inline functions in ASF headers */


/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void eic_clear_interrupt_line(volatile avr32_eic_t *eic, uint32_t line_number);
void eic_init(volatile avr32_eic_t *eic, const eic_options_t *opt, uint32_t nb_lines);
void eic_enable_lines(volatile avr32_eic_t *eic, uint32_t mask_lines);
void eic_enable_interrupt_lines(volatile avr32_eic_t *eic, uint32_t mask_lines);

#endif /* EIC_MOCK_H_ */
