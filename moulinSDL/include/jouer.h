#ifndef JOUER1_H
#define JOUER1_H
#include <stdbool.h>

#include "../include/struct.h"
int PionIndice(char c, etat e);
int BlockageMouvement1(etat c);
int BlockageMouvement2(etat c);
void copier(etat source, etat *copie);
etat h(etat c);

etat AlphaBeta(etat e, int p, int pions_a_placer, bool TourMax, int a, int b);
int MoulinForme(place *UnPlateau, int position, int Pion);
int VoisinagesPion(int source, int PositionTest, etat c, int joueur);
#endif // SDL2_H
