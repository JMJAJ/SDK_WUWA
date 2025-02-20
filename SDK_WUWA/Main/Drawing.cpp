#include "Drawing.h"
#include "addons.hpp"
#include "../Logger/logger.hpp"

#include <mutex>
#include <fstream>

LPCSTR Drawing::lpWindowName = "Jxint";
ImVec2 Drawing::vWindowSize = { 350, 75 };
ImGuiWindowFlags Drawing::WindowFlags = 0;
bool Drawing::bDraw = true;

void Drawing::Active()
{
	bDraw = true;
}

bool Drawing::isActive()
{
	return bDraw == true;
}

static bool isInitialized = false;
static std::mutex initMutex;

static void early_init() {
    std::lock_guard<std::mutex> lock(initMutex);
    if (isInitialized) return;

    try {
        Logger::init();
        Logger::setup_crash_handler();

        // LPVOID processEventAddress = reinterpret_cast<LPVOID>(Pointers::baseAddr + SDK::Offsets::ProcessEvent);
        // EnhancedLogger::EnhancedProcessEventLogger::Init(processEventAddress);

        isInitialized = true;
        Logger::success("Core systems initialized");
    }
    catch (const std::exception& e) {
        Logger::error("Initialization failed: " + std::string(e.what()));
    }
}

static void InitializeStyle() {
    ImGuiStyle& style = ImGui::GetStyle();

    static bool colorsInitialized = false;

    if (!colorsInitialized) {
        // Darker matte color scheme
        ImVec4* colors = style.Colors;
        colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.13f, 0.17f, 0.94f);
        colors[ImGuiCol_Header] = ImVec4(0.15f, 0.17f, 0.20f, 1.00f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
        colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.23f, 0.28f, 1.00f);
        colors[ImGuiCol_Button] = ImVec4(0.20f, 0.22f, 0.28f, 1.00f);
        colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.27f, 0.32f, 1.00f);
        colors[ImGuiCol_ButtonActive] = ImVec4(0.30f, 0.32f, 0.35f, 1.00f);
        colors[ImGuiCol_Text] = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);
        colors[ImGuiCol_Border] = ImVec4(0.15f, 0.17f, 0.22f, 1.00f);

        colorsInitialized = true;
    }

    // Matte styling adjustments
    style.WindowPadding = ImVec2(15, 15);
    style.FramePadding = ImVec2(5, 5);
    style.ItemSpacing = ImVec2(12, 8);
    style.ItemInnerSpacing = ImVec2(8, 6);
    style.WindowRounding = 5.0f;
    style.FrameRounding = 4.0f;
    style.PopupRounding = 4.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabRounding = 3.0f;
    style.TabRounding = 4.0f;
}

void Drawing::Draw()
{
    early_init();

    const ImVec2 displaySize = ImGui::GetIO().DisplaySize;
    const ImVec2 sidebarSize = { 320, displaySize.y - 60 };
    const ImVec2 topBarSize = { displaySize.x, 60 };
    float size_pixels = 20.0f;

    InitializeStyle();

    if (isActive()) {
        const float menuBarHeight = 20.0f;
        const float topBarHeight = 40.0f;
        const float totalTopHeight = menuBarHeight + topBarHeight;

        ImGui::SetNextWindowBgAlpha(0.7f);
        if (ImGui::BeginMainMenuBar()) {
            ImGui::Text("Jxint Control Panel    |  ");

            if (ImGui::BeginMenu("Player")) {
                ImGui::MenuItem("General Info",     nullptr, &Pointers::showGeneralInfoMenu);
                // ImGui::MenuItem("No Clip",          nullptr, &NoClip::showNoClipMenu);
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Gameplay")) {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Game Settings")) {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Debug Tools")) {
                ImGui::MenuItem("Process Logger",   nullptr, &ProcessEventLogger::showProcessLoggerMenu);
                ImGui::MenuItem("Console",          nullptr, &ConsoleConfig::showConsoleWindow);
                ImGui::EndMenu();
            }

            ImGui::SameLine(ImGui::GetWindowWidth() - 120);
            ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);

            ImGui::EndMainMenuBar();
        }

        // Individual windows will appear below the top bar when their menu items are selected
        if (Pointers::showGeneralInfoMenu               )           Pointers::generalInfo();
        if (ProcessEventLogger::showProcessLoggerMenu   )           ProcessEventLogger::ProcessLoggerMenu();
        if (ConsoleConfig::showConsoleWindow            )           ConsoleMenu();
        // if (NoClip::showNoClipMenu                      )           NoClip::menu();

         SDK::UInputSettings::GetDefaultObj()->ConsoleKeys[0].KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"F12");
         SDK::UObject* NewObject = SDK::UGameplayStatics::SpawnObject(Globals::getEngine()->ConsoleClass, Globals::getEngine()->GameViewport);
         Globals::getEngine()->GameViewport->ViewportConsole = static_cast<SDK::UConsole*>(NewObject);

        ImGui::End();
    }

    // ticks
    // NoClip::tick();

    if (GetAsyncKeyState(VK_INSERT) & 1) {
        bDraw = !bDraw;
    }
}