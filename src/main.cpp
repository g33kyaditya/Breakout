#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#include "defines.h"
#include "ball.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Breakout");
    window.setFramerateLimit(60);

    Ball ball(WIDTH/2.0, HEIGHT/2.0);

    while(true) {
        window.clear(sf::Color::Black);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            break;

        ball.update();
        ball.render(window);

        window.display();
    }
}

