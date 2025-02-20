#include "Console.h"
#include <cstdarg>
#include <cstdio>
#include <mutex>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <filesystem>
#include <algorithm>

std::vector<std::string> GameConsole::Items;
bool GameConsole::ScrollToBottom = false;
bool GameConsole::AutoScroll = true;
bool GameConsole::Copy = false;
bool GameConsole::useMarkdown = false;
bool GameConsole::showTrimWarning = false;
size_t GameConsole::maxLines = DEFAULT_MAX_LINES;
size_t GameConsole::addCounter = 0;
static std::mutex consoleMutex;

// Pipe handles for output redirection
static HANDLE g_hReadPipe = NULL;
static HANDLE g_hWritePipe = NULL;
static std::thread* g_pCaptureThread = nullptr;
static bool g_bCapturing = false;

// Static member initialization
std::wstring GameConsole::logDirectory;
bool GameConsole::isMonitoring = false;
std::thread* GameConsole::monitorThread = nullptr;
std::vector<std::filesystem::file_time_type> GameConsole::lastModifiedTimes;
std::vector<std::wstring> GameConsole::monitoredFiles;

std::vector<std::string> GameConsole::History;
int GameConsole::HistoryPos = -1;
char GameConsole::InputBuf[256] = {};
SDK::UConsole* GameConsole::GameViewportConsole = nullptr;

void GameConsole::TrimBuffer() {
    if (Items.size() > maxLines) {
        size_t itemsToRemove = Items.size() - maxLines;
        Items.erase(Items.begin(), Items.begin() + itemsToRemove);
        showTrimWarning = true;  // Set warning flag when lines are removed
    }
}

void GameConsole::AddLog(const char* fmt, ...) {
    char buf[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, IM_ARRAYSIZE(buf), fmt, args);
    buf[IM_ARRAYSIZE(buf) - 1] = 0;
    va_end(args);

    std::lock_guard<std::mutex> lock(consoleMutex);
    Items.push_back(buf);
    
    if (++addCounter >= BUFFER_CHECK_FREQUENCY) {
        TrimBuffer();
        addCounter = 0;
    }
    
    if (AutoScroll)
        ScrollToBottom = true;
}

void GameConsole::AddLogW(const wchar_t* fmt, ...) {
    wchar_t wbuf[1024];
    va_list args;
    va_start(args, fmt);
    _vsnwprintf_s(wbuf, IM_ARRAYSIZE(wbuf), fmt, args);
    wbuf[IM_ARRAYSIZE(wbuf) - 1] = 0;
    va_end(args);

    // Convert wide string to UTF-8
    char buf[1024];
    WideCharToMultiByte(CP_UTF8, 0, wbuf, -1, buf, sizeof(buf), NULL, NULL);

    std::lock_guard<std::mutex> lock(consoleMutex);
    Items.push_back(buf);
    
    if (++addCounter >= BUFFER_CHECK_FREQUENCY) {
        TrimBuffer();
        addCounter = 0;
    }
    
    if (AutoScroll)
        ScrollToBottom = true;
}

void GameConsole::Clear() {
    std::lock_guard<std::mutex> lock(consoleMutex);
    Items.clear();
    addCounter = 0;
}

void GameConsole::CaptureOutput() {
    char buffer[4096];
    DWORD bytesRead;
    
    while (g_bCapturing) {
        if (ReadFile(g_hReadPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
            buffer[bytesRead] = '\0';
            AddLog("%s", buffer);
        }
        else {
            Sleep(100); // Increased sleep time to reduce CPU usage
        }
    }
}

void GameConsole::RedirectStdHandles() {
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;

    // Create pipe for output redirection
    if (CreatePipe(&g_hReadPipe, &g_hWritePipe, &sa, 0)) {
        // Set the pipe handle as stdout
        SetStdHandle(STD_OUTPUT_HANDLE, g_hWritePipe);
        SetStdHandle(STD_ERROR_HANDLE, g_hWritePipe);

        // Start capture thread
        g_bCapturing = true;
        g_pCaptureThread = new std::thread(CaptureOutput);
    }
}

void GameConsole::InitGameConsole() {
    // Set console key to F12 and create console
    SDK::UInputSettings::GetDefaultObj()->ConsoleKeys[0].KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"F12");
    SDK::UObject* NewObject = SDK::UGameplayStatics::SpawnObject(Globals::getEngine()->ConsoleClass, Globals::getEngine()->GameViewport);
    Globals::getEngine()->GameViewport->ViewportConsole = static_cast<SDK::UConsole*>(NewObject);
    GameViewportConsole = static_cast<SDK::UConsole*>(NewObject);

    AddLog("Game console initialized. Press F12 to toggle game console.");
    AddLog("Type commands in the input box below and press Enter to execute.");
    AddLog("Use Up/Down arrows to navigate command history.");
}

void GameConsole::ExecuteCommand(const char* command) {
    if (!command || !command[0]) return;

    // Convert command to wstring then to FString
    std::wstring wcommand = std::wstring(command, command + strlen(command));
    SDK::FString fcommand = wcommand.c_str();

    // Get world context and player controller
    SDK::UObject* worldContext = Globals::getEngine()->GameViewport;
    SDK::APlayerController* playerController = nullptr;
    
	// TODO: Implement server-side command execution that doesnt kick me out of the server or at least it applies the changes
    // if (auto world = Globals::getEngine()->GameViewport->World) {
    //     if (auto gameInstance = world->OwningGameInstance) {
    //         if (auto localPlayers = gameInstance->LocalPlayers) {
    //             if (localPlayers.Num() > 0) {
    //                 playerController = localPlayers[0]->PlayerController;
    //
    //                 // Try server-side command execution first
    //                 if (playerController) {
    //                     // Try ServerExecuteConsoleCommand if it's a QRSLPlayerController
    //                     if (auto qrslController = static_cast<SDK::AQRSLPlayerController*>(playerController)) {
    //                         if (auto func = qrslController->Class->GetFunction("QRSLPlayerController", "ServerExecuteConsoleCommand")) {
    //                             struct {
    //                                 SDK::FString Args;
    //                             } params;
    //                             params.Args = fcommand;
    //                             qrslController->ProcessEvent(func, &params);
    //                         }
    //                     }
    //
    //                     // Try ServerExecuteCmd if we have a HottaATTMgr
    //                     if (auto attMgr = reinterpret_cast<SDK::AHottaATTMgr*>(playerController)) {
    //                         if (auto func = attMgr->Class->GetFunction("HottaATTMgr", "ServerExecuteCmd")) {
    //                             struct {
    //                                 SDK::UObject* Invoker;
    //                                 SDK::FHottaScriptObjectModel InModel;
    //                             } params;
    //                             params.Invoker = playerController;
    //                             params.InModel = SDK::FHottaScriptObjectModel(); // Initialize with default values
    //                             attMgr->ProcessEvent(func, &params);
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    // Try local command execution as fallback
    SDK::UKismetSystemLibrary::ExecuteConsoleCommand(worldContext, fcommand, playerController);
}

static int TextEditCallbackStub(ImGuiInputTextCallbackData* data) {
    switch (data->EventFlag) {
        case ImGuiInputTextFlags_CallbackHistory: {
            const int prev_history_pos = GameConsole::HistoryPos;
            if (data->EventKey == ImGuiKey_UpArrow) {
                if (GameConsole::HistoryPos == -1)
                    GameConsole::HistoryPos = GameConsole::History.size() - 1;
                else if (GameConsole::HistoryPos > 0)
                    GameConsole::HistoryPos--;
            }
            else if (data->EventKey == ImGuiKey_DownArrow) {
                if (GameConsole::HistoryPos != -1) {
                    if (++GameConsole::HistoryPos >= GameConsole::History.size())
                        GameConsole::HistoryPos = -1;
                }
            }

            if (prev_history_pos != GameConsole::HistoryPos) {
                const char* history_str = (GameConsole::HistoryPos >= 0) ? GameConsole::History[GameConsole::HistoryPos].c_str() : "";
                data->DeleteChars(0, data->BufTextLen);
                data->InsertChars(0, history_str);
            }
        }
    }
    return 0;
}

void GameConsole::ExecCommand(const char* command_line) {
    AddLog("> %s\n", command_line);
    History.push_back(command_line);
    HistoryPos = -1;

    ExecuteCommand(command_line);
}

void GameConsole::Draw(const char* title, bool* p_open) {
    if (!ImGui::Begin(title, p_open)) {
        ImGui::End();
        return;
    }

    // Options menu
    if (ImGui::BeginPopup("Options")) {
        ImGui::Checkbox("Auto-scroll", &AutoScroll);
        ImGui::EndPopup();
    }

    if (ImGui::Button("Options"))
        ImGui::OpenPopup("Options");
    ImGui::SameLine();
    bool clear = ImGui::Button("Clear");
    ImGui::SameLine();
    bool copy = ImGui::Button("Copy");
    ImGui::SameLine();
    Copy = copy;

    ImGui::Separator();

    // Reserve enough left-over height for 1 separator + 1 input text
    const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
    ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_None);
    if (clear)
        Clear();
    if (copy)
        ImGui::LogToClipboard();

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing

    float wrap_width = ImGui::GetContentRegionAvail().x;
    ImGuiListClipper clipper;
    clipper.Begin(Items.size());
    while (clipper.Step()) {
        for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++) {
            const char* item = Items[i].c_str();
            ImVec4 color(1.0f, 1.0f, 1.0f, 1.0f); // Default color

            // Color coding based on message type
            if (strstr(item, "Error:")) {
                color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); // Red for errors
            }
            else if (strstr(item, "Warning:")) {
                color = ImVec4(1.0f, 1.0f, 0.4f, 1.0f); // Yellow for warnings
            }
            else if (strstr(item, "Verbose:")) {
                color = ImVec4(0.4f, 0.8f, 1.0f, 1.0f); // Light blue for verbose
            }
            else if (i < History.size() && Items[i] == History[i]) {
                color = ImVec4(0.4f, 1.0f, 1.0f, 1.0f); // Cyan for user input
            }

            ImGui::PushStyleColor(ImGuiCol_Text, color);
            ImGui::PushTextWrapPos(wrap_width);
            ImGui::TextUnformatted(item);
            ImGui::PopTextWrapPos();
            ImGui::PopStyleColor();
        }
    }
    clipper.End();

    if (ScrollToBottom || (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
        ImGui::SetScrollHereY(1.0f);
    ScrollToBottom = false;

    ImGui::PopStyleVar();
    ImGui::EndChild();
    ImGui::Separator();

    // Command-line
    bool reclaim_focus = false;
    ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackHistory;
    
    // Style the input text
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.1f, 0.1f, 0.1f, 1.0f)); // Dark background
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.4f, 1.0f, 1.0f, 1.0f)); // Cyan text
    
    if (ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf), input_text_flags, TextEditCallbackStub)) {
        char* s = InputBuf;
        if (s[0]) {
            ExecCommand(s);
        }
        strcpy_s(s, IM_ARRAYSIZE(InputBuf), "");
        reclaim_focus = true;
    }

    ImGui::PopStyleColor(2); // Pop both colors

    // Auto-focus on window apparition
    ImGui::SetItemDefaultFocus();
    if (reclaim_focus)
        ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

    ImGui::End();
}

void GameConsole::MonitorLogFiles(const std::wstring& logPath) {
    if (isMonitoring) {
        StopMonitoring();
    }

    logDirectory = logPath;
    isMonitoring = true;
    monitorThread = new std::thread(&GameConsole::MonitorLogDirectory);
}

void GameConsole::StopMonitoring() {
    if (isMonitoring && monitorThread) {
        isMonitoring = false;
        if (monitorThread->joinable()) {
            monitorThread->join();
        }
        delete monitorThread;
        monitorThread = nullptr;
    }
}

void GameConsole::MonitorLogDirectory() {
    using namespace std::filesystem;
    
    while (isMonitoring) {
        try {
            // Check for new log files
            for (const auto& entry : directory_iterator(logDirectory)) {
                if (entry.is_regular_file() && entry.path().extension() == L".log") {
                    std::wstring filePath = entry.path().wstring();
                    
                    // Check if this is a new file
                    auto it = std::find(monitoredFiles.begin(), monitoredFiles.end(), filePath);
                    if (it == monitoredFiles.end()) {
                        monitoredFiles.push_back(filePath);
                        lastModifiedTimes.push_back(last_write_time(entry));
                        
                        // Read entire file content for new file
                        std::ifstream file(filePath);
                        if (file) {
                            std::string line;
                            while (std::getline(file, line)) {
                                AddLog("%s", line.c_str());
                            }
                        }
                    }
                    else {
                        // Check if existing file was modified
                        size_t index = it - monitoredFiles.begin();
                        auto currentTime = last_write_time(entry);
                        
                        if (currentTime > lastModifiedTimes[index]) {
                            // Read only new content
                            std::ifstream file(filePath);
                            if (file) {
                                file.seekg(0, std::ios::end);
                                auto fileSize = file.tellg();
                                
                                // Read last 4KB or entire file if smaller
                                const std::streamoff readSize = 4096;
                                std::streampos readPos = (fileSize > readSize) ? std::streampos(fileSize - readSize) : std::streampos(0);
                                file.seekg(readPos);
                                
                                std::string line;
                                while (std::getline(file, line)) {
                                    AddLog("%s", line.c_str());
                                }
                            }
                            lastModifiedTimes[index] = currentTime;
                        }
                    }
                }
            }
        }
        catch (const std::exception& e) {
            AddLog("Error monitoring log files: %s", e.what());
        }
        
        // Sleep longer to reduce CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
