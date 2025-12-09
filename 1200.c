#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 100

typedef struct tree_node {
    char letter;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

// funções de travessia
void traverse_infix(tree_node *);
void traverse_prefix(tree_node *);
void traverse_post(tree_node *);
void print_infix(char *);
void print_prefix(char *);
void print_post(char *);
tree_node* insert_node(tree_node *, char );
_Bool search_node(tree_node *, char );

// arrays globais de letras
char infix_letters[MAXSIZE] = {0};
char post_letters[MAXSIZE] = {0};
char prefix_letters[MAXSIZE] = {0};

// índices globais
int infix_idx = 0;
int post_idx = 0;
int prefix_idx = 0;

// teste simples de impressão
void test(tree_node *node) {
    if (node) {
        test(node->left);
        printf("%c ", node->letter);
        test(node->right);
    }
}

int main() {
    char cmd[20], letter;
    tree_node *node = NULL;

    while (scanf("%s%*c", cmd) != EOF) {
        if (strcmp(cmd, "I") == 0) {
            scanf("%c", &letter);
            node = insert_node(node, letter);
        }
        else if (strcmp(cmd, "INFIXA") == 0) {
            traverse_infix(node);
            print_infix(infix_letters);
        }
        else if (strcmp(cmd, "PREFIXA") == 0) {
            traverse_prefix(node);
            print_prefix(prefix_letters);
        }
        else if (strcmp(cmd, "P") == 0) {
            scanf("%c", &letter);
            if (search_node(node, letter))
                printf("%c existe\n", letter);
            else
                printf("%c nao existe\n", letter);
        }
        else {
            traverse_post(node);
            print_post(post_letters);
        }
    }

    return 0;
}

tree_node* insert_node(tree_node *node, char letter) {
    if (!node) {
        node = (tree_node *) malloc(sizeof(tree_node));
        node->letter = letter;
        node->left = node->right = NULL;
    }
    else if (node->letter > letter)
        node->left = insert_node(node->left, letter);
    else
        node->right = insert_node(node->right, letter);

    return node;
}

_Bool search_node(tree_node *node, char letter) {
    if (!node)
        return false;
    if (node->letter == letter)
        return true;
    if (node->letter > letter)
        return search_node(node->left, letter);
    else
        return search_node(node->right, letter);
}

void print_infix(char *letters) {
    int z;
    for (z = 0; z < infix_idx; ++z)
        if (!z)
            printf("%c", infix_letters[z]);
        else
            printf(" %c", infix_letters[z]);

    infix_idx = 0;
    printf("\n");
}

void print_prefix(char *letters) {
    int z;
    for (z = 0; z < prefix_idx; ++z)
        if (!z)
            printf("%c", prefix_letters[z]);
        else
            printf(" %c", prefix_letters[z]);

    prefix_idx = 0;
    printf("\n");
}

void print_post(char *letters) {
    int z;
    for (z = 0; z < post_idx; ++z)
        if (!z)
            printf("%c", post_letters[z]);
        else
            printf(" %c", post_letters[z]);

    post_idx = 0;
    printf("\n");
}

void traverse_infix(tree_node *node) {
    if (node) {
        traverse_infix(node->left);
        infix_letters[infix_idx++] = node->letter;
        traverse_infix(node->right);
    }
}

void traverse_post(tree_node *node) {
    if (node) {
        traverse_post(node->left);
        traverse_post(node->right);
        post_letters[post_idx++] = node->letter;
    }
}

void traverse_prefix(tree_node *node) {
    if (node) {
        prefix_letters[prefix_idx++] = node->letter;
        traverse_prefix(node->left);
        traverse_prefix(node->right);
    }
}
