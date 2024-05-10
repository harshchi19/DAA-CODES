#include<stdio.h>
#include<stdlib.h>

int min = __INT16_MAX__;
int max = 0;

void Divide_Conquer(int a[], int i, int j, int *min, int *max);

void Divide_Conquer(int a[], int i, int j, int *min, int *max) {
    int mid, min1, max1;

    if (i == j) {
        *min = a[i];
        *max = a[i];
    } else if (i == j - 1) {
        if (a[i] > a[j]) {
            *min = a[j];
            *max = a[i];
        } else {
            *min = a[i];
            *max = a[j];
        }
    } else {
        mid = (i + j) / 2;
        Divide_Conquer(a, i, mid, min, max);
        min1 = *min;
        max1 = *max;
        Divide_Conquer(a, mid + 1, j, min, max);
        if (min1 < *min) {
            *min = min1;
        }
        if (max1 > *max) {
            *max = max1;
        }
    }
}

int main() {
    int n, range, i, sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    average = (float) sum / n;

    i = 0;
    int j = n - 1;

    Divide_Conquer(a, i, j, &min, &max);

    printf("\nMinimum Element: %d", min);
    printf("\nMaximum Element: %d", max);
    printf("\nAverage: %.2f", average); // %.2f to print average up to 2 decimal places
    range = max - min;
    printf("\nRange: %d\n", range);

    return 0;
}
