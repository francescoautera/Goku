//
// Created by francesco on 30/09/17.
//

#include "Game.h"
Game::Game(sf::Texture*texture):window("Pong!",sf::Vector2u(800,600)),goku(texture,0,sf::Vector2u(2,3),0.4) {

}

Game::~Game() {

}

void Game::Update() {
    window.Update();
    goku.Update(0.2);
    goku.MoveBall();

}

void Game::Render(){
    window.BeginDraw();
    goku.Render(*window.GetRenderWindow());
    window.EndDraw();
}


void Game::HandleInput() {}