#include <stdio.h>

void strassen(int a[2][2], int b[2][2]);

void main() {
    int a[2][2], b[2][2];
    int i, j;

    printf("Enter elements of matrix a:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter a[%d][%d]: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of matrix b:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter b[%d][%d]: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    strassen(a, b);
}

void strassen(int a[][2], int b[][2]) {
    int i,j;
    int p,q,r,s,t,u,v;
    int c[2][2];
    p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    q=(a[1][0]+a[1][1])*b[0][0];
    r=a[0][0]*(b[0][1]-b[1][1]);
    s=a[1][1]*(b[1][0]-b[0][0]);
    t=(a[0][0]+a[0][1])*b[1][1];
    u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
    v=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

    c[0][0]=p+s-t+v;
    c[0][1]=r+t;
    c[1][0]=q+s;
    c[1][1]=p+r-q+u;

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}