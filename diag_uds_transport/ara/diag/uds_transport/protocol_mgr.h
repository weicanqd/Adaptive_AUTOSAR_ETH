/***
 *  Author: yiyang.cai@pm.me
 *  DOC   : AUTOSAR_SWS_Diagnostics R21-11
 *  Date  : 10.31.2022
 */

#ifndef CYY_AP_PROTOCOL_MGR_H
#define CYY_AP_PROTOCOL_MGR_H

#include "protocol_types.h"
#include "uds_message.h"
#include <cstdint>

namespace ara {
namespace diag {
namespace uds_transport {
class UdsTransportProtocolMgr {
public:
  using GlobalChannelIdentifier =
      std::tuple<UdsTransportProtocolHandlerID, ChannelID>;

  /**
   * @brief                 Indicates a message start. This is an interface,
   *                        which is just served/called by UdsTransport
   *                        ProtocolHandlers, which return true from
   *                        UdsTransportProtocolHandlers::isStartOfMessage
   *                        IndicationSupported().
   *
   * @param sourceAddr      UDS source address of message.
   * @param targetAddr      UDS target address of message.
   * @param type            Indication whether its is phys/func request.
   * @param globalChannel   transport protocol channel on which message start
   *                        happened.
   * @param size            Size in bytes of the UDS message starting from SID.
   * @param priority        The priority of given message, used for
   *                        prioritization of conversations.
   * @param protocolKind    Identifier of protocol kind associated to message.
   * @param payloadInfo     View onto the first received payload bytes, if any.
   *                        This view shall be used only within this function
   *                        call. It is recommended that the TP provides at
   *                        least the first two bytes of the request message, so
   *                        the DM can identify a functional TesterPresent.
   * @return                Pair of IndicationResult and pointer to UDS message
   *                        owned/created by DM core and returned to the handler
   *                        to get filled.
   */
  virtual auto
  IndicateMessage(ara::diag::uds_transport::UdsMessage::Address sourceAddr,
                  ara::diag::uds_transport::UdsMessage::Address targetAddr,
                  ara::diag::uds_transport::UdsMessage::TargetAddressType type,
                  GlobalChannelIdentifier globalChannel,
                  std::size_t size,
                  ara::diag::uds_transport::Priority priority,
                  ara::diag::uds_transport::ProtocolKind protocolKind,
                  ara::core::Span<const std::uint8_t> payloadInfo)
      -> std::pair<IndicationResult, UdsMessagePtr> = 0;
};
} // namespace uds_transport
} // namespace diag
} // namespace ara

#endif // CYY_AP_PROTOCOL_MGR_H
