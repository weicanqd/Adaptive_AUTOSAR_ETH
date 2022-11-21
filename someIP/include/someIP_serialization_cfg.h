/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.16.2022
*/

#ifndef CYY_AP_SOMEIP_SERIALIZATION_CFG_H
#define CYY_AP_SOMEIP_SERIALIZATION_CFG_H

#include "../../common/Platform_Types.h"

uint8 input_8_bit_base[20] = {
    0x00, 0x01, 0xAA
};

uint8 input_16_bit_base[20] = {
    0x10, 0x02, 0xAA, 0xBB
};

uint8 input_32_bit_base[20] = {
    0x20, 0x03, 0xAA, 0xBB, 0xCC, 0xDD
};


uint8 input_wire_type_7[20] = {
    0x70, 0x07, 0x00, 0x00, 0x00, 0x01, 0xAA
};

uint8 input_wire_type_6[20] = {
    0x60, 0x06, 0x00, 0x01, 0xAA
};

uint8 input_wire_type_5[20] = {
    0x50, 0x06, 0x02, 0xAA, 0xBB
};

uint8 input_wire_type_4[20] = {
    0x40, 0x04, 0x01, 0x01, 0x01, 0x01, 0xAA
};

uint8 input_wire_type_3[20] = {
    0x30, 0x03, 0xA1, 0xA2, 0xA3, 0xA4, 0xB1,
    0xB2, 0xB3, 0xB4
};

uint8 input_wire_type_2[20] = {
    0x20, 0x02, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE
};

uint8 input_wire_type_1[20] = {
    0x10, 0x0A, 0xAA, 0xBB
};

uint8 input_wire_type_0[20] = {
    0x00, 0x00, 0xAA
};

#endif // CYY_AP_SOMEIP_SERIALIZATION_CFG_H
