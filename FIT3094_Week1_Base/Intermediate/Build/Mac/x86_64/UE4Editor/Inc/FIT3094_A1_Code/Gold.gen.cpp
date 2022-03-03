// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FIT3094_A1_Code/Gold.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGold() {}
// Cross Module References
	FIT3094_A1_CODE_API UClass* Z_Construct_UClass_AGold_NoRegister();
	FIT3094_A1_CODE_API UClass* Z_Construct_UClass_AGold();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FIT3094_A1_Code();
// End Cross Module References
	void AGold::StaticRegisterNativesAGold()
	{
	}
	UClass* Z_Construct_UClass_AGold_NoRegister()
	{
		return AGold::StaticClass();
	}
	struct Z_Construct_UClass_AGold_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGold_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FIT3094_A1_Code,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGold_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Gold.h" },
		{ "ModuleRelativePath", "Gold.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGold_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGold>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGold_Statics::ClassParams = {
		&AGold::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGold_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGold_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGold()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGold_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGold, 522571805);
	template<> FIT3094_A1_CODE_API UClass* StaticClass<AGold>()
	{
		return AGold::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGold(Z_Construct_UClass_AGold, &AGold::StaticClass, TEXT("/Script/FIT3094_A1_Code"), TEXT("AGold"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGold);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
