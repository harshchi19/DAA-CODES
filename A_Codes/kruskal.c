#include<stdio.h>

int a,b,u,n,v,mincost=0,cost[10][10],i,j,visited[10]={0},count=1,min;

void main(){
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999; 
        }
    }

    visited[1]=1;
    while(count<n){
        for(i=1,min=999;i<=n;i++){ 
            for(j=1;j<=n;j++){ 
                if(cost[i][j]<min)
                    if(visited[i]!=0){
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
            }
        }
        if(visited[u] == 0 || visited[v] == 0){
            printf("\n Edge %d:(%d,%d) cost:%d", count,a,b,min);
            mincost=mincost+min;
            visited[b]=1;
            count++;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost : %d",mincost); 
}
