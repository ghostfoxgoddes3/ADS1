#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i){
       scanf("%d", v + i); 
    } 

    int menor = *v, pos = 0;
    for(int i = 1; i < n; ++i){
        if(*(v + i) < menor){
            menor = *(v + i);
            pos = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);

    free(v);
    return 0;
}
