#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "entity.h"
#include "random.h"


class enemy: public entity
{
public:
    float movementSpeed=.15;
    int score=5;
    bool alive= true;
    int hp=2;
    bool isBlood = false;
    bool noMore=false;
    int bloodCounter = 0;
    int bloodLifetime = 400;
    int randomNumber;



     enemy();
     void update();
     void enemyMovement();


};


#endif // ENEMY_H_INCLUDED
