/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.3.2022
*/

#ifndef CYY_AP_DIAG_UDS_NRC_ERROR_DOMAIN_H
#define CYY_AP_DIAG_UDS_NRC_ERROR_DOMAIN_H

#include <cstdint>

namespace ara {
namespace diag {

/**
 * @brief: Specifies the types of internal errors that can occur upon calling
 *         Offer or ReportMonitorAction
 * @attention: SWS_DM_0526
 */
enum class DiagUdsNrcErrc : std::int32_t {
  kGeneralReject = 0x10,
  kServiceNotSupported = 0x11,
  kSubfunctionNotSupported = 0x12,
  kIncorrectMessageLengthOrInvalidFormat = 0x13,
  kResponseToolLong = 0x14,
  kBusyRepeatRequest = 0x21,
  kConditionsNotCorrect = 0x22,
  kRequestSequenceError = 0x24,
  kNoResponseFromSubnetComponent = 0x25,
  kFailurePreventsExecutionOfRequestedAction = 0x26,
  kRequestOutOfRange = 0x31,
  kSecurityAccessDenied = 0x33,
  kInvalidKey = 0x35,
  kExceedNumberOfAttempts = 0x36,
  kRequiredTimeDelayNotExpired = 0x37,
  kUploadDownloadNotAccepted = 0x70,
  kTransferDataSuspended = 0x71,
  kGeneralProgrammingFailure = 0x72,
  kWrongBlockSequenceCounter = 0x73,
  kSubFunctionNotSupportedInActiveSession = 0x7E,
  kServiceNotSupportedInActiveSession = 0x7F,
  kRpmTooHigh = 0x81,
  kRpmTooLow = 0x82,
  kEngineIsRunning = 0x83,
  kEngineIsNotRunning = 0x84,
  kEngineRunTimeTooLow = 0x85,
  kTemperatureTooHigh = 0x86,
  kTemperatureTooLow = 0x87,
  kVehicleSpeedTooLow = 0x88,
  kVehicleSpeedTooHigh = 0x89,
  kThrottlePedalTooHigh = 0x8A,
  kThrottlePedalTooLow = 0x8B,
  kTransmissionRangeNotInNeutral = 0x8C,
  kTransmissionRangeNotInGear = 0x8D,
  kBrakeSwitchNotClosed = 0x8F,
  kShifterLeverNotInPark = 0x90,
  kTorqueConverterClutchLocked = 0x91,
  kVoltageTooHigh = 0x92,
  kVoltageTooLow = 0x93,
  kResourceTemporarilyNotAvailable = 0x94,
  kNoProcessingNoResponse = 0xFF,
};

/**
 * @brief: Exception type thrown by Diag classes
 * @attention: SWS_DM_00527
 */
class DiagUdsNrcException : public Exception {

  /**
   * @brief: Construct a new DiagException from an ErrorCode
   * @param err : the Error code
   * @attention: SWS_DM_00528
   */
  inline DiagUdsNrcException(ara::core::Error err) noexcept;

};

/**
 * @brief: Error domain for errors origination from several diagnostic classes.
 * @uniqueID: 0x8000000000000411
 * @attention: SWS_DM_00529
 */
class DiagUdsNrcErrorDomain final : public ErrorDomain {
  /**
   * @brief: Alias for the error code value enumeration.
   * @attention: SWS_DM_00530
   */
  using Errc = DiagUdsNrcErrc;

  /**
   * @brief: Alias for the exception base class.
   * @attention: SWS_DM_00531
   */
  using Exception = DiagUdsNrcException;

  /**
   * @brief: Default constructor.
   * @attention: SWS_DM_00532
   */
   constexpr DiagUdsNrcErrorDomain() noexcept;

   /**
    * @brief: Return the "shortname" ApApplicationErrorDomain.SN of this error domain
    * @return: const char* : "DiagUdsNrc"
    * @attention: SWS_DM_00533
    */
   const char* Name() const noexcept override;

   /**
    * @brief: Translate an error code value into a text message
    * @return : const char* : "the text message, never nullptr"
    * @attention: SWS_DM_00534
    */
   const char* Message(ara::core::ErrorDomain::CodeType errorCode) const noexcept override;

   /**
    * @brief: Throw the exception type corresponding to the given ErrorCode
    * @param errorCode
    * @attention: SWS_DM_00535
    */
   void ThrowAsException(const ara::core::ErrorCode &errorCode) const noexcept(false) override;

   /**
    * @brief: Obtain the reference to the single global DiagUdsNrcErrorDomain instance.
    * @return: const ara::core::ErrorDomain& : reference to the DiagUdsNrcErrorDomain instance
    * @attention: SWS_DM_00536
    */
   constexpr const ara::core::ErrorDomain& GetDiagUdsNrcDomain() noexcept;
};

/**
 * @brief: Create a new ErrorCode for DiagUdsNrcErrorDomain with the given support
 *         data type and message.
 * @param: code : an enumeration value from diag_errc
 * @param: data : a vendor-defined supplementary value.
 * @attention: SWS_DM_00537
 */
constexpr ara::core::ErrorCode MakeErrorCode(DiagUdsNrcErrc code,
                                             ara::core::ErrorDomain::SupportDataType data) noexcept;

}
}


#endif // CYY_AP_DIAG_UDS_NRC_ERROR_DOMAIN_H
