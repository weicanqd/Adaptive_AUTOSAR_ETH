/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.9.2022
 */

#ifndef CYY_AP_GENERIC_DATA_IDENTIFIER_H
#define CYY_AP_GENERIC_DATA_IDENTIFIER_H

#include <cstdint>
#include "meta_info.h"

/**
 * @brief: Generic DataIdentifier interface
 * @attention： SWS_DM_00607
 */
class GenericDataIdentifier {

  /**
   * @brief: Response data of positive respone message.
   * @attention: SWS_DM_00641
   */
  struct OperationOutput {

  };

  /**
   * @brief: Class of GenericDataIdentifier
   * @param specifier : InstanceSpecifier to an PortPrototype of an DiagnosticDataIdentifierGenericInterface
   * @param reentrancyType : specifies if interface is callable fully- or non-reentrant for reads, writes or both
   * @attention: SWS_DM_00634
   */
  inline GenericDataIdentifier (const ara::core::InstanceSpecifier &specifier,
                                DataIdentifierReentrancyType reentrancyType);

  /**
   * @brief: Destructor of class.
   * @attention: SWS_DM_00635.
   */
  virtual ~GenericDataIdentifier() noexcept=default;

  /**
   * @brief: This Offer will enable the DM to forward request messages to this handler.
   * @attention: SWS_DM_00638
   */
  ara::core::Result<void> Offer();

  /**
   * @brief: This StopOffer will disable the forwarding of request messages from DM.
   * @attention: SWS_DM_00639
   */
  void StopOffer();

  /**
   * @brief: Called for ReadDataByIdentifier request for this DiagnosticDataIdentifier.
   * @param dataIdentifier : the corresponding DataIdentifier
   * @param metaInfo : contains additional meta information
   * @param cancellationHandler : informs if the current conversation is canceled
   * @attention: SWS_DM_00636
   */
  virtual ara::core::Future<OperationOutput> Read(std::uint16_t dataIdentifier,
                                                  MetaInfo &metaInfo,
                                                  CancellationHandler cancellationHandler) = 0;

  /**
   * @brief: Called for WriteDataByIdentifier request for this DiagnosticDataIdentifier.
   * @param dataIdentifier : the corresponding DataIdentifier
   * @param cancellationHandler : informs if the current conversation is canceled
   * @attention: SWS_DM_00637
   */
  virtual ara::core::Future<void> Write(std::uint16_t dataIdentifier,
                                        CancellationHandler cancellationHandler) = 0;
};


#endif // CYY_AP_GENERIC_DATA_IDENTIFIER_H
