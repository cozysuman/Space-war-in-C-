#ifndef PROJECTILEENEMY_H_INCLUDED
#define PROJECTILEENEMY_H_INCLUDED

#include "entity.h"


class projectileEnemy: public entity
{
public:
    float playermovementSpeed=2;
    float enemymovementSpeed=0.3;
    bool destroy= false;
    int counterLifetime=0;
    int lifeTime=400;
    int attackDamage = 1;




     projectileEnemy();
     void update();

};


#endif // PROJECTILEENEMY_H_INCLUDED
