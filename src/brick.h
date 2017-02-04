#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>

class Brick {
    public:
        Brick();
        Brick(float x, float y);
        static const sf::Color mColor;
        static const float mHeight;
        static const float mWidth;

        bool mDestroyed;
        sf::RectangleShape mShape;

        void update();
        void render(sf::RenderWindow & window);

        float getX();   //Returns the left edge's X value
        float getY();
        float getWidth();
        float getHeight();
        float getLeft();
        float getRight();
        float getTop();
        float getBottom();
};


#endif  //BRICK_H
