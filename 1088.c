#include <stdlib.h>
#include <stdio.h>

int inv;   // inversion cnt

int cmp(int a, int b) {
    return a - b;   // cmp ints
}

void merge(int *v, int ini, int mid, int end) {
    int *aux = (int *)malloc((end - ini) * sizeof(int));
    int i = 0, i1 = ini, i2 = mid, n1 = mid, n2 = end;

    while (i1 < n1 && i2 < n2) {
        if (cmp(v[i1], v[i2]) < 0) {
            aux[i++] = v[i1++];
        } else {
            aux[i++] = v[i2++];
            inv += (n1 - i1);  // add inv
        }
    }

    while (i1 < n1) aux[i++] = v[i1++];
    while (i2 < n2) aux[i++] = v[i2++];

    for (int k = ini; k < end; k++)
        v[k] = aux[k - ini];

    free(aux);
}

void merge_sort(int *v, int ini, int end) {
    if (end - ini > 1) {
        int mid = (ini + end) / 2;

        merge_sort(v, ini, mid);
        merge_sort(v, mid, end);
        merge(v, ini, mid, end);
    }
}

int main() {
    int n, *p;

    while (scanf("%d", &n)) {
        if (!n) break;

        p = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);

        inv = 0;
        merge_sort(p, 0, n);

        printf("%s\n", (inv % 2) ? "Marcelo" : "Carlos");

        free(p);
    }

    return 0;
}
