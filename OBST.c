#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
int **memo;                

int sum(int freq[], int i, int j) {
    int s = 0,k;
    for (k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int OBST(int freq[], int i, int j) {
    int min,fsum,r;
    if (j < i)                      
        return 0;
    if (j == i)                       
        return freq[i];

    if (memo[i][j] != INT_MAX)
        return memo[i][j];

    fsum = sum(freq, i, j);
    min = INT_MAX;

    for ( r = i; r <= j; r++) {
        int cost = OBST(freq, i, r - 1) + OBST(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }

    memo[i][j] = min + fsum;
    return memo[i][j];
}

int main() {
    int n, *keys, *freq, i, j,cost;
    clrscr();
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    keys = (int*)malloc(n * sizeof(int));
    freq = (int*)malloc(n * sizeof(int));
    memo = (int**)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++) {
        memo[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            memo[i][j] = INT_MAX;                 
        }
    }

    printf("Enter the keys: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &keys[i]);           
    }

    printf("Enter the frequencies: ");
    for (i = 0; i < n; i++) { 
        scanf("%d", &freq[i]);           
    }

    cost = OBST(freq, 0, n - 1);
    printf("Cost of Optimal BST is %d\n", cost);

  
    for (i = 0; i < n; i++) {
        free(memo[i]);
    }
    free(memo);
    free(keys);
    free(freq);
    getch();
    return 0;
}
