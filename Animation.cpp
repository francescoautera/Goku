//
// Created by francesco on 11/10/17.
//

#include "Animation.h"

Animation::Animation(sf::Texture *texture, float switchTime, sf::Vector2u imageCount) {
    this->imageCount=imageCount;
    this->switchTIme=switchTime;
    totalTime=0.0f;
    currentImage.x=0;

    uvRect.width=texture->getSize().x/(imageCount.x);
    uvRect.height=texture->getSize().y/(imageCount.y);

}

Animation::~Animation() {}


void Animation::Update(int row, float deltaTime) {
     currentImage.y=row;
    totalTime+=deltaTime;

    if(totalTime>=switchTIme){
        totalTime-=switchTIme;
        //currentImage.x++;

        if(currentImage.x>=imageCount.x){
           currentImage.x=0;
        }
     uvRect.left=currentImage.x*uvRect.width;
     uvRect.top=currentImage.y*uvRect.height;
    }

}


