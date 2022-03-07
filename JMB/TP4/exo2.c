#include <stdio.h>
#define MAX 100

int main()
{
    int e;      /* contiendra successivement dans le temps les entiers lus */
    int t[MAX]; /* contiendra la suite des entiers lus ≠ 0 */
    int n;      /* contiendra le nombre d'entiers memorises */
    int i;      /* indice de parcours du tableau t */

    e = 1;
    n = 0;

    while (e > 0 && n < 100)
    {
        scanf("%d", &e);
        i = 0;
        while (i < n && t[i] != e)
            i++;
        if (i == n)
            t[n++] = e;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", t[i]);
    }
    return 0;
}