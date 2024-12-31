//
// Created by azarai on 11/09/24.
//

#ifndef STEP_CONTROL_H
#define STEP_CONTROL_H

#include "main.h"

#include <stdbool.h>

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
  // Timer for generating pulses
  TIM_HandleTypeDef *timer;
  uint32_t channel;
  // Enable pin
  GPIO_TypeDef *port_ena;
  uint32_t pin_ena;
  // Direction pin
  GPIO_TypeDef *port_dir;
  uint32_t pin_dir;
  // Data for pulse generating
  bool is_run;
  uint32_t count;
  uint32_t maxCount;
} SM;

// Extern global variables
extern TIM_HandleTypeDef htim11;

// Global variables
extern SM sm;
extern bool isStepInited;

// Functions provided
void Step_Init(void);
void Step_SetDirection(SM_Direction dir);
void Step_Run(uint32_t count);
void Step_UpdateCount(void);
void Step_Upload(void);


#endif //STEP_CONTROL_H
