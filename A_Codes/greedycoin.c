#include <stdio.h>

void greedy(int coin[], int sum, int n);

void main() {
    int coin[] = {10, 5, 6, 1};
    int sum = 12;
    int n = sizeof(coin) / sizeof(coin[0]);
    greedy(coin, sum, n);
}

void greedy(int coin[], int sum, int n) {
    int i, j, temp;

    // Sort the coins in descending order
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (coin[j] < coin[j + 1]) {
                temp = coin[j];
                coin[j] = coin[j + 1];
                coin[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        while (coin[i] <= sum) {
            printf("%d ", coin[i]);
            sum = sum - coin[i];
        }
    }
}