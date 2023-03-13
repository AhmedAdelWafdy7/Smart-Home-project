#include "RTC.h"

static RTC_t RTC;
static uint8_t RTC_Pack[18];

/**
 * 
 * @return 
 */
RTC_t Get_Date_Time(void){
    RTC.seconds = I2C_Read1ByteRegister(0xD0, 0x00);
    RTC.minutes = I2C_Read1ByteRegister(0xD0, 0x01);
    RTC.hours = I2C_Read1ByteRegister(0xD0, 0x02);
    RTC.day = I2C_Read1ByteRegister(0xD0, 0x04);
    RTC.month = I2C_Read1ByteRegister(0xD0, 0x05);
    RTC.year = I2C_Read1ByteRegister(0xD0, 0x06);
    return RTC;
}
void Print_Date_time(void){
    RTC_Pack[0] = ((RTC.day >> 4) + 0x30);
    RTC_Pack[1] = ((RTC.day & 0x0F) + 0x30);
    RTC_Pack[2] = '-';
    RTC_Pack[3] = ((RTC.month >> 4) + 0x30);
    RTC_Pack[4] = ((RTC.month & 0x0F) + 0x30);
    RTC_Pack[5] = '-';
    RTC_Pack[6] = ((RTC.year >> 4) + 0x30);
    RTC_Pack[7] = ((RTC.year & 0x0F) + 0x30);
    
    RTC_Pack[8] = '/';
    
    RTC_Pack[9]  = ((RTC.hours >> 4) + 0x30);
    RTC_Pack[10] = ((RTC.hours & 0x0F) + 0x30);
    RTC_Pack[11] = '-';
    RTC_Pack[12] = ((RTC.minutes >> 4) + 0x30);
    RTC_Pack[13] = ((RTC.minutes & 0x0F) + 0x30);
    RTC_Pack[14] = '-';
    RTC_Pack[15] = ((RTC.seconds >> 4) + 0x30);
    RTC_Pack[16] = ((RTC.seconds & 0x0F) + 0x30);
    
    RTC_Pack[17] = '\r';
    
    USART_Send_String("Date : ", 8);
    USART_Send_String(RTC_Pack, 18);    
}
