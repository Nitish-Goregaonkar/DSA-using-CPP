#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4
/* Define Infinite as a large enough value.
   This value will be used for vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    