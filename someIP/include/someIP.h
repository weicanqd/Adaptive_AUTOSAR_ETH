/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.15.2022
*/

#ifndef MY_AP_ADAPTIVE_AUTOSAR_SOMEIP_H
#define MY_AP_ADAPTIVE_AUTOSAR_SOMEIP_H
/* ========================================================================== */
/*                            Includes                                        */
/* ========================================================================== */
#include <stdint.h>

/* ========================================================================== */
/*                       Data struct define                                   */
/* ========================================================================== */
typedef uint32_t MessageID_Type;
typedef uint32_t Length_Type;
typedef uint32_t RequestID_Type;
typedef uint8_t  Protocol_Version_Type;
typedef uint8_t  Interface_Version_Type;
typedef uint8_t  Message_Type;
typedef uint8_t  Return_Code_Type;
typedef uint8_t  E2E_Header_Type;
typedef uint8_t  Payload_Type;
typedef uint16_t Service_ID_Type;
typedef uint16_t Method_ID_Type;
typedef uint16_t Event_ID_Type;

typedef struct someIP_E2E_Header_t {
  E2E_Header_Type E2E_Header[0];
} someIP_E2E_Header;

typedef struct someIP_Payload_t {
  Payload_Type payload[0];
} someIP_Payload;

typedef struct someIP_Method_t {
  Service_ID_Type service_id;
  uint8_t         unused_zero : 1;
  Method_ID_Type  method_id   : 15;
} someIP_Method;

typedef struct someIP_EventID_t {
  Service_ID_Type service_id;
  uint8_t         unused_one  : 1;
  Event_ID_Type   event_id    : 15;
} someIP_EventID;

typedef union someIP_MessageID_union_t {
  someIP_Method  method_id;
  someIP_EventID event_id;
} someIP_MessageID_union;

typedef struct someIP_RequestID_t {
  uint8_t  client_id_prefix;
  uint8_t  client_id;
  uint16_t session_id;
} someIP_RequestID;

typedef enum someIP_Message_Type_enum_t {
  /* A request expecting a response */
  REQUEST = 0x00,

  /* A fire & forget request */
  REQUEST_NO_RETURN = 0x01,

  /* A request of a notification/event callback expecting no response */
  NOTIFICATION = 0x02,

  /* The response message */
  RESPONSE = 0x80,

  /* The response containing an error */
  ERROR = 0x81,

  /* A TP request expecting a response */
  TP_REQUEST = 0x20,

  /* A TP fire & forget request */
  TP_REQUEST_NO_RETURN = 0x21,

  /* A TP request of a notification/event callback expecting no response */
  TP_NOTIFICATION = 0x22,

  /* The TP response message */
  TP_RESPONSE = 0xA0,

  /* The TP response containing an error */
  TP_ERROR = 0xA1,
} someIP_Message_Type_enum;

typedef enum someIP_Return_Codes_enum_t {
  /* No error occurred */
  E_OK = 0x00,

  /* An unspecified error occurred */
  E_NOT_OK = 0x01,

  /* The request Service ID is unknown */
  E_UNKNOWN_SERVICE = 0x02,

  /* The request Method IDis unknown. Service ID is know */
  E_UNKNOWN_METHOD = 0x03,

  /* Service ID and Method ID are known. Application not running */
  E_NOT_READY = 0x04,

  /* System running the service is not reachable(internal error only) */
  E_NOT_REACHABLE = 0x05,

  /* A timeout occurred(internal error only) */
  E_TIMEOUT = 0x06,

  /* Version of SOMEIP protocol not supported */
  E_WRONG_PROTOCOL_VERSION = 0x07,

  /* Interface version mismatch */
  E_WRONG_INTERFACE_VERSION = 0x08,

  /* Deserialization error, so that payload cannot be deserialized. */
  E_MALFORMED_MESSAGE = 0x09,

  /* An unexpected message type was received (e.g. REQUEST_NO_RETURN for a method defined as REQUEST). */
  E_WRONG_MESSAGE_TYPE = 0x0A,

  /* Repeated E2E calculation error */
  E_E2E_REPEATED = 0x0B,

  /* Wrong E2E sequence error */
  E_E2E_WRONG_SEQUENCE = 0x0C,

  /* Not further specified E2E Error */
  E_E2E = 0x0D,

  /* E2E not available */
  E_E2E_NOT_AVAILABLE = 0x0E,

  /* No new data for E2E calculation present. */
  E_E2E_NO_NEW_DATA = 0x0F,
} someIP_Return_Codes_enum;


/**
   SOME/IP Header and E2E header Format:
   -----------------------------------------------------------------------------------------
   |                                    Message ID [32bit]                                 |
   -----------------------------------------------------------------------------------------
   |                                     Length [32bit]                                    |
   -----------------------------------------------------------------------------------------
   |                                    Request ID [32bit]                                 |
   -----------------------------------------------------------------------------------------
   | Protocol Version 8bit | interface Version 8bit | Message type 8bit | Return Code 8bit |
   -----------------------------------------------------------------------------------------
   |             E2E Header [variable size / Dependent on selected E2E profile]            |
   -----------------------------------------------------------------------------------------
   |                                 Payload [variable size]                               |
   -----------------------------------------------------------------------------------------
 */
typedef struct someIP_Header_t {
  /* CYY: message id may use to identify a rpc call to a method, or an event. */
  someIP_MessageID_union*    messageID;

  /* CYY: length should contain the length in BYTE starting from Request ID to the end. */
  Length_Type                length;

  /* CYY: request ID[32] = Client ID Prefix[8] + Client ID[8] + Session ID[16] */
  someIP_RequestID*          requestID;
  Protocol_Version_Type      protocol_Version;
  Interface_Version_Type     interface_Version;
  someIP_Message_Type_enum   message_type;
  someIP_Return_Codes_enum   return_code;

} someIP_Header;

#endif //MY_AP_ADAPTIVE_AUTOSAR_SOMEIP_H
