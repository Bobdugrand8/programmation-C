#include <stdio.h>

/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
int somme(int n)
{
  int result = 0;
  for (int index = 1 ; index <= n ; index++)
  result += index;
  return result;
}
/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
int sommeCarre(int n)
{
  int result = 0;
  for (int index = 1 ; index <= n ; index++)
  result += index*index;
  return result;
}


int main(void) {

  int entier;
  printf("Donner un entier positif :");
  scanf("%d", &entier);

  printf("La somme de 1 à %d est %d\n", entier, somme(entier));
  printf("La somme des carrés de 1 à %d est %d\n", entier, sommeCarre(entier));
  return 0;
}