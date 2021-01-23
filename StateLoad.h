//
// Created by nQuynhtrang on 11/14/2020.
//

#ifndef VIRUSHUNTER_STATELOAD_H
#define VIRUSHUNTER_STATELOAD_H
#include<iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include"Data.h"
#include "Animation.h"
using namespace sf;
using namespace std;

class StateLoad {
private:
    Animation background;
    Animation loading;
    Animation loadbar;
    Data data;
    Text text;
    Font font;
public:
    void setStateLoad(RenderWindow &window);
    void run(RenderWindow &window, int &timeload);
};


#endif //VIRUSHUNTER_STATELOAD_H
