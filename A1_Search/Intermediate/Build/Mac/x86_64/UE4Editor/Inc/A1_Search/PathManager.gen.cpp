// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1_Search/Public/PathManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePathManager() {}
// Cross Module References
	A1_SEARCH_API UClass* Z_Construct_UClass_APathManager_NoRegister();
	A1_SEARCH_API UClass* Z_Construct_UClass_APathManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_A1_Search();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	A1_SEARCH_API UEnum* Z_Construct_UEnum_A1_Search_ESearchType();
	A1_SEARCH_API UClass* Z_Construct_UClass_ALevelGenerator_NoRegister();
	A1_SEARCH_API UClass* Z_Construct_UClass_AShip_NoRegister();
// End Cross Module References
	void APathManager::StaticRegisterNativesAPathManager()
	{
	}
	UClass* Z_Construct_UClass_APathManager_NoRegister()
	{
		return APathManager::StaticClass();
	}
	struct Z_Construct_UClass_APathManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PathDisplayActors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathDisplayActors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PathDisplayActors;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathDisplayBlueprint_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_PathDisplayBlueprint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SearchType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SearchType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LevelGenerator_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LevelGenerator;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Ship_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Ship;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APathManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_A1_Search,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/*\n * The Path Manager class is able to load and create paths for objects to follow\n */" },
		{ "IncludePath", "PathManager.h" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "* The Path Manager class is able to load and create paths for objects to follow" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayActors_Inner = { "PathDisplayActors", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayActors_MetaData[] = {
		{ "Category", "PathManager" },
		{ "Comment", "// The array of actors to be displayed on a path\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "The array of actors to be displayed on a path" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayActors = { "PathDisplayActors", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, PathDisplayActors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayActors_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayBlueprint_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "// The Path Display actor to spawn\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "The Path Display actor to spawn" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayBlueprint = { "PathDisplayBlueprint", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, PathDisplayBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayBlueprint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayBlueprint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_SearchType_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "// The search type to use\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "The search type to use" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_SearchType = { "SearchType", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, SearchType), Z_Construct_UEnum_A1_Search_ESearchType, METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_SearchType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_SearchType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_LevelGenerator_MetaData[] = {
		{ "Comment", "// A reference to the ship\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "A reference to the ship" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_LevelGenerator = { "LevelGenerator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, LevelGenerator), Z_Construct_UClass_ALevelGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_LevelGenerator_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_LevelGenerator_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_Ship_MetaData[] = {
		{ "Comment", "// A reference to the ship\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "A reference to the ship" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, Ship), Z_Construct_UClass_AShip_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_Ship_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_Ship_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APathManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayActors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_PathDisplayBlueprint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_SearchType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_LevelGenerator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_Ship,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APathManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APathManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APathManager_Statics::ClassParams = {
		&APathManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APathManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APathManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APathManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APathManager, 70316074);
	template<> A1_SEARCH_API UClass* StaticClass<APathManager>()
	{
		return APathManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APathManager(Z_Construct_UClass_APathManager, &APathManager::StaticClass, TEXT("/Script/A1_Search"), TEXT("APathManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APathManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
