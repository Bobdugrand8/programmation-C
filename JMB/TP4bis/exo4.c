#include <stdio.h>
#include <limits.h>
#define N 10

int main()
{
    int i = 0, X;
    int t[N] = {12, 17, 14, 15, 1, 81, 15, 51, 41, 41};

    X = 13;

    while(i < N && t[i] != X)
    {  
        i++;
    }
    if (i == N)
        printf("Il n'y a pas de X.\n");
    else
        printf("indice min ou l'on trouve x : %d \n", i);
}
