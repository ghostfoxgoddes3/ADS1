#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void main(void)
{
    char phrase[1100];
    unsigned short cases, qty_letters = 0, i, j, alpha_len, phrase_len;
    bool has_letter = false;

    scanf("%hu", &cases);

    while (cases--)
    {
        /* alfabeto base */
        char alpha[30] = {
            'a','b','c','d','e','f','g','h','i','j','k','l','m',
            'n','o','p','q','r','s','t','u','v','w','x','y','z','\0'
        };

        scanf(" %[^\n]", phrase);

        alpha_len = strlen(alpha);
        phrase_len = strlen(phrase);

        /* percorre frase */
        for (i = 0; i < phrase_len; ++i)
        {
            /* verifica letra */
            for (j = 0; j < alpha_len; ++j)
                if (phrase[i] == alpha[j])
                {
                    has_letter = true;
                    alpha[j] = '1'; /* marca uso */
                    break;
                }

            if (has_letter)
                ++qty_letters;

            has_letter = false;
        }

        /* classifica frase */
        if (qty_letters == 26)
            printf("frase completa\n");
        else if (qty_letters > 12 && qty_letters < 26)
            printf("frase quase completa\n");
        else
            printf("frase mal elaborada\n");

        qty_letters = 0;

        /* limpa buf */
        memset(phrase, 0, sizeof(phrase));
    }
}
