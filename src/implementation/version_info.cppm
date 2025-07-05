// SPDX-FileCopyrightText: (c) 2024 Silverlan <opensource@pragma-engine.com>
// SPDX-License-Identifier: MIT

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
