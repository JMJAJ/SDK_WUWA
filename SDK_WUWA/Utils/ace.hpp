#pragma once

#include <Windows.h>

namespace Ace {
    int myAce();

    typedef FARPROC(WINAPI* getProcAddressForCaller_t)(HMODULE hModule, LPCSTR lpProcName, void* caller);
    FARPROC WINAPI getProcAddress(HMODULE hModule, LPCSTR lpProcName, void* caller);

    typedef HANDLE(WINAPI* loadLibraryW_t)(LPCWSTR lpLibFileName);
    HANDLE WINAPI loadLibraryW(LPCWSTR lpLibFileName);

    // External variable declarations
    extern getProcAddressForCaller_t oGetProcAddress;
    extern loadLibraryW_t oLoadLibraryW;

    void init();
}
