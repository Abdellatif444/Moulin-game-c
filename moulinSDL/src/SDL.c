#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"
#include "../include/SDL2.h"

#include "../include/struct.h"
#include "../include/jouer.h"

SDL_Window *window;
SDL_Surface *ecran;
Mix_Chunk *effect1 = NULL, *effect2 = NULL, *effect3 = NULL, *effect4 = NULL, *effect5 = NULL, *effect6 = NULL, *effect7 = NULL, *effect8 = NULL, *effect9 = NULL, *effect10 = NULL;
Mix_Music *music = NULL;

void SDL_Inialiser()
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
     if (TTF_Init() != 0)
    {
        SDL_Log("Unable to initialize SDL_TTF: %s", TTF_GetError());
        exit(EXIT_FAILURE);
    }


    music = Mix_LoadMUS("");
    effect1 = Mix_LoadWAV("src/sons/wavfil.wav");
    effect2 = Mix_LoadWAV("src/sons/mouve.wav");
    effect3 = Mix_LoadWAV("src/sons/buttonclicksound.wav");
    effect4 = Mix_LoadWAV("src/sons/button.wav");
    effect5 = Mix_LoadWAV("src/sons/rak_rbahti.wav");
    effect6 = Mix_LoadWAV("src/sons/CPUWinssound.wav");
}
void afficher_regles() {
    SDL_Surface *srcsurface;
    SDL_Rect destrect;

    srcsurface = IMG_Load("BH1.jpg");
    if (srcsurface == NULL) {
        printf("Erreur de chargement de l'image des règles : %s\n", SDL_GetError());
        return;
    }

    TTF_Font *font = TTF_OpenFont("res/popins.ttf", 29);
    if (font == NULL) {
        printf("Erreur de chargement de la police : %s\n", TTF_GetError());
        SDL_FreeSurface(srcsurface);
        return;
    }

   SDL_Color textColor = {255, 255, 255, 255}; // Blanc
    SDL_Surface *textSurface = TTF_RenderText_Blended_Wrapped(font, "\t\t\t ""Here are the rules of the Nine Men's Morris game: \n1. The game is played on a board with 24 intersection points.\n2. Each player has 9 pieces.\n3. Players take turns placing their pieces. If a player forms a line of three pieces, they can remove an opponent's piece.\n4.  The goal is to reduce the opponent to less than three pieces or block all their moves.", textColor, 700);
    if (textSurface == NULL) {
        printf("Erreur de rendu du texte : %s\n", TTF_GetError());
        TTF_CloseFont(font);
        SDL_FreeSurface(srcsurface);
        return;
    }

    destrect.x = 50;
    destrect.y = 50;
    destrect.h = srcsurface->h;
    destrect.w = srcsurface->w;

    SDL_Surface *ecran = SDL_GetWindowSurface(window);
    if (ecran == NULL) {
        printf("Erreur de récupération de la surface de la fenêtre : %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        SDL_FreeSurface(srcsurface);
        TTF_CloseFont(font);
        return;
    }

    SDL_BlitSurface(srcsurface, NULL, ecran, &destrect);

    SDL_Rect textRect;
    textRect.x = destrect.x + 20;
    textRect.y = destrect.y + 20;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    SDL_BlitSurface(textSurface, NULL, ecran, &textRect);

    SDL_UpdateWindowSurface(window);

    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(srcsurface);
    TTF_CloseFont(font);

    bool attente = true;
    SDL_Event event;
    while (attente) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_QUIT) {
                attente = false;
                break;
            }
        }
    }
}



int entrer_utilisateur(int joueur, etat e)
{
    int choix = -1;
    SDL_Event event;
    while (choix == -1 || e.P[choix].joueur != joueur)
    {
        SDL_UpdateWindowSurface(window);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                SDL_DestroyWindow(window);
                Mix_CloseAudio();
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    if (event.button.x >= 100 && event.button.y >= 18 && event.button.x <= 100 + 45 && event.button.y <= 18 + 45)
                        choix = 0;
                    if (event.button.x >= 369 && event.button.y >= 15 && event.button.x <= 369 + 45 && event.button.y <= 15 + 45)
                        choix = 1;
                    if (event.button.x >= 636 && event.button.y >= 15 && event.button.x <= 636 + 45 && event.button.y <= 15 + 45)
                        choix = 2;
                    if (event.button.x >= 180 && event.button.y >= 97 && event.button.x <= 180 + 45 && event.button.y <= 97 + 45)
                        choix = 3;
                    if (event.button.x >= 367 && event.button.y >= 96 && event.button.x <= 367 + 45 && event.button.y <= 96 + 45)
                        choix = 4;
                    if (event.button.x >= 555 && event.button.y >= 96 && event.button.x <= 555 + 45 && event.button.y <= 96 + 45)
                        choix = 5;
                    if (event.button.x >= 271 && event.button.y >= 179 && event.button.x <= 271 + 45 && event.button.y <= 179 + 45)
                        choix = 6;
                    if (event.button.x >= 367 && event.button.y >= 179 && event.button.x <= 367 + 45 && event.button.y <= 179 + 45)
                        choix = 7;
                    if (event.button.x >= 461 && event.button.y >= 179 && event.button.x <= 461 + 45 && event.button.y <= 179 + 45)
                        choix = 8;

                    if (event.button.x >= 101 && event.button.y >= 276 && event.button.x <= 101 + 45 && event.button.y <= 276 + 45)
                        choix = 9;
                    if (event.button.x >= 180 && event.button.y >= 277 && event.button.x <= 180 + 45 && event.button.y <= 277 + 45)
                        choix = 10;
                    if (event.button.x >= 271 && event.button.y >= 277 && event.button.x <= 271 + 45 && event.button.y <= 277 + 45)
                        choix = 11;
                    if (event.button.x >= 460 && event.button.y >= 277 && event.button.x <= 460 + 45 && event.button.y <= 277 + 45)
                        choix = 12;
                    if (event.button.x >= 555 && event.button.y >= 281 && event.button.x <= 555 + 45 && event.button.y <= 281 + 45)
                        choix = 13;
                    if (event.button.x >= 635 && event.button.y >= 281 && event.button.x <= 635 + 45 && event.button.y <= 281 + 45)
                        choix = 14;

                    if (event.button.x >= 271 && event.button.y >= 378 && event.button.x <= 271 + 45 && event.button.y <= 378 + 45)
                        choix = 15;
                    if (event.button.x >= 369 && event.button.y >= 378 && event.button.x <= 369 + 45 && event.button.y <= 378 + 45)
                        choix = 16;
                    if (event.button.x >= 462 && event.button.y >= 377 && event.button.x <= 462 + 45 && event.button.y <= 377 + 45)
                        choix = 17;
                    if (event.button.x >= 178 && event.button.y >= 456 && event.button.x <= 178 + 45 && event.button.y <= 456 + 45)
                        choix = 18;
                    if (event.button.x >= 368 && event.button.y >= 456 && event.button.x <= 368 + 45 && event.button.y <= 456 + 45)
                        choix = 19;
                    if (event.button.x >= 554 && event.button.y >= 458 && event.button.x <= 554 + 45 && event.button.y <= 458 + 45)
                        choix = 20;
                    if (event.button.x >= 102 && event.button.y >= 544 && event.button.x <= 102 + 45 && event.button.y <= 544 + 45)
                        choix = 21;
                    if (event.button.x >= 367 && event.button.y >= 543 && event.button.x <= 367 + 45 && event.button.y <= 543 + 45)
                        choix = 22;
                    if (event.button.x >= 633 && event.button.y >= 545 && event.button.x <= 633 + 45 && event.button.y <= 545 + 45)
                        choix = 23;
                    if (choix == -1)
                        Mix_PlayChannel(-1, effect7, 0);
                    break;
                }
            }
        }
    }
    return choix;
}

void afficher(etat e)
{
    SDL_Surface *srcsurface;
    SDL_Rect destrect;
    destrect.h = 45, destrect.w = 45;

    srcsurface = IMG_Load("src/images/window.png");
    SDL_BlitSurface(srcsurface, NULL, ecran, NULL);
    SDL_FreeSurface(srcsurface);
    SDL_UpdateWindowSurface(window);

    for (int i = 0; i < 24; i++)
    {
        switch (i)
        {
        case 0:
            destrect.x = 100;
            destrect.y = 18;
            break;
        case 1:
            destrect.x = 369;
            destrect.y = 15;
            break;
        case 2:
            destrect.x = 636;
            destrect.y = 15;
            break;
        case 3:
            destrect.x = 180;
            destrect.y = 97;
            break;
        case 4:
            destrect.x = 367;
            destrect.y = 96;
            break;
        case 5:
            destrect.x = 555;
            destrect.y = 96;
            break;
        case 6:
            destrect.x = 271;
            destrect.y = 179;
            break;
        case 7:
            destrect.x = 367;
            destrect.y = 179;
            break;
        case 8:
            destrect.x = 461;
            destrect.y = 179;
            break;

        case 9:
            destrect.x = 101;
            destrect.y = 276;
            break;
        case 10:
            destrect.x = 180;
            destrect.y = 277;
            break;
        case 11:
            destrect.x = 271;
            destrect.y = 277;
            break;
        case 12:
            destrect.x = 460;
            destrect.y = 277;
            break;
        case 13:
            destrect.x = 555;
            destrect.y = 281;
            break;
        case 14:
            destrect.x = 635;
            destrect.y = 281;
            break;
        case 15:
            destrect.x = 271;
            destrect.y = 378;
            break;
        case 16:
            destrect.x = 369;
            destrect.y = 378;
            break;
        case 17:
            destrect.x = 462;
            destrect.y = 377;
            break;
        case 18:
            destrect.x = 178;
            destrect.y = 456;
            break;
        case 19:
            destrect.x = 368;
            destrect.y = 456;
            break;
        case 20:
            destrect.x = 554;
            destrect.y = 458;
            break;
        case 21:
            destrect.x = 102;
            destrect.y = 544;
            break;
        case 22:
            destrect.x = 367;
            destrect.y = 543;
            break;
        case 23:
            destrect.x = 633;
            destrect.y = 545;
            break;
        }
        if (e.P[i].joueur == 1)
        {
            srcsurface = IMG_Load("src/images/pion1.png");
            SDL_BlitSurface(srcsurface, NULL, ecran, &destrect);
            SDL_FreeSurface(srcsurface);
        }

        if (e.P[i].joueur == 2)
        {
            srcsurface = IMG_Load("src/images/pion2.png");
            SDL_BlitSurface(srcsurface, NULL, ecran, &destrect);
            SDL_FreeSurface(srcsurface);
        }
    }
    SDL_UpdateWindowSurface(window);
}

void SDLmain(etat e)
{
    etat em;
    SDL_Inialiser();
    window = SDL_CreateWindow("Jeu Du Moulin", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);

    if (window == NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    ecran = SDL_GetWindowSurface(window);
    Mix_PlayMusic(music, -1);

    SDL_Surface *srcsurface;
    srcsurface = IMG_Load("src/images/window2.jpg");

    SDL_BlitSurface(srcsurface, NULL, ecran, NULL);
    SDL_FreeSurface(srcsurface);

    SDL_Rect destrect;

    srcsurface = IMG_Load("src/images/play.png");
    destrect.x = 250;
    destrect.y = 100;
    destrect.h = 100;
    destrect.w = 300;
    SDL_BlitSurface(srcsurface, NULL, ecran, &destrect);
    SDL_FreeSurface(srcsurface);
///bouton des regles

     // Ajout du bouton des règles
    srcsurface = IMG_Load("src/images/rules.png");
    destrect.x = 250;
    destrect.y = 240;
    destrect.h = 100;
    destrect.w = 300;
    SDL_BlitSurface(srcsurface, NULL, ecran, &destrect);
    SDL_FreeSurface(srcsurface);

    srcsurface = IMG_Load("src/images/exit.png");
    destrect.x = 250;
    destrect.y = 380;
    destrect.h = 100;
    destrect.w = 300;
    SDL_BlitSurface(srcsurface, NULL, ecran, &destrect);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(srcsurface);

    bool fermer = false;
    SDL_Event event;
    while (!fermer)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    if (event.button.x > 250 && event.button.x < 550 && event.button.y > 100 && event.button.y < 200)
                    {

                        afficher(e);
                        for (int i = 0; i < 9; i++)
                        {
                            int choix;
                            choix = entrer_utilisateur(0, e);
                            Mix_PlayChannel(-1, effect1, 0);
                            e.P[choix].joueur = 2;
                            printf("Vous avez choisi la position : %d\n", choix);
                            afficher(e);
                            if (MoulinForme(e.P, choix, 2) == 0)
                            {
                                if (pion_libre(e.P) == 0)
                                {
                                    do
                                    {
                                        choix = entrer_utilisateur(1, e);
                                    } while (MoulinForme(e.P, choix, 1) == 0);
                                    Mix_PlayChannel(-1, effect3, 0);
                                    e.P[choix].joueur = 0;
                                    printf("Vous avez capture le pion : %d\n", choix);
                                    afficher(e);
                                    e.pos1--;
                                }
                            }
                            Nbr_des_pions_poser++;

                            em = AlphaBeta(e, 3, Nbr_des_pions_poser, true, -999999, 999999);
                            Mix_PlayChannel(-1, effect1, 0);
                            e.P[em.pos].joueur = 1;
                            printf("La machine choisi la position : %d\n", em.pos);
                            afficher(e);
                            if (em.pC != -1)
                            {
                                Mix_PlayChannel(-1, effect3, 0);
                                e.P[em.pC].joueur = 0;
                                printf("La machine a capture le pion : %d\n", em.pC);
                                afficher(e);
                                e.pos2--;
                            }
                            Nbr_des_pions_poser++;
                        }
                        while (e.pos1 >2 && e.pos2 > 2 && !BlockageMouvement1(e) && !BlockageMouvement2(e))
                        {
                            int source = -1, destination = -1;
                            do
                            {
                                source = entrer_utilisateur(2, e);
                                destination = entrer_utilisateur(0, e);
                            } while (!(VoisinagesPion(source, destination, e, 2) == 0 && e.P[destination].joueur == 0));
                            Mix_PlayChannel(-1, effect2, 0);
                            e.P[source].joueur = 0;
                            e.P[destination].joueur = 2;
                            printf("Vous avez passez de %d a %d\n", source, destination);
                            afficher(e);
                            if (MoulinForme(e.P, destination, 2) == 0)
                            {
                                if (pion_libre(e.P) == 0)
                                {
                                    int choix;
                                    do
                                    {
                                        choix = entrer_utilisateur(1, e);
                                    } while (MoulinForme(e.P, choix, 1) == 0);
                                    Mix_PlayChannel(-1, effect3, 0);
                                    e.P[choix].joueur = 0;
                                    printf("Vous avez capture le pion : %d\n", choix);
                                    afficher(e);
                                    e.pos1--;
                                }
                            }
                            Nbr_des_pions_poser++;
                            em = AlphaBeta(e, 3, Nbr_des_pions_poser, true, -999999, 999999);
                            Mix_PlayChannel(-1, effect1, 0);
                            e.P[em.pos].joueur = 1;
                            e.P[em.presd].joueur = 0;
                            printf("La machine passe de %d a %d\n", em.presd, em.pos);
                            afficher(e);
                            if (em.pC != -1)
                            {
                                Mix_PlayChannel(-1, effect3, 0);
                                e.P[em.pC].joueur = 0;
                                printf("La machine a capture le pion : %d\n", em.pC);
                                afficher(e);
                                e.pos2--;
                            }
                            Nbr_des_pions_poser++;
                        }

                        SDL_UpdateWindowSurface(window);
                        SDL_Delay(500);

                        if (e.pos1 ==2 || BlockageMouvement1(e))
                        {
                            Mix_PlayChannel(-1, effect5, 0);
                            srcsurface = IMG_Load("win.jpeg");
                            destrect.x = 175;
                            destrect.y = 75;
                            destrect.h = 307;
                            destrect.w = 450;
                            SDL_BlitSurface(srcsurface, NULL, ecran, &destrect);
                            SDL_UpdateWindowSurface(window);
                            SDL_FreeSurface(srcsurface);
                            SDL_Delay(2000);
                        }
                        else
                        {
                            Mix_PlayChannel(-1, effect6, 0);
                            srcsurface = IMG_Load("loose.jpg");
                            destrect.x = 150;
                            destrect.y = 50;
                            destrect.h = 307;
                            destrect.w = 450;
                            SDL_BlitSurface(srcsurface, NULL, ecran, &destrect);
                            SDL_UpdateWindowSurface(window);
                            SDL_FreeSurface(srcsurface);
                            SDL_Delay(2000);
                        }

                        fermer = true;
                        break;
                    }///bouton des regles
                    if (event.button.x > 250 && event.button.x < 550 && event.button.y > 240 && event.button.y < 340)
                    {


                        afficher_regles();
                    }

                    if (event.button.x > 250 && event.button.x < 550 && event.button.y > 380 && event.button.y < 480)
                    {
                        fermer = true;
                    }
                    break;
                }
                break;
            case SDL_QUIT:
                fermer = true;
                break;
            }
        }
    }
}
