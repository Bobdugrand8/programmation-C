#include <stdio.h>
#include <math.h>

int main(void)
{
    int angle = 0;
    int p;
    printf("Donner le pas :");
    scanf("%d",&p);
    while (angle <= 90)
    {
        printf("sin(%d) : %lf\n",angle, sin((double)angle*M_PI/180));
        angle+=p;
    }
}