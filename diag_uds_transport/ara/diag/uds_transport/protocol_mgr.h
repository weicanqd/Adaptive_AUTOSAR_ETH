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

/**
 * @attention: SWS_DM_00306
 */
class UdsTransportProtocolMgr {
public:

  /**
   * @brief: Type to tuple to pack UdsTransportProtocolHandlerId and ChannelId
   *         together, to form a global unique identifier of a UdsTransport
   *         Protocol channel.
   * @attention: SWS_DM_09021
   */
  using GlobalChannelIdentifier =
      std::tuple<UdsTransportProtocolHandlerID, ChannelID>;

  /**
   * @attention: SWS_DM_00384
   */
  enum class IndicationResult : std::uint8_t {
    kIndicationOK = 0,
    kIndicationOccupied = 1,
    kIndicationOverflow = 2,
  };

  /**
   * @attention: SWS_DM_00307
   */
  enum class TransmissionResult : std::uint8_t {
    kTransmitOk = 0,
    kTransmitFailed = 1,
  };

  /**
   * @brief: Notification call from the given transport channel, that is has
   *         been reestablished since the last (Re)start from the
   *         UdsTransportProtocolHandler to which this channel belongs.
   *         To active this notification a previous call to NotifyReestablishment()
   *         has to be done.
   * @param globalChannelId : transport protocol channel, which is available again.
   * @attention: SWS_DM00313
   */
  virtual void ChannelReestablished (GlobalChannelIdentifier globalChannelId) = 0;

  /**
   * @brief : Hands over a valid received message(currently this is only a
   *          request type) from transport layer to session layer. It corresponds
   *          to T_Data.ind of Figure 2 from ISO 14299-2. The behavior is
   *          asynchronously. I.e. the UdsMessage is handled over to Session
   *          Layer and it is expected, that it "instantly" returns, which means,
   *          the real processing of the message shall be done asynchronously.
   * @param message : The UDS message ptr with the request. Ownership of the
   *                  UdsMessage is given back to the generic DM core here.
   * @attention: SWS_DM_00311
   */
  virtual void HandleMessage(UdsMessagePtr message) = 0;

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
   * @attention: SWS_DM_00309
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

  /**
   * @brief Notification from handler, that it has stopped now(e.g. closed down
   *        network connections, freed resources, etc...)
   *        This callback is expected as a reaction from handler to a call to
   *        UdsTransportProtocolHandler::Stop.
   * @param handlerId: Indication, which plugin stopped.
   * @attention: SWS_DM_00314
   */
  virtual void HandlerStopped(
      UdsTransportProtocolHandlerID handlerId
      ) = 0;
};
} // namespace uds_transport
} // namespace diag
} // namespace ara

#endif // CYY_AP_PROTOCOL_MGR_H
