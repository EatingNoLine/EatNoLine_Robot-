//
// Created by azarai on 30/08/24.
//

#ifndef PID_H
#define PID_H

#define LIMIT(x, min, max) ((x) < (min)) ? (min) : (((x) > (max)) ? (max) : (x))
#define ABS_LIMIT(x, max) (LIMIT(x, -max, max))

typedef struct {
  double kP, kI, kD;
  double error, lastError;
  double integral, maxIntegral;
  double output, maxOutput;
} PID_TypeDef;

void PID_Init(PID_TypeDef *pid, double P, double I, double D, double maxIntegeral, double maxOutput);
void PID_Clear(PID_TypeDef *pid);

void PID_SingleCalc(PID_TypeDef *pid, double dest, double current);


#endif //PID_H
