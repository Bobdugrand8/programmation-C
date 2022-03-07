#include <stdio.h>

int main(void)
{
    printf("donner un prix :");
    int prix;
    scanf("%d",&prix);
    printf("500 x %d + ", prix / 500);
    prix %= 500;
    printf("200 x %d + ", prix / 200);
    prix %= 200;
    printf("100 x %d + ", prix / 100);
    prix %= 100;
    printf("50 x %d + ", prix / 50);
    prix %= 50;
    printf("20 x %d + ", prix / 20);
    prix %= 20;
    printf("10 x %d + ", prix / 10);
    prix %= 10;
    printf("5 x %d + ", prix / 5);
    prix %= 5;
    printf("2 x %d + ", prix / 2);
    ;
    printf("1 x %d ", prix%2);
}