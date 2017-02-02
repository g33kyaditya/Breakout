#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
    Paddle(float x, float y);
    static const sf::Color mColor;
    static const float mSpeed;
    static const sf::Vector2f mSize;  
  
    sf::RectangularShape mShape;
    
    void update();
    void render(sf::RenderWindow & window);
};


#endif //PADDLE_H