// FIT3094 - Assignment 1
// Harrison Verrios

#pragma once

#include "GridType.h"
#include "CoreMinimal.h"

/*
 * Stores information about a node on the grid, including path algorithms
 */
class A1_SEARCH_API GridNode
{
	
	/**************************************************************/
	public:

	// Position of the Grid
    int X;
    int Y;

    // Informed search variables
    int G;
    float H;
    float F;

    // Stores the specific type of node on the grid
    EGridType GridType;

    // Pointer to the previous node, used for searching
    GridNode* Parent;

    // Reference of the object at the current location
    AActor* ObjectAtLocation;

    // Flag for whether or not he grid square has been checked by a search
    bool IsChecked;

	
	/**************************************************************/

	/**
	 * @brief Default constructor for the grid node
	 */
	GridNode();

    /**
     * @brief Calculates the F value of the algorithm with some weighting
     */
    void CalculateF (float w = 1.0);

	/**
	* @brief Calculates the Cost of travelling to a location
	* @return The Cost in Units
	*/
	float GetTravelCost () const;

	/**
	 * @brief Calculates the speed factor when crossing this node
	 * @return The speed factor
	 */
	float GetNodeSpeed () const;

	/**
	 * @brief Returns the cost for a particular node
	 * @param type The type of the grid node
	 * @return The cost to land on this node
	 */
	static float GridTypeCost (EGridType type);
};
