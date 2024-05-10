#include<stdio.h>
#include<conio.h>

int max(int a , int b){
    int result;
    result = (a>b)?a:b;
    return result;
}

void main(){
    int cap=8;
    int w[]={3,4,5,6};
    int p[]={2,3,4,1};
    int n=4;
    int i,j;
    int a[n+1][cap+1];

    for(i=0;i<=n;i++){
        a[i][0] = 0;
    }

    for(j=0;j<=cap;j++){
        a[0][j] = 0;
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=cap;j++){
            if(w[i-1]>j){
                a[i][j]=a[i-1][j];
            }
            else{
                a[i][j] = max(a[i-1][j] , p[i-1]+a[i-1][j-w[i-1]]);
            }
        }
    }
    printf("The max profit is %d",a[n][cap]);
}