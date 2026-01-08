#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned short tests, shift;
    unsigned short i, j;

    scanf("%hd", &tests);

    for (i = 0; i < tests; ++i)
    {
        char word[50], ch;

        /* le palavra */
        scanf("%s", word);

        /* le desloc */
        scanf("%hd", &shift);

        /* aplica cifra */
        for (j = 0; j < strlen(word); ++j)
        {
            if (word[j] - shift < 'A')
            {
                ch = '[' - (shift - (word[j] - 'A'));
                printf("%c", ch);
            }
            else
            {
                ch = word[j] - shift;
                printf("%c", ch);
            }
        }

        printf("\n");
    }
}
