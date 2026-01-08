#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 35

_Bool visited[MAXSIZE];
char adj[MAXSIZE][MAXSIZE];
char component[MAXSIZE];

int comp_size;
int n_vertices, n_edges;

void dfs(int);
int compare_char(const void *, const void *);

int main() {
    int i, j, n_cases, case_no = 0;

    scanf("%d", &n_cases);

    while (n_cases--) {
        scanf("%d %d", &n_vertices, &n_edges);

        char u, v;
        for (i = 0; i < n_edges; ++i) {
            scanf(" %c %c", &u, &v);
            adj[u - 'a'][v - 'a'] = 1;
            adj[v - 'a'][u - 'a'] = 1;
        }

        printf("Case #%d:\n", ++case_no);
        int n_components = 0;

        for (i = 0; i < n_vertices; ++i) {
            if (!visited[i]) {
                ++n_components;
                comp_size = 0;
                dfs(i);

                qsort(component, comp_size, sizeof(char), compare_char);

                for (j = 0; j < comp_size; ++j)
                    printf("%c,", component[j] + 'a');
                printf("\n");
            }
        }

        printf("%d connected components\n\n", n_components);

        memset(visited, 0, sizeof(visited));
        memset(adj, 0, sizeof(adj));
    }

    return 0;
}

void dfs(int u) {
    visited[u] = 1;
    component[comp_size++] = u;

    for (int i = 0; i < n_vertices; ++i)
        if (adj[u][i] && !visited[i])
            dfs(i);
}

int compare_char(const void *a, const void *b) {
    char ca = *(char *)a;
    char cb = *(char *)b;
    return (ca > cb) - (ca < cb); // -1, 0 ou 1
}
