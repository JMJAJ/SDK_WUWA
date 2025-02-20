#include "ProcessEventLogger.hpp"

namespace ProcessEventLogger {

    // Mutex for thread safety
    std::mutex loggerMutex;

    // Logger state and data
    static bool bEnabled = false;
    bool initialized = false;
    static std::string path;
    static std::unordered_map<std::string, std::pair<int, std::vector<void*>>> functionDatabase;
    std::unordered_map<std::string, std::unordered_set<void*>> loggedParams;

    // Enable logging
    void enable() {
        std::lock_guard<std::mutex> lock(loggerMutex);
        bEnabled = true;
        Logger::info("Process Event Logger: Enabled");
    }

    // Disable logging
    void disable() {
        std::lock_guard<std::mutex> lock(loggerMutex);
        bEnabled = false;
        Logger::info("Process Event Logger: Disabled");
    }

    //  logging state
    void toggle() {
        bEnabled ? disable() : enable();
    }

    // Check if logging is enabled
    bool isEnabled() {
        std::lock_guard<std::mutex> lock(loggerMutex);
        return bEnabled;
    }

    std::string binaryToHexString(const SDK::TArray<uint8_t>& data) {
        std::stringstream ss;
        ss << std::hex << std::setfill('0');
        for (const auto& byte : data) {
            ss << std::setw(2) << static_cast<int>(byte);
        }
        return ss.str();
    }

    // Initialization routine
    void init() {
        try {
            path = Globals::getDllDirectory().append("\\ProcessEventLog.txt");

            std::ofstream testFile(path, std::ios::app);
            if (!testFile.is_open()) {
                throw std::runtime_error("Failed to open log file at: " + path);
            }
            testFile.close();
        }
        catch (const std::exception& ex) {
            Logger::error("ProcessEventLogger init failed: " + std::string(ex.what()));
        }
    }

    void logFunctionParameters(std::ofstream& logFile, SDK::UFunction* pFunction, void* pParams) {
        if (!pFunction || !pParams) return;

        std::string functionName = pFunction->GetFullName();
        
        // Get stored parameters for this function
        auto it = functionDatabase.find(functionName);
        if (it == functionDatabase.end()) {
            return;
        }

        logFile << "Function Call: " << functionName << "\n";
        logFile << "  Function Name: " << pFunction->GetName().c_str() << "\n";
        logFile << "  Full Name: " << pFunction->GetFullName() << "\n";
        logFile << "  Flags: 0x" << std::hex << pFunction->FunctionFlags << std::dec << "\n";
        logFile << "  Size: " << pFunction->Size << "\n\n";
        
        logFile << "  Parameters:\n";
        
        // Log each parameter's raw value from stored addresses
        const auto& paramAddresses = it->second.second;
        for (size_t i = 0; i < paramAddresses.size(); i++) {
            void* paramAddr = paramAddresses[i];
            if (!paramAddr) continue;

            logFile << "    Parameter " << i + 1 << " (Address: 0x" 
                   << std::hex << reinterpret_cast<uintptr_t>(paramAddr) << std::dec << "):\n";

            // Try to interpret the value in different ways
            // We'll read 8 bytes to support both 32-bit and 64-bit values
            uint64_t rawValue = 0;
            if (IsBadReadPtr(paramAddr, sizeof(uint64_t)) == 0) {
                memcpy(&rawValue, paramAddr, sizeof(uint64_t));
                
                // Output raw value first
                logFile << "      Raw (hex): 0x" << std::hex << rawValue << std::dec << "\n";

                // Only try to interpret values if we have enough space
                if (sizeof(uint64_t) >= sizeof(int32_t)) {
                    // 32-bit interpretations with alignment check
                    if ((reinterpret_cast<uintptr_t>(paramAddr) % sizeof(int32_t)) == 0) {
                        int32_t int32Val = *reinterpret_cast<int32_t*>(paramAddr);
                        float floatVal = *reinterpret_cast<float*>(paramAddr);
                        logFile << "      As Int32: " << int32Val << "\n";
                        logFile << "      As Float: " << floatVal << "\n";
                    }
                }

                if (sizeof(uint64_t) >= sizeof(int64_t)) {
                    // 64-bit interpretations with alignment check
                    if ((reinterpret_cast<uintptr_t>(paramAddr) % sizeof(int64_t)) == 0) {
                        int64_t int64Val = *reinterpret_cast<int64_t*>(paramAddr);
                        double doubleVal = *reinterpret_cast<double*>(paramAddr);
                        logFile << "      As Int64: " << int64Val << "\n";
                        logFile << "      As Double: " << doubleVal << "\n";
                    }
                }

                if (sizeof(uint64_t) >= sizeof(bool)) {
                    bool boolVal = *reinterpret_cast<bool*>(paramAddr);
                    logFile << "      As Bool: " << (boolVal ? "true" : "false") << "\n";
                }
                
                // Try to interpret as FString if it looks like a pointer and has proper alignment
                //if (rawValue > 0x10000 && rawValue < 0x7FFFFFFFFFFFFFFF) {  // Basic pointer validity check
                //    // Try to interpret as FString
                //    SDK::FString* fstr = reinterpret_cast<SDK::FString*>(paramAddr);
                //    if (IsBadReadPtr(fstr, sizeof(SDK::FString)) == 0) {
                //        std::string str;
                //        try {
                //            str = fstr->ToString();
                //            if (!str.empty() && str.length() < 1024) { // Reasonable string length check
                //                logFile << "      As FString: \"" << str << "\"\n";
                //            }
                //        } catch (...) {
                //            // Ignore any exceptions during string conversion
                //        }
                //    }
                //    
                //    // Also try as raw string pointer for non-FString cases
                //    char* strPtr = reinterpret_cast<char*>(rawValue);
                //    if (IsBadReadPtr(strPtr, 1) == 0) {
                //        // Read up to 1024 characters to prevent buffer overruns
                //        char buffer[1024] = {0};
                //        size_t safeLen = 0;
                //        
                //        // Safely probe the string length
                //        for (safeLen = 0; safeLen < 1023; safeLen++) {
                //            if (IsBadReadPtr(strPtr + safeLen, 1) != 0 || strPtr[safeLen] == '\0') {
                //                break;
                //            }
                //        }
                //        
                //        if (safeLen > 0) {
                //            memcpy(buffer, strPtr, safeLen);
                //            buffer[safeLen] = '\0';
                //            if (strlen(buffer) > 0) {
                //                logFile << "      As String: \"" << buffer << "\"\n";
                //            }
                //        }
                //    }
                //}
            }
            logFile << "\n";
        }
        logFile << "\n";
    }

    void logBasicFunctionInfo(std::ofstream& logFile, SDK::UFunction* pFunction, void* pParams) {
        // Log basic information about the function
        logFile << "  Function Name: " << pFunction->GetName() << "\n";
        logFile << "  Full Path: " << pFunction->GetFullName() << "\n";

        // Static class (from UObject)
        logFile << "  Static Class: " << pFunction->StaticClass() << "\n";

        // Class details
        logFile << "  Class: " << pFunction->Class << "\n";
        if (pFunction->Class) {
            logFile << "    Class Name: " << pFunction->Class->GetName() << "\n";
            logFile << "    Class Full Name: " << pFunction->Class->GetFullName() << "\n";
        }

        // Function Index
        logFile << "  Index: " << pFunction->Index << "\n";

        // Super function (if available)
        logFile << "  Super: " << (pFunction->Super ? pFunction->Super->GetName() : "None") << "\n";
        if (pFunction->Super) {
            logFile << "    Super Full Name: " << pFunction->Super->GetFullName() << "\n";
        }

        // Default object
        logFile << "  Get Default Obj: " << pFunction->GetDefaultObj() << "\n";
        if (pFunction->GetDefaultObj()) {
            logFile << "    Default Object Name: " << pFunction->GetDefaultObj()->GetName() << "\n";
            logFile << "    Default Object Full Name: " << pFunction->GetDefaultObj()->GetFullName() << "\n";
        }

        // Parameter pointer
        logFile << "  Parameter Pointer: " << pParams << "\n";

        // Function pointer
        logFile << "  Function Pointer: " << pFunction << "\n";

        // Log VTable pointer
        logFile << "  VTable Address: " << pFunction->VTable << "\n";

        // Function Flags
        logFile << "  Function Flags: 0x" << std::hex << pFunction->FunctionFlags << std::dec << "\n";

        // Object Flags
        logFile << "  Flags: 0x" << std::hex << static_cast<SDK::int32>(pFunction->Flags) << std::dec << "\n";
        logFile << "  Flags (Decimal): " << static_cast<SDK::int32>(pFunction->Flags) << "\n";

        // Check if the function has a return value
        // logFunctionFlags(logFile, pFunction);

        logFile << "  Size of pFunction: " << pFunction->Size << "\n";

        // Log the return value offset if the function has one
        //if (hasReturnValue) {
        //    logFile << "  Is Subclass Of: " << pFunction->IsSubclassOf() << "\n";
        //}

        // Log Child Properties (parameters)
        if (pFunction->ChildProperties != nullptr) {
            logFile << "  Child Properties: " << pFunction->ChildProperties << "\n";

            // Iterate over all child properties
            SDK::UField* field = pFunction->Children;
            while (field) {
                logFile << "    Property Name: " << field->GetName() << "\n";
                logFile << "    Full Property Name: " << field->GetFullName() << "\n";
                logFile << "    Static Class: " << field->StaticClass() << "\n";
                logFile << "    GObjects: " << field->GObjects << "\n";
                field = field->Next;  // Move to the next child
            }
        }
        else {
            logFile << "  No Child Properties\n";
        }

        // Log the outer object (owner of the function)
        if (pFunction->Outer) {
            logFile << "  Outer: " << pFunction->Outer->GetName() << "\n";
            logFile << "    Outer Full Name: " << pFunction->Outer->GetFullName() << "\n";
        }
        else {
            logFile << "  No Outer Object\n";
        }

        logFile << "\n";
    }

    void process(SDK::UObject* pObject, SDK::UFunction* pFunction, void* pParams, void* pResult) {
        if (!isEnabled()) return;

        std::string functionName = pFunction->GetFullName();

        {
            std::lock_guard<std::mutex> lock(loggerMutex);

            // Remove duplicate filtering so that every call is logged:
            // if (loggedParams[functionName].find(pParams) != loggedParams[functionName].end()) {
            //     return;
            // }
            // Instead, simply update the database without filtering:
            functionDatabase[functionName].first++;
            functionDatabase[functionName].second.push_back(pParams);

            // (Optional) You can clear loggedParams if you want to avoid any accidental filtering:
            // loggedParams[functionName].insert(pParams);
        }

        // Write to log file (adjust path and error handling as needed)
        std::ofstream logFile(path, std::ios::app);
        try {
            if (logFile.is_open()) {
                logFile << "Normal: " << functionName << " called\n";
                // Log basic function info and parameters:
                // logBasicFunctionInfo(logFile, pFunction, pParams);
                // logFunctionParameters(logFile, pFunction, pParams);
                logFile << std::endl;
                logFile.close();
            }
            else {
                Logger::error("Failed to write to log file: " + path);
            }
        }
        catch (const std::exception& ex) {
            Logger::error("Exception while writing to log file: " + std::string(ex.what()));
        }
    }

    // Flush logged parameter pointers
    void flushLoggedParams() {
        std::lock_guard<std::mutex> lock(loggerMutex);
        loggedParams.clear();
    }

    // Flush the log file and clear the function database
    void flush() {
        try {
            std::lock_guard<std::mutex> lock(loggerMutex);
            std::ofstream ofs(path, std::ofstream::out | std::ofstream::trunc);
            if (ofs.is_open()) {
                ofs.close();
                Logger::info("Process Event Logger: Flushed");
            }
            else {
                Logger::error("Failed to flush the log file: " + path);
            }
            functionDatabase.clear();
        }
        catch (const std::exception& ex) {
            Logger::error("Exception while flushing logger: " + std::string(ex.what()));
        }
    }

    // Flush the function database
    void flushFunctionDatabase() {
        std::lock_guard<std::mutex> lock(loggerMutex);
        functionDatabase.clear();
        Logger::info("Process Event Logger: Function Database Flushed");
    }

    // Get the function database
    const std::unordered_map<std::string, std::pair<int, std::vector<void*>>>& getFunctionDatabase() {
        std::lock_guard<std::mutex> lock(loggerMutex);
        return functionDatabase;
    }

    // Menu
    void ProcessLoggerMenu() {
        if (!showProcessLoggerMenu) return;

        static int sortingOption = 0;

        ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
        if (ImGui::Begin("Process Logger", &showProcessLoggerMenu, ImGuiWindowFlags_MenuBar)) {

            // Menu Bar
            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Export Data", nullptr)) {
                        // TODO: Add export functionality
                    }
                    if (ImGui::MenuItem("Clear All", nullptr)) {
                        ProcessEventLogger::flush();
                        ProcessEventLogger::flushFunctionDatabase();
                        ProcessEventLogger::flushLoggedParams();
                    }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("View")) {
                    static bool showNormalFunctions = true;
                    ImGui::MenuItem("Show Normal Functions", nullptr, &showNormalFunctions);

                    // Sorting Options
                    const char* sortingOptions[] = { "No Order at all", "Latest to Earliest", "Calls Ascending", "Calls Descending" };
                    ImGui::Combo("Sort By", &sortingOption, sortingOptions, IM_ARRAYSIZE(sortingOptions));

                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            // Control Panel
            ImGui::BeginChild("ControlPanel", ImVec2(0, 100), true);
            {
                // Status and Controls Row
                ImGui::Columns(2, "controlColumns", false);

                // Column 1: Logger Status
                {
                    bool isEnabled = ProcessEventLogger::isEnabled();
                    ImGui::PushStyleColor(ImGuiCol_Text, isEnabled ? ImVec4(0.0f, 1.0f, 0.0f, 1.0f) : ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
                    ImGui::Text("Logger Status: %s", isEnabled ? "ACTIVE" : "INACTIVE");
                    ImGui::PopStyleColor();

                    if (ImGui::Button(isEnabled ? "Stop Logging" : "Start Logging", ImVec2(150, 30))) {
                        ProcessEventLogger::toggle();
                    }
                }
                ImGui::NextColumn();

                // Column 2: Statistics
                {
                    const auto& functionDatabase = ProcessEventLogger::getFunctionDatabase();
                    int totalCalls = 0;
                    for (const auto& func : functionDatabase) {
                        totalCalls += func.second.first;
                    }
                    ImGui::Text("Total Functions: %zu", functionDatabase.size());
                    ImGui::Text("Total Calls: %d", totalCalls);
                }
                ImGui::Columns(1);
            }
            ImGui::EndChild();

            // Search and Filter Bar
            static ImGuiTextFilter filter;
            ImGui::SetNextItemWidth(-1);
            if (filter.Draw("Search functions... (Filter by name, type, or address)##search", -1)) {
                // Filter will automatically update when text changes
            }

            // Function List
            if (ImGui::BeginChild("FunctionList", ImVec2(0, 0), true)) {
                const auto& functionDatabase = ProcessEventLogger::getFunctionDatabase();

                // Sort functions based on selected sorting option
                std::vector<std::pair<std::string, std::pair<int, std::vector<void*>>>> sortedFunctions(
                    functionDatabase.begin(), functionDatabase.end());

                switch (sortingOption) {
                case 0: // Without any order
                    break;
                case 1: // Latest to Earliest (reverse order)
                    std::reverse(sortedFunctions.begin(), sortedFunctions.end());
                    break;
                case 2: // Calls Ascending
                    std::sort(sortedFunctions.begin(), sortedFunctions.end(),
                        [](const auto& a, const auto& b) { return a.second.first < b.second.first; });
                    break;
                case 3: // Calls Descending
                    std::sort(sortedFunctions.begin(), sortedFunctions.end(),
                        [](const auto& a, const auto& b) { return a.second.first > b.second.first; });
                    break;
                }

                // Display functions
                for (const auto& [functionName, data] : sortedFunctions) {
                    // Only display if it passes the filter
                    if (filter.PassFilter(functionName.c_str())) {
                        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));

                        std::string nodeLabel = std::format("{} (Called: {})", functionName, data.first);

                        if (ImGui::TreeNode(functionName.c_str(), "%s", nodeLabel.c_str())) {
                            ImGui::PopStyleColor();

                            // Function details
                            ImGui::Indent(10);
                            ImGui::TextWrapped("Full Name: %s", functionName.c_str());
                            ImGui::Text("Call Count: %d", data.first);

                            // Parameter list in a collapsible section
                            if (ImGui::TreeNode("Parameters")) {
                                if (ImGui::BeginTable("parameters", 2, ImGuiTableFlags_Borders)) {
                                    ImGui::TableSetupColumn("Index");
                                    ImGui::TableSetupColumn("Address");
                                    ImGui::TableHeadersRow();

                                    for (size_t i = 0; i < data.second.size(); i++) {
                                        ImGui::TableNextRow();
                                        ImGui::TableNextColumn();
                                        ImGui::Text("%zu", i + 1);
                                        ImGui::TableNextColumn();

                                        // Format address as hex string for better readability
                                        std::stringstream ss;
                                        ss << "0x" << std::hex << std::uppercase << data.second[i];
                                        ImGui::Text("%s", ss.str().c_str());
                                    }
                                    ImGui::EndTable();
                                }
                                ImGui::TreePop();
                            }

                            ImGui::Unindent(10);
                            ImGui::TreePop();
                        }
                        else {
                            ImGui::PopStyleColor();
                        }
                    }
                }
            }
            ImGui::EndChild();
        }
        ImGui::End();
    }
}