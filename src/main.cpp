#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>


#include "defines.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"

void solveBallPaddleCollision(Ball& ball, Paddle& paddle) {
    if (!(Game::isColliding(ball, paddle) ) )
        return;

    //std::cout << "COLLIDE\n";
    ball.mVelocity.y = -Ball::mSpeed;
    ball.mVelocity.x = ball.getX() < ( paddle.getX() + paddle.mWidth/2.0 ) ?
                       -Ball::mSpeed :
                       Ball::mSpeed  ;
}

void solveBallBrickCollision(Ball& ball, Brick& brick) {
    if (!(Game::isColliding(ball, brick)))
        return;

    brick.mDestroyed = true;

    float leftOverlap = ball.getRight() - brick.getLeft();
    float rightOverlap = brick.getRight() - ball.getLeft();
    float topOverlap = ball.getBottom() - brick.getTop();
    float bottomOverlap = brick.getBottom() - ball.getTop();

    bool ballFromLeft = false, ballFromTop = false;
    if (std::abs(leftOverlap) < std::abs(rightOverlap) )
        ballFromLeft = true;
    if (std::abs(topOverlap) < std::abs(bottomOverlap) )
        ballFromTop = true;

    float minOverLapX, minOverLapY;
    minOverLapX = (leftOverlap < rightOverlap) ? leftOverlap : rightOverlap;
    minOverLapY = (topOverlap < bottomOverlap) ? topOverlap : bottomOverlap;

    if (std::abs(minOverLapX) > std::abs(minOverLapY))
        ball.mVelocity.y = ballFromTop ? -Ball::mSpeed : Ball::mSpeed;
    else
        ball.mVelocity.x = ballFromLeft ? -Ball::mSpeed : Ball::mSpeed;

}

void fillGridWithBricks(std::vector<Brick>& grid) {
    for (int i = 0; i < BRICKROWS; i++) {
        for (int j = 0; j < BRICKCOLUMNS; j++) {
            float y = i*(BRICKSPACING + Brick::mHeight);
            float x = j*(BRICKSPACING + Brick::mWidth);
            grid.emplace_back(Brick(x, y));
        }
    }

}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Breakout");
    window.setFramerateLimit(60);

    Ball ball(WIDTH/2.0, HEIGHT/2.0);
    Paddle paddle(WIDTH/2 - paddle.mWidth/2.0, HEIGHT-paddle.mHeight-VERTICALWINDOWSPACKING);
    std::vector<Brick> grid;
    fillGridWithBricks(grid);

    while(true) {
        window.clear(sf::Color::White);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            break;

        ball.update();
        paddle.update();

        for (Brick& brick : grid) {
            solveBallBrickCollision(ball, brick);
        }
        solveBallPaddleCollision(ball, paddle);

        grid.erase(std::remove_if (std::begin(grid), std::end(grid),        //Beautiful code by
                     [](const auto& brick) {return brick.mDestroyed;} ),    //Vittorio Romeo
                     std::end(grid));


        for (Brick& brick : grid) {
            brick.render(window);
        }
        ball.render(window);
        paddle.render(window);

        window.display();
    }

    return 0;
}

