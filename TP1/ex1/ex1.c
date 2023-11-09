#include "../tp1.h"

sac generer(int taille, int poids_max) {
    sac bag;
    bag.taille = taille;
    bag.poids_max = poids_max;
    return bag;
}

int calculer_poids(bits b, sac s) {
    int poid = 0;
    for (int i = 0; i < s.taille; i++)
    {
        poid += b.bit[i] * s.objets[i].poids;
    }
    return poid;
}

int calculer_valeur(bits b, sac s) {
    int valeur = 0;
    for (int i = 0; i < s.taille; i++)
    {
        valeur += b.bit[i] * s.objets[i].valeur;
    }
    return valeur;
}

void afficher(sac s) {
    printf("poids max : %d \n", s.poids_max);
    printf("i : ");
    for(int i = 0; i < s.taille; i++) {
        printf("%2d ", i);
    }
    printf("\np : ");
    for (int p = 0; p < s.taille; p++)
    {
        printf("%2d ", s.objets[p].poids);
    }
    printf("\nv : ");
    for (int v = 0; v < s.taille; v++)
    {
        printf("%2d ", s.objets[v].valeur);
    }
    printf("\nb : ");
    for (int b = 0; b < s.taille; b++)
    {
        printf("%2d ", s.etat.bit[b]);
    }
    printf("\npoids : %d\nvaleur : %d\n", calculer_poids(s.etat, s), calculer_valeur(s.etat, s));
}

void traiter(bits b, sac *s) {
    if (calculer_poids(s->etat, *s) < calculer_poids(b, *s) &&
    calculer_valeur(s->etat, *s) < calculer_valeur(b, *s))
    {
        printf("nouveau meilleur sac\n");
        s->etat = b;
    }
}

bits generer_bits(int taille) {
    bits b;
    for (int i = 0; i < taille; i++)
    {
        b.bit[i] = rand() % 2;
    }
    return b;
}

sac fillBag(sac bag) {
    for (int i = 0; i < bag.taille; i++)
    {
        bag.objets[i].poids = rand() % 11;
        bag.objets[i].valeur = rand() % 11;
        bag.etat.bit[i] = rand() % 2;
    }
    bag.etat.bit[1] = 1;
    return bag;
}

void afficher_bits(bits b, int taille) {
    for (int i = 0; i < taille; i++)
    {
        printf("%d ", b.bit[i]);
    }
    printf("\n");
}

int main() {
    sac bag = generer(5, 16);
    bag = fillBag(bag);
    afficher(bag);
    bits bit = generer_bits(5);
    afficher_bits(bit, bag.taille);
    traiter(bit, &bag);
    afficher(bag);

    return 0;
}

