#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];
int key[MAX_VERTICES];
int mstSet[MAX_VERTICES];

int findMinKey(int V, int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMST(int V) {
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(V, key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int V = 5;

    graph[0][1] = 2;
    graph[0][3] = 6;
    graph[1][0] = 2;
    graph[1][2] = 3;
    graph[1][3] = 8;
    graph[1][4] = 5;
    graph[2][1] = 3;
    graph[2][4] = 7;
    graph[3][0] = 6;
    graph[3][1] = 8;
    graph[3][4] = 9;
    graph[4][1] = 5;
    graph[4][2] = 7;
    graph[4][3] = 9;

    primMST(V);

    return 0;
}