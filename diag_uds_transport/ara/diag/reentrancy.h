/***
*  Author: yiyang.cai@pm.me
*  DOC   : AUTOSAR_SWS_Diagnostics R21-11
*  Date  : 11.4.2022
 */

#ifndef CYY_AP_REENTRANCY_H
#define CYY_AP_REENTRANCY_H

#include <cstdint>

namespace ara {
namespace diag {

/**
 * @brief: Specifies the reentrancy type
 * @attention: SWS_DM_00935
 */
enum class ReentrancyType : std::uint8_t {
  /* The code is fully reentrancy */
  kFully = 0x00,

  /* Not reentrancy code */
  kNot = 0x01,
};

/**
 * @brief: Specifies the reentrancy type of a DataIdentifier related port.
 * @attention: SWS_DM_00936
 */
struct DataIdentifierReentrancyType {
  /**
   * @brief: Reentrancy type for Reads.
   * @attention: SWS_DM_00937
   */
  ReentrancyType read;

  /**
   * @brief: Reentrancy type for Writes.
   * @attention: SWS_DM_00938
   */
  ReentrancyType write;

  /**
   * @brief: Reentrancy type for Read and Writes.
   * @attention: SWS_DM_00939
   */
  ReentrancyType readWrite;
};

/**
 * @brief: Class to implement operations on diagnostic Monitor interface.
 * @attention: SWS_DM_00542
 */
class Monitor final {

  /**
   * @brief: Represents the parameters for counter-based debouncing.
   * @attention: SWS_DM_00538
   */
  struct CounterBased {
    /**
     * @brief: Threshold until qualified failed
     * @attention: SWS_DM_00621
     */
    std::int16_t failedThreshold;

    /**
     * @brief: Threshold until qualified passed
     * @attention: SWS_DM_00622
     */
    std::int16_t passedThreshold;

    /**
     * @brief: Stepsize per pre-passed report.
     * @attention: SWS_DM_00623
     */
    std::int16_t failedStepsize;

    /**
     * @brief: Stepsize per pre-passed report.
     * @attention: SWS_DM_00624
     */
    std::int16_t passedStepsize;

    /**
     * @brief: failed to jump value
     * @attention: SWS_DM_00625
     */
    std::int16_t failedJumpValue;

    /**
     * @brief: failed to jump value
     * @attention: SWS_DM_00626
     */
    std::int16_t passedJumpValue;

    /**
     * @brief: is jump support
     * @attention: SWS_DM_00627
     */
    bool useJumpToFailed;

    /**
     * @brief: is jump support
     * @attention: SWS_DM_00628
     */
    bool useJumpToPassed;
  };

  /**
   * @brief: Represents the parameters for time-based debouncing.
   * @attention: SWS_DM_00539
   */
  struct TimeBased {
    /**
     * @brief: time until passed in(ms)
     * @attention: SWS_DM_00630
     */
    std::uint32_t passedMs;

    /**
     * @brief: time until failed in(ms)
     * @attention: SWS_DM_00629
     */
    std::uint32_t failedMs;
  };
};

}
}

#endif // CYY_AP_REENTRANCY_H
