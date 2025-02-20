#pragma once

#include "../Globals/globals.hpp"
#include "../../Main/pch.h"

#include <stdio.h>

namespace Pointers {
	static bool showGeneralInfoMenu = false;
	const auto baseAddr = SDK::InSDKUtils::GetImageBase();

    extern UC::TArray<SDK::APlayerState*> playerArray;
    extern SDK::AGameStateBase* gameState;
    extern SDK::UGameEngine* getEngine;
    extern SDK::UGameInstance* gameInstance;
    extern SDK::UGameInstance* getInstance;
    extern SDK::UWorld* getWorld;
    extern SDK::UWorld* getWorld2;

	void generalInfo();
}