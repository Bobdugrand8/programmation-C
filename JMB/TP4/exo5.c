#include <stdio.h>
#define MAX 26


int pal (char t[], int size)
{
    int g,d;
    g = 0;
    d = size-1;
    while (t[g] == t[d] && g < d)
    {
        g++;
        d--;
    }
    return (g>=d);
}

int main()
{
    int lgc, nb;
    char c, mc[MAX];

    printf("Donner votre suite terminée par '.' : ");
    scanf("%c", &c);
    while (c == ' ')
    {
        scanf("%c", &c);
    }
    lgc = 0;
    while (c != ' ' && c != '.' && c != ',')
    {
        mc[lgc++] = c;
        scanf("%c", &c);
    }

    if (lgc == 0)
    {
        printf("aucun mot présent.");
        return 0;
    }
    else
    {
        if (pal(mc,lgc))
        {
            nb = 1;
        } else {
            nb = 0;
        }
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
        if (pal(mc,lgc))
        {
            nb++;
        }
        while (c == ' ' | c == ',')
            scanf("%c", &c);
    }
    printf("Il y a %d mot(s) palindrome(s) dans la suite donnée", nb);
}
