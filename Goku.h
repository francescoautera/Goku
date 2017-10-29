//
// Created by francesco on 11/10/17.
//

#ifndef GOKU_GOKU_H
#define GOKU_GOKU_H

#include "Animation.h"
#include <SFML/Graphics.hpp>
#include "Window.h"

class Goku {
public:
    Goku(sf::Texture*texture,float switchTime,sf::Vector2u imageCount,float speed);
    ~Goku();

    void Update(float deltaTime);
    void Render(sf::RenderWindow& window);
    void CreateBall();
    void MoveBall();

    float Gethp(){return hp;}
    void Damage();

private:
    sf::RectangleShape body1;
    sf::RectangleShape Life;
    sf::RectangleShape death;
    bool faceRight;
    Animation animation;
    unsigned int row;
    float speed;
    sf::Texture gtexture;
    sf::CircleShape onda;
    float hp;

};


#endif //GOKU_GOKU_H
