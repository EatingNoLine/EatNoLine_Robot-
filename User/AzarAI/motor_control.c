//
// Created by azarai on 11/09/24.
//

#include "motor_control.h"

DM dm[4];

void Az_Motor_Init(void) {
  dm[0].timer = &htim9;
  dm[1].timer = &htim9;
  dm[2].timer = &htim5;
  dm[3].timer = &htim5;

  dm[0].channel = TIM_CHANNEL_1;
  dm[1].channel = TIM_CHANNEL_2;
  dm[2].channel = TIM_CHANNEL_3;
  dm[3].channel = TIM_CHANNEL_4;

  dm[0].port_a = M_INA_3_GPIO_Port;
  dm[1].port_a = M_INA_4_GPIO_Port;
  dm[2].port_a = M_INA_1_GPIO_Port;
  dm[3].port_a = M_INA_2_GPIO_Port;

  dm[0].port_b = M_INB_3_GPIO_Port;
  dm[1].port_b = M_INB_4_GPIO_Port;
  dm[2].port_b = M_INB_1_GPIO_Port;
  dm[3].port_b = M_INB_2_GPIO_Port;

  dm[0].pin_a = M_INA_3_Pin;
  dm[1].pin_a = M_INA_4_Pin;
  dm[2].pin_a = M_INA_1_Pin;
  dm[3].pin_a = M_INA_2_Pin;

  dm[0].pin_b = M_INB_3_Pin;
  dm[1].pin_b = M_INB_4_Pin;
  dm[2].pin_b = M_INB_1_Pin;
  dm[3].pin_b = M_INB_2_Pin;

  dm[0].direction = DM_Forward;
  dm[1].direction = DM_Backward;
  dm[2].direction = DM_Forward;
  dm[3].direction = DM_Backward;

  for (int i = 0; i < 4; ++i) {
    // setting basic data
    dm[i].output = 0;

    // setting gpio pins
    __HAL_TIM_SetCompare(dm[i].timer, dm[i].channel, 0);
    HAL_TIM_PWM_Start(dm[i].timer, dm[i].channel);
    HAL_GPIO_WritePin(dm[i].port_a, dm[i].pin_a, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(dm[i].port_b, dm[i].pin_b, GPIO_PIN_RESET);
  }
}

void Az_Motor_SetSpeed(DM *pDm, double percentage) {
  // limit output
  if (percentage > 1.0) percentage = 1.0;

  Az_Motor_SetOutput(pDm, (uint32_t)(percentage * 1000));
}

void Az_Motor_SetDirection(DM *pDm, DM_Direction dir) {
  pDm->direction = dir;
  if (pDm->output != 0) {
    if (pDm->direction == DM_Forward) {
      HAL_GPIO_WritePin(pDm->port_a, pDm->pin_a, GPIO_PIN_SET);
      HAL_GPIO_WritePin(pDm->port_b, pDm->pin_b, GPIO_PIN_RESET);
    } else if (pDm->direction == DM_Backward){
      HAL_GPIO_WritePin(pDm->port_a, pDm->pin_a, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(pDm->port_b, pDm->pin_b, GPIO_PIN_SET);
    }
  }
}

void Az_Motor_SetOutput(DM *pDm, uint32_t output) {
  // limit output
  if (output > 999) output = 999;

  if (output == 0) {
    // Stop the motor
    pDm->output = 0;
    __HAL_TIM_SetCompare(pDm->timer, pDm->channel, output);
    HAL_GPIO_WritePin(pDm->port_a, pDm->pin_a, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pDm->port_b, pDm->pin_b, GPIO_PIN_RESET);
  } else {
    // Run the motor
    pDm->output = output;
    if (pDm->direction == DM_Forward) {
      // SM_Forward
      __HAL_TIM_SetCompare(pDm->timer, pDm->channel, output);
      HAL_GPIO_WritePin(pDm->port_a, pDm->pin_a, GPIO_PIN_SET);
      HAL_GPIO_WritePin(pDm->port_b, pDm->pin_b, GPIO_PIN_RESET);
    } else {
      // Backward
      __HAL_TIM_SetCompare(pDm->timer, pDm->channel, output);
      HAL_GPIO_WritePin(pDm->port_a, pDm->pin_a, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(pDm->port_b, pDm->pin_b, GPIO_PIN_SET);
    }
  }
}

void Az_Motor_Stop(void) {
  for (int i = 0; i < 4; ++i) {
    Az_Motor_SetOutput(&dm[i], 0);
  }
}