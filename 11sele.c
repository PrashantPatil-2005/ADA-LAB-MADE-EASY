#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000  // Maximum number of elements

// Selection Sort function
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    // Ask for number of elements
    printf("Enter the number of elements (<= %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Fill array with random numbers
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;  // Random number between 0 and 9999
    }

    // Measure sorting time
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    return 0;
}
