#include "no_clip.hpp"

namespace NoClip {
    Config::field<bool> enabled;
    bool InNextTick = false;
    std::chrono::time_point<std::chrono::system_clock> last = std::chrono::system_clock::now();

    // New variable to control movement speed
    float movementSpeed = 1.0f;

    void init() {
        enabled = Config::get<bool>("", false);

        Hooks::registerHook(
            "Engine.ActorComponent.ReceiveTick",
            [](SDK::UObject* pObject, SDK::UFunction* pFunction, void* pParams) -> Hooks::ExecutionFlag {
                if (InNextTick) {
                    const auto character = Globals::getCharacter();

                    if (character != nullptr) {
                        character->SetActorEnableCollision(!*enabled);
                        InNextTick = false;
                    }
                }

                return Hooks::ExecutionFlag::CONTINUE_EXECUTION;
            });
    }

    void toggle() {
        const auto character = Globals::getCharacter();

        if (character == nullptr) {
            return;
        }

        InNextTick = true;
    }

    void tick() {
        ImGuiIO& io = ImGui::GetIO();

        // Check for the  keypress (F6) | 20 is CAPSLOCK
        // https://boostrobotics.eu/windows-key-codes/
        if (GetAsyncKeyState(20) &&
            std::chrono::system_clock::now() - last >
            std::chrono::milliseconds(static_cast<int>(io.KeyRepeatDelay * 1000))) {
            enabled = !*enabled;
            toggle();
            last = std::chrono::system_clock::now();
        }

        // Only process movement if noclip is enabled
        if (!*enabled) {
            return;
        }

        const auto character = Globals::getCharacter();

        if (character == nullptr) {
            return;
        }

        const auto controller = Globals::GetPlayerController();

        if (controller == nullptr) {
            return;
        }

        const auto cameraManager = controller->PlayerCameraManager;
        SDK::FVector moveVector(0.0, 0.0, 0.0);

        // Move forward
        if (GetAsyncKeyState('W') & 0x8000) {
            moveVector += cameraManager->GetActorForwardVector();
        }

        // Move backward
        if (GetAsyncKeyState('S') & 0x8000) {
            moveVector -= cameraManager->GetActorForwardVector();
        }

        // Move left
        if (GetAsyncKeyState('A') & 0x8000) {
            moveVector -= cameraManager->GetActorRightVector();
        }

        // Move right
        if (GetAsyncKeyState('D') & 0x8000) {
            moveVector += cameraManager->GetActorRightVector();
        }

        // Move up
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            moveVector += cameraManager->GetActorUpVector();
        }

        // Move down
        if (GetAsyncKeyState(VK_LCONTROL) & 0x8000) {
            moveVector -= cameraManager->GetActorUpVector();
        }

        moveVector.Normalize();

        if (character->CharacterMovement->MovementMode == SDK::EMovementMode::MOVE_Falling ||
            character->CharacterMovement->MovementMode == SDK::EMovementMode::MOVE_Swimming) {
            character->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Walking, 0);
        }

        // Use the movementSpeed variable to scale the movement
        const auto movement = moveVector * (movementSpeed / 100.0f);

        character->CharacterMovement->Velocity = SDK::FVector(0.0, 0.0, 0.0);

        if (movement.IsZero()) {
            return;
        }

        const auto location = (SDK::FVector*)((byte*)character->CharacterMovement->UpdatedComponent + 0x1E0);
        *location += movement;
    }

    static void HelpMarker(const char* desc)
    {
        ImGui::TextDisabled("(?)");
        if (ImGui::IsItemHovered())
        {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(desc);
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }

    void menu() {
        // Display the current state of noclip in the ImGui menu
        if (ImGui::Checkbox("No Clip", &enabled)) {
            toggle();
        }

        // Slider to adjust movement speed
        ImGui::SliderFloat("Speed", &movementSpeed, 0.1f, 25000.0f, "%.1f");
        ImGui::SameLine(); HelpMarker("(If you cant click on buttons/collect things around you or tp, go to settings and unstuck)");
    }
}