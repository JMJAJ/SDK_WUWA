#pragma once

#include "../../Hook/hook.hpp"
#include "../Config/config.hpp"
#include "../Globals/globals.hpp"

#include <chrono>

namespace NoClip {
	static bool showNoClipMenu = false;

	void toggle();
	void tick();
	void menu();
	void init();
}