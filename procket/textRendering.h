#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "menu.h"



void CreateText(const char* message, int x, int y, TTF_Font *fnt, int FontSize, SDL_Texture* &TextTexture, SDL_Rect &TextRect, Uint8 R=255, Uint8 G=255, Uint8 B=255, Uint8 A=255) {
    /*TTF_Init();
    TTF_Font *font = TTF_OpenFont(font_name, font_size);
    if(!font)
    {
        //Some Xterm ansi escape codes to highligh errors easier
        std::cout << "\x1b[38;5;196m" << font_name << " Not found!" << "\x1b[0m" << std::endl;
        //If font not found exit instead of remaining stuck (font not found, idk what to do lool)
        exit(0);
    }*/
    TTF_SetFontSize(fnt, FontSize);
    TextSurface = TTF_RenderText_Solid(fnt, message, {R, G, B, A});
    TextTexture = SDL_CreateTextureFromSurface(Renderer, TextSurface);
    TextRect.x = x; // Center horizontaly
    TextRect.y = y; // Center verticaly
    TextRect.w = TextSurface->w;
    TextRect.h = TextSurface->h;

    
    // After you create the texture you can release the surface memory allocation because we actually render the texture not the surface.
    //SDL_FreeSurface(TextSurface);
    

    //TTF_Quit();
}
