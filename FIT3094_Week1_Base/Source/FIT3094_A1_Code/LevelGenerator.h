// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gold.h"
#include "GridNode.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"

UCLASS()
class FIT3094_A1_CODE_API ALevelGenerator : public AActor
{
	GENERATED_BODY()

public:
	
	// Sets default values for this actor's properties
	ALevelGenerator();

	// The size of the grid
	static const int GRID_SIZE_WORLD = 100;

	// Maximum size of the map
	static const int MAX_MAP_SIZE = 255;

	// The size of the map on the X-axis
	UPROPERTY(BlueprintReadOnly)
	int MapSizeX;

	// The size of the map on the Y-axis
	UPROPERTY(BlueprintReadOnly)
	int MapSizeY;

	// The array of gold positions
	UPROPERTY(BlueprintReadOnly)
	TArray<FVector2D> GoldArray;

	// Store an array of grids
	GridNode* WorldArray[MAX_MAP_SIZE][MAX_MAP_SIZE];

	// A list of gold actors
	UPROPERTY()
	TArray<AGold*> GoldActors;

	// Actors to spawn in the world
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta=(ExposeOnSpawn = true), Category="Entities")
	TSubclassOf<AActor> DeepBlueprint;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta=(ExposeOnSpawn = true), Category="Entities")
	TSubclassOf<AActor> LandBlueprint;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta=(ExposeOnSpawn = true), Category="Entities")
	TSubclassOf<AActor> ShallowBlueprint;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta=(ExposeOnSpawn = true), Category="Entities")
	TSubclassOf<AActor> GoldBlueprint;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta=(ExposeOnSpawn = true), Category="Entities")
	TSubclassOf<AActor> ShipBlueprint;

	// The camera from the world
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta=(ExposeOnSpawn = true), Category="Entities")
	AActor* Camera; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
	 * @brief Spawns all actors in the world based on the grid
	 * @param Grid - The current 2D Grid
	 */
	void SpawnWorldActors (char Grid[MAX_MAP_SIZE][MAX_MAP_SIZE]);

	/**
	 * @brief Generates all of the nodes in the map grid
	 * @param Grid - The current 2D Grid
	 */
	void GenerateNodeGrid (char Grid[MAX_MAP_SIZE][MAX_MAP_SIZE]);

	/**
	 * @brief Resets all of the nodes on the grid
	 */
	void ResetAllNodes();

	/**
	 * @brief Calculates the distance between two defined nodes
	 * @param first - The first grid node
	 * @param second - The second grid node
	 * @return The distance between two nodes
	 */
	float CalculateDistanceBetweenNodes (GridNode* first, GridNode* second);

	/**
	 * @brief Spawns the next gold entity in the grid
	 */
	void SpawnNextGold ();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Generates a new world from a file
	 * @param WorldArrayString - An array of string data from the file
	 */
	UFUNCTION(BlueprintCallable)
	void GenerateWorldFromFile (TArray<FString> WorldArrayString);

};
