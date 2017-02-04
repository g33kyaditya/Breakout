#include "brick.h"
#include "defines.h"

const float Brick::mHeight = 20;
const float Brick::mWidth = 60;
const sf::Color Brick::mColor = sf::Color::Green;

Brick::Brick()
{

}

Brick::Brick(float x, float y)
{
    mShape.setPosition(x, y);
    mShape.setFillColor(mColor);
    mShape.setSize(sf::Vector2f(mWidth, mHeight));
    mDestroyed = false;
}

void Brick::render(sf::RenderWindow& window)
{
    window.draw(mShape);
}

void Brick::update()
{

}

float Brick::getX()
{
    return mShape.getPosition().x;
}

float Brick::getY()
{
    return mShape.getPosition().y;
}

float Brick::getBottom()
{
    return getY() + getHeight();
}

float Brick::getHeight()
{
    return mShape.getSize().y;
}

float Brick::getLeft()
{
    return getX() - BRICKSPACING;
}

float Brick::getRight()
{
    return getX() + getWidth() + BRICKSPACING;
}

float Brick::getTop()
{
    return getY();
}

float Brick::getWidth()
{
    return mShape.getSize().x;
}
