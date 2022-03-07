#include <stdio.h>

int pgcd (int a, int b);

int pgcd (int a, int b) 
{
    int r = a % b;
    if (r == 0)
    {
        return b;
    } 
    else 
    {
        return pgcd (b,r);
    }
}

int main()
{
    printf("le pgcd de %d et %d est %d ", 1254, 582, pgcd(1254,582));
    return 0;
}
