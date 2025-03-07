#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ABP_Base_Sword

#include "Basic.hpp"

#include "AnimGraphRuntime_structs.hpp"
#include "KuroAnim_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass ABP_Base_Sword.ABP_Base_Sword_C
// 0x04E0 (0x0B00 - 0x0620)
class UABP_Base_Sword_C final : public UAnimInstance
{
public:
	uint8                                         Pad_3851[0x8];                                     // 0x0618(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0620(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root;                                // 0x0628(0x0038)()
	struct FAnimNode_PhyCloth                     AnimGraphNode_PhyCloth;                            // 0x0660(0x0440)()
	struct FAnimNode_ConvertComponentToLocalSpace AnimGraphNode_ComponentToLocalSpace;               // 0x0AA0(0x0020)()
	struct FAnimNode_ConvertLocalToComponentSpace AnimGraphNode_LocalToComponentSpace;               // 0x0AC0(0x0020)()
	struct FAnimNode_RefPose                      AnimGraphNode_LocalRefPose;                        // 0x0AE0(0x0018)()

public:
	void ExecuteUbergraph_ABP_Base_Sword(int32 EntryPoint);
	void AnimGraph(struct FPoseLink* Param_AnimGraph);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ABP_Base_Sword_C">();
	}
	static class UABP_Base_Sword_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UABP_Base_Sword_C>();
	}
};
static_assert(alignof(UABP_Base_Sword_C) == 0x000010, "Wrong alignment on UABP_Base_Sword_C");
static_assert(sizeof(UABP_Base_Sword_C) == 0x000B00, "Wrong size on UABP_Base_Sword_C");
static_assert(offsetof(UABP_Base_Sword_C, UberGraphFrame) == 0x000620, "Member 'UABP_Base_Sword_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UABP_Base_Sword_C, AnimGraphNode_Root) == 0x000628, "Member 'UABP_Base_Sword_C::AnimGraphNode_Root' has a wrong offset!");
static_assert(offsetof(UABP_Base_Sword_C, AnimGraphNode_PhyCloth) == 0x000660, "Member 'UABP_Base_Sword_C::AnimGraphNode_PhyCloth' has a wrong offset!");
static_assert(offsetof(UABP_Base_Sword_C, AnimGraphNode_ComponentToLocalSpace) == 0x000AA0, "Member 'UABP_Base_Sword_C::AnimGraphNode_ComponentToLocalSpace' has a wrong offset!");
static_assert(offsetof(UABP_Base_Sword_C, AnimGraphNode_LocalToComponentSpace) == 0x000AC0, "Member 'UABP_Base_Sword_C::AnimGraphNode_LocalToComponentSpace' has a wrong offset!");
static_assert(offsetof(UABP_Base_Sword_C, AnimGraphNode_LocalRefPose) == 0x000AE0, "Member 'UABP_Base_Sword_C::AnimGraphNode_LocalRefPose' has a wrong offset!");

}

