//
// Created by nQuynhtrang on 11/14/2020.
//

#ifndef VIRUSHUNTER_STATEPLAY_H
#define VIRUSHUNTER_STATEPLAY_H
#include<iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include"Data.h"
#include "Animation.h"
#include "Collision.h"
using namespace sf;
using namespace std;

class StatePlay {
private:
    Animation background;
    Animation score;
    Animation player;
    vector <Animation> A_enemy;
    vector<Sprite> enemy;
    vector<Sprite> bullet;
    vector <Animation> A_bullet;
    Data data;
    Sprite tmp;

    int vtrix;
    int vtriy;
    Text text;
    Font font;
    string namebullet;
public:
    void setStatePlay();
    bool isOutside(Sprite tmp);
    bool isCollision(int x1, int y1, float r1,float h1, int x2, int y2, float r2, float h2);
    void run(RenderWindow&,int &enemyrate, int &bulletrate,int &mark, int &ddchange,int &ddbullet);
    void drawTo(RenderWindow &window,Sprite textu);
};


#endif //VIRUSHUNTER_STATEPLAY_H
