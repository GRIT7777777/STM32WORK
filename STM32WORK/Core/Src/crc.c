/**
  ******************************************************************************
  * @file    crc.c
  * @brief   This file provides code for the configuration
  *          of the CRC instances.
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
#include "crc.h"

/* USER CODE BEGIN 0 */

#
/* USER CODE END 0 */

CRC_HandleTypeDef hcrc;

/* CRC init function */
void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

void HAL_CRC_MspInit(CRC_HandleTypeDef* crcHandle)
{

  if(crcHandle->Instance==CRC)
  {
  /* USER CODE BEGIN CRC_MspInit 0 */

  /* USER CODE END CRC_MspInit 0 */
    /* CRC clock enable */
    __HAL_RCC_CRC_CLK_ENABLE();
  /* USER CODE BEGIN CRC_MspInit 1 */

  /* USER CODE END CRC_MspInit 1 */
  }
}

void HAL_CRC_MspDeInit(CRC_HandleTypeDef* crcHandle)
{

  if(crcHandle->Instance==CRC)
  {
  /* USER CODE BEGIN CRC_MspDeInit 0 */

  /* USER CODE END CRC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CRC_CLK_DISABLE();
  /* USER CODE BEGIN CRC_MspDeInit 1 */

  /* USER CODE END CRC_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
/*鏍￠獙鐢熸垚�???涓猽int32*/
uint32_t CRC_Check(uint32_t *CRCBuffer,uint8_t Buffer_size)
{
  uint32_t CRCCode;
  CRCCode=HAL_CRC_Calculate(&hcrc,(uint32_t *)CRCBuffer,Buffer_size);
  return CRCCode;
}
/*鏍￠獙鍚庣敓鎴愪竴锟??4B鏁扮�?*/
 uint8_t CRCCodeAn[4];
uint8_t * CRC_Check_Analysis(uint8_t *CRCBufferA)
{
  uint32_t DATA[2];
  DATA[0]=((CRCBufferA[0]<<24)+(CRCBufferA[1]<<16)+(CRCBufferA[2]<<8)+CRCBufferA[3]);
  DATA[1]=(CRCBufferA[4]<<24)+(CRCBufferA[5]<<16);
  uint32_t CRCCodeA;
  CRCCodeA=HAL_CRC_Calculate(&hcrc,DATA,2);
//  uint8_t CRCCodeAn[4];
  CRCCodeAn[0]=CRCCodeA>>24;
  CRCCodeAn[1]=CRCCodeA>>16;
  CRCCodeAn[2]=CRCCodeA>>8;
  CRCCodeAn[3]=CRCCodeA;
  return CRCCodeAn;
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
