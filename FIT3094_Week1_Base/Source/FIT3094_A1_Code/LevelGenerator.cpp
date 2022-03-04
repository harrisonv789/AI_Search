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
	if (ShipBlueprint)
	{
		// Store defaults
		const int XPos = 22;
		const int YPos = 22;

		// Get the position and spawn the ship
		FVector Position(XPos * GRID_SIZE_WORLD, YPos * GRID_SIZE_WORLD, 20);
		AShip* Ship = World->SpawnActor<AShip>(ShipBlueprint, Position, FRotator::ZeroRotator);

		// Store the ship in the world array
		WorldArray[XPos][YPos]->ObjectAtLocation = Ship;

		// Adding the default path for testing
		for (int i = 0; i < 10; i++)
		{
			Ship->Path.Add(WorldArray[22][23]);
			Ship->Path.Add(WorldArray[22][24]);
			Ship->Path.Add(WorldArray[21][24]);
			Ship->Path.Add(WorldArray[21][23]);
			Ship->Path.Add(WorldArray[20][23]);
			Ship->Path.Add(WorldArray[20][22]);
			Ship->Path.Add(WorldArray[21][22]);
			Ship->Path.Add(WorldArray[21][21]);
			Ship->Path.Add(WorldArray[22][21]);
			Ship->Path.Add(WorldArray[22][22]);
		}
	}

	// Generate Initial food positions
	if (GoldBlueprint && GoldArray.Num() > 0)
	{
		const int XPos = GoldArray[0].X;
		const int YPos = GoldArray[0].Y;

		// Spawn the gold
		const FVector Position(XPos * GRID_SIZE_WORLD, YPos * GRID_SIZE_WORLD, 20);
		AGold* NewGold = World->SpawnActor<AGold>(GoldBlueprint, Position, FRotator::ZeroRotator);

		// Add the gold to the array
		WorldArray[XPos][YPos]->ObjectAtLocation = NewGold;
		GoldActors.Add(NewGold);
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
		}
	}
}

float ALevelGenerator::CalculateDistanceBetweenNodes(GridNode* first, GridNode* second)
{
	FVector distToTarget = FVector(second->X - first->X, second->Y - first->Y, 0);
	return distToTarget.Size();
}

void ALevelGenerator::SpawnNextGold()
{
	// Get the current world and remove the firs element from the gold
	UWorld* World = GetWorld();
	GoldArray.RemoveAt(0);

	// Generate Initial Food Positions
	if (GoldBlueprint && GoldArray.Num() > 0)
	{
		int XPos = GoldArray[0].X;
		int YPos = GoldArray[0].Y;

		// Get the position of the gold
		FVector Position(XPos * GRID_SIZE_WORLD, YPos * GRID_SIZE_WORLD, 20);
		AGold* NewGold = World->SpawnActor<AGold>(GoldBlueprint, Position, FRotator::ZeroRotator);

		// Store the gold position
		WorldArray[XPos][YPos]->ObjectAtLocation = NewGold;
		GoldActors.Add(NewGold);
	}
}

// Called every frame
void ALevelGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALevelGenerator::GenerateWorldFromFile(TArray<FString> WorldArrayString)
{
	// If the world is empty, return
	if (WorldArrayString.Num() == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, " World Array is Empty!");
		return;
	}

	// Second line is the height, aka X value
	FString Height = WorldArrayString[1];
	Height.RemoveFromStart("height ");
	MapSizeX = FCString::Atoi(*Height);
	UE_LOG(LogTemp, Warning, TEXT("Height: %d"), MapSizeX);
	
	// Third line is the height, aka X value
    FString Width = WorldArrayString[2];
    Width.RemoveFromStart("width ");
    MapSizeY = FCString::Atoi(*Width);
    UE_LOG(LogTemp, Warning, TEXT("Width: %d"), MapSizeY);

	char CharMapArray[MAX_MAP_SIZE][MAX_MAP_SIZE];

	// Read through the Map section for create the CharMapArray
	for (int LineNum = 4; LineNum < MapSizeX + 4; LineNum++)
	{
		for (int CharNum = 0; CharNum < WorldArrayString[LineNum].Len(); CharNum++)
		{
			CharMapArray[LineNum - 4][CharNum] = WorldArrayString[LineNum][CharNum];
		}
	}

	// Read in the food positions
	for (int LineNum = 4 + MapSizeX; LineNum < WorldArrayString.Num(); LineNum++)
	{
		FString GoldX, GoldY;
		WorldArrayString[LineNum].Split(",", &GoldX, &GoldY);
		UE_LOG(LogTemp, Warning, TEXT("GoldX: %s"), *GoldX);
		UE_LOG(LogTemp, Warning, TEXT("GoldY: %s"), *GoldY);

		// Add an item into the Gold
		GoldArray.Add(FVector2D(FCString::Atof(*GoldX), FCString::Atof(*GoldY)));
	}

	// Generates the files
	GenerateNodeGrid(CharMapArray);
	SpawnWorldActors(CharMapArray);
	
}
