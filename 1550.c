#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_node {
    int data;
    struct queue_node *next;
} queue_node;

typedef struct queue_t {
    queue_node *first;
    queue_node *last;
} queue_t;

int start, end_val;
int dist[100010];

void bfs(int);
void pop(queue_t *);
int front(queue_t *);
_Bool is_empty(queue_t *);
void push(queue_t *, int);
void make_queue(queue_t *);

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        memset(dist, -1, sizeof(dist));
        scanf("%d %d", &start, &end_val);

        bfs(start);

        printf("%d\n", dist[end_val]);
    }

    return 0;
}

void bfs(int u) {
    queue_t queue;
    make_queue(&queue);
    push(&queue, u);

    dist[u] = 0;

    while (!is_empty(&queue)) {
        int v = front(&queue);
        if (dist[end_val] != -1)
            break;

        pop(&queue);

        int rev = 0, temp = v;
        while (temp) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        if (dist[rev] == -1)
            dist[rev] = dist[v] + 1, push(&queue, rev);
        
        if (dist[v + 1] == -1)
            dist[v + 1] = dist[v] + 1, push(&queue, v + 1);
    }
}

void make_queue(queue_t *q) {
    q->first = NULL;
    q->last = NULL;
}

void push(queue_t *q, int val) {
    queue_node *node = (queue_node *) malloc(sizeof(queue_node));
    node->data = val;
    node->next = NULL;

    if (q->first)
        q->last->next = node;
    else
        q->first = node;

    q->last = node;
}

void pop(queue_t *q) {
    if (!q->first)
        return;

    queue_node *tmp = q->first;
    if (q->first->next)
        q->first = q->first->next;
    else
        q->first = q->last = NULL;

    free(tmp);
}

_Bool is_empty(queue_t *q) {
    return q->first == NULL;
}

int front(queue_t *q) {
    return q->first->data;
}
