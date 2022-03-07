#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Soit a x^2 + b x + c\ndonner a :");
    double a;
    scanf("%lf", &a);
    printf("donner b :");
    double b;
    scanf("%lf", &b);
    printf("donner c :");
    double c;
    scanf("%lf", &c);

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
        printf("les solutions sont x1 = %lf et x2 = %lf", ((-b - sqrt(discriminant)) / 2 * a), ((-b + sqrt(discriminant)) / 2 * a));
    else if (discriminant == 0)
        printf("la solution est xO = %lf", (-b / 2 * a));
    else
        printf("Il n'y a pas de solution réelle");
}