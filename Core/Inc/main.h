/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "step_motor.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern SM_TypeDef sm;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SM_PWM_Pin GPIO_PIN_8
#define SM_PWM_GPIO_Port GPIOF
#define ENC_2B_Pin GPIO_PIN_1
#define ENC_2B_GPIO_Port GPIOA
#define ENC_2A_Pin GPIO_PIN_5
#define ENC_2A_GPIO_Port GPIOA
#define ENC_3A_Pin GPIO_PIN_6
#define ENC_3A_GPIO_Port GPIOA
#define ENC_3B_Pin GPIO_PIN_7
#define ENC_3B_GPIO_Port GPIOA
#define ENC_1A_Pin GPIO_PIN_9
#define ENC_1A_GPIO_Port GPIOE
#define SM_EN_Pin GPIO_PIN_10
#define SM_EN_GPIO_Port GPIOE
#define ENC_1B_Pin GPIO_PIN_11
#define ENC_1B_GPIO_Port GPIOE
#define SM_DIR_Pin GPIO_PIN_12
#define SM_DIR_GPIO_Port GPIOE
#define BLM_PWM1_Pin GPIO_PIN_14
#define BLM_PWM1_GPIO_Port GPIOB
#define BLM_PWM2_Pin GPIO_PIN_15
#define BLM_PWM2_GPIO_Port GPIOB
#define ENC_4A_Pin GPIO_PIN_12
#define ENC_4A_GPIO_Port GPIOD
#define ENC_4B_Pin GPIO_PIN_13
#define ENC_4B_GPIO_Port GPIOD
#define SE_PWM1_Pin GPIO_PIN_6
#define SE_PWM1_GPIO_Port GPIOC
#define SE_PWM2_Pin GPIO_PIN_7
#define SE_PWM2_GPIO_Port GPIOC
#define SE_PWM3_Pin GPIO_PIN_8
#define SE_PWM3_GPIO_Port GPIOC
#define SE_PWM4_Pin GPIO_PIN_9
#define SE_PWM4_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
