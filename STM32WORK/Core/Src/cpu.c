#include "cpu.h"

uint8_t CRC_Check_ok=1;
/*Receive data and analyse ,then process data and transmit.*/
void DataProcess()
{
    Receive_PC_CheckCode_Compare();
    /**
     * 自定义7Byte数据接收数组
     * FF 同步字节|add 地址|cmd1|cmd2|data1|data2|checksum|  
     *  checksum=crc 4字节
     * eg FF 01 00 01 00 00 crc校验码
     */   
    if (CRC_Check_ok)
    {
        if (recv_buf[0] == S_syncb && recv_buf[1] == S_add)
        {
            uint16_t s;
            s=(recv_buf[2]<<8)+(recv_buf[3]);
            switch (s)
            {
                case R_temp:
                Transmit_PC_Data_Analysis(S_syncb,S_add,R_temp,sensor.temp);
                break;
                case R_humi:
                //Analysis_TH_Data();
                Transmit_PC_Data_Analysis(S_syncb,S_add,R_temp,sensor.humi);
                break;
            
                default:printf("no funcation");
                break;
            } 
            
        }
    }   
}  
/* transmit -> pc a frame data */
void Transmit_PC_Data_Analysis(uint8_t Syncb,uint8_t Add,uint16_t Funcation,uint16_t Data) 
{
    uint8_t TPcF[10];/* transmit -> pc a frame data */
    TPcF[0]= Syncb;
    TPcF[1]= Add;
    TPcF[2]= Funcation>>8;
    TPcF[3]= Funcation;
    TPcF[4]= Data>>8;
    TPcF[5]= Data;
    uint8_t TPcD_buff[6];
    uint8_t cnt = 0;
    while (cnt<6)
    {
        TPcD_buff[cnt]=TPcF[cnt];
        cnt++;
    }
    uint8_t * TPcC_buff;
    TPcC_buff=CRC_Check_Analysis(TPcD_buff);
    TPcF[6]=TPcC_buff[0];
    TPcF[7]=TPcC_buff[1];
    TPcF[8]=TPcC_buff[2];
    TPcF[9]=TPcC_buff[3];
    RS485_Transmit(TPcF,10);
}

/* Receive pc_data CRCcheck Compare*/ 
void Receive_PC_CheckCode_Compare()
{
    uint8_t RPcD[6];
    RPcD[0]=recv_buf[0];
    RPcD[1]=recv_buf[1];
    RPcD[2]=recv_buf[2];
    RPcD[3]=recv_buf[3];
    RPcD[4]=recv_buf[4];
    RPcD[5]=recv_buf[5];
    uint8_t RPcC[4];
    RPcC[0]=recv_buf[6];
    RPcC[1]=recv_buf[7];
    RPcC[2]=recv_buf[8];
    RPcC[3]=recv_buf[9];
    uint8_t *CheckCode;
    CheckCode=CRC_Check_Analysis(RPcD);
    uint8_t i;
    while (CRC_Check_ok && i<5)
    {
        if (RPcC[i] != CheckCode[i])
        {
            CRC_Check_ok = 0;
        }
        
    }
    if (CRC_Check_ok)
    {
        printf("Check ok");
    }

}
