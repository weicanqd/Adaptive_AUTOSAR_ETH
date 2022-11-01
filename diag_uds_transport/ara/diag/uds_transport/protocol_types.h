/***
 *  Author: yiyang.cai@pm.me
 *  DOC   : AUTOSAR_SWS_Diagnostics R21-11
 *  Date  : 10.31.2022
 */

#ifndef CYY_AP_PROTOCOL_TYPES_H
#define CYY_AP_PROTOCOL_TYPES_H

#include <cstdint>

namespace ara {
namespace diag {
namespace uds_transport {

using ByteVector = core::Span<std::uint8_t>;

using ChannelID = std::uint32_t;

using Priority = std::uint8_t;

using ProtocolKind = core::String;

using UdsTransportProtocolHandlerID = std::uint8_t;

using Priority = std::uint8_t;

using ProtocolKind = core::String;

} // namespace uds_transport
} // namespace diag
} // namespace ara

#endif // CYY_AP_PROTOCOL_TYPES_H
