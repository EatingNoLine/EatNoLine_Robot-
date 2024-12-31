//
// Created by azarai on 11/09/24.
//

#include "pump_control.h"

PUMP pump[2];

void Pump_Init(void) {
  // pump1
  pump[0].port = PUMP1_GPIO_Port;
  pump[0].pin = PUMP1_Pin;

  // pump2
  pump[1].port = PUMP2_GPIO_Port;
  pump[1].pin = PUMP2_Pin;

  // default to close pump
  Pump_Close(&pump[0]);
  Pump_Close(&pump[1]);
}

void Pump_Open(PUMP *pump) {
  pump->state = PUMP_OPEN;
  HAL_GPIO_WritePin(pump->port, pump->pin, GPIO_PIN_RESET);
}

void Pump_Close(PUMP *pump) {
  pump->state = PUMP_CLOSE;
  HAL_GPIO_WritePin(pump->port, pump->pin, GPIO_PIN_SET);
}

void Pump_Toggle(PUMP *pump) {
  if (pump->state == PUMP_OPEN) {
    Pump_Close(pump);
  } else if (pump->state == PUMP_CLOSE) {
    Pump_Open(pump);
  }
}
