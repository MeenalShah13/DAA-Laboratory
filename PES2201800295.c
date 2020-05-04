#include "tsp.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int min(int x, int y)
{
    return (x < y) ? x : y;
}

/**
 * Starting from node 0 recurisivly compute and return the minimum cost.*
 * graph[i][j] is the cost moving from node i to node j.*
 * At every function call currentCost contains the cost of the path traversed till now,*
 * nodesVisited is the number of visited nodes in the current path.*
 * When a path is completed commpare its cost to mincost, return minimum of both, backtrack*
 * and compute the costs of the other paths, return the minimum of all of them.*
 * If at any stage the currentCost becomes greater than the mincost backtrack from that point.
 */
int tspBacktrackRecursive(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int minCost)
{
    // if currentCost becomes greater than minCost, backtrack
    if (currentCost > minCost)
        return minCost;

    // when a path is completed
    if (nodesVisited == n)
    {
        currentCost += graph[v][0];
        minCost = min(currentCost, minCost);
        return minCost;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) // don't check for the condition graph[v][i] != 0 since the question considers paths where distance b/w nodes = 0
        {
            visited[i] = true;
            minCost = tspBacktrackRecursive(i, n, graph, visited, nodesVisited + 1, currentCost + graph[v][i], minCost);
            visited[i] = false;
        }
    }
    return minCost;
}

/**
 * Compute the minimum cost required to visit all nodes using the tspBacktrackRecursive() function 
 */
int tspBackTrack(int n, int graph[][n])
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    visited[0] = true;
    return tspBacktrackRecursive(0, n, graph, visited, 1, 0, __INT_MAX__);
}

static void pathFinder(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int *minCost, int *currentPath, int *minPath)
{
    // if currentCost is greater than minCost, backtrack
    if (currentCost > *minCost)
        return;
    
    // when a path is completed
    if (nodesVisited == n)
    {
        if (graph[v][0] == 0)
            return;
        currentCost += graph[v][0];
        if (currentCost < *minCost)
        {
            *minCost = currentCost;
            for (int i = 0; i < n; i++) 
                minPath[i] = currentPath[i];
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) // don't include graph[v][i] != 0
        {
            visited[i] = true;
            currentPath[nodesVisited] = i;
            pathFinder(i, n, graph, visited, nodesVisited + 1, currentCost + graph[v][i], minCost, currentPath, minPath);
            visited[i] = false;
        }
    }
}

/**
 * Print the minimum cost path, you use a static function similar to tspBacktrackRecursive()
 */
int *printPath(int n, int graph[][n])
{
    int *currentPath = calloc(n, sizeof(int));
    int *minPath = calloc(n, sizeof(int));
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int minCost = __INT_MAX__;
    visited[0] = true;
    pathFinder(0, n, graph, visited, 1, 0, &minCost, currentPath, minPath);
    free(currentPath);
    return minPath;
}