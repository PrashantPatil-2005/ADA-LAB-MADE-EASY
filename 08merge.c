#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void merge(int arr[], int left, int mid, int right) {
    int temp[MAX];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[MAX];
    int n;

    printf("Enter number of elements (up to %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Limit exceeded. Max allowed is %d.\n", MAX);
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d numbers: %f seconds\n", n, time_taken);

    return 0;
}

