#include <stdio.h>
#include <limits.h>
#define N 10

int main()
{
    int i, min,minindice;
    int t[N] = {12, 17, 14, 15, 1, 81, 15, 51, 41, 41};

    min = INT_MAX;
    minindice = 0;
    
    for (i = 0; i < N; i++)
    {
        if (t[i] < min) 
        {
            min = t[i];
            minindice = i;
        }
    }
    printf("Minimum : %d à l'indice : %d\n", min,minindice);
}
