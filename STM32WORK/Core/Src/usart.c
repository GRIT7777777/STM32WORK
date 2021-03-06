/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
//éåå·ç»ä¾?å¹é¥ææ½ç¼ä½¹Ééå¿æç¼ã æé»îîéæ¶¢åéï¼ç´°å¦ãæéæ©å¼»éç·ç·é¸î£ç¸¾éæ³Îéî¼ä»­éè§å´ç»î¿ãéºæ³äº¼éåä¾é¨éå´è¤å§æ´ªæ????,éååé·???å©µï¼åéæ ­æ§å¦¤åªçé¹è¾¾ééå©æ£éå­å«intféåå·ç»ä¾?å¹éç²åé¸å¿åéå¿æé«æ¿æ§¸æ¿®???,éåå·ç»ä¾?å´¥ç?£îçæ¿¡îå´µéå¯æ¡éã??è¤ç²»éæ¬¾çé¼ææ½§æ¿®å ãéîå«¹?éåæµå®ç¸å´°é°îæ´ªå¹éæå???æ¿ çµå§°é¨çâå¨ã©æé¸æ¶æéåãè¤é¯ç¡ MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//éåå·ç»ä¾?å¹é¡ãçéºå¤åå¨²îÎ§å©¢è·ºï¹ªå¦«å³°îéåå¢¬ç¼å¬«å¸¡å®æ¢æ¢éè©åµéåæéî î¼å©µç²î­æ¿®ç¸æéãç®é»æ£æ£éè«æ¨å¦¯åæ±é¸æ¨??æ¥æ½é»æ¯å°æ¾§æ¶¢æéã§ä»¢æ¤¤æªç¶æ¿¡æå¡æ¿ å©æ«æ¿ çµåé¨è·ºç»é¨î¥ï½æéºã¢æºéåç¨éãæéç©æ½æ¤¤æ¿æ??å©µå©åé¿???                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//éåæµé¡Ñîéå¦ç¶å©¢èµåéæ¥ãéå®âå¨æ³ç§¹éï½å¹é´çµçªys_exit()å©µçµæ¸éæ¶¢îé¡ç¸åå¨´å¼æ½çº¾åæé¡­æäºæ¤¤æ¢äº¶éå¶å´«éîæ«£ç¼??é¸å±¾å£éæ»ç®é¨î¼å§é»åº¢å¹éç¼å´ºéï½çæ¿æç§éä»æ¢ºé«ç²è¯æ¾§î¼âééæ°åé¡å¾æ½æ¿åï¹¢å®æ¿å¼½é¡ãçæ¿ ã£æ³é¬è©å£éé´ç¹æ¤¤æ ¨ç¹éå½æ£éîåé³è§å¿é©ã©å´±å¦¤å§ç²??é»åº¤îå¨²æ §Ãºéâ??ä¾?æ??    
void _sys_exit(int x) 
{ 
	x = x; 
} 
//éåå¸éç½æéä½µäº¹é¸æµäºé­æ»æç¼ã æé¸å¬§æ éï½å¹éæ¶î«éå´ç²¯å¨²æ ­åé´ç²ç·éçµåéæ£tcéåå·ç»ä¾?å¹éç²åé¸å¿åéå¿æé«æ¿æ§¸æ¿®??? 
int fputc(int ch, FILE *f)
{ 	
	while((USART1->SR&0X40)==0);//éä½½î§å¨´ç½å¼«æ¿ æ°¬ç£»å©µç²å°é¡©æ¥æ£é°îî ç¹æ²ç·éæ¶¢åéîæ§éæ´»å½é¡¨å©å¼??????,éåå·é³å å´é¢ç¨¿ç¾æ¿ å©åç¼æ°­ç¹é¡æ¨»å°­éºå©å??éå¤äº¾éåæ´¦éåæ¡é´ï¸½âé??????æ¿ çµå é»îå¾æµ å¬ªç®ºæ¿ å©çå§¹åæ¨å§åå¹é?????   
	USART1->DR = (uint8_t) ch;      
	return ch;
}
#endif 

//recv_sensor_data
recv_sensor_data sensor;

//USART1_RX  
#if EN_USART1_RX  
uint8_t USART1_RX_BUF[USART1_REC_LEN];     
uint16_t USART1_RX_STA=0;       
uint8_t aRxBuffer[RXBUFFERSIZE];
#endif
//USART2_PC_RX 485
#if EN_USART2_PC_RX //485
uint8_t res;
uint16_t recv_buf[recv_len];
uint16_t recv_cnt=0;
#endif 
//UART4_TH_RX 
#if EN_UART4_TH_RX 
uint8_t res_th;
uint16_t recv_th_buf[recv_th_len];
uint16_t recv_th_cnt=0;
#endif 

/* USER CODE END 0 */

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* UART4 init function */
void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 9600;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */
  HAL_UART_Receive_IT(&huart4,&res_th,1);
  /* USER CODE END UART4_Init 2 */

}
/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */
  HAL_UART_Receive_IT(&huart1,aRxBuffer,RXBUFFERSIZE);
  /* USER CODE END USART1_Init 2 */

}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */
  //RS485_RX_ENABLE();
  HAL_UART_Receive_IT(&huart2,&res,1);
  /* USER CODE END USART2_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspInit 0 */

  /* USER CODE END UART4_MspInit 0 */
    /* UART4 clock enable */
    __HAL_RCC_UART4_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**UART4 GPIO Configuration
    PA0-WKUP     ------> UART4_TX
    PA1     ------> UART4_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* UART4 interrupt Init */
    HAL_NVIC_SetPriority(UART4_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(UART4_IRQn);
  /* USER CODE BEGIN UART4_MspInit 1 */

  /* USER CODE END UART4_MspInit 1 */
  }
  else if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = Debug_Pin|DebugA10_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = RS485_Pin|RS485A3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspDeInit 0 */

  /* USER CODE END UART4_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_UART4_CLK_DISABLE();

    /**UART4 GPIO Configuration
    PA0-WKUP     ------> UART4_TX
    PA1     ------> UART4_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0|GPIO_PIN_1);

    /* UART4 interrupt Deinit */
    HAL_NVIC_DisableIRQ(UART4_IRQn);
  /* USER CODE BEGIN UART4_MspDeInit 1 */

  /* USER CODE END UART4_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, Debug_Pin|DebugA10_Pin);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, RS485_Pin|RS485A3_Pin);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==USART1)
	{
		if((USART1_RX_STA&0x8000)==0)
		{
			if(USART1_RX_STA&0x4000)
			{
				if(aRxBuffer[0]!=0x0a)USART1_RX_STA=0;
				else USART1_RX_STA|=0x8000;	
			}
			else 
			{	
				if(aRxBuffer[0]==0x0d)USART1_RX_STA|=0x4000;
				else
				{
					USART1_RX_BUF[USART1_RX_STA&0X3FFF]=aRxBuffer[0] ;
					USART1_RX_STA++;
					if(USART1_RX_STA>(USART1_REC_LEN-1))USART1_RX_STA=0; 
				}		 
			}
		}
  }
  //receive pc data 
  if(huart ->Instance == USART2)
  { 
    if (recv_cnt<11)
    {
      recv_buf[recv_cnt]=res; 
      recv_cnt++; 
      HAL_UART_Receive_IT(&huart2,&res,1);
    }
    else
    {
      recv_cnt = 0;
    }
  }	

  if (huart ->Instance == UART4)
  {
    if (recv_th_cnt<10)
    {
      recv_th_buf[recv_th_cnt]=res_th; 
      recv_th_cnt++; 
      HAL_UART_Receive_IT(&huart4,&res_th,1);
    }
    else
    {
      recv_th_cnt = 0;
    }
    
  }
  
}


/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
