/***
 *  Author: yiyang.cai@pm.me
 *  DOC   : AUTOSAR_SWS_Diagnostics R21-11
 *  Date  : 10.31.2022
 */

#ifndef CYY_AP_UDS_MESSAGE_H
#define CYY_AP_UDS_MESSAGE_H

#include <cstdint>
#include "protocol_types.h"

namespace ara {
namespace diag {

/**
 * @brief: Class represents an UDS message exchanged between DM generic core
 *         (UdsTransportProtocolMgr) and a specific implementation of
 *         UdsTransportProtocolHandler on diagnostic request reception path
 *         or diagnostic response transmission path.
 *         UdsMessage provides the storages for UDS requests/responses.
 *         Instances of UdsMessage(with optimized resource allocation) are only
 *         created by DM generic core. UdsTransportProtocolHandler read/write on it.
 * @attention: SWS_DM_00291
 */
namespace uds_transport {
class UdsMessage {
public:
  /**
   * @brief: Type of UDS source and target address.
   * @attention: SWS_DM_00293
   */
  using Address = std::uint16_t;

  /**
   * @brief: Type of the meta information attached to a UdsMessage
   * @attention: SWS_DM_00294
   */
  using MetaInfoMap = ara::core::Map<ara::core::String, ara::core::String>;

  /**
   * @brief: Type of target address in UdsMessage.
   * @attention: SWS_DM_00296
   */
  enum class TargetAddressType : std::uint8_t {
    kPhysical = 0,
    kFunctional = 1,
  };

protected:
  /**
   * @brief: Non public default constructor. The default constructor is
   * protected as we want to forbid, that UdsTransportProtocol handlers do
   * create UdsMessage on its own! Only DM is allowed to create and hands over
   *         UdsMessagePtrs to UdsTransportProtocolHandler.
   * @attention: SWS_DM_09012
   */
  UdsMessage() noexcept = default;

  /**
   * @bref: Copy constructing the UDS message.
   * @attention: SWS_DM_09011
   */
  UdsMessage(const UdsMessage &other) noexcept = default;

  /**
   * @brief: Move constructing the UDS message.
   * @attention: SWS_DM_09013
   */
  UdsMessage(UdsMessage &&other) noexcept = default;

  /**
   * @brief: Copy assigning the UDS message.
   * @param other: Object ot copy-assign from.
   * @return: UdsMessage &
   * @attention: SWS_DM_09014
   */
  UdsMessage &operator=(const UdsMessage &other) = default;

/**
 * @brief: Move assigning the UDS message.
 * @param other: Object ot copy-assign from.
 * @return : UdsMessage &
 * @attention: SWS_DM_09018
 */
  UdsMessage &operator=(UdsMessage &&other) noexcept = default;

  /**
   * @brief: Destructing the UDS message.
   * @attention: SWS_DM_09010
   */
  virtual ~UdsMessage();

  /**
   * @brief: Add new meta-info to this message.
   *         Typically called by the transport plugin to add channel specific
   *         meta-info.
   * @param metaInfo
   * @attention: SWS_DM_00302
   */
  virtual void AddMetaInfo(MetaInfoMap metaInfo);

  /**
   * @brief: Get the UDS message data starting with SID(A_Data as per ISO).
   *         Marked as "unsafe" with regard to threadsafety as implementation
   *         is allowed to resource allocation of buffer in the context of this
   *         call.
   * @return const uds_transport::ByteVector& : The entire payload data (A_Data)
   * @attention: SWS_DM_00300
   */
  virtual const uds_transport::ByteVector& GetPayload() const;

  /**
   * @brief: Get the source address of the UDS message.
   * @return Address : The source address of UDS message.
   * @attention: SWS_DM_00297
   */
  virtual Address GetSa() const noexcept;

  /**
   * @brief: Get the target address of the UDS message.
   * @return Address : The target address of UDS message.
   * @attention: SWS_DM_00298
   */
  virtual Address GetTa() const noexcept;

  /**
   * @brief: Get the target address type(func/phys) of the UDS message.
   * @return Address : The target address type of UDS message.
   * @attention: SWS_DM_00299
   */
  virtual Address GetTaType() const noexcept;
};
} // namespace uds_transport
} // namespace diag
} // namespace ara
#endif // CYY_AP_UDS_MESSAGE_H
