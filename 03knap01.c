#include <stdio.h>

int w[10], p[10], n;

int max(int a, int b) {
    return a > b ? a : b;
}

int knap(int i, int m) {
    if (i > n) return 0; // Fix: array starts at index 1
    if (w[i] > m) return knap(i + 1, m);
    return max(knap(i + 1, m), knap(i + 1, m - w[i]) + p[i]);
}

int main() {
    int m;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    
    printf("Enter the knapsack capacity: ");
    scanf("%d", &m);


    printf("Enter profit and weight for each object:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &p[i], &w[i]);


    int max_profit = knap(1, m);
    printf("Maximum profit = %d\n", max_profit);

    return 0;
}
