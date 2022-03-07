#include <stdio.h>

int main(void)
{
    int nb = 0, lg = 4, lgc = 0;
    char c = ' ';

    while (c != '.')
    {
        lgc = 0;
        c = getchar();
        while (c != ' ' && c != '.')
        {
            lgc++;
            c = getchar();
        }
        if (lg == lgc)
            nb++;
    }
    printf("il y a %d mots de longueur %d dans la suite donnée", nb,lg);
}

// ola, le beau paysage, comme sont belles les feuilles en automne.