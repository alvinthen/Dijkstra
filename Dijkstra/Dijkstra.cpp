// Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define V 9
int minDistance(int dist[], bool shortest[])
{
	int min = 999, min_index;

	for (int v = 0; v < 9; v++)
	{
		if (shortest[v] == false && dist[v] <= min)
		{
			min = dist[v], min_index = v;
		}
	}

	return min_index;
}

void printSolution(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[9][9], int src)
{
	int dist[V];
	bool shortestPath[V];

	for (int i = 0; i < V; i++)
	{
		dist[i] = 9999, shortestPath[i] = false;
	}

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, shortestPath);

		shortestPath[u] = true;

		for (int v = 0; v < V; v++)
		{
			if (!shortestPath[v] && graph[u][v] && dist[u] != 9999
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}

	printSolution(dist, V);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	dijkstra(graph, 0);
	getchar();
	return 0;
}

