#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Library.hpp"

class Node
{
    Path path;
    int index;
public:
    Node(Path);
    Direction getCurrentPath();
    void resetPath();
    Node mutate();
};

#endif // NODE_HPP_INCLUDED
