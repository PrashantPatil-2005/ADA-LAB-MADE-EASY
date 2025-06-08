#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000

typedef struct {
    int src, dest, weight;
} Edge;

int parent[MAX_EDGES];  // Stores the parent of each node

// Function to find parent of a node (with path compression)
int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

// Simple union function (without rank)
void Union(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    parent[xRoot] = yRoot;
}

// Comparator for qsort - sorts by edge weight
int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*) a;
    Edge* e2 = (Edge*) b;
    return (e1->weight) - (e2->weight);
}

int main() {
    int V, E;
    Edge edges[MAX_EDGES];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Initialize parent of each node to itself
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), compare);

    printf("Minimum Spanning Tree:\n");
    int mstWeight = 0;
    int count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            printf("(%d, %d) -> %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            Union(u, v);
            count++;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
    return 0;
}
