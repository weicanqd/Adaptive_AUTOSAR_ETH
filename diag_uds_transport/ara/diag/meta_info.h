/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.4.2022
 */

#ifndef CYY_AP_META_INFO_H
#define CYY_AP_META_INFO_H

/**
 * @brief: MetaInfo interface.
 * @attention: SWS_DM_00971
 */
class MetaInfo final {
  /**
   * @brief: Constructor of MetaInfo cannot be used.
   * @attention: SWS_DM_00972
   */
  MetaInfo() noexcept = delete;

  /**
   * @brief: Copy Constructor Of MetaInfo cannot be used.
   * @attention: SWS_DM_00973
   */
  MetaInfo(const MetaInfo&);
};

#endif // CYY_AP_META_INFO_H
