//
// Created by francesco on 11/10/17.
//

#ifndef GOKU_WINDOW_H
#define GOKU_WINDOW_H

#include<SFML/Graphics.hpp>

class Window {
public:
    Window();
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    void BeginDraw();
    void EndDraw();
    void Update();

    bool IsDone(){return isDone;};
    sf::RenderWindow* GetRenderWindow();
    sf::Vector2u GetWindowSize();

    void Draw(sf::Drawable& drawable);

private:
    void Setup(const std::string& title, const sf::Vector2u& size);
    void Destroy();
    void Create();

    sf::RenderWindow window;
    bool isDone;
    sf::Vector2u windowSize;
    std::string windowTitle;
};


#endif //GOKU_WINDOW_H
