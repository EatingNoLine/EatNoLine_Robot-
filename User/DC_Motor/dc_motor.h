//
// Created by azarai on 8/15/24.
//

#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <stdbool.h>

#include "stm32f4xx_hal.h"

typedef enum {
  DM_DIRECTION_FORWARD,
  DM_DIRECTION_BACKWARD
} DM_Direction_State;

typedef struct {
  TIM_HandleTypeDef *timer;
  uint32_t channel;
  GPIO_TypeDef *port_ina;
  uint32_t pin_ina;
  GPIO_TypeDef *port_inb;
  uint32_t pin_inb;

  uint32_t output;
  uint32_t max_output;
  DM_Direction_State direction;
  bool is_run;

  uint32_t reduction_ratio;
} DM_Typedef;

void DM_Init(DM_Typedef *dm, TIM_HandleTypeDef *timer, uint32_t channel,
             GPIO_TypeDef *port_ina, uint32_t pin_ina, GPIO_TypeDef *port_inb,
             uint32_t pin_inb, uint32_t max_output, uint32_t reduction_ratio);
void DM_SetDirection(DM_Typedef *dm, DM_Direction_State direction);
void DM_SetOutput_Number(DM_Typedef *dm, uint32_t output);
void DM_SetOutput_Percentage(DM_Typedef *dm, double persentage);

#endif  // DC_MOTOR_H
