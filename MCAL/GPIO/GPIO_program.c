#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void GPIO_voidSetPinDirection (u8 Copy_u8PortName, u8 Copy_u8PinNumber, PIN_st*  Copy_psPinInfo)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        switch( Copy_psPinInfo->PIN_MOD)
        {
        case INPUT:
            CLR_BIT(GPIOA_MODER,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOA_MODER,(Copy_u8PinNumber*2+1));
            break;
        case OUTPUT:
            SET_BIT(GPIOA_MODER,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOA_MODER,(Copy_u8PinNumber*2+1));
            break;
        case AF:
            CLR_BIT(GPIOA_MODER,(Copy_u8PinNumber*2));
            SET_BIT(GPIOA_MODER,(Copy_u8PinNumber*2+1));
            break;
        case ANALOG:
            SET_BIT(GPIOA_MODER,(Copy_u8PinNumber*2));
            SET_BIT(GPIOA_MODER,(Copy_u8PinNumber*2+1));
            break;
        }
        switch( Copy_psPinInfo->PIN_OT)
        {
        case PP:
            CLR_BIT(GPIOA_OTYPER,(Copy_u8PinNumber));
            break;
        case  OD:
            SET_BIT(GPIOA_OTYPER,(Copy_u8PinNumber));
            break;
        }
        switch( Copy_psPinInfo->PIN_SPD)
        {
        case LS:
            CLR_BIT(GPIOA_OSPEEDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOA_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case MS:
            SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOA_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case HS:
            CLR_BIT(GPIOA_OSPEEDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case VHS:
            SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        }
        switch( Copy_psPinInfo->PIN_PUPD)
        {
        case NPP:
            CLR_BIT(GPIOA_PUPDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOA_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        case PU:
            SET_BIT(GPIOA_PUPDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOA_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        case PD:
            CLR_BIT(GPIOA_PUPDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOA_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        }
        break;

    case PORTB:
        switch( Copy_psPinInfo->PIN_MOD)
        {
        case INPUT:
            CLR_BIT(GPIOB_MODER,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOB_MODER,(Copy_u8PinNumber*2+1));
            break;
        case OUTPUT:
            SET_BIT(GPIOB_MODER,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOB_MODER,(Copy_u8PinNumber*2+1));
            break;
        case AF:
            CLR_BIT(GPIOB_MODER,(Copy_u8PinNumber*2));
            SET_BIT(GPIOB_MODER,(Copy_u8PinNumber*2+1));
            break;
        case ANALOG:
            SET_BIT(GPIOB_MODER,(Copy_u8PinNumber*2));
            SET_BIT(GPIOB_MODER,(Copy_u8PinNumber*2+1));
            break;
        }
        switch( Copy_psPinInfo->PIN_OT)
        {
        case PP:
            CLR_BIT(GPIOB_OTYPER,(Copy_u8PinNumber));
            break;
        case  OD:
            SET_BIT(GPIOB_OTYPER,(Copy_u8PinNumber));
            break;
        }
        switch( Copy_psPinInfo->PIN_SPD)
        {
        case LS:
            CLR_BIT(GPIOB_OSPEEDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOB_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case MS:
            SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOB_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case HS:
            CLR_BIT(GPIOB_OSPEEDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case VHS:
            SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        }
        switch( Copy_psPinInfo->PIN_PUPD)
        {
        case NPP:
            CLR_BIT(GPIOB_PUPDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOB_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        case PU:
            SET_BIT(GPIOB_PUPDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOB_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        case PD:
            CLR_BIT(GPIOB_PUPDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOB_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        }

        break;

    case PORTC:
        switch( Copy_psPinInfo->PIN_MOD)
        {
        case INPUT:
            CLR_BIT(GPIOC_MODER,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOC_MODER,(Copy_u8PinNumber*2+1));
            break;
        case OUTPUT:
            SET_BIT(GPIOC_MODER,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOC_MODER,(Copy_u8PinNumber*2+1));
            break;
        case AF:
            CLR_BIT(GPIOC_MODER,(Copy_u8PinNumber*2));
            SET_BIT(GPIOC_MODER,(Copy_u8PinNumber*2+1));
            break;
        case ANALOG:
            SET_BIT(GPIOC_MODER,(Copy_u8PinNumber*2));
            SET_BIT(GPIOC_MODER,(Copy_u8PinNumber*2+1));
            break;
        }
        switch( Copy_psPinInfo->PIN_OT)
        {
        case PP:
            CLR_BIT(GPIOC_OTYPER,(Copy_u8PinNumber));
            break;
        case  OD:
            SET_BIT(GPIOC_OTYPER,(Copy_u8PinNumber));
            break;
        }
        switch( Copy_psPinInfo->PIN_SPD)
        {
        case LS:
            CLR_BIT(GPIOC_OSPEEDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOC_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case MS:
            SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOC_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case HS:
            CLR_BIT(GPIOC_OSPEEDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        case VHS:
            SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinNumber*2+1));
            break;
        }
        switch( Copy_psPinInfo->PIN_PUPD)
        {
        case NPP:
            CLR_BIT(GPIOC_PUPDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOC_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        case PU:
            SET_BIT(GPIOC_PUPDR,(Copy_u8PinNumber*2));
            CLR_BIT(GPIOC_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        case PD:
            CLR_BIT(GPIOC_PUPDR,(Copy_u8PinNumber*2));
            SET_BIT(GPIOC_PUPDR,(Copy_u8PinNumber*2+1));
            break;
        }

        break;
    }
}

void GPIO_voidSetPinValue     (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    if(Copy_u8PortName< PORT_RANGE && Copy_u8PinNumber<PIN_RANGE)
    {
        if(  (Copy_u8PortName==PORTA &&(Copy_u8PinNumber==PIN13||Copy_u8PinNumber==PIN14) ) ||
                (Copy_u8PortName==PORTA &&(Copy_u8PinNumber==PIN13||Copy_u8PinNumber==PIN14) )  )
        {
            //error
        }
        else
        {
            switch(Copy_u8PortName)
            {
            case PORTA:
                switch(Copy_u8PinValue)
                {
                case HIGH:
                    SET_BIT(GPIOA_ODR,Copy_u8PinNumber);

                    break;

                case LOW:
                    CLR_BIT(GPIOA_ODR,Copy_u8PinNumber);

                    break;
                }
                break;

            case PORTB:
                switch(Copy_u8PinValue)
                {
                case HIGH:
                    SET_BIT(GPIOB_ODR,Copy_u8PinNumber);

                    break;

                case LOW:
                    CLR_BIT(GPIOB_ODR,Copy_u8PinNumber);

                    break;
                }
                break;

            case PORTC:
                switch(Copy_u8PinValue)
                {
                case HIGH:
                    SET_BIT(GPIOC_ODR,Copy_u8PinNumber);

                    break;

                case LOW:
                    CLR_BIT(GPIOC_ODR,Copy_u8PinNumber);

                    break;
                }
                break;
            }
        }
    }
    else
    {
        //error
    }
}
u8   GPIO_u8GetPinValue       (u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 Local_Variable=0x55;
    if(Copy_u8PortName< PORT_RANGE && Copy_u8PinNumber<PIN_RANGE)
    {
        if(  (Copy_u8PortName==PORTA &&(Copy_u8PinNumber==PIN13||Copy_u8PinNumber==PIN14) ) ||
                (Copy_u8PortName==PORTA &&(Copy_u8PinNumber==PIN13||Copy_u8PinNumber==PIN14) )  )
        {
            //error
        }
        else
        {
            switch(Copy_u8PortName)
            {
            case PORTA:
                Local_Variable=GET_BIT(GPIOA_IDR,Copy_u8PinNumber);
                break;

            case PORTB:
                Local_Variable=GET_BIT(GPIOB_IDR,Copy_u8PinNumber);
                break;

            case PORTC:
                Local_Variable=GET_BIT(GPIOC_IDR,Copy_u8PinNumber);
                break;
            }
        }
    }
    else
    {
        //error
    }
    return Local_Variable;

}

u32   GPIO_u32GetPortValue      (u8 Copy_u8PortName)
{
    u32 Local_PortValue;
    if(Copy_u8PortName< PORT_RANGE )
    {

        switch(Copy_u8PortName)
        {
        case PORTA:
            Local_PortValue=GPIOA_IDR;
            break;

        case PORTB:
            Local_PortValue=GPIOB_IDR;
            break;

        case PORTC:
            Local_PortValue=GPIOC_IDR;
            break;
        }

    }
    else
    {
        //error
    }
    return Local_PortValue;
}

