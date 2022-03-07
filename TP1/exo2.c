#include <stdio.h>

int main(void)
{
    float x, y, tmp;

    printf("Donner x:");
    scanf("%f", &x);
    printf("Donner y:");
    scanf("%f", &y);

    printf("x = %f, y = %f", x, y);

    tmp = x;
    x = y;
    y = tmp;

    printf("x = %f, y = %f", x, y);

    return 0;
}