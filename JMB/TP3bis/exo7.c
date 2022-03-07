#include <stdio.h>
#define MAX 10

void printMatrix(float matrix[MAX][MAX], int sizeL, int sizeC)
{
    for (int lig = 0; lig <= sizeL; lig++)
    {
        for (int col = 0; col <= sizeC; col++)
        {
            printf("%5.1f", matrix[lig][col]);
            if (col == (sizeC - 1))
                printf("  | ");
        }
        printf("\n");
        if (lig == (sizeL - 1))
        {
            for (int pos = 0; pos < 5*(sizeC+1)+4; pos++)
            {
                printf("-");
            }
            printf("\n");
        }
    }
    printf("\n");
}

void updateMatrix(float matrix[MAX][MAX], int sizeL, int sizeC, int i, int j, float x)
{
    if (i >= 0 && i < sizeL && j >= 0 && j < sizeC)
    {
        matrix[i][j] = x;
    }
    for (int posL = 0; posL < sizeL - 1; posL++)
    {
        matrix[sizeL][j] += matrix[posL][j];
    }
    for (int posC = 0; posC < sizeC - 1; posC++)
    {
        matrix[i][sizeC] += matrix[i][posC];
    }
}

int main(void)
{
    printf("Dimension du tableau (x y) : ");
    int sizeL, sizeC;
    scanf("%d%d", &sizeL, &sizeC);
    float matrix[MAX][MAX] = {0};
    int i = 0, j = 0;
    float x = 0;
    while (i >= 0)
    {
        printMatrix(matrix, sizeL, sizeC);
        printf("donner (i, j) x :");
        scanf("%d%d%f", &i, &j, &x);
        updateMatrix(matrix, sizeL, sizeC, i, j, x);
        printf("\n");
    }
    return 0;
}