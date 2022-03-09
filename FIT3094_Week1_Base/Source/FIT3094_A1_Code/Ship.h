// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GridNode.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ship.generated.h"

// Resolves a circular dependency
class ALevelGenerator;


UCLASS()
class FIT3094_A1_CODE_API AShip : public AActor
{
	GENERATED_BODY()
	
public:	

	// Stores the speed that the ship can move at
	UPROPERTY(EditAnywhere, Category = "Stats")
	float MoveSpeed;

	// The distance between a point on the path and the current position before reaching the end
	UPROPERTY(EditAnywhere, Category = "Stats")
	float Tolerance;

	// A list of points on a path to follow
	TArray<GridNode*> Path;

	// A flag for whether a path needs to be generated
	bool GeneratePath = true;

	// A reference to the current level
	ALevelGenerator* Level;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Sets default values for this actor's properties
    AShip();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
