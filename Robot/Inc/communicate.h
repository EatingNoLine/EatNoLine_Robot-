//
// Created by azarai on 12/09/24.
//

#ifndef COMMUTICATE_H
#define COMMUTICATE_H

#define BUFFERSIZE 16
extern char ComBuffer[BUFFERSIZE];

#define COMMAND_STOP    (0)
#define COMMAND_RUN_1   (1)
#define COMMAND_RUN_2   (2)
#define COMMAND_RUN_3   (3)
#define COMMAND_RUN_4   (4)
#define COMMAND_RUN_5   (5)
#define COMMAND_GRAB    (6)
#define COMMAND_ROTATE  (7)
#define COMMAND_SHOOT  (8)

// Community
void Com_GetCommand(void);
void Com_Parse(void);
void Com_ExecCommand(void);
// Functions for executing
void Com_Stop(void);
void Com_Run(void);
void Com_Grab(void);
void Com_Shoot(void);

#endif  // COMMUTICATE_H
