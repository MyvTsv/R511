#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 1000
#define POIDS_MAX 1000

typedef struct objet {
    int poids;
    int valeur;
} objet;

typedef struct bits {
    int bit[TAILLE_MAX];
} bits;

typedef struct sac {
    objet objets[TAILLE_MAX];
    bits etat;
    int taille;
    int poids_max;
} sac;

sac generer(int taille, int poids_max);
void afficher(sac s);

void echanger(sac *s, int i, int j);
void melanger(sac *s);
void monte_carlo(int n, sac *s);

void trier(sac *s);
void glouton(sac *s);

void creer_tableau(int **T, sac s);
void afficher_tableau(int **T, sac s);
void resoudre(sac *s);
