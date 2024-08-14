//
// Created by azarai on 8/2/24.
//

#ifndef ARM_H
#define ARM_H

#include "stm32f4xx_hal.h"
#include "steering_engine.h"

typedef struct {
    SE_TypeDef *se1;
    SE_TypeDef *se2;
} Arm_TypeDef;

void Arm_Init(Arm_TypeDef *arm, SE_TypeDef *se1, SE_TypeDef *se2);
void Arm_SetGesgure(Arm_TypeDef *arm, double degree1, double degree2);

#endif //ARM_H
