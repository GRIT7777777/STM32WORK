#ifndef _CPU_H_
#define _CPU_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "usart.h"
#include "rs485_drv.h"
#include "sensor.h"
#include "crc.h"
/*Sybc Byte 1B*/
#define S_syncb 0XFF
/*Add  1B */
#define  S_add 0X01
/*cmd funcation 2B */
#define R_temp 0x0101
#define R_humi 0x0102
/*Data Byte 2B */
/*CRC Check 4B */


void DataProcess(void);
void Receive_PC_CheckCode_Compare(void);
void Transmit_PC_Data_Analysis(uint8_t Syncb,uint8_t Add,uint16_t Funcation,uint16_t Data);

#ifdef __cplusplus
}
#endif

#endif // !_CPU_H_
