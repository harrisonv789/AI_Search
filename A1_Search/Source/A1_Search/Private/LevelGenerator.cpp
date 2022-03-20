// FIT3094 - Assignment 1
// Harrison Verrios

#include "LevelGenerator.h"

// Sets default values
ALevelGenerator::ALevelGenerator()
{
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALevelGenerator::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALevelGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if the Ship requires a new path to be generated
	if (Ship && Ship->GeneratePath && GoldActors.Num() > 0) {

		// Update the new path
		CollectGold();
		ResetPath();
		SpawnNextGold();

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
}

void ALevelGenerator::CollectGold()
{
	// Remove the current gold
	GoldArray.RemoveAt(0);
	GoldActors[0]->Destroy();
	GoldActors.RemoveAt(0);
}

void ALevelGenerator::GenerateWorldFromFile(TArray<FString> WorldArrayString)
{
	// If empty array exit immediately something is horribly wrong
    if(WorldArrayString.Num() == 0)
    {
    	UE_LOG(LogTemp, Warning, TEXT("World Array is empty!"));
    	return;
    }

    // Second line is Height (aka Y value)
    FString Height = WorldArrayString[1];
    Height.RemoveFromStart("Height ");
    MapSizeY = FCString::Atoi(*Height);
    UE_LOG(LogTemp, Warning, TEXT("Height: %d"), MapSizeY);

    // Third line is Width (aka X value)
    FString Width = WorldArrayString[2];
    Width.RemoveFromStart("width ");
    MapSizeX = FCString::Atoi(*Width);
    UE_LOG(LogTemp, Warning, TEXT("Width: %d"), MapSizeX);

    char CharMapArray[MAX_MAP_SIZE][MAX_MAP_SIZE];
    
    // Read through the Map section for create the CharMapArray
    for (int LineNum = 4; LineNum < MapSizeY + 4; LineNum++)
    {
    	for (int CharNum = 0; CharNum < WorldArrayString[LineNum].Len(); CharNum++)
    	{
    		CharMapArray[LineNum-4][CharNum] = WorldArrayString[LineNum][CharNum];
    	}
    }

    // Read in the Gold positions
    for (int LineNum = 4 + MapSizeY; LineNum < WorldArrayString.Num(); LineNum++)
    {
    	FString GoldX, GoldY;
    	WorldArrayString[LineNum].Split(",", &GoldY, &GoldX);
    	UE_LOG(LogTemp, Warning, TEXT("GoldX: %s"), *GoldX);
    	UE_LOG(LogTemp, Warning, TEXT("GoldY: %s"), *GoldY);

    	GoldArray.Add(FVector2D(FCString::Atof(*GoldX), FCString::Atof(*GoldY)));

    }

	// Generates the files
	GenerateNodeGrid(CharMapArray);
	SpawnWorldActors(CharMapArray);

	// Load the search based on the search type
	switch (SearchType)
	{
		case DFS:		CalculateDFS(); break;
		case BFS:		CalculateBFS(); break;
		case DIJKSTRA:	CalculateDijkstra(); break;
		case A_STAR:	CalculateAStar(); break;
		default: break;
	}

	// Draw the path
	DetailPath();
}

void ALevelGenerator::SpawnWorldActors(char Grid[255][255])
{
	// Get the current world
	UWorld* World = GetWorld();

	// Make sure all blueprints are connected
	if (DeepBlueprint && ShallowBlueprint && LandBlueprint)
	{
		for (int X = 0; X < MapSizeX; X++)
		{
			for (int Y = 0; Y < MapSizeY; Y++)
			{
				const float XPos = X * GRID_SIZE_WORLD;
				const float YPos = Y * GRID_SIZE_WORLD;

				FVector Position(XPos, YPos, 0);

				switch (Grid[X][Y])
				{
					case '.':
					case 'G':
						World->SpawnActor(DeepBlueprint, &Position, &FRotator::ZeroRotator);
						break;
					case '@':
					case 'O':
					case 'S':
					case 'W':
						World->SpawnActor(LandBlueprint, &Position, &FRotator::ZeroRotator);
						break;
					case 'T':
						World->SpawnActor(ShallowBlueprint, &Position, &FRotator::ZeroRotator);
						break;
					default: break;
				}
			}
		}
	}

	// Generate Initial Agent Positions
    if(ShipBlueprint)
    {
    	int XPos = 16; //Default Intial X Position
    	int YPos = 23; //Default Intial Y Position

    	FVector Position(XPos * GRID_SIZE_WORLD, YPos * GRID_SIZE_WORLD, 20);
    	Ship = World->SpawnActor<AShip>(ShipBlueprint, Position, FRotator::ZeroRotator);
    	Ship->Level = this;

    	WorldArray[XPos][YPos]->ObjectAtLocation = Ship;
    	StartNode = WorldArray[XPos][YPos];
    }

	// Generate Initial food positions
	if (GoldBlueprint && GoldArray.Num() > 0)
	{
		SpawnNextGold();
	}

	// Set the static camera position
	if (Camera)
	{
		FVector CameraPosition = Camera->GetActorLocation();

		// Reset the position
		CameraPosition.X = MapSizeX * 0.5 * GRID_SIZE_WORLD;
		CameraPosition.Y = MapSizeY * 0.5 * GRID_SIZE_WORLD;

		// Set the camera location
		Camera->SetActorLocation(CameraPosition);
	}
}

void ALevelGenerator::SpawnNextGold()
{
	// Get the current world and remove the firs element from the gold
	UWorld* World = GetWorld();

	// Generate Initial Food Positions
	if (GoldBlueprint && GoldArray.Num() > 0)
	{
		int XPos = GoldArray[0].X;
		int YPos = GoldArray[0].Y;

		// Get the position of the gold
		const FVector Position(XPos * GRID_SIZE_WORLD, YPos * GRID_SIZE_WORLD, 20);
		AGold* NewGold = World->SpawnActor<AGold>(GoldBlueprint, Position, FRotator::ZeroRotator);

		// Store the gold position
		WorldArray[XPos][YPos]->ObjectAtLocation = NewGold;
		GoalNode = WorldArray[XPos][YPos];
		GoldActors.Add(NewGold);
	}
}

float ALevelGenerator::EstimateCost(GridNode* first, GridNode* second)
{
	// TODO For now just calculate the distance between the two as the heuristic
	return CalculateDistanceBetweenNodes(first, second);
}

void ALevelGenerator::GenerateNodeGrid(char Grid[255][255])
{
	for (int X = 0; X < MapSizeX; X++)
	{
		for (int Y = 0; Y < MapSizeY; Y++)
		{
			// Set up the world array with a new grid item
			WorldArray[X][Y] = new GridNode();
			WorldArray[X][Y]->X = X;
			WorldArray[X][Y]->Y = Y;

			// Characters as defined from the map file
			switch (Grid[X][Y])
			{
			case '.':
			case 'G': WorldArray[X][Y]->GridType = DeepWater; break;
			case '@':
			case 'O':
			case 'S':
			case 'W': WorldArray[X][Y]->GridType = Land; break;
			case 'T': WorldArray[X][Y]->GridType = ShallowWater; break;
			default: break;
			}
		}
	}
}

void ALevelGenerator::ResetAllNodes()
{
	for (int X = 0; X < MapSizeX; X++)
	{
		for (int Y = 0; Y < MapSizeY; Y++)
		{
			// Reset the search variables
			WorldArray[X][Y]->F = 0;
			WorldArray[X][Y]->G = 0;
			WorldArray[X][Y]->H = 0;
			WorldArray[X][Y]->Parent = nullptr;
			WorldArray[X][Y]->IsChecked = false;
		}
	}
}

float ALevelGenerator::CalculateDistanceBetweenNodes(GridNode* first, GridNode* second)
{
	const FVector distToTarget = FVector(second->X - first->X, second->Y - first->Y, 0);
	return distToTarget.Size();
}

void ALevelGenerator::DetailPath()
{
	// Onscreen Debug (Don't forget the include!)
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, FString::Printf(TEXT("Total Cells searched: %d with a path length of: %d and a distance of: %f"), SearchCount, Ship->Path.Num(), CalculateDistanceBetweenNodes(StartNode, GoalNode)));
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, FString::Printf(TEXT("The difference between the current implemented path and the direct flight path is: %f"), Ship->Path.Num() / CalculateDistanceBetweenNodes(StartNode, GoalNode)));
    
	// Log Debug message (Accessed through Window->Developer Tools->Output Log)
	UE_LOG(LogTemp, Warning, TEXT("Total Cells searched: %d with a path length of: %d and a distance of: %f"), SearchCount, Ship->Path.Num(), CalculateDistanceBetweenNodes(StartNode, GoalNode));
	UE_LOG(LogTemp, Warning, TEXT("The difference between the current implemented path and the direct flight path is: %f"), Ship->Path.Num() / CalculateDistanceBetweenNodes(StartNode, GoalNode));
}

void ALevelGenerator::CalculateDFS()
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
			tempNode = WorldArray[currentNode->X][currentNode->Y - 1];

			// Check to make sure the node hasn't been visited AND is not closed (Land)
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the top neighbour
		if (currentNode->X + 1 < MapSizeX - 1)
		{
			tempNode = WorldArray[currentNode->X + 1][currentNode->Y];
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the right neighbour
		if (currentNode->Y + 1 < MapSizeX - 1)
		{
			tempNode = WorldArray[currentNode->X][currentNode->Y + 1];
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
			tempNode = WorldArray[currentNode->X - 1][currentNode->Y];
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
		Ship->GeneratePath = false;
	}
}

void ALevelGenerator::CalculateBFS()
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
			tempNode = WorldArray[currentNode->X][currentNode->Y - 1];

			// Check to make sure the node hasn't been visited AND is not closed (Land)
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the top neighbour
		if (currentNode->X + 1 < MapSizeX - 1)
		{
			tempNode = WorldArray[currentNode->X + 1][currentNode->Y];
			if (tempNode->GridType != Land && !tempNode->IsChecked)
			{
				tempNode->IsChecked = true;
				tempNode->Parent = currentNode;
				nodesToVisit.Add(tempNode);
			}
		}

		// Check the right neighbour
		if (currentNode->Y + 1 < MapSizeY - 1)
		{
			tempNode = WorldArray[currentNode->X][currentNode->Y + 1];
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
			tempNode = WorldArray[currentNode->X - 1][currentNode->Y];
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
		Ship->GeneratePath = false;
	}
}

void ALevelGenerator::CalculateDijkstra()
{
	// Remove the H factor from the algorithm
	CalculateAStar(0.0);
}

void ALevelGenerator::CalculateAStar(float weight)
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
		if (currentNode->X + 1 < MapSizeX - 1)
			accessibleNodes.Add(WorldArray[currentNode->X + 1][currentNode->Y]);
		if (currentNode->X - 1 > 0) // TODO check if this works with >= 0
			accessibleNodes.Add(WorldArray[currentNode->X - 1][currentNode->Y]);
		if (currentNode->Y + 1 < MapSizeY - 1)
			accessibleNodes.Add(WorldArray[currentNode->X][currentNode->Y + 1]);
		if (currentNode->Y - 1 > 0) // TODO check if this works with >= 0
			accessibleNodes.Add(WorldArray[currentNode->X][currentNode->Y - 1]);
		
		// Loop through each node accessible from the current node
		for (GridNode* nextNode : accessibleNodes)
		{
			// Ensure the next node isn't on the closed list
			if (closedList.Contains(nextNode))
				continue;
			
			// Calculate the heuristic g value
			float possibleG = currentNode->G + nextNode->GetTravelCost(); // TODO check this is the correct method
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
	Ship->GeneratePath = false;
}

void ALevelGenerator::RenderPath()
{
	// Get the current world and final goal node
	UWorld* World = GetWorld();
	GridNode* CurrentNode = GoalNode;

	// Create a path render
	while (CurrentNode->Parent != nullptr)
	{
		// Spawn the new path node
		const FVector Position(CurrentNode->X * GRID_SIZE_WORLD, CurrentNode->Y * GRID_SIZE_WORLD, 20);
		AActor* PDActor = World->SpawnActor<AActor>(PathDisplayBlueprint, Position, FRotator::ZeroRotator);
		PathDisplayActors.Add(PDActor);

		// Move the ship to the next node
		Ship->Path.EmplaceAt(0, WorldArray[CurrentNode->X][CurrentNode->Y]);
		CurrentNode = CurrentNode->Parent;
	}
}

void ALevelGenerator::ResetPath()
{
	// Reset the nodes for the search
	IsPathCalculated = false;
	SearchCount = 0;
	ResetAllNodes();

	// Update the path of the actors
	for (int i = 0; i < PathDisplayActors.Num(); i++)
	{
		PathDisplayActors[i]->Destroy();
	}
	PathDisplayActors.Empty();

	// Reset the ships path
	Ship->Path.Empty();
}
