/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.4.2022
 */

#ifndef CYY_AP_META_INFO_H
#define CYY_AP_META_INFO_H

#include <cstdint>

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

  /**
   * @brief: move constructor.
   * @param obj : object to be moved.
   * @attention: SWS_DM_00974
   */
  MetaInfo(MetaInfo& &obj) noexcept;

  /**
   * @brief: Copy Assignment Operator of MetaInfo cannot be used.
   * @attention: SWS_DM_00975
   */
  MetaInfo& operator= (const MetaInfo &) =delete;

  /**
   * @brief: Move Assignment Operator of MetaInfo.
   * @param other : MetaInfo instance
   * @return MetaInfo& : Reference to the current object
   * @attention: SWS_DM_00976
   */
  MetaInfo& operator= (MetaInfo &&other) noexcept;

  /**
   * @brief: Description: Definition of possible call context.
   * @attention: SWS_DM_00977
   */
  enum class Context : std::uint32_t  {
    /* service context of DCM request */
    kDiagnosticCommunication,

    /* for DIDs in snapshots */
    kFaultMemory,

    /* for read VIN */
    kDoIP,
  };

  /**
   * @brief: Description: Get the metaInfo value for a given key.
   * @param key : identification of value to be returned
   * @return Return values for the given key
   * @attention: SWS_DM_00978
   */
  ara::core::Optional<ara::core::StringView> GetValue(ara::core::StringView key) const noexcept;

  /**
   * @brief: Get the context of the invocation.
   * @return : Context : returns the context
   * @attention: SWS_DM_00979
   */
  Context GetContext() const noexcept;

  /**
   * @brief: Default destructor.
   * @attention: SWS_DM_00980
   */
  ~MetaInfo() noexcept;

};

#endif // CYY_AP_META_INFO_H
