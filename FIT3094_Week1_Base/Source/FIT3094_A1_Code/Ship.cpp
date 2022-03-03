// Fill out your copyright notice in the Description page of Project Settings.
#include "Ship.h"

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

	// Get the current position
	FVector CurrentPosition = GetActorLocation();
	float TargetXPos = Path[0]->X
}

