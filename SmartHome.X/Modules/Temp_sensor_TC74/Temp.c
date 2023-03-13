#include "Temp.h"

/**
 * 
 * @param TC74_Address
 * @return 
 */
uint8_t Temp_Read_Temp(i2c_address_t TC74_Address){
    uint8_t Temp_value = 0;
    Temp_value = I2C_Read1ByteRegister(TC74_Address,0x00);
    return Temp_value;
}
