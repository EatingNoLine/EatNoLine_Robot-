//
// Created by azarai on 11/09/24.
//

#include "step_control.h"

SM sm;

void Az_Step_Init(void) {
  // Basic settings
  sm.count = 0;
  sm.maxCount = 72;
  sm.is_run = false;
  Az_Step_SetDirection(SM_Forward);

  sm.timer = &htim11;
  sm.channel = TIM_CHANNEL_1;

  sm.port_ena = SM_ENA_GPIO_Port;
  sm.port_dir = SM_DIR_GPIO_Port;

  sm.pin_ena = SM_ENA_Pin;
  sm.pin_dir = SM_DIR_Pin;

  // Start Interrupts
  __HAL_TIM_SetCompare(sm.timer, sm.channel, 50);
  HAL_TIM_Base_Start_IT(sm.timer);
}

void Az_Step_SetDirection(SM_Direction dir) {
  if (dir == SM_Forward) {
    HAL_GPIO_WritePin(sm.port_dir, sm.pin_dir, GPIO_PIN_SET);
  } else {
    HAL_GPIO_WritePin(sm.port_dir, sm.pin_dir, GPIO_PIN_RESET);
  }
}

void Az_Step_Run(uint32_t count) {
  // wait for next run command
  while (sm.is_run) ;

  HAL_TIM_PWM_Start(sm.timer, sm.channel);
  sm.maxCount = count;
  sm.is_run = true;
}

void Az_Step_UpdateCount(void) {
  if (sm.count < sm.maxCount) {
    sm.count += 1;
  } else {
    sm.count = 0;
    sm.is_run = false;
    HAL_TIM_PWM_Stop(sm.timer, sm.channel);
  }
}

void Az_Step_Upload(void) {
  Az_Step_Run(720);
}
