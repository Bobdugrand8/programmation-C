#include <stdio.h>
#define MAX 15

typedef struct
{
    char t[MAX];
    int lg;
} NR;

int val(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
        break;
    }
}

int Romain_Entier(NR x)
{
    int v;
    int res = val(x.t[x.lg - 1]);

    for (int i = 0; i < x.lg - 1; i++)
    {
        v = val(x.t[i]);
        if (v < val(x.t[i + 1]))
            res -= v;
        else
            res += v;
    }
    return res;
}

void ajouter(int k, NR *x, char S1, char S5, char S10)
{

    switch (k)
    {
    case 4:
        x->t[x->lg++] = S1;
    case 5:
    case 6:
    case 7:
    case 8:
        x->t[x->lg++] = S5;
        k -= 5;
    case 0:
    case 1:
    case 2:
    case 3:
        for (int i = 1; i <= k; i++)
            x->t[x->lg++] = S1;
        break;
    case 9:
        x->t[x->lg++] = S1;
        x->t[x->lg++] = S10;
        break;
    }
}

void Entier_Romain(int n, NR *x)
{
    x->lg = 0;
    int t = n / 1000;
    n %= 1000;
    ajouter(t, x, 'M', ' ', ' ');
    t = n / 100;
    n %= 100;
    ajouter(t, x, 'C', 'D', 'M');
    t = n / 10;
    n %= 10;
    ajouter(t, x, 'X', 'L', 'C');
    ajouter(n, x, 'I', 'V', 'X');
}

void afficherNR(NR x)
{
    for (int i = 0; i < x.lg; i++)
        printf("%c", x.t[i]);
}

int main()
{
    NR y;
    for (int v = 1; v <= 3999; v++)
    {
        printf("%5d -> ", v);
        Entier_Romain(v, &y);
        afficherNR(y);
        printf(" -> %5d \n", Romain_Entier(y));
    }
}