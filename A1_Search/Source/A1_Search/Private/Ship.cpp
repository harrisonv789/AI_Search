// FIT3094 - Assignment 1
// Harrison Verrios

#include "Ship.h"
#include "PathManager.h"
#include "LevelGenerator.h"

// Sets default values
AShip::AShip()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Set up some of the data
	MoveSpeed = 300;
	Tolerance = 5;
	Morale = MAX_MORALE;
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If has found gold, ignore
	if (HasFoundGold)
		return;

	// Check if the path is not empty
	if (Path.Num() > 0 && Morale > 0) {

		// Get the current position
		FVector currentPosition = GetActorLocation();
		const float targetPosX = Path[0]->X * ALevelGenerator::GRID_SIZE_WORLD + POSITION_OFFSET_X;
		const float targetPosY = Path[0]->Y * ALevelGenerator::GRID_SIZE_WORLD + POSITION_OFFSET_Y;

		// Determine the target position
		const FVector targetPosition = FVector(targetPosX, targetPosY, currentPosition.Z);

		// Determine the unit direction
		FVector direction = targetPosition - currentPosition;
		direction.Normalize();
		MoveHeading = direction;

		// Alter the current position
		currentPosition += direction * DeltaTime * GetMoveSpeed();

		// Check for a new point
		if (FVector::Dist(currentPosition, targetPosition) <= Tolerance)
		{
			// Update the position to the actual target
			currentPosition = targetPosition;
			PathManager->StartNode = Path[0];
			Path.RemoveAt(0);

			// Subtract a morale
			Morale--;
		}

		// Update the actor location
		SetActorLocation(currentPosition);
	}

	// Otherwise, if no path
	else if (Morale > 0)
	{
		// Increase the treasure collected
		Treasure++;

		// Adjust the found gold flag
		HasFoundGold = true;
	}

	// If Morale is zero, hide the path
	if (Morale <= 0)
	{
		PathManager->ResetPath();
	}
}

float AShip::GetMoveSpeed() const
{
	// Make sure the path is valid
	if (Path.Num() > 0)
		return MoveSpeed * Path[0]->GetNodeSpeed();
	return 0.0;
}


void AShip::FindNewGold()
{
	// Reset the gold flag
	HasFoundGold = false;

	// Reset the morale
	Morale = MAX_MORALE;

	// Generate a new path
	GeneratePath = true;
}
