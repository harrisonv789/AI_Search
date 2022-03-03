// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FIT3094_A1_Code/FIT3094_A1_CodeGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFIT3094_A1_CodeGameModeBase() {}
// Cross Module References
	FIT3094_A1_CODE_API UClass* Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_NoRegister();
	FIT3094_A1_CODE_API UClass* Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_FIT3094_A1_Code();
// End Cross Module References
	DEFINE_FUNCTION(AFIT3094_A1_CodeGameModeBase::execGetMapArray)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetMapArray();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFIT3094_A1_CodeGameModeBase::execGetRandomMapText)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetRandomMapText();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFIT3094_A1_CodeGameModeBase::execGetMapFileList)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetMapFileList();
		P_NATIVE_END;
	}
	void AFIT3094_A1_CodeGameModeBase::StaticRegisterNativesAFIT3094_A1_CodeGameModeBase()
	{
		UClass* Class = AFIT3094_A1_CodeGameModeBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMapArray", &AFIT3094_A1_CodeGameModeBase::execGetMapArray },
			{ "GetMapFileList", &AFIT3094_A1_CodeGameModeBase::execGetMapFileList },
			{ "GetRandomMapText", &AFIT3094_A1_CodeGameModeBase::execGetRandomMapText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics
	{
		struct FIT3094_A1_CodeGameModeBase_eventGetMapArray_Parms
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
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FIT3094_A1_CodeGameModeBase_eventGetMapArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Utility Functions" },
		{ "ModuleRelativePath", "FIT3094_A1_CodeGameModeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase, nullptr, "GetMapArray", nullptr, nullptr, sizeof(FIT3094_A1_CodeGameModeBase_eventGetMapArray_Parms), Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics
	{
		struct FIT3094_A1_CodeGameModeBase_eventGetMapFileList_Parms
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
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FIT3094_A1_CodeGameModeBase_eventGetMapFileList_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Utility Functions" },
		{ "ModuleRelativePath", "FIT3094_A1_CodeGameModeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase, nullptr, "GetMapFileList", nullptr, nullptr, sizeof(FIT3094_A1_CodeGameModeBase_eventGetMapFileList_Parms), Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics
	{
		struct FIT3094_A1_CodeGameModeBase_eventGetRandomMapText_Parms
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
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FIT3094_A1_CodeGameModeBase_eventGetRandomMapText_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Utility Functions" },
		{ "ModuleRelativePath", "FIT3094_A1_CodeGameModeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase, nullptr, "GetRandomMapText", nullptr, nullptr, sizeof(FIT3094_A1_CodeGameModeBase_eventGetRandomMapText_Parms), Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_NoRegister()
	{
		return AFIT3094_A1_CodeGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FIT3094_A1_Code,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapArray, "GetMapArray" }, // 2457325892
		{ &Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetMapFileList, "GetMapFileList" }, // 1208714043
		{ &Z_Construct_UFunction_AFIT3094_A1_CodeGameModeBase_GetRandomMapText, "GetRandomMapText" }, // 2408922865
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FIT3094_A1_CodeGameModeBase.h" },
		{ "ModuleRelativePath", "FIT3094_A1_CodeGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFIT3094_A1_CodeGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics::ClassParams = {
		&AFIT3094_A1_CodeGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFIT3094_A1_CodeGameModeBase, 1284540017);
	template<> FIT3094_A1_CODE_API UClass* StaticClass<AFIT3094_A1_CodeGameModeBase>()
	{
		return AFIT3094_A1_CodeGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFIT3094_A1_CodeGameModeBase(Z_Construct_UClass_AFIT3094_A1_CodeGameModeBase, &AFIT3094_A1_CodeGameModeBase::StaticClass, TEXT("/Script/FIT3094_A1_Code"), TEXT("AFIT3094_A1_CodeGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFIT3094_A1_CodeGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
