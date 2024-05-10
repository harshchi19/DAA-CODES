                                //Activity Selection Problem
//For the DHS JCT
//BY the DHS JCT
//OF the DHS JCT

#include<stdio.h>
#include<stdio.h>

int main(){
    int n,i,j,temp,temp1,temp2;
    printf("Enter the number of activities :");
    scanf("%d",&n);

    int start[n],finish[n];
    char task[n],activity[n];
    printf("Enter the start time of %d activities : ",n);
    for(i = 0;i < n;i++){
        scanf("%d",&start[i]);
        task[i] = i+1;
    }
    printf("Entre the finish time of %d activities : ",n);
    for(i = 0;i < n;i++){
        scanf("%d",&finish[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(finish[j] > finish[j+1]){

                temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;

                temp1 = start[j];
                start[j] = start[j+1];
                start[j+1] = temp1;

                temp2 = task[j];
                task[j] = task[j+1];
                task[j+1] = temp2;
            }
        }
    }
    
    activity[0] = task[0];
    i = 0;
    int count = 1;
    for(j = 1;j < n;j++){
        if(finish[i] <= start[j]){
            activity[count++] = task[j];
            i=j;
        }
    }

    printf("Selected Tasks are :");
    for(i=0;i<count;i++){
        printf("A%d ",activity[i]);
    } 
}

