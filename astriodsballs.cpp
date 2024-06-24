#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <array>


using std :: endl;
using std :: cout;
using std :: string;
using std :: ifstream;
using std :: array;


using namespace sf;
using namespace std;



int main (int argc, char **argv){
    
    sf::RenderWindow Window (sf::VideoMode(2024, 1000), "Sfml Window");
    
    sf::CircleShape bullet(10.f); //this creates a circle with a radius of 10
    bullet.setFillColor(sf::Color::White); // this paints the circle white
    bullet.getGlobalBounds(); // this gets the circles surrounding area
    bullet.setPosition(500,900); //this sets the bullets position
    
    
    //you need to make the bullet stay on top of you player1 and follow your player everywhere
    //cant I just say that the postions of the bullet is the same as the player??
    
    sf::RectangleShape player1(sf::Vector2f(100.f, 50.f));
    player1.setFillColor(sf::Color::Yellow);
    player1.getGlobalBounds();
    
    int position_x {}; //this is the x direction of the player1
    int Position_y {};// this is the y direction of the player1
    player1.setPosition(500, 900); // this sets the position of player1
    int delta_x = 10; // this causes the player one to move left to right
    int delta_y = 3;// this causes the player to move up and down
   
    //window
    sf::RectangleShape window(sf::Vector2f(9520.f, 50.f));
    window.setFillColor(sf::Color::White);
    window.getGlobalBounds();
    int posbox_x {};
    int posbox_y {};
    window.setPosition(0, 1250);
    
    
    //font for game over screen
    sf::Font font;
    
    if(!font.loadFromFile("/System/Library/Fonts/NewYork.ttf")){
        std:: cout << "Error Loading File" << std:: endl;
        system("pause");
    }
    
   //game over sprite
    sf::Text gameOver;
    gameOver.setCharacterSize(60);
    gameOver.setFillColor(sf::Color::Red);
    gameOver.setString("GAME OVER!");
    gameOver.setFont(font);
    
     int shootTime = 0;
    
    //arrays of balls
    std :: array < sf::CircleShape, 10 > Enemy; // this is an array of ten enemys
    
    
    //this is drawing my Enemys psotions and colors and sizes so dont unfold :))
    for (size_t idx = 0; idx < 10; idx++) {
        
        //the Enemys reset if they go off screen on the y direction
        
        
        //Enemy color and sizes
        Enemy[0].setFillColor(sf::Color::Red);
        Enemy[0].setRadius(50.f);
        
        Enemy[1].setFillColor(sf::Color::Magenta);
        Enemy[1].setRadius(80.f);
        
        Enemy[2].setFillColor(sf::Color::Blue);
        Enemy[2].setRadius(75.f);
        
        Enemy[3].setFillColor(sf::Color::Yellow);
        Enemy[3].setRadius(20.f);
        
        Enemy[4].setFillColor(sf::Color::Green);
        Enemy[4].setRadius(90.f);
        
        Enemy[5].setFillColor(sf::Color::Cyan);
        Enemy[5].setRadius(30.f);
        
        
        Enemy[6].setFillColor(sf::Color::White);
        Enemy[6].setRadius(65.f);
        
        Enemy[7].setFillColor(sf::Color::Yellow);
        Enemy[7].setRadius(79.f);
        
        Enemy[8].setFillColor(sf::Color::Red);
        Enemy[8].setRadius(53.f);
        
        Enemy[9].setFillColor(sf::Color::Cyan);
        Enemy[9].setRadius(47.f);
        
        //Enemy postions
         Enemy[0].setPosition(1700.f, -100.f);
         Enemy[1].setPosition(1600.f, -700.f);
         Enemy[2].setPosition(1200.f, -500.f);
         Enemy[3].setPosition(800.f, -900.f);
         Enemy[4].setPosition(400.f, -700.f);
         Enemy[5].setPosition(900.f, -200.f);
         Enemy[6].setPosition(100.f, -800.f);
         Enemy[7].setPosition(800.f, -500.f);
         Enemy[8].setPosition(900.f, -700.f);
         Enemy[9].setPosition(300.f, -300.f);
        
    }
        
    //this opens my window
    while (Window.isOpen())// this opens the window
    {
        
        Event event;
        
        while (Window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                Window.close();
            }
        }
       
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
           // this is an if statement for the bullet to move
           sf::Vector2f coor = player1.getPosition();
           if (coor.x >= 0+5.f){//prevents player1 from going off to the left
               player1.move(-10.f,0.f);
               bullet.move(-10.f,0.f);
            }
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
           sf::Vector2f coor = player1.getPosition();
            if (coor.x < 1920.f){
               player1.move(10.f,0.f);
                bullet.move(10.f,0.f);
                
           }
                  
       }
       
    //if the key is pressed the information inside proceeds
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTime >= 3){
            sf::Vector2f shoot = bullet.getPosition();
            if (shoot.y > 0.f+5.f) {
                bullet.move(0.f,-10.f); // fix this to flow not just every click
                
            }//ihatethisclass:)
            shootTime = 0;
        }
        
        //will always go up to three then shoot
        if (shootTime  < 3)
        {  shootTime++;}//dosent work
        
        
        
            //collisons this is long so just dont unfold :))))
        
                for (size_t idx = 0; idx < Enemy.size(); idx++)
                {
                
                    if (bullet.getGlobalBounds().intersects(Enemy[idx].getGlobalBounds()))
                    {
                        
                       Enemy[idx].setPosition(-3000, 3000); // i want to delete a sprite not change its position
                        
                        bullet.setPosition(player1.getPosition()); //sets the bullet at the position of the rectangle if the bullet and enemy collide
                        
                    }
                    //ik this is alot of code but thats the only route I could think to take so yeah
                    
                    if (window.getGlobalBounds().intersects(Enemy[0].getGlobalBounds()))
                        {
                            std::cout << "Crashhh" << std::endl; //checks if balls crash into lower window(not exact but close enough)
                            Enemy[0].setPosition(1700.f, -100.f);
                             
                    }
                    if (window.getGlobalBounds().intersects(Enemy[1].getGlobalBounds()))
                        {
                            
                            Enemy[1].setPosition(1600.f, -700.f);
                    
                        }
                    
                    if (window.getGlobalBounds().intersects(Enemy[2].getGlobalBounds()))
                        {
                            
                            Enemy[2].setPosition(1200.f, -500.f);
                    
                        }
                    
                    
               //reloads sprites to orignal postion everytime they go out the window
        if (window.getGlobalBounds().intersects(Enemy[3].getGlobalBounds()))
            {
                Enemy[3].setPosition(800.f, -900.f);
            }
        if (window.getGlobalBounds().intersects(Enemy[4].getGlobalBounds()))
            {
                Enemy[4].setPosition(400.f, -700.f);
            }
        if (window.getGlobalBounds().intersects(Enemy[5].getGlobalBounds()))
            {
                Enemy[5].setPosition(900.f, -200.f);
            }
        if (window.getGlobalBounds().intersects(Enemy[6].getGlobalBounds()))
            {
                Enemy[6].setPosition(100.f, -800.f);
            }
        if (window.getGlobalBounds().intersects(Enemy[7].getGlobalBounds()))
            {
                Enemy[7].setPosition(800.f, -500.f);
            }
        if (window.getGlobalBounds().intersects(Enemy[8].getGlobalBounds()))
            {
                Enemy[8].setPosition(900.f, -700.f);
            }
        if (window.getGlobalBounds().intersects(Enemy[9].getGlobalBounds()))
            {
                Enemy[9].setPosition(300.f, -300.f);
            }
                }
        
        
                //if the enemys go off screen on y axis i think they should reset to there orignal position
                
        //causes the Enemy arrays to move at a certain speed
           Enemy[0].move(0.f,3.f);
           Enemy[1].move(0.f,2.f);
           Enemy[2].move(0.f,1.f);
           Enemy[3].move(0.f,4.f);
           Enemy[4].move(0.f,5.f);
           Enemy[5].move(0.f,1.f);
           Enemy[6].move(0.f,2.f);
           Enemy[7].move(0.f,1.f);
           Enemy[8].move(0.f,3.f);
           Enemy[9].move(0.f,1.f);
        
    //set the postion of the enemys of screen from the top and let them fall, once they go past the bottom line then they should reapear in the same position again and do it over and over untill they all dead.
        
        Window.clear();
        
    
        for (size_t idx = 0; idx < 10; idx++)
        {  // will draw the balls on the window
            Window.draw(Enemy[idx]);
            
        }
        
        for (size_t idx =0; idx < Enemy.size(); idx++){
            
        if (player1.getGlobalBounds().intersects(Enemy[idx].getGlobalBounds())){
            
            
            Window.draw(gameOver);
            sleep(seconds(3));
            Window.close();
            //freeze the screen and display game overrr
            //window should pause
        }
            }
        
       
        
      //will draw the bullet and player1
    Window.draw(bullet);
    Window.draw (player1);
        Window.draw(window);
    Window.display();
    sf::sleep(sf::milliseconds(10));
    
    
    }
    return 0;

}
    
