#include <stdio.h>
#include <limits.h>

#define V_MAX 100
#define INF 99999

int V;                             // Number of vertices
int graph[V_MAX][V_MAX];          // Adjacency matrix
int parent[V_MAX];                // Stores MST
int key[V_MAX];                   // Key values to pick minimum weight edge
int mstSet[V_MAX];                // Track vertices included in MST

// Function to find vertex with the minimum key not yet included in MST
int minKey() {
    int min = INF, minIndex = -1;
    for (int v = 1; v <= V; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    return minIndex;
}

// Function to print the MST
void printMST() {
    int totalCost = 0;
    printf("\nEdge\tWeight\n");
    for (int i = 2; i <= V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);
}

// Prim's Algorithm implementation
void primMST() {
    for (int i = 1; i <= V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[1] = 0;         // Start from vertex 1
    parent[1] = -1;     // First node has no parent

    for (int count = 1; count < V; count++) {
        int u = minKey();
        mstSet[u] = 1;

        for (int v = 1; v <= V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST();
}

int main() {
    int E, u, v, w;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V > V_MAX || V <= 0) {
        printf("Error: Vertex count must be between 1 and %d.\n", V_MAX);
        return 1;
    }

    // Initialize graph with 0s
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v weight), vertices numbered from 1 to %d:\n", V);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        if (u < 1 || v < 1 || u > V || v > V) {
            printf("Invalid edge: vertices must be in range 1 to %d.\n", V);
            i--; // Re-enter this edge
            continue;
        }
        graph[u][v] = graph[v][u] = w;
    }

    primMST();
    return 0;
}
