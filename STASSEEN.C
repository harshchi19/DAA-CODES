#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void multiply(int A[][2], int B[][2], int C[][2]) {
    int i, j, k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void optimize_multiply(int A[][2], int B[][2], int D[][2]) {
    int P1 = A[0][0] * (B[0][1] - B[1][1]);
    int P2 = (A[0][0] + A[0][1]) * B[1][1];
    int P3 = (A[1][0] + A[1][1]) * B[0][0];
    int P4 = A[1][1] * (B[1][0] - B[0][0]);
    int P5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int P6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    int P7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);
    D[0][0] = P5 + P4 - P2 + P6;
    D[0][1] = P1 + P2;
    D[1][0] = P3 + P4;
    D[1][1] = P5 + P1 - P3 - P7;
}
int main() {
    int i,j;
    int A[2][2], B[2][2], C[2][2], D[2][2];
    clrscr();
    printf("Enter the elements of Matrix A:\n");
    for ( i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter the elements of Matrix B:\n");
    for ( i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    printf("Entered Matrix A is:\n");
    for ( i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("Entered Matrix B is:\n");
    for ( i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
    multiply(A, B, C);
    printf("Resultant Matrix is:\n");
    for ( i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    optimize_multiply(A, B, D);
    printf("Optimized Resultant Matrix is:\n");
    for ( i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    getch();
    return 0;
}
