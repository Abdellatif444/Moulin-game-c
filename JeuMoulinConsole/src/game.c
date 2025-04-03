#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#include "../include/structure.h"
int nodes_explored_minimax = 0;
int nodes_explored_alphabeta = 0;

/// trouver l'indice d'un pion sur la grille
int indice_pion(char c, EtatJeu e)
{
    for (int i = 0; i < 24; i++)
        if (e.position[i].lettre == c)
            return i;
}

/// v�rifie s'il n'y a pas de mouvement pour la machine
int PasMouvementMachine(EtatJeu c)
{
    int i;
    int t1 = 0;
    for (i = 0; i < 24; i++)
    {
        if (c.position[i].joueur == 1)
        {
            // int indice pion(char c);
            // la fonction donne l'indice de la case portant le caractere entree en indice.
            if ((c.position[indice_pion(c.position[i].v1, c)].joueur != 0) && (c.position[indice_pion(c.position[i].v2, c)].joueur != 0))
            {
                if ((c.position[i].v3 == '&') && (c.position[i].v4 == '&'))
                    t1++;
                if ((c.position[i].v3 != '&') && (c.position[i].v4 == '&'))
                {
                    if (c.position[indice_pion(c.position[i].v3, c)].joueur != 0)
                        t1++;
                }
                if ((c.position[i].v3 != '&') && (c.position[i].v4 != '&'))
                {
                    if ((c.position[indice_pion(c.position[i].v3, c)].joueur != 0) && (c.position[indice_pion(c.position[i].v4, c)].joueur != 0))
                        t1++;
                }
                // la variable v1 signifie le nombre de pions bloqu�s pour le joueur 1
            }
        }
    }

    if (t1 == c.nombrePionsMachine)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/// v�rifie s'il n'y a pas de mouvement pour le joueur
int PasMouvement2(EtatJeu c)
{
    int i;
    int t2 = 0;
    for (i = 0; i < 24; i++)
    {
        if (c.position[i].joueur == 2)
        {
            if ((c.position[indice_pion(c.position[i].v1, c)].joueur != 0) && (c.position[indice_pion(c.position[i].v2, c)].joueur != 0))
            {
                if ((c.position[i].v3 == '&') && (c.position[i].v4 == '&'))
                    t2++;
                if ((c.position[i].v3 != '&') && (c.position[i].v4 == '&'))
                {
                    if (c.position[indice_pion(c.position[i].v3, c)].joueur != 0)
                        t2++;
                }
                if ((c.position[i].v3 != '&') && (c.position[i].v4 != '&'))
                {
                    if ((c.position[indice_pion(c.position[i].v3, c)].joueur != 0) && (c.position[indice_pion(c.position[i].v4, c)].joueur != 0))
                        t2++;
                }
                // la variable v2 signifie le nombre de pions restants pour le joueur 2
            }
        }
    }
    if (t2 == c.nombrePionsHumain)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/// copier un etat dans un autre etat
void copier(EtatJeu source, EtatJeu *copie)
{
    copie->pionCaptureAdversaire = source.pionCaptureAdversaire;
    copie->precedent = source.pionCaptureAdversaire;
    copie->coutEtat = source.coutEtat;
    copie->positionActuelle = source.positionActuelle;
    copie->nombrePionsMachine = source.nombrePionsMachine;
    copie->nombrePionsHumain = source.nombrePionsHumain;
    for (int i = 0; i < 24; i++)
    {
        copie->position[i].joueur = source.position[i].joueur;
        copie->position[i].couleur = source.position[i].couleur;
        copie->position[i].lettre = source.position[i].lettre;
        copie->position[i].v1 = source.position[i].v1;
        copie->position[i].v2 = source.position[i].v2;
        copie->position[i].v3 = source.position[i].v3;
        copie->position[i].v4 = source.position[i].v1;
    }
}

/// la fonction heuristique
EtatJeu h(EtatJeu c)
{
    int nb1 = 0, nb2 = 0;
    for (int i = 0; i < 24; i++)
    {
        if (c.position[i].joueur == 1)
            nb1++;
        if (c.position[i].joueur == 2)
            nb2++;
        if (c.position[i].joueur == 0 && moulinForme(c.position, i, 1) == 0)
            nb1 += 3;
        if (c.position[i].joueur == 0 && moulinForme(c.position, i, 2) == 0)
            nb2 += 3;
        if (moulinForme(c.position, i, 1) == 0)
            nb1 += 10;
        if (moulinForme(c.position, i, 2) == 0)
            nb2 += 10;
    }
    c.coutEtat = nb1 - nb2;
    return c;
}

/// La strat�gie Minimax
EtatJeu Minimax(EtatJeu e, int p, int pions_a_placer, bool TourMax)
{
    nodes_explored_minimax++;
    if (p <= 0)
    {
        return h(e);
    }
    if (pions_a_placer > 18)
    {
        if (PasMouvementMachine(e) || e.nombrePionsMachine == 2)
        {
            e.coutEtat = -1000;
            return e;
        }
        if (PasMouvement2(e) || e.nombrePionsHumain == 2)
        {
            e.coutEtat = 1000;
            return e;
        }
    }
    if (TourMax)
    {
        p--;
        pions_a_placer++;
        EtatJeu eMax;
        copier(e, &eMax);
        eMax.coutEtat = -100000;
        eMax.pionCaptureAdversaire = -1;
        if (pions_a_placer <= 18)
        {
            for (int i = 0; i < 24; i++)
            {
                if (e.position[i].joueur == 0)
                {
                    nombreNoeuds++;
                    EtatJeu eCourant;
                    EtatJeu eAide;
                    copier(e, &eCourant);
                    eCourant.position[i].joueur = 1;
                    eCourant.position[i].couleur = 9;
                    eCourant.positionActuelle = i;
                    eCourant.pionCaptureAdversaire = -1;
                    if (moulinForme(eCourant.position, eCourant.positionActuelle, 1) == 0)
                    {
                        for (int j = 0; j < 24; j++)
                        {
                            if (e.position[j].joueur == 2 && !(moulinForme(eCourant.position, j, 2) == 0))
                            {
                                nombreNoeuds++;
                                eCourant.position[j].joueur = 0;
                                eCourant.position[j].couleur = 0;
                                e.nombrePionsHumain--;
                                eAide = Minimax(eCourant, p - 1, pions_a_placer - 1, !TourMax);
                                eAide.pionCaptureAdversaire = j;
                                eAide.positionActuelle = i;
                            }
                        }
                    }
                    else
                    {
                        eAide = Minimax(eCourant, p, pions_a_placer, !TourMax);
                        eAide.positionActuelle = i;
                        eAide.pionCaptureAdversaire = -1;
                    }
                    if (eMax.coutEtat < eAide.coutEtat)
                    {
                        eMax.coutEtat = eAide.coutEtat;
                        eMax.positionActuelle = i;
                        eMax.pionCaptureAdversaire = eAide.pionCaptureAdversaire;
                    }
                }
            }
            return eMax;
        }
        else
        {
            for (int k = 0; k < 24; k++)
            {
                if (e.position[k].joueur == 1)
                {
                    for (int i = 0; i < 24; i++)
                    {
                        if (Voisinages(k, i, e, 1) == 0 && e.position[i].joueur == 0)
                        {
                            nombreNoeuds++;
                            EtatJeu eCourant;
                            EtatJeu eAide;
                            copier(e, &eCourant);
                            eCourant.position[k].joueur = 0;
                            eCourant.position[k].couleur = 0;
                            eCourant.position[i].joueur = 1;
                            eCourant.position[i].couleur = 9;
                            eCourant.positionActuelle = i;
                            eCourant.precedent = k;
                            eCourant.pionCaptureAdversaire = -1;
                            if (moulinForme(eCourant.position, eCourant.positionActuelle, 1) == 0)
                            {
                                for (int j = 0; j < 24; j++)
                                {
                                    if (e.position[j].joueur == 2 && !(moulinForme(eCourant.position, j, 2) == 0))
                                    {
                                        nombreNoeuds++;
                                        eCourant.position[j].joueur = 0;
                                        eCourant.position[j].couleur = 0;
                                        eCourant.nombrePionsHumain--;
                                        eAide = Minimax(eCourant, p - 1, pions_a_placer - 1, !TourMax);
                                        eAide.pionCaptureAdversaire = j;
                                        eAide.positionActuelle = i;
                                    }
                                }
                            }
                            else
                            {
                                eAide = Minimax(eCourant, p, pions_a_placer, !TourMax);
                                eAide.positionActuelle = i;
                                eAide.pionCaptureAdversaire = -1;
                            }
                            if (eMax.coutEtat < eAide.coutEtat)
                            {
                                eMax.coutEtat = eAide.coutEtat;
                                eMax.positionActuelle = i;
                                eMax.precedent = k;
                                eMax.pionCaptureAdversaire = eAide.pionCaptureAdversaire;
                            }
                        }
                    }
                }
            }
            return eMax;
        }
    }
    else
    {
        p--;
        pions_a_placer++;
        EtatJeu eMin;
        copier(e, &eMin);
        eMin.coutEtat = 100000;
        eMin.pionCaptureAdversaire = -1;
        if (pions_a_placer <= 18)
        {
            for (int i = 0; i < 24; i++)
            {
                if (e.position[i].joueur == 0)
                {
                    nombreNoeuds++;
                    EtatJeu eCourant;
                    EtatJeu eAide;
                    copier(e, &eCourant);
                    eCourant.position[i].joueur = 2;
                    eCourant.position[i].couleur = 12;
                    eCourant.positionActuelle = i;
                    eCourant.pionCaptureAdversaire = -1;
                    if (moulinForme(eCourant.position, eCourant.positionActuelle, 2) == 0)
                    {
                        for (int j = 0; j < 24; j++)
                        {
                            if (e.position[j].joueur == 1 && !(moulinForme(eCourant.position, j, 1) == 0))
                            {
                                nombreNoeuds++;
                                eCourant.position[j].joueur = 0;
                                eCourant.position[j].couleur = 0;
                                eCourant.nombrePionsMachine--;
                                eAide = Minimax(eCourant, p - 1, pions_a_placer - 1, !TourMax);
                                eAide.pionCaptureAdversaire = j;
                                eAide.positionActuelle = i;
                            }
                        }
                    }
                    else
                    {
                        eAide = Minimax(eCourant, p, pions_a_placer, !TourMax);
                        eAide.positionActuelle = i;
                        eAide.pionCaptureAdversaire = -1;
                    }
                    if (eMin.coutEtat > eAide.coutEtat)
                    {
                        eMin.coutEtat = eAide.coutEtat;
                        eMin.positionActuelle = i;
                        eMin.pionCaptureAdversaire = eAide.pionCaptureAdversaire;
                    }
                }
            }
            return eMin;
        }
        else
        {
            for (int k = 0; k < 24; k++)
            {
                if (e.position[k].joueur == 2)
                {
                    for (int i = 0; i < 24; i++)
                    {
                        if (Voisinages(k, i, e, 2) == 0 && e.position[i].joueur == 0)
                        {
                            nombreNoeuds++;
                            EtatJeu eCourant;
                            EtatJeu eAide;
                            copier(e, &eCourant);
                            eCourant.position[k].joueur = 0;
                            eCourant.position[k].couleur = 0;
                            eCourant.position[i].joueur = 2;
                            eCourant.position[i].couleur = 12;
                            eCourant.positionActuelle = i;
                            eCourant.precedent = k;
                            eCourant.pionCaptureAdversaire = -1;
                            if (moulinForme(eCourant.position, eCourant.positionActuelle, 2) == 0)
                            {
                                for (int j = 0; j < 24; j++)
                                {
                                    if (e.position[j].joueur == 1 && !(moulinForme(eCourant.position, j, 1) == 0))
                                    {
                                        nombreNoeuds++;
                                        eCourant.position[j].joueur = 0;
                                        eCourant.position[j].couleur = 0;
                                        eCourant.nombrePionsMachine--;
                                        eAide = Minimax(eCourant, p - 1, pions_a_placer - 1, !TourMax);
                                        eAide.pionCaptureAdversaire = j;
                                        eAide.positionActuelle = i;
                                    }
                                }
                            }
                            else
                            {
                                eAide = Minimax(eCourant, p, pions_a_placer, !TourMax);
                                eAide.positionActuelle = i;
                                eAide.pionCaptureAdversaire = -1;
                            }
                            if (eMin.coutEtat > eAide.coutEtat)
                            {
                                eMin.coutEtat = eAide.coutEtat;
                                eMin.positionActuelle = i;
                                eMin.precedent = k;
                                eMin.pionCaptureAdversaire = eAide.pionCaptureAdversaire;
                            }
                        }
                    }
                }
            }
            return eMin;
        }
    }
}

/// La strat�gie AlphaBeta
EtatJeu AlphaBeta(EtatJeu e, int p, int pions_a_placer, bool TourMax, int a, int b)
{
    nodes_explored_alphabeta++;
    if (p <= 0)
    {
        return h(e);
    }
    if (pions_a_placer > 18)
    {
        if (PasMouvementMachine(e) || e.nombrePionsMachine == 2)
        {
            e.coutEtat = -1000;
            return e;
        }
        if (PasMouvement2(e) || e.nombrePionsHumain == 2)
        {
            e.coutEtat = 1000;
            return e;
        }
    }
    if (TourMax)
    {
        p--;
        pions_a_placer++;
        EtatJeu eMax;
        copier(e, &eMax);
        eMax.coutEtat = -100000;
        eMax.pionCaptureAdversaire = -1;
        if (pions_a_placer <= 18)
        {
            for (int i = 0; i < 24; i++)
            {
                if (e.position[i].joueur == 0)
                {
                    nombreNoeuds++;
                    EtatJeu eCourant;
                    EtatJeu eAide;
                    copier(e, &eCourant);
                    eCourant.position[i].joueur = 1;
                    eCourant.position[i].couleur = 9;
                    eCourant.positionActuelle = i;
                    if (moulinForme(eCourant.position, eCourant.positionActuelle, 1) == 0)
                    {
                        for (int j = 0; j < 24; j++)
                        {
                            if (e.position[j].joueur == 2 && !(moulinForme(eCourant.position, j, 2) == 0))
                            {
                                nombreNoeuds++;
                                eCourant.position[j].joueur = 0;
                                eCourant.position[j].couleur = 0;
                                e.nombrePionsHumain--;
                                eAide = AlphaBeta(eCourant, p - 1, pions_a_placer - 1, !TourMax, a, b);
                                eAide.pionCaptureAdversaire = j;
                                eAide.positionActuelle = i;
                            }
                        }
                    }
                    else
                    {
                        eAide = AlphaBeta(eCourant, p, pions_a_placer, !TourMax, a, b);
                        eAide.positionActuelle = i;
                        eAide.pionCaptureAdversaire = -1;
                    }
                    if (eMax.coutEtat < eAide.coutEtat)
                    {
                        eMax.coutEtat = eAide.coutEtat;
                        eMax.positionActuelle = i;
                        eMax.pionCaptureAdversaire = eAide.pionCaptureAdversaire;
                    }
                    if (a < eAide.coutEtat)
                        a = eAide.coutEtat;
                    if (a >= b)
                        i = 25;
                }
            }
            return eMax;
        }
        else
        {
            for (int k = 0; k < 24; k++)
            {
                if (e.position[k].joueur == 1)
                {
                    for (int i = 0; i < 24; i++)
                    {
                        if (Voisinages(k, i, e, 1) == 0 && e.position[i].joueur == 0)
                        {
                            nombreNoeuds++;
                            EtatJeu eCourant;
                            EtatJeu eAide;
                            copier(e, &eCourant);
                            eCourant.position[k].joueur = 0;
                            eCourant.position[k].couleur = 0;
                            eCourant.position[i].joueur = 1;
                            eCourant.position[i].couleur = 9;
                            eCourant.positionActuelle = i;
                            eCourant.precedent = k;
                            if (moulinForme(eCourant.position, eCourant.positionActuelle, 1) == 0)
                            {
                                for (int j = 0; j < 24; j++)
                                {
                                    if (e.position[j].joueur == 2 && !(moulinForme(eCourant.position, j, 2) == 0))
                                    {
                                        nombreNoeuds++;
                                        eCourant.position[j].joueur = 0;
                                        eCourant.position[j].couleur = 0;
                                        eCourant.nombrePionsHumain--;
                                        eAide = AlphaBeta(eCourant, p - 1, pions_a_placer - 1, !TourMax, a, b);
                                        eAide.pionCaptureAdversaire = j;
                                        eAide.positionActuelle = i;
                                    }
                                }
                            }
                            else
                            {
                                eAide = AlphaBeta(eCourant, p, pions_a_placer, !TourMax, a, b);
                                eAide.positionActuelle = i;
                                eAide.pionCaptureAdversaire = -1;
                            }
                            if (eMax.coutEtat < eAide.coutEtat)
                            {
                                eMax.coutEtat = eAide.coutEtat;
                                eMax.positionActuelle = i;
                                eMax.precedent = k;
                                eMax.pionCaptureAdversaire = eAide.pionCaptureAdversaire;
                            }
                            if (a < eAide.coutEtat)
                                a = eAide.coutEtat;
                            if (a >= b)
                                i = 25;
                        }
                    }
                }
            }
            return eMax;
        }
    }
    else
    {
        p--;
        pions_a_placer++;
        EtatJeu eMin;
        copier(e, &eMin);
        eMin.coutEtat = 100000;
        eMin.pionCaptureAdversaire = -1;
        if (pions_a_placer <= 18)
        {
            for (int i = 0; i < 24; i++)
            {
                if (e.position[i].joueur == 0)
                {
                    nombreNoeuds++;
                    EtatJeu eCourant;
                    EtatJeu eAide;
                    copier(e, &eCourant);
                    eCourant.position[i].joueur = 2;
                    eCourant.position[i].couleur = 12;
                    eCourant.positionActuelle = i;
                    if (moulinForme(eCourant.position, eCourant.positionActuelle, 2) == 0)
                    {
                        for (int j = 0; j < 24; j++)
                        {
                            if (e.position[j].joueur == 1 && !(moulinForme(eCourant.position, j, 1) == 0))
                            {
                                nombreNoeuds++;
                                eCourant.position[j].joueur = 0;
                                eCourant.position[j].couleur = 0;
                                eCourant.nombrePionsMachine--;
                                eAide = AlphaBeta(eCourant, p - 1, pions_a_placer - 1, !TourMax, a, b);
                                eAide.pionCaptureAdversaire = j;
                                eAide.positionActuelle = i;
                            }
                        }
                    }
                    else
                    {
                        eAide = AlphaBeta(eCourant, p, pions_a_placer, !TourMax, a, b);
                        eAide.positionActuelle = i;
                        eAide.pionCaptureAdversaire = -1;
                    }
                    if (eMin.coutEtat > eAide.coutEtat)
                    {
                        eMin.coutEtat = eAide.coutEtat;
                        eMin.positionActuelle = i;
                        eMin.pionCaptureAdversaire = eAide.pionCaptureAdversaire;
                    }
                    if (b > eAide.coutEtat)
                        b = eAide.coutEtat;
                    if (a >= b)
                        i = 25;
                }
            }
            return eMin;
        }
        else
        {
            for (int k = 0; k < 24; k++)
            {
                if (e.position[k].joueur == 2)
                {
                    for (int i = 0; i < 24; i++)
                    {
                        if (Voisinages(k, i, e, 2) == 0 && e.position[i].joueur == 0)
                        {
                            nombreNoeuds++;
                            EtatJeu eCourant;
                            EtatJeu eAide;
                            copier(e, &eCourant);
                            eCourant.position[k].joueur = 0;
                            eCourant.position[k].couleur = 0;
                            eCourant.position[i].joueur = 2;
                            eCourant.position[i].couleur = 12;
                            eCourant.positionActuelle = i;
                            eCourant.precedent = k;
                            if (moulinForme(eCourant.position, eCourant.positionActuelle, 2) == 0)
                            {
                                for (int j = 0; j < 24; j++)
                                {
                                    if (e.position[j].joueur == 1 && !(moulinForme(eCourant.position, j, 1) == 0))
                                    {
                                        nombreNoeuds++;
                                        eCourant.position[j].joueur = 0;
                                        eCourant.position[j].couleur = 0;
                                        eCourant.nombrePionsMachine--;
                                        eAide = AlphaBeta(eCourant, p - 1, pions_a_placer - 1, !TourMax, a, b);
                                        eAide.pionCaptureAdversaire = j;
                                        eAide.positionActuelle = i;
                                    }
                                }
                            }
                            else
                            {
                                eAide = AlphaBeta(eCourant, p, pions_a_placer, !TourMax, a, b);
                                eAide.positionActuelle = i;
                                eAide.pionCaptureAdversaire = -1;
                            }
                            if (eMin.coutEtat > eAide.coutEtat)
                            {
                                eMin.coutEtat = eAide.coutEtat;
                                eMin.positionActuelle = i;
                                eMin.precedent = k;
                                eMin.pionCaptureAdversaire = eAide.pionCaptureAdversaire;
                            }
                            if (b > eAide.coutEtat)
                                b = eAide.coutEtat;
                            if (a >= b)
                                i = 25;
                        }
                    }
                }
            }
            return eMin;
        }
    }
}
// Tableau représentant toutes les lignes de moulin possibles sur le plateau
const int lignes_moulin[16][3] = {
    {0, 1, 2}, {0, 9, 21}, {1, 4, 7}, {2, 14, 23}, {3, 4, 5}, {3, 10, 18}, {5, 13, 20}, {6, 7, 8}, {6, 11, 15}, {8, 12, 17}, {9, 10, 11}, {12, 13, 14}, {15, 16, 17}, {16, 19, 22}, {18, 19, 20}, {21, 22, 23}};
/// verifie s'il y a un moulin dans une position

int moulinForme(Position *UnPlateau, int position, int Pion)
{
    for (int i = 0; i < 16; ++i)
    {
        int count = 0;
        for (int j = 0; j < 3; ++j)
        {
            if (lignes_moulin[i][j] == position)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if (UnPlateau[lignes_moulin[i][k]].joueur == Pion)
                    {
                        count++;
                    }
                }
                if (count == 3)
                {
                    return 0; // Moulin trouvé
                }
                break;
            }
        }
    }
    return -1; // Aucun moulin trouvé
}
const int voisins[24][4] = {
    {1, 9, -1, -1},   // Voisins de la position 0
    {0, 2, 4, -1},    // Voisins de la position 1
    {1, 14, -1, -1},  // Voisins de la position 2
    {4, 10, -1, -1},  // Voisins de la position 3
    {1, 3, 5, 7},     // Voisins de la position 4
    {4, 13, -1, -1},  // Voisins de la position 5
    {7, 11, -1, -1},  // Voisins de la position 6
    {4, 6, 8, -1},    // Voisins de la position 7
    {7, 12, -1, -1},  // Voisins de la position 8
    {0, 10, 21, -1},  // Voisins de la position 9
    {3, 9, 11, 18},   // Voisins de la position 10
    {6, 10, 15, -1},  // Voisins de la position 11
    {8, 13, 17, -1},  // Voisins de la position 12
    {5, 12, 14, 20},  // Voisins de la position 13
    {2, 13, 23, -1},  // Voisins de la position 14
    {11, 16, -1, -1}, // Voisins de la position 15
    {15, 17, 19, -1}, // Voisins de la position 16
    {12, 16, -1, -1}, // Voisins de la position 17
    {10, 19, -1, -1}, // Voisins de la position 18
    {16, 18, 20, 22}, // Voisins de la position 19
    {13, 19, -1, -1}, // Voisins de la position 20
    {9, 22, -1, -1},  // Voisins de la position 21
    {19, 21, 23, -1}, // Voisins de la position 22
    {14, 22, -1, -1}  // Voisins de la position 23
};

/// retourne 1 si un joueur a une possibilit� de d�placer dans la grille et 0 sinon
int Voisinages(int source, int PositionTest, EtatJeu c, int joueur)
{
    for (int i = 0; i < 4; i++)
    {
        if (voisins[source][i] == -1)
            break;
        if (voisins[source][i] == PositionTest)
            return 0;
    }

    if (joueur == 1 && c.nombrePionsMachine <= 3)
        return 0;
    if (joueur == 2 && c.nombrePionsHumain <= 3)
        return 0;

    return -1;
}
int pionLibreHorsMoulin(Position *UnPlateau)
{
    int Choix = -1;
    for (int i = 0; i < 24; i++)
    {
        if (UnPlateau[i].joueur == 1)
            if (moulinForme(UnPlateau, i, 1) == -1)
            {
                Choix = 0;
                i = 24;
            }
    }
    if (Choix == -1)
    {
        printf("l'adversaire n'a que des moulin, vous pouver pas capturer un pion");
    }
    return Choix;
}
