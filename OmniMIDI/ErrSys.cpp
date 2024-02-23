/*

	OmniMIDI v15+ (Rewrite) for Windows NT

	This file contains the required code to run the driver under Windows 7 SP1 and later.

*/

#include "ErrSys.h"

void ErrorSystem::WinErr::Log(const char* Message, const OmniMIDI::source_location& location, int dummy, ...) {
#if defined(_WIN32) && !defined(_M_ARM)
	va_list vl;
	va_start(vl, dummy);

	char* cBuf = new char[SZBufSize];
	char* tBuf = new char[SZBufSize];
	
	vsprintf_s(tBuf, SZBufSize, Message, vl);
	sprintf_s(cBuf, SZBufSize, "[%s -> %s, L%d] >> %s", location.function_name(), location.file_name(), location.line(), tBuf);
	std::cout << cBuf << std::endl;

	delete[] cBuf;
	delete[] tBuf;

	va_end(vl);
#endif
}

void ErrorSystem::WinErr::ThrowError(const char* Error, const OmniMIDI::source_location& location, bool IsSeriousError, int dummy, ...) {
#if defined(_WIN32) && !defined(_M_ARM)
	va_list vl;
	va_start(vl, dummy);

	int GLE = GetLastError();
	char* Buf = nullptr;
	char* tBuf = nullptr;
	char* cBuf = nullptr;
	LPSTR GLEBuf = nullptr;

	if (!Error) {
		size_t MsgBufSize = FormatMessageA(
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS |
			FORMAT_MESSAGE_ALLOCATE_BUFFER,
			NULL, GLE,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&GLEBuf, 0, NULL);

		if (MsgBufSize != 0)
		{
			MessageBoxA(NULL, GLEBuf, "OmniMIDI - ERROR", IsSeriousError ? MB_ICONERROR : MB_ICONWARNING | MB_OK | MB_SYSTEMMODAL);
			LocalFree(GLEBuf);
		}
	}
	else {
		tBuf = new char[SZBufSize];
		Buf = new char[SZBufSize];
		cBuf = new char[SZBufSize];

		vsprintf_s(tBuf, SZBufSize, Error, vl);

#ifdef _DEBUG
		sprintf_s(Buf, BufSize, "An error has occured in the \"%s\" function! File: %s - Line: %d - Error:%s", 
			location.function_name(), location.file_name(), location.line(), tBuf);
#else
		sprintf_s(Buf, BufSize, "An error has occured in the \"%s\" function! Error: %s", 
			location.function_name(), tBuf);
#endif
		sprintf_s(cBuf, SZBufSize, "[%s -> %s, L%d] >> %s", location.function_name(), location.file_name(), location.line(), tBuf);
		std::async([&cBuf]() { std::cout << cBuf << std::endl; });
		delete[] cBuf;

		delete[] tBuf;

		MessageBoxA(NULL, Buf, "OmniMIDI - ERROR", IsSeriousError ? MB_ICONERROR : MB_ICONWARNING | MB_OK | MB_SYSTEMMODAL);

		delete[] Buf;
	}

	va_end(vl);
#endif
}

void ErrorSystem::WinErr::ThrowFatalError(const char* Error, const OmniMIDI::source_location& location) {
#if defined(_WIN32) && !defined(_M_ARM)
	char* Buf = new char[SZBufSize];
	int GLE = GetLastError();

#ifdef _DEBUG
	sprintf_s(Buf, BufSize, "An fatal error has occured in the \"%s\" function, from which the driver can NOT recover! File: %s - Line: %s - Error:%s",
		location.function_name(), location.file_name(), location.line(), Error);
#else
	sprintf_s(Buf, BufSize, "An fatal error has occured in the \"%s\" function, from which the driver can NOT recover! Error: %s", 
		location.function_name(), Error);
#endif

	MessageBoxA(NULL, Buf, "OmniMIDI - FATAL ERROR", MB_ICONERROR | MB_OK | MB_SYSTEMMODAL);
	std::async([&Buf]() { std::cout << Buf << std::endl; });
	delete[] Buf;

	throw std::runtime_error(Error);
#endif
}