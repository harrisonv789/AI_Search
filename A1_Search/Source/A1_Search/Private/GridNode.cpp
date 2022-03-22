// FIT3094 - Assignment 1
// Harrison Verrios

#include "GridNode.h"
#include "LevelGenerator.h"

GridNode::GridNode()
{
	// Reset the variables
	X = Y = 0;
	G = 0;
	H = F = 0.0;

	// Setup the cell types
	GridType = DeepWater;
	Parent = nullptr;
	ObjectAtLocation = nullptr;

	// Disable checking
	IsChecked = false;
}

void GridNode::CalculateF(float w)
{
	F = G + w * H;
}

float GridNode::GetTravelCost() const
{
	return GridTypeCost(GridType);
}

bool GridNode::IsTraversable() const
{
	return GridType != Land;
}

float GridNode::GetNodeSpeed() const
{
	// Check the grid type and return the correct speed factor
	switch (GridType)
	{
		case DeepWater: return 1.0;
		case ShallowWater: return ALevelGenerator::GetShallowWater() ? 0.5 : 1.0;
		default: return 0.01;
	}
}

float GridNode::GridTypeCost(EGridType type)
{
	// Check the grid type and return the correct cost
	switch (type)
	{
		case DeepWater: return 1;
		case ShallowWater: return ALevelGenerator::GetShallowWater() ? 2 : 1;
		default: return 999999;
	}
}

