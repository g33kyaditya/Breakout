#include "ball.h"
#include "defines.h"

const sf::Color Ball::mColor(sf::Color::Red);
const float Ball::mSpeed = 8.0;
const float Ball::mRadius = 10.0;
const int Ball::mPointCount = 100;

Ball::Ball(float x, float y)
{
    mShape.setPosition(x, y);
    mShape.setRadius(mRadius);
    mShape.setFillColor(mColor);
    mShape.setOrigin(mRadius, mRadius);
    mShape.setPointCount(mPointCount);
    mVelocity.x = -mSpeed;
    mVelocity.y = -mSpeed;
}

void Ball::update()
{
    mShape.move(mVelocity);

    if (getLeft() < 0)
        mVelocity.x = mSpeed;
    else if (getRight() > WIDTH)
        mVelocity.x = -mSpeed;

    if (getBottom() > HEIGHT)
        return;
    else if (getTop() < 0)
        mVelocity.y = mSpeed;
}

void Ball::render(sf::RenderWindow& window)
{
    window.draw(mShape);
}

float Ball::getX()
{
    return mShape.getPosition().x;
}

float Ball::getY()
{
    return mShape.getPosition().y;
}

float Ball::getBottom()
{
    return getY() + mShape.getRadius();
}

float Ball::getLeft()
{
    return getX() - mShape.getRadius();
}

float Ball::getRight()
{
    return getX() + mShape.getRadius();
}

float Ball::getTop()
{
    return getY() - mShape.getRadius();
}
