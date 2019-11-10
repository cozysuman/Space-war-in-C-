#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include<cstring>
#include <functional>
#include <tgmath.h>
#include <deque>
#include <list>
#include <vector>
#include <unistd.h>

class entity
{
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    //sf::CircleShape circle;
    sf::Text text;
};



#endif // ENTITY_H_INCLUDED
