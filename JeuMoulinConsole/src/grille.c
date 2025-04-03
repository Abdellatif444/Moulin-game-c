#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "../include/grille.h"
#include "../include/structure.h"
#include "../include/game.h"
int NbPionsPoses = 0;

// Fonction pour changer la couleur du texte et du fond
void ChangerCouleurTexte(int couleurDuTEXTE, int couleurDeFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTEXTE);
}

// Fonction pour afficher la grille avec couleur
void AppliquerCouleurPion(int i, EtatJeu *e)
{
    if (e->position[i].joueur == 0)
        ChangerCouleurTexte(15, 0);
    else if (e->position[i].joueur == 1)
        ChangerCouleurTexte(4, 11);
    else if (e->position[i].joueur == 2)
        ChangerCouleurTexte(2, 20);
}

void AfficherPlateau(EtatJeu e)
{
    EtatJeu ETAT;
    copier(e, &ETAT);

    printf("\n\n\n");
    printf("\t\t\t ");
    AppliquerCouleurPion(0, &ETAT);
    printf("|00|");
    ChangerCouleurTexte(15, 0);
    printf("=======================");
    AppliquerCouleurPion(1, &ETAT);
    printf("|01|");
    ChangerCouleurTexte(15, 0);
    printf("=======================");
    AppliquerCouleurPion(2, &ETAT);
    printf("|02|\n");

    ChangerCouleurTexte(15, 0);

    printf("\t\t\t  |  \t\t\t     |  \t\t        |\n");
    printf("\t\t\t  |\t\t\t     |  \t\t        |\n");
    printf("\t\t\t  |\t\t\t     |  \t\t        |\n");
    printf("\t\t\t  |         ");
    AppliquerCouleurPion(3, &ETAT);
    printf("|03|");
    ChangerCouleurTexte(15, 0);
    printf("============");
    AppliquerCouleurPion(4, &ETAT);
    printf("|04|");
    ChangerCouleurTexte(15, 0);
    printf("============");
    AppliquerCouleurPion(5, &ETAT);
    printf("|05|");
    ChangerCouleurTexte(15, 0);
    printf("        |\n");
    printf("\t\t\t  |          |               |               |          |\n");
    printf("\t\t\t  |          |               |               |          |\n");
    printf("\t\t\t  |          |               |               |          |\n");
    printf("\t\t\t  |          |    ");
    AppliquerCouleurPion(6, &ETAT);
    printf("|06|");
    ChangerCouleurTexte(15, 0);
    printf("======");
    AppliquerCouleurPion(7, &ETAT);
    printf("|07|");
    ChangerCouleurTexte(15, 0);
    printf("=====");
    AppliquerCouleurPion(8, &ETAT);
    printf("|08|");
    ChangerCouleurTexte(15, 0);
    printf("    |          |\n");
    printf("\t\t\t  |          |     |                  |      |          |\n");
    printf("\t\t\t  |          |     |                  |      |          |\n");
    printf("\t\t\t  |          |     |                  |      |          |\n");
    printf("\t\t\t ");
    AppliquerCouleurPion(9, &ETAT);
    printf("|09|");
    ChangerCouleurTexte(15, 0);
    printf("=======");
    AppliquerCouleurPion(10, &ETAT);
    printf("|10|");
    ChangerCouleurTexte(15, 0);
    printf("==");
    AppliquerCouleurPion(11, &ETAT);
    printf("|11|");
    ChangerCouleurTexte(15, 0);
    printf("               ");
    AppliquerCouleurPion(12, &ETAT);
    printf("|12|");
    ChangerCouleurTexte(15, 0);
    printf("==");
    AppliquerCouleurPion(13, &ETAT);
    printf("|13|");
    ChangerCouleurTexte(15, 0);
    printf("========");
    AppliquerCouleurPion(14, &ETAT);
    printf("|14|");
    printf("\n");
    ChangerCouleurTexte(15, 0);
    printf("\t\t\t  |          |     |                  |      |          |\n");
    printf("\t\t\t  |          |     |                  |      |          |\n");
    printf("\t\t\t  |          |     |                  |      |          |\n");
    ChangerCouleurTexte(15, 0);
    printf("\t\t\t  |          |    ");
    AppliquerCouleurPion(15, &ETAT);
    printf("|15|");
    ChangerCouleurTexte(15, 0);
    printf("======");
    AppliquerCouleurPion(16, &ETAT);
    printf("|16|");
    ChangerCouleurTexte(15, 0);
    printf("=====");
    AppliquerCouleurPion(17, &ETAT);
    printf("|17|");
    ChangerCouleurTexte(15, 0);
    printf("    |          |\n");
    printf("\t\t\t  |          |                |              |          |\n");
    printf("\t\t\t  |          |                |              |          |\n");
    printf("\t\t\t  |          |                |              |          |\n");
    ChangerCouleurTexte(15, 0);
    printf("\t\t\t  |         ");
    AppliquerCouleurPion(18, &ETAT);
    printf("|18|");
    ChangerCouleurTexte(15, 0);
    printf("============");
    AppliquerCouleurPion(19, &ETAT);
    printf("|19|");
    ChangerCouleurTexte(15, 0);
    printf("============");
    AppliquerCouleurPion(20, &ETAT);
    printf("|20|");
    ChangerCouleurTexte(15, 0);
    printf("        |\n");
    printf("\t\t\t  |\t\t\t      |  \t\t        |\n");
    printf("\t\t\t  |\t\t\t      |  \t\t        |\n");
    printf("\t\t\t  |\t\t\t      |  \t\t        |\n");
    printf("\t\t\t ");
    AppliquerCouleurPion(21, &ETAT);
    printf("|21|");
    ChangerCouleurTexte(15, 0);
    printf("=======================");
    AppliquerCouleurPion(22, &ETAT);
    printf("|22|");
    ChangerCouleurTexte(15, 0);
    printf("=======================");
    AppliquerCouleurPion(23, &ETAT);
    printf("|23|\n");
    ChangerCouleurTexte(15, 0);
}

int ObtenirChoixUtilisateur(int joueur, EtatJeu *e)
{
    int choix = -1;

    while (choix == -1 || e->position[choix].joueur != joueur)
    {

        printf("choisir la case:\n"); //
        scanf("%d", &choix);

    }
    return choix;
}
int ObtenirCasePourRetrait(int joueur, EtatJeu *e)
{
    int caseARetirer = -1;
    while (caseARetirer == -1 || e->position[caseARetirer].joueur != joueur)
    {

        printf("enter case  to remove: \n");
        scanf("%d", &caseARetirer);
    }
    return caseARetirer;
}
int ObtenirCaseSource(int joueur, EtatJeu *e)
{
    int caseSource = -1;

    while (caseSource == -1 || e->position[caseSource].joueur != joueur)
    {

        printf("entrer case source: \n");
        scanf("%d", &caseSource);
    }
    return caseSource;
}
int ObtenirCaseDestination(int joueur, EtatJeu *e)
{
    int caseDestination = -1;

    while (caseDestination == -1 || e->position[caseDestination].joueur != joueur)
    {

        printf("entrer case Destination: \n");
        scanf("%d", &caseDestination);
    }
    return caseDestination;
}


void beginmain(EtatJeu e)
{
    EtatJeu etatMachine;

    printf("Jeu de moulin\n");
    int choixMenu;
    system("cls");
    printf("\n\n");
    printf("\t\t ___________________________\n");
    printf("\t\t|                           \\ \n");
    printf("\t\t|         1- MINMAX          )       \n");
    printf("\t\t|___________________________/\n");

    printf("\t\t\t ___________________________\n");
    printf("\t\t\t|                           \\\n");
    printf("\t\t\t|       2-ALPHA-BETA         )\n");
    printf("\t\t\t|___________________________/\n");

    printf("\t\t\t\t ___________________________\n");
    printf("\t\t\t\t|                           \\\n");
    printf("\t\t\t\t|       3-Quitter            )\n");
    printf("\t\t\t\t|___________________________/\n");

    scanf("%d", &choixMenu);

    bool jeuEnCours = false;

    while (!jeuEnCours)
    {
        switch (choixMenu)
        {
        case 1:
            printf("tu as choixi minimax:\n");
            // Code pour Minimax
            printf("Nombre de noeuds explores par Minimax : %d\n", nodes_explored_minimax);
            system("cls");
            AfficherPlateau(e);

            for (int i = 0; i < 9; i++)
            {
                int choix;
                choix = ObtenirChoixUtilisateur(0, &e);

                e.position[choix].joueur = 2;
                printf("Vous avez choisi la position : %d\n", choix);
                if (moulinForme(e.position, choix, 2) == 0)
                {
                    if (pionLibreHorsMoulin(e.position) == 0)
                    {
                        do
                        {

                            choix = ObtenirChoixUtilisateur(1, &e);

                        } while (moulinForme(e.position, choix, 1) == 0);

                        printf("Vous avez capture le pion : %d\n", choix);
                        e.position[choix].joueur = 0;
                        AfficherPlateau(e);
                        e.nombrePionsMachine--;
                    }
                }
                NbPionsPoses++;
                etatMachine = Minimax(e, 3, NbPionsPoses, true);
                system("cls");
                printf("Nombre de noeuds explores par Minimax : %d\n", nodes_explored_minimax);
                e.position[etatMachine.positionActuelle].joueur = 1;

                printf("La machine choisi la position : %d\n", etatMachine.positionActuelle);
                AfficherPlateau(e);
                if (etatMachine.pionCaptureAdversaire != -1)
                {

                    e.position[etatMachine.pionCaptureAdversaire].joueur = 0;
                    system("cls");
                    printf("La machine a capture le pion : %d\n", etatMachine.pionCaptureAdversaire);
                    AfficherPlateau(e);
                    e.nombrePionsHumain--;
                }
                NbPionsPoses++;
                printf("\n");
                if (e.nombrePionsMachine == 2 || PasMouvementMachine(e))
            {
                ChangerCouleurTexte(15, 0);
                printf("\n\n\t\t\t\t\t\t\t\t            ___________    ____ \n");
                printf("\t\t\t\t\t\t\t\t     ______/   \\__//   \\__/____\\ \n");
                printf("\t\t\t\t\t\t\t\t   _/   \\_/  :           //____\\\\  \n");
                printf("\t\t\t\t\t\t\t\t  /|      :  :  ..      /        \\ \n");
                printf("\t\t\t\t\t\t\t\t | |     ::     ::      \\        / \n");
                printf("\t\t\t\t\t\t\t\t | |     :|     ||     \\ \\______/ \n");
                printf("\t\t\t\t\t\t\t\t | |     ||     ||      |\\  /  |  \n");
                printf("\t\t\t\t\t\t\t\t  \\|     ||     ||      |   / | \\ \n");
                printf("\t\t\t\t\t\t\t\t   |     ||     ||      |  / /_\\ \\ \n");
                printf("\t\t\t\t\t\t\t\t   | ___ || ___ ||      | /  /    \\ \n");
                printf("\t\t\t\t\t\t\t\t    \\_-_/  \\_-_/ | ____ |/__/      \\ \n");
                printf("\t\t\t\t\t\t\t\t                 _\\_--_/    \\      /  \n");
                printf("\t\t\t\t\t\t\t\t                /____             /  \n");
                printf("\t\t\t\t\t\t\t\t               /     \\           /  \n");
                printf("\t\t\t\t\t\t\t\t               \\______\\_________/ \n");
                ChangerCouleurTexte(14, 0);
                printf("\t\t\t    ______                              __        __       __  _                      ____  __                          ___    _\n");
                printf("\t\t\t   / ____/____  ____  ____ __________ _/ /___  __/ /____ _/ /_(_)____  ____  _____   / __ \\/ /____ ___  _____  _____   |__ \\  | |\n");
                printf("\t\t\t  / /    / __ \\/ __ \\/ __ `/ ___/ __ `/ __/ / / / // __ `/ __/ // __ \\/ __ \\/ ___/  / /_/ / // __ `/ / / / _ \\ / ___/     ) | | |\n");
                printf("\t\t\t / /___ / /_/ / / / / /_/ / /  / /_/ / /_/ /_/ / // /_/ / /_/ // /_/ / / / (__  )  / ____/ // /_/ / /_/ /  __ / /        / /  | |\n");
                printf("\t\t\t \\____/ \\____/_/ /_/\\__, /_/   \\__,_/\\__/\\__,_/_/ \\__,_/\\__/_/ \\____/_/ /_/____/  /_/   /_/ \\__,_/\\__, /\\___ /_/        / /_  |_|\n");
                printf("\t\t\t                   /____/                                                                        /____/                |____| (_)      \n\n");
                printf("\t\t\t\t  __   _____  _   _      _    ____  _____   _____ _   _ _____  __        _____ _   _ _   _ _____ ____               \n");
                printf("\t\t\t\t  \\ \\ / / _ \\| | | |    / \\  |  _ \\| ____| |_   _| | | | ____| \\ \\      / /_ _| \\ | | \\ | | ____|  _ \\ \n");
                printf("\t\t\t\t   \\ V / | | | | | |   / _ \\ | |_) |  _|     | | | |_| |  _|    \\ \\ /\\ / / | ||  \\| |  \\| |  _| | |_) |   \n");
                printf("\t\t\t\t    | || |_| | |_| |  / ___ \\|  _ <| |___    | | |  _  | |___    \\ V  V /  | || |\\  | |\\  | |___|  _ <         \n");
                printf("\t\t\t\t    |_| \\___/ \\___/  /_/   \\_\\_| \\_\\_____|   |_| |_| |_|_____|    \\_/\\_/  |___|_| \\_|_| \\_|_____|_| \\_\\  \n\n");
                ChangerCouleurTexte(15, 0);

                exit(0);
            }

            else if(e.nombrePionsHumain == 2 || PasMouvement2(e))
            {
                ChangerCouleurTexte(15, 0);
                printf("\t\t\t __     ______  _    _   _      ____   _____ ______ \n");
                printf("\t\t\t \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|\n");
                printf("\t\t\t  \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   \n");
                printf("\t\t\t   \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  \n");
                printf("\t\t\t    | | | |__| | |__| | | |___| |__| |____) | |____ \n");
                printf("\t\t\t    |_|  \\____/ \\____/  |______\\____/|_____/|______|\n");

                ChangerCouleurTexte(15, 0);
                exit(0);
            }
            }
            while (e.nombrePionsMachine > 2 && e.nombrePionsHumain > 2 && !PasMouvementMachine(e) && !PasMouvement2(e))
            {
                int source = -1, destination = -1;
                do
                {
                    source = ObtenirCaseSource(2, &e);
                    destination = ObtenirCaseDestination(0, &e);
                } while (!(Voisinages(source, destination, e, 2) == 0 && e.position[destination].joueur == 0));

                e.position[source].joueur = 0;
                e.position[destination].joueur = 2;
                system("cls");
                printf("Vous avez passez de %d a %d\n", source, destination);
                AfficherPlateau(e);
                if (moulinForme(e.position, destination, 2) == 0)
                {
                    if (pionLibreHorsMoulin(e.position) == 0)
                    {
                        int choixCase;
                        do
                        {
                            choixCase = ObtenirCasePourRetrait(1, &e);
                        } while (moulinForme(e.position, choixCase, 1) == 0);
                        system("cls");
                        printf("Vous avez capture le pion : %d\n", choixCase);
                        e.position[choixCase].joueur = 0;

                        AfficherPlateau(e);
                        e.nombrePionsMachine--;
                    }
                    else if (pionLibreHorsMoulin(e.position) != 0 && e.nombrePionsMachine == 3)
                    {
                        int choixCase;
                        choixCase = ObtenirCasePourRetrait(1, &e);
                        system("cls");
                        printf("Vous avez capture le pion : %d\n", choixCase);
                        e.position[choixCase].joueur = 0;
                        AfficherPlateau(e);
                        e.nombrePionsMachine--;
                    }
                }
                NbPionsPoses++;
                etatMachine = Minimax(e, 3, NbPionsPoses, true);

                e.position[etatMachine.positionActuelle].joueur = 1;
                e.position[etatMachine.precedent].joueur = 0;
                system("cls");
                printf("La machine passe de %d a %d\n", etatMachine.precedent, etatMachine.positionActuelle);
                AfficherPlateau(e);
                if (etatMachine.pionCaptureAdversaire != -1)
                {

                    e.position[etatMachine.pionCaptureAdversaire].joueur = 0;
                    system("cls");
                    printf("La machine a capture le pion : %d\n", etatMachine.pionCaptureAdversaire);

                    AfficherPlateau(e);
                    e.nombrePionsHumain--;
                }
                NbPionsPoses++;
                printf("\n");
                if (e.nombrePionsMachine == 2 || PasMouvementMachine(e))
            {
                ChangerCouleurTexte(15, 0);
                printf("\n\n\t\t\t\t\t\t\t\t            ___________    ____ \n");
                printf("\t\t\t\t\t\t\t\t     ______/   \\__//   \\__/____\\ \n");
                printf("\t\t\t\t\t\t\t\t   _/   \\_/  :           //____\\\\  \n");
                printf("\t\t\t\t\t\t\t\t  /|      :  :  ..      /        \\ \n");
                printf("\t\t\t\t\t\t\t\t | |     ::     ::      \\        / \n");
                printf("\t\t\t\t\t\t\t\t | |     :|     ||     \\ \\______/ \n");
                printf("\t\t\t\t\t\t\t\t | |     ||     ||      |\\  /  |  \n");
                printf("\t\t\t\t\t\t\t\t  \\|     ||     ||      |   / | \\ \n");
                printf("\t\t\t\t\t\t\t\t   |     ||     ||      |  / /_\\ \\ \n");
                printf("\t\t\t\t\t\t\t\t   | ___ || ___ ||      | /  /    \\ \n");
                printf("\t\t\t\t\t\t\t\t    \\_-_/  \\_-_/ | ____ |/__/      \\ \n");
                printf("\t\t\t\t\t\t\t\t                 _\\_--_/    \\      /  \n");
                printf("\t\t\t\t\t\t\t\t                /____             /  \n");
                printf("\t\t\t\t\t\t\t\t               /     \\           /  \n");
                printf("\t\t\t\t\t\t\t\t               \\______\\_________/ \n");
                ChangerCouleurTexte(14, 0);
                printf("\t\t\t    ______                              __        __       __  _                      ____  __                          ___    _\n");
                printf("\t\t\t   / ____/____  ____  ____ __________ _/ /___  __/ /____ _/ /_(_)____  ____  _____   / __ \\/ /____ ___  _____  _____   |__ \\  | |\n");
                printf("\t\t\t  / /    / __ \\/ __ \\/ __ `/ ___/ __ `/ __/ / / / // __ `/ __/ // __ \\/ __ \\/ ___/  / /_/ / // __ `/ / / / _ \\ / ___/     ) | | |\n");
                printf("\t\t\t / /___ / /_/ / / / / /_/ / /  / /_/ / /_/ /_/ / // /_/ / /_/ // /_/ / / / (__  )  / ____/ // /_/ / /_/ /  __ / /        / /  | |\n");
                printf("\t\t\t \\____/ \\____/_/ /_/\\__, /_/   \\__,_/\\__/\\__,_/_/ \\__,_/\\__/_/ \\____/_/ /_/____/  /_/   /_/ \\__,_/\\__, /\\___ /_/        / /_  |_|\n");
                printf("\t\t\t                   /____/                                                                        /____/                |____| (_)      \n\n");
                printf("\t\t\t\t  __   _____  _   _      _    ____  _____   _____ _   _ _____  __        _____ _   _ _   _ _____ ____               \n");
                printf("\t\t\t\t  \\ \\ / / _ \\| | | |    / \\  |  _ \\| ____| |_   _| | | | ____| \\ \\      / /_ _| \\ | | \\ | | ____|  _ \\ \n");
                printf("\t\t\t\t   \\ V / | | | | | |   / _ \\ | |_) |  _|     | | | |_| |  _|    \\ \\ /\\ / / | ||  \\| |  \\| |  _| | |_) |   \n");
                printf("\t\t\t\t    | || |_| | |_| |  / ___ \\|  _ <| |___    | | |  _  | |___    \\ V  V /  | || |\\  | |\\  | |___|  _ <         \n");
                printf("\t\t\t\t    |_| \\___/ \\___/  /_/   \\_\\_| \\_\\_____|   |_| |_| |_|_____|    \\_/\\_/  |___|_| \\_|_| \\_|_____|_| \\_\\  \n\n");
                ChangerCouleurTexte(15, 0);

                exit(0);
            }

            else if(e.nombrePionsHumain == 2 || PasMouvement2(e))
            {
                ChangerCouleurTexte(15, 0);
                printf("\t\t\t __     ______  _    _   _      ____   _____ ______ \n");
                printf("\t\t\t \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|\n");
                printf("\t\t\t  \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   \n");
                printf("\t\t\t   \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  \n");
                printf("\t\t\t    | | | |__| | |__| | | |___| |__| |____) | |____ \n");
                printf("\t\t\t    |_|  \\____/ \\____/  |______\\____/|_____/|______|\n");

                ChangerCouleurTexte(15, 0);
                exit(0);
            }
            }
            system("cls");
            AfficherPlateau(e);



            jeuEnCours = true;
            break;
        case 2:
            system("cls");
            printf("tu as choixi alphaBeta:\n");

            AfficherPlateau(e);
            for (int i = 0; i < 9; i++)
            {
                int choix;
                choix = ObtenirChoixUtilisateur(0, &e);

                e.position[choix].joueur = 2;
                system("cls");
                printf("Vous avez choisi la position : %d\n", choix);
                AfficherPlateau(e);
                if (moulinForme(e.position, choix, 2) == 0)
                {
                    if (pionLibreHorsMoulin(e.position) == 0)
                    {
                        do
                        {
                            choix = ObtenirChoixUtilisateur(1, &e);
                        } while (moulinForme(e.position, choix, 1) == 0);

                        e.position[choix].joueur = 0;
                        system("cls");
                        printf("Vous avez capture le pion : %d\n", choix);
                        AfficherPlateau(e);
                        e.nombrePionsMachine--;
                    }
                }
                NbPionsPoses++;

                etatMachine = AlphaBeta(e, 3, NbPionsPoses, true, -999999, 999999);
                system("cls");
                printf("Nombre de noeuds explores par Alpha-Beta : %d\n", nodes_explored_alphabeta);

                e.position[etatMachine.positionActuelle].joueur = 1;
                printf("La machine choisi la position : %d\n", etatMachine.positionActuelle);
                AfficherPlateau(e);
                if (etatMachine.pionCaptureAdversaire != -1)
                {

                    e.position[etatMachine.pionCaptureAdversaire].joueur = 0;
                    system("cls");
                    printf("Nombre de noeuds explores par Alpha-Beta : %d\n", nodes_explored_alphabeta);
                    printf("La machine a capture le pion : %d\n", etatMachine.pionCaptureAdversaire);
                    AfficherPlateau(e);
                    e.nombrePionsHumain--;
                }
                NbPionsPoses++;
            }
            while (e.nombrePionsMachine > 2 && e.nombrePionsHumain > 2 && !PasMouvementMachine(e) && !PasMouvement2(e))
            {
                int source = -1, destination = -1;
                do
                {
                    source =  ObtenirCaseSource(2, &e);
                    destination = ObtenirCaseDestination(0, &e);
                } while (!(Voisinages(source, destination, e, 2) == 0 && e.position[destination].joueur == 0));

                e.position[source].joueur = 0;
                e.position[destination].joueur = 2;
                system("cls");
                printf("Vous avez passez de %d a %d\n", source, destination);
                AfficherPlateau(e);
                if (moulinForme(e.position, destination, 2) == 0)
                {
                    if (pionLibreHorsMoulin(e.position) == 0)
                    {
                        int choix;
                        do
                        {
                            choix = ObtenirCasePourRetrait(1, &e);
                        } while (moulinForme(e.position, choix, 1) == 0);

                        e.position[choix].joueur = 0;
                        system("cls");
                        printf("Vous avez capture le pion : %d\n", choix);
                        AfficherPlateau(e);
                        e.nombrePionsMachine--;
                    }
                }
                NbPionsPoses++;
                etatMachine = AlphaBeta(e, 3, NbPionsPoses, true, -999999, 999999);

                e.position[etatMachine.positionActuelle].joueur = 1;
                e.position[etatMachine.precedent].joueur = 0;
                system("cls");
                printf("La machine passe de %d a %d\n", etatMachine.precedent, etatMachine.positionActuelle);
                AfficherPlateau(e);
                if (etatMachine.pionCaptureAdversaire != -1)
                {

                    e.position[etatMachine.pionCaptureAdversaire].joueur = 0;
                    system("cls");
                    printf("La machine a capture le pion : %d\n", etatMachine.pionCaptureAdversaire);
                    AfficherPlateau(e);
                    e.nombrePionsHumain--;
                }
                NbPionsPoses++;
            }
            system("cls");
            AfficherPlateau(e);

            if (e.nombrePionsMachine == 2 || PasMouvementMachine(e))
            {
                ChangerCouleurTexte(15, 0);
                printf("\n\n\t\t\t\t\t\t\t\t            ___________    ____ \n");
                printf("\t\t\t\t\t\t\t\t     ______/   \\__//   \\__/____\\ \n");
                printf("\t\t\t\t\t\t\t\t   _/   \\_/  :           //____\\\\  \n");
                printf("\t\t\t\t\t\t\t\t  /|      :  :  ..      /        \\ \n");
                printf("\t\t\t\t\t\t\t\t | |     ::     ::      \\        / \n");
                printf("\t\t\t\t\t\t\t\t | |     :|     ||     \\ \\______/ \n");
                printf("\t\t\t\t\t\t\t\t | |     ||     ||      |\\  /  |  \n");
                printf("\t\t\t\t\t\t\t\t  \\|     ||     ||      |   / | \\ \n");
                printf("\t\t\t\t\t\t\t\t   |     ||     ||      |  / /_\\ \\ \n");
                printf("\t\t\t\t\t\t\t\t   | ___ || ___ ||      | /  /    \\ \n");
                printf("\t\t\t\t\t\t\t\t    \\_-_/  \\_-_/ | ____ |/__/      \\ \n");
                printf("\t\t\t\t\t\t\t\t                 _\\_--_/    \\      /  \n");
                printf("\t\t\t\t\t\t\t\t                /____             /  \n");
                printf("\t\t\t\t\t\t\t\t               /     \\           /  \n");
                printf("\t\t\t\t\t\t\t\t               \\______\\_________/ \n");
                ChangerCouleurTexte(14, 0);
                printf("\t\t\t    ______                              __        __       __  _                      ____  __                          ___    _\n");
                printf("\t\t\t   / ____/____  ____  ____ __________ _/ /___  __/ /____ _/ /_(_)____  ____  _____   / __ \\/ /____ ___  _____  _____   |__ \\  | |\n");
                printf("\t\t\t  / /    / __ \\/ __ \\/ __ `/ ___/ __ `/ __/ / / / // __ `/ __/ // __ \\/ __ \\/ ___/  / /_/ / // __ `/ / / / _ \\ / ___/     ) | | |\n");
                printf("\t\t\t / /___ / /_/ / / / / /_/ / /  / /_/ / /_/ /_/ / // /_/ / /_/ // /_/ / / / (__  )  / ____/ // /_/ / /_/ /  __ / /        / /  | |\n");
                printf("\t\t\t \\____/ \\____/_/ /_/\\__, /_/   \\__,_/\\__/\\__,_/_/ \\__,_/\\__/_/ \\____/_/ /_/____/  /_/   /_/ \\__,_/\\__, /\\___ /_/        / /_  |_|\n");
                printf("\t\t\t                   /____/                                                                        /____/                |____| (_)      \n\n");
                printf("\t\t\t\t  __   _____  _   _      _    ____  _____   _____ _   _ _____  __        _____ _   _ _   _ _____ ____               \n");
                printf("\t\t\t\t  \\ \\ / / _ \\| | | |    / \\  |  _ \\| ____| |_   _| | | | ____| \\ \\      / /_ _| \\ | | \\ | | ____|  _ \\ \n");
                printf("\t\t\t\t   \\ V / | | | | | |   / _ \\ | |_) |  _|     | | | |_| |  _|    \\ \\ /\\ / / | ||  \\| |  \\| |  _| | |_) |   \n");
                printf("\t\t\t\t    | || |_| | |_| |  / ___ \\|  _ <| |___    | | |  _  | |___    \\ V  V /  | || |\\  | |\\  | |___|  _ <         \n");
                printf("\t\t\t\t    |_| \\___/ \\___/  /_/   \\_\\_| \\_\\_____|   |_| |_| |_|_____|    \\_/\\_/  |___|_| \\_|_| \\_|_____|_| \\_\\  \n\n");
                ChangerCouleurTexte(15, 0);

                exit(0);
            }

            else if(e.nombrePionsHumain == 2 || PasMouvement2(e))
            {
                ChangerCouleurTexte(15, 0);
                printf("\t\t\t __     ______  _    _   _      ____   _____ ______ \n");
                printf("\t\t\t \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|\n");
                printf("\t\t\t  \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   \n");
                printf("\t\t\t   \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  \n");
                printf("\t\t\t    | | | |__| | |__| | | |___| |__| |____) | |____ \n");
                printf("\t\t\t    |_|  \\____/ \\____/  |______\\____/|_____/|______|\n");

                ChangerCouleurTexte(15, 0);
                exit(0);
            }

            jeuEnCours = true;
            break;
        case 3:
            jeuEnCours = true;
            break;
        default:
            printf("Choix invalide\n");
            break;
        }
    }
}
