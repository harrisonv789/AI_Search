// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1_Search/Public/Ship.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShip() {}
// Cross Module References
	A1_SEARCH_API UClass* Z_Construct_UClass_AShip_NoRegister();
	A1_SEARCH_API UClass* Z_Construct_UClass_AShip();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_A1_Search();
	A1_SEARCH_API UClass* Z_Construct_UClass_APathManager_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AShip::execGetMoveSpeed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMoveSpeed();
		P_NATIVE_END;
	}
	void AShip::StaticRegisterNativesAShip()
	{
		UClass* Class = AShip::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMoveSpeed", &AShip::execGetMoveSpeed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AShip_GetMoveSpeed_Statics
	{
		struct Ship_eventGetMoveSpeed_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ship_eventGetMoveSpeed_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * @brief Returns the current move speed\n\x09 * @return The move speed in units per second\n\x09 */" },
		{ "ModuleRelativePath", "Public/Ship.h" },
		{ "ToolTip", "@brief Returns the current move speed\n@return The move speed in units per second" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShip, nullptr, "GetMoveSpeed", nullptr, nullptr, sizeof(Ship_eventGetMoveSpeed_Parms), Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AShip_GetMoveSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AShip_GetMoveSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AShip_NoRegister()
	{
		return AShip::StaticClass();
	}
	struct Z_Construct_UClass_AShip_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tolerance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Tolerance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathManager_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PathManager;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Morale_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Morale;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShip_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_A1_Search,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AShip_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AShip_GetMoveSpeed, "GetMoveSpeed" }, // 1184490506
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShip_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/*\n * Class for the ship agent to travel the sea\n */" },
		{ "IncludePath", "Ship.h" },
		{ "ModuleRelativePath", "Public/Ship.h" },
		{ "ToolTip", "* Class for the ship agent to travel the sea" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShip_Statics::NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "Stats" },
		{ "Comment", "// Stores the speed that the ship can move at\n" },
		{ "ModuleRelativePath", "Public/Ship.h" },
		{ "ToolTip", "Stores the speed that the ship can move at" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShip_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShip, MoveSpeed), METADATA_PARAMS(Z_Construct_UClass_AShip_Statics::NewProp_MoveSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShip_Statics::NewProp_MoveSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShip_Statics::NewProp_Tolerance_MetaData[] = {
		{ "Category", "Stats" },
		{ "Comment", "// The distance between a point on the path and the current position before reaching the end\n" },
		{ "ModuleRelativePath", "Public/Ship.h" },
		{ "ToolTip", "The distance between a point on the path and the current position before reaching the end" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShip_Statics::NewProp_Tolerance = { "Tolerance", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShip, Tolerance), METADATA_PARAMS(Z_Construct_UClass_AShip_Statics::NewProp_Tolerance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShip_Statics::NewProp_Tolerance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShip_Statics::NewProp_PathManager_MetaData[] = {
		{ "Comment", "// A reference to the current level\n" },
		{ "ModuleRelativePath", "Public/Ship.h" },
		{ "ToolTip", "A reference to the current level" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShip_Statics::NewProp_PathManager = { "PathManager", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShip, PathManager), Z_Construct_UClass_APathManager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShip_Statics::NewProp_PathManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShip_Statics::NewProp_PathManager_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShip_Statics::NewProp_Morale_MetaData[] = {
		{ "Category", "Ship" },
		{ "Comment", "// The current morale of the ship\n" },
		{ "ModuleRelativePath", "Public/Ship.h" },
		{ "ToolTip", "The current morale of the ship" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AShip_Statics::NewProp_Morale = { "Morale", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShip, Morale), METADATA_PARAMS(Z_Construct_UClass_AShip_Statics::NewProp_Morale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShip_Statics::NewProp_Morale_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShip_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShip_Statics::NewProp_MoveSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShip_Statics::NewProp_Tolerance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShip_Statics::NewProp_PathManager,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShip_Statics::NewProp_Morale,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShip_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShip>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShip_Statics::ClassParams = {
		&AShip::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AShip_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AShip_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AShip_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AShip_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShip()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShip_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShip, 3494429499);
	template<> A1_SEARCH_API UClass* StaticClass<AShip>()
	{
		return AShip::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShip(Z_Construct_UClass_AShip, &AShip::StaticClass, TEXT("/Script/A1_Search"), TEXT("AShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
