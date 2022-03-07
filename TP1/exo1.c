#include <stdio.h>

int main (void)
{
    int a = 5, b = -4, c = 3;
    printf("a = %d, b = %d, c = %d\n\n",a,b,c);
    int d = a+b;
    b=c;
    d=a+b;
    printf("a = %d, b = %d, c = %d, d = %d\n\n",a,b,c,d);
}