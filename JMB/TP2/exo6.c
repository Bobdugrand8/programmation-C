#include <stdio.h>

int main(void)
{
    int nb = 0;
    char c = ' ';

    while (c != '.')
    {
        c = getchar();
        while (c != ' ' && c != '.')
        {
            c = getchar();
        }
        if (c != '.')
            nb++;
        while (c == ' ')
        {
            c = getchar();
        }
    }

    printf("il y a %d mots dans la suite donnée", nb);
}

// Ola, le beau paysage, comme sont belles les feuilles en automne .