#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/**
 * @brief 
 * 
 * @return int 
 */
int entierPositif(void)
{
    int result = 0;
    while (result <= 0 || result > 99)
    {
        scanf("%d", &result);
    }
    return result;
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 */
void fillRandTable(int *table, int size)
{
    srand(time(NULL));
    for (int pos = 0; pos < size; pos++)
    {
        table[pos] = (-15 + rand() % (30 + 1));
    }
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 */
void printTable(int *table, int size)
{
    for (int pos = 0; pos < size; pos++)
    {
        printf("%d ", table[pos]);
    }
    printf("\n");
}
int sumTable(int *table, int size)
{
    int result = 0;
    for (int pos = 0; pos < size; pos++)
    {
        result += table[pos];
    }
    return result;
}

float avgTable(int *table, int size)
{
    return (float)sumTable(table, size) / size;
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 * @return int 
 */
int minTable(int *table, int size)
{
    int result = INT_MAX;
    for (int pos = 0; pos < size; pos++)
    {
        if (table[pos] < result)
        {
            result = table[pos];
        }
    }
    return result;
}

/**
 * @brief 
 * 
 * @param table 
 * @param size 
 */
void positiveTable(int *table, int size)
{
    for (int pos = 0; pos < size; pos++)
    {
        if (table[pos] < 0)
        {
            table[pos] = -table[pos];
        }
    }
}

void fillTableInverseOrder(int *tableSource, int *tableResult, int n)
{
    for (int pos = 0; pos < n; pos++)
        tableResult[pos] = tableSource[n - 1 - pos];
}

void moduloTable(int *tableSource, int *tableResult, int n, int nombre)
{
    for (int pos = 0; pos < n; pos++)
        tableResult[pos] = tableSource[pos] % nombre;
}

int numberOfInTable(int *table, int n, int nombre)
{
    int result = 0;
    for (int pos = 0; pos < n; pos++)
        if (table[pos] == nombre)
            result++;
    return result;
}

int numberOfPairInTable(int *table, int n)
{
    int result = 0;
    for (int pos = 0; pos < n; pos++)
        if (table[pos] % 2 == 0)
            result++;
    return result;
}

void tableWithPairNumber(int *tableSource,int *tableResult, int n, int nR)
{
    printf("nR:%d",nR);
    int index = 0;
    for (int pos = 0; pos < n; pos++)
        if (tableSource[pos] % 2 == 0)
        {
            printf("%d : %d ",pos,tableSource[pos]);
            tableResult[index] = tableSource[pos];
            printf("%d : %d ",pos,tableResult[index]);
            index++;
        }
}

int main(void)
{
    printf("donner une taille :");
    int n = entierPositif();
    int *t1 = malloc(n * sizeof(int));
    fillRandTable(t1, n);
    printTable(t1, n);
    printf("\nLa moyenne de t1 est %2.3f ", avgTable(t1, n));
    printf("\nLa valeur minimale dans t1 est %d\n", minTable(t1, n));

    positiveTable(t1, n);
    printTable(t1, n);

    int *t2 = malloc(n * sizeof(int));
    fillTableInverseOrder(t1, t2, n);

    printTable(t2, n);

    int *t3 = malloc(n * sizeof(int));

    moduloTable(t2, t3, n, 4);
    printTable(t3, n);

    printf("Il y a %d 0 dans t3\n",numberOfInTable(t3,n,0));

    printf("Donner  :");
    int valeur = entierPositif();

    printf("Il y a %d %d dans t3\n",numberOfInTable(t3,n,valeur),valeur);

    int nR = numberOfPairInTable(t3,n); 
    int tpair[nR];
    tableWithPairNumber(t3,tpair,n,nR);

    printTable(t2,n);
    printTable(tpair,nR);
    return 0;
}