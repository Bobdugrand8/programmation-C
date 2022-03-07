#include <stdio.h>

/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
void tableDeMultiplication(int n)
{
  printf("Table de multiplication de %d\n", n);
  for (int index = 1 ; index <= 10 ; index++)
    printf("%d x %d = %d\n", index, n, index*n);
}

int main(void) {

  int entier;
  printf("Donner un entier positif :");
  scanf("%d", &entier);

  tableDeMultiplication(entier);
  return 0;
}