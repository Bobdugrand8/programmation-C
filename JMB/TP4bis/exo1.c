#include <stdio.h>
#define N 10

int main()
{
    int i, nb;
    int t1[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int t2[N] = {12, 17, 14, 15, 1, 81, 15, 51, 41, 41};

    nb = 0;
    
    for (i = 0; i < N; i++)
    {
        if (t1[i] == t2[i]) 
        {
            nb++;
        }
    }
    printf("nb d'éléments identiques : %d\n", nb);
}
