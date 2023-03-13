

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "Modules/EEPROM_24C02C/EEPROM.h"
#include "Modules/RTC_DS1307/RTC.h"
#include "Modules/Temp_sensor_TC74/Temp.h"

RTC_t RTC;
uint8_t U4RecValue, U5RecValue;
uint8_t TempValue = 0;
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();


    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();



    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    USART_Send_String("System Started\r",15);
    EEPROM_Write_Byte(0xA2, 0x08, 7);
    __delay_us(100);
    EEPROM_Write_Byte(0xA2, 0x08, 10);
    __delay_us(100);
    U4RecValue = EEPROM_Read_Byte(0xA2,0x08);
    U5RecValue = EEPROM_Read_Byte(0xA6,0x08);
   
    while (1)
    {
        RTC = Get_Date_Time();
        Print_Date_time();
        TempValue = Temp_Read_Temp(0x9E);
        I2C_Write1ByteRegister(0x70, 0x00, TempValue);
        __delay_ms(300);
    }
}
/**
 End of File
*/