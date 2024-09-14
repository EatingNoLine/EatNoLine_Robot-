//
// Created by azarai on 13/09/24.
//

#ifndef PID_H
#define PID_H

#define LIMIT(x, min, max) \
  (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))
#define LIMIT_ABS(x, max) LIMIT((x), -fabs(max), fabs(max))

// Algorithm principle of PID
//
//  P - Proportion    - Increase the sensitivity of the system to errors
//  I - Integral      - Eliminate of static errors
//  D - Derivativeal  - Reduces system overshoot and improves system dynamic
//  response
//
//    Positional PID:
//        Output = Kp*e(k) + Ki*\sum{e(k)} + Kd*[e(k)-e(k-1)]
//
//    Increasal PID:
//        Output = Kp*[e(k)-e(k-1)] + Ki*e(k) + Kd*[e(k)-2e(k-1)+e(k-2)]

// Type Declaration
typedef struct _PID {
  double Kp, Ki, Kd;
  double target;
  double error[3];  // e[0] -> e(k), e[1] -> e(k-1), e[2] -> e(k-2)
  double output;
  double max_integral, max_output;
} PID;

// Variables needed
extern PID pid;

// Functions provided
void PID_Init(const double P, const double I, const double D,
              const double max_integral, const double max_output);
void PID_Clear(void);

#endif  // PID_H
