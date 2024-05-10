//Only run in online complier or vs not in turbo

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5

int dist[N][N] = {
    {0, 20, 30, 10, 11},
    {15, 0, 16, 4, 2},
    {3, 5, 0, 2, 4},
    {19, 6, 18, 0, 3},
    {16, 4, 7, 16, 0}
};

typedef struct Node {
    struct Node* parent;
    int reducedMatrix[N][N];
    int cost;
    int vertex;
    int level;
} Node;

Node* newNode(int parentMatrix[N][N], Node* parent, int level, int i, int j) {
    Node* node = (Node *)malloc(sizeof(Node));
    int k, l;
    for (k = 0; k < N; k++) {
        for (l = 0; l < N; l++) {
            node->reducedMatrix[k][l] = parentMatrix[k][l];
        }
    }
    for (k = 0; level != 0 && k < N; k++) {
        node->reducedMatrix[i][k] = INT_MAX;
        node->reducedMatrix[k][j] = INT_MAX;
    }
    node->reducedMatrix[j][0] = INT_MAX; // This sets the return path to INT_MAX; careful here, may need adjusting.
    node->level = level;
    node->vertex = j;
    node->parent = parent;
    node->cost = 0;
    return node;
}

void freeNode(Node* node) {
    free(node);
}

void rowReduction(int reducedMatrix[N][N], int row[N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        row[i] = INT_MAX;
        for (j = 0; j < N; j++) {
            if (reducedMatrix[i][j] < row[i]) {
                row[i] = reducedMatrix[i][j];
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (reducedMatrix[i][j] != INT_MAX && row[i] != INT_MAX) {
                reducedMatrix[i][j] -= row[i];
            }
        }
    }
}

void columnReduction(int reducedMatrix[N][N], int col[N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        col[i] = INT_MAX;
        for (j = 0; j < N; j++) {
            if (reducedMatrix[j][i] < col[i]) {
                col[i] = reducedMatrix[j][i];
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (reducedMatrix[j][i] != INT_MAX && col[i] != INT_MAX) {
                reducedMatrix[j][i] -= col[i];
            }
        }
    }
}

int calculateCost(int reducedMatrix[N][N]) {
    int cost = 0;
    int row[N], col[N];
    rowReduction(reducedMatrix, row);
    columnReduction(reducedMatrix, col);
    for (int i = 0; i < N; i++) {
        cost += (row[i] != INT_MAX) ? row[i] : 0;
        cost += (col[i] != INT_MAX) ? col[i] : 0;
    }
    return cost;
}

void printPath(Node* root) {
    if (root == NULL) return;
    printPath(root->parent);
    printf("%d ", root->vertex + 1);
}

int solve() {
    Node* root = newNode(dist, NULL, 0, -1, 0);
    Node* list[1024];  // Large enough list for demonstration
    int listSize = 0;
    int minCost = INT_MAX;
    Node* minNode = NULL;
    Node* currentNode;
    int i, j;

    root->cost = calculateCost(root->reducedMatrix);
    list[listSize++] = root;

    while (listSize != 0) {
        currentNode = list[--listSize];
        if (currentNode->level == N - 1) {
            currentNode->reducedMatrix[currentNode->vertex][0] = dist[currentNode->vertex][0];
            int totalCost = currentNode->cost + dist[currentNode->vertex][0];
            if (totalCost < minCost) {
                minCost = totalCost;
                minNode = currentNode;
            }
        } else {
            for (j = 0; j < N; j++) {
                if (currentNode->reducedMatrix[currentNode->vertex][j] != INT_MAX) {
                    Node* child = newNode(currentNode->reducedMatrix, currentNode, currentNode->level + 1, currentNode->vertex, j);
                    child->cost = currentNode->cost + currentNode->reducedMatrix[currentNode->vertex][j] + calculateCost(child->reducedMatrix);
                    list[listSize++] = child;
                }
            }
        }
        if (currentNode != minNode) { // Ensure we do not free the node that holds the min path before printing it
            freeNode(currentNode);
        }
    }
    if (minNode != NULL) {
        printf("Path: ");
        printPath(minNode);
        printf("\n");
        freeNode(minNode); // Ensure to free the minNode after using it
    }
    return minCost;
}

int main() {
    printf("Minimum cost : %d\n", solve());
    return 0;
}
