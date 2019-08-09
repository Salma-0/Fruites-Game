//
//  Fruit.cpp
//  Fruit Basket
//
//  Created by Salma on 12/8/18.
//  Copyright © 2018 Salma. All rights reserved.
//

#include "Fruit.hpp"
#include "ResourcePath.hpp"
#include <unistd.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



Fruit::Fruit(){
    srand((int)time(NULL));
    resetFruit();
    scale();
    fruitX = rand() % 820;
    sprite.setPosition(fruitX , 0);
}



sf::Sprite Fruit::getFruitSprite(){
    return sprite;
}


void Fruit::resetFruit(){
    int r = rand() % 6;
    if(!texture.loadFromFile(resourcePath() + FRUITS[r])){
        return EXIT_FAILURE;
    }
    if(r == 5){
        chilli = true;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    scale();
    fruitX = rand() % 820;
    sprite.setPosition(fruitX, 0);
}

void Fruit::drop(){
    if(!stopped){
    if(sprite.getPosition().y < 380){
        sprite.setPosition(fruitX, sprite.getPosition().y+((rand()%20)));
    }else{
        usleep(100000);
        resetFruit();
    }
 }
}

sf::Vector2f Fruit::getPosition(){
    return sprite.getPosition();
}

void Fruit::scale(){
    sf::FloatRect fruitRect = sprite.getLocalBounds();
    sf::Vector2f targetFruitSize(40.0f, 50.0f);
    float fruitScaleX = targetFruitSize.x/fruitRect.width;
    float fruitScaleY = targetFruitSize.y/fruitRect.height;
    sprite.setScale(fruitScaleX, fruitScaleY);
}

bool Fruit::isChilli(){
    return chilli;
}

void Fruit::setStop(bool s){
    stopped = s;
}



