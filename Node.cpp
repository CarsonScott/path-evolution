#include "Node.hpp"

Node::Node(Path path)
{
    this->path = path;
    index = 0;
}

Direction Node::getCurrentPath()
{
    Direction currentPath = path[index];

    if(index == path.size() - 1)
    {
        index = 0;
    }
    else
    {
        index ++;
    }

    return currentPath;
}

void Node::resetPath()
{
    index = 0;
}

Node Node::mutate()
{
    Path newPath = path;

    srand(time(NULL));
    int mutation = rand() % 100 + 1;

    if(mutation % 2 == 0)
    {
        if(mutation <= 25)
        {
            newPath.push_back(Left);
        }
        else if(mutation <= 50)
        {
            newPath.push_back(Right);
        }
        else if(mutation <= 75)
        {
            newPath.push_back(Up);
        }
        else if(mutation <= 100)
        {
            newPath.push_back(Down);
        }
    }
    else
    {
        if(mutation <= 25)
        {
            newPath.push_back(Left);
        }
        else if(mutation <= 50)
        {
            newPath.push_back(Right);
        }
        else if(mutation <= 75)
        {
            newPath.push_back(Up);
        }
        else if(mutation <= 100)
        {
            newPath.push_back(Down);
        }
    }

    if(mutation < newPath.size())
    {
        int mutation = rand() % 4;
        Direction direction = Direction(mutation);
        newPath.assign(mutation, direction);
    }

    Node node(newPath);
    return node;
}
