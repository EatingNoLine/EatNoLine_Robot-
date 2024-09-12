//
// Created by azarai on 11/09/24.
//

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "main.h"

//    Pinouts Configurations of Motors
//    ---------------------------------------------------------
//    | Name  |  Timer (Pin)  |   INA |  INB  | Enc_1 | Enc_2 |
//    ---------------------------------------------------------
//    |   M1  |   T9C1 (PE5)  |  PF11 |  PF3  | Enc_1 | Enc_2 |
//    |   M2  |   T9C2 (PE6)  |  PF12 |  PF4  | Enc_1 | Enc_2 |
//    |   M3  |   T5C3 (PA2)  |   PC4 |  PF1  | Enc_1 | Enc_2 |
//    |   M4  |   T5C4 (PA3)  |   PC5 |  PF2  | Enc_1 | Enc_2 |
//    ---------------------------------------------------------
//
//    Timer for update speed : TIM13 -- 10 ms
//
//    timer frequency : 72MHz
//    PSC = 1440-1    ARR = 1000-1
//    PWM frequency : 50Hz

// Type Declarations
typedef enum _DM_Direction{
  DM_Forward, DM_Backward
} DM_Direction;

typedef struct _DM{
  TIM_HandleTypeDef *timer;
  uint32_t channel;
  GPIO_TypeDef *port_a;
  uint16_t pin_a;
  GPIO_TypeDef *port_b;
  uint16_t pin_b;

  uint32_t output;
  DM_Direction direction;
} DM;

// Variables needed
extern TIM_HandleTypeDef htim5, htim9;
extern DM dm[4];

// Functions provided
void Az_Motor_Init(void);
void Az_Motor_SetDirection(DM *pDm, DM_Direction dir);
void Az_Motor_SetSpeed(DM *pDm, double percentage);
void Az_Motor_SetOutput(DM *pDm, uint32_t output);
void Az_Motor_Stop(void);

#endif //MOTOR_CONTROL_H
