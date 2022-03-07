#include <stdio.h>

int main(void)
{
    double prix = -1, prixTotal = 0;
    int nb = 0;
    while (prix != 0)
    {
        printf("donner un prix :");
        scanf("%lf", &prix);
        printf("prix TTC : %.2f\n", prix * 1.2);
        nb++;
        prixTotal += prix;
    }
    printf("%d produit(s) : Total prix TTC : %.2f\n", nb, prixTotal * 1.2);
}