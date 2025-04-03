#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct Position
{
    char lettre;
    int joueur;
    int couleur;
    char v1, v2, v3, v4; /// voisins de chaque position sur la grille
} Position;
typedef struct EtatJeu
{
    Position position[24];
    int nombrePionsMachine; /// nombre de pions sur table
    int nombrePionsHumain;
    int coutEtat;         /// cout de chaque etat
    int positionActuelle; /// position de chaque pion
    int precedent;
    int pionCaptureAdversaire; /// pion capture de l'adversaire

} EtatJeu;

typedef struct Noeud
{
    struct Noeud *suivant;
    EtatJeu Etat;
} Noeud;

static int nombreNoeuds = 0;

#endif // STRUCT_H_INCLUDED
