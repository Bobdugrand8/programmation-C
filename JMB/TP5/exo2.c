#include <stdio.h>

int calculXPuissN (int x, int n)
{
    if (n == 1) {
        return x;
    }
    if (n % 2 == 0) {
        return calculXPuissN(x*x,n/2);
    } else {
        return x*calculXPuissN(x,n-1);
    }
}


int main(int argc, char const *argv[])
{
    printf("Resultat: %d", calculXPuissN(2,10));
    return 0;
}
