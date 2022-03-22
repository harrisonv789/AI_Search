// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef A1_SEARCH_PathManager_generated_h
#error "PathManager.generated.h already included, missing '#pragma once' in PathManager.h"
#endif
#define A1_SEARCH_PathManager_generated_h

#define A1_Search_Source_A1_Search_Public_PathManager_h_21_SPARSE_DATA
#define A1_Search_Source_A1_Search_Public_PathManager_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetDefaultSearch); \
	DECLARE_FUNCTION(execGetSearchTypeName); \
	DECLARE_FUNCTION(execGetPathFactor);


#define A1_Search_Source_A1_Search_Public_PathManager_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetDefaultSearch); \
	DECLARE_FUNCTION(execGetSearchTypeName); \
	DECLARE_FUNCTION(execGetPathFactor);


#define A1_Search_Source_A1_Search_Public_PathManager_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPathManager(); \
	friend struct Z_Construct_UClass_APathManager_Statics; \
public: \
	DECLARE_CLASS(APathManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/A1_Search"), NO_API) \
	DECLARE_SERIALIZER(APathManager)


#define A1_Search_Source_A1_Search_Public_PathManager_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAPathManager(); \
	friend struct Z_Construct_UClass_APathManager_Statics; \
public: \
	DECLARE_CLASS(APathManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/A1_Search"), NO_API) \
	DECLARE_SERIALIZER(APathManager)


#define A1_Search_Source_A1_Search_Public_PathManager_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APathManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APathManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APathManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APathManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APathManager(APathManager&&); \
	NO_API APathManager(const APathManager&); \
public:


#define A1_Search_Source_A1_Search_Public_PathManager_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APathManager(APathManager&&); \
	NO_API APathManager(const APathManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APathManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APathManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APathManager)


#define A1_Search_Source_A1_Search_Public_PathManager_h_21_PRIVATE_PROPERTY_OFFSET
#define A1_Search_Source_A1_Search_Public_PathManager_h_18_PROLOG
#define A1_Search_Source_A1_Search_Public_PathManager_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_PRIVATE_PROPERTY_OFFSET \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_SPARSE_DATA \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_RPC_WRAPPERS \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_INCLASS \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define A1_Search_Source_A1_Search_Public_PathManager_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_PRIVATE_PROPERTY_OFFSET \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_SPARSE_DATA \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_INCLASS_NO_PURE_DECLS \
	A1_Search_Source_A1_Search_Public_PathManager_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> A1_SEARCH_API UClass* StaticClass<class APathManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID A1_Search_Source_A1_Search_Public_PathManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
