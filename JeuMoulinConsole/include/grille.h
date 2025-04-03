#ifndef GRILLE_H
#define GRILLE_H

#include "../include/structure.h"

int ObtenirChoixInitial();

void AfficherPlateau(EtatJeu e);
void AfficherGrille(EtatJeu e);
void DemarrerJeu(EtatJeu e);
int ObtenirChoixUtilisateur(int Joueur, EtatJeu *e);
void AfficherPion();
extern int NbPionsPoses;

#endif // GRILLE_H
