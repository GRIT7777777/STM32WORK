#include "rs485_drv.h"


/**
 * @brief 485数据发送
 */
void RS485_Transmit(uint8_t*pdata,uint8_t size)
{   
    RS485_TX_ENABLE();
    HAL_UART_Transmit(&huart2,pdata,size,1000);
    HAL_Delay(1);
    RS485_RX_ENABLE();

}




