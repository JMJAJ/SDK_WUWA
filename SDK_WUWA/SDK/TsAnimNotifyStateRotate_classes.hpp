#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsAnimNotifyStateRotate

#include "Basic.hpp"

#include "KuroRenderingRuntimeBPPlugin_classes.hpp"
#include "GameplayTags_structs.hpp"
#include "EAnsRotateBlackboardType_structs.hpp"


namespace SDK
{

// TypeScriptGeneratedClass TsAnimNotifyStateRotate.TsAnimNotifyStateRotate_C
// 0x0060 (0x00A8 - 0x0048)
class UTsAnimNotifyStateRotate_C final : public UKuroAnimNotifyState
{
public:
	float                                         _l__;                                              // 0x0048(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          _______;                                           // 0x004C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          _s__l;                                             // 0x004D(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1C40[0x2];                                     // 0x004E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class UCurveFloat*                            Curve;                                             // 0x0050(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ____lO_;                                           // 0x0058(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1C41[0x3];                                     // 0x0059(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         _lO_;                                              // 0x005C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          _n_______;                                         // 0x0060(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	EAnsRotateBlackboardType                      ____;                                              // 0x0061(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1C42[0x6];                                     // 0x0062(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 ________0;                                         // 0x0068(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	float                                         _b_l__;                                            // 0x0078(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ___l__;                                            // 0x007C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          _Star___Minus__;                                   // 0x0080(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          __Star___Minus_H;                                  // 0x0081(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1C43[0x6];                                     // 0x0082(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  O____h;                                            // 0x0088(0x0020)(Edit, BlueprintVisible)

public:
	bool K2_NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime);
	bool K2_NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation);
	bool K2_NotifyBegin(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration);
	void Initialize();

	class FString GetNotifyName() const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TsAnimNotifyStateRotate_C">();
	}
	static class UTsAnimNotifyStateRotate_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTsAnimNotifyStateRotate_C>();
	}
};
static_assert(alignof(UTsAnimNotifyStateRotate_C) == 0x000008, "Wrong alignment on UTsAnimNotifyStateRotate_C");
static_assert(sizeof(UTsAnimNotifyStateRotate_C) == 0x0000A8, "Wrong size on UTsAnimNotifyStateRotate_C");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, _l__) == 0x000048, "Member 'UTsAnimNotifyStateRotate_C::_l__' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, _______) == 0x00004C, "Member 'UTsAnimNotifyStateRotate_C::_______' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, _s__l) == 0x00004D, "Member 'UTsAnimNotifyStateRotate_C::_s__l' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, Curve) == 0x000050, "Member 'UTsAnimNotifyStateRotate_C::Curve' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, ____lO_) == 0x000058, "Member 'UTsAnimNotifyStateRotate_C::____lO_' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, _lO_) == 0x00005C, "Member 'UTsAnimNotifyStateRotate_C::_lO_' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, _n_______) == 0x000060, "Member 'UTsAnimNotifyStateRotate_C::_n_______' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, ____) == 0x000061, "Member 'UTsAnimNotifyStateRotate_C::____' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, ________0) == 0x000068, "Member 'UTsAnimNotifyStateRotate_C::________0' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, _b_l__) == 0x000078, "Member 'UTsAnimNotifyStateRotate_C::_b_l__' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, ___l__) == 0x00007C, "Member 'UTsAnimNotifyStateRotate_C::___l__' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, _Star___Minus__) == 0x000080, "Member 'UTsAnimNotifyStateRotate_C::_Star___Minus__' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, __Star___Minus_H) == 0x000081, "Member 'UTsAnimNotifyStateRotate_C::__Star___Minus_H' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyStateRotate_C, O____h) == 0x000088, "Member 'UTsAnimNotifyStateRotate_C::O____h' has a wrong offset!");

}

