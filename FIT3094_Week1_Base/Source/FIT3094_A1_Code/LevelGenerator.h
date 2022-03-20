// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gold.h"
#include "Ship.h"
#include "GridNode.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"

UENUM(Blueprintable)
enum ESearchType
{
	DFS,
	BFS,
	DIJKSTRA,
	ASTAR
};

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

	// The current search count of the tree
	int SearchCount;

	// Whether the current path is calculated
	bool IsPathCalculated;

	// The start and end nodes of the search tree
	GridNode* StartNode;
	GridNode* GoalNode;

	// A current reference to the ship that is in the path
	AShip* Ship;

	// The array of gold positions
	UPROPERTY(BlueprintReadOnly)
	TArray<FVector2D> GoldArray;

	// The array of actors to be displayed on a path
	UPROPERTY(BlueprintReadOnly)
	TArray<AActor*> PathDisplayActors;

	// Store an array of grids
	GridNode* WorldArray[MAX_MAP_SIZE][MAX_MAP_SIZE];

	// A list of gold actors
	UPROPERTY(BlueprintReadOnly)
	TArray<AGold*> GoldActors;

	// Actors to spawn in the world
	UPROPERTY(EditAnywhere, Category = "Entities")
	TSubclassOf<AActor> PathDisplayBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
	TSubclassOf<AActor> DeepBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
	TSubclassOf<AActor> LandBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
	TSubclassOf<AActor> ShallowBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
	TSubclassOf<AActor> GoldBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
	TSubclassOf<AActor> ShipBlueprint;

	// The camera from the world
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta=(ExposeOnSpawn = true), Category="Entities")
	AActor* Camera;

	// The search type to use
	UPROPERTY(EditAnywhere, Category = "Search")
	TEnumAsByte<ESearchType> SearchType;

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

	/**
	 * @brief Estimates the cost between two nodes
	 * @param first - The first grid node
	 * @param second - The second grid node
	 * @return The distance between two nodes
	 */
	float EstimateCost (GridNode* first, GridNode* second);

	
public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Generates a new world from a file
	 * @param WorldArrayString - An array of string data from the file
	 */
	UFUNCTION(BlueprintCallable)
	void GenerateWorldFromFile (TArray<FString> WorldArrayString);

	/**
	 * @brief Calculates the Depth First Expansion Strategy
	 */
	void CalculateDFS();

	/**
	 * @brief Calculates the Breadth First Search Strategy
	 */
	void CalculateBFS();

	/*
	 * @brief Calculates the Uniform Cost Search (Dijkstra) strategy
	*/
	void CalculateDijkstra();

	/**
	 * @brief Calculates the A* search strategy
	 * @param weight - The Weight of the algorithm
	 */
	void CalculateAStar(float weight = 1.0);

	/**
	 * @brief Renders the current path of the search algorithm
	 */
	void RenderPath();

	/**
	 * @brief Displays information to the screen of the current path chosen
	 */
	void DetailPath();

	/**
	 * @brief Resets the current path of the search algorithm
	 */
	void ResetPath();

	/**
	 * @brief Allows the ship to collect the gold at the end of the algorithm
	 */
	void CollectGold();
};
