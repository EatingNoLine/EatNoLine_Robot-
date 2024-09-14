//
// Created by azarai on 13/09/24.
//

#include "pid.h"

#include <string.h>

PID pid;

void PID_Init(const double P, const double I, const double D,
              const double max_integral, const double max_output) {
  // Set the PID basic value
  pid.Kp = P;
  pid.Ki = I;
  pid.Kd = D;

  pid.target = 0;
  pid.output = 0;
  // Set the limits of values
  pid.max_integral = max_integral;
  pid.max_output = max_output;
  // Clean errors
  memset(pid.error, 0x00, sizeof(double) * 3);
}

void PID_Clear(void) {
  pid.target = 0;
  pid.output = 0;
  pid.max_integral = 0;
  pid.max_output = 0;
}
