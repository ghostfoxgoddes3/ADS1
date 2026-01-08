#include <stdio.h>
#include <string.h>

typedef struct {
    short qty;
    short pos;
} qty_t;

/* ord por insercao */
void ins_sort(qty_t v[], unsigned short size);

void main(void)
{
    unsigned short cases, cnt = 0, i, j, k, max;
    char text[201];
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";

    scanf("%hu", &cases);

    while (cases--)
    {
        /* vet letras */
        qty_t letters[26];

        scanf(" %[^\n]", text);

        for (i = 0, k = 0; alpha[i]; ++i, ++k)
        {
            /* conta aparicoes */
            for (j = 0; text[j]; ++j)
                if (alpha[i] == text[j] ||
                    alpha[i] == text[j] - 32 ||
                    alpha[i] == text[j] + 32)
                    ++cnt;

            /* salva dados */
            letters[k].pos = i;
            letters[k].qty = cnt;
            cnt = 0;
        }

        /* ord decresc */
        ins_sort(letters, k);

        /* imprime max */
        for (i = 0; i < k; ++i)
            if (letters[i].qty >= letters[0].qty)
                printf("%c", alpha[letters[i].pos]);

        printf("\n");
    }
}

void ins_sort(qty_t v[], unsigned short size)
{
    int i, j;
    qty_t pivot;

    for (j = 1; j < size; ++j)
    {
        i = j - 1;
        pivot = v[j];

        while ((i >= 0) && (v[i].qty < pivot.qty))
        {
            v[i + 1] = v[i];
            --i;
        }

        v[i + 1] = pivot;
    }
}
