#include "paddle.h"

const sf::Color Paddle::mColor(sf::Color::Blue);
static const float mSpeed = 6.0;

Paddle::Paddle(float x, float y)
{
    mShape.setPosition(x, y);
    mShape.setFillColor(mColor);
}

void Paddle::render(sf::RenderWindow & window)
{
    window.draw(mShape);
}