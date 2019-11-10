#include "enemy.h"

enemy::enemy(){

     rect.setSize(sf::Vector2f(50,50));
     rect.setFillColor(sf::Color::White);
     rect.setPosition(600,0);
}
void enemy::update(){
    sprite.setPosition(rect.getPosition());
          if (isBlood == true)
    {
        bloodCounter++;

        if (bloodCounter >= bloodLifetime)
        {
            alive = false;
        }
    }
      }




void enemy::enemyMovement(){

//if(rect.getPosition().y<=700)
rect.move(0,movementSpeed);
if(rect.getPosition().y>800)
    noMore=true;

}

