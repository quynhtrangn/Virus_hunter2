//
// Created by nQuynhtrang on 11/14/2020.
//

#include "StateLoad.h"
void StateLoad::setStateLoad(RenderWindow &window){
    data.loadFormFile();
    font.loadFromFile("../Data/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(30);
//    text.setColor(Color::Yellow);
//    text.setString("Hello World!!");
    text.setPosition(Vector2f(360,730));
    text.setStyle(Text::Bold);
    background.run(data.getBackground("Intro"),0.5f,Vector2f(360,475),Vector2f(1.9,1.9),window);
    loadbar.run(data.getBackground("LoadBar"),0.5f,Vector2f(360,705),Vector2f(1,1),window);
    loading.run(data.getBackground("Loading"),0.0f,Vector2f(145,694),Vector2f(1,1),window);
}
void StateLoad::run(RenderWindow &window, int &timeload){
    background.run(data.getBackground("Intro"),0.5f,Vector2f(360,475),Vector2f(1.12,1.15),window);
    loadbar.run(data.getBackground("LoadBar"),0.5f,Vector2f(360,705),Vector2f(1,1),window);
    if(timeload<=100){
        loading.run(data.getBackground("Loading"),0.0f,Vector2f(145,694),Vector2f(0.01*timeload,1),window);
        text.setString(to_string(timeload)+"%");
    }
    else loading.run(data.getBackground("Loading"),0.0f,Vector2f(145,694),Vector2f(1,1),window);
    timeload++;
    window.draw(text);


}