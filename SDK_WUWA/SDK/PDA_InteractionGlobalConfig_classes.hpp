#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PDA_InteractionGlobalConfig

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PDA_InteractionGlobalConfig.PDA_InteractionGlobalConfig_C
// 0x01C0 (0x01F8 - 0x0038)
class UPDA_InteractionGlobalConfig_C final : public UPrimaryDataAsset
{
public:
	bool                                          O___4b__iS;                                        // 0x0038(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_31AA[0x7];                                     // 0x0039(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSoftObjectPath                        __b_P_;                                            // 0x0040(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        ______P_;                                          // 0x0060(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        ____P_;                                            // 0x0080(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        Fourb____P_;                                       // 0x00A0(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        Fourb____P__0;                                     // 0x00C0(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        ____P__0;                                          // 0x00E0(0x0020)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        Fourb____P__1;                                     // 0x0100(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        ______;                                            // 0x0120(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        ____4___;                                          // 0x0140(0x0020)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        Fourb____;                                         // 0x0160(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        Fourb__4___1;                                      // 0x0180(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        Fourb__4___2;                                      // 0x01A0(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSoftObjectPath                        Fourb__4___3;                                      // 0x01C0(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	bool                                          O___I0__iS;                                        // 0x01E0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          _b4__;                                             // 0x01E1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          _bI__;                                             // 0x01E2(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_31AB[0x5];                                     // 0x01E3(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UPDA_InteractionGlobalConfigParameters_C* ___p;                                              // 0x01E8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          _4__;                                              // 0x01F0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          _I__;                                              // 0x01F1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PDA_InteractionGlobalConfig_C">();
	}
	static class UPDA_InteractionGlobalConfig_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPDA_InteractionGlobalConfig_C>();
	}
};
static_assert(alignof(UPDA_InteractionGlobalConfig_C) == 0x000008, "Wrong alignment on UPDA_InteractionGlobalConfig_C");
static_assert(sizeof(UPDA_InteractionGlobalConfig_C) == 0x0001F8, "Wrong size on UPDA_InteractionGlobalConfig_C");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, O___4b__iS) == 0x000038, "Member 'UPDA_InteractionGlobalConfig_C::O___4b__iS' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, __b_P_) == 0x000040, "Member 'UPDA_InteractionGlobalConfig_C::__b_P_' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, ______P_) == 0x000060, "Member 'UPDA_InteractionGlobalConfig_C::______P_' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, ____P_) == 0x000080, "Member 'UPDA_InteractionGlobalConfig_C::____P_' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, Fourb____P_) == 0x0000A0, "Member 'UPDA_InteractionGlobalConfig_C::Fourb____P_' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, Fourb____P__0) == 0x0000C0, "Member 'UPDA_InteractionGlobalConfig_C::Fourb____P__0' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, ____P__0) == 0x0000E0, "Member 'UPDA_InteractionGlobalConfig_C::____P__0' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, Fourb____P__1) == 0x000100, "Member 'UPDA_InteractionGlobalConfig_C::Fourb____P__1' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, ______) == 0x000120, "Member 'UPDA_InteractionGlobalConfig_C::______' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, ____4___) == 0x000140, "Member 'UPDA_InteractionGlobalConfig_C::____4___' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, Fourb____) == 0x000160, "Member 'UPDA_InteractionGlobalConfig_C::Fourb____' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, Fourb__4___1) == 0x000180, "Member 'UPDA_InteractionGlobalConfig_C::Fourb__4___1' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, Fourb__4___2) == 0x0001A0, "Member 'UPDA_InteractionGlobalConfig_C::Fourb__4___2' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, Fourb__4___3) == 0x0001C0, "Member 'UPDA_InteractionGlobalConfig_C::Fourb__4___3' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, O___I0__iS) == 0x0001E0, "Member 'UPDA_InteractionGlobalConfig_C::O___I0__iS' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, _b4__) == 0x0001E1, "Member 'UPDA_InteractionGlobalConfig_C::_b4__' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, _bI__) == 0x0001E2, "Member 'UPDA_InteractionGlobalConfig_C::_bI__' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, ___p) == 0x0001E8, "Member 'UPDA_InteractionGlobalConfig_C::___p' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, _4__) == 0x0001F0, "Member 'UPDA_InteractionGlobalConfig_C::_4__' has a wrong offset!");
static_assert(offsetof(UPDA_InteractionGlobalConfig_C, _I__) == 0x0001F1, "Member 'UPDA_InteractionGlobalConfig_C::_I__' has a wrong offset!");

}

