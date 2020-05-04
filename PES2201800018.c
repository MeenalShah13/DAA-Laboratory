#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"tsp.h"

int tspBacktrackRecursive(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int minCost)
{
	if(currentCost>minCost)
		return minCost;
	if(nodesVisited==n-1)
	{
		currentCost+=graph[v][0];
		return (currentCost<minCost)?currentCost:minCost;
	}
	nodesVisited++;
	visited[v]=1;
	int i;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			minCost=tspBacktrackRecursive(i, n, graph, visited, nodesVisited, currentCost+graph[v][i], minCost);
		
	}
	nodesVisited--;
	visited[v]=0;
	return minCost;
}

int tspBackTrack(int n, int graph[][n])
{
	bool *visited=(bool *)calloc(n,sizeof(int));
	return tspBacktrackRecursive(0, n, graph, visited, 0, 0, __INT_MAX__);
}

static void pathFinder(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int *minCost, int *currentPath, int *minPath)
{
    if (currentCost > *minCost)
        return;
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