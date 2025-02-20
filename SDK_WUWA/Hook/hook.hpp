#pragma once

#include <string>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <map>

#include "../SDK/Engine_classes.hpp"
#include "../SDK/CoreUObject_structs.hpp"

#include "../logger/logger.hpp"
#include "../minhook/include/MinHook.h"
#include "../ProcessLogger/ProcessEventLogger.hpp"

namespace Hooks {
    enum ExecutionFlag {
        CONTINUE_EXECUTION = 0,
        STOP_EXECUTION = 1,
    };

    enum Type {
        PRE,
        POST,
    };

    typedef ExecutionFlag(*Callback)(SDK::UObject*, SDK::UFunction*, void*);

    //extern std::ostringstream paramLog;

    void init();
    void shutdown();
    void registerHook(std::string functionName, Callback handler, Type type = Type::PRE);
    //void LogParameters(SDK::UFunction* pFunction, void* pParams, std::ostringstream& log);
}