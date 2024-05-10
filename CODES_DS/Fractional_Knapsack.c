                                        //Fractional Knapsack 
//For the DHS JCT
//BY the DHS JCT
//OF the DHS JCT

#include<stdio.h>
#include<stdlib.h>

int main(){

    //Input

    int n,i,j,capacity;
    printf("Enter the number of items:");
    scanf("%d",&n);

    printf("Enter the capacity :");
    scanf("%d",&capacity);

    float profit[n],weight[n];
    float ratio[n];

    printf("Enter the Profit and Weight of each item respectively :\n");
    for(i=0;i<n;i++){
        printf("Profit of Item %d :",i+1);
        scanf("%f",&profit[i]);
        printf("Weight of Item %d :",i+1);
        scanf("%f",&weight[i]);
    }

    //Calculate Profit By Weight Ratio

    for(i=0;i<n;i++){
        ratio[i] = profit[i]/weight[i];
    }

    //Sorting the items based on p/w ratio
    int temp1,temp2;
    float temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(ratio[j] < ratio[j+1]){

               temp = ratio[j];
               ratio[j] = ratio[j+1];
               ratio[j+1] = temp;

               temp1 = profit[j];
               profit[j] = profit[j+1];
               profit[j+1] = temp1;

               temp2 = weight[j];
               weight[j] = weight[j+1];
               weight[j+1] = temp2; 
            }
        }
    }
    
    //Fractional Knapsack Begins

    float knapsack[n];
    for(i = 0;i<n;i++){
        if(weight[i] <= capacity && capacity != 0){
            capacity = capacity - weight[i];
            knapsack[i] = 1;
        }
        
        else if(weight[i] > capacity && capacity != 0){
            knapsack[i] = capacity/weight[i];
            capacity = 0;
        }

        else{
            knapsack[i] = 0;
        }
    }
    
    //Calculating Max Profit

    float sum = 0;
    for(i = 0;i < n;i++){
        sum = sum + (profit[i]*knapsack[i]);
    }
    
    printf("Max Profit : %.2f",sum);
}