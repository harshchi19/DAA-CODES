                               //Dijkstra Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int V) {
    int i;
    printf("Vertex Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int i, count, v;
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;
        for (v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, V);
}

int main() {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int i, j;
    int source;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix (0 for no connection):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(graph, source, V);
    return 0;
}
