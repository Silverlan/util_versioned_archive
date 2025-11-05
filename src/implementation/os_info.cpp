// SPDX-FileCopyrightText: (c) 2024 Silverlan <opensource@pragma-engine.com>
// SPDX-License-Identifier: MIT

module;

module pragma.uva;

import :os_info;

std::string pragma::uva::p_os_to_string(P_OS os)
{
	switch(os) {
	case P_OS::All:
		return "ALL";
	case P_OS::Win32:
		return "WIN32";
	case P_OS::Win64:
		return "WIN64";
	case P_OS::Lin32:
		return "LIN32";
	case P_OS::Lin64:
		return "LIN64";
	default:
		return "INVALID";
	};
}

pragma::uva::P_OS pragma::uva::get_active_system()
{
	if(util::is_linux_system()) {
		if(util::is_x64_system())
			return P_OS::Lin64;
		return P_OS::Lin32;
	}
	if(!util::is_windows_system())
		return P_OS::Invalid;
	if(util::is_x64_system())
		return P_OS::Win64;
	return P_OS::Win32;
}
