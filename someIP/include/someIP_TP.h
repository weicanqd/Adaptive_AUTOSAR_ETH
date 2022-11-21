/**
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.21.2022
*/

#ifndef CYY_AP_SOMEIP_TP_H
#define CYY_AP_SOMEIP_TP_H

#include "../../common/Std_Types.h"


typedef union someIP_TP_Header_union_t {
  uint32 someIP_TP_Header;
  struct {
    uint32 offset            :28;
    uint8  reversed_flag_1   :1;
    uint8  reversed_flag_2   :1;
    uint8  reversed_flag_3   :1;
    uint8  more_seg_flag     :1;
  };
} someIP_TP_Header_union;

#endif // CYY_AP_SOMEIP_TP_H
