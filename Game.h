//
// Created by francesco on 30/09/17.
//

#ifndef PROVA_GAME_H
#define PROVA_GAME_H


#include "Window.h"
#include "Goku.h"
#include "Animation.h"


class Game {
public:
    Game(sf::Texture*texture);
    ~Game();

    void Update();
    void Render();
    void HandleInput();
    Window* GetWindow(){return &window;}




private:
    Goku goku;
    Window window;




};


#endif //PROVA_GAME_H
