#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned short num_cases, i, sum, j;
    char leds[102];

    /* qtde leds por dig */
    short led_map[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

    scanf("%hd", &num_cases);

    for (j = 0; j < num_cases; ++j)
    {
        sum = 0;
        scanf("%s", leds);

        /* soma leds */
        for (i = 0; i < strlen(leds); ++i)
            sum += led_map[(int)leds[i] - 48];

        printf("%d leds\n", sum);
    }
}
