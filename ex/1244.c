#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int count_words;
char words[100][100];

int cmp_len(char *a, char *b) {
    return strlen(b) - strlen(a);  // len cmp
}

void ins_sort() {   // insertion sort
    char tmp[100];

    for (int i = 1; i < count_words; i++) {
        int j = i, k = j - 1;

        while (k > -1 && cmp_len(words[j], words[k]) < 0) {
            strcpy(tmp, words[j]);
            strcpy(words[j], words[k]);
            strcpy(words[k], tmp);
            j--, k--;   // decs
        }
    }
}

int main() {
    int n;
    char line[10000], *tok;

    scanf("%d\n", &n);

    for (int x = 0; x < n; x++) {
        scanf("%[^\n]\n", line);

        count_words = 0;
        tok = strtok(line, " ");

        while (tok != NULL) {
            strcpy(words[count_words++], tok);
            tok = strtok(NULL, " ");   // nxt
        }

        ins_sort();  // sort

        printf("%s", words[0]);
        for (int i = 1; i < count_words; i++)
            printf(" %s", words[i]);

        printf("\n");
    }

    return 0;
}
