#include<stdio.h>

int min(int a , int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

void fw(int m[10][10] , int n){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                m[i][j] = min(m[i][j],m[i][k]+m[k][j]);
            }
        }
    }
}

void main(){
    int i,j,m[10][10],n;

    m[1][1]=0;
    m[1][2]=9;
    m[1][3]=-4;
    m[1][4]=999;
    m[2][1]=6;
    m[2][2]=0;
    m[2][3]=999;
    m[2][4]=2;
    m[3][1]=999;
    m[3][2]=5;
    m[3][3]=0;
    m[3][4]=999;
    m[4][1]=999;
    m[4][2]=999;
    m[4][3]=1;
    m[4][4]=0;

    n=4;
    fw(m,n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}