// //
// // Created by azarai on 12/09/24.
// //
//
// #include "communicate.h"
//
// #include <stdio.h>
// #include <string.h>
//
// #include "main.h"
// #include "arm_control.h"
// #include "motor_control.h"
// #include "bldc_control.h"
// #include "step_control.h"
//
// char ComBuffer[BUFFERSIZE];
//
// void Com_GetCommand(void) {
//   scanf("%s", ComBuffer);
//   // clean \n character
//   getchar();
// }
//
// void Com_Parse(void) {
//   switch (ComBuffer[0] - '0') {
//     case COMMAND_STOP:
//       Motor_Stop();
//       break;
//     case COMMAND_RUN_1:
//     case COMMAND_RUN_2:
//     case COMMAND_RUN_3:
//     case COMMAND_RUN_4:
//     case COMMAND_RUN_5:
//       Com_Run();
//       break;
//     case COMMAND_GRAB:
//       // Grab the cube
//       Com_Grab();
//       break;
//     case COMMAND_ROTATE:
//       break;
//     case COMMAND_SHOOT:
//       Com_Shoot();
//       break;
//     default:
//       // Do nothing
//       break;
//   }
// }
//
// void Com_ExecCommand(void) {
//   memset(ComBuffer, 0x00, BUFFERSIZE);
//   Com_GetCommand();
//   Com_Parse();
//
//   printf("OK\n");
// }
//
// void Com_Stop(void) { Motor_Stop(); }
//
// void Com_Run(void) {
//   // Set direction
//   switch (ComBuffer[1]) {
//     case 'f':
//       Motor_SetDirection(&dm[0], DM_Forward);
//       Motor_SetDirection(&dm[1], DM_Backward);
//       Motor_SetDirection(&dm[2], DM_Forward);
//       Motor_SetDirection(&dm[3], DM_Backward);
//       break;
//     case 'b':
//       Motor_SetDirection(&dm[0], DM_Backward);
//       Motor_SetDirection(&dm[1], DM_Forward);
//       Motor_SetDirection(&dm[2], DM_Backward);
//       Motor_SetDirection(&dm[3], DM_Forward);
//       break;
//     case 'l':
//       Motor_SetDirection(&dm[0], DM_Backward);
//       Motor_SetDirection(&dm[1], DM_Backward);
//       Motor_SetDirection(&dm[2], DM_Forward);
//       Motor_SetDirection(&dm[3], DM_Forward);
//       break;
//     case 'r':
//       Motor_SetDirection(&dm[0], DM_Forward);
//       Motor_SetDirection(&dm[1], DM_Forward);
//       Motor_SetDirection(&dm[2], DM_Backward);
//       Motor_SetDirection(&dm[3], DM_Backward);
//       break;
//     default:
//       break;
//   }
//
//   // Set speed
//   float percentage = 0.1 * (ComBuffer[0] - '0') * 2;
//
//   Car_SetSpeed(percentage);
//   // HAL_Delay(200);
//   HAL_Delay(2000);
//   Car_SetSpeed(0);
// }
//
// void Com_Grab(void) {
//   if (ComBuffer[1] == 'l') {
//     Arm_Grab(&arm[0]);
//   } else if (ComBuffer[1] == 'r') {
//     Arm_Grab(&arm[1]);
//   }
// }
//
// void Com_Shoot(void) {
//   // Turn on the BLDC
//   BLDC_SetSpeed(&bldc[0], BLDC_Speed_2);
//   BLDC_SetSpeed(&bldc[1], BLDC_Speed_2);
//   HAL_Delay(3000);
//
//   // Step Motor move
//   Step_SetDirection(SM_Backward);
//   Step_Run(4000);
//
//   Step_Run(11000);
//   Step_SetDirection(SM_Forward);
//
//   Step_Run(7000);
//   Step_SetDirection(SM_Backward);
//   HAL_Delay(1000);
//
//   // Turn off the BLDC
//   BLDC_SetSpeed(&bldc[0], BLDC_Speed_0);
//   BLDC_SetSpeed(&bldc[1], BLDC_Speed_0);
// }
