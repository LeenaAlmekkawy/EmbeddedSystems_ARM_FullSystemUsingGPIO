#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"SSD_interface.h"
#include"LCD_interface.h"
#include"KPD_interface.h"
#include"TIMER_interface.h"

int main(void)
{
    RCC_voidSystemClkInit();
    RCC_voidEnablePerClk(RCC_AHB1,0);
    RCC_voidEnablePerClk(RCC_AHB1,1);
    RCC_voidEnablePerClk(RCC_AHB1,2);
    PIN_st PinOut= {OUTPUT,PP,VHS,NPP};
    // PIN_st PinIN= {INPUT,PP,VHS,PU};
    KPD_voidInit();
    LCD_voidInit();

    SSD_st SSD1 = {PORTB,PIN10,PIN12,PIN13,PIN14,PIN15,PIN8,PIN9,PIN9,COMMON_ANODE};
    SSD_voidInit(&SSD1);
    GPIO_voidSetPinDirection (PORTA, PIN10, &PinOut);
    GPIO_voidSetPinDirection (PORTA, PIN11, &PinOut);
    GPIO_voidSetPinDirection (PORTA, PIN12, &PinOut);
    GPIO_voidSetPinDirection (PORTA, PIN0, &PinOut);
    GPIO_voidSetPinDirection (PORTA, PIN1, &PinOut);


    for(u8 j=10; j<=15; j++)
    {
        GPIO_voidSetPinValue(PORTB,j, HIGH);
    }
    for(u8 j=8; j<=9; j++)
    {
        GPIO_voidSetPinValue(PORTA,j, HIGH);
    }


    u8 Local_u8Pressedkey=0xAA;
    u8 flag0=0;
    u8 flag1=0;
    u8 flag2=0;
    u8 flag3=0;
    u8 flag4=0;
    u8 flag5=0;
    u8 flag6=0;




    while(1)
    {
        do
        {
            Local_u8Pressedkey=KPB_u8GetPressedKey();
        }
        while( Local_u8Pressedkey==0xAA);



        if (Local_u8Pressedkey==15&&flag0==0)
        {
            Local_u8Pressedkey=0xAA;

            LCD_voidClear();

            LCD_voidGoToXY(0,3);
            LCD_voidSendString("WELCOME :)");
            _delay_ms(3000);

            flag0=1;
            LCD_voidClear();
            LCD_voidGoToXY(0,0);
            LCD_voidSendString("0 to 9: 7seg ON");
            LCD_voidGoToXY(1,0);
            LCD_voidSendString("10: 3 LEDs ON");
            _delay_ms(3000);
            LCD_voidClear();
            LCD_voidGoToXY(0,0);
            LCD_voidSendString("11: Buzzer ON");
            LCD_voidGoToXY(1,0);
            LCD_voidSendString("12:RGB/Blue ON");
            _delay_ms(3000);
            LCD_voidClear();
            LCD_voidGoToXY(0,0);
            LCD_voidSendString("13:RGB/Green ON");
            LCD_voidGoToXY(1,0);
            LCD_voidSendString("14:RGB/Red ON");
            _delay_ms(3000);




        }
        if (Local_u8Pressedkey==15&&flag0==1)
        {
            Local_u8Pressedkey=0xAA;
            LCD_voidClear();
            LCD_voidGoToXY(0,3);
            LCD_voidSendString("Thank you");
            _delay_ms(2000);
            LCD_voidClear();
            GPIO_voidSetPinValue(PORTB,10, HIGH);
            for(u8 j=12; j<=15; j++)
            {
                GPIO_voidSetPinValue(PORTB,j, HIGH);
            }
            for(u8 j=8; j<=9; j++)
            {
                GPIO_voidSetPinValue(PORTA,j, HIGH);
            }
            GPIO_voidSetPinValue (PORTA,PIN10,LOW);
            GPIO_voidSetPinValue (PORTA,PIN11,LOW);
            GPIO_voidSetPinValue (PORTA,PIN12,LOW);
            flag0=0;
            flag1=0;
            flag2=0;
            flag3=0;
            flag4=0;
            flag5=0;
            flag6=0;

        }
        ///---------------------

        if ((Local_u8Pressedkey==0||
                Local_u8Pressedkey==1||Local_u8Pressedkey==2
                ||Local_u8Pressedkey==3 ||Local_u8Pressedkey==4
                ||Local_u8Pressedkey==5||Local_u8Pressedkey==6
                ||Local_u8Pressedkey==7||Local_u8Pressedkey==8
                ||Local_u8Pressedkey==9)&&flag1==0)

        {
            u8 num=Local_u8Pressedkey;
            Local_u8Pressedkey=0xAA;
            SSD_voidSetNumber(num,&SSD1 );

            flag1=1;


        }
        if ((Local_u8Pressedkey==0||
                Local_u8Pressedkey==1||Local_u8Pressedkey==2
                ||Local_u8Pressedkey==3 ||Local_u8Pressedkey==4
                ||Local_u8Pressedkey==5||Local_u8Pressedkey==6
                ||Local_u8Pressedkey==7||Local_u8Pressedkey==8
                ||Local_u8Pressedkey==9)&&flag1==1)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue(PORTB,10, HIGH);
            for(u8 j=12; j<=15; j++)
            {
                GPIO_voidSetPinValue(PORTB,j, HIGH);
            }
            for(u8 j=8; j<=9; j++)
            {
                GPIO_voidSetPinValue(PORTA,j, HIGH);
            }

            flag1=0;

        }
        //--------------------------------------------
        if (Local_u8Pressedkey==10&&flag2==0)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN10,HIGH);
            flag2=1;
        }
        if (Local_u8Pressedkey==10&&flag2==1)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN10,LOW);
            flag2=0;

        }
        //------------------
        if (Local_u8Pressedkey==11&&flag3==0)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN11,HIGH);
            flag3=1;
        }
        if (Local_u8Pressedkey==11&&flag3==1)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN11,LOW);
            flag3=0;

        }
        //--------------------
        if (Local_u8Pressedkey==12&&flag4==0)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN12,HIGH);
            flag4=1;
        }
        if (Local_u8Pressedkey==12&&flag4==1)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN12,LOW);
            flag4=0;

        }
        if (Local_u8Pressedkey==13&&flag5==0)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN0,HIGH);
            flag5=1;
        }
        if (Local_u8Pressedkey==13&&flag5==1)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN0,LOW);
            flag5=0;

        }
        if (Local_u8Pressedkey==14&&flag6==0)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN1,HIGH);
            flag6=1;
        }
        if (Local_u8Pressedkey==14&&flag6==1)
        {
            Local_u8Pressedkey=0xAA;
            GPIO_voidSetPinValue (PORTA,PIN1,LOW);
            flag6=0;

        }



    }
    return 0;
}
