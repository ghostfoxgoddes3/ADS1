#include <stdlib.h>
#include <stdio.h>

struct list_node {
    int val;
    struct list_node *next;
};

struct linked_list {
    struct list_node *head;
};

struct hash_table {
    int n;
    struct linked_list *table;
};

void init_list(struct linked_list *l) {
    l->head = NULL;
}

void destroy_node(struct list_node *p) {
    if (p->next != NULL)
        destroy_node(p->next);
    free(p);
}

void destroy_list(struct linked_list *l) {
    if (l->head != NULL)
        destroy_node(l->head);
}

struct list_node *add_node(struct list_node *p, int val) {
    if (p == NULL) {
        struct list_node *new_node = (struct list_node *)malloc(sizeof(struct list_node));
        new_node->val = val;
        new_node->next = NULL;
        return new_node;
    } else {
        p->next = add_node(p->next, val);
        return p;
    }
}

void add_elem(struct linked_list *l, int val) {
    if (l == NULL)
        l = (struct linked_list *)malloc(sizeof(struct linked_list));
    l->head = add_node(l->head, val);
}

void print_list(struct linked_list *l) {
    if (l != NULL) {
        struct list_node *p = l->head;
        while (p != NULL) {
            printf("%d -> ", p->val);
            p = p->next;
        }
    }
    printf("\\\n");
}

void init_hash_table(struct hash_table *ht, int n) {
    ht->n = n;
    ht->table = (struct linked_list *)malloc(n * sizeof(struct linked_list));
    for (int i = 0; i < n; i++)
        init_list(&(ht->table[i]));
}

void destroy_hash_table(struct hash_table *ht) {
    for (int i = 0; i < ht->n; i++)
        destroy_list(&(ht->table[i]));
    ht->n = 0;
    free(ht->table);
}

int hash_func(struct hash_table *ht, int val) {
    return val % ht->n;
}

void add_elem_table(struct hash_table *ht, int val) {
    int idx = hash_func(ht, val);
    add_elem(&(ht->table[idx]), val);
}

void print_hash_table(struct hash_table *ht) {
    for (int i = 0; i < ht->n; i++) {
        printf("%d -> ", i);
        print_list(&(ht->table[i]));
    }
}

int main() {
    int N, M, C, num;
    struct hash_table ht;

    scanf("%d", &N);

    for (int k = 0; k < N; k++) {
        if (k)
            printf("\n");

        scanf("%d %d", &M, &C);

        init_hash_table(&ht, M);

        for (int i = 0; i < C; i++) {
            scanf("%d", &num);
            add_elem_table(&ht, num);
        }

        print_hash_table(&ht);
        destroy_hash_table(&ht);
    }

    return 0;
}
