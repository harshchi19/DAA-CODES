#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m;               //n->nodes  m->edges
int g[100][100];        //adjacency matrix
bool vis[100];          //yeh batayega ki node visit hua hy ki nai

void dfs(int x){
    vis[x] = true;      //tumhare source node ko visited mark karo
    printf("%d ", x);   
    for(int y = 1; y <= n; y++)
    {
        if(g[x][y]==1 && !vis[y])
        {
            dfs(y);
        }
    }
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
            g[i][j] = 0;                //puri ajacency matrix ko 0 kardiya
        }
    }

    //input for edges
    printf("Enter the edges: \n");
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;                    //jab graph undirected chahiye toh yeh line likhna otherwise nai
    }

    int src;
    printf("Enter your Source node:");
    scanf("%d",&src);
    printf("Applying DFS on graph\n Your result is: ");
    dfs(src);
    return 0;

}