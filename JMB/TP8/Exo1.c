#include <stdio.h>
#include <stdlib.h>
#include <stdassert.h>

typedef struct maillon
{
    int info;
    struct maillon *suiv;
} MAILLON;

typedef MAILLON *PTR;

PTR nouveauMaillon(int k, PTR s)
{
    PTR t;
    t = malloc(sizeof(MAILLON));
    assert(t != NULL);
    t->info = k;
    t->suiv = s;
    return t;
}

void afficherListe(PTR l)
{
    printf("Contenu de la liste\n-------------------");
    while (l != NULL)
    {
        printf("%6d ", l->info);
        y = y->suiv;
    }
    printf("\n");
}

// Exo 2
PTR rechercheListe(int x, PRT T)
{
    while (T != NULL && T->info != x)
    {
        T = T->suiv
    }
    return T;
}

// Exo 3



// Exo 4
void supprimerListe(int x, PTR *T)
{
    PTR p, c = *T, ture;
    while (c != NULL && c->info != x)
    {
        p = c;
        c = c->suiv;
    }
    if (c != NULL)
    {
        ture = c;
        if (c==*T)
        *T = c->suivi;
        else
        p->suiv = c -> suiv;
        free(ture);
    }
}

// Exo 5
void insererOrdoListe (int x, PTR *T)
{
    PTR p, c = *T;
    while (c != NULL && c->info < x)
    {
        p = c;
        c = c->suiv;
    }
    if (c == *T)
        *T = nouveauMaillon(x,c);
    else
        p->suiv = nouveauMaillon(x,c);
}

//Exo 9
// Partie 1 : refaire exo 2
PTR rechercherListeRecursif(int x, PTR T)
{
    if (T == NULL || T->info == x)
        return T;
        return rechercherListeRecursif(x,T->suiv);
}

// Partie 2 : refaire exo 4
void supprimerListeRecursif(int x, PTR *T)
{
    PTR sbi;
    if (*T != NULL)
        if((*T)->info == x)
        {
            sbi = *T;
            *T = (*T)->suiv;
            free(sbi);
        }
    else
        supprimerListeRecursif(x,&(*T->suivi));
}

// Exo 1
int main(int argc, char const *argv[])
{
    int x;
    PTR l;
    l = NULL;
    printf("Donner la suite d'entier positifs terminée par 0 : ");
    scanf("%d", &x);
    while (x != 0)
    {
        l = nouveauMaillon(x, l);
        scanf("%d", &x);
    }
    afficherListe(l);
    return 0;
}
