/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.18.2022
*/

#ifndef CYY_AP_PLATFORM_TYPES_H
#define CYY_AP_PLATFORM_TYPES_H

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*
 * AUTOSAR integer data types
 */
typedef signed char         sint8;          /*        -128 .. +127           */
typedef unsigned char       uint8;          /*           0 .. 255            */
typedef signed short        sint16;         /*      -32768 .. +32767         */
typedef unsigned short      uint16;         /*           0 .. 65535          */
typedef signed long         sint32;         /* -2147483648 .. +2147483647    */
typedef unsigned long       uint32;         /*           0 .. 4294967295     */
typedef signed long long    sint64;         /* 63 bit + 1 bit sign           */
typedef unsigned long long  uint64;         /* 64 bit                        */

typedef unsigned long       uint8_least;    /* At least 8 bit                */
typedef unsigned long       uint16_least;   /* At least 16 bit               */
typedef unsigned long       uint32_least;   /* At least 32 bit               */
typedef signed long         sint8_least;    /* At least 7 bit + 1 bit sign   */
typedef signed long         sint16_least;   /* At least 15 bit + 1 bit sign  */
typedef signed long         sint32_least;   /* At least 31 bit + 1 bit sign  */
typedef unsigned char       boolean;        /* for use with TRUE/FALSE       */

typedef float               float32;
typedef double              float64;

#ifndef TRUE                                /* conditional check */
#define TRUE      1
#endif

#ifndef FALSE                               /* conditional check */
#define FALSE     0
#endif


#endif // CYY_AP_PLATFORM_TYPES_H
