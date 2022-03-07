#include <stdio.h>

int main(void)
{
    int nb = 1;
    char cour = ' ', prem;

    prem = getchar();
    while (cour != '.')
    {
        cour = getchar();
        if (cour == prem)
            nb++;
    }
    printf("il y a %d '%c' dans la suite donnée", nb,prem);
}

// ola, le beau paysage, comme sont belles les feuilles en automne.