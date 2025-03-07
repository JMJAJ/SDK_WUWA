#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PD_CharacterControllerData

#include "Basic.hpp"

#include "ECharacterControllerType_structs.hpp"
#include "ECharacterMeshPart_structs.hpp"
#include "ECharacterBodySpecifiedType_structs.hpp"
#include "SMaterialControllerFloatGroup_structs.hpp"
#include "ECharacterSlotSpecifiedType_structs.hpp"
#include "ECharacterControllerApplyType_structs.hpp"
#include "SMaterialControllerLoopTime_structs.hpp"
#include "ECharacterControllerChannelSwitch_structs.hpp"
#include "SMaterialControllerColorGroup_structs.hpp"
#include "ECharacterControllerUVSwitch_structs.hpp"
#include "SMaterialControllerFloatParameter_structs.hpp"
#include "SMaterialControllerColorParameter_structs.hpp"
#include "SMaterialControllerTextureParameter_structs.hpp"
#include "KuroRenderingRuntimeBPPlugin_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PD_CharacterControllerData.PD_CharacterControllerData_C
// 0x4A48 (0x4A98 - 0x0050)
class UPD_CharacterControllerData_C final : public UKuroMaterialControllerDataAsset
{
public:
	ECharacterControllerType                      DataType;                                          // 0x0050(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECharacterBodySpecifiedType                   SpecifiedBodyType;                                 // 0x0051(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B91[0x6];                                     // 0x0052(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<ECharacterMeshPart>                    SpecifiedParts;                                    // 0x0058(0x0010)(Edit, BlueprintVisible)
	ECharacterSlotSpecifiedType                   SpecifiedSlotType;                                 // 0x0068(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECharacterControllerApplyType                 MaterialModifyType;                                // 0x0069(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B92[0x6];                                     // 0x006A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     ReplaceMaterial;                                   // 0x0070(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          UseRim;                                            // 0x0078(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          UseOutline;                                        // 0x0079(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          UseDissolve;                                       // 0x007A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B93[0x1];                                     // 0x007B(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerLoopTime           LoopTime;                                          // 0x007C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          RimRevertProperty;                                 // 0x0088(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, AdvancedDisplay)
	bool                                          RimUseTex;                                         // 0x0089(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	ECharacterControllerChannelSwitch             RimChannel;                                        // 0x008A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B94[0x5];                                     // 0x008B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerFloatGroup         RimRange;                                          // 0x0090(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerColorGroup         RimColor;                                          // 0x0240(0x0660)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          OutlineRevertProperty;                             // 0x08A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, AdvancedDisplay)
	bool                                          OutlineUseTex;                                     // 0x08A1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B95[0x6];                                     // 0x08A2(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerFloatGroup         OutlineWidth;                                      // 0x08A8(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerColorGroup         OutlineColor;                                      // 0x0A58(0x0660)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          DissolveRevertProperty;                            // 0x10B8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, AdvancedDisplay)
	ECharacterControllerChannelSwitch             DissolveChannel;                                   // 0x10B9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B96[0x6];                                     // 0x10BA(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerFloatGroup         DissolveProgress;                                  // 0x10C0(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerColorGroup         DissolveColor;                                     // 0x1270(0x0660)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerFloatGroup         DissolveColorIntensity;                            // 0x18D0(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          UseTextureSample;                                  // 0x1A80(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          TextureSampleRevertProperty;                       // 0x1A81(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          UseAlphaToMask;                                    // 0x1A82(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B97[0x5];                                     // 0x1A83(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UTexture2D*                             MaskTexture;                                       // 0x1A88(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSMaterialControllerFloatGroup         Rotation;                                          // 0x1A90(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	ECharacterControllerUVSwitch::ECharacterControllerUVSwitch UVSelection;                                       // 0x1C40(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B98[0x7];                                     // 0x1C41(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerColorGroup         TextureScaleAndOffset;                             // 0x1C48(0x0660)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerColorGroup         TextureSpeed;                                      // 0x22A8(0x0660)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerColorGroup         TextureColorTint;                                  // 0x2908(0x0660)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerFloatGroup         OutlineIntensity;                                  // 0x2F68(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          UseOuterOutlineEffect;                             // 0x3118(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          MobileUseDifferentMaterial;                        // 0x3119(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B99[0x6];                                     // 0x311A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     ReplaceMaterialMobile;                             // 0x3120(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          RevertMaterial;                                    // 0x3128(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, AdvancedDisplay)
	bool                                          UseParameterModify;                                // 0x3129(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B9A[0x6];                                     // 0x312A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FSMaterialControllerFloatParameter> FloatParameters;                                   // 0x3130(0x0010)(Edit, BlueprintVisible)
	bool                                          UseColor;                                          // 0x3140(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          ColorRevertProperty;                               // 0x3141(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, AdvancedDisplay)
	bool                                          BaseUseTex;                                        // 0x3142(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B9B[0x5];                                     // 0x3143(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerColorGroup         BaseColor;                                         // 0x3148(0x0660)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerFloatGroup         BaseColorIntensity;                                // 0x37A8(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          EmissionUseTex;                                    // 0x3958(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B9C[0x7];                                     // 0x3959(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerColorGroup         EmissionColor;                                     // 0x3960(0x0660)(Edit, BlueprintVisible, ExposeOnSpawn, HasGetValueTypeHash)
	struct FSMaterialControllerFloatGroup         EmissionIntensity;                                 // 0x3FC0(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TArray<struct FSMaterialControllerColorParameter> ColorParameters;                                   // 0x4170(0x0010)(Edit, BlueprintVisible)
	bool                                          UseCustomMaterialEffect;                           // 0x4180(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CustomRevertProperty;                              // 0x4181(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, AdvancedDisplay)
	uint8                                         Pad_2B9D[0x6];                                     // 0x4182(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FSMaterialControllerFloatParameter> CustomFloatParameters;                             // 0x4188(0x0010)(Edit, BlueprintVisible)
	TArray<struct FSMaterialControllerColorParameter> CustomColorParameters;                             // 0x4198(0x0010)(Edit, BlueprintVisible, ExposeOnSpawn)
	TArray<struct FSMaterialControllerTextureParameter> CustomTextureParameters;                           // 0x41A8(0x0010)(Edit, BlueprintVisible)
	bool                                          UseMotionOffset;                                   // 0x41B8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          MotionOffsetRevertProperty;                        // 0x41B9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, AdvancedDisplay)
	uint8                                         Pad_2B9E[0x2];                                     // 0x41BA(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         MotionOffsetLength;                                // 0x41BC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MotionAffectVertexRange;                           // 0x41C0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B9F[0x4];                                     // 0x41C4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FString>                         WeaponCases;                                       // 0x41C8(0x0010)(Edit, BlueprintVisible)
	bool                                          IgnoreTimeDilation;                                // 0x41D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          HiddenAfterEffect;                                 // 0x41D9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2BA0[0x6];                                     // 0x41DA(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerFloatGroup         DissolveSmooth;                                    // 0x41E0(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FSMaterialControllerFloatGroup         MotionNoiseSpeed;                                  // 0x4390(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          UseDitherEffect;                                   // 0x4540(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          DitherRevertProperty;                              // 0x4541(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, AdvancedDisplay)
	uint8                                         Pad_2BA1[0x6];                                     // 0x4542(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerFloatGroup         DitherValue;                                       // 0x4548(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TArray<class FString>                         OtherCases;                                        // 0x46F8(0x0010)(Edit, BlueprintVisible)
	bool                                          CleanOriginEffect;                                 // 0x4708(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay)
	uint8                                         Pad_2BA2[0x7];                                     // 0x4709(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSMaterialControllerFloatGroup         RimIntensity;                                      // 0x4710(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TArray<class FString>                         CustomPartNames;                                   // 0x48C0(0x0010)(Edit, BlueprintVisible)
	struct FSMaterialControllerFloatGroup         TextureMaskRange;                                  // 0x48D0(0x01B0)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          MaskOriginEffect;                                  // 0x4A80(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          UpdateAtLeastOneFrame;                             // 0x4A81(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2BA3[0x6];                                     // 0x4A82(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FString>                         CustomExcludePartNames;                            // 0x4A88(0x0010)(Edit, BlueprintVisible)

public:
	void InitCache();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PD_CharacterControllerData_C">();
	}
	static class UPD_CharacterControllerData_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPD_CharacterControllerData_C>();
	}
};
static_assert(alignof(UPD_CharacterControllerData_C) == 0x000008, "Wrong alignment on UPD_CharacterControllerData_C");
static_assert(sizeof(UPD_CharacterControllerData_C) == 0x004A98, "Wrong size on UPD_CharacterControllerData_C");
static_assert(offsetof(UPD_CharacterControllerData_C, DataType) == 0x000050, "Member 'UPD_CharacterControllerData_C::DataType' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, SpecifiedBodyType) == 0x000051, "Member 'UPD_CharacterControllerData_C::SpecifiedBodyType' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, SpecifiedParts) == 0x000058, "Member 'UPD_CharacterControllerData_C::SpecifiedParts' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, SpecifiedSlotType) == 0x000068, "Member 'UPD_CharacterControllerData_C::SpecifiedSlotType' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, MaterialModifyType) == 0x000069, "Member 'UPD_CharacterControllerData_C::MaterialModifyType' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, ReplaceMaterial) == 0x000070, "Member 'UPD_CharacterControllerData_C::ReplaceMaterial' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseRim) == 0x000078, "Member 'UPD_CharacterControllerData_C::UseRim' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseOutline) == 0x000079, "Member 'UPD_CharacterControllerData_C::UseOutline' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseDissolve) == 0x00007A, "Member 'UPD_CharacterControllerData_C::UseDissolve' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, LoopTime) == 0x00007C, "Member 'UPD_CharacterControllerData_C::LoopTime' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, RimRevertProperty) == 0x000088, "Member 'UPD_CharacterControllerData_C::RimRevertProperty' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, RimUseTex) == 0x000089, "Member 'UPD_CharacterControllerData_C::RimUseTex' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, RimChannel) == 0x00008A, "Member 'UPD_CharacterControllerData_C::RimChannel' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, RimRange) == 0x000090, "Member 'UPD_CharacterControllerData_C::RimRange' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, RimColor) == 0x000240, "Member 'UPD_CharacterControllerData_C::RimColor' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, OutlineRevertProperty) == 0x0008A0, "Member 'UPD_CharacterControllerData_C::OutlineRevertProperty' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, OutlineUseTex) == 0x0008A1, "Member 'UPD_CharacterControllerData_C::OutlineUseTex' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, OutlineWidth) == 0x0008A8, "Member 'UPD_CharacterControllerData_C::OutlineWidth' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, OutlineColor) == 0x000A58, "Member 'UPD_CharacterControllerData_C::OutlineColor' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, DissolveRevertProperty) == 0x0010B8, "Member 'UPD_CharacterControllerData_C::DissolveRevertProperty' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, DissolveChannel) == 0x0010B9, "Member 'UPD_CharacterControllerData_C::DissolveChannel' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, DissolveProgress) == 0x0010C0, "Member 'UPD_CharacterControllerData_C::DissolveProgress' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, DissolveColor) == 0x001270, "Member 'UPD_CharacterControllerData_C::DissolveColor' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, DissolveColorIntensity) == 0x0018D0, "Member 'UPD_CharacterControllerData_C::DissolveColorIntensity' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseTextureSample) == 0x001A80, "Member 'UPD_CharacterControllerData_C::UseTextureSample' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, TextureSampleRevertProperty) == 0x001A81, "Member 'UPD_CharacterControllerData_C::TextureSampleRevertProperty' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseAlphaToMask) == 0x001A82, "Member 'UPD_CharacterControllerData_C::UseAlphaToMask' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, MaskTexture) == 0x001A88, "Member 'UPD_CharacterControllerData_C::MaskTexture' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, Rotation) == 0x001A90, "Member 'UPD_CharacterControllerData_C::Rotation' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UVSelection) == 0x001C40, "Member 'UPD_CharacterControllerData_C::UVSelection' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, TextureScaleAndOffset) == 0x001C48, "Member 'UPD_CharacterControllerData_C::TextureScaleAndOffset' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, TextureSpeed) == 0x0022A8, "Member 'UPD_CharacterControllerData_C::TextureSpeed' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, TextureColorTint) == 0x002908, "Member 'UPD_CharacterControllerData_C::TextureColorTint' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, OutlineIntensity) == 0x002F68, "Member 'UPD_CharacterControllerData_C::OutlineIntensity' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseOuterOutlineEffect) == 0x003118, "Member 'UPD_CharacterControllerData_C::UseOuterOutlineEffect' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, MobileUseDifferentMaterial) == 0x003119, "Member 'UPD_CharacterControllerData_C::MobileUseDifferentMaterial' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, ReplaceMaterialMobile) == 0x003120, "Member 'UPD_CharacterControllerData_C::ReplaceMaterialMobile' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, RevertMaterial) == 0x003128, "Member 'UPD_CharacterControllerData_C::RevertMaterial' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseParameterModify) == 0x003129, "Member 'UPD_CharacterControllerData_C::UseParameterModify' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, FloatParameters) == 0x003130, "Member 'UPD_CharacterControllerData_C::FloatParameters' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseColor) == 0x003140, "Member 'UPD_CharacterControllerData_C::UseColor' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, ColorRevertProperty) == 0x003141, "Member 'UPD_CharacterControllerData_C::ColorRevertProperty' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, BaseUseTex) == 0x003142, "Member 'UPD_CharacterControllerData_C::BaseUseTex' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, BaseColor) == 0x003148, "Member 'UPD_CharacterControllerData_C::BaseColor' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, BaseColorIntensity) == 0x0037A8, "Member 'UPD_CharacterControllerData_C::BaseColorIntensity' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, EmissionUseTex) == 0x003958, "Member 'UPD_CharacterControllerData_C::EmissionUseTex' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, EmissionColor) == 0x003960, "Member 'UPD_CharacterControllerData_C::EmissionColor' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, EmissionIntensity) == 0x003FC0, "Member 'UPD_CharacterControllerData_C::EmissionIntensity' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, ColorParameters) == 0x004170, "Member 'UPD_CharacterControllerData_C::ColorParameters' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseCustomMaterialEffect) == 0x004180, "Member 'UPD_CharacterControllerData_C::UseCustomMaterialEffect' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, CustomRevertProperty) == 0x004181, "Member 'UPD_CharacterControllerData_C::CustomRevertProperty' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, CustomFloatParameters) == 0x004188, "Member 'UPD_CharacterControllerData_C::CustomFloatParameters' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, CustomColorParameters) == 0x004198, "Member 'UPD_CharacterControllerData_C::CustomColorParameters' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, CustomTextureParameters) == 0x0041A8, "Member 'UPD_CharacterControllerData_C::CustomTextureParameters' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseMotionOffset) == 0x0041B8, "Member 'UPD_CharacterControllerData_C::UseMotionOffset' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, MotionOffsetRevertProperty) == 0x0041B9, "Member 'UPD_CharacterControllerData_C::MotionOffsetRevertProperty' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, MotionOffsetLength) == 0x0041BC, "Member 'UPD_CharacterControllerData_C::MotionOffsetLength' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, MotionAffectVertexRange) == 0x0041C0, "Member 'UPD_CharacterControllerData_C::MotionAffectVertexRange' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, WeaponCases) == 0x0041C8, "Member 'UPD_CharacterControllerData_C::WeaponCases' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, IgnoreTimeDilation) == 0x0041D8, "Member 'UPD_CharacterControllerData_C::IgnoreTimeDilation' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, HiddenAfterEffect) == 0x0041D9, "Member 'UPD_CharacterControllerData_C::HiddenAfterEffect' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, DissolveSmooth) == 0x0041E0, "Member 'UPD_CharacterControllerData_C::DissolveSmooth' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, MotionNoiseSpeed) == 0x004390, "Member 'UPD_CharacterControllerData_C::MotionNoiseSpeed' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UseDitherEffect) == 0x004540, "Member 'UPD_CharacterControllerData_C::UseDitherEffect' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, DitherRevertProperty) == 0x004541, "Member 'UPD_CharacterControllerData_C::DitherRevertProperty' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, DitherValue) == 0x004548, "Member 'UPD_CharacterControllerData_C::DitherValue' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, OtherCases) == 0x0046F8, "Member 'UPD_CharacterControllerData_C::OtherCases' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, CleanOriginEffect) == 0x004708, "Member 'UPD_CharacterControllerData_C::CleanOriginEffect' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, RimIntensity) == 0x004710, "Member 'UPD_CharacterControllerData_C::RimIntensity' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, CustomPartNames) == 0x0048C0, "Member 'UPD_CharacterControllerData_C::CustomPartNames' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, TextureMaskRange) == 0x0048D0, "Member 'UPD_CharacterControllerData_C::TextureMaskRange' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, MaskOriginEffect) == 0x004A80, "Member 'UPD_CharacterControllerData_C::MaskOriginEffect' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, UpdateAtLeastOneFrame) == 0x004A81, "Member 'UPD_CharacterControllerData_C::UpdateAtLeastOneFrame' has a wrong offset!");
static_assert(offsetof(UPD_CharacterControllerData_C, CustomExcludePartNames) == 0x004A88, "Member 'UPD_CharacterControllerData_C::CustomExcludePartNames' has a wrong offset!");

}

