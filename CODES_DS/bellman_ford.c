#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m;               //n->nodes  m->edges
int g[100][100];        //adjacency matrix
bool vis[100];          //yeh batayega ki node visit hua hy ki nai

int inf = 10000;        //infinity 
int dist[100];          //har ek node ka total path cost find karne k liye
int parent[100];        //har ek node ka parent

struct e {
    int u;
    int v;
    int c;
};
struct e edges[1000];   //struct e ka edges naam ka ek array
int curr = 0;

int main(){

    printf("Enter the number of Nodes (n) & Edges(m):");
    scanf("%d%d", &n, &m);

    //graph initialization
    for(int i = 1; i <= n; i++)
    {
        vis[i] = false;                 //saare nodes ko unvisited kardiya
        dist[i] = inf;                  //saare nodes ki cost infinity kardiya
        parent[i] = -1;                 //saare nodes ke parents null kardiya
        for(int j = 1; j <= n; j++)
        {
            g[i][j] = inf;                //puri ajacency matrix ko infinity kardiya
        }
    }

    //input for edges
    printf("Enter the edge list of your graph: \n");
    for(int i = 1; i <= m; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        g[u][v] = c;
        edges[curr].u = u;
        edges[curr].v = v;
        edges[curr].c = c;
        curr++;
    }

    printf("Your Adjacency list is:\n");
    for(int i = 0; i < m; i++){
        printf("%d -> %d at cost %d.\n", edges[i].u, edges[i].v, edges[i].c);
    }

    dist[1] = 0;                    //very very important step; tumhare source ka dist 0 karna mat bhulna
    for(int i = 1; i < n; i++){
        for(int i = 0; i < m; i++){
            int u = edges[i].u;         //yaha u,v,c isliye liye so that short hojaye warna tumko formula mein pura likhna padta
            int v = edges[i].v;
            int c = edges[i].c;
            if(dist[v] > dist[u] + c)   //same as (dist[edges[i].v] > dist[edges[i].u] + edges[i].c)
            {
                dist[v] = dist[u] + c;
                parent[v] = u;
            }
        }
    }

    printf("Shortest path from source for all nodes are:\n");
    for(int i = 1; i <= n; i++){
        printf("Node %d => %d\n", i, dist[i]);
    }


    //path print karne k liye
    printf("Enter the destination node:");
    int src;
    scanf("%d", &src);
    int dest = src;
    while(dest != -1){
        printf("%d ", dest);
        dest = parent[dest];
    }
    return 0;

}