#include <stdio.h>

void activ(int start[], int finish[], int n);

void main() {
    int start[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finish[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n = sizeof(finish) / sizeof(finish[0]);
    activ(start, finish, n);
}

void activ(int start[], int finish[], int n) {
    int i, j;
    int selected[n];
    int last_finish = -1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int temp_finish = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp_finish;
                int temp_start = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp_start;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (start[i] >= last_finish) {
            selected[i] = 1;
            last_finish = finish[i];
        }
        else{
            selected[i] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", selected[i]);
    }
}