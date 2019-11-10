#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "entity.h"


class projectile: public entity
{
public:
    float playermovementSpeed=2;
    float enemymovementSpeed=0.3;
    bool destroy= false;
    int counterLifetime=0;
    int lifeTime=400;
    int attackDamage = 1;




     projectile();
     void update();



};
#endif // PROJECTILE_H_INCLUDED
