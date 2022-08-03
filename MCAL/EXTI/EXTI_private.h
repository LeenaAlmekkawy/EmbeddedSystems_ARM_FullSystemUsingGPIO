#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADD   (u32)(0x40013C00)

#define EXTI_IMR       *( (volatile u32*)( (EXTI_BASE_ADD) + 0x00) )
#define EXTI_EMR       *( (volatile u32*)( (EXTI_BASE_ADD) + 0x04) )
#define EXTI_RTSR      *( (volatile u32*)( (EXTI_BASE_ADD) + 0x08) )
#define EXTI_FTSR      *( (volatile u32*)( (EXTI_BASE_ADD) + 0x0C) )

#define EXTI_SWIER     *( (volatile u32*)( (EXTI_BASE_ADD) + 0x10) )
#define EXTI_PR        *( (volatile u32*)( (EXTI_BASE_ADD) + 0x14) )




#endif
