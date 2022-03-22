// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1_Search/Public/LevelGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLevelGenerator() {}
// Cross Module References
	A1_SEARCH_API UClass* Z_Construct_UClass_ALevelGenerator_NoRegister();
	A1_SEARCH_API UClass* Z_Construct_UClass_ALevelGenerator();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_A1_Search();
	A1_SEARCH_API UClass* Z_Construct_UClass_AShip_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	A1_SEARCH_API UClass* Z_Construct_UClass_AGold_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	A1_SEARCH_API UClass* Z_Construct_UClass_APathManager_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ALevelGenerator::execSetShallowWater)
	{
		P_GET_UBOOL(Z_Param_flag);
		P_FINISH;
		P_NATIVE_BEGIN;
		ALevelGenerator::SetShallowWater(Z_Param_flag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALevelGenerator::execGetShallowWater)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=ALevelGenerator::GetShallowWater();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALevelGenerator::execGenerateWorldFromFile)
	{
		P_GET_TARRAY(FString,Z_Param_WorldArrayString);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GenerateWorldFromFile(Z_Param_WorldArrayString);
		P_NATIVE_END;
	}
	void ALevelGenerator::StaticRegisterNativesALevelGenerator()
	{
		UClass* Class = ALevelGenerator::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateWorldFromFile", &ALevelGenerator::execGenerateWorldFromFile },
			{ "GetShallowWater", &ALevelGenerator::execGetShallowWater },
			{ "SetShallowWater", &ALevelGenerator::execSetShallowWater },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics
	{
		struct LevelGenerator_eventGenerateWorldFromFile_Parms
		{
			TArray<FString> WorldArrayString;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_WorldArrayString_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_WorldArrayString;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::NewProp_WorldArrayString_Inner = { "WorldArrayString", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::NewProp_WorldArrayString = { "WorldArrayString", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LevelGenerator_eventGenerateWorldFromFile_Parms, WorldArrayString), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::NewProp_WorldArrayString_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::NewProp_WorldArrayString,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n     * @brief Generates a new world from a file\n     * @param WorldArrayString - An array of string data from the file\n     */" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "@brief Generates a new world from a file\n@param WorldArrayString - An array of string data from the file" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALevelGenerator, nullptr, "GenerateWorldFromFile", nullptr, nullptr, sizeof(LevelGenerator_eventGenerateWorldFromFile_Parms), Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics
	{
		struct LevelGenerator_eventGetShallowWater_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LevelGenerator_eventGetShallowWater_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(LevelGenerator_eventGetShallowWater_Parms), &Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * @brief Determines if using shallow water\n\x09 * @return A flag for shallow water using\n\x09 */" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "@brief Determines if using shallow water\n@return A flag for shallow water using" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALevelGenerator, nullptr, "GetShallowWater", nullptr, nullptr, sizeof(LevelGenerator_eventGetShallowWater_Parms), Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALevelGenerator_GetShallowWater()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ALevelGenerator_GetShallowWater_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics
	{
		struct LevelGenerator_eventSetShallowWater_Parms
		{
			bool flag;
		};
		static void NewProp_flag_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_flag;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::NewProp_flag_SetBit(void* Obj)
	{
		((LevelGenerator_eventSetShallowWater_Parms*)Obj)->flag = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::NewProp_flag = { "flag", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(LevelGenerator_eventSetShallowWater_Parms), &Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::NewProp_flag_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::NewProp_flag,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * @brief Sets a new flag for using shallow water\n\x09 * @param flag A flag for shallow water using\n\x09 */" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "@brief Sets a new flag for using shallow water\n@param flag A flag for shallow water using" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALevelGenerator, nullptr, "SetShallowWater", nullptr, nullptr, sizeof(LevelGenerator_eventSetShallowWater_Parms), Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALevelGenerator_SetShallowWater()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ALevelGenerator_SetShallowWater_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ALevelGenerator_NoRegister()
	{
		return ALevelGenerator::StaticClass();
	}
	struct Z_Construct_UClass_ALevelGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapSizeX_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MapSizeX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapSizeY_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MapSizeY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Ship_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Ship;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GoldArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GoldArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GoldArray;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GoldActors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GoldActors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GoldActors;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeepBlueprint_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DeepBlueprint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LandBlueprint_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_LandBlueprint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShallowBlueprint_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ShallowBlueprint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GoldBlueprint_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_GoldBlueprint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShipBlueprint_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ShipBlueprint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathManager_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PathManager;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALevelGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_A1_Search,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ALevelGenerator_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ALevelGenerator_GenerateWorldFromFile, "GenerateWorldFromFile" }, // 534706362
		{ &Z_Construct_UFunction_ALevelGenerator_GetShallowWater, "GetShallowWater" }, // 2978756178
		{ &Z_Construct_UFunction_ALevelGenerator_SetShallowWater, "SetShallowWater" }, // 4217481873
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/*\n * This class generates the level in the world\n */" },
		{ "IncludePath", "LevelGenerator.h" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "* This class generates the level in the world" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeX_MetaData[] = {
		{ "Category", "LevelGenerator" },
		{ "Comment", "// The size of the map on the X-axis\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The size of the map on the X-axis" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeX = { "MapSizeX", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, MapSizeX), METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeY_MetaData[] = {
		{ "Category", "LevelGenerator" },
		{ "Comment", "// The size of the map on the Y-axis\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The size of the map on the Y-axis" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeY = { "MapSizeY", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, MapSizeY), METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeY_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Ship_MetaData[] = {
		{ "Category", "LevelGenerator" },
		{ "Comment", "// A current reference to the ship that is in the path\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "A current reference to the ship that is in the path" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, Ship), Z_Construct_UClass_AShip_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Ship_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Ship_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldArray_Inner = { "GoldArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldArray_MetaData[] = {
		{ "Category", "LevelGenerator" },
		{ "Comment", "// The array of gold positions\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The array of gold positions" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldArray = { "GoldArray", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, GoldArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldArray_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldActors_Inner = { "GoldActors", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AGold_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldActors_MetaData[] = {
		{ "Category", "LevelGenerator" },
		{ "Comment", "// A list of gold actors\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "A list of gold actors" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldActors = { "GoldActors", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, GoldActors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldActors_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_DeepBlueprint_MetaData[] = {
		{ "Category", "Entities" },
		{ "Comment", "// The Deep Water Tile Blueprint\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The Deep Water Tile Blueprint" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_DeepBlueprint = { "DeepBlueprint", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, DeepBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_DeepBlueprint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_DeepBlueprint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_LandBlueprint_MetaData[] = {
		{ "Category", "Entities" },
		{ "Comment", "// The Land Tile Blueprint\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The Land Tile Blueprint" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_LandBlueprint = { "LandBlueprint", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, LandBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_LandBlueprint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_LandBlueprint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShallowBlueprint_MetaData[] = {
		{ "Category", "Entities" },
		{ "Comment", "// The Shallow Water Tile Blueprint\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The Shallow Water Tile Blueprint" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShallowBlueprint = { "ShallowBlueprint", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, ShallowBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShallowBlueprint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShallowBlueprint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldBlueprint_MetaData[] = {
		{ "Category", "Entities" },
		{ "Comment", "// The Gold entity blueprint\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The Gold entity blueprint" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldBlueprint = { "GoldBlueprint", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, GoldBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldBlueprint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldBlueprint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShipBlueprint_MetaData[] = {
		{ "Category", "Entities" },
		{ "Comment", "// The Ship entity blueprint\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The Ship entity blueprint" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShipBlueprint = { "ShipBlueprint", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, ShipBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShipBlueprint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShipBlueprint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "Entities" },
		{ "Comment", "// The camera from the world\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The camera from the world" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, Camera), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALevelGenerator_Statics::NewProp_PathManager_MetaData[] = {
		{ "Category", "Entities" },
		{ "Comment", "// The path manager\n" },
		{ "ModuleRelativePath", "Public/LevelGenerator.h" },
		{ "ToolTip", "The path manager" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALevelGenerator_Statics::NewProp_PathManager = { "PathManager", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALevelGenerator, PathManager), Z_Construct_UClass_APathManager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_PathManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::NewProp_PathManager_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALevelGenerator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_MapSizeY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Ship,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldActors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_DeepBlueprint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_LandBlueprint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShallowBlueprint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_GoldBlueprint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_ShipBlueprint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_Camera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelGenerator_Statics::NewProp_PathManager,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALevelGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALevelGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALevelGenerator_Statics::ClassParams = {
		&ALevelGenerator::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ALevelGenerator_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ALevelGenerator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALevelGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALevelGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALevelGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALevelGenerator, 114366498);
	template<> A1_SEARCH_API UClass* StaticClass<ALevelGenerator>()
	{
		return ALevelGenerator::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALevelGenerator(Z_Construct_UClass_ALevelGenerator, &ALevelGenerator::StaticClass, TEXT("/Script/A1_Search"), TEXT("ALevelGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALevelGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
