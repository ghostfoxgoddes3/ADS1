#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main(void)
{
    unsigned short cases;
    short len_1, len_2;
    char str_1[1100], str_2[1100];

    scanf("%hu", &cases);

    while (cases--)
    {
        /* le strings */
        scanf("%s %s", str_1, str_2);

        len_1 = strlen(str_1);
        len_2 = strlen(str_2);

        /* compara finais */
        if (len_1 == len_2)
        {
            if (strcmp(str_1, str_2) == 0)
                printf("encaixa\n");
            else
                printf("nao encaixa\n");
        }
        else if (len_1 < len_2)
            printf("nao encaixa\n");
        else if (strstr(&str_1[len_1 - len_2 - 1], str_2))
            printf("encaixa\n");
        else
            printf("nao encaixa\n");
    }
}
