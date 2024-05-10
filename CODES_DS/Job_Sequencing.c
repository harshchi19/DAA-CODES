                                    // Job Sequencing

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,j,temp,temp1,temp2,max = 0,max_profit = 0;
    printf("Enter the number of jobs :");
    scanf("%d",&n);

    int jobs[n],deadline[n],profit[n];
    printf("Enter the Profit and Deadline for each job\n");
    for(i=0;i<n;i++){
        printf("Profit of Job %d :",i+1);
        scanf("%d",&profit[i]);
        printf("Deadline of Job %d :",i+1);
        scanf("%d",&deadline[i]);
        jobs[i] = i+1;
        //Find the value of maximum deadline
        if(max < deadline[i]){
            max = deadline[i];
        }
    }

    // Sort All the Jobs in Decreasing Order of their Profit
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(profit[j] < profit[j+1]){

                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                temp1 = deadline[j];
                deadline[j] = deadline[j+1];
                deadline[j+1] = temp1;

                temp2 = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp2;
            }
        }        
    }

    int chart[max],m;
    for(i= 0;i<n;i++){
        chart[i] = 0;
    }

    for(i = 0 ;i< n;i++){
        m = deadline[i];
        if(chart[m-1] == 0){
            chart[m-1] = jobs[i];
            max_profit = max_profit + profit[i]; 
        }
        else{
            for(j = m-1; j >= 0;j--){
                if(chart[j] == 0){
                    chart[j] = jobs[i];
                    max_profit = max_profit + profit[i];
                    break;
                }
            }
        }
    }
     
    printf("Selected Jobs are :");
    for(i = 0;i<n;i++){
        if(chart[i] != 0){
            printf("J%d ",chart[i]);
        }
    }
    printf("\nMaximum Profit : %d",max_profit);
}