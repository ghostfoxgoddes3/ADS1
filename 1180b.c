#include <stdio.h>

int main(){
    int n, v[n];

    scanf("%d", &n);
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
    return 0;
}
