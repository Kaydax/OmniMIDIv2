/*
 * SPDX-License-Identifier: MIT
 *
 * OmniMIDI
 *
 * Copyright (c) 2024 Keppy's Software
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the MIT License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * MIT License for more details.
 *
 * You should have received a copy of the MIT License along with this
 * program.  If not, see <https://opensource.org/license/mit/>.
 */

#ifdef _NONFREE

#ifdef _WIN32

#include "bass/bassasio.h"

unsigned int (WINAPI* BASS_ASIO_GetVersion)() = 0;
int (WINAPI* BASS_ASIO_SetUnicode)(int unicode) = 0;
unsigned int (WINAPI* BASS_ASIO_ErrorGetCode)() = 0;
int (WINAPI* BASS_ASIO_GetDeviceInfo)(unsigned int device, BASS_ASIO_DEVICEINFO* info) = 0;
unsigned int (WINAPI* BASS_ASIO_AddDevice)(const GUID* clsid, const char* driver, const char* name) = 0;
int (WINAPI* BASS_ASIO_SetDevice)(unsigned int device) = 0;
unsigned int (WINAPI* BASS_ASIO_GetDevice)() = 0;
int (WINAPI* BASS_ASIO_Init)(int device, unsigned int flags) = 0;
int (WINAPI* BASS_ASIO_Free)() = 0;
int (WINAPI* BASS_ASIO_Lock)(int lock) = 0;
int (WINAPI* BASS_ASIO_SetNotify)(ASIONOTIFYPROC* proc, void* user) = 0;
int (WINAPI* BASS_ASIO_ControlPanel)() = 0;
int (WINAPI* BASS_ASIO_GetInfo)(BASS_ASIO_INFO* info) = 0;
int (WINAPI* BASS_ASIO_CheckRate)(double rate) = 0;
int (WINAPI* BASS_ASIO_SetRate)(double rate) = 0;
double (WINAPI* BASS_ASIO_GetRate)() = 0;
int (WINAPI* BASS_ASIO_Start)(unsigned int buflen, unsigned int threads) = 0;
int (WINAPI* BASS_ASIO_Stop)() = 0;
int (WINAPI* BASS_ASIO_IsStarted)() = 0;
unsigned int (WINAPI* BASS_ASIO_GetLatency)(int input) = 0;
float (WINAPI* BASS_ASIO_GetCPU)() = 0;
int (WINAPI* BASS_ASIO_Monitor)(int input, unsigned int output, unsigned int gain, unsigned int state, unsigned int pan) = 0;
int (WINAPI* BASS_ASIO_SetDSD)(int dsd) = 0;
int (WINAPI* BASS_ASIO_Future)(unsigned int selector, void* param) = 0;

int (WINAPI* BASS_ASIO_ChannelGetInfo)(int input, unsigned int channel, BASS_ASIO_CHANNELINFO* info) = 0;
int (WINAPI* BASS_ASIO_ChannelReset)(int input, int channel, unsigned int flags) = 0;
int (WINAPI* BASS_ASIO_ChannelEnable)(int input, unsigned int channel, ASIOPROC* proc, void* user) = 0;
int (WINAPI* BASS_ASIO_ChannelEnableMirror)(unsigned int channel, int input2, unsigned int channel2) = 0;
int (WINAPI* BASS_ASIO_ChannelEnableBASS)(int input, unsigned int channel, unsigned int handle, int join) = 0;
int (WINAPI* BASS_ASIO_ChannelJoin)(int input, unsigned int channel, int channel2) = 0;
int (WINAPI* BASS_ASIO_ChannelPause)(int input, unsigned int channel) = 0;
unsigned int (WINAPI* BASS_ASIO_ChannelIsActive)(int input, unsigned int channel) = 0;
int (WINAPI* BASS_ASIO_ChannelSetFormat)(int input, unsigned int channel, unsigned int format) = 0;
unsigned int (WINAPI* BASS_ASIO_ChannelGetFormat)(int input, unsigned int channel) = 0;
int (WINAPI* BASS_ASIO_ChannelSetRate)(int input, unsigned int channel, double rate) = 0;
double (WINAPI* BASS_ASIO_ChannelGetRate)(int input, unsigned int channel) = 0;
int (WINAPI* BASS_ASIO_ChannelSetVolume)(int input, int channel, float volume) = 0;
float (WINAPI* BASS_ASIO_ChannelGetVolume)(int input, int channel) = 0;
float (WINAPI* BASS_ASIO_ChannelGetLevel)(int input, unsigned int channel) = 0;

#endif

#endif