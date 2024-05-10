#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <limits.h>  

#define N 4


int row[] = {1, 0, -1, 0}; 
int col[] = {0, 1, 0, -1};


typedef struct Node {
    int puzzle[N][N];  
    int x, y;  
    int cost;  
    int level;  
    struct Node* parent;  
} Node;


int calculateCost(int initial[N][N], int final[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (initial[i][j] != 0) {
                int num = initial[i][j];
                for (int x = 0; x < N; x++) {
                    for (int y = 0; y < N; y++) {
                        if (final[x][y] == num) {
                            count += abs(x - i) + abs(y - j);
                            break;
                        }
                    }
                }
            }
        }
    }
    return count;
}


Node* createNode(int puzzle[N][N], int x, int y, int newX, int newY, int level, Node* parent, int final[N][N]) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->parent = parent;
    memcpy(node->puzzle, puzzle, sizeof(node->puzzle));
   
    node->puzzle[x][y] = node->puzzle[newX][newY];
    node->puzzle[newX][newY] = 0;

    node->cost = calculateCost(node->puzzle, final);
    node->level = level;
    node->x = newX;
    node->y = newY;
    return node;
}


void printMatrix(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", puzzle[i][j]);
        printf("\n");
    }
}


int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}


void printPath(Node* root) {
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->puzzle);
    printf("\n");
}


Node* solve(int initial[N][N], int x, int y, int final[N][N]) {
    
    Node* root = createNode(initial, x, y, x, y, 0, NULL, final);

    Node* min = root;

    while (min != NULL) {
        if (min->cost == 0) {
            printPath(min);
            return min;
        }

        
        for (int i = 0; i < 4; i++) {
            int newx = min->x + row[i];
            int newy = min->y + col[i];
            if (isSafe(newx, newy)) {
                Node* child = createNode(min->puzzle, min->x, min->y, newx, newy, min->level + 1, min, final);
                min = child;  
            }
        }
    }
    return NULL;
}

int main() {
    int initial[N][N] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 0, 15 }
    };

    int final[N][N] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 0 }
    };

    int x = 3, y = 2

    Node* solution = solve(initial, x, y, final);

    if(solution == NULL)
        printf("No solution exists\n");
    else
        printf("Solution found!\n");

    return 0;
}
