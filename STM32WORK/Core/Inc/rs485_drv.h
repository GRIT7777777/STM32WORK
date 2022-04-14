#ifndef _RS485_DRV_H_
#define _RS485_DRV_H_

#include "usart.h"
#include "sensor.h"

/*RS485 RX/TX Control*/
#define RS485_TX_ENABLE()   HAL_Delay(1);\
                            HAL_GPIO_WritePin(RS485_K_GPIO_Port, RS485_K_Pin, GPIO_PIN_SET);\
                            HAL_Delay(1);                         
                            
#define RS485_RX_ENABLE()   HAL_Delay(1);\
                            HAL_GPIO_WritePin(RS485_K_GPIO_Port, RS485_K_Pin, GPIO_PIN_RESET);;\
                            HAL_Delay(1);


void RS485_Init(void);
void RS485_Receive(uint8_t *pdata,uint8_t *size);
void RS485_Transmit(uint8_t*pdata,uint8_t size);



#endif /*_RS485_DRV_H_*/
