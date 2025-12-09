#include <stdio.h>
#include <string.h>

void main(void)
{
    char word[1100], tmp;
    unsigned cases;
    unsigned short i, j, len, half_len;

    scanf("%u", &cases);

    while (cases)
    {
        scanf(" %[^\n]", word);

        len = strlen(word);
        half_len = len / 2;

        /* pass 1: shift letras +3 */
        for (i = 0; i < len; ++i)
            if ((word[i] >= 'A' && word[i] <= 'Z') ||
                (word[i] >= 'a' && word[i] <= 'z'))
                word[i] = word[i] + 3;

        /* pass 2: inverte str */
        for (i = 0, j = len - 1; i < half_len; ++i, --j)
        {
            tmp = word[j];
            word[j] = word[i];
            word[i] = tmp;
        }

        /* pass 3: metade final -1 */
        for (i = half_len; i < len; ++i)
            if (word[i] >= 32 && word[i] <= 176)
                word[i] = word[i] - 1;

        printf("%s\n", word);

        /* limpa buf */
        memset(word, 0, sizeof(word));

        --cases;
    }
}
