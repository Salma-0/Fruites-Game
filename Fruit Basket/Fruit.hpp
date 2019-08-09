//
//  Fruit.hpp
//  Fruit Basket
//
//  Created by Salma on 12/8/18.
//  Copyright © 2018 Salma. All rights reserved.
//

#ifndef Fruit_hpp
#define Fruit_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Fruit{

private:
    
    sf::Texture texture;
    sf::Sprite sprite;
    const std::string FRUITS[6] = {"appleAsset.png", "orangeAsset.png", "frAsset.png", "graspAsset.png", "greenappleAsset.png", "chilli.png"};
    sf::Vector2f position;
    float fruitX;
    bool chilli = false;
    bool stopped = false;


public:
    
    void drop();
    Fruit();
    void resetFruit();
    sf::Sprite getFruitSprite();
    sf::Vector2f getPosition();
    void scale();
    bool isChilli();
    void setStop(bool);
    
    
    
};

#endif /* Fruit_hpp */
