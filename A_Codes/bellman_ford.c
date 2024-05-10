#include <stdio.h>

void bf(int s, int m[4][4], int dist[4], int n) {
    int i, u, v;
    for (i = 0; i < n - 1; i++) {
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

int main() {
    int n = 4, m[4][4], dist[4], i, j, s;
    m[0][0] = 0;
    m[0][1] = 15;
    m[0][2] = 5;
    m[0][3] = 999;
    m[1][0] = 15;
    m[1][1] = 0;
    m[1][2] = 999;
    m[1][3] = -10;
    m[2][0] = 5;
    m[2][1] = 999;
    m[2][2] = 0;
    m[2][3] = 10;
    m[3][0] = 999;
    m[3][1] = 10;
    m[3][2] = 10;
    m[3][3] = 0;
    s = 0;
    for (i = 0; i < n; i++) {
        dist[i] = 999;
    }
    dist[s] = 0;
    bf(s, m, dist, n);
    return 0;
}