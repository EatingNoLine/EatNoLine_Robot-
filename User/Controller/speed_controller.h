//
// Created by azarai on 30/08/24.
//

#ifndef SPEED_CONTROLLER_H
#define SPEED_CONTROLLER_H

#include "dc_motor.h"
#include "encoder.h"
#include "pid.h"
#include "stm32f4xx_hal.h"

typedef struct {
  bool is_initialized;
  DM_Typedef *motor;         // for motor control
  Encoder_TypeDef *encoder;  // for encoder
  PID_TypeDef *pid;          // for calculate pid
  double speed;
  uint32_t target;
} SpeedController_TypeDef;

void SpeedController_Init(SpeedController_TypeDef *controller,
                          DM_Typedef *motor, Encoder_TypeDef *encoder,
                          PID_TypeDef *pid);
void SpeedController_SetTargetSpeed(SpeedController_TypeDef *controller,
                                    double speed);
void SpeedController_SetTargetCount(SpeedController_TypeDef *controller,
                                     uint32_t count);
double SpeedController_GetSpeed(SpeedController_TypeDef *controller);
void SpeedController_UpdateOutput(SpeedController_TypeDef *controller);

#endif  // SPEED_CONTROLLER_H
