/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.15.2022
*/

#ifndef MY_AP_ADAPTIVE_AUTOSAR_SOMEIP_H
#define MY_AP_ADAPTIVE_AUTOSAR_SOMEIP_H

#include <cstdint>

typedef uint32_t MessageID_Type;
typedef uint32_t Length_Type;
typedef uint32_t RequestID_Type;
typedef uint8_t Protocol_Version_Type;
typedef uint8_t Interface_Version_Type;
typedef uint8_t Message_Type;
typedef uint8_t Return_Code_Type;
typedef uint8_t E2E_Header_Type;
typedef uint8_t Payload_Type;

typedef struct someIP_E2E_Header_t {
    E2E_Header_Type E2E_Header[0];
} someIP_E2E_Header;

typedef struct someIP_Payload_t {
    Payload_Type payload[0];
} someIP_Payload;

typedef struct someIP_Header_t {
    MessageID_Type         messageID;
    Length_Type            length;
    RequestID_Type         requestID;
    Protocol_Version_Type  protocol_Version;
    Interface_Version_Type interface_Version;
    Message_Type           message;
    Return_Code_Type       return_code;
    someIP_E2E_Header*     E2E_Header;
    someIP_Payload*        payload;
} someIP_Header;

#endif //MY_AP_ADAPTIVE_AUTOSAR_SOMEIP_H
