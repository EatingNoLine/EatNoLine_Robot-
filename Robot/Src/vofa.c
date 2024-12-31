//
// Created by azarai on 30/09/24.
//

#include "vofa.h"

#include <stdio.h>
#include <string.h>

#include "motor_control.h"

char Vofa_Buffer[VOFA_BUFFER_SIZE];

void Vofa_Communicate(void) {
  scanf("%s", Vofa_Buffer);
  printf("%s\n", Vofa_Buffer);
  Vofa_Parse(Vofa_Buffer);
  getchar();

  memset(Vofa_Buffer, 0, sizeof(Vofa_Buffer));
}

void Vofa_Parse(char *str) {
  char c;
  int tmp1, tmp2;
  sscanf(str, "%c=%d.%d", &c, &tmp1, &tmp2);
  double f = tmp1 + (double)tmp2 * 0.001;

  switch (c) {
    case 'P':
      for (int i = 0; i < 4; ++i) {
        pid[i].Kp = f;
      }
      break;
    case 'I':
      for (int i = 0; i < 4; ++i) {
        pid[i].Ki = f;
      }
      break;
    case 'D':
      for (int i = 0; i < 4; ++i) {
        pid[i].Kd = f;
      }
      break;
    case 'T':
      for (int i = 0; i < 4; ++i) {
        DM_SetSpeed(i, f);
      }
      break;
    default:
      break;
  }
}
