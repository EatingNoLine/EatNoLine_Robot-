//
// Created by azarai on 30/09/24.
//

#ifndef VOFA_H
#define VOFA_H

#ifndef PID_DEBUG

#define VOFA_BUFFER_SIZE 20

// Global variables
extern char Vofa_Buffer[VOFA_BUFFER_SIZE];

// Functions provided
void Vofa_Communicate(void);
void Vofa_Parse(char *str);

#endif //PID_DEBUG

#endif //VOFA_H
