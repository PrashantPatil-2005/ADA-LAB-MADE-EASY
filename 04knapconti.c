#include <stdio.h>
#define MAX 50

int weights[MAX], profits[MAX], selected[MAX];
int n, capacity;
double maxProfit = 0.0;

void greedyKnapsack() {
    double ratio[MAX];

    for (int i = 0; i < n; i++)
        ratio[i] = (double)profits[i] / weights[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                int tempW = weights[i];
                weights[i] = weights[j];
                weights[j] = tempW;

                int tempP = profits[i];
                profits[i] = profits[j];
                profits[j] = tempP;
            }
        }
    }

    int currWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (currWeight + weights[i] <= capacity) {
            selected[i] = 1;
            currWeight += weights[i];
            maxProfit += profits[i];
        } else {
            selected[i] = (capacity - currWeight) / (double)weights[i];
            maxProfit += selected[i] * profits[i];
            break;
        }
    }

    printf("Maximum Profit: %.2f\n", maxProfit);
    printf("Selection Vector: ");
    for (int i = 0; i < n; i++)
        printf("%d\t", selected[i]);
    printf("\n");
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    printf("Enter profits of items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &profits[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    greedyKnapsack();
    return 0;
}
