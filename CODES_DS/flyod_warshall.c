#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int n, m;               //n->nodes  m->edges
int g[100][100];        //adjacency matrix
bool vis[100];          //yeh batayega ki node visit hua hy ki nai
int inf = 10000;        //infinity 
int dist[100][100];     //isme apneko cost ka matrix lagta hy

int min(int x, int y)
{
    if(x<y)return x;
    return y;
}

int main(){

    printf("Enter the number of Nodes (n) & Edges(m):");
    scanf("%d%d", &n, &m);

    //graph initialization
    for(int i = 1; i <= n; i++)
    {
        vis[i] = false;                 //saare nodes ko unvisited kardiya
        for(int j = 1; j <= n; j++)
        {
            g[i][j] = inf;                //puri ajacency matrix ko infinity kardiya
            dist[i][j] = inf;             //saare nodes ki cost infinity kardiya
        }
        dist[i][i] = 0;                   //diagonal elements ko zero karo  
    }


    //input for edges
    printf("Enter the edge list of your graph: \n");
    for(int i = 1; i <= m; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        g[u][v] = c;
        dist[u][v] = c;
    }

    for(int k = 1; k <= n; k++){            //yeh thoda difficult lag sakta hy lekin thoda shanti se dekhna samaj jayega
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    printf("Final Path Cost Matrix:\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    return 0;

}