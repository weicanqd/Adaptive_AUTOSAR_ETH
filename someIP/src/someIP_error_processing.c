/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_PRS_SOMEIPProtocol AUTOSAR FO R21-11
*  Date  : 11.16.2022
 */
/* ========================================================================== */
/*                                Include                                     */
/* ========================================================================== */
#include "someIP.h"

/* ========================================================================== */
/*                       Static function definition                           */
/* ========================================================================== */

Std_ReturnType someIP_error_handing(const someIP_Header tag) {
  Std_ReturnType return_value = E_NOT_OK;

  /* Protocol Version supported? */
  if (TRUE) {
    return_value = E_OK;
  } else {
    return_value = E_WRONG_PROTOCOL_VERSION;
  }

  /* Service ID OK? */
  if (TRUE) {
    return_value = E_OK;
  } else {
    return_value = E_UNKNOWN_SERVICE;
  }

  /* Interface Version OK? */
  if (TRUE) {
    return_value = E_OK;
  } else {
    return_value = E_WRONG_INTERFACE_VERSION;
  }

  /* Method OK? */
  return_value = E_UNKNOWN_METHOD;

  /* Message Type Supported? */
  if (TRUE) {
    return_value = E_OK;
  } else {
    return_value = E_WRONG_MESSAGE_TYPE;
  }

  /* Message Type as configured? */

}