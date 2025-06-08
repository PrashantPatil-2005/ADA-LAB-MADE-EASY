#include <stdio.h>
#define MAX 10

int set[MAX], include[MAX], d, n, totalSum = 0;

void sumOfSubsets(int partialSum, int index, int remainingSum) 
{
    include[index] = 1;
    if (partialSum + set[index] == d)
    {
        for (int i = 1; i <= index; i++){
            if (include[i] == 1) printf("%d ", set[i]);
        }
        printf("\n");
    } 



    else if (partialSum + set[index] + set[index + 1] <= d)  sumOfSubsets(partialSum + set[index], index + 1, remainingSum - set[index]);



    if ((partialSum + remainingSum - set[index] >= d) && (partialSum + set[index + 1] <= d))
    {
        include[index] = 0;
        sumOfSubsets(partialSum, index + 1, remainingSum - set[index]);
    }
}

int main() {
    printf("Enter the number of elements (<= %d): ", MAX - 1);
    scanf("%d", &n);

    printf("Enter the set in increasing order:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &set[i]);

    printf("Enter the target sum: ");
    scanf("%d", &d);

    for (int i = 1; i <= n; i++)
        totalSum += set[i];

    if (totalSum < d || set[1] > d)
        printf("No subset possible\n");
    else
        sumOfSubsets(0, 1, totalSum);

    return 0;
}
