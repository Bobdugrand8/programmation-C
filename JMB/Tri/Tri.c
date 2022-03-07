#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

#define MAX 10000

void printTable(int table[MAX], size_t size);
void printTable_part(int table[MAX], size_t size, int start);

/**
 * @brief Tri la table par insertion
 * 
 * @param table pointeur vers la table
 * @param start indice du premier élement à trier
 * @param size taille de table
 */
void triParInsertion(int table[], int start, int size)
{
    int i, j;
    int elementCourant;
    for (i = start + 1; i < size; i++)
    {
        elementCourant = table[i];
        for (j = i; j > start && table[j - 1] > elementCourant; j--)
        {
            table[j] = table[j - 1];
        }
        table[j] = elementCourant;
    }
}

/**
 * @brief Tri la table par séléction
 * 
 * @param table pointeur vers la table
 * @param start indice du premier élement à trier
 * @param size taille de table
 */
void triParSelection(int table[],int start, int size)
{
    int i, j, indiceMax, elementTemp;
    for (i = (size - 1); i >= start; i--)
    {
        indiceMax = i;
        for (j = i - 1; j >= start; j--)
        {
            if (table[indiceMax] < table[j])
                indiceMax = j;
        }
        if (i != indiceMax)
        {
            elementTemp = table[i];
            table[i] = table[indiceMax];
            table[indiceMax] = elementTemp;
        }
    }
}

/**
 * @brief Tri la table par échange
 * 
 * @param table pointeur vers la table
 * @param start indice du premier élement à trier
 * @param size taille de table
 */
void triParEchange(int table[],int start, int size)
{
    int i, k, kprim, elemTmp;
    k = (size - 1);
    while (k > start)
    {
        kprim = 0;
        for (i = start; i < k; i++)
        {

            if (table[i] > table[i + 1])
            {
                elemTmp = table[i];
                table[i] = table[i + 1];
                table[i + 1] = elemTmp;
                kprim = i;
            }
        }

        k = kprim;
    }
}

/**
 * @brief 
 * 
 * @param table pointeur vers la table
 * @param start indice du premier élement à trier
 * @param size taille de table
 */
void triParShake(int table[],int start, int size)
{
    int i, kPlus, kMoins, kPrim = 0, elemTmp;
    kPlus = (size - 1);
    kMoins = 0;

    while (kPlus > kMoins)
    {
        for (i = kMoins; i < kPlus; i++)
        {
            if (table[i] > table[i + 1])
            {
                elemTmp = table[i];
                table[i] = table[i + 1];
                table[i + 1] = elemTmp;
                kPrim = i;
            }
        }
        kPlus = kPrim;
        kPrim = kPlus;

        for (i = kPlus; i > kMoins; i--)
        {
            if (table[i] < table[i - 1])
            {
                elemTmp = table[i];
                table[i] = table[i - 1];
                table[i - 1] = elemTmp;
                kPrim = i;
            }
        }
        kMoins = kPrim;
        kPrim = kMoins;
    }
}

/**
 * @brief Tri la table par la méthode "shellSort"
 * 
 * @param table pointeur vers la table
 * @param start indice du premier élement à trier
 * @param size taille de table
 */
void triParShell(int table[],int start, int size)
{
    int i, j, k, m, elemTmp, pas[MAX];
    pas[0] = 1;
    m = 0;
    while (pas[m] < (size / 2)) /* Calcul du pas "idéal" */
    {
        m++;
        pas[m] = pas[m - 1] * 3 + 1;
    }

    // printTable(pas, m); // et affichage :)
    while (m > 0)
    {
        for (k = 0; k < pas[m - 1]; k++)
            for (i = k + pas[m - 1]; i < (size); i = i + pas[m - 1])
            {
                // printf("%d : %d\n", i, pas[m - 1]);
                elemTmp = table[i];
                for (j = i; j - pas[m - 1] >= 0 && table[j - pas[m - 1]] > elemTmp; j = j - pas[m - 1])
                {
                    table[j] = table[j - pas[m - 1]];
                    // printf("Echange %d : %d\n", j, j - pas[m - 1]);
                }
                table[j] = elemTmp;
            }
        m--;
    }
}

/**
 * @brief 
 * 
 * @param g 
 * @param d 
 * @param T 
 */
void placer(int g, int d, int *T)
{
    int i, j, x, place_trouvee;
    x = T[g];      /* x est la valeur à placer */
    i = g;         /* i est la position provisoire de x */
    j = 2 * g + 1; /* j est l’indice de son premier fils */
    place_trouvee = 0;

    while ((j <= d) && !(place_trouvee))
    {

        if (j < d)
            if (T[j + 1] > T[j])
                j = j + 1; /* T[j] est alors le plus grand des fils */
        if (x >= T[j])
            place_trouvee = 1;
        else
        {
            T[i] = T[j]; /* Le plus grand des fils “remonte” */
            i = j;       /* et la place provisoire de x “descend” */
            j = 2 * i + 1;
        }
    }
    T[i] = x; /* i est la position définitive de x */
}

/**
 * @brief 
 * 
 * @param table 
 * @param start 
 * @param size 
 */
void triParHeap(int table[],int start, int size)
{
    int i, j, elemTmp;
    for (i = size / 2; i >= 0; i--)
    {
        placer(i, size, table);
        // printTable(table, size);
    }
    j = size - 1;
    // printf("Fin du premier tas\n");
    while (j > 0)
    {
        elemTmp = table[0];
        table[0] = table[j];
        table[j] = elemTmp;
        // printTable(table, size);
        // printf("Element %d placé, on remet le tas en place \n", j);
        j--;
        placer(0, j, table);
    }
}

/**
 * @brief 
 * 
 * @param table 
 * @param start 
 * @param end 
 * @return int 
 */
int partitionner(int table[], int start, int end)
{
    int p, k1, k2, elemTmp;
    k1 = start;
    k2 = end - 1;
    p = table[rand() % (k2 - k1) + k1];
    //printf("Partition : %d->%d, p[%d]: %d\n", k1, k2, rand() % (k2 - k1) + k1, p);
    while (k1 < k2)
    {
        while (table[k1] <= p && k1 < k2)
            k1++;
        while (table[k2] > p && k2 > k1)
            k2--;
        //printf("Echange %d <-> %d\n", k1, k2);
        elemTmp = table[k1];
        table[k1] = table[k2];
        table[k2] = elemTmp;
    }
    if (k1 == end - 1)
    {
        //printf("IndicePivot +1 : %d\n", k1+1);
        return k1 + 1; 
    }
    else
    {
        //printf("IndicePivot : %d\n", k1);
        return k1;
    }
}

/**
 * @brief 
 * 
 * @param table 
 * @param start 
 * @param size 
 */
void triRapide(int table[], int start, int size)
{
    int indicePivot;
    //printf("%d : %d\n", start, size);
    if (size - start > 15)
    {
        //printTable_part(table, size, start);
        indicePivot = partitionner(table, start, size);
        //printTable_part(table, size, start);
        triRapide(table, start, indicePivot);
        triRapide(table,indicePivot, size);
    }
    else
    {
        // printTable_part(table,size,start);
        // printf("Tri par insertion : %d -> %d\n", start,size);
        triParInsertion(table, start, size);
        // printTable_part(table,size,start);
    }
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 */
void sortedTable(int table[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (table[i - 1] > table[i])
        {
            printf("Le tableau n'est pas trié.\n");
            return;
        }
    }
    printf("Le tableau est trié.\n");
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 */
void randomTable(int table[MAX], size_t size)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        table[i] = rand() % 10000;
    }
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 */
void printTable(int table[MAX], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 * @param start 
 */
void printTable_part(int table[MAX], size_t size, int start)
{
    for (size_t i = start; i < size; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 */
void randomTableSorted(int table[MAX], size_t size)
{
    srand(time(NULL));
    table[0] = rand() % 11;
    for (size_t i = 0; i < size; i++)
    {
        table[i] = table[i - 1] + rand() % 11;
    }
}

/**
 * @brief 
 * 
 * @param taille 
 */
void calculTri(int taille)
{
    struct timeval t1, t2;
    float resultat[10][11];
    int table[MAX], srcTable[MAX];
    long moy = 0;
    for (size_t i = 0; i < 10; i++)
    {

        randomTable(srcTable, taille);
        memcpy(table,srcTable,sizeof(table));
        gettimeofday(&t1, NULL);
        triParInsertion(table,0,taille);
        gettimeofday(&t2, NULL);
        // sortedTable(table, taille);
        resultat[0][i] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));

        memcpy(table,srcTable,sizeof(table));
        gettimeofday(&t1, NULL);
        triParSelection(table,0,taille);
        gettimeofday(&t2, NULL);
        // sortedTable(table, taille);
        resultat[1][i] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));

        memcpy(table,srcTable,sizeof(table));
        gettimeofday(&t1, NULL);
        triParEchange(table,0,taille);
        gettimeofday(&t2, NULL);
        // sortedTable(table, taille);
        resultat[2][i] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));

        memcpy(table,srcTable,sizeof(table));
        gettimeofday(&t1, NULL);
        triParShake(table,0,taille);
        gettimeofday(&t2, NULL);
        // sortedTable(table, taille);
        resultat[3][i] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));

        memcpy(table,srcTable,sizeof(table));
        gettimeofday(&t1, NULL);
        triParShell(table,0,taille);
        gettimeofday(&t2, NULL);
        // sortedTable(table, taille);
        resultat[4][i] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));

        memcpy(table,srcTable,sizeof(table));
        gettimeofday(&t1, NULL);
        triParHeap(table,0,taille);
        gettimeofday(&t2, NULL);
        // sortedTable(table, taille);
        resultat[5][i] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));

        memcpy(table,srcTable,sizeof(table));
        gettimeofday(&t1, NULL);
        triRapide(table,0,taille);
        gettimeofday(&t2, NULL);
        // sortedTable(table, taille);
        resultat[6][i] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));
    }

    randomTableSorted(srcTable, taille);

    memcpy(table,srcTable,sizeof(table));
    gettimeofday(&t1, NULL);
    triParInsertion(table,0,taille);
    gettimeofday(&t2, NULL);
    // sortedTable(table, taille);
    resultat[0][10] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));

    memcpy(table,srcTable,sizeof(table));
    gettimeofday(&t1, NULL);
    triParSelection(table,0,taille);
    gettimeofday(&t2, NULL);
    // sortedTable(table, taille);
    resultat[1][10] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));

    memcpy(table,srcTable,sizeof(table));
    gettimeofday(&t1, NULL);
    triParEchange(table,0,taille);
    gettimeofday(&t2, NULL);
    // sortedTable(table, taille);
    resultat[2][10] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));


    memcpy(table,srcTable,sizeof(table));
    gettimeofday(&t1, NULL);
    triParShake(table,0,taille);
    gettimeofday(&t2, NULL);
    // sortedTable(table, taille);
    resultat[3][10] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));


    memcpy(table,srcTable,sizeof(table));
    gettimeofday(&t1, NULL);
    triParShell(table,0,taille);
    gettimeofday(&t2, NULL);
    // sortedTable(table, taille);
    resultat[4][10] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));
  

    memcpy(table,srcTable,sizeof(table));
    gettimeofday(&t1, NULL);
    triParHeap(table,0,taille);
    gettimeofday(&t2, NULL);
    // sortedTable(table, taille);
    resultat[5][10] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));


    memcpy(table,srcTable,sizeof(table));
    gettimeofday(&t1, NULL);
    triRapide(table,0,taille);
    gettimeofday(&t2, NULL);
    // sortedTable(table, taille);
    resultat[6][10] = (((t2.tv_sec * 1000000) + t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec));
    
    for (size_t i = 0; i < 7; i++)
    {
    printf("---- Tri %d ----\n",i);
    for (size_t j = 0; j < 10; j++)
    {
        moy += resultat[i][j];
    }
    printf("Tableau non trié : nb: %d  = %ld (moyenne sur 10 tableaux)\n", taille, moy / 10); 
    moy = resultat[i][10];
    printf("Tableau trié : nb: %d  = %ld\n", taille, moy);
    }
    

}



int main()
{

    calculTri(500);
    calculTri(1000);
    calculTri(10000);

    // int table[MAX], taille = 10000;
    // randomTable(table, taille);
    // printTable(table, taille);
    // triRapide(table, taille, 0);
    // //printTable(table, taille);
    // sortedTable(table, taille);

    return 1;
}
