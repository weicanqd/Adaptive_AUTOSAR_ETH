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

  /**
   * @brief: Default constructor.
   * @attention: SWS_DM_00520
   */
  constexpr DiagErrorDomain() noexcept;

  /**
   * @brief: Return the shortname ApApplicationErrorDomain.SN of this domain.
   * @return const char* : Diag name
   * @attention: SWS_DM_00521
   */
  const char* Name() const noexcept override;

  /**
   * @brief: Translate an error code value into a test message.
   * @param errorCode : the error code value
   * @return const char* : the test message, should never null ptr
   * @attention: SWS_DM_00522
   */
  const char* Message(
      ara::core::ErrorDomain::CodeType errorCode ) const noexcept override;

  /**
   * @brief: Throw the exception type corresponding to the given ErrorCode.
   * @param errorCode : the ErrorCode instance
   * @attention: SWS_DM_00523
   */
  void ThrowAsException(const ara::core::ErrorCode &errorCode) const noexcept(false) override;

  /**
   * @brief: Obtain the reference to the signal global DiagErrorDomain with the
   *         given support data type.
   * @attention: SWS_DM_00524
   */
  constexpr const ara::core::ErrorDomain& GetDiagDomain() noexcept;

  /**
   * @brief: Create a new ErrorCode for DiagError Domain with the given support data type.
   * @param: code : an enumeration value from future_errc.
   * @param: data : a vendor-defined supplementary value.
   * @return: ErrorCode: the new ErrorCode instance.
   * @attention: SWS_DM_00525
   */
  constexpr ara::core::ErrorCode MakeErrorCode(DiagErrc code,
                                               ara::core::ErrorDomain::SupportDataType data) noexcept;

};

/**
 * @brief: The DiagOfferErrc enumeration defines the error codes for the DiagOffer ErrorDomain.
 * @attention: SWS_DM_00599
 */
enum class DiagOfferErrc : ara::core::ErrorDomain::CodeType {
  /* The service is already offered */
  kAlreadyOffered = 101,

  /* monitor configuration dose not match dext */
  kConfigurationMismatch = 102,

  /* monitor debouncing configuration invalid, e.g. passed threshold larger failed
   * threshold...*/
  kDebouncingConfigurationInconsistent = 103,
};

/**
 * @brief: Create a new ErrorCode for DiagOfferErrorDomain with the given support DataType.
 * @param: code : an enumeration value from future_errc
 * @param: data : a vendor_defined supplementary value
 * @return: ara::core::ErrorCode : the new ErrorCode instance
 * @attention: SWS_DM_01005
 */
constexpr ara::core::ErrorCode MakeErrorCode(DiagOfferErrc code,
                                             ara::core::ErrorDomain::SupportDataType data) noexcept;

/**
 * @brief: Error domain for diagnostic errors.
 * @uniqueID: 0x8000000000000403
 * @attention: SWS_DM_00989
 */
class DiagOfferErrorDomain final : public ErrorDomain {
  /**
  * @brief: Alias for the exception base class.
  * @attention: SWS_DM_00991
  */
  using Exception = DiagException;

  /**
  * @brief: Alias for the error code value enumeration.
  * @attention: SWS_DM_00990
  */
  using Errc = DiagOfferErrc;

  /**
   * @brief: Throw the exception type corresponding to the given ErrorCode.
   * @param errorCode
   * @attention: SWS_DM_00995
   */
  void ThrowAsException(const ara::core::ErrorCode &errorCode) const noexcept(false) override;

  /**
   * @brief: Translate an error code value into a test message.
   * @param errorCode : the error code value
   * @return const char* : the test message, never nullptr
   * @attention: SWS_DM_00994
   */
  const char* Message(ara::core::ErrorDomain::CodeType errorCode) const noexcept override;

  /**
   * @brief: Return the shortname ApApplicationErrorDomain.SN of this error domain
   * @return : const char*
   * @attention: SWS_DM_00993
   */
  const char* Name() const noexcept override;

  /**
   * @brief: Default constructor
   * @attention: SWS_DM_00992
   */
  constexpr DiagOfferErrorDomain() noexcept;
};



} // namespace diag
} // namespace ara

#endif // CYY_AP_DIAG_ERROR_DOMAIN_H
