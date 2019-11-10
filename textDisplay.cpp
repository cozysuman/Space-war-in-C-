#include "textDisplay.h"
#include<iostream>
using namespace std;

textDisplay::textDisplay(){
    text.setPosition(300,300);
    text.setCharacterSize(50);
    text.setString("START");
}



void textDisplay::exit(){
    text.setCharacterSize(40);
    text.setPosition(300,400);
    text.setString("EXIT");


}


void textDisplay::gameOver(){
    text.setCharacterSize(40);
    text.setPosition(300,360);
    text.setString("GAME OVER");

}
void textDisplay::instructions(){
    text.setCharacterSize(40);
    text.setPosition(300,360);
    text.setString("INSTRUCTIONS");
}



