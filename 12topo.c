#include <stdio.h>

#define MAX 100

int V, E;
int adj[MAX][MAX];       // Adjacency matrix
int inDegree[MAX];       // In-degree of each vertex
int queue[MAX];          // Queue for processing nodes

void topologicalSort() {
    int front = 0, rear = -1;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            queue[++rear] = i;
    }

    // Process the queue
    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    printf("\n");
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix and in-degree array
    for (int i = 0; i < V; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        inDegree[dest]++;
    }

    topologicalSort();

    return 0;
}
