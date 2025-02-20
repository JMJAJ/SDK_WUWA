#pragma once
#include "../Addons/Globals/globals.hpp"
#include "../logger/chain/chain.hpp"
#include "../logger/logger.hpp"
#include "../Main/pch.h"
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <any>

namespace ProcessEventLogger {
	static bool showProcessLoggerMenu = false;

    void enable();
    void disable();
    void toggle();
    bool isEnabled();
    void init();
    void process(SDK::UObject* pObject, SDK::UFunction* pFunction, void* pParams, void* pResult);
    void flush();
    void flushFunctionDatabase();
    void flushLoggedParams();
    const std::unordered_map<std::string, std::pair<int, std::vector<void*>>>& getFunctionDatabase();
    void logFunctionParameters(std::ofstream& logFile, SDK::UFunction* pFunction, void* pParams);
    void ProcessLoggerMenu();
}
