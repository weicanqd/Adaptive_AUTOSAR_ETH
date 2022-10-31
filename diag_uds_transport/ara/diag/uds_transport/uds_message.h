/***
 *  Author: yiyang.cai@pm.me
 *  DOC   : AUTOSAR_SWS_Diagnostics R21-11
 *  Date  : 10.31.2022
 */

#ifndef CYY_AP_UDS_MESSAGE_H
#define CYY_AP_UDS_MESSAGE_H

#include <cstdint>

namespace ara {
namespace diag {
namespace uds_transport {
class UdsMessage {
public:
  using Address = std::uint16_t;

  enum class TargetAddressType : std::uint8_t {
    kPhysical = 0,
    kFunctional = 1,
  };
};
} // namespace uds_transport
} // namespace diag
} // namespace ara
#endif // CYY_AP_UDS_MESSAGE_H
