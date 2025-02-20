#pragma once
#define WIN32_LEAN_AND_MEAN

// #include "SDK.hpp"
#include "../../SDK/Engine_classes.hpp"

#include <vector>

namespace Globals {
    SDK::UGameEngine *getEngine();
    SDK::UGameInstance *getInstance();
    SDK::UWorld *getWorld();
    SDK::ULocalPlayer *getLocalPlayer();
    SDK::ACharacter *getCharacter();

    //std::vector<SDK::APlayerController*> GetAllPlayerControllers();
    //std::vector<SDK::APlayerState*> GetAllPlayerStates();

    SDK::UGameInstance* getGameInstance();
    SDK::UCheatManager* getCheatManager();
    SDK::UCheatManager* getCheatManager();
    SDK::APlayerCameraManager* GetCameraManager();

    std::string getDllDirectory();

    SDK::AHUD* getHUD();
    SDK::APlayerController* GetPlayerController();
    std::vector<SDK::APlayerController*> getPlayerControllers();

    template <typename T> T getObject(SDK::UClass *uClass) {
        for (int i = 0; i < SDK::UObject::GObjects->Num(); i++) {
            SDK::UObject *Obj = SDK::UObject::GObjects->GetByIndex(i);

            if (!Obj) {
                continue;
            }

            if (Obj->IsA(uClass)) {
                if (!Obj->IsDefaultObject()) {
                    return (T)Obj;
                }
            }
        }

        return nullptr;
    }

    template <typename T> std::vector<T> getAllObjects(SDK::UClass *uClass) {
        std::vector<T> objects;

        for (int i = 0; i < SDK::UObject::GObjects->Num(); i++) {
            SDK::UObject *Obj = SDK::UObject::GObjects->GetByIndex(i);

            if (!Obj) {
                continue;
            }

            if (Obj->IsA(uClass)) {
                if (!Obj->IsDefaultObject()) {
                    objects.push_back((T)Obj);
                }
            }
        }

        return objects;
    }
}