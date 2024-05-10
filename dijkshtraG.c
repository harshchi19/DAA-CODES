#include<stdio.h>

void print(int m[10][10],int n){
    int i,j;
    printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d \t",m[i][j]);
        }
        printf("\n");
    }
}

void dj(int m[10][10],int s,int n,int dist[10]){
    int i,visited[10],count=1,min,v;
    for(i=1;i<=n;i++){
        dist[i]=m[s][i];
        visited[i]=0;
    }
    visited[s]=1;
    dist[s]=0;
    while(count<=n){
        min=999;
        v=0;
        for(i=1;i<=n;i++){
            if(dist[i]<min && visited[i]==0){
                min=dist[i];
                v=i;
            }
        }
        visited[v]=1;
        count++;
        for(i=1;i<=n;i++){
            if(m[v][i]!=0 && dist[i]>dist[v]+m[v][i]){
                dist[i]=dist[v]+m[v][i];
            }
        }
    }
}

void main(){
    int i,j,m[10][10],dist[10],n,s;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("Enter the distance of %d->%d: ",i,j);
            scanf("%d",&m[i][j]);
            if(m[i][j] == 0){
            m[i][j] = 998;
            }
        }
    }
    print(m,n);

    printf("\n\nEnter the source : ");
    scanf("%d",&s);

    dj(m,s,n,dist);

    for(i=1;i<=n;i++){
        if(s!=i){
            printf("%d->%d : mincost=%d",s,i,dist[i]);
        }
    }

}
