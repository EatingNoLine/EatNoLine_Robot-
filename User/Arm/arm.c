//
// Created by azarai on 8/2/24.
//

#include "arm.h"

void Arm_Init(Arm_TypeDef *arm, SE_TypeDef *se1, SE_TypeDef *se2) {
    arm->se1 = se1;
    arm->se2 = se2;
}

void Arm_SetGesgure(Arm_TypeDef *arm, double degree1, double degree2) {
    SE_Rotate(arm->se1, degree1);
    SE_Rotate(arm->se2, degree2);
}
