#include <stdio.h>

void selection_sort(short *, unsigned short);
int swaps;

int main() {
    unsigned short cases;
    unsigned short num_students;
    int i;

    scanf("%hu", &cases);

    while (cases--) {
        scanf("%hu", &num_students);

        short queue_before[num_students];
        short queue_after[num_students];

        for (i = 0; i < num_students; ++i) {
            scanf("%hd", &queue_before[i]);
            queue_after[i] = queue_before[i];
        }

        swaps = 0;
        selection_sort(queue_after, num_students);

        // conta posições que não mudaram
        for (i = 0; i < num_students; ++i)
            if (queue_before[i] == queue_after[i])
                ++swaps;

        printf("%d\n", swaps);
    }

    return 0;
}

void selection_sort(short *arr, unsigned short size) {
    unsigned short i, j;
    short max_idx, temp;

    for (i = 0; i < size - 1; ++i) {
        max_idx = i;
        for (j = i + 1; j < size; ++j)
            if (arr[j] > arr[max_idx])
                max_idx = j;

        if (i != max_idx) {
            temp = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = temp;
        }
    }
}
