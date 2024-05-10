#include<stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void main() {
    int coins[] = {1, 5, 6, 9};
    int sum = 11;
    int n = sizeof(coins) / sizeof(coins[0]);
    int m = sum;
    int i, j, a[n + 1][m + 1]; 

    for(i = 0; i <= n; i++) {
        a[i][0] = 0;
    }

    for(j = 0; j <= m; j++) {
        a[0][j] = 999999;
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(coins[i - 1] > j) {
                a[i][j] = a[i - 1][j];
            } else {
                a[i][j] = min(a[i - 1][j], 1 + a[i][j - coins[i - 1]]);
            }
        }
    }
    printf("%d coins are minimum required\n", a[n][m]);
}
