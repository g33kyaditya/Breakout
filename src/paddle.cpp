#include "paddle.h"
#include "defines.h"

const sf::Color Paddle::mColor(sf::Color::Blue);
const float Paddle::mSpeed = 9.0;
const float Paddle::mWidth = 100;
const float Paddle::mHeight = 20;

Paddle::Paddle(float x, float y)
{
    mShape.setPosition(x, y);
    mShape.setFillColor(mColor);
    mShape.setSize(sf::Vector2f(mWidth, mHeight));
}

void Paddle::update()
{
    processInput();
    mShape.move(mVelocity);
}

void Paddle::render(sf::RenderWindow & window)
{
    window.draw(mShape);
}

void Paddle::processInput()
{ 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeft() > 0)
        mVelocity.x = -mSpeed;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRight() < WIDTH)
        mVelocity.x = mSpeed;
    else
        mVelocity.x = 0;
}

float Paddle::getX()
{
    return mShape.getPosition().x;
}

float Paddle::getY()
{
    return mShape.getPosition().y;
}

float Paddle::getHeight()
{
    return mShape.getSize().y;
}

float Paddle::getWidth()
{
    return mShape.getSize().x;
}

float Paddle::getLeft()
{
    return getX() - VERTICALWINDOWSPACKING;
}

float Paddle::getRight()
{
    return getX() + getWidth() + VERTICALWINDOWSPACKING;
}

float Paddle::getTop()
{
    return getY();
}

float Paddle::getBottom()
{
    return getY() + getHeight();
}
