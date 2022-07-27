#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"SSD_interface.h"
u8 Delay (void)
{
    for(u32 i = 0 ; i<1000000 ; i++ )
    {
        asm("NOP");
    }
    return 0;
}
void SmallDelay (void)
{
    for(u32 s = 0 ; s<2000 ; s++ )
    {
        asm("NOP");
    }
}
int main(void)
{
    RCC_voidSystemClkInit();
    RCC_voidEnablePerClk(RCC_AHB1,0);
    RCC_voidEnablePerClk(RCC_AHB1,1);
    PIN_st pin={OUTPUT,PP,VHS,NPP};




    //  PIN_st pinIN={INPUT,PP,VHS,PU};
         GPIO_voidSetPinDirection(PORTB,PIN0,&pin);
         GPIO_voidSetPinDirection(PORTB,PIN1,&pin);


    SSD_st SSD1 ={PORTA,PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,COMMON_ANODE};
     SSD_voidInit(&SSD1);




    while(1)
    {
        for(int i=0;i<10;i++ )
        {
               for(int j=0;j<500;j++)
               {
                   GPIO_voidSetPinValue(PORTB,PIN0,HIGH);
                   GPIO_voidSetPinValue(PORTB,PIN1,LOW);
                   SSD_voidSetNumber(i, &SSD1);
                   SmallDelay ();
                   GPIO_voidSetPinValue(PORTB,PIN0,LOW);
                   GPIO_voidSetPinValue(PORTB,PIN1,HIGH);
                   SSD_voidSetNumber((10-i-1), &SSD1);
                   SmallDelay ();

               }

        }

    }
    return 0;
}
