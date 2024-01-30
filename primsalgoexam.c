#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

// Structure to represent an edge
struct Edge
{
    int u;      // Vertex 1
    int v;      // Vertex 2
    int weight; // Edge weight
};

// Function to find the vertex with minimum key value
int findMinKeyVertex(int key[], bool mstSet[], int V)
{
    int minKey = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < minKey)
        {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the edges and cost of the minimum spanning tree
void printMinimumSpanningTree(struct Edge mst[], int V)
{
    printf("Minimum Spanning Tree:\n");
    int totalCost = 0;
    for (int i = 1; i < V; i++)
    {
        printf("%d --(%d)-- %d\n", mst[i].u, mst[i].weight, mst[i].v);
        totalCost += mst[i].weight;
    }
    printf("Total Cost: %d\n", totalCost);
}

// Function to implement Prim's algorithm
void prim(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    struct Edge mst[V];
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize key values and mstSet
    for (int v = 0; v < V; v++)
    {
        key[v] = INT_MAX;
        mstSet[v] = false;
    }

    key[0] = 0;     // Start from the first vertex
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinKeyVertex(key, mstSet, V);
        mstSet[u] = true;

        // Update key values and parent index of the adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Populate the minimum spanning tree edges
    for (int i = 1; i < V; i++)
    {
        mst[i].u = parent[i];
        mst[i].v = i;
        mst[i].weight = graph[i][parent[i]];
    }

    printMinimumSpanningTree(mst, V);
}

int main()
{
    int V = 9; // Number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 6, 5, 0, 0, 0, 0, 0},
        {1, 0, 6, 0, 0, 0, 0, 0, 0},
        {6, 6, 0, 0, 7, 3, 0, 0, 0},
        {5, 0, 0, 0, 0, 2, 10, 0, 0},
        {0, 0, 7, 0, 0, 0, 0, 12, 0},
        {0, 0, 3, 2, 0, 0, 0, 8, 0},
        {0, 0, 0, 10, 0, 0, 0, 7, 3},
        {0, 0, 0, 0, 12, 8, 7, 0, 8},
        {0, 0, 0, 0, 0, 0, 3, 8, 0}};
    prim(graph, V);

    return 0;
}
