//
// Created by francesco on 11/10/17.
//

#ifndef GOKU_ANIMATION_H
#define GOKU_ANIMATION_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation(sf::Texture*texture,float switchTime,sf::Vector2u imageCount);
    ~Animation();

    void Update(int row,float deltaTime);
    sf::Vector2u GetCurrentimage(){ return currentImage;}
    void SetCurrentimage(sf::Vector2u Currentimage){this->currentImage=Currentimage;}
    sf::IntRect uvRect;


private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float totalTime;
    float switchTIme;

};


#endif //GOKU_ANIMATION_H
