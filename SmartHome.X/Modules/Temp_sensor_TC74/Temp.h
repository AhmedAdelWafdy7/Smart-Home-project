/* 
 * File:   Temp.h
 * Author: user
 *
 * Created on March 12, 2023, 10:24 AM
 */

#ifndef TEMP_H
#define	TEMP_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t Temp_Read_Temp(i2c_address_t TC74_Address);


#endif	/* TEMP_H */

