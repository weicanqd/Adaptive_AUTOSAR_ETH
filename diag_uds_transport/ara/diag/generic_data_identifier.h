/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.9.2022
 */

#ifndef CYY_AP_GENERIC_DATA_IDENTIFIER_H
#define CYY_AP_GENERIC_DATA_IDENTIFIER_H

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
};


#endif // CYY_AP_GENERIC_DATA_IDENTIFIER_H
