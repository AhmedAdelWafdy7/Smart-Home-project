/* 
 * File:   EEPROM.h
 * Author: user
 *
 * Created on March 12, 2023, 10:02 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#include "../../mcc_generated_files/examples/i2c_master_example.h"

void EEPROM_Write_Byte(i2c_address_t EEPROM_Address,i2c_address_t Byte_Address,uint8_t data);
uint8_t EEPROM_Read_Byte(i2c_address_t EEPROM_Address,i2c_address_t Byte_Address);


#endif	/* EEPROM_H */

