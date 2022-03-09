// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

/**
 * 
 */
class FIT3094_A1_CODE_API GridNode
{

public:

	// All types of Grid cells
	enum GRID_TYPE
	{
		DeepWater,
		Land,
		ShallowWater
	};

	GridNode();

	/**
	 * @brief Calculates the Cost of travelling to a location
	 * @return The Cost in Units
	 */
	float GetTravelCost () const;

	// Position of the Grid
	int X;
	int Y;

	// Informed search variables
	int G;
	float H;
	float F;

	// Stores the specific type of Grid
	GRID_TYPE GridType;

	// Pointer to the previous node, used for searching
	GridNode* Parent;

	// Reference of the object at the current location
	AActor* ObjectAtLocation;

	// Flag for whether or not he grid square has been checked by a search
	bool IsChecked;
};
