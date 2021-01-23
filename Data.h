//
// Created by nQuynhtrang on 11/14/2020.
//

#ifndef VIRUSHUNTER_DATA_H
#define VIRUSHUNTER_DATA_H
#include<iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Data {
private:
    vector <pair<string,Texture> > background;
    vector <pair<string,Texture> > player;
    vector <pair<string, vector<Texture> > > enemy;
    vector <pair<string,Texture> > bullet;
    Texture tmp;

public:
    void loadFormFile();
    Texture& getBackground(string);
    Texture& getPlayer(string);
    Texture& getBullet(string);
    vector <Texture>& getEnemy(string);
};


#endif //VIRUSHUNTER_DATA_H
