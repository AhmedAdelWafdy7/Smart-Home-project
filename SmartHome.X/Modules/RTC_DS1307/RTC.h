/* 
 * File:   RTC.h
 * Author: user
 *
 * Created on March 12, 2023, 9:36 AM
 */

#ifndef RTC_H
#define	RTC_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"
#include "../USART_Data/USART_DATA.h"

typedef struct{
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
    uint8_t year;
    uint8_t month;
    uint8_t day;    
}RTC_t;

RTC_t Get_Date_Time(void);
void Print_Date_time(void);

#endif	/* RTC_H */

