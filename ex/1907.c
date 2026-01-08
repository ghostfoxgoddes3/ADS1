#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Node;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Aloca grid
    char **grid = malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        grid[i] = malloc((M + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }

    // visited como char (mais rápido e menor)
    char **visited = malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++)
        visited[i] = calloc(M, sizeof(char));

    // Fila única para todo programa (M * N posições)
    Node *queue = malloc(N * M * sizeof(Node));

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int clicks = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (grid[i][j] == '.' && !visited[i][j]) {

                clicks++;

                int front = 0, back = 0;
                visited[i][j] = 1;
                queue[back++] = (Node){i, j};

                // BFS rápido
                while (front < back) {
                    Node u = queue[front++];

                    for (int k = 0; k < 4; k++) {
                        int nx = u.x + dx[k];
                        int ny = u.y + dy[k];

                        if ((unsigned)nx < (unsigned)N && (unsigned)ny < (unsigned)M) {
                            if (!visited[nx][ny] && grid[nx][ny] == '.') {
                                visited[nx][ny] = 1;
                                queue[back++] = (Node){nx, ny};
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", clicks);

    // liberar memória
    for (int i = 0; i < N; i++) {
        free(grid[i]);
        free(visited[i]);
    }
    free(grid);
    free(visited);
    free(queue);

    return 0;
}
