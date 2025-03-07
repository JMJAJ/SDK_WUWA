#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Nvzhu

#include "Basic.hpp"

#include "TsBaseCharacter_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_Nvzhu.BP_Nvzhu_C
// 0x0020 (0x07D0 - 0x07B0)
class ABP_Nvzhu_C final : public ATsBaseCharacter_C
{
public:
	uint8                                         Pad_2C05[0x7];                                     // 0x07A1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UKuroAdjustableCapsuleComponent*        Bip001LThighTwist;                                 // 0x07A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UKuroAdjustableCapsuleComponent*        Bip001RThighTwist;                                 // 0x07B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UKuroAdjustableCapsuleComponent*        Bip001Spine2;                                      // 0x07B8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 WeaponCase1;                                       // 0x07C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 WeaponCase0;                                       // 0x07C8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	void FightCommand(bool IsInAir);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_Nvzhu_C">();
	}
	static class ABP_Nvzhu_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_Nvzhu_C>();
	}
};
static_assert(alignof(ABP_Nvzhu_C) == 0x000010, "Wrong alignment on ABP_Nvzhu_C");
static_assert(sizeof(ABP_Nvzhu_C) == 0x0007D0, "Wrong size on ABP_Nvzhu_C");
static_assert(offsetof(ABP_Nvzhu_C, Bip001LThighTwist) == 0x0007A8, "Member 'ABP_Nvzhu_C::Bip001LThighTwist' has a wrong offset!");
static_assert(offsetof(ABP_Nvzhu_C, Bip001RThighTwist) == 0x0007B0, "Member 'ABP_Nvzhu_C::Bip001RThighTwist' has a wrong offset!");
static_assert(offsetof(ABP_Nvzhu_C, Bip001Spine2) == 0x0007B8, "Member 'ABP_Nvzhu_C::Bip001Spine2' has a wrong offset!");
static_assert(offsetof(ABP_Nvzhu_C, WeaponCase1) == 0x0007C0, "Member 'ABP_Nvzhu_C::WeaponCase1' has a wrong offset!");
static_assert(offsetof(ABP_Nvzhu_C, WeaponCase0) == 0x0007C8, "Member 'ABP_Nvzhu_C::WeaponCase0' has a wrong offset!");

}

