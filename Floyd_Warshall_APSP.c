#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>    

void floydWarshall(int **graph, int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int n, i, j;
    int **graph;
    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

  
    graph = (int **)malloc(n * sizeof(int *));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        if (graph[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }


    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }

  
    printf("Enter the edges: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf("Enter weight for edge [%d][%d], or %d for no edge: ", i, j, INT_MAX);
                scanf("%d", &graph[i][j]);
                if (graph[i][j] == INT_MAX) { 
                    graph[i][j] = INT_MAX;
                }
            }
        }
    }

    
    printf("The original graph is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == INT_MAX)
                printf(" INF ");
            else
                printf("%4d ", graph[i][j]);
        }
        printf("\n");
    }

   
    floydWarshall(graph, n);

  
    printf("The shortest path matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == INT_MAX)
                printf(" INF ");
            else
                printf("%4d ", graph[i][j]);
        }
        printf("\n");
    }

   
    for (i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    getch(); 
    return 0;
}
