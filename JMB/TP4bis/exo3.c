#include <stdio.h>
#include <limits.h>
#define N 10

int main()
{
    int i, X;
    int t[N] = {12, 17, 14, 15, 1, 81, 15, 51, 41, 41};

    X = 13;

    for (i = 0; i < N; i++)
    {
        if (t[i] == X)
        {
            printf("indice min ou l'on trouve x : %d \n", i);
            break;
        }
    }
    if (i == N)
        printf("Il n'y a pas de %d.\n", X);
}
