#include <stdio.h>

void merge(int arr[], int first, int mid, int last);
void mergesort(int arr[], int first, int last);

int main() {
    int arr[] = {9, 6, 4, 7, 10, 14, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergesort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void merge(int arr[], int first, int mid, int last) {
    int n1 = mid - first + 1;
    int n2 = last - mid;

    int Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[first + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = first;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;

        mergesort(arr, first, mid);
        mergesort(arr, mid + 1, last);

        merge(arr, first, mid, last);
    }
}
