/*================================ FILE INFO =================================*/
/* Filename           : test_iic_at32uc3l0256.cpp                             */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256 library                           */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {
#include <stdint.h>
#include "asf.h"
#include "iic_at32uc3l0256.h"
}

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
/* none */

/*============================================================================*/
/*                            Mock Implementations                            */
/*============================================================================*/
extern "C"
{

void INTC_init_interrupts(void)
{
    mock().actualCall("INTC_init_interrupts");
}

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(HalIicTests)
{
    void setup() override
    {
        mock().clear();
    }

    void teardown() override
    {
        mock().checkExpectations();
        mock().clear();
    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(HalIicTests, InitIicCallsFunctions)
{
    mock().expectOneCall("INTC_init_interrupts");
    init_iic_at32uc3l0256();
}

TEST(HalIicTests, DeinitIic)
{
    deinit_iic_at32uc3l0256();
}

TEST(HalIicTests, EnableGlobalInterrupts)
{
    enable_global_interrupts_at32uc3l0256();
}

TEST(HalIicTests, DisableGlobalInterrupts)
{
    disable_global_interrupts_at32uc3l0256();
}
