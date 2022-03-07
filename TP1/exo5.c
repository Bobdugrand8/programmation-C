#include <stdio.h> // inclue les entrée-sortie de base

int main(void) {
  // déclarations des variables
  int nbProduitA, nbProduitB;
  float prixHTPorduitA, prixHTPorduitB;

// aquisition des nombres
  printf("Combien de produits A :");
  scanf("%d", &nbProduitA);
  printf("Prix du produit A :");
  scanf("%f", &prixHTPorduitA);
  printf("Combien de produits B :");
  scanf("%d", &nbProduitB);
  printf("Prix du produit B :");
  scanf("%f", &prixHTPorduitB);

  printf( "Produit A : %d x %3.2f €HT = %3.2f €TTC\n",nbProduitA, prixHTPorduitA, nbProduitA*prixHTPorduitA*1.196 );
    printf( "Produit B : %d x %3.2f €HT = %3.2f €TTC\n",nbProduitB, prixHTPorduitB, nbProduitB*prixHTPorduitB*1.196 );
    printf( "Total : %3.2f €TTC\n", (nbProduitB*prixHTPorduitB+nbProduitA*prixHTPorduitA)*1.196 );

  return 0;
}