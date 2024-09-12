//
// Created by azarai on 12/09/24.
//

#include "communicate.h"

#include <stdio.h>
#include <string.h>

#include "arm_control.h"
#include "main.h"
#include "motor_control.h"

char ComBuffer[BUFFERSIZE];

void Az_Com_GetCommand(void) {
  scanf("%s", ComBuffer);
  // clean \n character
  getchar();
}

void Az_Com_Parse(void) {
  switch (ComBuffer[0] - '0') {
    case COMMAND_STOP:
      Az_Motor_Stop();
      break;
    case COMMAND_RUN_1:
    case COMMAND_RUN_2:
    case COMMAND_RUN_3:
    case COMMAND_RUN_4:
    case COMMAND_RUN_5:
      Az_Com_Run();
      break;
    case COMMAND_GRAB:
      // Grab the cube
      Az_Com_Grab();
      break;
    case COMMAND_ROTATE:
      break;
    default:
      // Do nothing
      break;
  }
}

void Az_Com_ExecCommand(void) {
  memset(ComBuffer, 0x00, BUFFERSIZE);
  Az_Com_GetCommand();
  Az_Com_Parse();

  printf("OK\n");
}

void Az_Com_Stop(void) { Az_Motor_Stop(); }

void Az_Com_Run(void) {
  // Set direction
  switch (ComBuffer[1]) {
    case 'f':
      Az_Motor_SetDirection(&dm[0], DM_Forward);
      Az_Motor_SetDirection(&dm[1], DM_Backward);
      Az_Motor_SetDirection(&dm[2], DM_Forward);
      Az_Motor_SetDirection(&dm[3], DM_Backward);
      break;
    case 'b':
      Az_Motor_SetDirection(&dm[0], DM_Backward);
      Az_Motor_SetDirection(&dm[1], DM_Forward);
      Az_Motor_SetDirection(&dm[2], DM_Backward);
      Az_Motor_SetDirection(&dm[3], DM_Forward);
      break;
    case 'l':
      Az_Motor_SetDirection(&dm[0], DM_Backward);
      Az_Motor_SetDirection(&dm[1], DM_Backward);
      Az_Motor_SetDirection(&dm[2], DM_Forward);
      Az_Motor_SetDirection(&dm[3], DM_Forward);
      break;
    case 'r':
      Az_Motor_SetDirection(&dm[0], DM_Forward);
      Az_Motor_SetDirection(&dm[1], DM_Forward);
      Az_Motor_SetDirection(&dm[2], DM_Backward);
      Az_Motor_SetDirection(&dm[3], DM_Backward);
      break;
    default:
      break;
  }

  // Set speed
  float percentage = 0.1 * (ComBuffer[0] - '0');
  Az_Motor_SetSpeed(&dm[0], percentage);
  Az_Motor_SetSpeed(&dm[1], percentage);
  Az_Motor_SetSpeed(&dm[2], percentage);
  Az_Motor_SetSpeed(&dm[3], percentage);
}

void Az_Com_Grab(void) {
  if (ComBuffer[1] == 'l') {
    Az_Arm_Grab(&arm[0]);
  } else if (ComBuffer[1] == 'r') {
    Az_Arm_Grab(&arm[1]);
  }
}
