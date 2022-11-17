/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.16.2022
*/

#include "../include/someIP_serialization.h"
#include <stdio.h>


uint8_t input_demo1[2] = {
    0x04, 0xF2
};

void someIP_deserialize_wireType_dataId(const uint8_t* input,
                                        someIP_wire_data_id_union* wire_data_id) {


  wire_data_id->R = ((input[0] << 8) | input[1]);


//  printf("input byte 0x%04x\n", wire_data_id->R);
//
//  printf("wire_type: 0x%02x\n", wire_data_id->B.wire_type);
//  printf("data_id_high: 0x%02x\n", wire_data_id->B.data_id_high);
//  printf("data_id_low: 0x%02x\n", wire_data_id->B.data_id_low);

}

void someIP_deserializing(uint8_t* input) {
  someIP_wire_data_id_union wireType_dataID = {0};

  someIP_deserialize_wireType_dataId(&input[0], &wireType_dataID);

  printf("input byte 0x%04x\n", wireType_dataID.R);

  printf("wire_type: 0x%02x\n", wireType_dataID.B.wire_type);
  printf("data_id_high: 0x%02x\n", wireType_dataID.B.data_id_high);
  printf("data_id_low: 0x%02x\n", wireType_dataID.B.data_id_low);
}



int main() {

  someIP_deserializing(input_demo1);

  return 0;
}