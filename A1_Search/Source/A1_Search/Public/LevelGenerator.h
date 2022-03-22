// FIT3094 - Assignment 1
// Harrison Verrios

#pragma once

#include "Gold.h"
#include "Ship.h"
#include "GridNode.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"


/*
 * This class generates the level in the world
 */
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

    // A current reference to the ship that is in the path
	UPROPERTY(BlueprintReadOnly)
    AShip* Ship;

    // The array of gold positions
    UPROPERTY(BlueprintReadOnly)
    TArray<FVector2D> GoldArray;

    // Store an array of grids
    GridNode* WorldArray[MAX_MAP_SIZE][MAX_MAP_SIZE];

    // A list of gold actors
    UPROPERTY(BlueprintReadOnly)
    TArray<AGold*> GoldActors;
	
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
    UPROPERTY(EditAnywhere, Category="Entities")
    AActor* Camera;

	// The path manager
	UPROPERTY(EditAnywhere, Category="Entities")
	APathManager* PathManager;

	
	
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

	/**
	 * @brief Determines if using shallow water
	 * @return A flag for shallow water using
	 */
	UFUNCTION(BlueprintPure, BlueprintCallable)
	static bool GetShallowWater ();

	/**
	 * @brief Sets a new flag for using shallow water
	 * @param flag A flag for shallow water using
	 */
	UFUNCTION(BlueprintCallable)
	static void SetShallowWater (bool flag);


	
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
     * @brief Spawns the next gold entity in the grid
     */
    void SpawnNextGold ();

    /**
     * @brief Allows the ship to collect the gold at the end of the algorithm
     */
    void CollectGold();

	

};