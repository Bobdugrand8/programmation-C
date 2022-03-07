#include <stdio.h>

int main(void)
{
    int casier[21] = {0};
    int nombre;
    scanf("%d", &nombre);
    while (nombre >= 00 && nombre <= 20)
    {
        casier[nombre]++;
        scanf("%d", &nombre);
    }
    for (int pos = 0; pos < 21; pos++)
    {
        printf("%d:%d  ", pos, casier[pos]);
    }
    printf("\n");
    return 0;
}