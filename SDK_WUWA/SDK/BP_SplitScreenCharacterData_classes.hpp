#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_SplitScreenCharacterData

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_SplitScreenCharacterData.BP_SplitScreenCharacterData_C
// 0x0040 (0x0078 - 0x0038)
class UBP_SplitScreenCharacterData_C final : public UPrimaryDataAsset
{
public:
	class UClass*                                 CharacterActorClass;                               // 0x0038(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimSequence*                          Cos_Pose_AnimSequence;                             // 0x0040(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                PointLight_Location;                               // 0x0048(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           PointLight_Color;                                  // 0x0054(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           EyeLightSimulation_Color;                          // 0x0064(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_SplitScreenCharacterData_C">();
	}
	static class UBP_SplitScreenCharacterData_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_SplitScreenCharacterData_C>();
	}
};
static_assert(alignof(UBP_SplitScreenCharacterData_C) == 0x000008, "Wrong alignment on UBP_SplitScreenCharacterData_C");
static_assert(sizeof(UBP_SplitScreenCharacterData_C) == 0x000078, "Wrong size on UBP_SplitScreenCharacterData_C");
static_assert(offsetof(UBP_SplitScreenCharacterData_C, CharacterActorClass) == 0x000038, "Member 'UBP_SplitScreenCharacterData_C::CharacterActorClass' has a wrong offset!");
static_assert(offsetof(UBP_SplitScreenCharacterData_C, Cos_Pose_AnimSequence) == 0x000040, "Member 'UBP_SplitScreenCharacterData_C::Cos_Pose_AnimSequence' has a wrong offset!");
static_assert(offsetof(UBP_SplitScreenCharacterData_C, PointLight_Location) == 0x000048, "Member 'UBP_SplitScreenCharacterData_C::PointLight_Location' has a wrong offset!");
static_assert(offsetof(UBP_SplitScreenCharacterData_C, PointLight_Color) == 0x000054, "Member 'UBP_SplitScreenCharacterData_C::PointLight_Color' has a wrong offset!");
static_assert(offsetof(UBP_SplitScreenCharacterData_C, EyeLightSimulation_Color) == 0x000064, "Member 'UBP_SplitScreenCharacterData_C::EyeLightSimulation_Color' has a wrong offset!");

}

