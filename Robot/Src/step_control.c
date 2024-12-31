//
// Created by azarai on 11/09/24.
//

#include "step_control.h"

#include <stdio.h>

SM sm;
bool isStepInited = false;

void Step_Init(void) {
  // Timer for generating pulses
  sm.timer = &htim11;
  sm.channel = TIM_CHANNEL_1;
  // Enable pin
  sm.port_ena = SM_ENA_GPIO_Port;
  sm.pin_ena = SM_ENA_Pin;
  // Direction pin
  sm.port_dir = SM_DIR_GPIO_Port;
  sm.pin_dir = SM_DIR_Pin;

  // Data for pulse generating
  sm.is_run = false;
  sm.count = 0;
  sm.maxCount = 72;
  Step_SetDirection(SM_Forward);

  // Start Interrupts
  __HAL_TIM_SetCompare(sm.timer, sm.channel, 50);
  HAL_TIM_Base_Start_IT(sm.timer);

  isStepInited = true;
}

void Step_SetDirection(SM_Direction dir) {
  if (dir == SM_Forward) {
    HAL_GPIO_WritePin(sm.port_dir, sm.pin_dir, GPIO_PIN_SET);
  } else {
    HAL_GPIO_WritePin(sm.port_dir, sm.pin_dir, GPIO_PIN_RESET);
  }
}

void Step_Run(uint32_t count) {
  // wait for next run command
  while (sm.is_run)
    ;

  HAL_TIM_PWM_Start(sm.timer, sm.channel);
  sm.maxCount = count;
  sm.is_run = true;
}

void Step_UpdateCount(void) {
  if (sm.count < sm.maxCount) {
    sm.count += 1;
  } else {
    sm.count = 0;
    sm.is_run = false;
    HAL_TIM_PWM_Stop(sm.timer, sm.channel);
  }
}

void Step_Upload(void) { Step_Run(720); }
