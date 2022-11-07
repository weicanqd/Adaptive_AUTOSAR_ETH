/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.7.2022
 */

#ifndef CYY_AP_MONITOR_H
#define CYY_AP_MONITOR_H

namespace ara {
namespace diag {

#include <cstdint>

class monitor {

  /**
   * @brief: Monitor constructor for Monitors with Monitor-internal debouncing.
   * @param specifier : InstanceSpecifier to an Port prototype of an DiagnosticMonitorInterface.
   * @param initMonitor : Possibility to register an InitMonitor callback
   * @param getFaultDetectionCounter : Possibility to register a function to get the current
   *                                   FDC for this event.
   * @attention: SWS_DM_00548
   */
  Monitor (const ara::core::InstanceSpecifier &specifier,
          std::function<void(InitMonitorReason)> initMonitor,
          std::function< std::int8_t()> getFaultDetectionCounter);

  /**
   * @brief: Monitor constructor for Monitors with time-based debouncing.
   * @param specifier : InstanceSpecifier to an PortPrototype of an DiagnosticMonitorInterface
   * @param initMonitor : Possibility to register an InitMonitor callback
   * @param defaultValues : Default values for CounterBased debouncing
   * @attention: SWS_DM_00549
   */
  Monitor (const ara::core::InstanceSpecifier &specifier,
          std::function<void(InitMonitorReason)> initMonitor,
          TimeBased defaultValues);

  /**
   * @brief: Monitor constructor for Monitors with counter-based debouncing.
   * @param specifier : InstanceSpecifier to an PortPrototype of an DiagnosticMonitorInterface
   * @param initMonitor : Possibility to register an InitMonitor callback
   * @param defaultValues : Default values for CounterBased debouncing
   * @attention: SWS_DM_00550
   */
  Monitor (const ara::core::InstanceSpecifier &specifier,
          std::function<void(InitMonitorReason)> initMonitor,
          CounterBased defaultValues);

  /**
   * @brief: Function to report the status information being relevant for error monitoring paths.
   * @param action : Contains either the last (un-)qualified test result of
   *                 the diagnostic monitor or commands to control the
   *                 debouncing or to force a prestorage.
   * @attention: SWS_DM_00543
   */
  void ReportMonitorAction (MonitorAction action);

  /**
   * @brief: This Offer will enable the DM to forward request messages to this handler.
   * @attention: SWS_DM_01088
   */
  ara::core::Result<void> Offer();

  /**
   * @brief: This StopOffer will disable the forwarding of request messages from DM.
   * @attention: SWS_DM_01089
   */
  void StopOffer();
};

}
}

#endif // CYY_AP_MONITOR_H
