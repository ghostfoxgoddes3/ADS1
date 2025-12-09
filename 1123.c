#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 100000
#define MAXSIZE 101010

int visited[MAXSIZE];
int dist[MAXSIZE];

typedef struct node {
    int u, w;
    struct node *next;
} node_t;

typedef struct graph {
    node_t *adj;
} graph_t;

graph_t *make_graph(int size);
node_t *make_node(int u, int w);
void dijkstra(graph_t *, int, int);
void push_back(graph_t *, int, int, int);

int main() {
    int n, m, c, k, a, b, w, i;

    while (scanf("%d %d %d %d", &n, &m, &c, &k), (c && n && m && k)) {
        graph_t *g = make_graph(n + 1);

        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &w);

            if ((a >= c && b >= c) || ((a < c) && (b < c) && (abs(a - b) == 1))) {
                push_back(g, a, b, w);
                push_back(g, b, a, w);
            }

            if (a >= c && b < c)
                push_back(g, b, a, w);

            if (b >= c && a < c)
                push_back(g, a, b, w);
        }

        dijkstra(g, k, n);
        printf("%d\n", dist[c - 1]);
    }

    return 0;
}

void dijkstra(graph_t *g, int s, int size) {
    node_t *curr;
    int i, j, v;

    for (i = 0; i < size; ++i)
        dist[i] = INF;

    memset(visited, false, sizeof(visited));
    dist[s] = 0;

    for (i = 0; i < size; ++i) {
        v = -1;

        for (j = 0; j < size; ++j)
            if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (dist[v] == INF)
            break;

        visited[v] = true;

        for (curr = g->adj[v].next; curr != NULL; curr = curr->next) {
            int to = curr->u;
            int len = curr->w;

            if (dist[v] + len < dist[to])
                dist[to] = dist[v] + len;
        }
    }
}

graph_t *make_graph(int size) {
    int i;
    graph_t *g = (graph_t *) malloc(sizeof(graph_t));
    g->adj = (node_t *) malloc(sizeof(node_t) * (size + 1));

    for (i = 0; i < size; ++i)
        g->adj[i].next = NULL;

    return g;
}

node_t *make_node(int u, int w) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->u = u;
    new_node->w = w;
    new_node->next = NULL;
    return new_node;
}

void push_back(graph_t *g, int u, int v, int w) {
    node_t *new_node = make_node(u, w);
    new_node->next = g->adj[v].next;
    g->adj[v].next = new_node;
}
