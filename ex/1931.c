#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 11234
#define INF 0x3f3f3fu

typedef struct _node {
    int to, weight;
    struct _node *next;
} node_t;

typedef struct _graph {
    node_t *adj;
} graph_t;

int visited[MAX_SIZE];
int distance[MAX_SIZE];

graph_t *make_graph(const int size);
node_t *make_node(const int to, const int weight);
void dijkstra(const graph_t *restrict g, const int start, const int size);
void push_back(const graph_t *restrict g, const int from, const int to, const int weight);
void make_aux_graph(const graph_t *restrict g1, const graph_t *restrict g2, const int size);

int main(int argc, char **argv)
{
    int u, v, w;
    int n_nodes, n_edges, i, j;

    scanf("%d %d", &n_nodes, &n_edges);

    graph_t *g1 = make_graph(n_nodes + 1);
    graph_t *g2 = make_graph(n_nodes + 1);

    while (n_edges--)
    {
        scanf("%d %d %d", &u, &v, &w);
        push_back(g1, u, v, w);
        push_back(g1, v, u, w);
    }

    dijkstra(g2, 1, n_nodes);

    if (distance[n_nodes] == INF)
        puts("-1");
    else
        printf("%d\n", distance[n_nodes]);

    return 0;
}

graph_t *make_graph(const int size)
{
    graph_t *g = (graph_t *) malloc(sizeof(graph_t));
    g->adj = (node_t *) malloc(sizeof(node_t) * (size + 1));

    for (int i = 1; i <= size; ++i)
        g->adj[i].next = NULL;

    return g;
}

node_t *make_node(const int to, const int weight)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->to = to;
    new_node->weight = weight;
    new_node->next = NULL;
    return new_node;
}

void push_back(const graph_t *restrict g, const int from, const int to, const int weight)
{
    node_t *new_node = make_node(from, weight);
    new_node->next = g->adj[to].next;
    g->adj[to].next = new_node;
}

void dijkstra(const graph_t *restrict g, const int start, const int size)
{
    int i, j, current;
    node_t *k;

    memset(visited, false, sizeof(visited));
    for (i = 1; i <= size; ++i)
        distance[i] = INF;

    distance[start] = 0;

    for (i = 1; i <= size; ++i)
    {
        current = -1;
        for (j = 1; j <= size; ++j)
            if (!visited[j] && (current == -1 || distance[j] < distance[current]))
                current = j;

        if (distance[current] == INF)
            break;

        visited[current] = true;

        for (k = g->adj[current].next; k != NULL; k = k->next)
        {
            int to_node = k->to;
            int edge_weight = k->weight;

            if (distance[current] + edge_weight < distance[to_node])
                distance[to_node] = distance[current] + edge_weight;
        }
    }
}

void make_aux_graph(const graph_t *restrict g1, const graph_t *restrict g2, const int size)
{
    int i;
    node_t *j, *k;

    for (i = 1; i <= size; ++i)
    {
        for (j = g1->adj[i].next; j != NULL; j = j->next)
        {
            int u = j->to;
            int w = j->weight;

            for (k = g1->adj[u].next; k != NULL; k = k->next)
            {
                int v = k->to;
                int w2 = k->weight;
                push_back(g2, i, v, w + w2);
            }
        }
    }
}
