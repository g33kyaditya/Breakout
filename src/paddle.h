#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {

    public:
        Paddle(float x, float y);
        static const sf::Color mColor;
        static const float mSpeed;
        static const float mWidth;
        static const int mHeight;

        sf::Vector2f mVelocity;
        sf::RectangleShape mShape;

        void update();
        void render(sf::RenderWindow & window);
        void processInput();

        float getX();
        float getY();
        float getHeight();
        float getWidth();
        float getLeft();
        float getRight();
        float getTop();
        float getBottom();
};

#endif // PADDLE_H
