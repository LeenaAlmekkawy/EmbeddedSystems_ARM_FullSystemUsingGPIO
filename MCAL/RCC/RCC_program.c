#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"




void RCC_voidSystemClkInit(void)
{
	/*RCC_CR 		= 0x00050000;
		RCC_CFGR 	= 0x00000001;*/

      #if RCC_CLK_SOURCE==HSE

         SET_BIT(RCC_CR, RCC_HSEBYP);
         SET_BIT(RCC_CR, RCC_HSEON);
         SET_BIT(RCC_CFGR, RCC_SW0);
         CLR_BIT(RCC_CFGR, RCC_SW1);

    #elif RCC_CLK_SOURCE==HSI 
         SET_BIT(RCC_CR, RCC_HSION);
         CLR_BIT(RCC_CFGR, RCC_SW0);
         CLR_BIT(RCC_CFGR, RCC_SW1);

    #elif RCC_CLK_SOURCE==LSE 
         SET_BIT(RCC_BDCR, RCC_LSEBYP);
         SET_BIT(RCC_BDCR, RCC_LSEON);

    #elif RCC_CLK_SOURCE==LSI 
         SET_BIT(RCC_CSR, RCC_LSION);



        


    #endif


}

void RCC_voidEnablePerClk(u8 Copy_u8Bus, u8 Copy_u8Per)
{
    //RangeCheck
    if(Copy_u8Per<PerRange)
    {
        switch(Copy_u8Bus)
        {
        case  RCC_AHB1 :
            SET_BIT(RCC_AHB1ENR, Copy_u8Per);
                break;
        case  RCC_AHB2 :
            SET_BIT(RCC_AHB2ENR, Copy_u8Per);
                break;
        case  RCC_APB1 :
            SET_BIT(RCC_APB1ENR, Copy_u8Per);
                break;
        case  RCC_APB2 :
            SET_BIT(RCC_APB2ENR, Copy_u8Per);
                break;

        }
    }
    else
    {
        //out of range
    }
}

void RCC_voidDisablePerClk(u8 Copy_u8Bus, u8 Copy_u8Per)
{
    //RangeCheck
    if(Copy_u8Per<PerRange)
    {
        switch(Copy_u8Bus)
        {
        case  RCC_AHB1 :
            CLR_BIT(RCC_AHB1ENR, Copy_u8Per);
                break;
        case  RCC_AHB2 :
            CLR_BIT(RCC_AHB2ENR, Copy_u8Per);
                break;
        case  RCC_APB1 :
            CLR_BIT(RCC_APB1ENR, Copy_u8Per);
                break;
        case  RCC_APB2 :
            CLR_BIT(RCC_APB2ENR, Copy_u8Per);
                break;

        }
    }
    else
    {
        //out of range
    }
}
