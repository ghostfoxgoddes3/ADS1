#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAX_EDGES 40050
#define MAX_VERTICES 40000

typedef struct {
    int u, v, w;
} edge_t;

edge_t edges[MAX_EDGES];
int parent[MAX_VERTICES];

// funções
int compare_edges(edge_t *, edge_t *);
int kruskal(int num_edges);
int find_component(int);

int main() {
    int num_vertices, num_edges, i;

    while (scanf("%d %d", &num_vertices, &num_edges), num_vertices && num_edges) {
        memset(edges, 0, sizeof(edges));
        memset(parent, 0, sizeof(parent));

        for (i = 0; i < num_edges; ++i)
            scanf("%d %d %d", &edges[i].v, &edges[i].u, &edges[i].w);

        qsort(edges, num_edges, sizeof(edge_t), (int(*)(const void*, const void*))compare_edges);

        for (i = 1; i <= num_vertices; ++i)
            parent[i] = i;

        printf("%d\n", kruskal(num_edges));
    }

    return 0;
}

// compara pesos das arestas
int compare_edges(edge_t *a, edge_t *b) {
    return a->w - b->w;
}

// encontra componente de um vértice
int find_component(int x) {
    if (x == parent[x])
        return x;
    return find_component(parent[x]);
}

// algoritmo de Kruskal
int kruskal(int num_edges) {
    int i, ans = 0, u_comp, v_comp;

    for (i = 0; i < num_edges; ++i) {
        v_comp = find_component(edges[i].v);
        u_comp = find_component(edges[i].u);

        if (v_comp != u_comp) {
            parent[v_comp] = parent[u_comp];
            ans += edges[i].w;
        }
    }

    return ans;
}
