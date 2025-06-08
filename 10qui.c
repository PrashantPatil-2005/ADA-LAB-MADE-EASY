#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000  // You can change this as needed

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[MAX_SIZE]; int n;
    printf("Enter number of elements (<= %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: Number exceeds maximum allowed (%d).\n", MAX_SIZE);
        return 1;
    }



    // Generate random numbers
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    // Sort and calculate time
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d numbers: %f seconds\n", n, time_taken);

    return 0;
}
