//
// Created by azarai on 11/09/24.
//

#ifndef ARM_CONTROL_H
#define ARM_CONTROL_H

#include "main.h"

// Configurations of the arms
//    -----------------------------
//    |  SE | PIN | Timer_Channel |
//    -----------------------------
//    | SE1 | PC6 |    TIM8_CH1   |
//    | SE2 | PC7 |    TIM8_CH2   |
//    | SE3 | PC8 |    TIM8_CH3   |
//    | SE4 | PC9 |    TIM8_CH4   |
//    -----------------------------
//    Arm1 : SE1, SE2
//    Arm2 : SE3, SE4
//
//    timer frequency : 72MHz
//    PSC = 720-1     ARR = 1000-1
//    PWM frequency : 100Hz  --> 10ms
//
//    Tables for steering engine's degree settings
//    -------------------------------------------------
//    |  degree | Compare Value | PWM |  signal time  |
//    -------------------------------------------------
//    |   0 deg |       50      |  5% |     0.5ms     |
//    |  45 deg |      100      | 10% |       1ms     |
//    |  90 deg |      150      | 15% |     1.5ms     |
//    | 135 deg |      200      | 20% |       2ms     |
//    | 180 deg |      250      | 25% |     2.5ms     |
//    -------------------------------------------------

// Type Declarations
typedef struct _SE {
  TIM_HandleTypeDef *timer;
  uint32_t channel;
} SE;

typedef struct _Arm {
  SE *se1;
  SE *se2;
} Arm;

// Variables needed
extern TIM_HandleTypeDef htim8;
extern SE se[4];
extern Arm arm[2];

// Functions provided
void Az_SE_SetDegree(SE se, uint32_t degree);

void Az_Arm_Init(void);
void Az_Arm_SetPosture(Arm a, uint32_t deg1, uint32_t deg2);
void Az_Arm_SetDefaultDegree(Arm a);
void Az_Arm_Grab(Arm *a);

#endif  // ARM_CONTROL_H
