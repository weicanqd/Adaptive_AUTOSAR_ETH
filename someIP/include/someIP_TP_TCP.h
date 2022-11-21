/**
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.21.2022
*/

#ifndef CYY_AP_SOMEIP_TCP_H
#define CYY_AP_SOMEIP_TCP_H
#include "someIP.h"
/* ========================================================================== */
/*                       Internal Data structure                              */
/* ========================================================================== */

someIP_Header magic_cookie_C2S = {
    .messageID.id      = 0xFFFFFFF,
    .length            = 0x00000008,
    .requestID         = 0xDEADBEEF,
    .protocol_Version  = 0x01,
    .interface_Version = 0x01,
    .message_type      = 0x01,
    .return_code       = 0x00,
};

someIP_Header magic_cookie_S2C = {
    .messageID.id      = 0xFFF8000,
    .length            = 0x00000008,
    .requestID         = 0xDEADBEEF,
    .protocol_Version  = 0x01,
    .interface_Version = 0x01,
    .message_type      = 0x02,
    .return_code       = 0x00,
};

#endif // CYY_AP_SOMEIP_TCP_H
