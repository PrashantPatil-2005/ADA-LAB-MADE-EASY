#include <stdio.h>
#define INF 999

void floyd(int p[][10], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (p[i][k] + p[k][j] < p[i][j])
                    p[i][j] = p[i][k] + p[k][j];
}

int main() {
    int a[10][10],n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    floyd(a, n);

    printf("\nShortest path matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
