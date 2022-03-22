// FIT3094 - Assignment 1
// Harrison Verrios

#include "LevelGenerator.h"
#include "PathManager.h"

// Stores the use of shallow water
static bool ShallowWaterFlag = true;

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
		SpawnNextGold();
		PathManager->CreatePath();
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

	// Update the path manager
	if (PathManager)
		PathManager->LevelGenerator = this;

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

	// Create the path
	PathManager->CreatePath();
}


bool ALevelGenerator::GetShallowWater()
{
	return ShallowWaterFlag;
}


void ALevelGenerator::SetShallowWater(bool flag)
{
	ShallowWaterFlag = flag;
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
    	constexpr int XPos = 16; // Default Initial X Position
    	constexpr int YPos = 23; // Default Initial Y Position

    	const FVector Position(XPos * GRID_SIZE_WORLD, YPos * GRID_SIZE_WORLD, 20);
    	Ship = World->SpawnActor<AShip>(ShipBlueprint, Position, FRotator::ZeroRotator);
    	Ship->PathManager = PathManager;
    	PathManager->Ship = Ship;

    	WorldArray[XPos][YPos]->ObjectAtLocation = Ship;
    	PathManager->StartNode = WorldArray[XPos][YPos];
    }

	// Generate Initial food positions
	if (GoldBlueprint && GoldArray.Num() > 0)
	{
		SpawnNextGold();
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
		PathManager->GoalNode = WorldArray[XPos][YPos];
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