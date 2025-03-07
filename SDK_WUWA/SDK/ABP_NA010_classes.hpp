#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ABP_NA010

#include "Basic.hpp"

#include "ABP_BaseAnimal_classes.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass ABP_NA010.ABP_NA010_C
// 0x0000 (0x3A20 - 0x3A20)
class UABP_NA010_C final : public UABP_BaseAnimal_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ABP_NA010_C">();
	}
	static class UABP_NA010_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UABP_NA010_C>();
	}
};
static_assert(alignof(UABP_NA010_C) == 0x000010, "Wrong alignment on UABP_NA010_C");
static_assert(sizeof(UABP_NA010_C) == 0x003A20, "Wrong size on UABP_NA010_C");

}

