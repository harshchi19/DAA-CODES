#include <stdio.h>
#include <conio.h>

void fractional(int cap, int w[], int p[], int n);
int max(int a, int b)
{
    return (a > b) ? a : b;
}

void main()
{
    int cap, n, i;
    int w[101], p[101];
    int temp_w, temp_p, j;
    clrscr();
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacities of the items:\n");
    for(i = 0; i < n; i++)
    {
        printf("Weight %d: ", i+1);
        scanf("%d", &w[i]);
        printf("Profit %d: ", i+1);
        scanf("%d", &p[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &cap);

    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(w[j] > w[j+1])
            {
                temp_w = w[j];
                w[j] = w[j+1];
                w[j+1] = temp_w;
                temp_p = p[j];
                p[j] = p[j+1];
                p[j+1] = temp_p;
            }
        }
    }
    
    fractional(cap, w, p, n);
    getch();
}

void fractional(int cap, int w[], int p[], int n)
{
    int table[101][101];
    int i, j;

   
    for(i = 0; i <= n; i++)
    {
        table[i][0] = 0;
    }

    for(j = 0; j <= cap; j++)
    {
        table[0][j] = 0;
    }


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
                table[i][j] = max(table[i-1][j], p[i-1] + table[i-1][j-w[i-1]]);
            }
        }
    }
 
    printf("DP Table:\n");
    for (i = 0; i <= n; i++)
    {
        for(j = 0; j <= cap; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("The maximum profit is %d\n", table[n][cap]);
}
