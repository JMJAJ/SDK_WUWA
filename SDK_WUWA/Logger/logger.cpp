#include "logger.hpp"

#pragma warning(disable : 4996)

namespace Logger {
    DWORD mode;
    bool initialized = false;

    //bool is_debugger_present() {
    //    return IsDebuggerPresent() || CheckRemoteDebuggerPresent(GetCurrentProcess(), nullptr);
    //}

    void init() {
        //if (is_debugger_present()) {
        //    error(L"Debugger detected! You may be running the application under a debugger.");
        //    exit(1);
        //}

        AllocConsole();
        freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleMode(output, &mode);
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(output, mode);
    }

    void shutdown() {
        fclose(stdout);
        FreeConsole();
    }

    // Helper function to get current time as string
    std::wstring get_current_time() {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        std::wstringstream timeStream;
        timeStream << std::put_time(std::localtime(&now_c), L"%Y-%m-%d %H:%M:%S");
        return timeStream.str();
    }

    template<typename T>
    void log_message(const std::wstring& prefix, const std::wstring& color, const T& message) {
        std::wcout << color << prefix << L" [" << get_current_time() << L"] " << message << L"\033[0m" << std::endl;
    }

    void info(const std::string& message) { info(std::wstring(message.begin(), message.end())); }
    void success(const std::string& message) { success(std::wstring(message.begin(), message.end())); }
    void error(const std::string& message) { error(std::wstring(message.begin(), message.end())); }
    void warning(const std::string& message) { warning(std::wstring(message.begin(), message.end())); }
    void debug(const std::string& message) { debug(std::wstring(message.begin(), message.end())); }

    void info(const std::wstring& message) {
        log_message(L"[Jxint:INFO]", L"\033[38;2;0;111;238m", message);
    }

    void success(const std::wstring& message) {
        log_message(L"[Jxint:SUCCESS]", L"\033[38;2;23;201;100m", message);
    }

    void error(const std::wstring& message) {
        log_message(L"[Jxint:ERROR]", L"\033[38;2;243;18;96m", message);
    }

    void warning(const std::wstring& message) {
        log_message(L"[Jxint:WARNING]", L"\033[38;2;245;165;36m", message);
    }

    void debug(const std::wstring& message) {
        log_message(L"[Jxint:DEBUG]", L"\033[38;2;147;83;211m", message);
    }

    std::wstring get_crash_log_path() {
        wchar_t buffer[MAX_PATH];
        GetModuleFileNameW(NULL, buffer, MAX_PATH);
        std::filesystem::path exePath(buffer);
        auto crashDir = exePath.parent_path() / L"crashes";
        std::filesystem::create_directories(crashDir);

        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        std::wstringstream ss;
        ss << std::put_time(std::localtime(&now_c), L"%Y%m%d_%H%M%S");
        return (crashDir / (L"crash_" + ss.str() + L".dmp")).wstring();
    }

    void create_minidump(EXCEPTION_POINTERS* e, const std::wstring& path) {
        HANDLE hFile = CreateFileW(path.c_str(), GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
        if (hFile == INVALID_HANDLE_VALUE) {
            error(L"Failed to create dump file");
            return;
        }

        MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
        exceptionInfo.ThreadId = GetCurrentThreadId();
        exceptionInfo.ExceptionPointers = e;
        exceptionInfo.ClientPointers = FALSE;

        // Optimized dump flags for essential crash information while keeping size manageable
        MINIDUMP_TYPE dumpFlags = (MINIDUMP_TYPE)(
            MiniDumpNormal |                    // Basic info including threads, modules, and exception info
            MiniDumpWithThreadInfo |            // Thread timing and priority information
            MiniDumpWithIndirectlyReferencedMemory |  // Memory referenced by stack/registers
            MiniDumpWithDataSegs                // Data sections of loaded modules
        );

        MiniDumpWriteDump(
            GetCurrentProcess(),
            GetCurrentProcessId(),
            hFile,
            dumpFlags,
            e ? &exceptionInfo : NULL,
            NULL,
            NULL
        );

        CloseHandle(hFile);
    }

    LONG WINAPI crash_handler(EXCEPTION_POINTERS* e) {
        std::wstringstream ss;
        ss << L"Exception detected!\n"
           << L"Code: 0x" << std::hex << e->ExceptionRecord->ExceptionCode
           << L" at address: 0x" << std::hex << e->ExceptionRecord->ExceptionAddress;

        if (e->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION) {
            ss << L"\nAccess violation "
               << ((e->ExceptionRecord->ExceptionInformation[0] == 0) ? L"reading " : L"writing ")
               << L"address 0x" << std::hex << e->ExceptionRecord->ExceptionInformation[1];
        }

        // Log register state
        ss << L"\nRegister State:"
           << L"\nRAX=" << std::hex << e->ContextRecord->Rax
           << L" RBX=" << e->ContextRecord->Rbx
           << L" RCX=" << e->ContextRecord->Rcx
           << L" RDX=" << e->ContextRecord->Rdx
           << L"\nRSI=" << e->ContextRecord->Rsi
           << L" RDI=" << e->ContextRecord->Rdi
           << L" RBP=" << e->ContextRecord->Rbp
           << L" RSP=" << e->ContextRecord->Rsp;

        error(ss.str());

        auto dumpPath = get_crash_log_path();
        create_minidump(e, dumpPath);

        success(L"Crash dump created at: " + dumpPath);
        return EXCEPTION_CONTINUE_SEARCH;
    }

    void setup_crash_handler() {
        SetUnhandledExceptionFilter(crash_handler);
        success(L"Crash handler initialized");
    }
}