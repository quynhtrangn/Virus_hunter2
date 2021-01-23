//
// Created by nQuynhtrang on 11/14/2020.
//

#ifndef VIRUSHUNTER_ANIMATION_H
#define VIRUSHUNTER_ANIMATION_H
#include<iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include"Data.h"
using namespace sf;
using namespace std;

class Animation {
private:
    Sprite imagine;
    Texture texture;
    vector<Texture> vtexture;
    Data data;
public:
    void setAnimation();
    void setImagine(Texture&);
    void setImagine(vector <Texture>&);
    void setPosition(Vector2f);
    void setScale(Vector2f);
    void setOrigin(float);
    void setMove(Vector2f);
    void drawTo(RenderWindow &window);
    void run(Texture &textu, float xy, Vector2f posi, Vector2f scal, RenderWindow &window);
    void run(Texture &textu, float xy, Vector2f posi, Vector2f scal,Vector2f move,RenderWindow &window);
    Sprite getImagine();
};


#endif //VIRUSHUNTER_ANIMATION_H
