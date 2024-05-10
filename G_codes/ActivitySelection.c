#include<stdio.h>
void activitySelection(int start[], int finish[], int n);

int main()
{
    int start[] = {1,0,1,4,2,5,3,4};
    int finish[] = {3,4,2,6,9,8,5,5};
    int n;
    n = sizeof(finish)/sizeof(finish[0]);
    activitySelection(start, finish, n);
    return 0;
}
void activitySelection(int start[], int finish[], int n)
{
    int i,j,task[50],activity[50],temp,count;
    for (i = 0; i < n; i++)
    {
        task[i]=i+1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(finish[j] > finish[j+1])
            {
                temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;
                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
                temp = task[j];
                task[j] = task[j+1];
                task[j+1] = temp;

            }
        }
    }
    activity[0] = task[0];
    i = 0;
    count = 1;
    for(j = 1; j < n; j++)
    {
        if(start[j]>=finish[i])
        {
            activity[count++] = task[j];
            i=j;
        }
    }
    printf("Selected Activity:");
    for(i = 0; i < n; i++)
    {   
        if(activity[i]!=0)
        {
            printf(" %d ",activity[i]);
        }
            
    }
    
}
