#include <stdio.h>
#include <conio.h> 

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCoins(int coins[], int m, int V) {
    int i, j, p;
    static int table[101][101]; 
    int sol[101];                                       

    
    for (i = 0; i <= m; i++) {
        table[i][0] = 0;
    }
    for (i = 1; i <= V; i++) {
        table[0][i] = V + 1;    
    }

   
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= V; j++) {
            if (coins[i - 1] > j) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - coins[i - 1]]);
            }
        }
    }

   
    printf("Capacity/Coins\t\n");
    printf("\t");
    for (i = 0; i <= V; i++) {
        printf("%4d", i);
    }
    printf("\n");
    for (i = 1; i <= m; i++) {
        printf("%3d\t", coins[i - 1]);
        for (j = 0; j <= V; j++) {
            if (table[i][j] >= V + 1)    
                printf("  INF");
            else
                printf("%4d", table[i][j]);
        }
        printf("\n");
    }

    
    i = m, j = V, p = 0;
    while (j > 0 && i > 0) {
        if (table[i][j] == table[i - 1][j]) {
            i--;
        } else {
            j -= coins[i - 1];
            sol[p++] = coins[i - 1];
        }
    }

    printf("Coins used: ");
    for (i = 0; i < p; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");

    return table[m][V];
}

int main() {
    int coins[100], m, V, i;
    int minCount;
    clrscr();
    printf("Enter the number of coins: ");
    scanf("%d", &m);

    printf("Enter the coins: ");
    for ( i = 0; i < m; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the total amount: ");
    scanf("%d", &V);

    minCount = minCoins(coins, m, V);
    printf("Minimum number of coins required: %d\n", minCount);
    getch();
    return 0;
}
