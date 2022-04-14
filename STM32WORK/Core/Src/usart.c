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
//闂傚倷绀�?幉鈥愁潖缂佹ɑ鍙忛柟缁㈠枛閻鏌涢埄鍐＄細妞も晝鍏橀弻鏇熷緞閸績鍋撳Δ鍛仭闁规崘绉ぐ鎺撳亼闁告侗鍨遍崑褔姊洪�????,闂傚偊鎷???婵＄偑鍊栭悧妤冪矙閹达附鍎婇柣锝呭厫intf闂傚倷绀�?幉锟犲垂閸忓吋鍙忛柕鍫濐槸濮???,闂傚倷绀�?崥�?�熆濡崵闄勯柡鍐�??荤粻鏂款熆閼搁潧濮堟い銉嫹?闂備浇宕甸崰鎰洪幋鐘愁�???濠电姰鍨煎▔娑㈩敄閸涙惌鏁傛い褏鎯玡 MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//闂傚倷绀�?幖顐ょ矓閺夋嚚娲Χ婢跺﹪妫峰銈嗙墬缁嬫帡宕曢悢鍏肩厵闁告挆鍛婵炲濮甸敃銏ゅ箖閻戣棄鍗虫慨妯哄暱閸�??斥攽閻愯尙澧涢柛銊ョ仢椤曪綁濡搁埡濠冩櫖濠电偞鍨跺玻鍨ｉ悜鑺モ拺闁告稑锕ら悘鍗炩攽椤斿�??婵嗩嚕閿???                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//闂備浇顕у锕傦綖婢舵劖鍎楁い鏂垮⒔娑撳秹鏌ｉ幒鎴炵窛ys_exit()婵犵數鍋涢顓熸叏娴兼潙纾块柛顭戝亜椤曢亶鏌嶉崫鍕櫣缂??閸屾壕鍋撻獮鍨姎閻庢凹鍓熼崺銏ｇ疀濞戞瑧鍘介梺閫炲苯澧┑陇鍋愰埀顒冾潐濞叉﹢宕濋弽顐ょ煓濠㈣泛鐬肩壕鍏间繆椤栨繂鍚归柣銊嚙閳规垿鍩ラ崱妤冧�??閻庤娲栧ú銊�??�?�??    
void _sys_exit(int x) 
{ 
	x = x; 
} 
//闂傚倸鍊烽悞锕併亹閸愵亞鐭撻柟缁㈠枟閸嬧晠鏌ｉ幇闈涘闁崇粯娲栭埞鎴炲緞鐏炵偓鐝杣tc闂傚倷绀�?幉锟犲垂閸忓吋鍙忛柕鍫濐槸濮??? 
int fputc(int ch, FILE *f)
{ 	
	while((USART1->SR&0X40)==0);//闂佽娴烽弫濠氬磻婵犲啰顩查柣鎰瀹撲線鏌涢埄鍐槈闁活厽顨婇�??????,闂傚倷鑳堕崕鐢稿疾濠婂啞缂氭繛鍡樻尭閺勩�??鍏夊亾闁告洦鍋嗛悡鎴︽⒑�??????濠电偠鎻徊浠嬪箺濠婂牆姹叉慨姗嗗幗�?????   
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
