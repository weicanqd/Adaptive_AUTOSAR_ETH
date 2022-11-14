/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.14.2022
 */

#ifndef CYY_AP_GENERIC_ROUTINE_H
#define CYY_AP_GENERIC_ROUTINE_H

#include <cstdint>
#include "reentrancy.h"

namespace ara {
namespace diag {

/**
 * @brief: Generic Routine interface
 * @attention: SWS_DM_00605
 */
class GenericRoutine {

  /**
   * @brief: Response Data of positive response message.
   * @attention: SWS_DM_00551
   */
  struct OperationOutput {
    /**
     * @brief: Content of positive response message.(without RoutineIdentifier)
     * @attention: SWS_DM_00633
     */
    ara::core::Vector<std::uint8_t> responseData;
  };

  /**
   * @brief: class for an generic Routine.
   * @param specifier : instanceSpecifier to an PortPrototype of an DiagnosticRoutineGenericInterface.
   * @param reentrancyType : specifies if interface is callable fully or non-reentrant.
   * @attention: SWS_DM_00552
   */
  inline GenericRoutine(const ara::core::InstanceSpecifier &specifier,
                        ReentrancyType reentrancyType);

  /**
   * @brief: Destructor of class GenericRoutine.
   * @attention: SWS_DM_00553
   */
  virtual ~GenericRoutine() noexcept = default;

  /**
   * @brief: This StopOffer will disable the forwarding of request messages from DM.
   * @attention: SWS_DM_00558
   */
  void StopOffer();

  /**
   * @brief: Called for RoutineControl with SubFunction Start request for this DiagnosticRoutineIdentifier.
   * @param routineId : the corresponding Routine Identifier
   * @param requestData : Content of request Message
   * @param metaInfo : contains additional meta information
   * @param cancellationHandler : informs if the current conversation is canceled.
   * @attention: SWS_DM_00554
   */
  virtual ara::core::Future<OperationOutput> Start (std::uint16_t routineId,
                                                   ara::core::Span< std::uint8_t> requestData,
                                                   MetaInfo &metaInfo,
                                                   CancellationHandler cancellationHandler) = 0;

  /**
   * @brief: Called for RoutineControl with SubFunction Stop request for this DiagnosticRoutineIdentifier.
   * @param routineId : the corresponding Routine Identifier
   * @param requestData : Content of request Message
   * @param metaInfo : contains additional meta information
   * @param cancellationHandler : informs if the current conversation is canceled.
   * @attention: SWS_DM_00555
   */
  virtual ara::core::Future<OperationOutput> Stop (std::uint16_t routineId,
                                                  ara::core::Span< std::uint8_t> requestData,
                                                  MetaInfo &metaInfo,
                                                  CancellationHandler cancellationHandler) = 0;

  /**
   * @brief: Called for RoutineControl with SubFunction RequestResults request for this DiagnosticRoutine Identifier
   * @param routineId : the corresponding Routine Identifier
   * @param requestData : Content of request Message
   * @param metaInfo : contains additional meta information
   * @param cancellationHandler : informs if the current conversation is canceled.
   * @attention : SWS_DM_00556
   */
  virtual ara::core::Future<OperationOutput>
  RequestResults (std::uint16_t routineId,
                 ara::core::Span< std::uint8_t> requestData,
                 MetaInfo &metaInfo,
                 CancellationHandler cancellationHandler) = 0;
};

}
}

#endif // CYY_AP_GENERIC_ROUTINE_H
