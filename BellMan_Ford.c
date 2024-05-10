#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<conio.h>
struct Edge {
    int source, destination, weight;
};

struct Graph {
    int V; 
    int E;
    struct Edge* edge; 
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void BellmanFord(struct Graph* graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int distance[1000];     
    int i, j, u, v, weight;

    for (i = 0; i < V; i++)
        distance[i] = INT_MAX;
    distance[source] = 0;

    for (i = 1; i <= V - 1; i++) {
        for (j = 0; j < E; j++) {
            u = graph->edge[j].source;
            v = graph->edge[j].destination;
            weight = graph->edge[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

    for (j = 0; j < E; j++) {
        u = graph->edge[j].source;
        v = graph->edge[j].destination;
        weight = graph->edge[j].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle");
            return;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, distance[i]);
}

int main() {
    int V, E, i, source;
    struct Graph* graph;
    clrscr();
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    graph = createGraph(V, E);

    printf("Enter source, destination, and weight for each edge:\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    BellmanFord(graph, source);
    getch();
    return 0;
}
