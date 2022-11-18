/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.18.2022
*/

#ifndef CYY_AP_STD_TYPES_H
#define CYY_AP_STD_TYPES_H

#include "Platform_Types.h"

typedef uint8 Std_ReturnType;

typedef unsigned char StatusType;

/* SWS_Std_00007 */
#define STD_HIGH    0x01u   /* Physical state 5V or 3.3V             */
#define STD_LOW     0x00u   /* Physical state 0V                     */

/* SWS_Std_00013 */
#define STD_ACTIVE  0x01u   /* Logical state active                  */
#define STD_IDLE    0x00u   /* Logical state idle                    */

/* SWS_Std_00010 */
#define STD_ON      0x01u
#define STD_OFF     0x00u

#define E_OK      0x00u
#define E_NOT_OK    0x01u

#endif // CYY_AP_STD_TYPES_H
