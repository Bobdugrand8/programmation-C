#include <stdio.h>
#include <limits.h>
#define N 10

int main()
{
    int i, X;
    int t[N] = {12, 17, 14, 15, 1, 81, 15, 51, 41, 41};

    X = 13;

    for (i = 0; i < N; i++)
    {
        if (t[i] == X)
        {
            printf("indice min ou l'on trouve x : %d \n", i);
            break;
        }
    }
    if (i == N)
        printf("Il n'y a pas de X.\n");
}

/*
RECHERCHE DICHOTOMIQUE DANS UN TABLEAU ORDONNE. On considère un tableau T de N nombres entiers deux à deux distincts, rangés par ordre croissant, et un nombre X. Ecrivez un programme qui détermine l’indice exprimant soit le rang de X dans T soit, si X ne figure pas dans T, le rang de l’emplacement dans lequel il faudrait ranger X pour l’insérer dans le tableau, en conservant trié ce dernier.
Principe : considérer deux indices i et j tels que le sous-tableau [ ti ... tj ] soit seul susceptible de contenir X (initiale- ment, i = 0 et j = N-1). En comparant X et l’élément du milieu, déterminer celle des deux moitiés du sous-tableau qui est susceptible de contenir X. Recommencer cette opération jusqu’à déterminer une unique position du tableau.
Estimez le nombre moyen d’opérations faites par ce programme et par celui du n° 4. Estimez le nombre moyen d’opérations faites par l’une et l’autre méthode, lorsque la recherche d’un élément qui ne figure pas dans le tableau doit être suivie de son insertion.
*/