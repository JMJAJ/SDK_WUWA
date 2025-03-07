#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ThunderGenerator

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "AkAudio_structs.hpp"
#include "KuroRenderingRuntimeBPPlugin_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ThunderGenerator.BP_ThunderGenerator_C
// 0x00A0 (0x05A0 - 0x0500)
class ABP_ThunderGenerator_C final : public AThunderGenerator
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0500(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UKuroPostProcessComponent*              KuroPostProcess_Vignette;                          // 0x0508(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPDA_ThunderConfigMap_C*                ThunderConfigMap;                                  // 0x0510(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPDA_ThunderConfig_C*                   ThunderConfig;                                     // 0x0518(0x0008)(Edit, BlueprintVisible, ZeroConstructor, Transient, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAkAudioEvent*                          CachedAudioEvent2D;                                // 0x0520(0x0008)(Edit, BlueprintVisible, ZeroConstructor, Transient, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CachedTransition;                                  // 0x0528(0x0004)(Edit, BlueprintVisible, ZeroConstructor, Transient, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          PartialCloudFlash;                                 // 0x052C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_377E[0x3];                                     // 0x052D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CloudThunderHeight;                                // 0x0530(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_377F[0xC];                                     // 0x0534(0x000C)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             CachedCameraTransform;                             // 0x0540(0x0030)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	class UPDA_CloudThunderData_C*                CloudThunderConfigData;                            // 0x0570(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         PartialThunderIndex;                               // 0x0578(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CachedPartialEmissionScale;                        // 0x057C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CachedThunderPlaySpeedScale;                       // 0x0580(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DebugPartitialThunder;                             // 0x0584(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3780[0x3];                                     // 0x0585(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         DebugPartitialThunderDensity;                      // 0x0588(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                ThunderVectorCameraSpace;                          // 0x058C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void UpdateCloudThunderParameter();
	bool CalculateThunderPosition_Cloud(const struct FTransform& CameraTransform, bool bAttack, struct FVector* OutPosition);
	void ForceUpdate();
	bool CalculateThunderPosition_Common(const struct FTransform& CameraTransform, bool bAttack, struct FVector* OutPosition);
	bool CalculateThunderPosition(const struct FTransform& CameraTransform, struct FVector* OutPosition, bool bAttack);
	void ClearThunder();
	void UpdateAudio2D();
	void UserConstructionScript();
	void OnReceiveThunderAttack(const struct FVector& Location, bool bAttack);
	void OnThunderTypeChanged();
	void OnUpdateThunderEffect(float DeltaSeconds);
	void ReceiveEndPlay(EEndPlayReason EndPlayReason);
	void ExecuteUbergraph_BP_ThunderGenerator(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ThunderGenerator_C">();
	}
	static class ABP_ThunderGenerator_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ThunderGenerator_C>();
	}
};
static_assert(alignof(ABP_ThunderGenerator_C) == 0x000010, "Wrong alignment on ABP_ThunderGenerator_C");
static_assert(sizeof(ABP_ThunderGenerator_C) == 0x0005A0, "Wrong size on ABP_ThunderGenerator_C");
static_assert(offsetof(ABP_ThunderGenerator_C, UberGraphFrame) == 0x000500, "Member 'ABP_ThunderGenerator_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, KuroPostProcess_Vignette) == 0x000508, "Member 'ABP_ThunderGenerator_C::KuroPostProcess_Vignette' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, ThunderConfigMap) == 0x000510, "Member 'ABP_ThunderGenerator_C::ThunderConfigMap' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, ThunderConfig) == 0x000518, "Member 'ABP_ThunderGenerator_C::ThunderConfig' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CachedAudioEvent2D) == 0x000520, "Member 'ABP_ThunderGenerator_C::CachedAudioEvent2D' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CachedTransition) == 0x000528, "Member 'ABP_ThunderGenerator_C::CachedTransition' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, PartialCloudFlash) == 0x00052C, "Member 'ABP_ThunderGenerator_C::PartialCloudFlash' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CloudThunderHeight) == 0x000530, "Member 'ABP_ThunderGenerator_C::CloudThunderHeight' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CachedCameraTransform) == 0x000540, "Member 'ABP_ThunderGenerator_C::CachedCameraTransform' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CloudThunderConfigData) == 0x000570, "Member 'ABP_ThunderGenerator_C::CloudThunderConfigData' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, PartialThunderIndex) == 0x000578, "Member 'ABP_ThunderGenerator_C::PartialThunderIndex' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CachedPartialEmissionScale) == 0x00057C, "Member 'ABP_ThunderGenerator_C::CachedPartialEmissionScale' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CachedThunderPlaySpeedScale) == 0x000580, "Member 'ABP_ThunderGenerator_C::CachedThunderPlaySpeedScale' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, DebugPartitialThunder) == 0x000584, "Member 'ABP_ThunderGenerator_C::DebugPartitialThunder' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, DebugPartitialThunderDensity) == 0x000588, "Member 'ABP_ThunderGenerator_C::DebugPartitialThunderDensity' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, ThunderVectorCameraSpace) == 0x00058C, "Member 'ABP_ThunderGenerator_C::ThunderVectorCameraSpace' has a wrong offset!");

}

