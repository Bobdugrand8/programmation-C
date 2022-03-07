#include <stdio.h>

int entierPositif(void)
{
    int result = 0;
    while (result <= 0 || result > 99)
    {
        scanf("%d", &result);
    }
    return result;
}

void printValue(int largeur, int hauteur, int ligne, int colonne)
{
    if (largeur >= 10 && hauteur < 10)
        printf("(%d,%2d)", ligne, colonne);
    else if (largeur < 10 && hauteur >= 10)
        printf("(%2d,%d)", ligne, colonne);
    else if (largeur >= 10 && hauteur >= 10)
        printf("(%2d,%2d)", ligne, colonne);
    else
        printf("(%d,%d)", ligne, colonne);
}

void printMatrix(int largeur, int hauteur)
{
    for (int ligne = 1; ligne <= hauteur; ligne++)
    {
        for (int colonne = 1; colonne <= largeur; colonne++)
            printValue(largeur, hauteur, ligne, colonne);
        printf("\n");
    }
}

int main(void)
{

    printf("Donner la largeur (entre 1 et 99) :");
    int largeur = entierPositif();
    printf("Donner la hauteur (entre 1 et 99) :");
    int hauteur = entierPositif();

    printMatrix(largeur, hauteur);

    return 0;
}