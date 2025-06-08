#include <stdio.h>

void warshall(int p[][10], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
}

int main() {
    int a[10][10], n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++)
            scanf("%d", &a[i][j]);

    warshall(a, n);

    printf("Resultant path matrix (transitive closure):\n");
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
