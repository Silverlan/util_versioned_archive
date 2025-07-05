// SPDX-FileCopyrightText: (c) 2024 Silverlan <opensource@pragma-engine.com>
// SPDX-License-Identifier: MIT

#ifndef __UVA_DEFINITIONS_HPP__
#define __UVA_DEFINITIONS_HPP__

#ifdef UVA_STATIC
#define DLLUVA
#elif UVA_DLL
#ifdef __linux__
#define DLLUVA __attribute__((visibility("default")))
#else
#define DLLUVA __declspec(dllexport)
#endif
#else
#ifdef __linux__
#define DLLUVA
#else
#define DLLUVA __declspec(dllimport)
#endif
#endif

#endif
