#include <iostream>
#include "Goku.h"
#include "Game.h"

int main() {



sf::Texture texture;
texture.loadFromFile("Goku.png");
    Game game(&texture);

    while(!game.GetWindow()->IsDone()){
        game.HandleInput();
        game.Render();
        game.Update();
    }



    return 0;
}