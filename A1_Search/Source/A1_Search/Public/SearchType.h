// FIT3094 - Assignment 1
// Harrison Verrios

#pragma once

UENUM(Blueprintable, BlueprintType)
enum ESearchType
{
	DFS			= 0, // Depth First Search
	BFS			= 1, // Breadth First Search
	DIJKSTRA    = 2, // Uniform Cost Search
	A_STAR	    = 3, // A* Algorithm
};