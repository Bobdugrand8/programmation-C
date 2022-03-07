#include <stdio.h>

int main(void)
{
    int entier = 0, total = 0;
    int nb = 0;
    while (entier >= 0)
    {
        printf("Donner un entier :");
        scanf("%d", &entier);
        total += entier;
        nb++;
    }
    total -= entier;
    nb--;
    printf("La moyenne est de %lf\n", ((double)total) / nb);
}