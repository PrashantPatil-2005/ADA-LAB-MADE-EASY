#include <stdio.h>
#define INF 999
int c[10][10];
int d[10];
int s;
int n;

void dijkstra()
{
    int v[10], min, u;

    // Initialize distance array 'd' with direct distances from source 's'
    // and mark all nodes as unvisited (v[i] = 0)
    for (int i = 1; i <= n; i++) {
        d[i] = c[s][i];  // Distance from source to i
        v[i] = 0;        // Mark all nodes unvisited
    }

    v[s] = 1;  // Mark the source node as visited

    // Repeat for (n - 1) nodes
    for (int i = 1; i <= n - 1; i++) 
    {
        min = INF;  // Set minimum to a large number initially

        // Find the unvisited node with the smallest distance
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] < min) {
                min = d[j];
                u = j;  // 'u' will be the node with minimum distance
            }
        }

        v[u] = 1;  // Mark the selected node 'u' as visited

        // Update distances of unvisited neighbors of 'u'
        for (int j = 1; j <= n; j++) 
            if (!v[j] && d[u] + c[u][j] < d[j]) 
                d[j] = d[u] + c[u][j];  // Update if shorter path is found     
    }
}


int main() {
    printf("Enter n value: ");
    scanf("%d", &n);

    printf("Enter the graph data:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &s);

    dijkstra();

    for (int i = 1; i <= n; i++)
        printf("Shortest distance from %d to %d is %d\n", s, i, d[i]);

    return 0;
}
