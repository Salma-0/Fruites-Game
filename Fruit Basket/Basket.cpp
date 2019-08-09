//
//  Basket.cpp
//  Fruit Basket
//
//  Created by Salma on 12/4/18.
//  Copyright © 2018 Salma. All rights reserved.
//

#include "Basket.hpp"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

Basket::Basket(sf::Sprite sprite){
    score = 0;
    basketSprite = sprite;
    sf::FloatRect basketRect = basketSprite.getLocalBounds();
    basketSprite.setOrigin(basketRect.left + basketRect.width/2.0f,
                           basketRect.top  + basketRect.height/2.0f);
    left = basketRect.left;
    top = basketRect.top;
    basketSprite.setPosition(sf::Vector2f(450, 450));
}



void Basket::moveToLeft(){
    int positionX = basketSprite.getPosition().x;
    if(positionX > 90){
        basketSprite.setPosition(positionX-10,  450);
        left -=10;
    }
}


void Basket::moveToRight(){
    int positionX = basketSprite.getPosition().x;
    if(positionX < 800){
        basketSprite.setPosition(positionX+20,  450);
        left +=20;
    }
}

sf::Sprite Basket::getSprite(){
    return basketSprite;
}

int Basket::getScore(){
    return score;
}

void Basket::addScore(){
    score += 1;
}

float Basket::getTop(){
    return top;
}

float Basket::getLeft(){
    return left;
}

