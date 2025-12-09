#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 30100

typedef struct _node {
    int u;
    struct _node *next;
} node;

typedef struct _graph {
    node **adj;
} graph_t;

_Bool cycle_flag;
char visited[MAXSIZE];

graph_t *make_graph(int);
void dfs(graph_t *, int);
node *make_node(int);
void push_back(graph_t *, int, int);

int main() {
    int n, m, i, k, u, v;
    scanf("%d", &k);

    while (k--) {
        graph_t *graph = make_graph(10100);
        scanf("%d %d", &n, &m);

        for (i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            push_back(graph, u, v);
        }

        cycle_flag = false;
        for (i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(graph, i);
            if (cycle_flag)
                break;
        }

        printf("%s\n", cycle_flag ? "SIM" : "NAO");
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}

graph_t *make_graph(int size) {
    int i;
    graph_t *graph = (graph_t *) malloc(sizeof(graph_t));
    graph->adj = (node **) malloc(size * sizeof(node *));
    for (i = 0; i < size; ++i)
        graph->adj[i] = NULL;
    return graph;
}

node *make_node(int u) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->u = u;
    new_node->next = NULL;
    return new_node;
}

void push_back(graph_t *graph, int u, int v) {
    node *new_node = make_node(v);
    new_node->next = graph->adj[u];
    graph->adj[u] = new_node;
}

void dfs(graph_t *graph, int u) {
    node *i;
    visited[u] = true;

    if (cycle_flag)
        return;

    for (i = graph->adj[u]; i != NULL; i = i->next) {
        int v = i->u;
        if (visited[v] == 1) {
            cycle_flag = true;
            break;
        } else if (visited[v] == 0) {
            dfs(graph, v);
        }
    }

    visited[u] = 2;
}
