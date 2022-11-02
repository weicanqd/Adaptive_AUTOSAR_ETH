/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.2.2022
*/

#ifndef CYY_AP_DIAG_ERROR_DOMAIN_H
#define CYY_AP_DIAG_ERROR_DOMAIN_H

namespace ara {
namespace diag {

/**
 * @brief: Specifies the types of internal errors that can occur upon calling
 *         Offer or ReportMonitorAction.
 * @attention: SWS_DM_00514
 */
enum class DiagErrc : ara::core::ErrorDomain::CodeType
{
  /* The service is already offered. */
  kAlreadyOffered = 101,

  /* monitor configuration dose not match dext */
  kConfigurationMismatch = 102,

  /* monitor debouncing configuration invalid, e.g. passed threshold larger
   * than failed threshold... */
  kDebouncingConfigurationInconsistent = 103,

  /* Enable Conditions disabled, OC not started, ... */
  kReportIgnored = 104,

  /* e.g. kPreFailed with internal debouncing */
  kInvalidArgument = 105,

  /* Offer not called before reporting */
  kNotOffered = 106,

  /* generic issue, e.g. connection to DM lost */
  kGenericError = 107,

  /* No DTC available */
  kNoSuchDTC = 108,

  /* Interface is busy with processing. */
  kBusy = 109,

  /* Failed to process */
  kFailed = 110,

  /* A memory error occurred during processing. */
  kMemoryError = 111,

  /* A wrong DTC number was requested. */
  kWrongDtc = 112,

  /* Requested operation was rejected due to State Managements/machines internal state. */
  kRejected = 113,

  /* The requested Diagnostic reset type is not supported by the Diagnostic Address instance. */
  kResetTypeNotSupported = 114,

  /* Diagnostic request could not be performed successfully. */
  kRequestFailed = 115,

  /* The requested Diagnostic custom reset type is not supported by the Diagnostic Address instance. */
  kCustomResetTypeNotSupported = 116,

};

/**
 * @brief: Exception type thrown by Diag classes.
 * @attention: SWS_DM_00515
 */
class DiagException : public Exception {

  /**
   * @brief: Construct a new DiagException from an ERROR CODE
   * @param err : The error code
   * @attention: SWS_DM_00516
   */
  inline DiagException(ara::Core::ErrorCode err) noexcept;

};

/**
 * @brief: Error domain for diagnostic errors.
 * @UniqueID: 0x8000’0000’0000’0401
 * @attention: SWS_DM_00517
 */
class DiagErrorDomain final : public ErrorDomain {

  /**
   * @brief: Alias for the error code value enumeration.
   * @attention: SWS_DM_00518
   */
  using Errc = DiagErrc;

  /**
   * @brief: Alias for the exception base class.
   * @attention: SWS_DM_00519
   */
  using Exception = DiagException;

};

} // namespace diag
} // namespace ara

#endif // CYY_AP_DIAG_ERROR_DOMAIN_H
