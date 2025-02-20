#include "ConsoleMenu.h"
#include "Console.h"
#include "ConsoleConfig.h"
#include <ShlObj.h>
#include <filesystem>

static bool initialized = false;

// Helper function to get the Hotta Logs directory
std::wstring GetHottaLogsPath() {
    wchar_t appDataPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, appDataPath))) {
        std::filesystem::path logsPath = std::filesystem::path(appDataPath) / L"Hotta" / L"Saved" / L"Logs";
        return logsPath.wstring();
    }
    return L"";
}

void ConsoleMenu() {
    if (!initialized) {
        // Initialize console to capture stdout/stderr
        GameConsole::RedirectStdHandles();
        
        // Initialize game console integration
        GameConsole::InitGameConsole();
        
        // Start monitoring the logs directory
        std::wstring logsPath = GetHottaLogsPath();
        if (!logsPath.empty()) {
            GameConsole::MonitorLogFiles(logsPath);
        }
        
        // Add initial console message
        GameConsole::AddLog("Console initialized successfully!");
        GameConsole::AddLog("Monitoring logs directory: %ls", logsPath.c_str());
        GameConsole::AddLog("Type commands in the input box below. Use Up/Down arrows for command history.");
        
        initialized = true;
    }

    // Draw console window if enabled
    if (ConsoleConfig::showConsoleWindow) {
        GameConsole::Draw("Game Console", &ConsoleConfig::showConsoleWindow);
    }
}
