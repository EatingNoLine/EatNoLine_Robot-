//
// Created by azarai on 8/15/24.
//

#include "dc_motor.h"

void DM_Init(DM_Typedef *dm, TIM_HandleTypeDef *timer, uint32_t channel,
             GPIO_TypeDef *port_ina, uint32_t pin_ina, GPIO_TypeDef *port_inb,
             uint32_t pin_inb, uint32_t max_output, uint32_t reduction_ratio) {
  // set up timer
  dm->timer = timer;
  dm->channel = channel;
  DM_SetOutput_Number(dm, 0);
  // set up INA pin
  dm->port_ina = port_ina;
  dm->pin_ina = pin_ina;
  // set up INB pin
  dm->port_inb = port_inb;
  dm->pin_inb = pin_inb;

  dm->reduction_ratio = reduction_ratio;

  // default setting
  dm->output = 0;
  dm->max_output = max_output;
  DM_SetDirection(dm, DM_DIRECTION_FORWARD);
  dm->is_run = false;
}

void DM_SetDirection(DM_Typedef *dm, DM_Direction_State direction) {
  dm->direction = direction;
  if (direction == DM_DIRECTION_FORWARD) {
    HAL_GPIO_WritePin(dm->port_ina, dm->pin_ina, GPIO_PIN_SET);
    HAL_GPIO_WritePin(dm->port_inb, dm->pin_inb, GPIO_PIN_RESET);
  } else {
    HAL_GPIO_WritePin(dm->port_ina, dm->pin_ina, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(dm->port_inb, dm->pin_inb, GPIO_PIN_SET);
  }
}

void DM_SetOutput_Number(DM_Typedef *dm, uint32_t output) {
  if (output >= dm->max_output) {
    dm->output = dm->max_output;
  } else {
    dm->output = output;
  }
  __HAL_TIM_SetCompare(dm->timer, dm->channel, dm->output);
  // turn on/off the pwm timer according to given output
  if (dm->output == 0) {
    dm->is_run = false;
    HAL_GPIO_WritePin(dm->port_ina, dm->pin_ina, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(dm->port_inb, dm->pin_inb, GPIO_PIN_RESET);
    HAL_TIM_PWM_Stop(dm->timer, dm->channel);
  }else {
    dm->is_run = true;
    HAL_TIM_PWM_Start(dm->timer, dm->channel);
  }
}

void DM_SetOutput_Percentage(DM_Typedef *dm, double persentage) {
  uint32_t output;
  if (persentage >= 1.0) {
    output = dm->max_output;
  } else {
    output = (uint32_t)(persentage * dm->max_output);
  }
  DM_SetOutput_Number(dm, output);
}