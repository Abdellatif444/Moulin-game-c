#ifndef GAME_H
#define GAME_H
#include <stdbool.h>

#include "../include/structure.h"
int indice_pion(char c, EtatJeu e);
int PasMouvementMachine(EtatJeu c);
int PasMouvement2(EtatJeu c);
void copier(EtatJeu source, EtatJeu *copie);
EtatJeu h(EtatJeu c);
EtatJeu Minimax(EtatJeu e, int p, int pions_a_placer, bool TourMax);
EtatJeu AlphaBeta(EtatJeu e, int p, int pions_a_placer, bool TourMax, int a, int b);
int moulinForme(Position *UnPlateau, int position, int Pion);
int Voisinages(int source, int PositionTest, EtatJeu c, int joueur);
int pionLibreHorsMoulin(Position *P);
extern int nodes_explored_minimax;
extern int nodes_explored_alphabeta;
#endif // SDL2_H
