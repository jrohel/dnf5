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

#ifndef LIBDNF_REPO_REPO_CALLBACKS_HPP
#define LIBDNF_REPO_REPO_CALLBACKS_HPP

#include <string>
#include <vector>

namespace libdnf::repo {

/// Base class for repository callbacks.
/// To implement callbacks, inherit from this class and override virtual methods.
class RepoCallbacks {
public:
    RepoCallbacks() = default;
    RepoCallbacks(const RepoCallbacks &) = delete;
    RepoCallbacks(RepoCallbacks &&) = delete;
    RepoCallbacks & operator=(const RepoCallbacks &) = delete;
    RepoCallbacks & operator=(RepoCallbacks &&) = delete;
    virtual ~RepoCallbacks() = default;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

    /// GPG key import callback. Allows to confirm or deny the import.
    /// @param id the key id
    /// @param user_ids the list of the key user IDs
    /// @param fingerprint the fingerprint of the key
    /// @param url the URL from which the key was downloaded
    /// @param timestamp the timestamp of the key
    /// @return `true` to import the key, `false` to not import
    virtual bool repokey_import(
        const std::string & id,
        const std::vector<std::string> & user_ids,
        const std::string & fingerprint,
        const std::string & url,
        long int timestamp) {
        return true;
    }
#pragma GCC diagnostic pop
};

}  // namespace libdnf::repo

#endif  // LIBDNF_REPO_REPO_CALLBACKS_HPP
