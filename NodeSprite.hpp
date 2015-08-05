#ifndef NODESPRITE_HPP_INCLUDED
#define NODESPRITE_HPP_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Node.hpp"

class NodeSprite:public sf::Sprite
{
    Node* node;
    bool active;
    sf::Vector2f targetPosition;
    sf::Texture texture;

    bool atTarget();
    void setTargetPosition();
    void controlMovement(float);
public:
    NodeSprite(Node&);
    void run();
    void reset();
    void update(float);
};

#endif // NODESPRITE_HPP_INCLUDED
