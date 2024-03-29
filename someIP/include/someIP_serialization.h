/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.16.2022
*/


#ifndef CYY_AP_SOMEIP_SERIALIZATION_H
#define CYY_AP_SOMEIP_SERIALIZATION_H
/* ========================================================================== */
/*                            Includes                                        */
/* ========================================================================== */
#include "someIP.h"
#include "../../common/Std_Types.h"
#include "../include/someIP_serialization_cfg.h"
#include <stdio.h>
/* ========================================================================== */
/*                       Data struct define                                   */
/* ========================================================================== */

typedef enum someIP_Wire_Type_enum_t {
  /* 8-bit base data type */
  WIRE_TYPE_8_BIT           = 0x00,

  /* 16-bit base data type */
  WIRE_TYPE_16_BIT          = 0x01,

  /* 32-bit base data type */
  WIRE_TYPE_32_BIT          = 0x02,

  /* 64-bit base data type */
  WIRE_TYPE_64_BIT          = 0x03,

  /* Array, Struct, String, Union with length field of static size. */
  WIRE_TYPE_COMPLEX_STATIC  = 0x04,

  /* Array, Struct, String, Union with length field size 1 byte.(ignore static) */
  WIRE_TYPE_COMPLEX_8BIT    = 0x05,

  /* Array, Struct, String, Union with length field size 2 bytes.(ignore static) */
  WIRE_TYPE_COMPLEX_16BIT   = 0x06,

  /* Array, Struct, String, Union with length field size 4 bytes.(ignore static) */
  WIRE_TYPE_COMPLEX_32BIT   = 0x07,

} someIP_Wire_Type_enum;

typedef enum someIP_Data_Type_enum_t {
  /* base data type */
  BASE_8_BIT     = 0x00,
  BASE_16_BIT    = 0x01,
  BASE_32_BIT    = 0x02,
  BASE_64_BIT    = 0x03,

  /* static size: eg. define in ARXML */
  STATIC_SIZE    = 0x04,

  /* dynamic size */
  DYNAMIC_1_BYTE = 0x05,
  DYNAMIC_2_BYTE = 0x06,
  DYNAMIC_4_BYTE = 0x07,

} someIP_Data_Type_enum;

/* CYY: DataID layout refer Figure4.6 */
typedef union someIP_wire_data_id_union_t {
  volatile uint16_t R;
  struct {
    volatile uint8_t               data_id_low;
    volatile uint8_t               data_id_high :4;
    volatile someIP_Wire_Type_enum wire_type    :3;
    volatile uint8_t               unused_7     :1;
  } B;
} someIP_wire_data_id_union;

typedef struct someIP_Tag_t {
  someIP_wire_data_id_union someIp_wire_data_id;
} someIP_Tag;

/* ========================================================================== */
/*                       Internal Data structure                              */
/* ========================================================================== */

typedef struct someIP_deserialized_result_t {
  uint16 data_id;
  someIP_Wire_Type_enum wire_type;
  uint32* data_ptr;
} someIP_deserialized_result;

#endif // CYY_AP_SOMEIP_SERIALIZATION_H
