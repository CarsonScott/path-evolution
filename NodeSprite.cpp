#include "NodeSprite.hpp"

void NodeSprite::setTargetPosition()
{
    sf::Vector2f currentPosition = getPosition();
    targetPosition = currentPosition;

    Direction currentPath = node->getCurrentPath();
    int tileSize = 50;

    if(currentPath == Left)
    {
        targetPosition.x -= tileSize;
    }
    else if(currentPath == Right)
    {
        targetPosition.x += tileSize;
    }
    else if(currentPath == Up)
    {
        targetPosition.y -= tileSize;
    }
    else if(currentPath == Down)
    {
        targetPosition.y += tileSize;
    }
}

bool NodeSprite::atTarget()
{
    bool atTarget;
    if(getPosition() == targetPosition)
    {
        atTarget = true;
    }
    else
    {
        atTarget = false;
    }

    return atTarget;
}

void NodeSprite::controlMovement(float dt)
{
    sf::Vector2f currentPosition = getPosition();
    int speed = 50;

    if(targetPosition.x < currentPosition.x)
    {
        move(-speed*dt, 0);

        if(targetPosition.x >= getPosition().x)
        {
            setPosition(targetPosition);
        }
    }
    else if(targetPosition.x > currentPosition.x)
    {
        move(speed*dt, 0);

        if(targetPosition.x <= getPosition().x)
        {
            setPosition(targetPosition);
        }
    }

    if(targetPosition.y < currentPosition.y)
    {
        move(0, -speed*dt);

        if(targetPosition.y >= getPosition().y)
        {
            setPosition(targetPosition);
        }
    }
    else if(targetPosition.y > currentPosition.y)
    {
        move(0, speed*dt);

        if(targetPosition.y <= getPosition().y)
        {
            setPosition(targetPosition);
        }
    }
}

NodeSprite::NodeSprite(Node& node)
{
    this->node = &node;
    active = false;

    texture.loadFromFile("images/nodesprite.png");
    setTexture(texture);
}

void NodeSprite::run()
{
    active = true;
}

void NodeSprite::reset()
{
    active = false;
    node->resetPath();

    setPosition(0, 0);
    targetPosition = getPosition();
}

void NodeSprite::update(float dt)
{
    if(active)
    {
        if(atTarget())
        {
            setTargetPosition();
        }
        else
        {
            controlMovement(dt);
        }
    }
}
