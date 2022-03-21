// FIT3094 - Assignment 1
// Harrison Verrios

#include "Ship.h"
#include "PathManager.h"
#include "LevelGenerator.h"


// Sets default values
APathManager::APathManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APathManager::CreatePath()
{
	// Resets the path
	ResetPath();
	
	// Load the search based on the search type
	switch (SearchType)
	{
		case DFS:		CalculateDFS(); break;
		case BFS:		CalculateBFS(); break;
		case DIJKSTRA:	CalculateDijkstra(); break;
		case A_STAR:	CalculateAStar(); break;
		default: break;
	}
		
	DetailPath();
}

// Called when the game starts or when spawned
void APathManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APathManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float APathManager::CalculateDistanceBetweenNodes(const GridNode* first, const GridNode* second)
{
	const FVector distToTarget = FVector(second->X - first->X, second->Y - first->Y, 0);
	return distToTarget.Size();
}

void APathManager::DetailPath() const
{
	// Onscreen Debug (Don't forget the include!)
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, FString::Printf(TEXT("Total Cells searched: %d with a path length of: %d and a distance of: %f"), SearchCount, Ship->Path.Num(), CalculateDistanceBetweenNodes(StartNode, GoalNode)));
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, FString::Printf(TEXT("The difference between the current implemented path and the direct flight path is: %f"), Ship->Path.Num() / CalculateDistanceBetweenNodes(StartNode, GoalNode)));
    
	// Log Debug message (Accessed through Window->Developer Tools->Output Log)
	UE_LOG(LogTemp, Warning, TEXT("Total Cells searched: %d with a path length of: %d and a distance of: %f"), SearchCount, Ship->Path.Num(), CalculateDistanceBetweenNodes(StartNode, GoalNode));
	UE_LOG(LogTemp, Warning, TEXT("The difference between the current implemented path and the direct flight path is: %f"), Ship->Path.Num() / CalculateDistanceBetweenNodes(StartNode, GoalNode));
}

void APathManager::CalculateDFS()
{
	// Create the starting nodes
	GridNode* currentNode = nullptr;
	GridNode* tempNode = nullptr;
	bool isGoalFound = false;

	// Create a list of nodes
	TArray<GridNode*> nodesToVisit;
	StartNode->IsChecked = true;
	nodesToVisit.Add(StartNode);

	// Loop through all the required nodes
	while (nodesToVisit.Num() >= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Count: %d"), SearchCount);
		// Get the next node and remove it from the list
		SearchCount++;
		currentNode = nodesToVisit.Last();
		nodesToVisit.RemoveAt(nodesToVisit.Num() - 1);

		// Check if the goal is reached
		if (currentNode == GoalNode)
		{
			isGoalFound = true;
			break;
		}

		// Check the left neighbour
		if (currentNode->Y - 1 >= 0)
		{
			// Get the Left neighbour from the list
			tempNode = LevelGenerator->WorldArray[currentNode->X][currentNode->Y - 1];

			// Check to make sure the node hasn't been visited AND is not closed (Land)
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the top neighbour
		if (currentNode->X + 1 < LevelGenerator->MapSizeX - 1)
		{
			tempNode = LevelGenerator->WorldArray[currentNode->X + 1][currentNode->Y];
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the right neighbour
		if (currentNode->Y + 1 < LevelGenerator->MapSizeY - 1)
		{
			tempNode = LevelGenerator->WorldArray[currentNode->X][currentNode->Y + 1];
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the bottom neighbour
		if (currentNode->X - 1 > 0)
		{
			tempNode = LevelGenerator->WorldArray[currentNode->X - 1][currentNode->Y];
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}
	}

	// If the final goal is reached
	if (isGoalFound)
	{
		RenderPath();
		if (Ship)
			Ship->GeneratePath = false;
	}
}

void APathManager::CalculateBFS()
{
	// Create the starting nodes
	GridNode* currentNode = nullptr;
	GridNode* tempNode = nullptr;
	bool isGoalFound = false;

	// Create a list of nodes
	TArray<GridNode*> nodesToVisit;
	StartNode->IsChecked = true;
	nodesToVisit.Add(StartNode);

	// Loop through all the required nodes
	while (nodesToVisit.Num() >= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Count: %d"), SearchCount);
		// Get the next node and remove it from the list
		SearchCount++;
		currentNode = nodesToVisit[0];
		nodesToVisit.RemoveAt(0); // ONLY THIS IS DIFFERENT

		// Check if the goal is reached
		if (currentNode == GoalNode)
		{
			isGoalFound = true;
			break;
		}

		// Check the left neighbour
		if (currentNode->Y - 1 >= 0)
		{
			// Get the Left neighbour from the list
			tempNode = LevelGenerator->WorldArray[currentNode->X][currentNode->Y - 1];

			// Check to make sure the node hasn't been visited AND is not closed (Land)
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the top neighbour
		if (currentNode->X + 1 < LevelGenerator->MapSizeX - 1)
		{
			tempNode = LevelGenerator->WorldArray[currentNode->X + 1][currentNode->Y];
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the right neighbour
		if (currentNode->Y + 1 < LevelGenerator->MapSizeY - 1)
		{
			tempNode = LevelGenerator->WorldArray[currentNode->X][currentNode->Y + 1];
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the bottom neighbour
		if (currentNode->X - 1 > 0)
		{
			tempNode = LevelGenerator->WorldArray[currentNode->X - 1][currentNode->Y];
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}
	}

	// If the final goal is reached
	if (isGoalFound)
	{
		RenderPath();
		if (Ship)
			Ship->GeneratePath = false;
	}
}

void APathManager::CalculateDijkstra()
{
	// Remove the H factor from the algorithm
	CalculateAStar(0.0);
}

void APathManager::CalculateAStar(float weight)
{
	// Define the list of nodes that have been visited or should be visited
	TArray<GridNode*> openList;
	TArray<GridNode*> closedList;

	// Store a reference to the current node
	GridNode* currentNode;

	// Define a start node's cost value
	StartNode->G = 0;
	StartNode->H = EstimateCost(StartNode, GoalNode);
	StartNode->CalculateF(weight);

	// Adds the starting node to the open list
	openList.Add(StartNode);

	// Loop while the open list is valid
	while (openList.Num() > 0) {
	    // Find the node in the open list with the smallest F value
		{
			int smallFIndex = 0;
			float smallFValue = 999999;

			// Loop through each element in the list
			for (int i = 0; i < openList.Num(); i++) {
				if (openList[i]->F < smallFValue)
				{
					smallFValue = openList[i]->F;
					smallFIndex = i;
				}
			}

			// Get and store the current node as the smallest value in the open list
			currentNode = openList[smallFIndex];
			openList.RemoveAt(smallFIndex);
			closedList.Add(currentNode);
		}

		// Check if the current node is the goal
		if (currentNode == GoalNode)
			break; // TODO return path from start node to goal node

		// Create a list of accessible nodes
		TArray<GridNode*> accessibleNodes = {};
		if (currentNode->X + 1 < LevelGenerator->MapSizeX - 1)
			accessibleNodes.Add(LevelGenerator->WorldArray[currentNode->X + 1][currentNode->Y]);
		if (currentNode->X - 1 > 0) // TODO check if this works with >= 0
			accessibleNodes.Add(LevelGenerator->WorldArray[currentNode->X - 1][currentNode->Y]);
		if (currentNode->Y + 1 < LevelGenerator->MapSizeY - 1)
			accessibleNodes.Add(LevelGenerator->WorldArray[currentNode->X][currentNode->Y + 1]);
		if (currentNode->Y - 1 > 0) // TODO check if this works with >= 0
			accessibleNodes.Add(LevelGenerator->WorldArray[currentNode->X][currentNode->Y - 1]);
		
		// Loop through each node accessible from the current node
		for (GridNode* nextNode : accessibleNodes)
		{
			// Ensure the next node isn't on the closed list
			if (closedList.Contains(nextNode))
				continue;
			
			// Calculate the heuristic g value
			const float possibleG = currentNode->G + nextNode->GetTravelCost(); // TODO check this is the correct method
			bool possibleGIsBetter = false;

			// Check if the next node is not in the open list
			if (!openList.Contains(nextNode))
			{
				// Find the heuristic value of the node
				openList.Add(nextNode);
				nextNode->H = EstimateCost(nextNode, GoalNode);
				possibleGIsBetter = true;
			}

			// Check if the possible G is better than the current G
			else if (possibleG < nextNode->G)
			{
				possibleGIsBetter = true;
			}

			// If there is a possible better G value
			if (possibleGIsBetter)
			{
				nextNode->Parent = currentNode;
				nextNode->G = possibleG;
				nextNode->CalculateF(weight);
			}
		}
	}

	// TODO check if the path is valid
	RenderPath();
	if (Ship)
		Ship->GeneratePath = false;
}

void APathManager::RenderPath()
{
	// Get the current world and final goal node
	UWorld* World = GetWorld();
	GridNode* CurrentNode = GoalNode;

	// Create a path render
	while (CurrentNode->Parent != nullptr)
	{
		// Spawn the new path node
		const FVector Position(CurrentNode->X * ALevelGenerator::GRID_SIZE_WORLD, CurrentNode->Y * ALevelGenerator::GRID_SIZE_WORLD, 20);
		AActor* PDActor = World->SpawnActor<AActor>(PathDisplayBlueprint, Position, FRotator::ZeroRotator);
		PathDisplayActors.Add(PDActor);

		// Move the ship to the next node
		if (Ship)
			Ship->Path.EmplaceAt(0, LevelGenerator->WorldArray[CurrentNode->X][CurrentNode->Y]);
		CurrentNode = CurrentNode->Parent;
	}
}

void APathManager::ResetPath()
{
	// Reset the nodes for the search
	IsPathCalculated = false;
	SearchCount = 0;

	// Reset the nodes
	for (int X = 0; X < LevelGenerator->MapSizeX; X++)
	{
		for (int Y = 0; Y < LevelGenerator->MapSizeY; Y++)
		{
			// Reset the search variables
			LevelGenerator->WorldArray[X][Y]->F = 0;
			LevelGenerator->WorldArray[X][Y]->G = 0;
			LevelGenerator->WorldArray[X][Y]->H = 0;
			LevelGenerator->WorldArray[X][Y]->Parent = nullptr;
			LevelGenerator->WorldArray[X][Y]->IsChecked = false;
		}
	}

	// Update the path of the actors
	for (int i = 0; i < PathDisplayActors.Num(); i++)
	{
		PathDisplayActors[i]->Destroy();
	}
	
	PathDisplayActors.Empty();

	// Reset the ships path
	if (Ship)
		Ship->Path.Empty();
}


float APathManager::EstimateCost(GridNode* first, GridNode* second)
{
	// TODO For now just calculate the distance between the two as the heuristic
	return CalculateDistanceBetweenNodes(first, second);
}

