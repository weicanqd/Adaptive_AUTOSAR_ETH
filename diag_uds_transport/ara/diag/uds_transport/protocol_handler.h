/***
 *  Author: yiyang.cai@pm.me
 *  DOC   : AUTOSAR_SWS_Diagnostics R21-11
 *  Date  : 11.1.2022
 */

#ifndef CYY_AP_PROTOCOL_HANDLER_H
#define CYY_AP_PROTOCOL_HANDLER_H

#include "protocol_mgr.h"
#include "protocol_types.h"
#include "uds_message.h"

namespace ara {
namespace diag {
namespace uds_transport {

/**
 * @brief:  Abstract Class, which a specific UDS Transport Protocol(Plugin) shall
 *          subclass.
 * @attention SWS_DM_00315
 */
class UdsTransportProtocolHandler {
public:

  /**
   * @brief Result of Initializer
   *
   * @attention SWS_DM_09017
   */
  enum class InitializationResult : std::uint8_t {
    kInitializeOK = 0,
    kInitializeFailed = 1,
  };

  /**
   * @brief Constructor of UdsTransportProtocolHandler
   *
   * @param handlerId: The handler Id used by DM to identify this handler. This
   *                   is just a number/identification given by the DM core
   *                   when instantiating a udsTransportProtocolHandler instance
   *                   to be able to distinguish it from other handler-plugins
   *                   or built-in UdsTransportProtocolHandler implementations.
   * @param transportProtocolMgr: Reference to UdsTransportProtocolMgr owned by
   *                              this DM, with which UdsTransportProtocolHandler
   *                              instance shall interact.
   * @attention SWS_DM_09015
   */
  inline UdsTransportProtocolHandler(
      UdsTransportProtocolHandlerID const handlerId,
      UdsTransportProtocolMgr &transportProtocolMgr);

  /**
   * @brief: Destructor of UdsTransportProtocolHandler
   * @attention: SWS_DM_09016
   */
  virtual ~UdsTransportProtocolHandler();

  /**
   * @brief: Return the UdsTransportProtocolHandlerId, which was given to the
   *         implementation during construction.
   * @return UdsTransportProtocolHandlerID
   * @attention: SWS_DM_00325
   */
  virtual UdsTransportProtocolHandlerID GetHandlerId() const;

 /**
  * @brief  Initializes handler.
  *        Must be called before Start(). The idea is to have "initialization"
  *        of handler-plugin separated from its ctor.
  * @return InitializationResult
  * @attention SWS_DM_00319
  */
  virtual InitializationResult Initialize() = 0;

  /**
   * @brief: Tells the UdsTransportProtocolHandler, that it shall notify the DM
   *         core via UdsTransportProtocolMgr::ChannelReestablished() if the
   *         given channel has been re-established after next UdsTransportProtocolHandler::Start().
   *         The main purpose of this method is to allow DM to provide an
   *         ECU-Reset(0x11 service), with configuration option "Pos. response
   *         AFTER reset". In this scenario the request of 0x11 will be received
   *         on a certain channel with identifying tuple<p_x, p_y>(GlobalChannelIdentifier)
   *         Then the ECU-Reset takes place and after ECU-Reset all plugins/
   *         UdsTransportProtocolHandlers get restarted via call to Start().
   *         Now there are two exceptions, when this method has been called
   *         before and return "TRUE": IF the same remote client connects to
   *         the UdsProtocolHandler, it shall get a channel identification with
   *         the same identifying tuple<p_x, c_y> as last time. It shall call
   *         this method.
   * @param channelId
   * @return
   * @attention: SWS_DM_00326
   */
  virtual bool NotifyReestablishment(ChannelID channelId) = 0;

  /**
   * @brief Start Processing the implemented Uds Transport Protocol.
   *        The implementation shall call its superclass Start() method as there
   *        might be some stack specific implementation. Implementation shall be
   *        asynchronous as DM might start many/different UdsTransportProtocolHandler
   *        in parallel and strong serialization of all those starts just
   *        unnecessarily slows down DM startup.
   * @attention SWS_DM_00322
   */
  virtual void Start() = 0;

  /**
   * @brief Method ot indicate that this Uds TransportProtocolHandler should
   *        terminated. If UdsTransportProtocolHandler has stopped, it shall call
   *        UdsTransportProtocolMgr::HandlerStopped(UdsTransportProtocolHandlerID).
   *        After return from Stop(), the handler-plugin shall NOT call to
   *        UdsTransportProtocolMgr with any other method but UdsTransportProto-
   *        -colMgr::HandlerStopped();
   * @attention SWS_DM_00323
   */
  virtual void Stop() = 0;

  /**
   * @brief: Transmit a UDS message via the underlying UDS Protocol channel.
   *         This transmit API covers T_Data.req of ISO 14229-2 Figure 2.
   * @param message  : The message to be transmitted as a UdsMessage::Ptr.
   *                   UdsTransportProtocolHandler has to give back this Ptr
   *                   via UdsTransportProtocolMgr::TransmitConfirmation() to
   *                   signal, that it is done with this message.
   * @param channelId: Identification of channel on which to transmit.
   * @attention: SWS_DM_00327
   */
  virtual void Transmit(UdsMessageConstPtr message, ChannelID channelId) = 0;

  /**
   * @brief: Return corresponding periodic TP handler.
   * @return ara::core::Result<UdsTransportProtocolHandler&>:
   *         UdsTransportProtocolPeriodicHandler reference if periodic transmissions
   *         are supported on this transport protocol, an error if not supported.
   * @attention: SWS_DM_01068
   */
  virtual ara::core::Result<UdsTransportProtocolHandler&> GetPeriodicHandler();
};
} // namespace uds_transport
} // namespace diag
} // namespace ara

#endif // CYY_AP_PROTOCOL_HANDLER_H
