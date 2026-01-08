#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000100

typedef struct node {
    char str[SIZE];
    struct node *left;
    struct node *right;
} node_t;

unsigned ans;

node_t *push(node_t *, char *);

int main() {
    char buffer[SIZE];
    node_t *tree = NULL;

    while (scanf("%s", buffer) != EOF)
        tree = push(tree, buffer);

    printf("%u\n", ans);

    return 0;
}

node_t *push(node_t *tree, char *word) {
    if (!tree) {
        tree = (node_t *) malloc(sizeof(node_t));
        tree->left = tree->right = NULL;
        strcpy(tree->str, word);
        ++ans;
    } else if (strcmp(tree->str, word) > 0) {
        tree->left = push(tree->left, word);
    } else if (strcmp(tree->str, word) < 0) {
        tree->right = push(tree->right, word);
    }

    return tree;
}
