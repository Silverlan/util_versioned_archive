// SPDX-FileCopyrightText: (c) 2024 Silverlan <opensource@pragma-engine.com>
// SPDX-License-Identifier: MIT

module;


module pragma.uva;

import :os_info;

pragma::uva::FileInfo::Flags pragma::uva::FileInfo::os_to_flags(P_OS os)
{
	switch(os) {
	case P_OS::Win32:
		return Flags::x86 | Flags::Windows;
		break;
	case P_OS::Win64:
		return Flags::x64 | Flags::Windows;
		break;
	case P_OS::Lin32:
		return Flags::x86 | Flags::Linux;
		break;
	case P_OS::Lin64:
		return Flags::x64 | Flags::Linux;
		break;
	case P_OS::Invalid:
	default:
		break;
	}
	return Flags::None;
}
bool pragma::uva::FileInfo::IsDirectory() const { return (flags & Flags::Directory) != Flags::None; }
bool pragma::uva::FileInfo::IsFile() const { return !IsDirectory(); }
bool pragma::uva::FileInfo::IsCompressed() const { return true; }
bool pragma::uva::FileInfo::operator==(P_OS os) const
{
	auto osFlags = flags & Flags::AllOS;
	switch(os) {
	case P_OS::Win32:
		return osFlags == (Flags::Windows | Flags::x86);
	case P_OS::Win64:
		return osFlags == (Flags::Windows | Flags::x64);
	case P_OS::Lin32:
		return osFlags == (Flags::Linux | Flags::x86);
	case P_OS::Lin64:
		return osFlags == (Flags::Linux | Flags::x64);
	case P_OS::All:
		return osFlags == Flags::AllOS;
	default:
		return true;
	}
}
bool pragma::uva::FileInfo::operator!=(P_OS os) const { return !(*this == os); }

pragma::uva::PublishInfo::PublishInfo(const std::string &_file, P_OS _os, const std::string &_src) : file(_file), os(_os), src(_src) {}
bool pragma::uva::PublishInfo::operator==(const PublishInfo &other) const { return (this->file == other.file && this->os == other.os) ? true : false; }
bool pragma::uva::PublishInfo::operator!=(const PublishInfo &other) const { return (*this == other) ? false : true; }
bool pragma::uva::PublishInfo::operator==(const std::string &str) const { return (this->file == str) ? true : false; }
bool pragma::uva::PublishInfo::operator!=(const std::string &str) const { return (*this == str) ? false : true; }
bool pragma::uva::PublishInfo::operator==(const P_OS &os) const { return (this->os == os) ? true : false; }
bool pragma::uva::PublishInfo::operator!=(const P_OS &os) const { return (*this == os) ? false : true; }
bool pragma::uva::PublishInfo::operator==(const pragma::uva::FileInfo &info) const
{
	if(pragma::uva::FileInfo::os_to_flags(os) != info.flags)
		return false;
	std::string name = GetSourceName();
	return (name == info.name) ? true : false;
}
bool pragma::uva::PublishInfo::operator!=(const pragma::uva::FileInfo &info) const { return (*this == info) ? false : true; }
std::string pragma::uva::PublishInfo::GetSourceName() const
{
	std::string name = src;
	auto bFileName = (name.find_first_of('.') != ustring::NOT_FOUND) ? true : false;
	if(!name.empty() && bFileName == false) {
		if(name.back() == '/')
			name[name.size() - 1] = '\\';
		else
			name += '\\';
		if(name.size() == 1 && name.back() == '\\')
			name = "";
	}
	else if(bFileName == true && !name.empty() && name.back() == '.')
		name.erase(name.end() - 1);
	if(bFileName == false)
		name += ufile::get_file_from_filename(file);
	return FileManager::GetCanonicalizedPath(name);
}
