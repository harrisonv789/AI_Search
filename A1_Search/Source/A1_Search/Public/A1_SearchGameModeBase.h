// FIT3094 - Assignment 1
// Harrison Verrios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "A1_SearchGameModeBase.generated.h"

/**
 * Main base class for loading arrays
 */
UCLASS()
class A1_SEARCH_API AA1_SearchGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	/**************************************************************/
	public:

	/**
	 * @brief Returns a list of all map files found in the source folder
	 * @return An array of file paths
	 */
    UFUNCTION(BlueprintCallable, Category = "Utility Functions")
	TArray<FString> GetMapFileList();

	/**
	 * @brief Loads a random map file data from the source folder
	 * @return The map file data
	 */
    UFUNCTION(BlueprintCallable, Category = "Utility Functions")
	FString GetRandomMapText();
	
	/**
	 * @brief Gets a random map file and parses into an array
	 * @return A list of array lines
	 */
	UFUNCTION(BlueprintCallable, Category = "Utility Functions")
	TArray<FString> GetMapArray();
	
};
