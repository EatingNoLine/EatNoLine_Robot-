//
// Created by azarai on 11/09/24.
//

#include "arm_control.h"
#include "pump_control.h"
#include "bldc_control.h"
#include "step_control.h"

SE se[4];
Arm arm[2];

void Az_Arm_Init(void) {
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
  Az_Arm_SetDefaultDegree(arm[0]);
  Az_Arm_SetDefaultDegree(arm[1]);

  // Start timer
  HAL_TIM_PWM_Start(arm[0].se1->timer, arm[0].se1->channel);
  HAL_TIM_PWM_Start(arm[0].se2->timer, arm[0].se2->channel);
  HAL_TIM_PWM_Start(arm[1].se1->timer, arm[1].se1->channel);
  HAL_TIM_PWM_Start(arm[1].se2->timer, arm[1].se2->channel);
}

void Az_SE_SetDegree(const SE se, uint32_t degree) {
  // Limit degree within 180
  if (degree > 180) degree = 180;
  // Calculate the degree
  const uint32_t compare = (uint32_t)((double)degree * 10 / 9 + 50);
  // Change PWM duty
  __HAL_TIM_SetCompare(se.timer, se.channel, compare);
}

void Az_Arm_SetPosture(const Arm a, const uint32_t deg1, const uint32_t deg2) {
  Az_SE_SetDegree(*(a.se1), deg1);
  Az_SE_SetDegree(*(a.se2), deg2);
}

void Az_Arm_SetDefaultDegree(const Arm a) {
  static uint32_t deg1 = 90;
  static uint32_t deg2 = 90;

  Az_SE_SetDegree(*a.se1, deg1);
  Az_SE_SetDegree(*a.se2, deg2);
}

void Az_Arm_Grab(Arm *a) {
  bool side = (a == &arm[0]);

  // Arm
  Az_Arm_SetPosture(*a, 13, 0);
  Az_Pump_Open(&pump[side ? 0 : 1]);
  HAL_Delay(2000);

  Az_BLDC_SetSpeed(&bldc[0], BLDC_Speed_Light_4);
  Az_BLDC_SetSpeed(&bldc[1], BLDC_Speed_Light_4);

  Az_Arm_SetPosture(*a, 113, 160);
  HAL_Delay(2000);

  Az_Pump_Close(&pump[side ? 0 : 1]);
  HAL_Delay(500);
  Az_Arm_SetDefaultDegree(*a);

  // Step Motor
  Az_Step_SetDirection(SM_Backward);
  Az_Step_Run(6000);

  Az_Step_Run(13000);
  Az_Step_SetDirection(SM_Forward);

  Az_Step_Run(7000);
  Az_Step_SetDirection(SM_Backward);

  HAL_Delay(1000);
  Az_BLDC_SetSpeed(&bldc[0], BLDC_Speed_0);
  Az_BLDC_SetSpeed(&bldc[1], BLDC_Speed_0);
}