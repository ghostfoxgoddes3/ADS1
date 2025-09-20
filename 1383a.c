#include <stdio.h>
#include <string.h>

int mat[9][9];
int lista[] = {0,0,0,0,0,0,0,0,0,0};

int row(){
        for(int j = 0; j<9; ++j){ 
            for(int k = 0; k<9; ++k){
                if(lista[mat[j][k]] == 0)
                    lista[mat[j][k]] = 1;
                else
                    return 0;
            } 
            memset(lista, 0, sizeof(lista));       
        }
    return 1;
}

int column(){
    for(int k = 0; k<9; ++k){ 
        for(int j = 0; j<9; ++j){
            if(lista[mat[j][k]] == 0)
                lista[mat[j][k]] = 1;
            else
                return 0;
        } 
        memset(lista, 0, sizeof(lista));       
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
    int n, i = 1;
    scanf("%d", &n);
    

    do
    {
        for(int j = 0; j<9; ++j){ //leitura
            for(int k = 0; k < 9; ++k){
                scanf("%d", &mat[j][k]);
            }
        }
        printf("Instancia %d", i);
        if(column() && row() && block()){
            printf("SIM");
        }
        else{
            printf("NAO");
        }

        ++i;
    } while (i < n);
    
}
