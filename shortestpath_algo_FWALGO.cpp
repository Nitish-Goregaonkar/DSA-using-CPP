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

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices */
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above-picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

/* A utility function to print the solution */
void printSolution(int dist[][V]) {
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF "
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

// Driver code
int main() {
    /* Let us create the following weighted graph
          10
      (0)------>(3)
       |       /|\
      5|      | |
       |      | | 1
       |     \|/
      (1)----->(2)
          3        */
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph);
    return 0;
}
