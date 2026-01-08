#include <stdio.h>

int cmp(int a, int b) {
    return a - b;   // cmp ints
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int ins_sort(int *v, int len) {
    int swp_cnt = 0;

    for (int i = 1; i < len; i++) {
        int j = i, k = j - 1;

        while (k > -1 && cmp(v[j], v[k]) < 0) {
            swap(&v[j], &v[k]);
            swp_cnt++;
            j--, k--;   // decs
        }
    }

    return swp_cnt;
}

int main() {
    int n, l, cars[50];

    scanf("%d", &n);

    for (int t = 0; t < n; t++) {
        scanf("%d", &l);

        for (int i = 0; i < l; i++)
            scanf("%d", &cars[i]);

        printf("Optimal train swapping takes %d swaps.\n",
               ins_sort(cars, l));
    }

    return 0;
}
