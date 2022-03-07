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

    if (mois == 12 && jour == 31)
    {
        jour = 1;
        mois = 1;
        annee++;
    }
    else if ((mois == 2 && ((((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) && jour == 29) || jour == 28)) || 
            ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour == 30) || 
            jour == 31)
    {
        mois++;
        jour = 1;
    } else {
        jour++;
    }
    printf("%d/%d/%d",jour,mois,annee);
}