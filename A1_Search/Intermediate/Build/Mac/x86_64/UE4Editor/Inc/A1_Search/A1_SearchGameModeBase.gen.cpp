// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1_Search/Public/A1_SearchGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeA1_SearchGameModeBase() {}
// Cross Module References
	A1_SEARCH_API UClass* Z_Construct_UClass_AA1_SearchGameModeBase_NoRegister();
	A1_SEARCH_API UClass* Z_Construct_UClass_AA1_SearchGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_A1_Search();
// End Cross Module References
	DEFINE_FUNCTION(AA1_SearchGameModeBase::execGetMapArray)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetMapArray();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AA1_SearchGameModeBase::execGetRandomMapText)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetRandomMapText();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AA1_SearchGameModeBase::execGetMapFileList)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetMapFileList();
		P_NATIVE_END;
	}
	void AA1_SearchGameModeBase::StaticRegisterNativesAA1_SearchGameModeBase()
	{
		UClass* Class = AA1_SearchGameModeBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMapArray", &AA1_SearchGameModeBase::execGetMapArray },
			{ "GetMapFileList", &AA1_SearchGameModeBase::execGetMapFileList },
			{ "GetRandomMapText", &AA1_SearchGameModeBase::execGetRandomMapText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics
	{
		struct A1_SearchGameModeBase_eventGetMapArray_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(A1_SearchGameModeBase_eventGetMapArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Utility Functions" },
		{ "Comment", "/**\n\x09 * @brief Gets a random map file and parses into an array\n\x09 * @return A list of array lines\n\x09 */" },
		{ "ModuleRelativePath", "Public/A1_SearchGameModeBase.h" },
		{ "ToolTip", "@brief Gets a random map file and parses into an array\n@return A list of array lines" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AA1_SearchGameModeBase, nullptr, "GetMapArray", nullptr, nullptr, sizeof(A1_SearchGameModeBase_eventGetMapArray_Parms), Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics
	{
		struct A1_SearchGameModeBase_eventGetMapFileList_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(A1_SearchGameModeBase_eventGetMapFileList_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Utility Functions" },
		{ "Comment", "/**\n\x09 * @brief Returns a list of all map files found in the source folder\n\x09 * @return An array of file paths\n\x09 */" },
		{ "ModuleRelativePath", "Public/A1_SearchGameModeBase.h" },
		{ "ToolTip", "@brief Returns a list of all map files found in the source folder\n@return An array of file paths" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AA1_SearchGameModeBase, nullptr, "GetMapFileList", nullptr, nullptr, sizeof(A1_SearchGameModeBase_eventGetMapFileList_Parms), Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics
	{
		struct A1_SearchGameModeBase_eventGetRandomMapText_Parms
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
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(A1_SearchGameModeBase_eventGetRandomMapText_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Utility Functions" },
		{ "Comment", "/**\n\x09 * @brief Loads a random map file data from the source folder\n\x09 * @return The map file data\n\x09 */" },
		{ "ModuleRelativePath", "Public/A1_SearchGameModeBase.h" },
		{ "ToolTip", "@brief Loads a random map file data from the source folder\n@return The map file data" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AA1_SearchGameModeBase, nullptr, "GetRandomMapText", nullptr, nullptr, sizeof(A1_SearchGameModeBase_eventGetRandomMapText_Parms), Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AA1_SearchGameModeBase_NoRegister()
	{
		return AA1_SearchGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AA1_SearchGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AA1_SearchGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_A1_Search,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AA1_SearchGameModeBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapArray, "GetMapArray" }, // 2696038404
		{ &Z_Construct_UFunction_AA1_SearchGameModeBase_GetMapFileList, "GetMapFileList" }, // 2887316827
		{ &Z_Construct_UFunction_AA1_SearchGameModeBase_GetRandomMapText, "GetRandomMapText" }, // 436067952
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AA1_SearchGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Main base class for loading arrays\n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "A1_SearchGameModeBase.h" },
		{ "ModuleRelativePath", "Public/A1_SearchGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "Main base class for loading arrays" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AA1_SearchGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AA1_SearchGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AA1_SearchGameModeBase_Statics::ClassParams = {
		&AA1_SearchGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AA1_SearchGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AA1_SearchGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AA1_SearchGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AA1_SearchGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AA1_SearchGameModeBase, 804099378);
	template<> A1_SEARCH_API UClass* StaticClass<AA1_SearchGameModeBase>()
	{
		return AA1_SearchGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AA1_SearchGameModeBase(Z_Construct_UClass_AA1_SearchGameModeBase, &AA1_SearchGameModeBase::StaticClass, TEXT("/Script/A1_Search"), TEXT("AA1_SearchGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AA1_SearchGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
