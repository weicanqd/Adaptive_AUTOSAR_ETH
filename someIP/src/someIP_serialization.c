/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.16.2022
*/

#include "../include/someIP_serialization.h"
#include "../../common/Std_Types.h"
#include "../include/someIP_serialization_cfg.h"
#include <stdio.h>

static inline void someIP_deserialize_wire_type_data_Id(const uint8* input, someIP_Tag* tag) {

  /* mapping input array to wire_data_id type */
  tag->someIp_wire_data_id.R = ((input[0] << 8) | input[1]);

}

static inline Std_ReturnType someIP_length_mapping(const someIP_Tag* tag, someIP_Data_Type_enum *length) {

  Std_ReturnType return_value = E_OK;

  /* 0. tag check */
  if ((tag->someIp_wire_data_id.B.wire_type < 0x00) || tag->someIp_wire_data_id.B.wire_type > 0x08) {
    return_value = E_NOT_OK;
  }

  /* 1. mapping tag */
  if (return_value == E_OK) {
    switch (tag->someIp_wire_data_id.B.wire_type) {
    case WIRE_TYPE_8_BIT:
      *length = BASE_8_BIT;
      break;
    case WIRE_TYPE_16_BIT:
      *length = BASE_16_BIT;
      break;
    case WIRE_TYPE_32_BIT:
      *length = BASE_32_BIT;
      break;
    case WIRE_TYPE_64_BIT:
      *length = BASE_64_BIT;
      break;
    case WIRE_TYPE_COMPLEX_STATIC:
      *length = STATIC_SIZE;
      break;
    case WIRE_TYPE_COMPLEX_8BIT:
      *length = DYNAMIC_1_BYTE;
      break;
    case WIRE_TYPE_COMPLEX_16BIT:
      *length = DYNAMIC_2_BYTE;
      break;
    case WIRE_TYPE_COMPLEX_32BIT:
      *length = DYNAMIC_4_BYTE;
      break;
    }
  }

  return return_value;

}

static inline void someIP_get_length_field(const someIP_Data_Type_enum length_type,
                                           const uint16* index_for_length,
                                           uint16* index_for_data,
                                           uint32* length_field,
                                           const uint8* input) {
  switch (length_type) {
  case BASE_8_BIT:
    /* CYY: base data type have no length_field */
    *length_field = 0x01;
    *index_for_data = *index_for_length;
    break ;
  case BASE_16_BIT:
    *length_field = 0x02;
    *index_for_data = *index_for_length;
    break;
  case BASE_32_BIT:
    *length_field = 0x04;
    *index_for_data = *index_for_length;
    break;
  case BASE_64_BIT:
    *length_field = 0x08;
    *index_for_data = *index_for_length;
    break;
  case STATIC_SIZE:
    /* length filed should be defined in arxml. */
    *length_field = 0xFF;
    *index_for_data = *index_for_length;
    break;
  case DYNAMIC_1_BYTE:
    *length_field = input[*index_for_length];
    *index_for_data = *index_for_length + 1 * sizeof(uint8);
    break;
  case DYNAMIC_2_BYTE:
    *length_field = (input[*index_for_length] << 8)
                    | (input[(*index_for_length) + (1 * sizeof(uint8_t))]);

    *index_for_data = *index_for_length + 2 * sizeof(uint8);
    break;
  case DYNAMIC_4_BYTE:
    *length_field = (input[*index_for_length] << 24)
                    | (input[(*index_for_length) + (1 * sizeof(uint8_t))] << 16)
                    | (input[(*index_for_length) + (2 * sizeof(uint8_t))] << 8)
                    | (input[(*index_for_length) + (3 * sizeof(uint8_t))]);
    *index_for_data = *index_for_length + 4 * sizeof(uint8);
    break;
  }
}

static inline void someIP_print(const uint8* buffer, uint32 length) {
  for (uint32 i = 0; i < length; i++) {
    printf("%ld: 0x%02x\n", i, buffer[i]);
  }
    printf("\n");
}

void someIP_deserializing(uint8* input) {
  Std_ReturnType        return_value  = E_NOT_OK;
  someIP_Tag            tag           = {.someIp_wire_data_id.R = 0xFFFFU};
  someIP_Wire_Type_enum wire_type;
  uint16                index_for_tag = 0;
  uint16                index_for_length = 0;
  uint16                index_for_data = 0;
  someIP_Data_Type_enum length_type;
  uint32                length_field = 0;
  uint16                data_id;

  /* 0. Update index */
  index_for_length = index_for_tag + 2;

  /* 1. Get wire type and data id */
  someIP_deserialize_wire_type_data_Id(&input[index_for_tag],&tag);
  wire_type = tag.someIp_wire_data_id.B.wire_type;
  data_id = (tag.someIp_wire_data_id.B.data_id_high << 8) | (tag.someIp_wire_data_id.B.data_id_low);

  /* 2. Mapping wire type and length*/
  return_value = someIP_length_mapping(&tag, &length_type);

  printf("wire_type: 0x%02x\n", tag.someIp_wire_data_id.B.wire_type);

  printf("data type: %d\n", length_type);
  printf("data id: 0x%04x\n", data_id);

  /* 3. Get length_filed based wire type
   * CYY: suppose no padding bits here */
  if (return_value == E_OK) {
    someIP_get_length_field(length_type, &index_for_length, &index_for_data, &length_field, &input[index_for_tag]);
  }

  printf("length_field: 0x%04lx\n", length_field);
  someIP_print(&input[index_for_data], length_field);
}



int main() {

//  someIP_deserializing(input_wire_type_0);
//  someIP_deserializing(input_wire_type_1);
//  someIP_deserializing(input_wire_type_2);
//  someIP_deserializing(input_wire_type_3);
  someIP_deserializing(input_wire_type_5);
  someIP_deserializing(input_wire_type_6);
  someIP_deserializing(input_wire_type_7);
  return 0;
}