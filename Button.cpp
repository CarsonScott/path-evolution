#include "Button.hpp"

Button::Button()
{
    active = true;

    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("images/button.png");
    setTexture(*texture);
}

bool Button::isPressed(sf::Vector2i mousePosition)
{
    bool pressed = false;

    if(!getGlobalBounds().contains(sf::Vector2f(mousePosition)))
    {
        active = false;
    }
    else if(!active && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        active = true;
        pressed = true;
    }

    return pressed;
}
