#include <stdio.h>

int main(void)
{
    int nb = 0;
    char c = ' ', p = ' ';

    while (c != '.')
    {
        p = c;
        c = getchar();
        if (c == 'e' && p == 'l')
            nb++;
    }
    printf("il y a %d 'le' dans la suite donnée", nb);
}