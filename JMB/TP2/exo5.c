#include <stdio.h>

int main(void)
{
    int nb = 0;
    char c = ' ', p = ' ', pp = ' ';

    while (c != '.')
    {
        pp = p;
        p = c;
        c = getchar();
        if (pp == 'l' && p == 'e' && c == 's')
            nb++;
    }
    printf("il y a %d 'les' dans la suite donnée", nb);
}