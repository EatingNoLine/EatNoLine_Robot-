//
// Created by azarai on 8/15/24.
//

#include "pump.h"

void Pump_Init(Pump_TypeDef *pmp, GPIO_TypeDef *port, uint32_t pin){
  pmp->port = port;
  pmp->pin = pin;

  // Set up state of pump
  pmp->state = PUMP_STATE_OFF;
  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}
void Pump_On(Pump_TypeDef *pmp){
  pmp->state = PUMP_STATE_ON;
  HAL_GPIO_WritePin(pmp->port, pmp->pin, GPIO_PIN_RESET);
}
void Pump_Off(Pump_TypeDef *pmp){
  pmp->state = PUMP_STATE_OFF;
  HAL_GPIO_WritePin(pmp->port, pmp->pin, GPIO_PIN_SET);
}
void Pump_Toggle(Pump_TypeDef *pmp){
  if (pmp->state == PUMP_STATE_ON) {
    Pump_Off(pmp);
  } else {
    Pump_On(pmp);
  }
}
