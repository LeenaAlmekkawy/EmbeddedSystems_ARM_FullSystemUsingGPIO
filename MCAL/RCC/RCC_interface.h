#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB1    0
#define RCC_AHB2    1
#define RCC_APB1    2
#define RCC_APB2    3

#define PerRange    32
 
 void RCC_voidSystemClkInit(void);

 void RCC_voidEnablePerClk(u8 Copy_u8Bus, u8 Copy_u8Per);

 void RCC_voidDisablePerClk(u8 Copy_u8Bus, u8 Copy_u8Per);


       
#endif
