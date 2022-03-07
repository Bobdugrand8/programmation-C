#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 4
#define NBPROP 12
#define MAXREP 2
#define TRUE 1
#define FALSE 0

void couleur(int num)
{
    switch (num)
    {
    case 0:
        printf("rouge ");
        break;
    case 1:
        printf("vert ");
        break;
    case 2:
        printf("bleu ");
        break;
    case 3:
        printf("orange ");
        break;
    case 4:
        printf("rose ");
        break;
    case 5:
        printf("jaune ");
        break;
    case 6:
        printf("blanc ");
        break;
    case 7:
        printf("noir ");
        break;
    default:
        break;
    }
}

void mixTable(int table[], int size)
{

    int pos, j, temp;
    for (pos = 0; pos < size; pos++)
    {
        table[pos] = pos;
    }
    srand(time(NULL));
    for (int pos = 0; pos < size - 1; pos++)
    {
        j = pos + rand() % (size - pos);
        temp = table[pos];
        table[pos] = table[j];
        table[j] = temp;
    }
}

void ressemblence(int R1[MAX], int R2[MAX], int T[MAX])
{
    int rep[MAX] = {0};
    for (int pos = 0; pos < MAX; pos++)
    {
        if (R1[pos] == R2[pos])
            rep[pos] = 1;
    }
    for (int pos = 0; pos < MAX; pos++)
    {
        if (rep[pos] != 1)
            for (int index = 0; index < MAX; index++)
                if (rep[index] == 0 && R1[pos] == R2[index])
                {
                    rep[index] = 2;
                    break; // Des qu'on a trouver un résultat on s'arrete
                }
    }
    T[0] = 0;
    T[1] = 0;
    for (int pos = 0; pos < MAX; pos++)
    {
        T[0] += rep[pos] % 2;
        T[1] += rep[pos] / 2;
    }
}

void printTable(int table[], int size)
{
    for (int pos = 0; pos < size; pos++)
    {
        printf("%d ", table[pos]);
    }
    printf("\n");
}

void combinaison2Propositions(int prop, int t[MAX])
{
    t[0] = prop / (8 * 8 * 8);
    prop %= (8 * 8 * 8);
    t[1] = prop / (8 * 8);
    prop %= (8 * 8);
    t[2] = prop / 8;
    t[3] = prop % 8;
}

int compareTable(int t1[], int t2[], int size)
{
    for (int pos = 0; pos < size; pos++)
    {
        if (t1[pos] != t2[pos])
            return FALSE;
    }
    return TRUE;
}

void afficherProposition(int propositions[MAX], int couleurs[8], int nbPropositions)
{
    printf("Proposition n°%d :\n", nbPropositions + 1);
    for (int pos = 0; pos < MAX; pos++)
        couleur(couleurs[propositions[pos]]);
    printf("\n");
}

int faireProposition(int propositions[NBPROP][MAX], int reponses[NBPROP][MAXREP], int nbPropositions, int combinaisons)
{
    int eligible = TRUE, pos = 0, combinaisonInitiale = combinaisons;
    int rep[MAXREP], prop[MAX];
    while ((pos < nbPropositions))
    {
        pos = 0;
        eligible = TRUE;
        combinaisons++;
        combinaison2Propositions(combinaisons, prop);
        while (eligible && pos < nbPropositions)
        {
            ressemblence(propositions[pos], prop, rep);
            if (!compareTable(rep, reponses[pos], MAXREP))
            {
                eligible = FALSE;
            }
            else
            {
                pos++;
            }
        }
        if (combinaisons == 4096) {
            combinaisons = 0;
        }
        if (combinaisons == combinaisonInitiale)
            break;
    }
    if (nbPropositions == 0)
    {
        combinaison2Propositions(combinaisons, prop);
    }
    for (int pos = 0; pos < MAX; pos++)
    {
        propositions[nbPropositions][pos] = prop[pos];
    }
    return combinaisons;
}

int main()
{
    int propositions[NBPROP][MAX] = {0};
    int reponses[NBPROP][MAXREP] = {0};
    int couleurs[8] = {0};
    mixTable(couleurs, 8);

    int combinaisons = rand()%4096;
    int nbPropositions = 0;

    // Première proposition et affichage de la proposition
    // combinaison2Propositions(combinaisons, propositions[nbPropositions]);
    // afficherProposition(propositions[nbPropositions], couleurs, nbPropositions);

    while ((nbPropositions <= 12) && (reponses[nbPropositions][0] != 4))
    {
        combinaisons = faireProposition(propositions, reponses, nbPropositions, combinaisons);
        afficherProposition(propositions[nbPropositions], couleurs, nbPropositions);
        printf("Combien de couleurs bien placé ?");
        scanf("%d", &reponses[nbPropositions][0]);
        printf("Combien de couleurs mal placé ?");
        scanf("%d", &reponses[nbPropositions][1]);
        if (nbPropositions > 12)
        {
            printf("L'ordinateur a perdu en %d essais\n", nbPropositions + 1);
            break;
        }
        else if (reponses[nbPropositions][0] == 4)
        {
            printf("L'ordinateur a gagné en %d essais\n", nbPropositions + 1);
            break;
        }
        else
        {
            nbPropositions++;
        }
    }

    /*
     int t1[MAX] = {1, 2, 2, 3};
     int t2[MAX] = {2, 2, 1, 1};
     int res[MAXREP] = {0};
     ressemblence(t1, t2, res);
     printTable(t1, MAX);
     printTable(t2, MAX);
     printTable(res, MAXREP);
    */
}