#include "player.h"
#include<iostream>
using namespace std;

player::player(){

     rect.setSize(sf::Vector2f(50,50));
     rect.setFillColor(sf::Color::White);
     rect.setPosition(650,550);
}
  void player::update(){
      sprite.setPosition(rect.getPosition());
      }


void player::playerMovement(){
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(rect.getPosition().x>=-20)
    rect.move(-movementSpeed,0);
    }
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(rect.getPosition().x<=750)
        rect.move(movementSpeed,0);
    }
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(rect.getPosition().y>=-25)
        rect.move(0,-movementSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(rect.getPosition().y<=650)
        rect.move(0,movementSpeed);
    }
 }


