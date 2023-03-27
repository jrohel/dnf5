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


#ifndef LIBDNF_CLI_UTILS_UNITS
#define LIBDNF_CLI_UTILS_UNITS

#include <string>
#include <utility>


namespace libdnf::cli::utils::units {


std::pair<float, const char *> to_size(int64_t num);

std::string format_size_aligned(int64_t num);


}  // namespace libdnf::cli::utils::units


#endif  // LIBDNF_CLI_UTILS_UNITS
