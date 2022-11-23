/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.22.2022
 */

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef CYY_AP_SOMEIP_SD_H
#define CYY_AP_SOMEIP_SD_H
/* ========================================================================== */
/*                            Includes                                        */
/* ========================================================================== */
#include "someIP.h"

/* ========================================================================== */
/*                             Macros                                         */
/* ========================================================================== */
#define SOMEIP_SD_OPTION_IPV4_TCP     (0x06)
#define SOMEIP_SD_OPTION_IPV4_UDP     (0x11)

/* ========================================================================== */
/*                       Data struct define                                   */
/* ========================================================================== */
/**
   SOME/IP SD header Format:
   -----------------------------------------------------------------------------------------
   |                                    Message ID [32bit]                                 |
   -----------------------------------------------------------------------------------------
   |                                     Length [32bit]                                    |
   -----------------------------------------------------------------------------------------
   |                                    Request ID [32bit]                                 |
   -----------------------------------------------------------------------------------------
   | Protocol Version 8bit | interface Version 8bit | Message type 8bit | Return Code 8bit |
   -----------------------------------------------------------------------------------------
   |     Flags[8bit]       |                         Reserved[24bit]                       |
   -----------------------------------------------------------------------------------------
   |                              Length fo Entries Array[32bit]                           |
   -----------------------------------------------------------------------------------------
   |                                     Entries Array                                     |
   -----------------------------------------------------------------------------------------
   |                             Length of Options Array[32bit]                            |
   -----------------------------------------------------------------------------------------
   |                                     Options Array                                     |
   -----------------------------------------------------------------------------------------
 */

typedef struct someIP_SD_entries_t {
  uint32 length_of_entries;
  uint8  entries_array[0];
} someIP_SD_entries;

typedef struct someIP_SD_options_t {
  uint32 length_of_entries;
  uint8  entries_array[0];
} someIP_SD_options;

typedef struct someIP_SD_flags_t {
  /* CYY: reboot flag of someIP SD header shall be set to one for all messages after reboot
   * until the Session-ID in the someIP header wraps around and thus stars with 1 again.
   * After this wrp around the Reboot Flag is set to 0.*/
  uint8 reboot_flag   :1;
  uint8 unicast_flag  :1;
  uint8 unused        :6;
} someIP_SD_flags;

typedef enum someIP_SD_type_filed_enum_t {
  FIND_SERVICE       = 0x00,
  OFFER_SERVICE      = 0x01,
  STOP_OFFER_SERVICE = 0x03
} someIP_SD_type_filed_enum;

typedef struct someIP_SD_entry_t {
  someIP_SD_type_filed_enum type_field;
  uint8                     index_first_option_run;
  uint8                     index_second_option_run;
  uint8                     numbers_of_option_1 :4;
  uint8                     numbers_of_option_2 :4;
  uint16                    service_id;
  uint16                    instance_id;
  uint8                     major_version;
  /* Describes the lifetime of the entry in seconds */
  uint32                    ttl :24;
  uint32                    minor_version;
} someIP_SD_entry;

typedef struct someIP_SD_entry_group_t {
  someIP_SD_type_filed_enum type_field;
  uint8                     index_first_option_run;
  uint8                     index_second_option_run;
  uint8                     numbers_of_option_1 :4;
  uint8                     numbers_of_option_2 :4;
  uint16                    service_id;
  uint16                    instance_id;
  uint8                     major_version;
  /* Describes the lifetime of the entry in seconds */
  uint32                    ttl :24;
  uint32                    minor_version;
  uint16                    reserved :12;
  uint8                     counter :4;
  uint16                    event_group_id;
} someIP_SD_entry_group;

typedef struct someIP_SD_option_format_t {
  uint16 length;
  uint8  type;
  uint8  discardable_flag :1;
} someIP_SD_option_format;

typedef struct someIP_SD_Header_t {
  someIP_Header *     someIP_header;
  someIP_SD_flags *   flag;
  someIP_SD_entries * entries;
  someIP_SD_options * options;
} someIP_SD_Header;

someIP_SD_option_format LB_option = {
    .length           = 0x0005,
    .type             = 0x02,
    .discardable_flag = 1,
};

someIP_SD_option_format IPV4_endpoint_option = {
    .length           = 0x0009,
    .type             = 0x04,
    .discardable_flag = 0,
};

someIP_SD_option_format IPV4_multicast_option = {
    .length           = 0x0009,
    .type             = 0x14,
    .discardable_flag = 0,
};

someIP_SD_option_format IPV4_SD_endpoint_option = {
    .length           = 0x0009,
    .type             = 0x24,
    .discardable_flag = 0,
};

someIP_SD_option_format IPV6_endpoint_option = {
    .length           = 0x0015,
    .type             = 0x06,
    .discardable_flag = 0,
};

someIP_SD_option_format IPV6_SD_endpoint_option = {
    .length           = 0x0015,
    .type             = 0x26,
    .discardable_flag = 0,
};

someIP_SD_option_format IPV6_multicast_option = {
    .length           = 0x0015,
    .type             = 0x16,
    .discardable_flag = 0,
};

typedef struct someIP_SD_LB_option_t {
  /* LB_option have default values */
  someIP_SD_option_format * LB_option;
  uint16                    priority;
  uint16                    weight;
} someIP_SD_LB_option;

typedef struct someIP_SD_IPV4_endpoint_option_t {
  /* IPV4_option have default values */
  someIP_SD_option_format   IPV4_endpoint_option;
  uint32                    IPV4_address;
  uint8                     reserved;
  uint8                     protocol;
} someIP_SD_IPV4_endpoint_option;

typedef struct someIP_SD_IPV4_multicast_option_t {
  /* IPV4_option have default values */
  someIP_SD_option_format   IPV4_endpoint_option;
  uint32                    IPV4_address;
  uint8                     reserved;
  /* PROTOCOL MUST BE UDP */
  uint8                     protocol;
} someIP_SD_IPV4_multicast_option;

typedef struct someIP_SD_IPV6_endpoint_option_t {
  /* IPV4_option have default values */
  someIP_SD_option_format * IPV6_endpoint_option;
  uint8                     IPV6_address[16];
  uint8                     reserved;
  uint8                     protocol;
} someIP_SD_IPV6_endpoint_option;

typedef struct someIP_SD_IPV6_multicast_option_t {
  /* IPV4_option have default values */
  someIP_SD_option_format * IPV6_endpoint_option;
  uint8                     IPV6_address[16];
  uint8                     reserved;
  /* PROTOCOL MUST BE UDP */
  uint8                     protocol;
} someIP_SD_IPV6_multicast_option;

#endif // CYY_AP_SOMEIP_SD_H

#pragma clang diagnostic pop