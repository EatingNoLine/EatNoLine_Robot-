//
// Created by azarai on 8/2/24.
//

#ifndef STEERING_ENGINE_H
#define STEERING_ENGINE_H

#include "stm32f4xx_hal.h"

typedef struct {
    TIM_HandleTypeDef *timer;
    uint32_t timer_channel;
    double degree;
    double max_degree;
    double min_degree;
} SE_TypeDef;

void SE_Init(SE_TypeDef *se, TIM_HandleTypeDef *timer, uint32_t channel, double default_degree, double min_degree, double max_degree);
void SE_Rotate(SE_TypeDef *se, double degree);


#endif //STEERING_ENGINE_H
