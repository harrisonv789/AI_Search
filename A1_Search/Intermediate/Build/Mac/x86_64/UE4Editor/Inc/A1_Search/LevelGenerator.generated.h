// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef A1_SEARCH_LevelGenerator_generated_h
#error "LevelGenerator.generated.h already included, missing '#pragma once' in LevelGenerator.h"
#endif
#define A1_SEARCH_LevelGenerator_generated_h

#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_SPARSE_DATA
#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetShallowWater); \
	DECLARE_FUNCTION(execGetShallowWater); \
	DECLARE_FUNCTION(execGenerateWorldFromFile);


#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetShallowWater); \
	DECLARE_FUNCTION(execGetShallowWater); \
	DECLARE_FUNCTION(execGenerateWorldFromFile);


#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALevelGenerator(); \
	friend struct Z_Construct_UClass_ALevelGenerator_Statics; \
public: \
	DECLARE_CLASS(ALevelGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/A1_Search"), NO_API) \
	DECLARE_SERIALIZER(ALevelGenerator)


#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_INCLASS \
private: \
	static void StaticRegisterNativesALevelGenerator(); \
	friend struct Z_Construct_UClass_ALevelGenerator_Statics; \
public: \
	DECLARE_CLASS(ALevelGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/A1_Search"), NO_API) \
	DECLARE_SERIALIZER(ALevelGenerator)


#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALevelGenerator(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALevelGenerator) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALevelGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALevelGenerator); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALevelGenerator(ALevelGenerator&&); \
	NO_API ALevelGenerator(const ALevelGenerator&); \
public:


#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALevelGenerator(ALevelGenerator&&); \
	NO_API ALevelGenerator(const ALevelGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALevelGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALevelGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALevelGenerator)


#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_PRIVATE_PROPERTY_OFFSET
#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_17_PROLOG
#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_PRIVATE_PROPERTY_OFFSET \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_SPARSE_DATA \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_RPC_WRAPPERS \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_INCLASS \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_PRIVATE_PROPERTY_OFFSET \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_SPARSE_DATA \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_INCLASS_NO_PURE_DECLS \
	A1_Search_Source_A1_Search_Public_LevelGenerator_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> A1_SEARCH_API UClass* StaticClass<class ALevelGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID A1_Search_Source_A1_Search_Public_LevelGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
