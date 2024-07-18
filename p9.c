#include <stdio.h>
#include <time.h>

#define V 4  // Number of vertices in the graph

// Function to print the transitive closure matrix
void printMatrix(int reach[V][V]) {
    printf("Transitive closure matrix is:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Warshall's algorithm
void warshall(int graph[V][V]) {
    int reach[V][V];
    int i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above-picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on a path from i to j, then make sure that the value of reach[i][j] is 1
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print the transitive closure of the given graph
    printMatrix(reach);
}

int main() {
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 0},
                        {0, 0, 1, 1} };

    clock_t start, end;

    // Start time
    start = clock();

    // Execute Warshall's algorithm
    warshall(graph);

    // End time
    end = clock();

    // Calculate time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to find transitive closure: %f seconds\n", time_taken);

    return 0;
}