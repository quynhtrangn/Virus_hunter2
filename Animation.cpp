//
// Created by nQuynhtrang on 11/14/2020.
//

#include "Animation.h"

void Animation::setAnimation() {
    data.loadFormFile();

}

void Animation::setImagine(Texture &textu) {
    imagine.setTexture(textu);
//    imagine.setOrigin((Vector2f)imagine.getTexture()->getSize()*0.5f);
//    imagine.setPosition(360,475);
}
void Animation::setImagine(vector <Texture>& textu){
    imagine.setTexture(textu[0]);
}
void Animation::setPosition(Vector2f posi){
    imagine.setPosition(posi);
}
void Animation::setScale(Vector2f scal){
    imagine.setScale(scal);
}
void Animation::setOrigin(float xy){
    imagine.setOrigin((Vector2f)imagine.getTexture()->getSize()*xy);
}
void Animation::setMove(Vector2f move){
    imagine.move(move);
}
void Animation::drawTo(RenderWindow &window) {
    window.draw(imagine);
}
void Animation::run(Texture &textu, float xy, Vector2f posi, Vector2f scal, RenderWindow &window){
    setImagine(textu);
    setPosition(posi);
    setScale(scal);
    setOrigin(xy);
//    imagine.setTexture(textu);
//    imagine.setOrigin((Vector2f)imagine.getTexture()->getSize()*xy);
//    imagine.setPosition(posi);
//    imagine.setScale(scal);
    drawTo(window);
}

void Animation::run(Texture &textu, float xy, Vector2f posi, Vector2f scal, Vector2f move,RenderWindow& window){
    setImagine(textu);
    setPosition(posi);
    setScale(scal);
    setOrigin(xy);
    imagine.move(move);
//    imagine.setTexture(textu);
//    imagine.setOrigin((Vector2f)imagine.getTexture()->getSize()*xy);
//    imagine.setPosition(posi);
//    imagine.setScale(scal);
    drawTo(window);
}

Sprite Animation::getImagine() {
    return imagine;
}
