#include <stdio.h>

int main(void)
{
    int lignes, colonnes;
    printf("Combien de lignes, colonnes :");
    scanf("%d%d", &lignes, &colonnes);
    for (int ligne = 1; ligne <= lignes; ligne++)
    {
        for (int colonne = 1; colonne <= colonnes; colonne++)
            printf("(%2d,%2d)", ligne, colonne);
        printf("\n");
    }
    return 0;
}