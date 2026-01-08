#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned short id;
    unsigned short pos;
} person;

int main() {
    unsigned short num_people, num_left;
    unsigned short i, person_id;
    person queue[51000];

    scanf("%hu", &num_people);
    memset(queue, 0, sizeof(queue));

    // Preenche a fila com id e posição
    for (i = 0; i < num_people; ++i) {
        scanf("%hu", &person_id);
        queue[i].id = person_id;
        queue[person_id].pos = i; // acesso direto pelo id
    }

    scanf("%hu", &num_left);

    // Remove pessoas da fila definindo id = 0
    for (i = 0; i < num_left; ++i) {
        scanf("%hu", &person_id);
        queue[queue[person_id].pos].id = 0;
    }

    // Impressão sem espaços extras no início/fim
    bool first_print = false;
    for (i = 0; i < num_people; ++i) {
        if (queue[i].id) {
            if (first_print)
                printf(" ");
            first_print = true;
            printf("%hu", queue[i].id);
        }
    }

    printf("\n");
    return 0;
}
