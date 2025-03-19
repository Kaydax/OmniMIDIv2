/*

	OmniMIDI v15+ (Rewrite) for Windows NT

	This file contains the required code to run the driver under Windows 7 SP1 and later.
	This file is useful only if you want to compile the driver under Windows, it's not needed for Linux/macOS porting.

*/

#ifdef _WIN32

#ifndef _WDMENTRY_H
#define _WDMENTRY_H

#pragma once

#include "Common.hpp"

#include <shlwapi.h>
#include <devguid.h>
#include <newdev.h>
#include <regstr.h>
#include <setupapi.h>
#include <cstdlib>
#include "ErrSys.hpp"
#include "WDMDrv.hpp"
#include "KDMAPI.hpp"
#include "SynthHost.hpp"

#ifdef DEFINE_DEVPROPKEY
#undef DEFINE_DEVPROPKEY
#endif
#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) EXTERN_C const DEVPROPKEY DECLSPEC_SELECTANY name = { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }

// Copied from devpkey.h in the WinDDK
DEFINE_DEVPROPKEY(DEVPKEY_Device_BusReportedDeviceDesc, 0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 4);	// DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_ContainerId, 0x8c7ed206, 0x3f8a, 0x4827, 0xb3, 0xab, 0xae, 0x9e, 0x1f, 0xae, 0xfc, 0x6c, 2);			// DEVPROP_TYPE_GUID
DEFINE_DEVPROPKEY(DEVPKEY_Device_FriendlyName, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 14);			// DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_Category, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x5a);	// DEVPROP_TYPE_STRING_LIST
DEFINE_DEVPROPKEY(DEVPKEY_Device_LocationInfo, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 15);			// DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_Manufacturer, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 13);			// DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_SecuritySDS, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 26);			// DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING

const GUID DevGUID = GUID_DEVCLASS_MEDIA;
const wchar_t DEVICE_NAME_MEDIA[] = L"MEDIA";
const wchar_t DEVICE_DESCRIPTION[] = L"OmniMIDI for Windows NT";
const wchar_t DRIVER_PROVIDER_NAME[] = L"Keppy's Software";
const wchar_t DRIVER_CLASS_PROP_DRIVER_DESC[] = L"DriverDesc";
const wchar_t DRIVER_CLASS_PROP_PROVIDER_NAME[] = L"ProviderName";
const wchar_t DRIVER_CLASS_SUBKEY_DRIVERS[] = L"Drivers";
const wchar_t DRIVER_CLASS_PROP_SUBCLASSES[] = L"SubClasses";
const wchar_t DRIVER_CLASS_SUBCLASSES[] = L"midi";
const wchar_t DRIVER_SUBCLASS_SUBKEYS[] = L"midi\\OmniMIDI.dll";
const wchar_t DRIVER_SUBCLASS_PROP_DRIVER[] = L"Driver";
const wchar_t DRIVER_SUBCLASS_PROP_DESCRIPTION[] = L"Description";
const wchar_t DRIVER_SUBCLASS_PROP_ALIAS[] = L"Alias";
const wchar_t SHAKRA_DRIVER_NAME[] = L"OmniMIDI.dll";

// MIDI REG
const wchar_t MIDI_REGISTRY_ENTRY_TEMPLATE[] = L"midi%d";

#endif
#endif