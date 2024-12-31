//
// Created by azarai on 11/09/24.
//

#include "arm_control.h"
#include "pump_control.h"
#include "bldc_control.h"
#include "step_control.h"

SE se[4];
Arm arm[2];

void Arm_Init(void) {
  // Initialize the steering engines
  se[0].timer = &htim8;
  se[1].timer = &htim8;
  se[2].timer = &htim8;
  se[3].timer = &htim8;

  se[0].channel = TIM_CHANNEL_1;
  se[1].channel = TIM_CHANNEL_2;
  se[2].channel = TIM_CHANNEL_3;
  se[3].channel = TIM_CHANNEL_4;

  // Initialize the arms
  arm[0].se1 = &se[0];
  arm[0].se2 = &se[1];
  arm[1].se1 = &se[2];
  arm[1].se2 = &se[3];

  // Set up the timer's degree
  Arm_SetDefaultDegree(arm[0]);
  Arm_SetDefaultDegree(arm[1]);

  // Start timer
  HAL_TIM_PWM_Start(arm[0].se1->timer, arm[0].se1->channel);
  HAL_TIM_PWM_Start(arm[0].se2->timer, arm[0].se2->channel);
  HAL_TIM_PWM_Start(arm[1].se1->timer, arm[1].se1->channel);
  HAL_TIM_PWM_Start(arm[1].se2->timer, arm[1].se2->channel);
}

void SE_SetDegree(const SE se, uint32_t degree) {
  // Limit degree within 180
  if (degree > 180) degree = 180;
  // Calculate the degree
  const uint32_t compare = (uint32_t)((double)degree * 10 / 9 + 50);
  // Change PWM duty
  __HAL_TIM_SetCompare(se.timer, se.channel, compare);
}

void Arm_SetPosture(const Arm a, const uint32_t deg1, const uint32_t deg2) {
  SE_SetDegree(*(a.se1), deg1);
  SE_SetDegree(*(a.se2), deg2);
}

void Arm_SetDefaultDegree(const Arm a) {
  static uint32_t deg1 = 90;
  static uint32_t deg2 = 90;

  SE_SetDegree(*a.se1, deg1);
  SE_SetDegree(*a.se2, deg2);
}

void Arm_Grab(Arm *a) {
  bool side = (a == &arm[0]);

  // Arm
  Arm_SetPosture(*a, 13, 0);
  Pump_Open(&pump[side ? 0 : 1]);
  HAL_Delay(2000);

  Arm_SetPosture(*a, 109, 0);
  HAL_Delay(300);
  Arm_SetPosture(*a, 109, 175);
  HAL_Delay(1700);

  // Arm_SetPosture(*a, 109, 175);
  // HAL_Delay(2000);

  Pump_Close(&pump[side ? 0 : 1]);
  HAL_Delay(500);
  Arm_SetDefaultDegree(*a);
}
