#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
    public :
        Paddle(float x, float y);
        static const sf::Color mColor;
        static const float mSpeed;
        static const float mWidth;
        static const float mHeight;
        static const int mWindowGap;      //Gap b/w paddle and window

        sf::Vector2f mVelocity;
        sf::RectangleShape mShape;

        void update();
        void render(sf::RenderWindow & window);
        void processInput();

        float getX();   //Returns the left edge's X value
        float getY();
        float getWidth();
        float getHeight();
        float getLeft();
        float getRight();
        float getTop();
        float getBottom();
};


#endif //PADDLE_H
