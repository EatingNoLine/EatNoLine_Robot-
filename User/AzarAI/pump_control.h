//
// Created by azarai on 11/09/24.
//

#ifndef PUMP_CONTROL_H
#define PUMP_CONTROL_H

#include <stdbool.h>
#include "main.h"

//   Configurations of the pump controller
//    ----------------
//    | Name  | Pin  |
//    ----------------
//    | PUMP1 | PF13 |
//    | PUMP2 | PF14 |
//    ----------------
//
//    when gpio of pump controller is HIGH-Level, the pump is closed


// Type Declarations
typedef enum _PUMP_State {
  PUMP_OPEN = true,
  PUMP_CLOSE = false
} PUMP_State;

typedef struct _PUMP{
  GPIO_TypeDef *port;
  uint32_t pin;
  bool state;
} PUMP;

// Variables needed
extern PUMP pump[2];

// Functions provided
void Az_Pump_Init(void);
void Az_Pump_Open(PUMP *pump);
void Az_Pump_Close(PUMP *pump);
void Az_Pump_Toggle(PUMP *pump);

#endif //PUMP_CONTROL_H
