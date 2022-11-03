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

};

}
}


#endif // CYY_AP_DIAG_UDS_NRC_ERROR_DOMAIN_H
