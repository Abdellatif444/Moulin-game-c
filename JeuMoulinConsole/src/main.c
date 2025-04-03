#include <stdio.h>
#include <stdlib.h>

#include "../include/grille.h"
#include "../include/game.h"
#include "../include/structure.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

void displayWelcomeScreen()
{
    // Page d'entree
    printf("\n");
    ChangerCouleurTexte(9, 0);
    printf("\t\t\t\t   GGGGGGGG      A      MMM     MMM  EEEEEEEE\n");
    printf("\t\t\t\t  GG            A A     MM  M M  MM  EE      \n");
    printf("\t\t\t\t  GG   GGGG    AAAAA    MM   M   MM  EEEEEEEE\n");
    printf("\t\t\t\t  GG     GG   A     A   MM       MM  EE      \n");
    printf("\t\t\t\t   GGGGGGGG  A       A  MM       MM  EEEEEEEE\n");
    printf("\n\n");
    ChangerCouleurTexte(10, 0);
    printf("\t   NNN   NNN   IIIIII  NNN   NNN  EEEEEEEE");
    ChangerCouleurTexte(12, 0);
    printf("       MMM     MMM  EEEEEEEE  NNN      NN   SSSSSS \n");
    ChangerCouleurTexte(10, 0);
    printf("\t   NNNN  NNN     II    NNNN  NNN  EE      ");
    ChangerCouleurTexte(12, 0);
    printf("       MM  M M  MM  EE        NNN NN   NN   S\n");
    ChangerCouleurTexte(10, 0);
    printf("\t   NN NN NNN     II    NN NN NNN  EEEEEE   ");
    ChangerCouleurTexte(12, 0);
    printf("      MM   M   MM  EEEEE     NN   NN  NN   SSSSSS\n");
    ChangerCouleurTexte(10, 0);
    printf("\t   NN   NNNN     II    NN   NNNN  EE     ");
    ChangerCouleurTexte(12, 0);
    printf("        MM       MM  EE        NN      NNN        S\n");
    ChangerCouleurTexte(10, 0);
    printf("\t   NN   NNNN   IIIIII  NN   NNNN  EEEEEEEE ");
    ChangerCouleurTexte(12, 0);
    printf("      MM       MM  EEEEEEEE  NN       NN   SSSSSS\n");
    ChangerCouleurTexte(11, 0);
    printf("\n\n");

    ChangerCouleurTexte(1, 0);
    printf("\t\t\tMMM     MMM   OOOOOOOO   RRRRRRR   RRRRRRR   IIIIII   SSSSSS\n");
    ChangerCouleurTexte(1, 0);
    printf("\t\t\tMM  M M  MM   OO    OO   RR    RR  RR    RR    II     S      \n");
    ChangerCouleurTexte(1, 0);
    printf("\t\t\tMM   M   MM   OO    OO   RRRRRRR   RRRRRRR     II     SSSSSS \n");
    ChangerCouleurTexte(1, 0);
    printf("\t\t\tMM       MM   OO    OO   RR   RR   RR   RR     II          S \n");
    ChangerCouleurTexte(1, 0);
    printf("\t\t\tMM       MM   OOOOOOOO   RR    RR  RR    RR  IIIIII   SSSSSS  \n");

    ChangerCouleurTexte(7, 0);
    printf("\n");
    printf("                                            ____________________");
    printf("\n");
    printf("                                           |                    |");
    printf("\n");
    printf("                                           | - GOURRI ABDELLATIF|");
    printf("\n");
    printf("                                           | -MOUH KAOUTAR      |  ");
    printf("\n");
    printf("                                           | -TALEB DOAA        |  ");
    printf("\n");
    printf("                                           | -TARMOUMIA HIBA    |  ");
    printf("\n");
    printf("                                           |____________________|");
    printf("\n\n\n");
    getch();
}
void displayMenu()
{
    system("cls ");
    printf("\n\n");
    // MENU 1
    printf("\t      			        	  _______________________\n");
    printf("\t        			    	 /                       \\\n");
    printf("\t        			    	(     1 >  P L A Y        )\n");
    printf("\t          			    	 \\_______________________/\n");
    printf("\t       			        	  _______________________\n");
    printf("\t        			    	 /                       \\\n");
    printf("\t        			    	(     2 > R U L ES        )\n");
    printf("\t          			    	 \\_______________________/\n");
    printf("\t       			        	  _______________________\n");
    printf("\t        			    	 /                       \\\n");
    printf("\t        			    	(    3 > E X I T          )\n");
    printf("\t          			    	 \\_______________________/\n");
    printf("\n\n");
    printf("\t       			        |-->ENTER YOUR CHOICE :  ");
}
void displayRules()
{
    system("cls");
                printf("                     \n");
                printf("\t\t\t\t\t\t\t    _____     _   _    _      ______   ______        \n");
                printf("\t\t\t\t\t\t\t   |  ___ \\  | | | |  | |    |  ____| |  ____|   \n");
                printf("\t\t\t\t\t\t\t   | |___) ) | | | |  | |    | |__    |  |___   \n");
                printf("\t\t\t\t\t\t\t   |      /  | |_| |  | |    |  __|   |____  |  \n");
                printf("\t\t\t\t\t\t\t   | | \\ \\   | |_| |  | |___ | |____   ____| |    \n");
                printf("\t\t\t\t\t\t\t   |_|  \\_\\   \\___/   \\_____||______| |______|      \n");
                printf("\n\n");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("       ____________________________________________________________________________________________________________________________________\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("Players take turns to play a piece of their own colour on any unoccupied point until all eighteen pieces have been played.   ");
    ChangerCouleurTexte(3, 0);
    printf("       |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("After that, play continues alternately but each turn consists of a player moving one piece along a line to an adjacent empty point.");
    ChangerCouleurTexte(3, 0);
    printf(" |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("During each turn, whenever a player has three of their pieces in a line, they form a mill.");
    ChangerCouleurTexte(3, 0);
    printf("                                          |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("That player then immediately removes from the board one piece belonging to the opponent that does not form part of a mill.");
    ChangerCouleurTexte(3, 0);
    printf("          |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("If all of the opponent's pieces form mills, then the player is allowed to remove any one of the opponent's pieces.");
    ChangerCouleurTexte(3, 0);
    printf("                  |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("Players may break a mill by moving a piece out of it and then, in a subsequent turn,");
    ChangerCouleurTexte(3, 0);
    printf("                                                |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("play the piece back again, thus forming a new mill and capturing another piece.");
    ChangerCouleurTexte(3, 0);
    printf("                                                     |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("Captured pieces cannot be reclaimed and are out of the game.");
    ChangerCouleurTexte(3, 0);
    printf("                                                                        |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("When a player is reduced to three pieces they may then move to any vacant point on the board.");
    ChangerCouleurTexte(3, 0);
    printf("                                       |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |                                                                                                                                    |");
    printf("\n");
    ChangerCouleurTexte(8, 0);
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |");
    ChangerCouleurTexte(14, 0);
    printf("The player wins the game when either they reduce their opponent to two pieces or by leaving them without a legal move.");
    ChangerCouleurTexte(3, 0);
    printf("              |\n   ");
    printf("\t\t");
    ChangerCouleurTexte(3, 0);
    printf("      |____________________________________________________________________________________________________________________________________|\n");
    ChangerCouleurTexte(8, 0);
    getch();
    system("cls");
}
int main()
{
    srand(time(NULL));
    EtatJeu e;
    while (1)
    {
        displayWelcomeScreen();
    playMenu:
        ChangerCouleurTexte(7, 0);
        displayMenu();
        int choix;
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            for (int i = 0; i < 24; i++)
            {
                e.position[i].lettre = 'a' + i;
                e.position[i].joueur = 0;
            }

            // couleur des joueurs
            for (int i = 0; i < 24; i++)
            {
                if (e.position[i].joueur == 1)
                {
                    e.position[i].couleur = 9;
                }
                else if (e.position[i].joueur == 2)
                {
                    e.position[i].couleur = 12;
                }
                else
                {
                    e.position[i].couleur = 0;
                }
            }
            // voisins
            e.position[0].v1 = 'b';
            e.position[0].v2 = 'j';
            e.position[0].v3 = '&';
            e.position[0].v4 = '&';
            e.position[1].v1 = 'a';
            e.position[1].v2 = 'c';
            e.position[1].v3 = 'e';
            e.position[1].v4 = '&';
            e.position[2].v1 = 'b';
            e.position[2].v2 = 'o';
            e.position[2].v3 = '&';
            e.position[2].v4 = '&';
            e.position[3].v1 = 'e';
            e.position[3].v2 = 'k';
            e.position[3].v3 = '&';
            e.position[3].v4 = '&';
            e.position[4].v1 = 'b';
            e.position[4].v2 = 'd';
            e.position[4].v3 = 'f';
            e.position[4].v4 = 'h';
            e.position[5].v1 = 'e';
            e.position[5].v2 = 'n';
            e.position[5].v3 = '&';
            e.position[5].v4 = '&';
            e.position[6].v1 = 'h';
            e.position[6].v2 = 'l';
            e.position[6].v3 = '&';
            e.position[6].v4 = '&';
            e.position[7].v1 = 'g';
            e.position[7].v2 = 'e';
            e.position[7].v3 = 'i';
            e.position[7].v4 = '&';
            e.position[8].v1 = 'h';
            e.position[8].v2 = 'm';
            e.position[8].v3 = '&';
            e.position[9].v4 = '&';
            e.position[9].v1 = 'a';
            e.position[9].v2 = 'k';
            e.position[9].v3 = 'v';
            e.position[9].v4 = '&';
            e.position[10].v1 = 'j';
            e.position[10].v2 = 'd';
            e.position[10].v3 = 'l';
            e.position[10].v4 = 's';
            e.position[11].v1 = 'k';
            e.position[11].v2 = 'g';
            e.position[11].v3 = 'p';
            e.position[11].v4 = '&';
            e.position[12].v1 = 'i';
            e.position[12].v2 = 'n';
            e.position[12].v3 = 'r';
            e.position[12].v4 = '&';
            e.position[13].v1 = 'm';
            e.position[13].v2 = 'f';
            e.position[13].v3 = 'o';
            e.position[13].v4 = 'u';
            e.position[14].v1 = 'n';
            e.position[14].v2 = 'c';
            e.position[14].v3 = 'x';
            e.position[14].v4 = '&';
            e.position[15].v1 = 'l';
            e.position[15].v2 = 'q';
            e.position[15].v3 = '&';
            e.position[15].v4 = '&';
            e.position[16].v1 = 'p';
            e.position[16].v2 = 'r';
            e.position[16].v3 = 't';
            e.position[16].v4 = '&';
            e.position[17].v1 = 'q';
            e.position[17].v2 = 'm';
            e.position[17].v3 = '&';
            e.position[17].v4 = '&';
            e.position[18].v1 = 'k';
            e.position[18].v2 = 't';
            e.position[18].v3 = '&';
            e.position[18].v4 = '&';
            e.position[19].v1 = 's';
            e.position[19].v2 = 'q';
            e.position[19].v3 = 'u';
            e.position[19].v4 = 'w';
            e.position[20].v1 = 't';
            e.position[20].v2 = 'n';
            e.position[20].v3 = '&';
            e.position[20].v4 = '&';
            e.position[21].v1 = 'j';
            e.position[21].v2 = 'w';
            e.position[21].v3 = '&';
            e.position[21].v4 = '&';
            e.position[22].v1 = 'v';
            e.position[22].v2 = 't';
            e.position[22].v3 = 'x';
            e.position[22].v4 = '&';
            e.position[23].v1 = 'w';
            e.position[23].v2 = 'o';
            e.position[23].v3 = '&';
            e.position[23].v4 = '&';

            e.nombrePionsMachine = 9;
            e.nombrePionsHumain = 9;

            beginmain(e);
            break;
        case 2:
            displayRules();
            goto playMenu;
            break;
        case 3:
            printf("Do you really want to go out? [y/n]\n");
            char confirmation;
            scanf(" %c", &confirmation);
            if (confirmation == 'y')
            {
                return 0;
                break;
            }
            else if (confirmation == 'n')
            {
                system("cls");
            }
        default:
            printf("\n NOT RESPOND CORRECTLY ......\n");
            break;
        }
    }

    return 0;
}
