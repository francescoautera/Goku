//
// Created by francesco on 11/10/17.
//

#include "Window.h"
Window::Window() {
    Setup("Pong", sf::Vector2u(800,600));
}

Window::~Window() {
    Destroy();
};

Window::Window(const std::string &title, const sf::Vector2u &size) {
    Setup(title, size);
}

void Window::Setup(const std::string &title, const sf::Vector2u &size) {
    windowTitle=title;
    windowSize=size;
    isDone = false;
    Create();
}

void Window::Update() {
    sf::Event event;
    while (window.pollEvent(event)){
        if(event.type==sf::Event::Closed)
            isDone = true;
    }
}

void Window::Create() {
    window.create({windowSize.x,windowSize.y }, windowTitle);
}

void Window::Destroy() {
    window.close();
}

void Window::BeginDraw() {
    window.clear(sf::Color::White);}

void Window::EndDraw() {
    window.display();
}

void Window::Draw(sf::Drawable &drawable) {
    window.draw(drawable);
}

sf::RenderWindow* Window::GetRenderWindow() {
    return &window;
}

sf::Vector2u Window::GetWindowSize() {
    return windowSize;
}
