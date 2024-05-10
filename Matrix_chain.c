#include <stdio.h>
#include <stdlib.h>                     
#include<conio.h>
int memo[10][10][2] = {0};      


int MatrixChainOrder(int p[], int i, int j) {
    int k;
    int min = 9999;
    int count;
    int k1;
    if (i == j) {
        return 0;
    }
    if (memo[i][j][0] != 0) {
        return memo[i][j][1];
    }
    for (k = i; k < j; k++) {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < min) {
            min = count;
            k1 = k;
        }
    }
    memo[i][j][0] = k1;
    memo[i][j][1] = min;
    return min;
}


void printOptimalParens(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(i, memo[i][j][0]);
        printOptimalParens(memo[i][j][0] + 1, j);
        printf(")");
    }
}

int main() {
    int n, i, j;
    int *p = malloc((n + 1) * sizeof(int));         
    clrscr();
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;                                             
    }

    printf("Enter the dimensions of matrices (including dimensions of result matrix):\n");
    for (i = 0; i <= n; i++) {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }


    printf("The minimum cost matrix is: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j >= i) {
                printf("%d ", MatrixChainOrder(p, i + 1, j + 1));
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

   
    printf("\nThe split points (k-values) matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j >= i) {
                printf("%d ", memo[i+1][j+1][0]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

   
    printf("\nOptimal parenthesization is: ");
    printOptimalParens(1, n);
    printf("\n");

    free(p);       
    getch();
    return 0;
}
