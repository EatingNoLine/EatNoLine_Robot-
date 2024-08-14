//
// Created by azarai on 8/2/24.
//

#include "steering_engine.h"

void SE_Init(SE_TypeDef* se, TIM_HandleTypeDef* timer, uint32_t channel,
             double default_degree, double min_degree, double max_degree) {
  // Set up the se instance
  se->timer = timer;
  se->timer_channel = channel;

  // Set se's degree boundery
  se->max_degree = max_degree;
  se->min_degree = min_degree;

  // Set the degree to default degree
  se->degree = default_degree;
  SE_Rotate(se, default_degree);
  // Activate the timer
  HAL_TIM_PWM_Start(timer, channel);
}

void SE_Rotate(SE_TypeDef* se, double degree) {
  if (degree >= se->min_degree && degree <= se->max_degree) {
    se->degree = degree;
    __HAL_TIM_SetCompare(se->timer, se->timer_channel,
                         (uint16_t)(se->degree / 180 * 200) + 50);
  }
}
