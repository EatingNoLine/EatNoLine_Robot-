//
// Created by azarai on 11/09/24.
//

#ifndef STEP_CONTROL_H
#define STEP_CONTROL_H

#include <stdbool.h>
#include "main.h"

// Configurations of the step motor
//    ----------------------------
//    | Name   | PIN             |
//    ----------------------------
//    |  ENA   | PE10            |
//    |  DIR   | PE12            |
//    |  PUL   | PF7 (TIM11_CH1) |
//    ----------------------------
//
//    timer frequency : 72MHz
//    PSC : 72-1    ARR : 1000-1
//    PWM frequency : 1kHz

// Type declaration
typedef enum _SM_Direction {
  SM_Forward, SM_Backward
} SM_Direction;

typedef struct _SM {
  GPIO_TypeDef *port_ena;
  uint32_t pin_ena;

  GPIO_TypeDef *port_dir;
  uint32_t pin_dir;

  TIM_HandleTypeDef *timer;
  uint32_t channel;

  bool is_run;
  uint32_t count;
  uint32_t maxCount;
} SM;

// Variables needed
extern TIM_HandleTypeDef htim11;
extern SM sm;

// Functions provided
void Az_Step_Init(void);
void Az_Step_SetDirection(SM_Direction dir);
void Az_Step_Run(uint32_t count);
void Az_Step_UpdateCount(void);
void Az_Step_Upload(void);


#endif //STEP_CONTROL_H
