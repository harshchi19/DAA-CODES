#include<stdio.h>

void main(){
    int coins[] = {1, 5, 6, 9};
    int sum = 11;
    int n = sizeof(coins) / sizeof(coins[0]);
    int m = sum;
    int i, j, a[n+1][m+1]; 

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= sum; j++) {
            if (j == 0) {
                a[i][j] = 1; 
            } else if (i == 0) {
                a[i][j] = 0; 
            } else if (coins[i - 1] > j) {
                a[i][j] = a[i - 1][j]; 
            } else {
                a[i][j] = a[i - 1][j] + a[i][j - coins[i - 1]];
            }
        }
    }
    printf("There are total %d number of ways ", a[n+1][m+1]);
}
