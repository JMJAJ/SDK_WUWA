#include "hook.hpp"

#define RETURN_IF_STOPPING(result, message)                                                                            \
    if (result == STOP_EXECUTION) {                                                                                    \
        printf("stopped: %p \n", message);                                                                                \
        return;                                                                                                        \
    }

namespace Hooks {
    std::vector<std::string> tab{};
    bool in_array(const std::string& value, const std::vector<std::string>& array)
    {
        return std::find(array.begin(), array.end(), value) != array.end();
    }

    std::map<Type, std::map<std::string, std::vector<Callback>>> handlers = {
        {Type::PRE, std::map<std::string, std::vector<Callback>>()},
        {Type::POST, std::map<std::string, std::vector<Callback>>()},
    };

    typedef void(WINAPI* ProcessEvent)(SDK::UObject* pObject, SDK::UFunction* pFunction, void* pParams, void* pResult);
    ProcessEvent oProcessEvent = nullptr;

    ExecutionFlag runHooks(Type type, const std::string& functionName, SDK::UObject* pObject, SDK::UFunction* pFunction,
        void* pParams) {

        if (handlers[type].find(functionName) != handlers[type].end()) {
            for (auto& handler : handlers[type][functionName]) {
                const auto result = handler(pObject, pFunction, pParams);

                if (result == STOP_EXECUTION) {
                    return STOP_EXECUTION;
                }
            }
        }

        return CONTINUE_EXECUTION;
    }

    // Static method to log memory in a more structured way
    static void LogMemory(const void* memory, size_t size) {
        if (!memory || size == 0) return;

        const unsigned char* bytes = static_cast<const unsigned char*>(memory);
        std::ostringstream oss;

        oss << "[MEMORY] ";
        for (size_t i = 0; i < size; ++i) {
            oss << std::hex << std::setw(2) << std::setfill('0')
                << static_cast<int>(bytes[i]) << " ";

            // Add a newline every 16 bytes for readability
            if ((i + 1) % 16 == 0 && i < size - 1) {
                oss << "\n        ";
            }
        }
    }

    // Specialized value logging for different types
    static void LogParameterValue(std::ostringstream& log,
        SDK::FProperty* property,
        void* paramValue) {
        size_t size = property->ElementSize;

        if (size == sizeof(int)) {
            log << *reinterpret_cast<int*>(paramValue);
        }
        else if (size == sizeof(float)) {
            log << *reinterpret_cast<float*>(paramValue);
        }
        else if (size == sizeof(SDK::FName)) {
            SDK::FName* name = reinterpret_cast<SDK::FName*>(paramValue);
            log << name->ToString();
        }
        else {
            log << "Raw: " << paramValue;
            // Optional detailed memory dump for complex types
            LogMemory(paramValue, size);
        }
    }

	// Log parameters for a given function
    static void LogParameters(SDK::UFunction* pFunction, void* pParams, std::ostringstream& log) {
        if (!pFunction || !pParams) return;

        log << "[PARAMS] Function: " << pFunction->GetFullName() << "\n";

        SDK::FField* child = reinterpret_cast<SDK::FField*>(pFunction->Children);
        while (child) {
            SDK::FProperty* property = reinterpret_cast<SDK::FProperty*>(child);
            if (property) {
                const std::string paramName = property->Name.ToString();
                size_t offset = property->Offset;
                size_t size = property->ElementSize;

                log << "  Param: " << paramName
                    << ", Offset: " << offset
                    << ", Size: " << size;

                void* paramValue = reinterpret_cast<char*>(pParams) + offset;

                // Enhanced type detection and logging
                if (property->ArrayDim == 1) {
                    log << ", Value: ";
                    LogParameterValue(log, property, paramValue);
                }
                else {
                    log << ", Array/Complex Type (Dim: "
                        << property->ArrayDim << ")";
                }
                log << "\n";
            }

            child = reinterpret_cast<SDK::FField*>(child->Next);
        }
    }

    void WINAPI myProcessEvent(SDK::UObject* pObject, SDK::UFunction* pFunction, void* pParams, void* pResult) {
        if (!pObject || !pFunction) {
            return oProcessEvent(pObject, pFunction, pParams, pResult);
        }

        // Only log if logging is enabled
        ProcessEventLogger::process(pObject, pFunction, pParams, pResult);

        // Obtain the function name (adjust as needed)
        const std::string functionName = pFunction->GetFullName().substr(9);

        // Run pre-hooks
        const auto preResult = runHooks(Type::PRE, functionName, pObject, pFunction, pParams);
        RETURN_IF_STOPPING(preResult, "Pre-hooks: Execution for " + functionName + " was stopped");

        const auto preWildResult = runHooks(Type::PRE, "*", pObject, pFunction, pParams);
        RETURN_IF_STOPPING(preWildResult, "Pre-hooks (Wildcard): Execution for " + functionName + " was stopped");

        // (Optional) If you want detailed parameter logging here,
        // you could construct an ostringstream and call LogParameters:
        // std::ostringstream paramLog;
        // LogParameters(pFunction, pParams, paramLog);
        // Logger::info(paramLog.str());

        // Call the original ProcessEvent
        oProcessEvent(pObject, pFunction, pParams, pResult);

        // Run post-hooks
        const auto postWildResult = runHooks(Type::POST, "*", pObject, pFunction, pParams);
        RETURN_IF_STOPPING(postWildResult, "Post-hooks (Wildcard): Execution for " + functionName + " was stopped");

        const auto postResult = runHooks(Type::POST, functionName, pObject, pFunction, pParams);
        RETURN_IF_STOPPING(postResult, "Post-hooks: Execution for " + functionName + " was stopped");
    }

    void init() {
        const auto base = SDK::InSDKUtils::GetImageBase();

        // Menu::init() implicitly calls MH_Initialize() so we can just go ahead and hook the functions
        MH_Initialize();
        MH_CreateHook((LPVOID)(base + SDK::Offsets::ProcessEvent), myProcessEvent, (LPVOID*)&oProcessEvent);
        MH_EnableHook((LPVOID)(base + SDK::Offsets::ProcessEvent));

        // Logger::info("MinHook has been initialized.");
    }

    void shutdown() {
        const auto base = SDK::InSDKUtils::GetImageBase();

        MH_DisableHook((LPVOID)(base + SDK::Offsets::ProcessEvent));
        MH_RemoveHook((LPVOID)(base + SDK::Offsets::ProcessEvent));
        MH_Uninitialize();
    }

    void registerHook(std::string functionName, Callback handler, Type type) {
        if (handlers[type].find(functionName) == handlers[type].end()) {
            handlers[type][functionName] = std::vector<Callback>();
        }

        handlers[type][functionName].push_back(handler);
    }
}