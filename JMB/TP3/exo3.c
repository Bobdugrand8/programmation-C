#include <stdio.h>

int main(void)
{
    int nb = 0, lg1 = 0, lgc = 0;
    char c = getchar();
    
    while (c != ' ' && c != '.')
    {
        lg1++;
        c = getchar();
    }
    printf("%d \n", lg1);
    while (c != '.')
    {
        lgc = 0;
        c = getchar();
        while (c != ' ' && c != '.')
        {
            lgc++;
            c = getchar();
        }
        if (lg1 == lgc)
            nb++;
    }
    printf("il y a %d mots de même longueur que le premier mot dans la suite donnée", nb);
}

// ola, le beau paysage, comme sont belles les feuilles en automne.