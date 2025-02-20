#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include "../../Main/pch.h"
#include "../Globals/globals.hpp"

class GameConsole {
public:
    static void AddLog(const char* fmt, ...);
    static void AddLogW(const wchar_t* fmt, ...);
    static void Draw(const char* title, bool* p_open = nullptr);
    static void Clear();
    static void RedirectStdHandles();
    static bool IsInitialized() { return !Items.empty(); }
    static void MonitorLogFiles(const std::wstring& logPath);
    static void StopMonitoring();
    static void SetMaxLines(size_t max) { maxLines = max; }
    static void EnableMarkdown(bool enable) { useMarkdown = enable; }
    static size_t GetLineCount() { return Items.size(); }
    static size_t GetMaxLines() { return maxLines; }
    static void InitGameConsole();
    static void ExecuteCommand(const char* command);

    // Make these public so the callback can access them
    static std::vector<std::string> History;
    static int HistoryPos;

private:
    static constexpr size_t DEFAULT_MAX_LINES = 50000;  // Increased to 50k lines
    static constexpr size_t BUFFER_CHECK_FREQUENCY = 100;  // Check buffer every N additions
    static std::vector<std::string> Items;
    static char InputBuf[256];
    static bool ScrollToBottom;
    static bool AutoScroll;
    static bool Copy;
    static bool useMarkdown;
    static size_t maxLines;
    static size_t addCounter;
    static bool showTrimWarning;
    static SDK::UConsole* GameViewportConsole;
    // Added back in
    static SDK::UConsole* Console;
    
    static void CaptureOutput();
    static void MonitorLogDirectory();
    static void TrimBuffer();
    static void ExecCommand(const char* command_line);
    static std::wstring logDirectory;
    static bool isMonitoring;
    static std::thread* monitorThread;
    static std::vector<std::filesystem::file_time_type> lastModifiedTimes;
    static std::vector<std::wstring> monitoredFiles;
};
