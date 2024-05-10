#include<stdio.h>
#include<conio.h>
void minmax(int first ,int last ,int a[], int *min, int *max);

void main()
{
    int i,j,a[10],min,max,n;
    printf("Enter the length\n");
    scanf("%d",&n);
    printf("Enter the values of the string\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    minmax(0 ,n-1 ,a,&min,&max);
    printf("The value of max is %d and min is %d",max,min);
    getch();
}

void minmax(int first ,int last ,int a[], int *min, int *max)
{   
    int right_max,right_min,left_min,left_max,mid;
    if(first==last)
    {
        *min=*max=a[first];
    }
    else if(first==last+1)
    {
        if(a[first]>a[last])
        {
            *max = a[first];
            *min = a[last];
        }
        else 
        {
            *max = a[last];
            *min = a[first];
        }
    }
    else
    {
        mid = (first+last)/2;
        minmax(first ,mid ,a,&left_min,&left_max);
        minmax(mid+1 ,last ,a,&right_min,&right_max);
        
        if(left_max > right_max)
        {
            *max=left_max;
        }
        else
        {
            *max=right_max;
        }
        
        if(right_min > left_min)
        {
            *min = left_min;
        }
        else
        {
            *min = right_min;
        }
        
    }
}