#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {

    public:
        Ball(float x, float y);
        static const sf::Color mColor;
        static const float mSpeed;
        static const float mRadius;
        static const int mPointCount;

        sf::Vector2f mVelocity;

        sf::CircleShape mShape;

        void update();
        void render(sf::RenderWindow & window);

        float getX();
        float getY();
        float getTop();
        float getBottom();
        float getLeft();
        float getRight();
};

#endif // BALL_H
