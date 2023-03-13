#include "EEPROM.h"


/**
 * 
 * @param EEPROM_Address
 * @param Byte_Address
 * @param data
 */
void EEPROM_Write_Byte(i2c_address_t EEPROM_Address,i2c_address_t Byte_Address,uint8_t data){
    I2C_Write1ByteRegister(EEPROM_Address,Byte_Address,data);
}
/**
 * 
 * @param EEPROM_Address
 * @param Byte_Address
 * @return 
 */
uint8_t EEPROM_Read_Byte(i2c_address_t EEPROM_Address,i2c_address_t Byte_Address){
    unsigned char Recived_value = 0;
    Recived_value = I2C_Read1ByteRegister(EEPROM_Address,Byte_Address);
    return Recived_value;
}
