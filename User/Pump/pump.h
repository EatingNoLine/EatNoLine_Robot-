//
// Created by azarai on 8/15/24.
//

#ifndef PUMP_H
#define PUMP_H

#include "stm32f4xx_hal.h"

typedef enum {
  PUMP_STATE_ON,
  PUMP_STATE_OFF
} Pump_State;

typedef struct {
  GPIO_TypeDef *port;
  uint32_t pin;
  Pump_State state;
} Pump_TypeDef;

void Pump_Init(Pump_TypeDef *pmp, GPIO_TypeDef *port, uint32_t pin);
void Pump_On(Pump_TypeDef *pmp);
void Pump_Off(Pump_TypeDef *pmp);
void Pump_Toggle(Pump_TypeDef *pmp);

#endif //PUMP_H
