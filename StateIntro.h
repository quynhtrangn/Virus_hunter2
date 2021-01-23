//
// Created by nQuynhtrang on 11/14/2020.
//

#ifndef VIRUSHUNTER_STATEINTRO_H
#define VIRUSHUNTER_STATEINTRO_H
#include<iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include"Data.h"
#include "Animation.h"
#include "Collision.h"
using namespace sf;
using namespace std;

class StateIntro {
private:
    Animation background;
    Animation menubtn;
    Animation playbtn;
    Animation playbtn2;
    Animation title;
    Animation logo;
    Data data;
    Collision check;
public:
    void setStateIntro(RenderWindow &window);
    void run(RenderWindow &window, int &titlemove, int &ddtitle,int &menubtnmove, int &playbtnmove,int &ddchange);
};


#endif //VIRUSHUNTER_STATEINTRO_H
