// Fill out your copyright notice in the Description page of Project Settings.
#include "Ship.h"

#include "LevelGenerator.h"

// Sets default values
AShip::AShip()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Set up some of the data
	MoveSpeed = 100;
	Tolerance = 5;
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
		CurrentPosition += Direction * MoveSpeed * DeltaTime;

		// Check for a new point
		if (FVector::Dist(CurrentPosition, TargetPosition) <= Tolerance)
		{
			// Update the position to the actual target
			CurrentPosition = TargetPosition;
			Level->StartNode = Path[0];
			Path.RemoveAt(0);
		}

		// Update the actor location
		SetActorLocation(CurrentPosition);
	}

	// Otherwise, if no path
	else
	{
		GeneratePath = true;
	}
}

