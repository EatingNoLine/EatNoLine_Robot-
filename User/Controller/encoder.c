//
// Created by azarai on 31/08/24.
//

#include "encoder.h"

void Encoder_Init(Encoder_TypeDef *encoder, TIM_HandleTypeDef *timer,
                  uint32_t channel, uint32_t maxCount, uint32_t PPR) {
  // initialize timer
  encoder->timer = timer;
  encoder->channel = channel;
  HAL_TIM_Encoder_Start(timer, channel);
  // initialize counter and loop for overflow
  encoder->count = 0;
  encoder->maxCount = maxCount;
  encoder->loop = 0;
  encoder->PPR = PPR;
}

uint32_t Encoder_GetCount(Encoder_TypeDef *encoder) {
  // get count cache
  uint32_t count = __HAL_TIM_GetCounter(encoder->timer);
  count += encoder->loop * encoder->maxCount;
  encoder->count = count;

  // clear count cache
  __HAL_TIM_SetCounter(encoder->timer, 0);
  encoder->loop = 0;

  return count;
}