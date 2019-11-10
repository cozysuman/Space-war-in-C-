
//headers
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<algorithm>
#include <sstream>
#include<fstream>
#include<iterator>
#include "player.h"
#include "entity.h"
#include "projectile.h"
#include "enemy.h"
#include "projectileEnemy.h"
#include "random.h"
#include "textDisplay.h"
#include<windows.h>

using namespace std;
string toString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}





//start of main 1 window
int gamewindow()

{
    int counter=0;
    int counter2=0;
    int counter3=0;
    int randomNumber=0;
    bool check=true;
    bool check2=true;
    int score=0;
    bool go=false;
    int score1=0;
    bool restart=false;


    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
    sf::Clock clock5;
    sf::Clock clock6;


    sf::RenderWindow win(sf::VideoMode(800, 700),"SPACE WAR");


    //draw text for press new game to play again
         sf::Font fonttry;
    if (!fonttry.loadFromFile("resources/playbill.ttf")) {
        return 0;
    }
    sf::Text texttry("PRESS 'N' TO PLAY AGAIN",fonttry, 40);
    texttry.setColor(sf::Color::Yellow);
    texttry.setPosition(50,500);
//draw text for press esc to exit form the game
         sf::Font fontexit;
    if (!fontexit.loadFromFile("resources/playbill.ttf")) {
        return 0;
    }
    sf::Text textexit("PRESS 'ESC' TO EXIT",fontexit, 40);
    textexit.setColor(sf::Color::Blue);
    textexit.setPosition(50,600);




 // sprite for player
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("resources/playership.png")) {
        cout<<"the texture cannnot be loaded"<<endl;
        return 0;
    }
    sf::Sprite spritePlayer(texturePlayer);


    // sprite for enemy1
    sf::Texture textureEnemy;
    if (!textureEnemy.loadFromFile("resources/enemyspaceship1.png")) {
            cout<<"the texture cannnot be loaded"<<endl;
        return 0;
    }
    sf::Sprite spriteEnemy(textureEnemy);

        // sprite for enemy2
    sf::Texture textureEnemy2;
    if (!textureEnemy2.loadFromFile("resources/enemyShip2.png")) {
        cout<<"the texture cannnot be loaded"<<endl;
        return 0;
    }
    sf::Sprite spriteEnemy2(textureEnemy2);


    //sprite for background
    sf::Texture textureBackground;
   if (!textureBackground.loadFromFile("resources/space1.jpg")) {
       return 0;
    }
    sf::Sprite spriteBackground(textureBackground);


    //player bullet
    sf::Texture textureBullet;
   if (!textureBullet.loadFromFile("resources/rocket.png")) {
       return 0;
    }
    sf::Sprite spriteBullet(textureBullet);


    //enemy bullet
        sf::Texture textureBullet1;
   if (!textureBullet1.loadFromFile("resources/enemyBullet1.png")) {
       return 0;
    }
    sf::Sprite spriteBullet1(textureBullet1);

        //enemy bullet
        sf::Texture textureBullet11;
   if (!textureBullet11.loadFromFile("resources/greenBullet22.png")) {
       return 0;
    }
    sf::Sprite spriteBullet11(textureBullet11);

        //collision sprite
    sf::Texture collision;
   if (!collision.loadFromFile("resources/bang.png")) {
       return 0;
    }
    sf::Sprite spriteCollision(collision);


        // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("resources/castellar.ttf")) {
        return 0;
    }
    sf::Text text("",font, 25);
    text.setColor(sf::Color::Yellow);
    text.setPosition(0, 12);



        sf::Font font1;
    if (!font1.loadFromFile("resources/castellar.ttf")) {
        return 0;
    }
    sf::Text text2("GAME OVER",font1, 50);
    text2.setColor(sf::Color::Red);
    text2.setPosition(400, win.getSize().y/2);





    sf::SoundBuffer playerShot;
    if(!playerShot.loadFromFile("resources/bulletsound.ogg")){
       return 0;
       }
    sf::Sound soundShot;
    soundShot.setBuffer(playerShot);

        sf::SoundBuffer enemyShot;
    if(!enemyShot.loadFromFile("resources/shoot.wav")){
       return 0;
       }
    sf::Sound soundShot1;
    soundShot1.setBuffer(enemyShot);

        sf::SoundBuffer explosion;
    if(!explosion.loadFromFile("resources/Explosion.wav")){
       return 0;
       }
    sf::Sound soundExplosion;
    soundExplosion.setBuffer(explosion);

     //Play the music
     // Change some parameters
     // music.setPosition(0, 1, 10); // change its 3D position
    //music.setPitch(2);           // increase the pitch
    // music.setVolume(100);         // reduce the volume
     //music.setLoop(true);         // make it loop
    //music.play();




//    player vector array
    vector<player>::const_iterator iter2;
    vector<player> playerArray;

    class player player1;
    player1.sprite.setTexture(texturePlayer);
    playerArray.push_back(player1);


    //projectile vector array for player
    vector<projectile>::const_iterator iter;
    vector<projectile> projectileArray;
    class projectile projectile1;
    projectile1.sprite.setTexture(textureBullet);

        //projectile vector array for enemy1
    vector<projectileEnemy>::const_iterator iter1;
    vector<projectileEnemy> enemyArray;
    class projectileEnemy projectile2;
    projectile2.sprite.setTexture(textureBullet1);


            //projectile vector array for enemy2
    vector<projectileEnemy>::const_iterator iter13;
    vector<projectileEnemy> enemyArray3;
    class projectileEnemy projectile3;
    projectile3.sprite.setTexture(textureBullet11);


    // Enemy Vector Array
    vector<enemy>::const_iterator iter4;
    vector<enemy> enemyArray1;

    vector<enemy>::const_iterator iter10;
    vector<enemy> enemyArray2;

        // Enemy Object
    class enemy enemy1,enemy2;
    enemy1.sprite.setTexture(textureEnemy);
    enemyArray1.push_back(enemy1);
    enemy2.sprite.setTexture(textureEnemy2);
    enemyArray2.push_back(enemy2);

        // collision Vector Array
    vector<enemy>::const_iterator iter20;
    vector<enemy> bloodArray;

        // Blood Object
    class enemy blood1;
    blood1.isBlood = true;
    blood1.sprite.setTexture(collision);



        //text vector array
    vector<textDisplay>::iterator iter100;
    vector<textDisplay> textArray;
    class textDisplay text1;
    text1.text.setFont(font);
    text1.text.setCharacterSize(30);


    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                win.close();

            }
        }



        win.clear();




        // Clock
        sf::Time elapsed1 = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();
        sf::Time elapsed4 = clock4.getElapsedTime();
        sf::Time elapsed5 = clock5.getElapsedTime();
        sf::Time elapsed6 = clock6.getElapsedTime();


                //player Projectile Collides with Enemy1
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter4 = enemyArray1.begin(); iter4 != enemyArray1.end(); iter4++)
            {
                if (projectileArray[counter].sprite.getGlobalBounds().intersects(enemyArray1[counter2].sprite.getGlobalBounds()))
                {
                    projectileArray[counter].destroy = true;

                    enemyArray1[counter2].hp -= projectileArray[counter].attackDamage;
                    if (enemyArray1[counter2].hp <= 0)
                    {
                        enemyArray1[counter2].alive = false;
                    }
                }

                counter2++;
            }

            counter++;
        }







        // Delete Dead Enemy1
        counter = 0;
        for (iter4 = enemyArray1.begin(); iter4 != enemyArray1.end(); iter4++)
        {
            if (enemyArray1[counter].alive == false||enemyArray1[counter].noMore == true)
            {
        // Create Enemy Blood Stain
        if (enemyArray1[counter].alive == false){
                blood1.rect.setPosition(enemyArray1[counter].sprite.getPosition());
                bloodArray.push_back(blood1);
                soundExplosion.setVolume(50);
                soundExplosion.play();
                score+=5;
                }
                enemyArray1.erase(enemyArray1.begin()+counter);
                check=false;
                if (enemyArray1[counter].noMore == true)
                playerArray[counter].hp -=1;  //TO REDUCE THE HEALTH BY 1 WHEN ENEMY GOES DOWN
                clock5.restart();
                break;
            }
            counter++;
        }



                        //player Projectile Collides with Enemy2
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter10 = enemyArray2.begin(); iter10 != enemyArray2.end(); iter10++)
            {
                if (projectileArray[counter].sprite.getGlobalBounds().intersects(enemyArray2[counter2].sprite.getGlobalBounds()))
                {
                    projectileArray[counter].destroy = true;

                    enemyArray2[counter2].hp -= projectileArray[counter].attackDamage;
                    if (enemyArray2[counter2].hp <= 0)
                    {
                        enemyArray2[counter2].alive = false;
                    }
                }

                counter2++;
            }

            counter++;
        }


        // Delete Dead Enemy2
        counter = 0;
        for (iter10 = enemyArray2.begin(); iter10 != enemyArray2.end(); iter10++)
        {
            if (enemyArray2[counter].alive == false||enemyArray2[counter].noMore == true)
            {
        // Create Enemy2 Blood Stain
        if (enemyArray2[counter].alive == false){
                blood1.rect.setPosition(enemyArray2[counter].sprite.getPosition());
                bloodArray.push_back(blood1);
                soundExplosion.setVolume(50);
                soundExplosion.play();
                score+=5;
                }
                check2=false;
                enemyArray2.erase(enemyArray2.begin()+counter);
                if (enemyArray2[counter].noMore == true)
                playerArray[counter].hp -=1;
                clock5.restart();
                break;
            }
            counter++;
        }










        //enemy1 Projectile Collides with player
        counter = 0;
        for (iter1 = enemyArray.begin(); iter1 != enemyArray.end(); iter1++)
        {
            counter2 = 0;
            for (iter2 = playerArray.begin(); iter2 != playerArray.end(); iter2++)
            {
                if (enemyArray[counter].sprite.getGlobalBounds().intersects(playerArray[counter2].sprite.getGlobalBounds()))
                {
                    enemyArray[counter].destroy = true;

                    playerArray[counter2].hp -= enemyArray[counter].attackDamage;
                    if (playerArray[counter2].hp <= 0)
                    {
                        playerArray[counter2].alive = false;
                    }
                }

                counter2++;
            }

            counter++;
        }


                //enemy2 Projectile Collides with player
        counter = 0;
        for (iter13 = enemyArray3.begin(); iter13!= enemyArray3.end(); iter13++)
        {
            counter2 = 0;
            for (iter2 = playerArray.begin(); iter2 != playerArray.end(); iter2++)
            {
                if (enemyArray3[counter].sprite.getGlobalBounds().intersects(playerArray[counter2].sprite.getGlobalBounds()))
                {
                    enemyArray3[counter].destroy = true;

                    playerArray[counter2].hp -= enemyArray[counter].attackDamage;
                    if (playerArray[counter2].hp <= 0)
                    {
                        playerArray[counter2].alive = false;
                    }
                }

                counter2++;
            }

            counter++;
        }





        // Delete Dead player
        counter = 0;
        for (iter2 = playerArray.begin(); iter2 != playerArray.end(); iter2++)
        {
            if (playerArray[counter].alive == false||playerArray[counter].hp==0)
            {
                blood1.rect.setPosition(playerArray[counter].sprite.getPosition());
                bloodArray.push_back(blood1);
                soundExplosion.setVolume(50);
                soundExplosion.play();
                playerArray.erase(playerArray.begin()+counter);
                textArray.push_back(text1);
                restart=true;


                break;
            }

            counter++;


        }


                        // Delete Projectile of player
       counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if (projectileArray[counter].destroy == true)
            {
                projectileArray.erase(projectileArray.begin()+counter);
                break;
            }

            counter++;
        }

                       // Delete Projectile of enemy1
       counter = 0;
        for (iter1 = enemyArray.begin(); iter1 != enemyArray.end(); iter1++)
        {
            if (enemyArray[counter].destroy == true)
            {
                enemyArray.erase(enemyArray.begin()+counter);
                break;
            }

            counter++;
        }

                               // Delete Projectile of enemy2
       counter = 0;
        for (iter13 = enemyArray3.begin(); iter13 != enemyArray3.end(); iter13++)
        {
            if (enemyArray3[counter].destroy == true)
            {
                enemyArray3.erase(enemyArray3.begin()+counter);
               // go=false;
               // check2=false;
                break;
            }

            counter++;
        }


                // Delete Enemy Blood Stain
        counter = 0;
        for (iter20 = bloodArray.begin(); iter20 != bloodArray.end(); iter20++)
        {
            if (bloodArray[counter].alive == false)
            {
                bloodArray.erase(bloodArray.begin()+counter);
                break;
            }

            counter++;
        }





        //draw background
       win.draw(spriteBackground);

        //enemy1 appear randomly
          if (enemyArray1[counter].alive == false||enemyArray1[counter].noMore == true){
                 if (elapsed5.asSeconds() >= 4)
        {
           clock5.restart();
           check=true;
        enemy1.rect.setPosition(generateRandom(win.getSize().x-100),0);
        enemyArray1.push_back(enemy1);
        }
        }

                //enemy2 appear randomly
          if (enemyArray2[counter].alive == false||enemyArray2[counter].noMore == true){
                 if (elapsed6.asSeconds() >= 5)
        {
           clock6.restart();
           check2=true;
        enemy2.rect.setPosition(generateRandom(win.getSize().x-100),0);
        enemyArray2.push_back(enemy2);
        }}


                  //fires missiles by enemy1
                if (elapsed2.asSeconds() >= 1.5)
        {
           clock2.restart();
          projectile2.sprite.setPosition(enemyArray1[counter].rect.getPosition().x+enemyArray1[counter].rect.getSize().x/2-10,enemyArray1[counter].rect.getPosition().y+enemyArray1[counter].rect.getSize().y/2);
                 if(check==true){
                soundShot1.setVolume(10);
                soundShot1.play();
          enemyArray.push_back(projectile2);
          }}





            //fires missiles by enemy2

                if (elapsed4.asSeconds() >= 1.5)
        {
           clock4.restart();
          projectile3.sprite.setPosition(enemyArray2[counter].rect.getPosition().x+enemyArray2[counter].rect.getSize().x/2-10,enemyArray2[counter].rect.getPosition().y+enemyArray2[counter].rect.getSize().y/2);
          if(go==true &&check2==true){
                soundShot1.setVolume(12);
                soundShot1.play();
          enemyArray3.push_back(projectile3);
          }
        }






        // Fires Missile by player (Space bar)
        if (elapsed1.asSeconds() >= 0.15)
        {
            clock.restart();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
             soundShot.setVolume(10);
             soundShot.play();

          projectile1.sprite.setPosition(playerArray[counter].rect.getPosition().x+playerArray[counter].rect.getSize().x/2.3,playerArray[counter].rect.getPosition().y+playerArray[counter].rect.getSize().y/1.9);
          projectileArray.push_back(projectile1);
        }}




                        // Draw projectiles for enemy1
        counter = 0;
        for (iter1 = enemyArray.begin(); iter1 != enemyArray.end(); iter1++)
        {
            enemyArray[counter].update();
            win.draw(enemyArray[counter].sprite);
            counter++;
        }


                                // Draw projectiles for enemy2
        counter = 0;
        for (iter13 = enemyArray3.begin(); iter13 != enemyArray3.end(); iter13++)
        {
            enemyArray3[counter].update();
            win.draw(enemyArray3[counter].sprite);
            counter++;
        }



                // Draw  player
        counter = 0;
        for (iter2 = playerArray.begin(); iter2 != playerArray.end(); iter2++)
        {
            playerArray[counter].update();
            playerArray[counter].playerMovement();
            win.draw(playerArray[counter].sprite);


            counter++;
        }


                // Draw Projectiles for player
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            projectileArray[counter].update();
            win.draw(projectileArray[counter].sprite);


            counter++;
        }

       // Draw Enemy1
        counter = 0;
        for (iter4 = enemyArray1.begin(); iter4 != enemyArray1.end(); iter4++)
        {
            enemyArray1[counter].update();
            enemyArray1[counter].enemyMovement();
            win.draw(enemyArray1[counter].sprite);
            counter++;
        }




                // Draw Enemy2
                counter = 0;
      if (elapsed3.asSeconds() >=7)
       {
        go=true;
        for (iter10 = enemyArray2.begin(); iter10 != enemyArray2.end(); iter10++)
        {
            enemyArray2[counter].update();
            enemyArray2[counter].enemyMovement();
            win.draw(enemyArray2[counter].sprite);
            counter++;
        }
                }



                // Draw Enemy Dead Blood
        counter = 0;
        for (iter20 = bloodArray.begin(); iter20 != bloodArray.end(); iter20++)
        {
            bloodArray[counter].update();
            win.draw(bloodArray[counter].sprite);

            counter++;
        }

        //draw text
                counter = 0;
        for (iter100 = textArray.begin(); iter100 != textArray.end(); iter100++)
        {
            textArray[counter].gameOver();
            win.draw(textArray[counter].text);
            win.draw(texttry);//press N new game to continue for
            win.draw(textexit);//press esc to exit

        }





//updating score

ifstream infile("score.txt");
       infile>>score1;
       if(score>=score1){
       ofstream outfile("score.txt");
       outfile<<score;
       score1=score;
       }



       //
        counter=0;
        for (iter2 = playerArray.begin(); iter2 != playerArray.end(); iter2++)
        {
        text.setString("SCORE: "+ toString(score)+"\t\t\t\t\t\t\t\t\t\t\t\t\tHigh Score:"+toString(score1)+"\nHEALTH: "+ toString(playerArray[counter].hp));
        win.draw(text);

        counter++;
        }



        if(restart==true)
            {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
        win.close();
        gamewindow();
        //win.close();
        }
        }


        win.display();
    }

    //return 0;
}//END OF GAME  WINDOW FOR PLAYING GAME



//instructions window
int instructions(){
    sf::RenderWindow win(sf::VideoMode(800, 700),"SPACE WAR");
    sf::Texture backgroundInstuctions;
   if (!backgroundInstuctions.loadFromFile("resources/backgroundInstructions.jpg")) {
    return 0;
    }
    sf::Sprite spriteBackgroundInstructions(backgroundInstuctions);
            while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                win.close();
            }
        }
        win.clear();
        win.draw(spriteBackgroundInstructions);
        win.display();
    }
}

//START DEFAULT MAIN WINDOW
int main(){
    int counter;
    bool display=true;
    sf::RenderWindow win(sf::VideoMode(800, 700),"SPACE WAR");


    sf::Texture mainBackground;
    if (!mainBackground.loadFromFile("resources/Star_Wars_1(try).jpg")) {
        return 0;
    }
    sf::Sprite spriteMainBackground(mainBackground);


        sf::Music music;
    if (!music.openFromFile("resources/backgroundMusic1.ogg")) {
        return EXIT_FAILURE;
    }



// loading font for space war
        sf::Font font;
    if (!font.loadFromFile("resources/font.ttf")) {
        return 0;
    }
    sf::Text text("SPACE WAR",font, 70);
    text.setColor(sf::Color::Yellow);
    text.setPosition(200,200);






            //text vector array for start menu
    vector<textDisplay>::const_iterator iterstart;
    vector<textDisplay> textArraystart;
    class textDisplay textstart;
    textstart.text.setFont(font);
    textArraystart.push_back(textstart);


     //text vector array for instructions menu
    vector<textDisplay>::const_iterator iterInstructions;
    vector<textDisplay> textArrayInstructions;
    class textDisplay textInstructions;
    textInstructions.text.setFont(font);
    textArrayInstructions.push_back(textInstructions);

//text vector array for exit menu
        vector<textDisplay>::const_iterator iter2000;
    vector<textDisplay> textArray2000;
    class textDisplay text2000;
    text2000.text.setFont(font);
    textArray2000.push_back(text2000);


    //play music
            music.setLoop(true);
            music.play();



//for opening the window
        while (win.isOpen())
    {
        sf::Event event;

        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                win.close();

            }
        }



        win.clear();





//FOR START (CLOSING THE PRESENT WINDOW AND RUNNING THE GAME WINDOW)
//for loading the text array for start
            counter = 0;
        for (iterstart = textArraystart.begin(); iterstart != textArraystart.end(); iterstart++)
        {
                if (textArraystart[counter].text.getGlobalBounds().contains(sf::Mouse::getPosition(win).x,sf::Mouse::getPosition(win).y))
                {
                    textArraystart[counter].text.setStyle(sf::Text::Bold);
                    textArraystart[counter].text.setColor(sf::Color::Green);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                             {
                                 win.close();
                               gamewindow();

                             }

                }
                else
                textArraystart[counter].text.setColor(sf::Color::Red);
            counter++;
        }





//FOR EXIT
                    counter = 0;
        for (iter2000 = textArray2000.begin(); iter2000 != textArray2000.end(); iter2000++)
        {
                if (textArray2000[counter].text.getGlobalBounds().contains(sf::Mouse::getPosition(win).x,sf::Mouse::getPosition(win).y))
                {
                    textArray2000[counter].text.setStyle(sf::Text::Bold);
                    textArray2000[counter].text.setCharacterSize(50);
                    textArray2000[counter].text.setColor(sf::Color::Green);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                             {
                               win.close();
                            }
                }
                else
                textArray2000[counter].text.setColor(sf::Color::Red);
            counter++;
        }

//for instructions
                 counter = 0;
        for (iterInstructions = textArrayInstructions.begin(); iterInstructions != textArrayInstructions.end(); iterInstructions++){
                 if (textArrayInstructions[counter].text.getGlobalBounds().contains(sf::Mouse::getPosition(win).x,sf::Mouse::getPosition(win).y))
                {
                    textArrayInstructions[counter].text.setStyle(sf::Text::Bold);
                    textArrayInstructions[counter].text.setCharacterSize(50);
                    textArrayInstructions[counter].text.setColor(sf::Color::Green);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                             {
                               instructions();
                             }}
                else
                textArrayInstructions[counter].text.setColor(sf::Color::Red);
            counter++;
        }


        win.draw(spriteMainBackground);




                //draw start text
               int counter = 0;
        for (iterstart = textArraystart.begin(); iterstart != textArraystart.end(); iterstart++)
        {
            win.draw(textArraystart[counter].text);
            counter++;
        }



        //FOR INSTRUCTION TO DRAW



                        //draw exit text
               counter = 0;
        for (iter2000 = textArray2000.begin(); iter2000 != textArray2000.end(); iter2000++)
        {
            textArray2000[counter].exit();
            win.draw(textArray2000[counter].text);
            counter++;
        }



                        //draw instructions text
               counter = 0;
        for (iterInstructions = textArrayInstructions.begin(); iterInstructions != textArrayInstructions.end(); iterInstructions++)
        {
            textArrayInstructions[counter].instructions();
            win.draw(textArrayInstructions[counter].text);
            counter++;
        }



               win.draw(text);
               win.display();


    }
return 0;
}

