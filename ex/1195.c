#include <stdio.h>
#include <stdlib.h>

/* BST node */
typedef struct bst_node {
    int val;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;

/* create new node */
bst_node* new_node(int val) {
    bst_node* n = (bst_node*)malloc(sizeof(bst_node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* insert into BST */
bst_node* bst_insert(bst_node* node, int val) {
    if (node == NULL)
        return new_node(val);

    if (val < node->val)
        node->left = bst_insert(node->left, val);
    else
        node->right = bst_insert(node->right, val);

    return node;
}

/* traversals */
void bst_pre(bst_node* node, int* first_flag) {
    if (!node) return;

    if (!(*first_flag)) printf(" ");
    printf("%d", node->val);
    *first_flag = 0;

    bst_pre(node->left, first_flag);
    bst_pre(node->right, first_flag);
}

void bst_in(bst_node* node, int* first_flag) {
    if (!node) return;

    bst_in(node->left, first_flag);

    if (!(*first_flag)) printf(" ");
    printf("%d", node->val);
    *first_flag = 0;

    bst_in(node->right, first_flag);
}

void bst_post(bst_node* node, int* first_flag) {
    if (!node) return;

    bst_post(node->left, first_flag);
    bst_post(node->right, first_flag);

    if (!(*first_flag)) printf(" ");
    printf("%d", node->val);
    *first_flag = 0;
}

/* free BST memory */
void free_tree(bst_node* node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int c = 1; c <= C; c++) {
        int N;
        scanf("%d", &N);

        bst_node* root = NULL;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            root = bst_insert(root, x);
        }

        printf("Case %d:\n", c);

        int first_flag = 1;
        printf("Pre.: ");
        bst_pre(root, &first_flag);
        printf("\n");

        first_flag = 1;
        printf("In..: ");
        bst_in(root, &first_flag);
        printf("\n");

        first_flag = 1;
        printf("Post: ");
        bst_post(root, &first_flag);
        printf("\n\n");

        free_tree(root);
    }

    return 0;
}
