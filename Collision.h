//
// Created by nQuynhtrang on 11/14/2020.
//

#ifndef VIRUSHUNTER_COLLISION_H
#define VIRUSHUNTER_COLLISION_H
#include<iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include"Data.h"
#include "Animation.h"
using namespace sf;
using namespace std;

class Collision : public Sprite{
public:
    Collision();
    bool isOnButton(FloatRect&);
    bool isClickButton(RenderWindow &window,Animation object);
    bool isButton(int x1, int y1, float r1, int x2, int y2, float r2);
    bool isCollision(int x1, int y1, float r1,float h1, int x2, int y2, float r2, float h2);

};

#endif //VIRUSHUNTER_COLLISION_H
