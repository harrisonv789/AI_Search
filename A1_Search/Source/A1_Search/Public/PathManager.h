// FIT3094 - Assignment 1
// Harrison Verrios

#pragma once

#include "CoreMinimal.h"
#include "GridNode.h"
#include "SearchType.h"
#include "GameFramework/Actor.h"
#include "PathManager.generated.h"

class AShip;
class ALevelGenerator;

/*
 * The Path Manager class is able to load and create paths for objects to follow
 */
UCLASS()
class A1_SEARCH_API APathManager : public AActor
{
	GENERATED_BODY()

	/**************************************************************/
	public:

	// The current search count of the tree
	UPROPERTY(BlueprintReadOnly)
	int SearchCount;

	// The length of the current path
	UPROPERTY(BlueprintReadOnly)
	int PathLength;

	// The total cost of the search
	UPROPERTY(BlueprintReadOnly)
	int PathCost;

	// The distance to the goal
	UPROPERTY(BlueprintReadOnly)
	float GoalDistance;

	// The time taken to calculate the path
	UPROPERTY(BlueprintReadOnly)
	float PathCalculationTime;

	// Whether the current path is calculated
	UPROPERTY(BlueprintReadOnly)
	bool IsPathCalculated;

	// The start node of the search tree
	GridNode* StartNode;

	// The final goal node of the search
	GridNode* GoalNode;

	// The array of actors to be displayed on a path
	UPROPERTY(BlueprintReadOnly)
	TArray<AActor*> PathDisplayActors;

	// The Path Display actor to spawn
	UPROPERTY(EditAnywhere, Category = "Search")
	TSubclassOf<AActor> PathDisplayBlueprint;

	// The search type to use
	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<ESearchType> SearchType;

	// The weighted A star factor, only for use in W_A_STAR
	UPROPERTY(BlueprintReadWrite)
	float WeightedAStar = 1.0;

	// A reference to the ship
	UPROPERTY()
	ALevelGenerator* LevelGenerator;
	
	// A reference to the ship
	UPROPERTY()
	AShip* Ship;


	
	/**************************************************************/
	private:

	// The starting time of the path calculation
	FDateTime StartingTime;

	// Whether a path has been found
	bool ValidPath;


	
	/**************************************************************/
	public:

	/**
	 * @brief Sets default values for this actor's properties
	 */
	APathManager();
	
	/**
	 * @brief Called every frame
	 * @param DeltaTime The time-step between each frame
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Creates a new path and details it
	 */
	void CreatePath();

	/**
	 * @brief Calculates the path factor dividing distance by cost
	 * @return The path factor
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetPathFactor () const;

	/**
	 * @brief Gets the name of the current search algorithm
	 * @return The name of the algorithm
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetSearchTypeName () const;

	/**
	 * @brief Resets the current path of the search algorithm
	 */
	void ResetPath();

	/**
	 * @brief Sets the default search algorithms when restarted
	 * @param type The new default type
	 * @param weight The new weighting
	 */
	UFUNCTION(BlueprintCallable)
	static void SetDefaultSearch (ESearchType type, float weight);
	
	

	/**************************************************************/
	protected:
	
	/**
	 * @brief Called when the game starts or when spawned
	 */
	virtual void BeginPlay() override;

	/**
	 * @brief Calculates the distance between two defined nodes
	 * @param first - The first grid node
	 * @param second - The second grid node
	 * @return The distance between two nodes
	 */
	static float CalculateDistanceBetweenNodes (const GridNode* first, const GridNode* second);

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

	/*
	 * @brief Calculates the Weighted A* search strategy
	*/
	void CalculateWeightedAStar();

	/**
	 * @brief Renders the current path of the search algorithm
	 */
	void RenderPath();

	/**
	 * @brief Displays information to the screen of the current path chosen
	 */
	void DetailPath() const;
	
};
