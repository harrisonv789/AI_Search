// FIT3094 - Assignment 1
// Harrison Verrios

#include "GridNode.h"

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

float GridNode::GridTypeCost(EGridType type)
{
	// Check the grid type and return the correct cost
	switch (type)
	{
		case DeepWater: return 1;
		case ShallowWater: return 2;
		default: return 999999;
	}
}

