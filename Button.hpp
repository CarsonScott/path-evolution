#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class Button: public sf::Sprite
{
    bool active;
public:
    Button();
    bool isPressed(sf::Vector2i);
};

#endif // BUTTON_HPP_INCLUDED
