/*
Copyright Contributors to the libdnf project.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef LIBDNF_VERSION_HPP
#define LIBDNF_VERSION_HPP

#include <cstdint>

namespace libdnf {

/// Library version
/// @since 5.0
struct LibraryVersion {
    std::uint16_t major;
    std::uint16_t minor;
    std::uint16_t micro;
};

/// Plugin API version
/// @since 5.0
struct PluginAPIVersion {
    std::uint16_t major;  // libdnf5 and the plugin must implement the same `major` version to work together
    std::uint16_t minor;  // libdnf5 must implement the `minor` version >= than the plugin to work together
};

static constexpr PluginAPIVersion PLUGIN_API_VERSION{.major = 1, .minor = 0};

/// @return Library version
/// @since 5.0
LibraryVersion get_library_version() noexcept;

/// @return Plugin API version implemented in the library
/// @since 5.0
PluginAPIVersion get_plugin_api_version() noexcept;

}  // namespace libdnf

#endif
