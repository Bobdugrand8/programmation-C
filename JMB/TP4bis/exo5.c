#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void printTable(int table[], int sizeTable);
void createSortedTable(int table[], int dim);
void merge2Table(int table1[], int sizeTable1, int table2[], int sizeTable2, int tableResult[]);

int main(void)
{

    int tableA[MAX] = {0};
    int sizeTableA = 15;
    createSortedTable(tableA, sizeTableA);
    int tableB[MAX] = {0};
    int sizeTableB = 3;
    createSortedTable(tableB, sizeTableB);

    printf("Table A \n");
    printTable(tableA, sizeTableA);
    printf("Table B \n");
    printTable(tableB, sizeTableB);

    int tableC[MAX];
    merge2Table(tableA,sizeTableA,tableB,sizeTableB,tableC);
    int sizeTableC = sizeTableA + sizeTableB;
    printf("Table C \n");
    printTable(tableC, sizeTableC);

    return 0;
}

void merge2Table(int table1[], int sizeTable1, int table2[], int sizeTable2, int tableResult[])
{
    int pos1 = 0, pos2 = 0, posRes = 0;

    while ((pos1 < sizeTable1) || (pos2 < sizeTable2))
    {
        if ((pos2 >= sizeTable2) || ((pos1 < sizeTable1) && (table1[pos1] < table2[pos2])))
        {
            tableResult[posRes] = table1[pos1];
            pos1++;
            posRes++;
            printf("T1 : %d\n",posRes);
        }
        else
        {
            tableResult[posRes] = table2[pos2];
            pos2++;
            posRes++;
            printf("T2 : %d\n",posRes);
        }
    }
}

void printTable(int table[], int sizeTable)
{
    for (int pos = 0; pos < sizeTable; pos++)
        printf("%4d", table[pos]);
    printf("\n");
}

void createSortedTable(int table[], int dim)
{
    srand(time(NULL));
    table[0] = rand()%11;
    for (int pos = 1; pos < dim; pos++)
        table[pos] = table[pos - 1] + rand()%11;
}