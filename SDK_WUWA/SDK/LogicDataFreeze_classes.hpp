#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LogicDataFreeze

#include "Basic.hpp"

#include "GameplayTags_structs.hpp"
#include "EBulletObject_structs.hpp"
#include "LogicDataBase_classes.hpp"


namespace SDK
{

// TypeScriptGeneratedClass LogicDataFreeze.LogicDataFreeze_C
// 0x0028 (0x0068 - 0x0040)
class ULogicDataFreeze_C final : public ULogicDataBase_C
{
public:
	uint8                                         Pad_3160[0x7];                                     // 0x0039(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  Tags;                                              // 0x0040(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	float                                         FreezeTime;                                        // 0x0060(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EBulletObject                                 Target;                                            // 0x0064(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"LogicDataFreeze_C">();
	}
	static class ULogicDataFreeze_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ULogicDataFreeze_C>();
	}
};
static_assert(alignof(ULogicDataFreeze_C) == 0x000008, "Wrong alignment on ULogicDataFreeze_C");
static_assert(sizeof(ULogicDataFreeze_C) == 0x000068, "Wrong size on ULogicDataFreeze_C");
static_assert(offsetof(ULogicDataFreeze_C, Tags) == 0x000040, "Member 'ULogicDataFreeze_C::Tags' has a wrong offset!");
static_assert(offsetof(ULogicDataFreeze_C, FreezeTime) == 0x000060, "Member 'ULogicDataFreeze_C::FreezeTime' has a wrong offset!");
static_assert(offsetof(ULogicDataFreeze_C, Target) == 0x000064, "Member 'ULogicDataFreeze_C::Target' has a wrong offset!");

}

