#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesis of matrix multiplication
void printOptimalParenthesis(int i, int j, int n, int *bracket, char name) {
    if (i == j) {
        printf("%c%d", name, i);
        return;
    }
    printf("(");
    printOptimalParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
    printOptimalParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    printf(")");
}

// Function to find the minimum number of scalar multiplications needed to multiply the chain of matrices
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n - 1, n, (int *)bracket, 'A');
    printf("\n");
    return m[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices:");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the dimensions :");
    for(int i=0;i<n+1;i++){
        scanf("%d",&arr[i]);
    }
    matrixChainOrder(arr, n+1);
    return 0;
}
