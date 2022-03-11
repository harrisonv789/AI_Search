// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelGenerator.h"

#include "Ship.h"
#include "Engine/World.h"

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
		//CalculateDFS();
		CalculateBFS();
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
	//CalculateDFS();
	CalculateBFS();
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
			case 'G': WorldArray[X][Y]->GridType = GridNode::DeepWater; break;
			case '@':
			case 'O':
			case 'S':
			case 'W': WorldArray[X][Y]->GridType = GridNode::Land; break;
			case 'T': WorldArray[X][Y]->GridType = GridNode::ShallowWater; break;
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
			if (tempNode->GridType != GridNode::Land && !tempNode->IsChecked)
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
			if (tempNode->GridType != GridNode::Land && !tempNode->IsChecked)
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
			if (tempNode->GridType != GridNode::Land && !tempNode->IsChecked)
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
			if (tempNode->GridType != GridNode::Land && !tempNode->IsChecked)
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
			if (tempNode->GridType != GridNode::Land && !tempNode->IsChecked)
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
			if (tempNode->GridType != GridNode::Land && !tempNode->IsChecked)
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
			if (tempNode->GridType != GridNode::Land && !tempNode->IsChecked)
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
			if (tempNode->GridType != GridNode::Land && !tempNode->IsChecked)
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
