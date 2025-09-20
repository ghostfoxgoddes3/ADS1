#include <stdio.h>
#include <string.h>

int mat[9][9];
int lista[10]; // [0..9]

int row(){
    for(int j = 0; j < 9; ++j){ 
        memset(lista, 0, sizeof(lista));
        for(int k = 0; k < 9; ++k){
            if(lista[mat[j][k]] == 0)
                lista[mat[j][k]] = 1;
            else
                return 0;
        } 
    }
    return 1;
}

int column(){
    for(int k = 0; k < 9; ++k){ 
        memset(lista, 0, sizeof(lista));
        for(int j = 0; j < 9; ++j){
            if(lista[mat[j][k]] == 0)
                lista[mat[j][k]] = 1;
            else
                return 0;
        } 
    }
    return 1;
}

int block(){
    for(int r = 0; r < 9; r += 3){        
        for(int s = 0; s < 9; s += 3){    
            memset(lista, 0, sizeof(lista));
            for(int j = r; j < r+3; j++){ 
                for(int k = s; k < s+3; k++){
                    if(lista[mat[j][k]] == 0)
                        lista[mat[j][k]] = 1;
                    else
                        return 0;
                }
            }
        }
    }
    return 1; 
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 9; ++j){ 
            for(int k = 0; k < 9; ++k){
                scanf("%d", &mat[j][k]);
            }
        }
        printf("Instancia %d\n", i);
        if(column() && row() && block())
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
    }
    return 0;
}
