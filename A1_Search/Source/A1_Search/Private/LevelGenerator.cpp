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
    FString height = WorldArrayString[1];
    height.RemoveFromStart("Height ");
    MapSizeY = FCString::Atoi(*height);
    UE_LOG(LogTemp, Warning, TEXT("Height: %d"), MapSizeY);

    // Third line is Width (aka X value)
    FString width = WorldArrayString[2];
    width.RemoveFromStart("width ");
    MapSizeX = FCString::Atoi(*width);
    UE_LOG(LogTemp, Warning, TEXT("Width: %d"), MapSizeX);

	// Update the path manager
	if (PathManager)
		PathManager->LevelGenerator = this;

    char CharMapArray[MAX_MAP_SIZE][MAX_MAP_SIZE];
    
    // Read through the Map section for create the CharMapArray
    for (int lineNum = 4; lineNum < MapSizeY + 4; lineNum++)
    {
    	for (int charNum = 0; charNum < WorldArrayString[lineNum].Len(); charNum++)
    	{
    		CharMapArray[lineNum-4][charNum] = WorldArrayString[lineNum][charNum];
    	}
    }

    // Read in the Gold positions
    for (int lineNum = 4 + MapSizeY; lineNum < WorldArrayString.Num(); lineNum++)
    {
    	FString goldX, goldY;
    	WorldArrayString[lineNum].Split(",", &goldY, &goldX);
    	UE_LOG(LogTemp, Warning, TEXT("GoldX: %s"), *goldX);
    	UE_LOG(LogTemp, Warning, TEXT("GoldY: %s"), *goldY);

    	GoldArray.Add(FVector2D(FCString::Atof(*goldX), FCString::Atof(*goldY)));

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
	UWorld* world = GetWorld();

	// Make sure all blueprints are connected
	if (DeepBlueprint && ShallowBlueprint && LandBlueprint)
	{
		for (int X = 0; X < MapSizeX; X++)
		{
			for (int Y = 0; Y < MapSizeY; Y++)
			{
				const float posX = X * GRID_SIZE_WORLD;
				const float posY = Y * GRID_SIZE_WORLD;

				FVector Position(posX, posY, 0);

				switch (Grid[X][Y])
				{
					case '.':
					case 'G':
						world->SpawnActor(DeepBlueprint, &Position, &FRotator::ZeroRotator);
						break;
					case '@':
					case 'O':
					case 'S':
					case 'W':
						world->SpawnActor(LandBlueprint, &Position, &FRotator::ZeroRotator);
						break;
					case 'T':
						world->SpawnActor(ShallowBlueprint, &Position, &FRotator::ZeroRotator);
						break;
					default: break;
				}
			}
		}
	}

	// Generate Initial Agent Positions
    if(ShipBlueprint)
    {
    	constexpr int posX = 16; // Default Initial X Position
    	constexpr int posY = 23; // Default Initial Y Position

    	const FVector position(posX * GRID_SIZE_WORLD, posY * GRID_SIZE_WORLD, 20);
    	Ship = world->SpawnActor<AShip>(ShipBlueprint, position, FRotator::ZeroRotator);
    	Ship->PathManager = PathManager;
    	PathManager->Ship = Ship;

    	WorldArray[posX][posY]->ObjectAtLocation = Ship;
    	PathManager->StartNode = WorldArray[posX][posY];
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
	UWorld* world = GetWorld();

	// Generate Initial Food Positions
	if (GoldBlueprint && GoldArray.Num() > 0)
	{
		int posX = GoldArray[0].X;
		int posY = GoldArray[0].Y;

		// Get the position of the gold
		const FVector position(posX * GRID_SIZE_WORLD, posY * GRID_SIZE_WORLD, 20);
		AGold* newGold = world->SpawnActor<AGold>(GoldBlueprint, position, FRotator::ZeroRotator);

		// Store the gold position
		WorldArray[posX][posY]->ObjectAtLocation = newGold;
		PathManager->GoalNode = WorldArray[posX][posY];
		GoldActors.Add(newGold);
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