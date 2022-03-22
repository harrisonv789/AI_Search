// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1_Search/Public/SearchType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSearchType() {}
// Cross Module References
	A1_SEARCH_API UEnum* Z_Construct_UEnum_A1_Search_ESearchType();
	UPackage* Z_Construct_UPackage__Script_A1_Search();
// End Cross Module References
	static UEnum* ESearchType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_A1_Search_ESearchType, Z_Construct_UPackage__Script_A1_Search(), TEXT("ESearchType"));
		}
		return Singleton;
	}
	template<> A1_SEARCH_API UEnum* StaticEnum<ESearchType>()
	{
		return ESearchType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESearchType(ESearchType_StaticEnum, TEXT("/Script/A1_Search"), TEXT("ESearchType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_A1_Search_ESearchType_Hash() { return 1096762986U; }
	UEnum* Z_Construct_UEnum_A1_Search_ESearchType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_A1_Search();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESearchType"), 0, Get_Z_Construct_UEnum_A1_Search_ESearchType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "DFS", (int64)DFS },
				{ "BFS", (int64)BFS },
				{ "DIJKSTRA", (int64)DIJKSTRA },
				{ "A_STAR", (int64)A_STAR },
				{ "W_A_STAR", (int64)W_A_STAR },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "A_STAR.Comment", "// Uniform Cost Search\n" },
				{ "A_STAR.Name", "A_STAR" },
				{ "A_STAR.ToolTip", "Uniform Cost Search" },
				{ "BFS.Comment", "// Depth First Search\n" },
				{ "BFS.Name", "BFS" },
				{ "BFS.ToolTip", "Depth First Search" },
				{ "BlueprintType", "true" },
				{ "DFS.Name", "DFS" },
				{ "DIJKSTRA.Comment", "// Breadth First Search\n" },
				{ "DIJKSTRA.Name", "DIJKSTRA" },
				{ "DIJKSTRA.ToolTip", "Breadth First Search" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/SearchType.h" },
				{ "W_A_STAR.Comment", "// A* Algorithm\n" },
				{ "W_A_STAR.Name", "W_A_STAR" },
				{ "W_A_STAR.ToolTip", "A* Algorithm" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_A1_Search,
				nullptr,
				"ESearchType",
				"ESearchType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Regular,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
