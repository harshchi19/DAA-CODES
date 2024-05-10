#include <stdio.h>
#include <conio.h>           

void sortCoins(int coins[], int m) {
    int i ;
    
    for ( i = 1; i < m; i++) {
        int key = coins[i];
        int j = i - 1;
        while (j >= 0 && coins[j] < key) {
            coins[j + 1] = coins[j];
            j = j - 1;
        }
        coins[j + 1] = key;
    }
}

int minCoinsGreedy(int coins[], int m, int V) {
    int count , i ;
    sortCoins(coins, m);       
    count = 0;
    printf("Coins used: ");
    for ( i = 0; i < m; i++) {
        while (V >= coins[i]) {
            V -= coins[i];
            printf("%d ", coins[i]);           
            count++;                               
        }
        if (V == 0) break;                
    }
    printf("\n");
    return count;    
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

    minCount = minCoinsGreedy(coins, m, V);
    printf("Minimum number of coins required using greedy approach: %d\n", minCount);
    getch();
    return 0;
}
