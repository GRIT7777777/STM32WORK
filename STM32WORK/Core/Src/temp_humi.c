#include "temp_humi.h"

/*读取温湿度数据*/
 void Get_Temp_Humi_Data()
 {
    uint8_t tBuf[8]={0x02,0x04,0x00,0x00,0x00,0x02,0x71,0xF8};
    /*rec:02 04（功能码） 04（通道号） 19 E8（温度） 1C 9A（湿度） C7 47 （校验） */
    /*（温度-4000）/100、湿度/100*/
    RS485_Transmit(tBuf,8);
 }
 
void Analysis_TH_Data()
{
   //temp data 
   sensor.temp=(recv_th_buf[4]<<8)+(recv_th_buf[5]);
   //humi data
   sensor.humi=(recv_th_buf[6]<<8)+(recv_th_buf[7]);
   printf("S_Temp-----%x\n",sensor.temp);
   printf("S_Humi-----%x\n",sensor.humi);
   
} 





