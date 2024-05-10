#include <stdio.h>
#include <conio.h>
void fractional(int cap, int w[], int p[], int n);
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void main()
{
    int cap=8;
    int w[]={3,5,4,6};
    int p[]={2,4,3,1};
    int temp_w,temp_p,i,j;
    int n = 4;
    
    // Sorting them according to the weight in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(w[j]>w[j+1])
            {
                temp_w=w[j];
                w[j]=w[j+1];
                w[j+1]=temp_w;
                temp_p=p[j];
                p[j]=p[j+1];
                p[j+1]=temp_p;
            }
        }
    }
    
    fractional(cap, w, p, n);
    getch();
}

void fractional(int cap, int w[], int p[], int n)
{
    int table[50][50];
    int i,j;
    
    //Since we are adding one extra row and column we will be going till n and cap and not n-1 and cap-1
    //Making the initial column 0
    for(i = 0; i <= n; i++)
    {
        table[i][0] = 0;
    }
    //Making the initial row 0
    for(j = 0; j <= cap; j++)
    {
        table[0][j] = 0;
    }
    
     //Applying the formula 
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= cap; j++)
        {
            if(w[i-1] > j)
            {
                table[i][j] = table[i-1][j];
            }
            else
            {
                table[i][j] = max(table[i-1][j], p[i-1]+table[i-1][j-w[i-1]]); 
            }
        }
    }
    //For table display
    for (i = 0; i <= n; i++)
    {
        
        for(j = 0; j <= cap; j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("The maximum profit is %d",table[n][cap]);
}

