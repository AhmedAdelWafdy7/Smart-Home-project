#include "USART_DATA.h"

/**
 * 
 * @param 
 * @param str_len
 */
void USART_Send_String(uint8_t *string,uint16_t str_len){
    uint16_t l_String_Length = 0;
    for(l_String_Length = 0; l_String_Length < str_len; ++l_String_Length){
        EUSART_Write(*string++);
    }
}
