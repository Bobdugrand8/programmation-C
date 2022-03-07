#include <stdio.h> // inclue les entrée-sortie de base

int main(void)
{
  printf("Donner un nombre :\n");
  int nombre, result;
  scanf("%d", &nombre);
  result = nombre * nombre;

  printf("le carré de %d est %d\n\n", nombre, result);
  printf("L'adresse de nombre est %pd\nL'adresse de resultat est %pd\n", &nombre, &result);
  return 0;
}