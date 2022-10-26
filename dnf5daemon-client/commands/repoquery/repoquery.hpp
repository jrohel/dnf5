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

#ifndef DNF5DAEMON_CLIENT_COMMANDS_REPOQUERY_REPOQUERY_HPP
#define DNF5DAEMON_CLIENT_COMMANDS_REPOQUERY_REPOQUERY_HPP

#include "commands/command.hpp"

#include <libdnf-cli/session.hpp>
#include <libdnf/conf/option.hpp>
#include <libdnf/conf/option_bool.hpp>

#include <memory>
#include <vector>

namespace dnfdaemon::client {

class RepoqueryCommand : public DaemonCommand {
public:
    explicit RepoqueryCommand(Context & context);
    void run() override;
    dnfdaemon::KeyValueMap session_config() override;

private:
    libdnf::OptionBool * available_option{nullptr};
    libdnf::OptionBool * installed_option{nullptr};
    libdnf::OptionBool * info_option{nullptr};
    std::vector<std::unique_ptr<libdnf::Option>> * patterns_options{nullptr};
};

}  // namespace dnfdaemon::client

#endif
