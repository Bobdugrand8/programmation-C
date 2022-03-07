#include <stdio.h>

int main(void)
{
    printf("donner a :");
    int a;
    scanf("%d", &a);
    printf("donner b :");
    int b;
    scanf("%d", &b);
    if (a > b)
        printf("a est plus grand que b");
    else if (b > a)
        printf("b est plus grand que a");
    else
        printf("a et b sont égaux");
}