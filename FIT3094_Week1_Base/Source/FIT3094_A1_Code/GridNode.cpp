// Fill out your copyright notice in the Description page of Project Settings.


#include "GridNode.h"

GridNode::GridNode()
{
	// Setup the variables
	X = Y = 0;
	G = H = F = 0.0;

	// Setup the cell types
	GridType = DeepWater;
	Parent = nullptr;
	ObjectAtLocation = nullptr;
}

float GridNode::GetTravelCost() const
{
	// Check the grid type and return the correct cost
	switch (GridType)
	{
		case Land: return 999999;
		case DeepWater: return 1;
		case ShallowWater: return 1;
	}

	// Missing a type
	return 999999;
}
