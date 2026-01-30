/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : clock_mock.h                                          */
/*                                                                            */
/* Bare minimum interface/definitions to get clock hal implementation to      */
/* build on Windows                                                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef CLOCK_MOCK_H_
#define CLOCK_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
struct genclk_config {
    uint32_t ctrl;
};

struct dfll_config {
    struct genclk_config    ref_cfg;        //!< Reference clock
    uint32_t                conf;           //!< DFLLnCONF
    uint32_t                mul;            //!< DFLLnMUL
    uint32_t                step;           //!< DFLLnSTEP
    uint32_t                ssg;            //!< DFLLnSSG
};

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void dfll_enable_open_loop(const struct dfll_config *cfg, unsigned int dfll_id);

#endif /* CLOCK_MOCK_H_ */
