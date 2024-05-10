                      //0/1 knapsack Problem

#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int n,capacity;
    printf("Enter the number of items :");
    scanf("%d",&n);
    printf("Enter the capacity:");
    scanf("%d",&capacity);
    int weight[n],profit[n],items[n],selected[n],m[n+1][capacity+1];
    printf("Enter the profit and weights of items\n");
    for(int i = 0;i<n;i++){
        printf("Enter the profit of %d item :",i+1);
        scanf("%d",&profit[i]);
        printf("Enter the weight of %d item :",i+1);
        scanf("%d",&weight[i]);
        printf("\n");
        items[i] = i+1;
    }
    
    for(int j = 0;j < n - 1;j++){
        for(int i = 0;i < n - i - 1 ;i++){
            if(weight[i] > weight [i+1]){
                int temp = weight[i];
                weight[i] = weight[i+1];
                weight[i+1] = temp;

                int temp1 = profit[i];
                profit[i] = profit[i+1];
                profit[i+1] = temp1;
                
                int temp2 = items[i];
                items[i] = items[i+1];
                items[i+1] = temp2;
            }
        }
    }
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= capacity;j++){
            if( i == 0 || j == 0){
                m[i][j] = 0;
            }

            else if(j < weight[i-1]){
                m[i][j] = m[i-1][j];
            }
            else{
                m[i][j] = max(m[i-1][j],m[i-1][j-weight[i-1]] + profit[i - 1]);
            }
        }
    }
    
    printf("\nMatrix m:\n");
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit :%d",m[n][capacity]);
    
    int i = n;
    int j = capacity;
    
    while(i > 0 && j > 0){
        if(m[i][j] != m[i-1][j]){
            selected[i-1] = 1;
            j = j - weight[i-1];
        }
        else{
            selected[i-1] = 0;
        }
        i--;
    }
    
    printf("\nItems\tSelection\n");
    for(int i = 0;i < n;i++){
        printf("%d\t\t%d",items[i],selected[i]);
        printf("\n");
    }
    
}