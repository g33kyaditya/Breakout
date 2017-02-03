#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>


#include "defines.h"
#include "ball.h"
#include "paddle.h"

void solveBallPaddleCollision(Ball& ball, Paddle& paddle) {
    if (!(Game::isColliding(ball, paddle) ) )
        return;

    //std::cout << "COLLIDE\n";
    ball.mVelocity.y = -Ball::mSpeed;
    ball.mVelocity.x = ball.getX() < ( paddle.getX() + paddle.mWidth/2.0 ) ?
                       -Ball::mSpeed :
                       Ball::mSpeed  ;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Breakout");
    window.setFramerateLimit(60);

    Ball ball(WIDTH/2.0, HEIGHT/2.0);
    Paddle paddle(WIDTH/2 - paddle.mWidth/2.0, HEIGHT-paddle.mHeight-5);

    while(true) {
        window.clear(sf::Color::Black);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            break;

        ball.update();
        paddle.update();

        solveBallPaddleCollision(ball, paddle);

        ball.render(window);
        paddle.render(window);

        window.display();
    }
}

