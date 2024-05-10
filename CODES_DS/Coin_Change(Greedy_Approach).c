                             //Coin Change Using Greedy Approach

#include<stdio.h>
#include<stdlib.h>

int main(){
    int sum = 0,n,i,j,amount,temp;
    printf("Enter the number of denominations :");
    scanf("%d",&n);
    int coins[n],select[100];
    printf("\nEnter the coins:");
    for(i = 0;i < n;i++){
        scanf("%d",&coins[i]);
    }
    printf("\nEnter the amount:");
    scanf("%d",&amount);
    
    for(i = 0;i<n-1;i++){
        for(j = 0;j<n-i-1;j++){
            if(coins[j] < coins[j+1]){
                temp = coins[j];
                coins[j] = coins[j+1];
                coins[j+1] = temp;
            }
        }
    }

    i = 0;
    j = 0;

    while(sum != amount){
        if(sum + coins[i] <= amount){
            sum = sum + coins[i];
            select[j++] = coins[i];   
        }
        else{
            i++;
        }
    }

    printf("\nSelected Coins are :");
    for(i = 0 ; i < j ; i++){
        printf("%d ",select[i]);
    }
}