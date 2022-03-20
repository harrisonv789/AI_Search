// FIT3094 - Assignment 1
// Harrison Verrios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gold.generated.h"

/*
 * Stores a class for adding in gold to the screen
 */
UCLASS(Blueprintable, BlueprintType)
class A1_SEARCH_API AGold : public AActor
{
	GENERATED_BODY()

	/**************************************************************/
	public:
	
	/**
	 * @brief Default constructor that sets up the gold
	 */
	AGold();

	
	/**************************************************************/
	protected:
	
	/**
	 * @brief Called when the game starts or when the object is spawned
	 */
	virtual void BeginPlay() override;


	/**************************************************************/
	public:
	
	/**
	 * @brief Called every frame
	 * @param DeltaTime The time difference between each frame
	 */
	virtual void Tick(float DeltaTime) override;
};
