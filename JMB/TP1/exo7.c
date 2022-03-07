#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("donner jour :");
    int jour;
    scanf("%d", &jour);
    printf("donner mois :");
    int mois;
    scanf("%d", &mois);
    printf("donner année :");
    int annee;
    scanf("%d", &annee);

    if (mois < 3)
        annee--;
    if (mois >= 3)
        mois -= 2;
    else
        mois += 10;

    int ns = annee / 100;
    int as = annee - ns * 100;

    int f = jour + as + (as / 4) - 2 * ns + (ns / 4) + ((26 * mois - 2) / 10);

    int jourSemaine = f % 7;

    switch (jourSemaine)
    {
    case 0:
        printf("dimanche\n");
        break;
    case 1:
        printf("lundi\n");
        break;
    case 2:
        printf("mardi\n");
        break;
    case 3:
        printf("mercredi\n");
        break;
    case 4:
        printf("jeudi\n");
        break;
    case 5:
        printf("vendredi\n");
        break;
    case 6:
        printf("samedi\n");
        break;
    default:
        break;
    }
}