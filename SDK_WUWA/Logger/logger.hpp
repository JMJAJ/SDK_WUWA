#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <DbgHelp.h>
#include <filesystem>

namespace Logger {

    void init();
    void shutdown();

    void info(const std::string& message);
    void success(const std::string& message);
    void error(const std::string& message);
    void warning(const std::string& message);
    void debug(const std::string& message);

    void info(const std::wstring& message);
    void success(const std::wstring& message);
    void error(const std::wstring& message);
    void warning(const std::wstring& message);
    void debug(const std::wstring& message);

    // Crash handling functions
    void setup_crash_handler();
    void create_minidump(EXCEPTION_POINTERS* e, const std::wstring& path);
    LONG WINAPI crash_handler(EXCEPTION_POINTERS* e);
    std::wstring get_crash_log_path();
}