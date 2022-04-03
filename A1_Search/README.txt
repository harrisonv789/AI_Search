/**************************************************************/
                        README INFORMATION
/**************************************************************/
                         Harrison Verrios
                           ASSIGNMENT 1
/**************************************************************/


JUSTIFICATION OF SEARCH ALGORITHM:
There are a number of search algorithms that have been demonstrated in this assignment. 
They include the following:
 - DFS
 - BFS
 - Dijkstra
 - A-Star
 - Weighted A-Star
 
In my assignment, I have an interactive UI that allows the user to change the algorithms used
and find better path planning methods. The user is able to adjust the algorithm, and for the
Weighted A-Star option, a Weighting can also be applied. Additionally, the UI shows the
following statistics for the search path found:
 - Cells Searched; The number of cells (including the start and goal nodes) that exist at some
        point in the OPEN list of the algorithm
 - Path Length; The number of cells the ship must transition through, excluding the start node
 - Path Cost; The heuristic cost of the path to reach the goal node from the start node
 - Goal Distance; The straight line distance from the start node to the goal node
 - Path Factor; The path length over the total distance
 - Path Time; The computational time it took to calculate the search path
 
I was able to use this UI feature to determine the best algorithm to use, and found the following
results for the first three gold.

GOLD ONE:
            CELLS SEARCH    |   PATH COST   |   FACTOR      |    TIME       
DFS:            991                 126         15.65           0.263s
BFS:            628                 18          1.342           0.155s
DIJKSTRA:       518                 18          1.342           0.005s
A-STAR:         101                 18          1.342           0.005s
W-A-STAR (1.5): 22                  18          1.342           0.005s
W-A-STAR (2.0): 19                  18          1.342           0.004s

GOLD TWO:
            CELLS SEARCH    |   PATH COST   |   FACTOR      |    TIME       
DFS:            --                  --           --               --
BFS:            65                  6           1.342           0.020s
DIJKSTRA:       56                  6           1.342           0.003s
A-STAR:         16                  6           1.342           0.003s
W-A-STAR (1.5): 8                   6           1.342           0.002s
W-A-STAR (2.0): 7                   6           1.342           0.002s

GOLD THREE:
            CELLS SEARCH    |   PATH COST   |   FACTOR      |    TIME       
DFS:            --                  --           --               --
BFS:            536                 23          1.414           0.117s
DIJKSTRA:       488                 20          1.414           0.006s
A-STAR:         139                 20          1.414           0.006s
W-A-STAR (1.5): 23                  20          1.414           0.006s
W-A-STAR (2.0): 21                  20          1.414           0.006s


Looking at the 6 chosen algorithms, it is clear that we can discard DFS. In
the first path, it took more than 50 steps to the goal, of which by then, the
morale of the ship had depleted. DFS is a horrible algorithm for this situation.

Next, we looked at BFS. BFS got to the goal accurately, however, it took a very
significant amount of time to compute and a large number of searches. We can also
disregard this algorithm.

Next, we looked at Dijkstra. Although this algorithm was computed in a small amount
of time, it required a large number of cells to be searched, so this one can be
ignored too.

Next, we looked at the A-star searches. There are three here; with weights of 1.0,
1.5 and 2.0 for example. Each one found the path optimally, and each had a minimal
path heuristic cost. The number of cells searched decreases as the weighting factor
increases. The reason for this is because the ocean is flat and there is very little
land in the way making for non-straight paths.

Because of how the map is shown, it makes more sense to increase the weighting oif
the Weighted A-star algorithm, as there are no blockages made by the non-passable
terrain. There are a couple of areas where a larger weighting moves the ship
through more shallow water nodes.

Therefore, for THIS PARTICULAR SOLUTION, I have chosen the:
    WEIGHTED A-STAR ALGORITHM, with a WEIGHTING OF 1.5
    
In my Assignment, these are the 'Default' settings that are shown on Start Up and
after pressing 'Restart with Defaults'.


/**************************************************************/


JUSTIFICATION OF COLLISION AVOIDANCE:
Currently, the only 'collision' we have is the ground, acting as non-traversable
terrain. Originally, we set the terrain to have a heuristic value of 999999, which
in theory will be ignored. A better approach would to have a function on the 
grid node class that returns whether or not it can be passable by a ship. If the
terrain is not a water tile, it returns False and this grid node cannot be
accepted to the OPEN list for each search algorithm. I have implemented this
feature to my Assignment.