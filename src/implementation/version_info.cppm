/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

module;

#include <vector>
#include <sharedutils/util_version.h>
#include <cinttypes>

export module pragma.uva:version_info;

export namespace pragma::uva {
	struct VersionInfo {
		util::Version version;
		std::vector<uint32_t> files;
	};
};
