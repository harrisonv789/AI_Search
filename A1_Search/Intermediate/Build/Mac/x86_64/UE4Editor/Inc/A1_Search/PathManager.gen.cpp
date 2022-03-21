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
	DEFINE_FUNCTION(APathManager::execGetSearchTypeName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetSearchTypeName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APathManager::execGetPathFactor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPathFactor();
		P_NATIVE_END;
	}
	void APathManager::StaticRegisterNativesAPathManager()
	{
		UClass* Class = APathManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetPathFactor", &APathManager::execGetPathFactor },
			{ "GetSearchTypeName", &APathManager::execGetSearchTypeName },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APathManager_GetPathFactor_Statics
	{
		struct PathManager_eventGetPathFactor_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_APathManager_GetPathFactor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PathManager_eventGetPathFactor_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APathManager_GetPathFactor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathManager_GetPathFactor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APathManager_GetPathFactor_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * @brief Calculates the path factor dividing distance by cost\n\x09 * @return The path factor\n\x09 */" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "@brief Calculates the path factor dividing distance by cost\n@return The path factor" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APathManager_GetPathFactor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APathManager, nullptr, "GetPathFactor", nullptr, nullptr, sizeof(PathManager_eventGetPathFactor_Parms), Z_Construct_UFunction_APathManager_GetPathFactor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APathManager_GetPathFactor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APathManager_GetPathFactor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APathManager_GetPathFactor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APathManager_GetPathFactor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APathManager_GetPathFactor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics
	{
		struct PathManager_eventGetSearchTypeName_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PathManager_eventGetSearchTypeName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * @brief Gets the name of the current search algorithm\n\x09 * @return The name of the algorithm\n\x09 */" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "@brief Gets the name of the current search algorithm\n@return The name of the algorithm" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APathManager, nullptr, "GetSearchTypeName", nullptr, nullptr, sizeof(PathManager_eventGetSearchTypeName_Parms), Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APathManager_GetSearchTypeName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APathManager_GetSearchTypeName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APathManager_NoRegister()
	{
		return APathManager::StaticClass();
	}
	struct Z_Construct_UClass_APathManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SearchCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_SearchCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathLength_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_PathLength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathCost_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_PathCost;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GoalDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GoalDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathCalculationTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PathCalculationTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsPathCalculated_MetaData[];
#endif
		static void NewProp_IsPathCalculated_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsPathCalculated;
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
	const FClassFunctionLinkInfo Z_Construct_UClass_APathManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APathManager_GetPathFactor, "GetPathFactor" }, // 3259502185
		{ &Z_Construct_UFunction_APathManager_GetSearchTypeName, "GetSearchTypeName" }, // 2274118120
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/*\n * The Path Manager class is able to load and create paths for objects to follow\n */" },
		{ "IncludePath", "PathManager.h" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "* The Path Manager class is able to load and create paths for objects to follow" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_SearchCount_MetaData[] = {
		{ "Category", "PathManager" },
		{ "Comment", "// The current search count of the tree\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "The current search count of the tree" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_SearchCount = { "SearchCount", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, SearchCount), METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_SearchCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_SearchCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_PathLength_MetaData[] = {
		{ "Category", "PathManager" },
		{ "Comment", "// The length of the current path\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "The length of the current path" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_PathLength = { "PathLength", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, PathLength), METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_PathLength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_PathLength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_PathCost_MetaData[] = {
		{ "Category", "PathManager" },
		{ "Comment", "// The total cost of the search\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "The total cost of the search" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_PathCost = { "PathCost", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, PathCost), METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_PathCost_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_PathCost_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_GoalDistance_MetaData[] = {
		{ "Category", "PathManager" },
		{ "Comment", "// The distance to the goal\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "The distance to the goal" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_GoalDistance = { "GoalDistance", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, GoalDistance), METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_GoalDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_GoalDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_PathCalculationTime_MetaData[] = {
		{ "Category", "PathManager" },
		{ "Comment", "// The time taken to calculate the path\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "The time taken to calculate the path" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_PathCalculationTime = { "PathCalculationTime", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APathManager, PathCalculationTime), METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_PathCalculationTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_PathCalculationTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathManager_Statics::NewProp_IsPathCalculated_MetaData[] = {
		{ "Category", "PathManager" },
		{ "Comment", "// Whether the current path is calculated\n" },
		{ "ModuleRelativePath", "Public/PathManager.h" },
		{ "ToolTip", "Whether the current path is calculated" },
	};
#endif
	void Z_Construct_UClass_APathManager_Statics::NewProp_IsPathCalculated_SetBit(void* Obj)
	{
		((APathManager*)Obj)->IsPathCalculated = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APathManager_Statics::NewProp_IsPathCalculated = { "IsPathCalculated", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(APathManager), &Z_Construct_UClass_APathManager_Statics::NewProp_IsPathCalculated_SetBit, METADATA_PARAMS(Z_Construct_UClass_APathManager_Statics::NewProp_IsPathCalculated_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APathManager_Statics::NewProp_IsPathCalculated_MetaData)) };
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
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_SearchCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_PathLength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_PathCost,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_GoalDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_PathCalculationTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathManager_Statics::NewProp_IsPathCalculated,
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
		FuncInfo,
		Z_Construct_UClass_APathManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(APathManager, 2878160380);
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
