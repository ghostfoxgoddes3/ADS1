#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 600
#define INF 0x3f3f3f3f

int adj[MAXSIZE][MAXSIZE];

void dijkstra(int n, int src, int dest);

int main() {
    int u, v, w;
    int n, m, i, j, t;

    while (scanf("%d %d", &n, &m), n || m) {
        // inicializa matriz de adjacência
        for (i = 0; i <= n; ++i)
            for (j = 0; j <= n; ++j)
                adj[i][j] = INF;

        // lê arestas
        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            if (adj[v][u] != INF)
                adj[u][v] = adj[v][u] = 0; // mão dupla com conflito
            else
                adj[u][v] = w;
        }

        scanf("%d", &t);
        while (t--) {
            scanf("%d %d", &u, &v);
            dijkstra(n, u, v);
        }

        putchar_unlocked('\n');
    }

    return 0;
}

void dijkstra(int n, int src, int dest) {
    int i, j;
    int visited[n + 1];
    int dist[n + 1];

    memset(visited, false, sizeof(visited));

    for (i = 0; i <= n; ++i)
        dist[i] = INF;

    dist[src] = 0;

    for (i = 0; i <= n; ++i) {
        int u = -1;
        for (j = 0; j <= n; ++j)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        if (dist[u] == INF)
            break;

        visited[u] = true;
        for (j = 0; j <= n; ++j)
            if (dist[u] + adj[u][j] < dist[j])
                dist[j] = dist[u] + adj[u][j];
    }

    if (dist[dest] < INF)
        printf("%d\n", dist[dest]);
    else
        puts("Nao e possivel entregar a carta");
}
