#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"

class player: public entity
{
public:
    float movementSpeed=.3;
    int score=5;
    bool alive= true;
    int hp=3;


     player();
     void update();
     void playerMovement();

};


#endif // PLAYER_H_INCLUDED
