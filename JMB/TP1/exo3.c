#include <stdio.h>

int main(void)
{
    printf("donner un prix :");
    double prix;
    scanf("%lf", &prix);
    prix *= 1.2;
    printf("prix TTC : %f\n", prix);
    int resultat = (int)prix;
    printf("prix TTC arrondi à l'inferieur : %d\n", resultat);
    resultat = (prix + 0.5);
    printf("prix TTC arrondi à l'inferieur : %d\n", resultat);
    resultat = prix * 4+0.5;
    double resultat2 = resultat / 4;
    printf("prix TTC arrondi à l'inferieur : %f\n", resultat2);
}