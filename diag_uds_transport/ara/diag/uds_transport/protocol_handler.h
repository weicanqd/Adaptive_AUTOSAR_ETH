/***
 *  Author: yiyang.cai@pm.me
 *  DOC   : AUTOSAR_SWS_Diagnostics R21-11
 *  Date  : 11.1.2022
 */

#ifndef CYY_AP_PROTOCOL_HANDLER_H
#define CYY_AP_PROTOCOL_HANDLER_H

#include "protocol_mgr.h"
#include "protocol_types.h"

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
      UdsTransportProtocolMgr &transportProtocolMgr)
      : transportProtocolMgr_{transportProtocolMgr}, handlerId_{handlerId} {}

/**
 * @brief  Initializes handler. Must be called before Start(). The idea is to
 *         have "initialization" of handler-plugin separated from its ctor.
 * @return InitializationResult
 * @attention SWS_DM_00319
 */
  virtual InitializationResult Initialize() = 0;

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

protected:
  UdsTransportProtocolMgr &transportProtocolMgr_;

private:
  UdsTransportProtocolHandlerID const handlerId_;
};
} // namespace uds_transport
} // namespace diag
} // namespace ara

#endif // CYY_AP_PROTOCOL_HANDLER_H
