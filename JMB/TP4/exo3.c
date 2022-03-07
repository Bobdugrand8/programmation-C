#include <stdio.h>
#define MAX 26

int main()
{
    int lgl, lgc, i;
    char c, ml[MAX], mc[MAX];

    printf("Donner votre suite terminée par '.' : ");
    scanf("%c", &c);
    while (c == ' ')
    {
        scanf("%c", &c);
    }
    lgl = 0;

    while (c != ' ' && c != '.' && c != ',')
    {
        ml[lgl] = c;
        lgl++;
        scanf("%c", &c);
    }

    if (lgl == 0)
    {
        printf("aucun mot présent.");
        return 0;
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
        if (lgc > lgl)
        {
            for (i = 0; i < lgc; i++)
                ml[i] = mc[i];
            lgl = lgc;
        }
        while (c == ' ' | c == ',')
            scanf("%c", &c);
    }
    printf("le mot '");
    for (i = 0; i < lgl; i++)
    {
        printf("%c", ml[i]);
    }
    printf("' est le mot le plus long ; il est de longueur : %d", lgl);
}
