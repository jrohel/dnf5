/*
Copyright Contributors to the libdnf project.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef DNF5_COMMANDS_SWAP_SWAP_HPP
#define DNF5_COMMANDS_SWAP_SWAP_HPP

#include "../shared_options.hpp"

#include <dnf5/context.hpp>

#include <vector>

namespace dnf5 {

// TODO(jrohel): The "swap" command may be removed in the future in favor of a more powerful command (eg "do"),
//               which will allow multiple actions to be combined in one transaction.
class SwapCommand : public Command {
public:
    explicit SwapCommand(Command & parent) : Command(parent, "swap", "software_management_commands") {}
    void set_argument_parser() override;
    void configure() override;
    void load_additional_packages() override;
    void run() override;

private:
    std::string remove_pkg_spec;
    std::vector<std::string> install_pkg_specs;
    std::vector<std::string> install_pkg_file_paths;
    std::vector<libdnf::rpm::Package> cmdline_packages;

    std::unique_ptr<AllowErasingOption> allow_erasing;
};

}  // namespace dnf5

#endif  // DNF5_COMMANDS_SWAP_SWAP_HPP
