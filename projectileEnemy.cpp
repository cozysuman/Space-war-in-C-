#include "projectileEnemy.h"

projectileEnemy::projectileEnemy(){

     rect.setSize(sf::Vector2f(5,5));
     rect.setFillColor(sf::Color::Green);
     rect.setPosition(44,44);
}
void projectileEnemy::update(){
      sprite.move(0,playermovementSpeed);
          counterLifetime++;
    if (counterLifetime >= lifeTime)
    {
        destroy = true;
    }

      }





