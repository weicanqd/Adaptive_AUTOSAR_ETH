/***
 *  Author: yiyang.cai@pm.me
 *  DOC   : AUTOSAR_SWS_Diagnostics R21-11
 *  Date  : 10.31.2022
 */

#ifndef CYY_AP_PROTOCOL_MGR_H
#define CYY_AP_PROTOCOL_MGR_H

#include "protocol_types.h"
#include "uds_message.h"

namespace ara {
namespace diag {
namespace uds_transport {
class UdsTransportProtocolMgr {
public:
  using GlobalChannelIdentifier =
      std::tuple<UdsTransportProtocolHandlerID, ChannelID>;

  auto IndicateMessage(ara::diag::uds_transport::UdsMessage::Address sourceAddr,
                       ara::diag::uds_transport::UdsMessage::Address targetAddr,
                       ara::diag::uds_transport::UdsMessage::TargetAddressType,
                       GlobalChannelIdentifier globalChannel)
};
} // namespace uds_transport
} // namespace diag
} // namespace ara

#endif // CYY_AP_PROTOCOL_MGR_H
