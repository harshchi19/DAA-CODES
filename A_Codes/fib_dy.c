#include<stdio.h>
#include<conio.h>

    int n = 6;
    int fib[6];

void fibdy(int n);
int fibna(int n);

void main(){
    int ans;
    fibdy(n);
    ans=fibna(n);
    printf("The 6th fib number from recurssion is %d",ans);
}

void fibdy(int n){
    int i;
    fib[0]=0;
    fib[1]=1;
    for(i=2;i<=n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    printf("The 6th fib number is %d\n",fib[n]);
}

int fibna(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibna(n-1)+fibna(n-2);
    n--;
}