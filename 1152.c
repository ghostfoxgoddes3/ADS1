#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned u, v, w;
} edge_t;

#define MAXSIZE 200100

edge_t edges[MAXSIZE];
int parent_arr[MAXSIZE];

int kruskal(int);
int find_parent(int);
int compare_edges(edge_t *, edge_t *);

int main() {
    int n_nodes, n_edges;

    while (scanf("%d %d", &n_nodes, &n_edges), n_nodes && n_edges) {
        unsigned i, total = 0;

        for (i = 0; i < n_edges; ++i) {
            scanf("%d %d %d", &edges[i].v, &edges[i].u, &edges[i].w);
            total += edges[i].w;
        }

        qsort(edges, n_edges, sizeof(edge_t), compare_edges);

        for (i = 1; i <= n_nodes; ++i)
            parent_arr[i] = i;

        printf("%u\n", total - kruskal(n_edges));

        memset(edges, 0, sizeof(edges));
        memset(parent_arr, 0, sizeof(parent_arr));
    }

    return 0;
}

// encontra o representante do conjunto
int find_parent(int x) {
    if (x == parent_arr[x])
        return x;
    return find_parent(parent_arr[x]);
}

int kruskal(int n) {
    int i, u, v;
    unsigned ans = 0;

    for (i = 0; i < n; ++i) {
        v = find_parent(edges[i].v);
        u = find_parent(edges[i].u);

        if (v != u) {
            parent_arr[v] = parent_arr[u];
            ans += edges[i].w;
        }
    }

    return ans;
}

// comparação de arestas para qsort
int compare_edges(edge_t *a, edge_t *b) {
    return a->w - b->w;
}
