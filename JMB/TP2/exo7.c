#include <stdio.h>

int main(void)
{
    int nb = 0;
    char c = ' ', p = ' ';

    while (c != '.')
    {
        p = c;
        c = getchar();
        if (p != ' ' && p != '.' && (c == ' ' || c == '.'))
            nb++;
    }
    printf("il y a %d mots dans la suite donnée", nb);
}

//    Ola,  le beau   paysage,   comme sont belles les feuilles en automne  .