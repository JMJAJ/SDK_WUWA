#include "pointers.hpp"

namespace Pointers {
    void generalInfo() {
        if (showGeneralInfoMenu && ImGui::Begin("General Info", &showGeneralInfoMenu)) {

            SDK::UGameEngine* getEngine = Globals::getEngine();
            SDK::UGameInstance* getInstance = Globals::getInstance();
            SDK::UGameInstance* gameInstance = Globals::getGameInstance();
            SDK::UWorld* getWorld = Globals::getWorld();
            SDK::UWorld* getWorld2 = SDK::UWorld::GetWorld();
            SDK::AGameStateBase* gameState = getWorld->GameState;
            SDK::TArray<SDK::APlayerState*> playerArray;

            ImGui::Text("Engine: %p", getEngine);
            ImGui::SameLine();
            if (ImGui::Button("Copy##Engine"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", getEngine);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("Game Instance: %p", getInstance);
            ImGui::SameLine();
            if (ImGui::Button("Copy##Instance"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", getInstance);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("World: %p", getWorld);
            ImGui::SameLine();
            if (ImGui::Button("Copy##World"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", getWorld);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("World (Test): %p", getWorld2);  // same as getWorld (who would say that xD)
            ImGui::SameLine();
            if (ImGui::Button("Copy##WorldTest"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", getWorld2);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("Game State: %p", gameState);
            ImGui::SameLine();
            if (ImGui::Button("Copy##GameState"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", gameState);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("Player Array: %p", playerArray);
            ImGui::SameLine();
            if (ImGui::Button("Copy##playerArray"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", playerArray);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("base Address: %p", baseAddr);
            ImGui::SameLine();
            if (ImGui::Button("Copy##baseAddr"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", baseAddr);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("Append String Address: %p", baseAddr + SDK::Offsets::AppendString);  // not needed
            ImGui::SameLine();
            if (ImGui::Button("Copy##AppendString"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", baseAddr + SDK::Offsets::AppendString);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("GNames Address: %p", baseAddr + SDK::Offsets::GNames);    // not needed | https://www.youtube.com/watch?v=ZZycj2z9iWs (its not GNames after UE4.23 but FNamePool)
            ImGui::SameLine();
            if (ImGui::Button("Copy##GNames"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", baseAddr + SDK::Offsets::GNames);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("GObjects Address: %p", baseAddr + SDK::Offsets::GObjects);  // not needed | https://www.youtube.com/watch?v=OxCABgj0ftI
            ImGui::SameLine();
            if (ImGui::Button("Copy##GObjects"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", baseAddr + SDK::Offsets::GObjects);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Text("Process Event: %p", baseAddr + SDK::Offsets::ProcessEvent);
            ImGui::SameLine();
            if (ImGui::Button("Copy##ProcessEvent"))
            {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "%p", baseAddr + SDK::Offsets::ProcessEvent);
                ImGui::SetClipboardText(buffer);
            }

            ImGui::Separator();

            //if (ImGui::Button("FNamePool")) {

            //    // Get FNamePool address
            //    uint64_t FNamePoolAddress = Memory::read<uint64_t>(baseAddr + 0x8D33ED0);

            //    // Print the FNamePool address
            //    printf("FNamePool Address: 0x%llx\n", FNamePoolAddress);

            //    SDK::FName FNameInstance;

            //    // Calculate chunk and entry index
            //    SDK::int32 ChunkIndex = FNameInstance.ComparisonIndex / 16384;
            //    SDK::int32 EntryIndex = FNameInstance.ComparisonIndex % 16384;

            //    // Print the chunk and entry index
            //    printf("Chunk Index: %d, Entry Index: %d\n", ChunkIndex, EntryIndex);

            //    // Get the chunk
            //    uint64_t Chunk = Memory::read<uint64_t>(FNamePoolAddress + (ChunkIndex * 8));

            //    // Print the chunk address
            //    printf("Chunk Address: 0x%llx\n", Chunk);

            //    // Get the FNameEntry
            //    uint64_t FNameEntryPtr = Memory::read<uint64_t>(Chunk + (EntryIndex * 8));

            //    // Print the FNameEntry pointer
            //    printf("FNameEntry Pointer: 0x%llx\n", FNameEntryPtr);

            //    // Check if it is Ansi or Wide
            //    bool bIsWide = (Memory::read<uint16_t>(FNameEntryPtr) & 0x1) == 0x1;

                //if (bIsWide) {
                //    wchar_t WideName[NAME_SIZE] = { 0 };
                //    Memory::read(reinterpret_cast<static void*>(FNameEntryPtr + OffsetToWideName), WideName, NAME_SIZE * sizeof(wchar_t));

                //    // Print the wide name
                //    wprintf(L"Wide Name: %ls\n", WideName);
                //}
                //else {
                //    char AnsiName[NAME_SIZE] = { 0 };
                //    Memory::read(reinterpret_cast<static void*>(FNameEntryPtr + OffsetToAnsiName), AnsiName, NAME_SIZE);

                //    // Print the ANSI name
                //    printf("Ansi Name: %s\n", AnsiName);
                //}

            //}

        }
    }
}