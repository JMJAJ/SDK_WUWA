#include "globals.hpp"

namespace Globals {

    static SDK::UGameEngine* engine = nullptr;
    static SDK::UCheatManager* cheatManager = nullptr;

    SDK::UGameEngine* getEngine() {
        if (engine == nullptr) {
            engine = static_cast<SDK::UGameEngine*>(SDK::UEngine::GetEngine());
        }
        return engine;
    }

    SDK::UGameInstance* getGameInstance() {
        SDK::UGameEngine* eng = getEngine();
        return eng ? static_cast<SDK::UGameInstance*>(eng->GameInstance) : nullptr;
    }

    SDK::UGameInstance* getInstance() {
        SDK::UGameInstance* gameInstance = getGameInstance();
        return gameInstance ? static_cast<SDK::UGameInstance*>(gameInstance) : nullptr;
    }

    SDK::ULocalPlayer* getLocalPlayer() {
        SDK::UGameInstance* instance = getInstance();
        if (instance && instance->LocalPlayers.Num() > 0) {
            return static_cast<SDK::ULocalPlayer*>(instance->LocalPlayers[0]);
        }
        return nullptr;
    }

    SDK::UWorld* getWorld() {
        SDK::UGameEngine* eng = getEngine();
        return (eng && eng->GameViewport) ? eng->GameViewport->World : nullptr;
    }

    SDK::ACharacter* getCharacter() {
        SDK::ULocalPlayer* localPlayer = getLocalPlayer();
        if (localPlayer && localPlayer->PlayerController) {
            SDK::APlayerController* playerController = static_cast<SDK::APlayerController*>(localPlayer->PlayerController);
            return playerController->IsA(SDK::APlayerController::StaticClass()) ? static_cast<SDK::ACharacter*>(playerController->Owner) : static_cast<SDK::ACharacter*>(playerController->Character);
        }
        return nullptr;
    }

    //SDK::AHUD* getHUD() {
    //    SDK::UWorld* world = getWorld();
    //    if (world) {
    //        SDK::UGameInstance* gameInstance = world->OwningGameInstance;
    //        if (gameInstance) {
    //            for (int i = 0; i < gameInstance->LocalPlayers.Num(); ++i) {
    //                SDK::ULocalPlayer* localPlayer = gameInstance->LocalPlayers[i];
    //                if (localPlayer && localPlayer->PlayerController) {
    //                    SDK::APlayerController* playerController = localPlayer->PlayerController;
    //                    return playerController ? playerController->GetHUD() : nullptr;
    //                }
    //            }
    //        }
    //    }
    //    return nullptr;
    //}

    SDK::AHUD* getHUD() {
        SDK::UWorld* world = getWorld();
        if (!world) return nullptr;

        // Get local player controller
        SDK::ULocalPlayer* localPlayer = getLocalPlayer();
        if (!localPlayer || !localPlayer->PlayerController) return nullptr;

        // Get HUD and cast to HUD
        SDK::AHUD* hud = localPlayer->PlayerController->GetHUD();
        return static_cast<SDK::AHUD*>(hud);
    }

    SDK::APlayerController* GetPlayerController() {
        SDK::UWorld* world = Globals::getWorld();
        if (world != nullptr && Globals::getLocalPlayer()->PlayerController != nullptr) {
            return static_cast<SDK::APlayerController*>(Globals::getLocalPlayer()->PlayerController);
        }
        return nullptr;
    }

    std::vector<SDK::APlayerController*> getPlayerControllers() {
        std::vector<SDK::APlayerController*> playerControllers;
        SDK::UWorld* world = getWorld();
        if (world) {
            SDK::UGameInstance* gameInstance = world->OwningGameInstance;
            if (gameInstance) {
                for (int i = 0; i < gameInstance->LocalPlayers.Num(); ++i) {
                    SDK::ULocalPlayer* localPlayer = gameInstance->LocalPlayers[i];
                    if (localPlayer && localPlayer->PlayerController) {
                        playerControllers.push_back(localPlayer->PlayerController);
                    }
                }
            }
        }
        return playerControllers;
    }

    SDK::UCheatManager* getCheatManager() {
        if (!cheatManager) {
            SDK::APlayerController* playerController = getLocalPlayer()->PlayerController;
            cheatManager = playerController->CheatManager;
        }
        return cheatManager;
    }

    //SDK::UCheatManager* getCheatManager() {
    //    if (!cheatManager) {
    //        SDK::ULocalPlayer* localPlayer = getLocalPlayer();
    //        if (localPlayer && localPlayer->PlayerController) {
    //            // Safely cast CheatManager to UCheatManager
    //            cheatManager = static_cast<SDK::UCheatManager*>(localPlayer->PlayerController->CheatManager);
    //        }
    //    }
    //    return static_cast<SDK::UCheatManager*>(cheatManager);
    //}

    SDK::APlayerCameraManager* GetCameraManager() {
        if (auto world = Globals::getWorld()) {
            if (auto localPlayer = world->OwningGameInstance->LocalPlayers[0]) {
                if (auto playerController = localPlayer->PlayerController) {
                    return playerController->PlayerCameraManager;
                }
            }
        }
        return nullptr;
    }

    std::string getDllDirectory() {
        char buffer[MAX_PATH];
        if (GetModuleFileNameA(GetModuleHandleA("SDK_cheat_menu.dll"), buffer, MAX_PATH)) {
            std::string fullPath(buffer);
            size_t lastSlashPos = fullPath.find_last_of("\\/");
            return (lastSlashPos != std::string::npos) ? fullPath.substr(0, lastSlashPos) : "";
        }
        return "";
    }
}