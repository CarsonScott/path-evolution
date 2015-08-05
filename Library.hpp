#ifndef LIBRARY_HPP_INCLUDED
#define LIBRARY_HPP_INCLUDED

#include <iostream>
#include <vector>

#include "Button.hpp"

enum Direction{Left, Right, Up, Down};
class Path: public std::vector<Direction>{};



#endif // LIBRARY_HPP_INCLUDED
