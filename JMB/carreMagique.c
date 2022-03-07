#include <stdio.h>

int main()
{

    int d;
    scanf("%d", &d);
    if (d % 2 == 0)
        return -1;

    int tableau[d][d] = {0};

    // for (int ligne = 0; ligne < d; ligne++)
    //     for (int colonne = 0; colonne < d; colonne++)
    //         tableau[ligne][colonne] = 0;

    // première case :
    int col = d / 2, lig = col - 1, index = 2;
    tableau[lig][col] = 1;
    lig--;
    col++;
    while (index <= d * d)
    {
        if (lig < 0)
            lig += d;
        if (col < 0)
            col += d;
        if (col >= d)
            col -= d;

        if (tableau[lig][col] == 0)
        {
            tableau[lig][col] = index;
            index++;
            lig--;
            col++;
        }
        else
        {
            col--;
            lig--;
        }
    }

    for (int ligne = 0; ligne < d; ligne++)
    {
        for (int colonne = 0; colonne < d; colonne++)
            printf("%3d ", tableau[ligne][colonne]);
        printf("\n");
    }
}