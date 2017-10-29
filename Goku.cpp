//
// Created by francesco on 11/10/17.
//

#include "Goku.h"
Goku::Goku(sf::Texture *texture, float switchTime, sf::Vector2u imageCount, float speed):animation(texture,switchTime,imageCount)
{


    this->speed=speed;
    row=0;
    faceRight= true;
    body1.setPosition(100,300);
    body1.setSize(sf::Vector2f(100,100));
    body1.setTexture(texture);
    body1.setFillColor(sf::Color::White);
    Life.setFillColor (sf::Color::Green);
    hp=100;
    Life.setPosition (100,1);
    Life.setSize (sf::Vector2f(100,20));
    death.setSize (sf::Vector2f(100,20)) ;
    death.setPosition (100,1);
    death.setFillColor (sf::Color::Red);

    }



void Goku::Render(sf::RenderWindow &window) {
    window.draw(body1);
    window.draw(onda);
    window.draw (death);
    window.draw (Life);
    if(Gethp ()==0){
        sf::Text text;
        text.setString ("GameOver");
        text.setColor (sf::Color::Red);
        text.setPosition (300,300);
        sf::Font font;
        font.loadFromFile ("arial.ttf");
        text.setFont (font);
        window.draw (text);

        }
}

void Goku::Update(float deltaTime) {
    sf::Vector2f movement(0.0f,0.0f);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movement.x-=speed*deltaTime;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x+=speed*deltaTime;

    }
        sf::Event event;

     if (movement.x==0&&sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        row=2;
         animation.SetCurrentimage(sf::Vector2u(0,2));
         }else if(movement.x==0&&event.key.code==sf::Keyboard::Space){
         row=2;
         animation.SetCurrentimage(sf::Vector2u(1,2));
         CreateBall();
         MoveBall();
         Damage ();

     }

     else if(movement.x==0) { row=0;}

    if(movement.x>0||movement.x<0){
        row=1;
    }

    if(movement.x>0.0f){
        animation.SetCurrentimage(sf::Vector2u(0,1));
    }else if(movement.x<0.0f){
        animation.SetCurrentimage(sf::Vector2u(1,1));
    }



    animation.Update(row,deltaTime);
    body1.setTextureRect(animation.uvRect);
    body1.move(movement);

}

Goku::~Goku() {}


void Goku::CreateBall() {
    onda.setPosition(body1.getPosition().x+100,body1.getPosition().y+40);
    onda.setFillColor(sf::Color::Red);
    onda.setRadius(body1.getSize().x/4);

}


void Goku::MoveBall() {
     sf::Vector2f moveball(1,0);

    if(moveball.x>0){
        onda.setPosition(onda.getPosition().x+moveball.x,onda.getPosition().y+moveball.y);
    }
}


void Goku::Damage() {

      Life.setSize (sf::Vector2f(Gethp ()-10,20));
    hp-=10;

    }

