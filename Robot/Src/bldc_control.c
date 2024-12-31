//
// Created by azarai on 11/09/24.
//

#include "bldc_control.h"

BLDC bldc[4];

void BLDC_Init(void) {
  // BLDC1
  bldc[0].timer = &htim12;
  bldc[0].channel = TIM_CHANNEL_1;

  // BLDC2
  bldc[1].timer = &htim12;
  bldc[1].channel = TIM_CHANNEL_2;

  // set speed to lowest (0)
  BLDC_SetSpeed(&bldc[0], BLDC_Speed_STOP);
  BLDC_SetSpeed(&bldc[1], BLDC_Speed_STOP);

  // Start timer
  HAL_TIM_PWM_Start(bldc[0].timer, bldc[0].channel);
  HAL_TIM_PWM_Start(bldc[1].timer, bldc[1].channel);
}

void BLDC_SetSpeed(BLDC *pBldc, BLDC_Speed speed) {
  pBldc->speed = speed;
  __HAL_TIM_SetCompare(pBldc->timer, pBldc->channel, pBldc->speed);
}
