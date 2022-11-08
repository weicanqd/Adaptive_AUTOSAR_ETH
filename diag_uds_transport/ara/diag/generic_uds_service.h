/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.7.2022
 */

#ifndef CYY_AP_GENERIC_UDS_SERVICE_H
#define CYY_AP_GENERIC_UDS_SERVICE_H

#include <cstdint>
#include "reentrancy.h"
#include "meta_info.h"

namespace ara {
namespace diag {

/**
 * @brief: Generic UDS interface
 * @attention: SWS_DM_00602
 */
class GenericUdsService {
  /**
   * @brief: Response data of positive response message.
   * @attention: SWS_DM_00578
   */
  struct OperationOutput {
    /**
     * @brief: Content of positive response message (without SID)
     * @attention: SWS_DM_00632
     */
    ara::core::Vector<std::uint8_t> responseData;
  };

  /**
   * @brief: Constructor of GenericUdsService
   * @param specifier : An instanceSpecifier linking this instance with.
   * @param reentrancyType : specifies if interface is callable fully- or non-reentrant
   * @attention: SWS_DM_00616
   */
  inline GenericUDSService (const ara::core::InstanceSpecifier &specifier,
                           ReentrancyType reentrancyType);

  /**
   * @brief: Destructor of GenericUDSService.
   * @attention: SWS_DM_00584
   */
  virtual ~GenericUDSService () noexcept=default;

  /**
   * @brief: This Offer will enable the DM to forward request messages to this handler.
   * @attention: SWS_DM_00619
   */
  ara::core::Result<void> Offer();

  /**
   * @brief: This StopOffer will disable the forwarding of request messages from DM.
   * @attention: SWS_DM_00620
   */
  void StopOffer ();

  /**
   * @brief: Called for any request message.
   * @param sid : Diagnostic Request Service Identifier.
   * @param requestData : Diagnostic request data (starting after SID).
   * @param metaInfo : MetaInfo of the request
   * @param cancellationHandler : Set if the current conversation is canceled.
   * @attention: SWS_DM_618
   */
  virtual ara::core::Future<OperationOutput>
  HandleMessage (std::uint8_t sid,
                ara::core::Span< std::uint8_t > requestData,
                MetaInfo &metaInfo,
                CancellationHandler cancellationHandler) = 0;
};

}
}

#endif // CYY_AP_GENERIC_UDS_SERVICE_H
