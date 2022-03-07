#include <stdio.h>
#include <math.h>

int main(void)
{

    int p, b, a;
    printf("Donner le pas :");
    scanf("%d", &p);
    printf("Donner la borne a :");
    scanf("%d", &a);
    printf("Donner la borne b :");
    scanf("%d", &b);
    int angle = a;
    while (angle <= b)
    {
        printf("sin(%d) : %lf\n", angle, sin((double)angle * M_PI / 180));
        angle += p;
    }
}