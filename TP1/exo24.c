#include <stdio.h>

void carre(int largeur, int hauteur)
{
  for (int ligne = 1; ligne <= hauteur; ligne++)
  {
    for (int colonne = 1; colonne <= largeur; colonne++)
      printf("*");
    printf("\n");
  }
}

void triangleInf(int d)
{
  for (int ligne = 1; ligne <= d; ligne++)
  {
    for (int colonne = 1; colonne <= ligne; colonne++)
      printf("*");
    printf("\n");
  }
}

void carreVide(int largeur, int hauteur)
{
  for (int ligne = 1; ligne <= hauteur; ligne++)
  {

    for (int colonne = 1; colonne <= largeur; colonne++)
      if ((colonne == 1 || colonne == largeur) || ligne == 1 || ligne == hauteur)
        printf("*");
      else
        printf(" ");
    printf("\n");
  }
}

int main(void)
{

  int entier = 0;
  printf("Combien voulez-vous d'étoiles :");

  while (entier <= 0)
  {
    scanf("%d", &entier);
  }

  // partie 1
  for (int pos = 1; pos <= entier; pos++)
    printf("*");

  printf("\n\n");
  // partie 2
  int largeur = 0;
  printf("Donner la largueur (entier positif) :");
  while (largeur <= 0)
  {
    scanf("%d", &largeur);
  }
  int hauteur = 0;
  printf("Donner la largueur (entier positif) :");
  while (hauteur <= 0)
  {
    scanf("%d", &hauteur);
  }

  carre(largeur, hauteur);
  printf("\n\n");
  triangleInf(hauteur);
  printf("\n\n");
  carreVide(largeur, hauteur);

  return 0;
}