#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int));

    // Fill array with random values
    for(int i = 0; i < N; i++) {
        arr[i] = rand() % 10000; // You can increase range for more randomness
    }

    // Measure time
    clock_t start, end;
    start = clock();

    mergeSort(arr, 0, N - 1);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    printArray(arr, N);

    printf("Time taken to sort %d elements: %f seconds\n", N, time_taken);

    free(arr);
    return 0;
}

