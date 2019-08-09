

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Basket.hpp"
#include <SFML/Window.hpp>
#include <vector>
#include "Fruit.hpp"
#include <unistd.h>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600

sf::Text scoreText;

void updateScore(int score){
    scoreText.setString("score: "+std::to_string(score));
}



int main(int, char const**)
{
    
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Fruit Basket", sf::Style::Close,settings);

    sf::Texture backgroundTexture, basketTexture;
    sf::Vector2u backgroundSize, windowSize;
    sf::Sprite backgroundSprite, basketSprite, fr1Sprite, fr2Sprite, fr3Sprite;
    sf::Font font;
    sf::SoundBuffer hitBuffer, gameOverBuffer;
    sf::Text gameOverText;
    
    Fruit fr1;
        
    fr1Sprite = fr1.getFruitSprite();
    
    
    if(!backgroundTexture.loadFromFile(resourcePath() + "background.png")){
        return EXIT_FAILURE;
    }
    
    if(!basketTexture.loadFromFile(resourcePath() + "basketAsset.png")){
        return EXIT_FAILURE;
    }
   
    if (!font.loadFromFile(resourcePath() + "KOMIKAP_.ttf")) {
        return EXIT_FAILURE;
    }
    if(!hitBuffer.loadFromFile(resourcePath() + "hit.ogg")){
        return EXIT_FAILURE;
    }
    if(!gameOverBuffer.loadFromFile(resourcePath() + "game_over.wav")){
        return EXIT_FAILURE;
    }
    
    sf::Sound hitSound, gameOverSound;
    hitSound.setBuffer(hitBuffer);

    gameOverSound.setBuffer(gameOverBuffer);
    
    /*to render the background image to fit in the window:
     1.we get the ratio between window size and texture size
     2.then use it to scale the texture
     */
    backgroundSize = backgroundTexture.getSize();
    windowSize = window.getSize();
    
    
    float scaleX = (float)windowSize.x / backgroundSize.x;
    float scaleY = (float)windowSize.y / backgroundSize.y;
    
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.scale(scaleX, scaleY);
    
    //set the sprite of the basket and initilize a basket
    basketSprite.setTexture(basketTexture);
    Basket basket(basketSprite);
   
    
    //std::cout << "basket top: " << basketRect.top << "\nbasket left: " << basketRect.left;
    
    
    
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setString("score: ");
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(60, 540);
    
    
    gameOverText.setFont(font);
    gameOverText.setString("");
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setCharacterSize(50);
    gameOverText.setPosition(300, 300);
    
    
    
    // Start the game loop
    while (window.isOpen())
    {
     
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
               window.close();
            }

        }
        
        //handle left arrow press
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
            basket.moveToLeft();
        }
        
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
            basket.moveToRight();
        }
        
        fr1.drop();
        
        sf::FloatRect basketRect = basket.getSprite().getGlobalBounds();
        if(basketRect.intersects(fr1.getFruitSprite().getGlobalBounds())){
            //collision
            if(fr1.getPosition().y >= 378){
            if(!fr1.isChilli()){
            hitSound.play();
            basket.addScore();
            updateScore(basket.getScore());
            }else{
                //game over
                gameOverSound.play();
                fr1.setStop(true);
                gameOverText.setString("GAME OVER!");
                
            }
        }
        }
        
        
        //printBounds(basketRect);


        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(backgroundSprite);
        window.draw(fr1.getFruitSprite());
        window.draw(basket.getSprite());
        window.draw(scoreText);
        window.draw(gameOverText);
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
 }




