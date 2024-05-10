#include <stdio.h>

void minmax(int first, int last, int *min, int *max);

int arr[] = {9, 6, 4, 7, 10, 14, 8, 11};

int main() {
    int min, max;
    minmax(0, sizeof(arr) / sizeof(arr[0]) - 1, &min, &max);
    printf("The min value is %d and max value is %d", min, max);
    return 0;
}

void minmax(int first, int last, int *min, int *max) {
    if (first == last) {
        *max = *min = arr[first];
    } else if (first == last + 1) {
        if (arr[first] > arr[last]) {
            *max = arr[first];
            *min = arr[last];
        } else {
            *max = arr[last];
            *min = arr[first];
        }
    } else {
        int mid = (first + last) / 2;
        int left_min, left_max, right_min, right_max;
        minmax(first, mid, &left_min, &left_max);
        minmax(mid + 1, last, &right_min, &right_max);

        *min = (left_min < right_min) ? left_min : right_min;
        *max = (left_max > right_max) ? left_max : right_max;
    }
}
