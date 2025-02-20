#include "ace.hpp"
#include "../minhook/include/MinHook.h"
#include <string>

namespace Ace {
    getProcAddressForCaller_t oGetProcAddress = nullptr;
    loadLibraryW_t oLoadLibraryW = nullptr;

    int myAce() {
        return 0;
    }

    FARPROC WINAPI getProcAddress(HMODULE hModule, LPCSTR lpProcName, void* caller) {
        if (reinterpret_cast<uintptr_t>(lpProcName) >= 0xFFFF) {
            if (std::string(lpProcName).find("InitAceClient") != std::string::npos) {
                return reinterpret_cast<FARPROC>(&myAce);
            }
        }
        return oGetProcAddress(hModule, lpProcName, caller);
    }

    HANDLE WINAPI loadLibraryW(LPCWSTR lpLibFileName) {
        if (std::wstring(lpLibFileName).find(L"ACE-Base64.dll") != std::wstring::npos) {
            return reinterpret_cast<HANDLE>(0xBAADC0DE);
        }
        return oLoadLibraryW(lpLibFileName);
    }

    void init() {
        MH_Initialize();
        HMODULE mod = GetModuleHandle(L"kernelbase.dll");

        void* loadLibraryWAddr = GetProcAddress(mod, "LoadLibraryW");
        void* getProcAddressAddr = GetProcAddress(mod, "GetProcAddressForCaller");

        MH_CreateHook(loadLibraryWAddr, loadLibraryW, reinterpret_cast<void**>(&oLoadLibraryW));
        MH_EnableHook(loadLibraryWAddr);

        MH_CreateHook(getProcAddressAddr, getProcAddress, reinterpret_cast<void**>(&oGetProcAddress));
        MH_EnableHook(getProcAddressAddr);
    }
} // namespace Ace
