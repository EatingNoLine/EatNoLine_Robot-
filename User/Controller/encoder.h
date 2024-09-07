//
// Created by azarai on 31/08/24.
//

#ifndef ENCODER_H
#define ENCODER_H

#include "stm32f4xx_hal.h"

typedef struct {
  TIM_HandleTypeDef *timer;
  uint32_t channel;

  uint32_t count;
  uint32_t maxCount;
  uint32_t loop;

  uint32_t PPR;
} Encoder_TypeDef;

void Encoder_Init(Encoder_TypeDef *encoder, TIM_HandleTypeDef *timer,
                  uint32_t channel, uint32_t maxCount, uint32_t PPR);
uint32_t Encoder_GetCount(Encoder_TypeDef *encoder);

#endif  // ENCODER_H
