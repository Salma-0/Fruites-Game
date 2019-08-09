//
//  Basket.hpp
//  Fruit Basket
//
//  Created by Salma on 12/4/18.
//  Copyright © 2018 Salma. All rights reserved.
//

#ifndef Basket_hpp
#define Basket_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Basket{
    
private:
    int score = 0;
    float positionX = 450;
    sf::Sprite basketSprite;
    float left;
    float top;
    
    
public:
    Basket(sf::Sprite);
    void moveToLeft();
    void moveToRight();
    int getScore();
    void addScore();
    float getPositionX();
    sf::Sprite getSprite();
    float getTop();
    float getLeft();
    
    
    
    
};

#endif /* Basket_hpp */
