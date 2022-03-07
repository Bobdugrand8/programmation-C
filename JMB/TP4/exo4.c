#include <stdio.h>
#define MAX 26

int main()
{
    int lg1, lgc, i, nb;
    char c, m1[MAX], mc[MAX];

    printf("Donner votre suite terminée par '.' : ");
    scanf("%c", &c);
    while (c == ' ')
    {
        scanf("%c", &c);
    }
    lg1 = 0;
    while (c != ' ' && c != '.' && c != ',')
    {
        m1[lg1++] = c;
        scanf("%c", &c);
    }

    if (lg1 == 0)
    {
        printf("aucun mot présent.");
        return 0;
    }
    else
    {
        nb = 1;
    }

    while (c == ' ' | c == ',')
        scanf("%c", &c);

    while (c != '.')
    {
        lgc = 0;
        while (c != ' ' && c != '.' && c != ',')
        {
            mc[lgc++] = c;
            scanf("%c", &c);
        }
        if (lgc == lg1)
        {
            for (i = 0; i < lg1; i++)
                if (m1[i] != mc[i])
                {
                    break;
                }
            if (lg1 == i)
            {
                nb++;
            }
        }
        while (c == ' ' | c == ',')
            scanf("%c", &c);
    }
    printf("Il y a %d apparition(s) du premier mot dans la suite donnée", nb);
}
