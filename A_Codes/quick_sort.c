#include <stdio.h>

void quicksort(int arr[], int first, int last);
int partition(int arr[], int first, int last);

int main() {
    int arr[] = {9, 6, 4, 7, 10, 14, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        quicksort(arr, first, pivot - 1);
        quicksort(arr, pivot + 1, last);
    }
}

int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[last];
    arr[last] = temp;

    return i + 1;
}
