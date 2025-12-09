#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

struct stack_node {
    char val;
    struct stack_node *below;
};

struct stack {
    int size;
    struct stack_node *top;
};

void push(struct stack *s, char val) {
    s->size++;
    struct stack_node *new_top = (struct stack_node *)malloc(sizeof(struct stack_node));

    new_top->val   = val;
    new_top->below = s->top;
    s->top = new_top;
}

void pop(struct stack *s) {
    if (s->size > 0) {
        s->size--;
        struct stack_node *old_top = s->top;
        s->top = s->top->below;
        free(old_top);
    }
}

char top_val(struct stack *s) {
    return s->top->val;
}

int stack_size(struct stack *s) {
    return s->size;
}

int empty(struct stack *s) {
    return s->size == 0;
}

void init(struct stack *s) {
    s->size = 0;
    s->top = NULL;
}

void destroy(struct stack *s) {
    while (!empty(s))
        pop(s);
}

int prec(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return 0; // fallback
}

int main() {
    int n, len;
    struct stack s;
    char expr[301];

    scanf("%d\n", &n);

    for (int k = 0; k < n; k++) {
        scanf("%s\n", expr);

        init(&s);

        len = strlen(expr);
        for (int i = 0; i < len; i++) {
            if (isalpha(expr[i]) || isdigit(expr[i])) {
                printf("%c", expr[i]);
            }
            else if (expr[i] == '(' || expr[i] == '^') {
                push(&s, expr[i]);
            }
            else if (expr
