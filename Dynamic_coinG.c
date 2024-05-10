#include <stdio.h>
#include <conio.h>
void minCoins(int coins[], int no_coins, int amount);
int min(int a, int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main() { 
    int coins[100], no_coins, amount; 
    printf("Enter the number of coins: "); 
    scanf("%d", &no_coins); 
    printf("Enter the coins: "); 
    for (int i = 0; i < no_coins; i++) { 
        scanf("%d", &coins[i]); 
    } 
    printf("Enter the total amount: "); 
    scanf("%d", &amount); 
    minCoins(coins, no_coins, amount); 
    return 0;
} 
//Same as 0/1 Knapsack 
//Instead of weight use coins 
//Instead of capacity use amount

void minCoins(int coins[], int no_coins, int amount)
{
    int table[50][50];
    int i,j;
    int sol[50];
    //Since we are adding one extra row and column we will be going till n and cap and not n-1 and cap-1
    //Making the initial column 0
    for(i = 0; i <= no_coins; i++)
    {
        table[i][0] = 0;
    }
    //Making the initial row 0
    for(j = 0; j <= amount; j++)
    {
        //Replace 0 with j
        table[0][j] = j;
    }
    
     //Applying the formula 
     for (int i = 1; i <= no_coins; i++) { 
        for (int j = 1; j <= amount; j++) { 
            if (coins[i - 1] > j) 
                table[i][j] = table[i - 1][j]; 
            else 
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - coins[i - 1]]); 
        } 
     }
    //For table display
    for (i = 1; i <= no_coins; i++)
    {
        
        for(j = 0; j <= amount; j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    
    i=no_coins;
    j=amount;
    int p=0;
    while(j > 0)
    {
        if(table[i][j]==table[i-1][j])
        {
            i=i-1;
        }
        else
        {
            j=j-coins[i-1];
            sol[p]=coins[i-1];
            p++;
        }
    }
    printf("Coins Used are:");
    
    for(int k = 0; k < p; k++)
    {
        printf("%d ",sol[k]);
    }
    printf("\n");
    printf("Minimum Coins required are %d",table[no_coins][amount]);
}

