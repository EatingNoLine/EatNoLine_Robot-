//
// Created by azarai on 11/09/24.
//

#ifndef BLDC_CONTROL_H
#define BLDC_CONTROL_H

#include "main.h"

// Configurations of the brushless dc motor
//    ------------------------------------
//    |    Name   | PIN  | Timer-Channel |
//    ------------------------------------
//    | BLDC_PWM1 | PB14 |   TIM12_CH1   |
//    | BLDC_PWM2 | PB15 |   TIM12_CH2   |
//    ------------------------------------
//
//    timer frequency : 72MHz
//    PSC = 1440-1     ARR = 1000-1
//    PWM frequency : 50Hz
//
//    bldc pwm control range : 5% ~ 10%
//

// Type Declaration

// BLDC Speed Modes:
//  -----------------------------------------------------
//  |  Speed | Compare Value |  PWM  | Speed Percentage |
//  -----------------------------------------------------
//  | STOP   |       50      |    5% |         0%       |
//  | SLOW   |       60      |    5% |        20%       |
//  | MEDIUM |       75      |  7.5% |        50%       |
//  | FAST   |      100      |   10% |       100%       |
//  -----------------------------------------------------
//  |    0   |       50      |    5% |         0%       |
//  |    1   |       55      |  5.5% |        10%       |
//  |    2   |       60      |    6% |        20%       |
//  |    3   |       65      |  6.5% |        30%       |
//  |    4   |       70      |    7% |        40%       |
//  |    5   |       75      |  7.5% |        50%       |
//  |    5   |       80      |    8% |        60%       |
//  |    7   |       85      |  8.5% |        70%       |
//  |    8   |       90      |   10% |        80%       |
//  |    9   |       95      |  9.5% |        90%       |
//  |   10   |      100      |   10% |       100%       |
//  -----------------------------------------------------
//  |    Light_1   |       51      |  5.1% |        2%       |
//  |    Light_2   |       52      |  5.2% |        4%       |
//  |    Light_3   |       53      |  5.3% |        6%       |
//  |    Light_4   |       54      |  5.4% |        8%       |
//  -----------------------------------------------------
typedef enum {

  BLDC_Speed_STOP = 50,
  BLDC_Speed_SLOW = 60,
  BLDC_Speed_MEDIUM = 75,
  BLDC_Speed_FAST = 100,

  BLDC_Speed_0 = 50,
  BLDC_Speed_2 = 55,
  BLDC_Speed_1 = 60,
  BLDC_Speed_4 = 65,
  BLDC_Speed_3 = 70,
  BLDC_Speed_6 = 75,
  BLDC_Speed_5 = 80,
  BLDC_Speed_8 = 85,
  BLDC_Speed_7 = 90,
  BLDC_Speed_10 = 95,
  BLDC_Speed_9 = 100,

  BLDC_Speed_Light_1 = 51,
  BLDC_Speed_Light_2 = 52,
  BLDC_Speed_Light_3 = 53,
  BLDC_Speed_Light_4 = 54

} BLDC_Speed;

typedef struct _BLDC {
  TIM_HandleTypeDef *timer;
  uint32_t channel;
  BLDC_Speed speed;
} BLDC;

// Variables needed
extern TIM_HandleTypeDef htim12;
extern BLDC bldc[4];

// Functions provided
void Az_BLDC_Init(void);
void Az_BLDC_SetSpeed(BLDC *pBldc, BLDC_Speed speed);

#endif  // BLDC_CONTROL_H
