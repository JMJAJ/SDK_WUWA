#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: KuroNetwork

#include "Basic.hpp"


namespace SDK
{

// Enum KuroNetwork.EHttpMethod
// NumValues: 0x0003
enum class EHttpMethod : uint8
{
	GET                                      = 0,
	POST                                     = 1,
	EHttpMethod_MAX                          = 2,
};

// ScriptStruct KuroNetwork.KuroPrivateKey
// 0x0030 (0x0030 - 0x0000)
struct FKuroPrivateKey final
{
public:
	class FString                                 Modulus;                                           // 0x0000(0x0010)(Edit, ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Exponent;                                          // 0x0010(0x0010)(Edit, ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 PrivateExponent;                                   // 0x0020(0x0010)(Edit, ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(FKuroPrivateKey) == 0x000008, "Wrong alignment on FKuroPrivateKey");
static_assert(sizeof(FKuroPrivateKey) == 0x000030, "Wrong size on FKuroPrivateKey");
static_assert(offsetof(FKuroPrivateKey, Modulus) == 0x000000, "Member 'FKuroPrivateKey::Modulus' has a wrong offset!");
static_assert(offsetof(FKuroPrivateKey, Exponent) == 0x000010, "Member 'FKuroPrivateKey::Exponent' has a wrong offset!");
static_assert(offsetof(FKuroPrivateKey, PrivateExponent) == 0x000020, "Member 'FKuroPrivateKey::PrivateExponent' has a wrong offset!");

// ScriptStruct KuroNetwork.KuroPublicKey
// 0x0020 (0x0020 - 0x0000)
struct FKuroPublicKey final
{
public:
	class FString                                 Modulus;                                           // 0x0000(0x0010)(Edit, ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Exponent;                                          // 0x0010(0x0010)(Edit, ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(FKuroPublicKey) == 0x000008, "Wrong alignment on FKuroPublicKey");
static_assert(sizeof(FKuroPublicKey) == 0x000020, "Wrong size on FKuroPublicKey");
static_assert(offsetof(FKuroPublicKey, Modulus) == 0x000000, "Member 'FKuroPublicKey::Modulus' has a wrong offset!");
static_assert(offsetof(FKuroPublicKey, Exponent) == 0x000010, "Member 'FKuroPublicKey::Exponent' has a wrong offset!");

}

