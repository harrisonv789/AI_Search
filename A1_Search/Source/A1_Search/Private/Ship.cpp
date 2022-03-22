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

	// Check if the path is not empty
	if (Path.Num() > 0) {

		// Get the current position
		FVector CurrentPosition = GetActorLocation();
		const float TargetXPos = Path[0]->X * ALevelGenerator::GRID_SIZE_WORLD;
		const float TargetYPos = Path[0]->Y * ALevelGenerator::GRID_SIZE_WORLD;

		// Determine the target position
		const FVector TargetPosition = FVector(TargetXPos, TargetYPos, CurrentPosition.Z);

		// Determine the unit direction
		FVector Direction = TargetPosition - CurrentPosition;
		Direction.Normalize();

		// Alter the current position
		CurrentPosition += Direction * DeltaTime * GetMoveSpeed();

		// Check for a new point
		if (FVector::Dist(CurrentPosition, TargetPosition) <= Tolerance)
		{
			// Update the position to the actual target
			CurrentPosition = TargetPosition;
			PathManager->StartNode = Path[0];
			Path.RemoveAt(0);

			// Subtract a morale
			Morale--;
		}

		// Update the actor location
		SetActorLocation(CurrentPosition);
	}

	// Otherwise, if no path
	else
	{
		GeneratePath = true;

		// Reset the morale
		Morale = MAX_MORALE;
	}
}

float AShip::GetMoveSpeed() const
{
	// Make sure the path is valid
	if (Path.Num() > 0)
		return MoveSpeed * Path[0]->GetNodeSpeed();
	return 0.0;
}
