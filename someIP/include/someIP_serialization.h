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

/* CYY: DataID layout refer Figure4.6 */
typedef union someIP_wire_data_id_union_t {
  volatile uint16_t R;
  struct {
    volatile uint8_t               unused_7     :1;
    volatile someIP_Wire_Type_enum wire_type    :3;
    volatile uint8_t               data_id_high :4;
    volatile uint8_t               data_id_low;
  } B ;
} someIP_wire_data_id_union;

typedef struct someIP_Tag_t {
  someIP_wire_data_id_union someIp_wire_data_id;
  uint8_t length_field[0];
} someIP_Tag;

#endif // CYY_AP_SOMEIP_SERIALIZATION_H
