#include <stdio.h>

int main(void)
{
    printf("donner un prix :");
    double prix;
    scanf("%lf", &prix);
    printf("prix TTC : %.2f", prix * 1.2);
}