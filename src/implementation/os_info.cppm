// SPDX-FileCopyrightText: (c) 2024 Silverlan <opensource@pragma-engine.com>
// SPDX-License-Identifier: MIT

module;

#include <sharedutils/util.h>
#include <string>
#include <cinttypes>

#undef WIN32
#undef WIN64

export module pragma.uva:os_info;

export namespace pragma::uva {
	enum class P_OS : uint8_t { Invalid = 0, All, Win32, Win64, Lin32, Lin64 };

	std::string p_os_to_string(P_OS os);
	P_OS get_active_system();
};
