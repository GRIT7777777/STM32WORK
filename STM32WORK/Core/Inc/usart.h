/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "rs485_drv.h"
#include "stdio.h"
#include "temp_humi.h"
#include "sensor.h"
/* USER CODE END Includes */

extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
extern recv_sensor_data sensor;
/*DEBUG USART1 START*/
#define EN_USART1_RX 			1		
#define USART1_REC_LEN  			200  	  	
extern uint8_t  USART1_RX_BUF[USART1_REC_LEN]; 
extern uint16_t USART1_RX_STA;         		

#define RXBUFFERSIZE   1 
extern uint8_t aRxBuffer[RXBUFFERSIZE];
/*DEBUG USART1 ENDING*/

/*RS485 USART2 32<=>pc */
#define EN_USART2_PC_RX 			1		
#define recv_len 10
extern uint16_t recv_buf[recv_len];
extern uint16_t recv_cnt;

extern uint8_t res;

extern uint8_t RS485_tx_finish;
extern uint8_t RS485_rx_finish;

/*RS485 USART2 ENDING*/

/*Temp_humi UART4 START*/
#define EN_UART4_TH_RX 			1		
#define recv_th_len 9
extern uint16_t recv_th_buf[recv_th_len];
extern uint16_t recv_th_cnt;

extern uint8_t res_th;
/*Temp_humi UART4 ENDING*/

/* USER CODE END Private defines */

void MX_UART4_Init(void);
void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
