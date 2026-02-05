/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : usart_mock.h                                          */
/*                                                                            */
/* Bare minimum interface/definitions from ASF library to get universal       */
/* synchronous/asynchronous receiver/transmitter hal implementation to build  */
/* on Windows.                                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef USART_MOCK_H_
#define USART_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* ASF constants and struct definitions */
typedef struct
{
  //! Set baud rate of the USART (unused in slave modes).
  unsigned long baudrate;

  //! Number of bits to transmit as a character (5 to 9).
  unsigned char charlength;

  //! How to calculate the parity bit: \ref USART_EVEN_PARITY, \ref USART_ODD_PARITY,
  //! \ref USART_SPACE_PARITY, \ref USART_MARK_PARITY, \ref USART_NO_PARITY or
  //! \ref USART_MULTIDROP_PARITY.
  unsigned char paritytype;

  //! Number of stop bits between two characters: \ref USART_1_STOPBIT,
  //! \ref USART_1_5_STOPBITS, \ref USART_2_STOPBITS or any number from 3 to 257
  //! which will result in a time guard period of that length between characters.
  //! \note \ref USART_1_5_STOPBITS is supported in asynchronous modes only.
  unsigned short stopbits;

  //! Run the channel in testmode: \ref USART_NORMAL_CHMODE, \ref USART_AUTO_ECHO,
  //! \ref USART_LOCAL_LOOPBACK or \ref USART_REMOTE_LOOPBACK.
  unsigned char channelmode;
} usart_options_t;

typedef usart_options_t usart_serial_options_t;

enum
{
    AVR32_USART_MR_PAR_NONE = 0x00000004,
    AVR32_USART_MR_NBSTOP_1 = 0x00000000
};

typedef union avr32_usart_cr_t {
  struct {
    unsigned int                 :10;
    unsigned int linwkup         : 1;
    unsigned int linabt          : 1;
    unsigned int rtsdis          : 1;
    unsigned int rtsen           : 1;
    unsigned int                 : 2;
    unsigned int retto           : 1;
    unsigned int rstnack         : 1;
    unsigned int rstit           : 1;
    unsigned int senda           : 1;
    unsigned int sttto           : 1;
    unsigned int stpbrk          : 1;
    unsigned int sttbrk          : 1;
    unsigned int rststa          : 1;
    unsigned int txdis           : 1;
    unsigned int txen            : 1;
    unsigned int rxdis           : 1;
    unsigned int rxen            : 1;
    unsigned int rsttx           : 1;
    unsigned int rstrx           : 1;
    unsigned int                 : 2;
  } lin_mode;
  struct {
    unsigned int                 :12;
    unsigned int rcs             : 1;
    unsigned int fcs             : 1;
    unsigned int                 : 2;
    unsigned int retto           : 1;
    unsigned int rstnack         : 1;
    unsigned int rstit           : 1;
    unsigned int senda           : 1;
    unsigned int sttto           : 1;
    unsigned int stpbrk          : 1;
    unsigned int sttbrk          : 1;
    unsigned int rststa          : 1;
    unsigned int txdis           : 1;
    unsigned int txen            : 1;
    unsigned int rxdis           : 1;
    unsigned int rxen            : 1;
    unsigned int rsttx           : 1;
    unsigned int rstrx           : 1;
    unsigned int                 : 2;
  } spi_master_mode;
  struct {
    unsigned int                 :12;
    unsigned int rtsdis          : 1;
    unsigned int rtsen           : 1;
    unsigned int                 : 2;
    unsigned int retto           : 1;
    unsigned int rstnack         : 1;
    unsigned int rstit           : 1;
    unsigned int senda           : 1;
    unsigned int sttto           : 1;
    unsigned int stpbrk          : 1;
    unsigned int sttbrk          : 1;
    unsigned int rststa          : 1;
    unsigned int txdis           : 1;
    unsigned int txen            : 1;
    unsigned int rxdis           : 1;
    unsigned int rxen            : 1;
    unsigned int rsttx           : 1;
    unsigned int rstrx           : 1;
    unsigned int                 : 2;
  } usart_mode;
} avr32_usart_cr_t;

typedef union avr32_usart_mr_t {
  struct {
    unsigned int                 : 3;
    unsigned int filter          : 1;
    unsigned int                 : 1;
    unsigned int max_iteration   : 3;
    unsigned int                 : 2;
    unsigned int dsnack          : 1;
    unsigned int inack           : 1;
    unsigned int over            : 1;
    unsigned int clko            : 1;
    unsigned int mode9           : 1;
    unsigned int cpol            : 1;
    unsigned int chmode          : 2;
    unsigned int nbstop          : 2;
    unsigned int par             : 3;
    unsigned int cpha            : 1;
    unsigned int chrl            : 2;
    unsigned int usclks          : 2;
    unsigned int mode            : 4;
  } spi_mode;
  struct {
    unsigned int onebit          : 1;
    unsigned int modsync         : 1;
    unsigned int man             : 1;
    unsigned int filter          : 1;
    unsigned int                 : 1;
    unsigned int max_iteration   : 3;
    unsigned int                 : 1;
    unsigned int var_sync        : 1;
    unsigned int dsnack          : 1;
    unsigned int inack           : 1;
    unsigned int over            : 1;
    unsigned int clko            : 1;
    unsigned int mode9           : 1;
    unsigned int msbf            : 1;
    unsigned int chmode          : 2;
    unsigned int nbstop          : 2;
    unsigned int par             : 3;
    unsigned int sync            : 1;
    unsigned int chrl            : 2;
    unsigned int usclks          : 2;
    unsigned int mode            : 4;
  } usart_mode;
} avr32_usart_mr_t;

typedef union avr32_usart_ier_t {
  struct {
    unsigned int                 : 2;
    unsigned int linsnre         : 1;
    unsigned int lince           : 1;
    unsigned int linipe          : 1;
    unsigned int linisfe         : 1;
    unsigned int linbe           : 1;
    unsigned int                 : 5;
    unsigned int ctsic           : 1;
    unsigned int                 : 3;
    unsigned int lintc           : 1;
    unsigned int linid           : 1;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iter            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } lin_mode;
  struct {
    unsigned int                 :12;
    unsigned int ctsic           : 1;
    unsigned int                 : 5;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int unre            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } spi_slave_mode;
  struct {
    unsigned int                 :12;
    unsigned int ctsic           : 1;
    unsigned int                 : 5;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iter            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } usart_mode;
} avr32_usart_ier_t;

typedef union avr32_usart_idr_t {
  struct {
    unsigned int                 : 2;
    unsigned int linsnre         : 1;
    unsigned int lince           : 1;
    unsigned int linipe          : 1;
    unsigned int linisfe         : 1;
    unsigned int linbe           : 1;
    unsigned int                 : 5;
    unsigned int ctsic           : 1;
    unsigned int                 : 3;
    unsigned int lintc           : 1;
    unsigned int linid           : 1;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iter            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } lin_mode;
  struct {
    unsigned int                 :12;
    unsigned int ctsic           : 1;
    unsigned int                 : 5;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int unre            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } spi_slave_mode;
  struct {
    unsigned int                 :12;
    unsigned int ctsic           : 1;
    unsigned int                 : 5;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iter            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } usart_mode;
} avr32_usart_idr_t;

typedef union avr32_usart_imr_t {
  struct {
    unsigned int                 : 2;
    unsigned int linsnre         : 1;
    unsigned int lince           : 1;
    unsigned int linipe          : 1;
    unsigned int linisfe         : 1;
    unsigned int linbe           : 1;
    unsigned int                 : 5;
    unsigned int ctsic           : 1;
    unsigned int                 : 3;
    unsigned int lintc           : 1;
    unsigned int linid           : 1;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iter            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } lin_mode;
  struct {
    unsigned int                 :12;
    unsigned int ctsic           : 1;
    unsigned int                 : 5;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int unre            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } spi_slave_mode;
  struct {
    unsigned int                 : 7;
    unsigned int manea           : 1;
    unsigned int                 : 3;
    unsigned int mane            : 1;
    unsigned int ctsic           : 1;
    unsigned int                 : 5;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iter            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } usart_mode;
} avr32_usart_imr_t;

typedef union avr32_usart_csr_t {
  struct {
    unsigned int                 : 2;
    unsigned int linsnre         : 1;
    unsigned int lince           : 1;
    unsigned int linipe          : 1;
    unsigned int linisfe         : 1;
    unsigned int linbe           : 1;
    unsigned int                 : 1;
    unsigned int cts             : 1;
    unsigned int                 : 3;
    unsigned int ctsic           : 1;
    unsigned int                 : 3;
    unsigned int lintc           : 1;
    unsigned int linid           : 1;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iter            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } lin_mode;
  struct {
    unsigned int                 : 8;
    unsigned int cts             : 1;
    unsigned int                 : 3;
    unsigned int ctsic           : 1;
    unsigned int                 : 5;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int unre            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } spi_slave_mode;
  struct {
    unsigned int                 : 7;
    unsigned int manerr          : 1;
    unsigned int cts             : 1;
    unsigned int                 : 3;
    unsigned int ctsic           : 1;
    unsigned int                 : 5;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iter            : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
  } usart_mode;
} avr32_usart_csr_t;

typedef struct avr32_usart_rhr_t {
    unsigned int                 :16;
    unsigned int rxsynh          : 1;
    unsigned int                 : 6;
    unsigned int rxchr           : 9;
} avr32_usart_rhr_t;

typedef struct avr32_usart_thr_t {
    unsigned int                 :16;
    unsigned int txsynh          : 1;
    unsigned int                 : 6;
    unsigned int txchr           : 9;
} avr32_usart_thr_t;

typedef struct avr32_usart_brgr_t {
    unsigned int                 :13;
    unsigned int fp              : 3;
    unsigned int cd              :16;
} avr32_usart_brgr_t;

typedef struct avr32_usart_rtor_t {
    unsigned int                 :15;
    unsigned int to              :17;
} avr32_usart_rtor_t;

typedef struct avr32_usart_ttgr_t {
    unsigned int                 :24;
    unsigned int tg              : 8;
} avr32_usart_ttgr_t;

typedef struct avr32_usart_fidi_t {
    unsigned int                 :21;
    unsigned int fi_di_ratio     :11;
} avr32_usart_fidi_t;

typedef struct avr32_usart_ner_t {
    unsigned int                 :24;
    unsigned int nb_errors       : 8;
} avr32_usart_ner_t;

typedef struct avr32_usart_xxr_t {
    unsigned int                 :16;
    unsigned int xon             : 8;
    unsigned int xoff            : 8;
} avr32_usart_xxr_t;

typedef struct avr32_usart_ifr_t {
    unsigned int                 :24;
    unsigned int irda_filter     : 8;
} avr32_usart_ifr_t;

typedef struct avr32_usart_man_t {
    unsigned int                 : 1;
    unsigned int drift           : 1;
    unsigned int                 : 1;
    unsigned int rx_mpol         : 1;
    unsigned int                 : 2;
    unsigned int rx_pp           : 2;
    unsigned int                 : 4;
    unsigned int rx_pl           : 4;
    unsigned int                 : 3;
    unsigned int tx_mpol         : 1;
    unsigned int                 : 2;
    unsigned int tx_pp           : 2;
    unsigned int                 : 4;
    unsigned int tx_pl           : 4;
} avr32_usart_man_t;

typedef struct avr32_usart_linmr_t {
    unsigned int                 :15;
    unsigned int pdcm            : 1;
    unsigned int dlc             : 8;
    unsigned int wkuptyp         : 1;
    unsigned int fsdis           : 1;
    unsigned int dlm             : 1;
    unsigned int chktyp          : 1;
    unsigned int chkdis          : 1;
    unsigned int pardis          : 1;
    unsigned int nact            : 2;
} avr32_usart_linmr_t;

typedef struct avr32_usart_linir_t {
    unsigned int                 :24;
    unsigned int idchr           : 8;
} avr32_usart_linir_t;

typedef struct avr32_usart_wpmr_t {
    unsigned int wpkey           :24;
    unsigned int                 : 7;
    unsigned int wpen            : 1;
} avr32_usart_wpmr_t;

typedef struct avr32_usart_wpsr_t {
    unsigned int                 : 8;
    unsigned int wpvsrc          :16;
    unsigned int                 : 7;
    unsigned int wpv             : 1;
} avr32_usart_wpsr_t;

typedef struct avr32_usart_features_t {
    unsigned int                 :14;
    unsigned int hcspimas        : 1;
    unsigned int spiconfig       : 1;
    unsigned int spiimpl         : 1;
    unsigned int linpdcimpl      : 1;
    unsigned int hclinmas        : 1;
    unsigned int linconf         : 1;
    unsigned int linimpl         : 1;
    unsigned int enpolneg        : 1;
    unsigned int fracnimpl       : 1;
    unsigned int nberrimpl       : 1;
    unsigned int rs485impl       : 1;
    unsigned int hhimpl          : 1;
    unsigned int modimpl         : 1;
    unsigned int manoutimpl      : 1;
    unsigned int iso7816impl     : 1;
    unsigned int irdaimpl        : 1;
    unsigned int xximpl          : 1;
    unsigned int manbpimpl       : 1;
} avr32_usart_features_t;

typedef struct avr32_usart_version_t {
    unsigned int                 :13;
    unsigned int variant         : 3;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_usart_version_t;

typedef struct avr32_usart_t {
  union {
          unsigned long                  cr        ;//0x0000
          avr32_usart_cr_t               CR        ;
  };
  union {
          unsigned long                  mr        ;//0x0004
          avr32_usart_mr_t               MR        ;
  };
  union {
          unsigned long                  ier       ;//0x0008
          avr32_usart_ier_t              IER       ;
  };
  union {
          unsigned long                  idr       ;//0x000c
          avr32_usart_idr_t              IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x0010
    const avr32_usart_imr_t              IMR       ;
  };
  union {
    const unsigned long                  csr       ;//0x0014
    const avr32_usart_csr_t              CSR       ;
  };
  union {
    const unsigned long                  rhr       ;//0x0018
    const avr32_usart_rhr_t              RHR       ;
  };
  union {
          unsigned long                  thr       ;//0x001c
          avr32_usart_thr_t              THR       ;
  };
  union {
          unsigned long                  brgr      ;//0x0020
          avr32_usart_brgr_t             BRGR      ;
  };
  union {
          unsigned long                  rtor      ;//0x0024
          avr32_usart_rtor_t             RTOR      ;
  };
  union {
          unsigned long                  ttgr      ;//0x0028
          avr32_usart_ttgr_t             TTGR      ;
  };
          unsigned int                   :32       ;//0x002c
          unsigned int                   :32       ;//0x0030
          unsigned int                   :32       ;//0x0034
          unsigned int                   :32       ;//0x0038
          unsigned int                   :32       ;//0x003c
  union {
          unsigned long                  fidi      ;//0x0040
          avr32_usart_fidi_t             FIDI      ;
  };
  union {
    const unsigned long                  ner       ;//0x0044
    const avr32_usart_ner_t              NER       ;
  };
  union {
          unsigned long                  xxr       ;//0x0048
          avr32_usart_xxr_t              XXR       ;
  };
  union {
          unsigned long                  ifr       ;//0x004c
          avr32_usart_ifr_t              IFR       ;
  };
  union {
          unsigned long                  man       ;//0x0050
          avr32_usart_man_t              MAN       ;
  };
  union {
          unsigned long                  linmr     ;//0x0054
          avr32_usart_linmr_t            LINMR     ;
  };
  union {
          unsigned long                  linir     ;//0x0058
          avr32_usart_linir_t            LINIR     ;
  };
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
  union {
          unsigned long                  wpmr      ;//0x00e4
          avr32_usart_wpmr_t             WPMR      ;
  };
  union {
    const unsigned long                  wpsr      ;//0x00e8
    const avr32_usart_wpsr_t             WPSR      ;
  };
          unsigned int                   :32       ;//0x00ec
          unsigned int                   :32       ;//0x00f0
          unsigned int                   :32       ;//0x00f4
  union {
    const unsigned long                  features  ;//0x00f8
    const avr32_usart_features_t         FEATURES  ;
  };
  union {
    const unsigned long                  version   ;//0x00fc
    const avr32_usart_version_t          VERSION   ;
  };
} avr32_usart_t;

enum
{
    AVR32_USART2_ADDRESS = 0xFFFF3800
};

#define AVR32_USART2 (*((volatile avr32_usart_t*)AVR32_USART2_ADDRESS))

/* untestable static inline functions in ASF headers */
static inline void stdio_serial_init(volatile void *usart, const usart_serial_options_t *opt) {}

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
/* none */

#endif /* USART_MOCK_H_ */
