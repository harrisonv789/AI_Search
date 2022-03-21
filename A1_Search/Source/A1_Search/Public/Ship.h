// FIT3094 - Assignment 1
// Harrison Verrios

#pragma once

#include "CoreMinimal.h"
#include "GridNode.h"
#include "GameFramework/Actor.h"
#include "Ship.generated.h"

// Resolves a circular dependency with forward declaration
class APathManager;

/*
 * Class for the ship agent to travel the sea
 */
UCLASS()
class A1_SEARCH_API AShip : public AActor
{
	GENERATED_BODY()

	/**************************************************************/
	public:

	// Stores the speed that the ship can move at
    UPROPERTY(EditAnywhere, Category = "Stats")
    float MoveSpeed;

    // The distance between a point on the path and the current position before reaching the end
    UPROPERTY(EditAnywhere, Category = "Stats")
    float Tolerance;

    // A list of points on a path to follow
    TArray<GridNode*> Path;

    // A flag for whether a path needs to be generated
    bool GeneratePath = true;

    // A reference to the current level
	UPROPERTY()
    APathManager* PathManager;

	
	/**************************************************************/
	
	/**
	 * @brief Sets default values for this actor's properties
	 */
	AShip();

	/**
	 * @brief Called every frame
	 * @param DeltaTime The time-step between each frame
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Returns the current move speed
	 * @return The move speed in units per second
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMoveSpeed () const;


	
	/**************************************************************/
	protected:
	
	/**
	 * @brief Called when the game starts or when spawned
	 */
	virtual void BeginPlay() override;

};
