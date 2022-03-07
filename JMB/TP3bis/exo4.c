#include <stdio.h>

int main(void)
{
    int nb;
    printf("Combien de nombre :");
    scanf("%d", &nb);
    int tableau[nb];
    for (int pos = 0; pos < nb; pos++)
    {
        scanf("%d", &tableau[nb - 1 - pos]);
    }
    for (int pos = 0; pos < nb; pos++)
    {
        printf("%d ", tableau[pos]);
    }
    printf("\n");
}