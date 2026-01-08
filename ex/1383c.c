#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_rows(int **mat){
    int *seen = malloc(10 * sizeof(int));
    for(int i = 0; i < 9; ++i){
        memset(seen, 0, 10 * sizeof(int));
        for(int j = 0; j < 9; ++j){
            int val = mat[i][j];
            if(seen[val]){ free(seen); return 0; }
            seen[val] = 1;
        }
    }
    free(seen);
    return 1;
}

int check_cols(int **mat){
    int *seen = malloc(10 * sizeof(int));
    for(int j = 0; j < 9; ++j){
        memset(seen, 0, 10 * sizeof(int));
        for(int i = 0; i < 9; ++i){
            int val = mat[i][j];
            if(seen[val]){ free(seen); return 0; }
            seen[val] = 1;
        }
    }
    free(seen);
    return 1;
}

int check_blocks(int **mat){
    int *seen = malloc(10 * sizeof(int));
    for(int r = 0; r < 9; r += 3){
        for(int c = 0; c < 9; c += 3){
            memset(seen, 0, 10 * sizeof(int));
            for(int i = r; i < r+3; ++i){
                for(int j = c; j < c+3; ++j){
                    int val = mat[i][j];
                    if(seen[val]){ free(seen); return 0; }
                    seen[val] = 1;
                }
            }
        }
    }
    free(seen);
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int t = 1; t <= n; ++t){
        int **mat = malloc(9 * sizeof(int*));
        for(int i = 0; i < 9; ++i)
            mat[i] = malloc(9 * sizeof(int));
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                scanf("%d", &mat[i][j]);
        printf("Instancia %d\n", t);
        if(check_rows(mat) && check_cols(mat) && check_blocks(mat))
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
        for(int i = 0; i < 9; ++i) free(mat[i]);
        free(mat);
    }
    return 0;
}
