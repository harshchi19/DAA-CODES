#include <stdio.h>
#include <conio.h>
int m[5][5],dist[5];

void bf(int s, int n) {
    int i, u, v;
    for (i = 0; i < n; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (m[u][v] != 999 && dist[u] + m[u][v] < dist[v]) {
                    dist[v] = dist[u] + m[u][v];
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (s != i) {
            printf("\nThe dist from %d to %d is %d", s, i, dist[i]);
        }
    }
}

void main() {
    int n = 5, i, j, s;
    m[0][0] = 999;
    m[0][1] = 4;
    m[0][2] = 2;
    m[0][3] = 999;
    m[0][4] = 999;
    m[1][0] = 999;
    m[1][1] = 999;
    m[1][2] = 3;
    m[1][3] = 2;
    m[1][4] = 3;
    m[2][0] = 999;
    m[2][1] = 1;
    m[2][2] = 999;
    m[2][3] = 4;
    m[2][4] = 5;
    m[3][0] = 999;
    m[3][1] = 999;
    m[3][2] = 999;
    m[3][3] = 999;
    m[3][4] = 999;
    m[4][0] = 999;
    m[4][1] = 999;
    m[4][2] = 999;
    m[4][3] = -5;
    m[4][4] = 999;
    s = 0;
    for (i = 0; i < n; i++) {
        dist[i] = 999;
    }
    dist[s] = 0;
    bf(s, n);
    getch();
}
