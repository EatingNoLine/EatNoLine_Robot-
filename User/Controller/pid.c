//
// Created by azarai on 30/08/24.
//

#include "pid.h"

void PID_Init(PID_TypeDef *pid, double kP, double kI, double kD, double maxIntegeral, double maxOutput) {
  pid->kP = kP;
  pid->kI = kI;
  pid->kD = kD;

  pid->maxIntegral = maxIntegeral;
  pid->maxOutput = maxOutput;

}

void PID_Clear(PID_TypeDef *pid) {
  pid->error = 0;
  pid->lastError = 0;
  pid->integral = 0;
  pid->output = 0;
}

void PID_SingleCalc(PID_TypeDef *pid, double dest, double current) {
  // update data
  pid->lastError=pid->error;
  pid->error = dest - current;

  // calculate differential
  pid->output = pid->kD * (pid->error - pid->lastError);
  // calculate portion
  pid->output += pid->kP * pid->error;

  // calculate integral within limits
  pid->integral += pid->kI * pid->error;
  pid->integral = ABS_LIMIT(pid->integral , pid->maxIntegral);
  pid->output += pid->integral;

  // assign output within limits
  pid->output = ABS_LIMIT(pid->output , pid->maxOutput);
}