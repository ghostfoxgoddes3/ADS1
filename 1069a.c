#include <stdio.h>
#define MAX 1000   

typedef struct {
    char item[MAX]; 
    int up;        
} Stack;

void ignite(Stack *p) {
    p->up = -1;
}

int isEmpty(Stack *p) {
    return (p->up == -1);
}

void push(Stack *p, char valor) {
    p->item[++(p->up)] = valor;
}

char pop(Stack *p) {
    return p->item[(p->up)--];
}

char top(Stack *p) {
    if (isEmpty(p))
        return '\0';
    return p->item[p->up];
}

int main(){
    int n;
    scanf("%d", &n);
    getchar(); 

    for(int i = 0; i < n; ++i){
        Stack pilha;
        ignite(&pilha);
        int diamond = 0;

        char linha[MAX];
        fgets(linha, MAX, stdin); 

        for(int j = 0; linha[j] != '\0'; j++){
            char c = linha[j];

            if(c == '<'){
                push(&pilha, c);
            }
            else if(c == '>'){
                if(!isEmpty(&pilha)){
                    pop(&pilha);
                    diamond++;
                }
            }
        }

        printf("%d\n", diamond);
    }

    return 0;
}
