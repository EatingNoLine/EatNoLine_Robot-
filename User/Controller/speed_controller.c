//
// Created by azarai on 30/08/24.
//

#include "speed_controller.h"

#include <stdio.h>

void SpeedController_Init(SpeedController_TypeDef *controller,
                          DM_Typedef *motor, Encoder_TypeDef *encoder,
                          PID_TypeDef *pid) {
  // basic setttings
  controller->motor = motor;
  controller->encoder = encoder;
  controller->pid = pid;

  // set default speed and target to 0
  controller->speed = 0;
  controller->target = 0;

  controller->is_initialized = true;
}

void SpeedController_SetTargetSpeed(SpeedController_TypeDef *controller,
                                    double speed) {
  controller->target = speed;
  // uint32_t output = speed
}

void SpeedController_SetTargetCount(SpeedController_TypeDef *controller,
                                     uint32_t count) {
  controller->target = count;
}

double SpeedController_GetSpeed(SpeedController_TypeDef *controller) {
  controller->speed =
      (double)controller->encoder->count /
      (controller->encoder->PPR * controller->motor->reduction_ratio);
  return controller->speed;
}

void SpeedController_UpdateOutput(SpeedController_TypeDef *controller) {
  // get counts in this pieriod and set encoder counter to 0, and then calculate
  // correct output for given target count
  PID_SingleCalc(controller->pid, controller->target,
                 Encoder_GetCount(controller->encoder));
  // set output into motor's control
  // printf("Current Output is %lf\n", controller->pid->output);
  DM_SetOutput_Number(controller->motor, controller->pid->output);
}
