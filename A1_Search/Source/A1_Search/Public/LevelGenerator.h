// FIT3094 - Assignment 1
// Harrison Verrios

#pragma once

#include "SearchType.h"
#include "Gold.h"
#include "Ship.h"
#include "GridNode.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"

UCLASS()
class A1_SEARCH_API ALevelGenerator : public AActor
{
	GENERATED_BODY()

	/**************************************************************/
	public:

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

    // The start node of the search tree
    GridNode* StartNode;

	// The final goal node of the search
    GridNode* GoalNode;

    // A current reference to the ship that is in the path
	UPROPERTY(BlueprintReadOnly)
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

    // The Path Display actor
    UPROPERTY(EditAnywhere, Category = "Entities")
    TSubclassOf<AActor> PathDisplayBlueprint;

	// The Deep Water Tile Blueprint
	UPROPERTY(EditAnywhere, Category = "Entities")
    TSubclassOf<AActor> DeepBlueprint;

	// The Land Tile Blueprint
	UPROPERTY(EditAnywhere, Category = "Entities")
    TSubclassOf<AActor> LandBlueprint;

	// The Shallow Water Tile Blueprint
	UPROPERTY(EditAnywhere, Category = "Entities")
    TSubclassOf<AActor> ShallowBlueprint;

	// The Gold entity blueprint
	UPROPERTY(EditAnywhere, Category = "Entities")
    TSubclassOf<AActor> GoldBlueprint;

	// The Ship entity blueprint
	UPROPERTY(EditAnywhere, Category = "Entities")
    TSubclassOf<AActor> ShipBlueprint;

    // The camera from the world
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta=(ExposeOnSpawn = true), Category="Entities")
    AActor* Camera;

    // The search type to use
    UPROPERTY(EditAnywhere, Category = "Search")
    TEnumAsByte<ESearchType> SearchType;


	
	/**************************************************************/

	/**
	 * @brief Sets default values for this actor's properties
	 */
	ALevelGenerator();
	
	/**
	 * @brief Called every frame
	 * @param DeltaTime The time-step between each frame
	 */
	virtual void Tick(float DeltaTime) override;

	/**
     * @brief Generates a new world from a file
     * @param WorldArrayString - An array of string data from the file
     */
    UFUNCTION(BlueprintCallable)
    void GenerateWorldFromFile (TArray<FString> WorldArrayString);


	
	/**************************************************************/
	protected:
	
	/**
	 * @brief Called when the game starts or when spawned
	 */
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