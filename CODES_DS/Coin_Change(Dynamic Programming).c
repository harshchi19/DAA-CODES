#include<stdio.h>
#include<stdlib.h>

int min(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int main() {
    int n, amount, i, j, p = 0, sol[100];
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    printf("Enter the amount: ");
    scanf("%d", &amount);
    int coins[n], a[n][amount + 1];
    printf("Enter the coins: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j <= amount; j++) {
            if (j == 0) {
                a[i][j] = 0;
            } else if (i == 0 && j >= coins[i]) {
                a[i][j] = 1 + a[i][j - coins[i]];
            } else if (i > 0 && j >= coins[i]) {
                a[i][j] = min(a[i - 1][j], 1 + a[i][j - coins[i]]);
            } else {
                a[i][j] = a[i - 1][j];
            }
        }
    }
    
    i = n - 1; 
    j = amount;
    while (j > 0) {
        if (a[i][j] == a[i - 1][j]) {
            i--;
        } else {
            sol[p++] = coins[i];
            j -= coins[i];
        }
    }

    printf("Minimum coins required: %d", a[n - 1][amount]);
    printf("\nSelected Coins :");
    for (i = 0; i < p; i++) {
        printf("%d ", sol[i]);
    }

    return 0;
}
