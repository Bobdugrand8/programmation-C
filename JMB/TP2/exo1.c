#include <stdio.h>

int main(void)
{
    int nb = 0;
    char c = ' ';

    while (c != '.')
    {
        c = getchar();
        if (c == 'l')
            nb++;
    }
    printf("il y a %d 'l' dans la suite donnée", nb);
}