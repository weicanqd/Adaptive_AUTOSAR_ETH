/***
 *  Author: yiyang.cai@pm.me
 *  DOC   : AUTOSAR_SWS_Diagnostics R21-11
 *  Date  : 11.2.2022
 */
#ifndef CYY_AP_PROTOCOL_PERIODIC_HANDLER_H
#define CYY_AP_PROTOCOL_PERIODIC_HANDLER_H

#include "protocol_types.h"
#include "uds_message.h"
#include <cstdint>

namespace ara {
namespace diag {
namespace uds_transport {

/**
 * @brief: This class is to support 0x2A service from ISO
 * @attention: SWS_DM_01064
 */
class UdsTransportProtocolPeriodicHandler
{
  /**
   * @brief: Report the TP implementation and connection specific number of
   *         periodic messages.
   * @param channelId : The concrete connection to send over.
   * @return std::size_t
   * @attention: SWS_DM_01065
   */
  virtual std::size_t GetNumberOfPeriodicMessages(ChannelID channelId) const = 0;

  /**
   * @brief : Reports the maximum payload length supported for a single periodic
   *          transmission on the channel.
   * @param channelId : The concrete connection for which the maximum payload
   *                    length is reported.
   * @return : std::size_t
   * @attention: SWS_DM_01066
   */
  virtual std::size_t GetMaxPayloadLength(ChannelID channelId) const = 0;

  /**
   * @brief: Sends all messages in the list in given order. If one messages
   *         transmission fails, the send process is stopped and the
   *         PeriodicTransmitConfirmation is invoked with the number of sent
   *         messages and the same Vector with UdsMessages.
   * @param channelId
   * @param message
   */
  virtual void PeriodicTransmit(ChannelID channelId,
                                ara::core::Vector<UdsMessageConstPtr> message) = 0;
};

} // namespace uds_transport
} // namespace diag
} // namespace ara

#endif // CYY_AP_PROTOCOL_PERIODIC_HANDLER_H
