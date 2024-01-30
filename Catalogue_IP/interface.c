#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <interface.h>

int main(int argc, char const *argv[]) {

    int ev = 20;
    int eh = 175;
    int boutton = 1;

    SDL_Window *window = creation_de_fenetre();
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    

    if (renderer == NULL) {
        SDL_Log("Erreur : Création du renderer > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
         exit(EXIT_FAILURE);
    }

    TTF_Font *snowman = TTF_OpenFont("Snowman.ttf", 35);
    TTF_Font *snowman_titre = TTF_OpenFont("Snowman.ttf", 100);


    if (snowman == NULL) {
        SDL_Log("Erreur : Chargement de la police > %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    for (int compteur = 1; compteur <= 2; compteur++) {
        int py = compteur * (150 + ev);

        for (int c = 1; c <= 2; c++) {

            int px = c * (50 + eh);
            if (c == 1 && compteur == 1) {
                
                creation_rectangle(renderer, 50, py);
                creation_texte(renderer, snowman, "Ajouter une adresse IP", 110, py + 25);
            }
            if (c == 1 && compteur == 2) {
                
                creation_rectangle(renderer, 50, py);
                creation_texte(renderer, snowman, "Utiliser les adresse dans la base", 70, py + 25);
            }
            if (c == 2 && compteur == 1) {
                creation_rectangle(renderer, px, py);
                creation_texte(renderer, snowman, "Selectionner une adresse", px +50 , py + 25);
            } 
            if (c == 2 && compteur == 2) {
                creation_rectangle(renderer, px, py);
                creation_texte(renderer, snowman, "Recherche par masque", px + 50, py + 25);
            } 
        }
    }

    creation_texte(renderer, snowman_titre, "IP C-atalogue", 250, 25);
    SDL_RenderPresent(renderer);
    while (boutton) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                boutton = 0;
            }
        }
    }

    TTF_CloseFont(snowman);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();

    return 0;
}
