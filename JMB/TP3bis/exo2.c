#include <stdio.h>
#include <math.h>

int main(void)
{
    int angle = 0;
    while (angle <= 90)
    {
        printf("sin(%d) : %lf\n",angle, sin((double)angle*M_PI/180));
        angle+=15;
    }
}